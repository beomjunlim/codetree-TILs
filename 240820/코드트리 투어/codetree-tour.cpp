#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <climits>
using namespace std;

int n,m;
vector<pair<int,int>> city[2001];
map<int, pair<int,int>> product;
priority_queue<pair<int,int>> sold;
bool deleted[30001];
int dist[2001];
int start;

void ProductPrice(){
    sold = priority_queue<pair<int,int>> ();

    for(auto it : product){
        int id = it.first;
        int revenue = it.second.first;
        int dest = it.second.second;

        int cost = revenue - dist[dest];

        if(cost>=0&&!deleted[id]){
            sold.push(make_pair(cost,-id));
        }
    }
}

void dijkstra(){
    for(int i=0; i<n; i++){
        dist[i] = INT_MAX;
    }

    dist[start] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int cnt = -pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        if(dist[idx] < cnt)
            continue;
        
        for(int i=0; i<city[idx].size(); i++){
            int node = city[idx][i].first;
            int next = city[idx][i].second + cnt;

            if(dist[node] > next){
                dist[node] = next;
                pq.push(make_pair(-next, node));
            }
        }
    }
}

int main() {
    int q;
    cin>>q;

    while(q>0){
        int num;
        cin>>num;

        if(num==100){
            cin>>n>>m;

            for(int i=0; i<m; i++){
                int x,y,z;
                cin>>x>>y>>z;
                city[x].push_back(make_pair(y,z));
                city[y].push_back(make_pair(x,z));
            }
            
            start = 0;
            dijkstra();
        }
        else if(num==200){
            int id,revenue,dest;
            cin>>id>>revenue>>dest;
            product[id] = make_pair(revenue, dest);

            int cost = revenue - dist[dest];

            if(cost>=0)
                sold.push(make_pair(cost,-id));              
        }
        else if(num==300){
            int id;
            cin>>id;
            if(product.find(id)!=product.end()){
                product.erase(id);
                deleted[id] = true;
            }
        }
        else if(num==400){
            int id = -1;
            while(!sold.empty()){
                id = -sold.top().second;

                if(deleted[id]){
                    id = -1;
                    sold.pop();
                }
                else
                    break;
            }

            cout<<id<<'\n';
            if(id!=-1){
                product.erase(id);
                sold.pop();
                deleted[id] = true;
            }
        }
        else if(num==500){
            int s;
            cin>>s;
            start = s;
            dijkstra();
            ProductPrice();
        }
        q--;
    }
    return 0;
}
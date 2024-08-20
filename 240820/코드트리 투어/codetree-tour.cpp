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
int dist[2001];
int start;

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
        }
        else if(num==300){
            int id;
            cin>>id;
            product.erase(id);
        }
        else if(num==400){
            int max_id = -1;
            int max_cost = -1;
            for(auto it : product){
                int id = it.first;
                int revenue = it.second.first;
                int dest = it.second.second;

                int cost = revenue - dist[dest];

                if(cost>=0&&max_cost<cost){
                    max_cost = cost;
                    max_id = id;
                }
            }

            cout<<max_id<<'\n';
            product.erase(max_id);
        }
        else if(num==500){
            int s;
            cin>>s;
            start = s;
            dijkstra();
        }
        q--;
    }
    return 0;
}
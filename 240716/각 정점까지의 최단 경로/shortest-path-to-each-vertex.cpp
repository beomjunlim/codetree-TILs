#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m,k;
vector<pair<int,int>> arr[20001];
int dist[20001];

int main() {
    cin>>n>>m;
    cin>>k;

    for(int i=0; i<m; i++){
        int x,y,dis;
        cin>>x>>y>>dis;
        arr[x].push_back(make_pair(y,dis));
        arr[y].push_back(make_pair(x,dis));
    }    

    for(int i=1; i<=n; i++)
        dist[i] = 987654321;
    
    dist[k] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,k));

    while(!pq.empty()){
        int min_dist = -pq.top().first;
        int min_index = pq.top().second;
        pq.pop();

        if(min_dist > dist[min_index])
            continue;
        
        for(int i=0; i<arr[min_index].size(); i++){
            int index = arr[min_index][i].first;
            int distance = arr[min_index][i].second;

            int new_dist = dist[min_index] + distance;
            if(dist[index]>new_dist){
                dist[index] = new_dist;
                pq.push(make_pair(-new_dist, index));
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(dist[i]!=987654321)
            cout<<dist[i]<<'\n';
        else
            cout<<-1<<'\n';
    }


    return 0;
}
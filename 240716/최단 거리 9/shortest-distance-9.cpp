#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
vector<pair<int,int>> arr[1001];
int dist[1001];
int pre[1001];

int main() {
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int x,y,dis;
        cin>>x>>y>>dis;
        arr[x].push_back(make_pair(y,dis));
        arr[y].push_back(make_pair(x,dis));
    }

    int start,end;
    cin>>start>>end;

    for(int i=1; i<=n; i++)
        dist[i] = 987654321;

    dist[start] = 0;


    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int min_dist = -pq.top().first;
        int min_index = pq.top().second;
        pq.pop();

        if(dist[min_index] < min_dist)
            continue;
        
        for(int i=0; i<arr[min_index].size(); i++){
            int next_index = arr[min_index][i].first;
            int next_dist = arr[min_index][i].second;

            int new_dist = dist[min_index] + next_dist;

            if(dist[next_index] > new_dist){
                pre[next_index] = min_index;
                dist[next_index] = new_dist;
                pq.push(make_pair(-new_dist,next_index));
            }
        }
    }

    cout<<dist[end]<<'\n';

    vector<int> ans;
    ans.push_back(end);
    int idx = end;
    
    while(true){
        ans.push_back(pre[idx]);
        if(pre[idx]==start)
            break;
        idx = pre[idx];
    }

    for(int i=ans.size()-1; i>=0; i--)
        cout<<ans[i]<<" ";

    return 0;
}
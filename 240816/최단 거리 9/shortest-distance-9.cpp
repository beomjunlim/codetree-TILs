#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <stack>
using namespace std;

int n,m;
int dist[1001];
int pre[1001];
bool visited[1001];
vector<pair<int,int>> v[1001];

int main() {
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }

    int s,e;
    cin>>s>>e;

    for(int i=1; i<=n; i++){
        dist[i] = 1e9;
        pre[i] = 0;
    }

    dist[s] = 0;

    for(int i=1; i<=n; i++){
        int min_idx;
        int dis = INT_MAX;

        for(int j=1; j<=n; j++){
            if(!visited[j]&&dist[j]<dis){
                min_idx = j;
                dis = dist[j];
            }
        }

        visited[min_idx] = true;

        for(int j=0; j<v[min_idx].size(); j++){
            int next_idx = v[min_idx][j].first;
            int next_dist = v[min_idx][j].second + dis;

            if(dist[next_idx] > next_dist){
                dist[next_idx] = next_dist;
                pre[next_idx] = min_idx;
            }
        }
    }

    stack<int> st;
    int idx = e;

    while(idx!=0){
        st.push(idx);
        idx = pre[idx];
    }

    cout<<dist[e]<<'\n';

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
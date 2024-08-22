#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
using namespace std;

map<int, pair<int,pair<int,int>>> node;
map<int,set<int>>Parent;
set<int> root;
int score = 0;
bool COLOR[6];
bool visited_node[100001];

void dfs(int x) {
    if (visited_node[x]) return; // 이미 방문한 노드일 경우 넘긴다.

    visited_node[x] = true; // 해당 노드 방문 처리

    bool localColor[6] = {false}; 
    localColor[node[x].second.first] = true; // 해당 노드 색 true

    for (auto it : Parent[x]) {
        dfs(it); // 자식 노드 dfs 호출
        for (int i = 1; i <=5; i++) {
            if (COLOR[i]) { // 자식 노드에서 방문한 것 처리
                localColor[i] = true;
            }
        }
    }

    for (int i = 1; i <=5; i++) {
        COLOR[i] = localColor[i]; // 전역 배열 업데이트
    }

    int cnt = 0;
    for (int i = 1; i <=5; i++) {
        if (COLOR[i]) {
            cnt++;
        }
    }

    score += cnt * cnt;
}

int main() {
    int q;
    cin>>q;

    for(int i=1; i<=q; i++){
        int n;
        cin>>n;

        if(n==100){
            int id,Pid,color,depth;
            cin>>id>>Pid>>color>>depth;
            if(Pid==-1){
                node[id] = make_pair(Pid, make_pair(color, depth));
                root.insert(id);
            }
            else{
                int P_depth = node[Pid].second.second;
                depth = min(P_depth - 1, depth);
                if(depth==0)
                    continue;
                node[id] = make_pair(Pid, make_pair(color, depth));
                int parent = Pid;
                while(parent!=-1){
                    Parent[parent].insert(id); // 해당 부모가 가지고 있는 자식들
                    parent = node[parent].first;
                }
            }
        }
        else if(n==200){
            int id, color;
            cin>>id>>color;
            
            int Pid = node[id].first;
            int depth = node[id].second.second;

            node[id] = make_pair(Pid, make_pair(color, depth));

            for(auto it : Parent[id]){
                int Pid = node[it].first;
                int depth = node[it].second.second;
                node[it] = make_pair(Pid, make_pair(color, depth));
            }
        }
        else if(n==300){
            int id;
            cin>>id;
            cout<<node[id].second.first<<'\n';
        }
        else if(n==400){
            score = 0;
            for(auto it : root){
                memset(visited_node, false, sizeof(visited_node));
                memset(COLOR, false, sizeof(COLOR));
                dfs(it);
            }
            cout<<score<<'\n';
        }

    }
    return 0;
}
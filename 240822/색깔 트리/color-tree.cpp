#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <queue>
using namespace std;

map<int, pair<int,pair<int,int>>> node;
map<int,set<int>>Parent;
set<int> root;
int score = 0;
bool COLOR[6];
set<int> used_node;
map<int,int> Color;



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
                Color[id] = color;
                used_node.insert(id);
            }
            else{
                int P_depth = node[Pid].second.second;
                depth = min(P_depth - 1, depth);
                if(depth==0)
                    continue;
                node[id] = make_pair(Pid, make_pair(color, depth));
                Color[id] = color;
                used_node.insert(id);
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
            Color[id] = color;

            for(auto it : Parent[id]){
                int Pid = node[it].first;
                int depth = node[it].second.second;
                node[it] = make_pair(Pid, make_pair(color, depth));
                Color[it] = color;
            }
        }
        else if(n==300){
            int id;
            cin>>id;
            cout<<node[id].second.first<<'\n';
        }
        else if(n==400){
            score = 0;
            set<int> leaf;
            for(auto it : used_node){
                leaf.insert(it);
            }

            for(auto it : Parent){
                int id = it.first;
                set<int> cnt;
                leaf.erase(id);
                cnt.insert(Color[id]);
                for(auto idx : Parent[id]){
                    cnt.insert(Color[idx]);
                }
                int num =cnt.size();
                score += num*num;
            }
            score += leaf.size();
            cout<<score<<'\n';
        }


    }
    return 0;
}
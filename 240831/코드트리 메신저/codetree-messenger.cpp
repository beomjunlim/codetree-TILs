#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Node{
    int p = -1;
    int l = -1;
    int r = -1;
};

int Q,N;
map<int,int> authority;
bool Ignore[100001];

int main() {
    cin>>N>>Q;

    map<int, Node> node;
    for(int q=1; q<=Q; q++){
        int command;
        cin>>command;

        if(command==100){
            node[0].p= -1;

            for(int i=1; i<=N; i++){
                int a;
                cin>>a;
                node[i].p = a;

                if(node[a].l==-1)
                    node[a].l = i;
                else if(node[a].r==-1)
                    node[a].r = i;
            }

            for(int i=1; i<=N; i++){
                int a;
                cin>>a;
                authority[i] = a;
            }
        }
        else if(command==200){
            int a;
            cin>>a;
            Ignore[a] ^=1;
        }
        else if(command==300){
            int a,power;
            cin>>a>>power;
            authority[a] = power; 
        }
        else if(command==400){
            int a,b;
            cin>>a>>b;
            int a_p = node[a].p;
            int b_p = node[b].p;
            
            if(node[a_p].l==a){
                int temp = node[a_p].l;
                if(node[b_p].l==b){
                    node[a_p].l = node[b_p].l;
                    node[b_p].l = temp;
                }
                else if(node[b_p].r==b){
                    node[a_p].l = node[b_p].r;
                    node[b_p].r = temp;
                }
            }
            else if(node[a_p].r==a){
                int temp = node[a_p].r;
                if(node[b_p].l==b){
                    node[a_p].r = node[b_p].l;
                    node[b_p].l = temp;
                }
                else if(node[b_p].r==b){
                    node[a_p].r = node[b_p].r;
                    node[b_p].r = temp;
                }
            }


            node[a].p = b_p;
            node[b].p = a_p;
        }
        else if(command==500){
            int a;
            cin>>a;

            int ans = 0;

            queue<pair<int,int>> q;
            if(node[a].l!=-1)
                q.push(make_pair(node[a].l,1));
            if(node[a].r!=-1)
                q.push(make_pair(node[a].r,1));
            
            while(!q.empty()){
                int x = q.front().first;
                int depth = q.front().second;
                q.pop();

                if(Ignore[x])
                    continue;

                if(depth<=authority[x])
                    ans++;

                if(node[x].l!=-1)
                    q.push(make_pair(node[x].l, depth + 1));
                if(node[x].r!=-1)
                    q.push(make_pair(node[x].r, depth + 1));
            }

            cout<<ans<<'\n';
        }
    }    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;

struct Rabbit{
    int x,y;
    int id;
    int d;
    int count;

    bool operator<(const Rabbit& cmp) const{
        if(count==cmp.count){
            if(x+y==cmp.x+cmp.y){
                if(x==cmp.x){
                    if(y==cmp.y)
                        return id > cmp.id;
                    return y > cmp.y;
                }
                return x > cmp.x;
            }
            return x + y > cmp.x + cmp.y;
        }
        return count > cmp.count;
    }
};

int N,M,P;
priority_queue<Rabbit> pq;
unordered_map<int,Rabbit> rabbit; 
unordered_map<int,ll> score;

int dx[] = {0,1,0,-1}; // 좌 하 우 상  
int dy[] = {-1,0,1,0};

bool cmp1(pair<int,int> a, pair<int,int> b){
    if(a.first + a.second == b.first + b.second){
        if(a.first==b.first)
            return a.second > b.second;
        else
           return a.first > b.first;
    }

    return a.first + a.second > b.first + b.second;
}

bool cmp2(Rabbit& a, Rabbit& b){
    if(a.x + a.y == b.x + b.y){
        if(a.x==b.x){
            return a.y > b.y;
        }
        return a.x > b.x;
    }
    return a.x + a.y > b.x + b.y;
}

int main() {
    int Q;
    cin>>Q;
    while(Q>0){
        int command;
        cin>>command;

        if(command==100){
            cin>>N>>M>>P;

            for(int i=1; i<=P; i++){
                int id, d;
                cin>>id>>d;
                
                rabbit[id] = {1,1,id,d,0};
            }

            for(auto it : rabbit){
                pq.push(it.second);
                score[it.first] = 0;
            }   
        }
        else if(command==200){
            int K,S;
            cin>>K>>S;

            set<int> selected;

            for(int i=0; i<K; i++){
                auto [x,y,id,jump,count] = pq.top();
                count++;
               // cout<<"before "<<id<<" "<<x<<" "<<y<<" "<<jump<<'\n';

                pq.pop();
                selected.insert(id);

                int mod_n = 2*N - 2;
                int mod_m = 2*M - 2;

                vector<pair<ll,ll>> coordinate;
                // 하
                int nx = x;
                int ny = y;
                int dist = jump%mod_n;
                
                if(N-x>=dist){
                    nx = x + dist;
                }
                else{
                    dist -= (N-x);
                    if(dist>=N){
                        dist -= N-1;
                        nx = 1 + dist;
                    }
                    else{
                        nx = N - dist;
                    }
                }
                //cout<<"jump "<<nx<<" "<<ny<<'\n';
                coordinate.push_back(make_pair(nx,ny));

                // 상
                nx = x;
                ny = y;
                dist = jump%mod_n;

                if(x-1>=dist){
                    nx = x - dist;
                }
                else{
                    dist -= (x-1);

                    if(dist>=N){
                        dist -= N-1;
                        nx = N - dist;
                    }
                    else{
                        nx = 1 + dist;
                    }
                }
            //    cout<<"jump "<<nx<<" "<<ny<<'\n';
                coordinate.push_back(make_pair(nx,ny));

                // 우
                nx = x;
                ny = y;
                dist = jump%mod_m;

                if(M-y>=dist){
                    ny = y + dist;
                }
                else{
                    dist -= (M-y);
                    if(dist>=M){
                        dist -= M-1;
                        ny = 1 + dist;
                    }
                    else{
                        ny = M - dist;
                    }
                }
               // cout<<"jump "<<nx<<" "<<ny<<'\n';
                coordinate.push_back(make_pair(nx,ny));

                // 좌
                nx = x;
                ny = y;
                dist = jump%mod_m;

                if(y-1>=dist){
                    ny = y - dist;
                }
                else{
                    dist -= (y-1);

                    if(dist>=M){
                        dist -= M-1;
                        ny = M - dist;
                    }
                    else{
                        ny = 1 + dist;
                    }
                }

            //    cout<<"jump "<<nx<<" "<<ny<<'\n';
                coordinate.push_back(make_pair(nx,ny));

                sort(coordinate.begin(), coordinate.end(), cmp1);
                
                x = coordinate[0].first;
                y = coordinate[0].second;

                rabbit[id].x = x;
                rabbit[id].y = y;
                rabbit[id].count = count;
                pq.push(rabbit[id]);

               // cout<<"after : "<<id<<" "<<x<<" "<<y<<'\n';

                for(auto& it : score){
                    if(it.first!=id)
                        it.second+= x+y;
                }
            }

            vector<Rabbit> v;
            for(auto id : selected)
                v.push_back(rabbit[id]);
            
            sort(v.begin(), v.end(), cmp2);

            score[v.front().id] += S;
            
        }
        else if(command==300){
            int id, l;
            cin>>id>>l;
            rabbit[id].d*=l;

         //   cout<<"change "<<rabbit[id].d<<'\n';

            while(!pq.empty())
                pq.pop();
            
            for(auto it : rabbit){
                pq.push(it.second);
              //  cout<<it.second.count<<" "<<it.second.x<<" "<<it.second.y<<" "<<it.second.id<<'\n';
            }
        }
        else if(command==400){
            ll max_num = 0;
            
            for(auto it : score)
                max_num = max(max_num, it.second);
            cout<<max_num;
        }
        Q--;
    }
    return 0;
}





// #include <bits/stdc++.h>
// #define endl '\n'
// #define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// using namespace std;

// typedef long long ll;
// typedef pair<int,int> pii;
// typedef pair<ll, ll> pll;
// typedef tuple<int,int,int> tiii;
// const int INF=1e9+1;

// struct Rabbit {
//     int x, y;
//     int pid;
//     int d;
//     int jump_count;
//     // 토끼 우선순위
//     bool operator<(const Rabbit& cmp) const {
//         if(jump_count==cmp.jump_count) {
//             if(x+y==cmp.x+cmp.y) {
//                 if(x==cmp.x) {
//                     if(y==cmp.y) return pid>cmp.pid;
//                     return y>cmp.y;
//                 }
//                 return x>cmp.x;
//             }
//             return x+y>cmp.x+cmp.y;
//         }
//         return jump_count>cmp.jump_count;
//     }
// };

// bool cmp(pii& a, pii& b) {
//     // 토끼 이동 정렬
//     if(a.first+a.second==b.first+b.second) {
//         if(a.first==a.second) return a.second>b.second;
//         return a.first>b.first;
//     }
//     return a.first+a.second>b.first+b.second;
// }

// bool cmp2(Rabbit& a, Rabbit& b) {
//     // 점수를 추가할 토끼 정렬
//     if(a.x+a.y==b.x+b.y) {
//         if(a.x==b.x) {
//             if(a.y==b.y) return a.pid>b.pid;
//             return a.y>b.y;
//         }
//         return a.x>b.x;
//     }
//     return a.x+a.y>b.x+b.y;
// }

// unordered_map<int,Rabbit> rabbits; // (토끼 id, 토끼)
// unordered_map<int,ll> score; // (토끼 id, 점수)
// priority_queue<Rabbit> pq;
// int n, m, p;

// void init(int p) {
//     cin>>n>>m>>p;
//     for(int i=0;i<p;i++) {
//         int pid, d; cin>>pid>>d;
//         rabbits[pid]={0,0,pid,d,0};
//     }
//     for(auto it : rabbits) {
//         pq.push(it.second);
//         score[it.first]=0;
//     }
// }

// // 토끼 이동은 반복되므로 나머지 연산을 적용한다
// // distance %= 2 * ((N or M) -1)
// // 한 방향으로 이동, 반대로 이동, 다시 반대로 이동이 하나의 사이클이 된다

// pii right(int x, int y, int d) {
//     int dist=d%(2*(m-1));
//     if(m-y-1<dist) {
//         dist-=m-y-1;
//         if(m-1<dist) {
//             dist-=m-1;
//             y=dist;
//         }
//         else y=m-1-dist;
//     }
//     else y+=dist;
//     cout<<"jump "<<x<<" "<<y<<'\n';
//     return {x,y};
// }

// pii left(int x, int y, int d) {
//     int dist=d%(2*(m-1));
//     if(y<dist) {
//         dist-=y;
//         if(m-1<dist) {
//             dist-=m-1;
//             y=m-1-dist;
//         }
//         else y=dist;
//     }
//     else y-=dist;
//     cout<<"jump "<<x<<" "<<y<<'\n';
//     return {x,y};
// }

// pii up(int x, int y, int d) {
//     int dist=d%(2*(n-1));
//     if(x<dist) {
//         dist-=x;
//         if(n-1<dist) {
//             dist-=n-1;
//             x=n-1-dist;
//         }
//         else x=dist;
//     }
//     else x-=dist;
//     cout<<"jump "<<x<<" "<<y<<'\n';
//     return {x,y};
// }

// pii down(int x, int y, int d) {
//     int dist=d%(2*(n-1));
//     if(n-x-1<dist) {
//         dist-=n-x-1;
//         if(n-1<dist) {
//             dist-=n-1;
//             x=dist;
//         }
//         else x=n-1-dist;
//     }
//     else x+=dist;
//     cout<<"jump "<<x<<" "<<y<<'\n';
//     return {x,y};
// }

// void race(int k, int s) { // 토끼 이동
//     set<int> selected;
//     while(k--) {
//         auto [x,y,pid,dist,jump_count]=pq.top();
//         cout<<"before "<<pid<<" "<<x<<" "<<y<<" "<<dist<<'\n';
//         pq.pop();
//         selected.insert(pid);

//         vector<pii> v;
//         pii r=right(x,y,dist);
//         v.push_back(r);
//         pii l=left(x,y,dist);
//         v.push_back(l);
//         pii u=up(x,y,dist);
//         v.push_back(u);
//         pii d=down(x,y,dist);
//         v.push_back(d);
        
//         sort(v.begin(),v.end(),cmp);
//         x=v.front().first, y=v.front().second;

//         rabbits[pid].x=x, rabbits[pid].y=y, rabbits[pid].jump_count++;
//         pq.push(rabbits[pid]);
        
//         cout<<"after "<<pid<<" "<<x<<" "<<y<<'\n';
//         // score
//         for(auto& it : score) {
//             if(it.first!=pid) it.second+=x+y+2;
//         }
//     }
//     vector<Rabbit> v;
//     for(auto pid : selected) v.push_back(rabbits[pid]);
//     sort(v.begin(),v.end(),cmp2);
//     score[v.front().pid]+=s;
// }

// void multiply(int pid, int l) { // 이동거리 곱
//     rabbits[pid].d*=l;
//     cout<<"change "<<rabbits[pid].d<<'\n';
//     while(!pq.empty()) pq.pop();
//     for(auto it : rabbits) {
//         pq.push(it.second);
//         cout<<it.second.jump_count<<" "<<it.second.x<<" "<<it.second.y<<" "<<it.second.pid<<'\n';
//     }
// }

// ll bestRabbit() { // 최고의 토끼를 선정, 점수는 int 범위를 넘어간다
//     ll max_score=0;
//     for(auto it : score) max_score=max(max_score, it.second);
//     return max_score;
// }

// int main() {

//     int query_cnt; cin>>query_cnt;
//     while(query_cnt--) {
//         int cmd; cin>>cmd;
//         switch(cmd) {
//             case 100: {
//                 init(p);
//                 break;
//             }
//             case 200: {
//                 int k,s; cin>>k>>s;
//                 race(k,s);
//                 break;
//             }
//             case 300: {
//                 int pid, l; cin>>pid>>l;
//                 multiply(pid,l);
//                 break;
//             }
//             case 400: {
//                 cout<<bestRabbit()<<endl;
//                 break;
//             }
//             default:
//                 break;
//         }
//     }
//     return 0;
// }
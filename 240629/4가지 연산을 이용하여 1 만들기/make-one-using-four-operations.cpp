#include <iostream>
#include <queue>
using namespace std;

int n;
bool visited[1000001];

void bfs(){
    queue<pair<int,int>> q;
    q.push(make_pair(0,n));
    visited[n] = true;

    while(!q.empty()){
        int num = q.front().second;
        int cnt = q.front().first;
        visited[num] = true;
        q.pop();

        if(num==1){
            cout<<cnt;
            break;
        }

        if(!visited[num-1])
            q.push(make_pair(cnt+1, num-1));
        if(!visited[num+1])
            q.push(make_pair(cnt+1, num+1));
        if(num%2==0&&!visited[num/2])
            q.push(make_pair(cnt+1, num/2));
        if(num%3==0&&!visited[num/3])
            q.push(make_pair(cnt+1, num/3));
    }
}

int main() {
    cin>>n;
    bfs();    
    return 0;
}
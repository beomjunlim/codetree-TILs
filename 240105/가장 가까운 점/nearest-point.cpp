#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    priority_queue<pair<int,int>>q;

    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        q.push(make_pair(-(x+y),-x));
    }

    for(int i=0; i<m; i++){
        int x = -q.top().second;
        int y = -(q.top().first+x);
        x+=2;
        y+=2;
        q.pop();
        q.push(make_pair(-(x+y),-x));
    }

    cout<<-q.top().second<<" "<<-(q.top().first-q.top().second);
    
    return 0;
}
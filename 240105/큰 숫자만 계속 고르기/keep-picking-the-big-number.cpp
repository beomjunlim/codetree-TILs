#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;

    priority_queue<int> q;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        q.push(a);
    }
    for(int i=0; i<m; i++){
        int num = q.top();
        q.pop();
        q.push(num-1);
    }
    cout<<q.top();

    return 0;
}
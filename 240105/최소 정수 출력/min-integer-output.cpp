#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin>>n;
    priority_queue<int> q;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x==0){
            if(q.empty())
                cout<<0<<'\n';
            else{
                cout<<-q.top()<<'\n';
                q.pop();
            }
        }
        else{
            q.push(-x);
        }
    }
    return 0;
}
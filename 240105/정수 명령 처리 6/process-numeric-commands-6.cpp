#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> q;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        if(s=="push"){
            int a;
            cin>>a;
            q.push(a);
        }
        if(s=="pop"){
            cout<<q.top()<<'\n';
            q.pop();
        }
        if(s=="size"){
            cout<<q.size()<<'\n';
        }
        if(s=="empty"){
            if(q.empty())
                cout<<1<<'\n';
            else
                cout<<0<<'\n';
        }
        if(s=="top"){
            cout<<q.top()<<'\n';
        }
    }
    return 0;
}
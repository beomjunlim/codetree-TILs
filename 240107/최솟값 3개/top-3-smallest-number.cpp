#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin>>n;
    priority_queue<int> pq;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        pq.push(-x);
        if(pq.size()<3)
            cout<<-1<<'\n';
        else{
            int a,b,c;
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            c = pq.top();
            pq.push(a);
            pq.push(b);
            cout<<-a*b*c<<'\n';
        }
    }
    return 0;
}
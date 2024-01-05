#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin>>n;

    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        pq.push(a);
    }
    while(1){
        if(pq.size()==1){
            cout<<pq.top();
            break;
        }
        if(pq.empty()){
            cout<<-1;
            break;
        }
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();

        if(x-y!=0)
            pq.push(x-y);
    }

    return 0;
}
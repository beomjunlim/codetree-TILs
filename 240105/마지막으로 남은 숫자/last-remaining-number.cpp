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
    while(pq.size()!=1){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        
        if(x-y!=0)
            pq.push(x-y);
    }
    cout<<pq.top();
    return 0;
}
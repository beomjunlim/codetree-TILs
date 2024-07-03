#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        pq.push(x);
    }

    while(pq.size()>1){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();

        int num = x - y;

        if(num!=0){
            pq.push(num);
        }
    }

    if(pq.empty())
        cout<<-1;
    else
        cout<<pq.top();
    return 0;
}
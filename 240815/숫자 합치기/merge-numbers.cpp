#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int n;
    cin>>n;

    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        pq.push(-a);
    }

    int cnt = 0;
    while(pq.size()>1){
        int A = - pq.top();
        pq.pop();
        int B = - pq.top();
        pq.pop();

        cnt += (A+B);

        pq.push(-(A+B));
    }

    cout<<cnt;
    return 0;
}
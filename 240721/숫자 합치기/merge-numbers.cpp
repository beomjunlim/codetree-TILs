#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    int n;
    cin>>n;
    
    priority_queue<long long> pq;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        pq.push(-x);
    }

    long long sum = 0;

    while(pq.size()>1){
        long long x = -pq.top();
        pq.pop();
        long long y = -pq.top();
        pq.pop();
        long long num = x + y;
        sum += num;
        pq.push(-num);
    }

    cout<<sum;
    return 0;
}
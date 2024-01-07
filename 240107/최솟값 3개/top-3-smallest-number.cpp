#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin>>n;
    priority_queue<pair<int,int>> pq;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        pq.push(make_pair(-x,i));
        if(pq.size()<3)
            cout<<-1<<'\n';
        else{
            int a,b;
            int index_a,index_b;
            a = pq.top().first;
            index_a = pq.top().second;
            pq.pop();
            b = pq.top().first;
            index_b = pq.top().second;
            pq.pop();
            long long sum = (long long)a*b*(-pq.top().first);
            cout<<sum<<'\n';
            pq.push(make_pair(a, index_a));
            pq.push(make_pair(b, index_b));
        }
    }
    return 0;
}
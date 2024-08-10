#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int A[100001];
int B[100001];
int main() {
    int n,m,k;
    cin>>n>>m>>k;

    for(int i=0; i<n; i++){
        cin>>A[i];
    }

    for(int i=0; i<m; i++){
        cin>>B[i];
    }

    sort(A, A+n);
    sort(B, B+m);

    priority_queue<pair<int,pair<int,pair<int,int>>>> pq;

    for(int i=0; i<n; i++){
        int num = A[i] + B[0];
        pq.push(make_pair(-num, make_pair(A[i], make_pair(B[0], 0))));
    }

    int ans = 0;
    while(k--){
        ans = -pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second.first;
        int idx = pq.top().second.second.second;
        pq.pop();
        if(idx+1>=m)
            continue;
        int num = a + B[idx+1];
        pq.push(make_pair(-num, make_pair(a, make_pair(B[idx+1], idx+1))));
    }

    cout<<ans<<'\n';

    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int cost[1001];

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>cost[i];
    }

    sort(cost, cost+n);

    int ans = 0;

    for(int i=0; i<n; i++){
        int sum = m;
        sum -= cost[i]/2;
        int cnt = 1;
        for(int j=0; j<n; j++){
            if(i!=j){
                if(sum-cost[j]>=0){
                    sum -= cost[j];
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);
    }

    cout<<ans;
    return 0;
}
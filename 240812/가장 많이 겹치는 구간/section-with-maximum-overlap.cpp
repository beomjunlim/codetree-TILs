#include <iostream>
#include <set>
using namespace std;

int arr[200001];

int main() {
    int n;
    cin>>n;

    set<int> num;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        arr[x]++;
        arr[y]--;
        num.insert(x);
        num.insert(y);
    }

    int ans = 0;
    int cnt = 0;
    for(auto it : num){
        cnt += arr[it];
        ans = max(ans, cnt);
    }

    cout<<ans;
    return 0;
}
#include <iostream>
#include <set>
using namespace std;

int arr[100001];
long long L[100001];
long long R[100001];

int main() {
    int n;
    cin >> n;
    long long s = 0;
    
    for (int i = 0; i < n; i++) {
        cin >>arr[i];
        s += arr[i];
    }

    long long lv = 0, rv = 0;
    set<int> center;
    for(int i=1; i<=n; i++){
        lv += arr[i-1];
        if(lv == s/4)
            L[i] = L[i-1] + 1;
        else
            L[i] = L[i-1];

        rv += arr[n-i];
        if(rv == s/4)
            R[n-i] = R[n-i+1] + 1;
        else
            R[n-i] = R[n-i+1];
        
        if(lv == s/2 && i>=2 &&i<=n-2)
            center.insert(i);
    }

    long long ans = 0;
    for(auto it : center){
        ans += L[it - 1]*R[it + 1];
    }

    cout<<ans;
    return 0;
}
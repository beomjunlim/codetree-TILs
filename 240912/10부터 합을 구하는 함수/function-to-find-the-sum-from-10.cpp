#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    long long ans = 0;
    for(int i=10; i<=n; i++){
        ans += i;
    }

    cout<<ans;
    return 0;
}
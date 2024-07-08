#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,c,g,h;
    cin>>n>>c>>g>>h;

    int H[1001];
    int L[1001];
    int high = 0;
    int low = 1001;

    for(int i=0; i<n; i++){
        cin>>L[i]>>H[i];
        low = min(low, L[i]);
        high = max(high, H[i]);
    }

    int ans = 0;
    for(int i=low-1; i<=high+1; i++){
        int temp = i;
        int num = 0;
        for(int j=0; j<n; j++){
            if(temp<L[j])
                num += c;
            if(L[j]<=temp&&temp<=H[j])
                num += g;
            if(temp>H[j])
                num += h;
        }
        ans = max(ans, num);
    }

    cout<<ans;
    return 0;  
}
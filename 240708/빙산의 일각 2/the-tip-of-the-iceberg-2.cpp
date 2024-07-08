#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;

    int arr[101];

    int start = 1001;
    int end = 0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        start = min(start, arr[i]);
        end = max(end, arr[i]);
    }

    int ans = 0;
    for(int i=start; i<=end; i++){
        int cnt = 0;
        bool sw = false;
        for(int j=0; j<n; j++){
            if(arr[j]>i){
                sw = true;
            }
            else{
                if(sw){
                    cnt++;
                    sw = false;
                }
            }
        }    
        if(sw)
            cnt++;
        ans = max(ans, cnt);
    }
    cout<<ans;
    return 0;
}
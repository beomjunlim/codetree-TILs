#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main() {
    int n;
    cin>>n;

    int max_height = 0;
    int min_height = 1000000001;
    for(int i=0; i<n; i++){
        cin>>arr[i];

        max_height = max(max_height, arr[i]);
        min_height = min(min_height, arr[i]);
    }

    int ans = 0;
    for(int i=min_height; i<max_height; i++){
        int count = 0;
        bool sw = false;
        if(arr[0]>i)
            sw = true;
        for(int idx=1; idx<n; idx++){
            if(arr[idx]>i)
                sw = true;
            else if(arr[idx]<=i){
                if(sw)
                    count++;
                sw = false;
            }
        }

        if(sw)
            count++;
        
        ans = max(ans, count);
    }

    cout<<ans;

    return 0;
}
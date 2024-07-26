#include <iostream>
#include <algorithm>
using namespace std;

int arr[2001];
int main() {
    int n;
    cin>>n;
    int start = 1000;

    for(int i=0; i<n; i++){
        int x;
        char y;
        cin>>x>>y;
        
        if(y=='R'){
            for(int j=start; j<start+x; j++)
                arr[j]++;
            
            start = start + x;
        }
        else{
            for(int j=start-x; j<start; j++)
                arr[j]++;
            
            start = start - x;
        }
    }

    int ans = 0;
    int idx = 0;
    bool sw = false;


    for(int i=0; i<2001; i++){
        if(arr[i]>1&&!sw){
            idx = i;
            sw = true;
        }
        if(arr[i]<=1&&sw){
            ans += (i-idx);
            sw = false;
        }
    }

    cout<<ans;


    return 0;
}
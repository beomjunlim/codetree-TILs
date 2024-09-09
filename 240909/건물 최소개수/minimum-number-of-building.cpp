#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int X[50001];
int Y[50001];
bool height[100001];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>X[i]>>Y[i];
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        if(Y[i]==0){
            memset(height, false, sizeof(height));
        }
        else{
            if(!height[Y[i]]){
                height[Y[i]] = true;
                ans++;
            }
            for(int j=Y[i]+1; j<=100000; j++){
                    height[j] = false;
            }
        }
    }
    
    cout<<ans;
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int X[101], Y[101];

int main() {
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>X[i]>>Y[i];
    
    int ans = 0;

    for(int i=0; i<n; i++){
        bool sw = false;

        for(int j=0; j<n; j++){
            if(i!=j){
                if(X[i]<=X[j]&&Y[i]>=Y[j]){
                    sw = true;
                    break;
                }
                if(X[i]>=X[j]&&Y[i]<=Y[j]){
                    sw = true;
                    break;
                }
            }
        }
        
        if(!sw)
            ans++;
    }

    cout<<ans;
    return 0;
}
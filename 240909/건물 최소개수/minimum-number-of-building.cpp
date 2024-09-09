#include <iostream>
using namespace std;

int X[50001];
int Y[50001];

int main() {
    int n;
    cin>>n;

    int ans = 0;
    int min_height = 0;
    for(int i=0; i<n; i++){
        cin>>X[i]>>Y[i];
    }

    min_height = Y[0];

    for(int i=1; i<n; i++){
        if(Y[i]>min_height&&Y[i]!=Y[i-1])
            ans++;
        
        if(Y[i]<min_height){
            ans++;
            if(Y[i]!=0)
                min_height = Y[i];
            
            if(Y[i]==0)
                min_height = Y[i+1];
        }
    }

    ans++;
    cout<<ans;
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    char arr[101];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = 0;

    for(int i=0; i<n-2; i++){
        if(arr[i]=='C'){
            for(int j=i+1; j<n-1; j++){
                if(arr[j]=='O'){
                    for(int k=j+1; k<n; k++){
                        if(arr[k]=='W')
                            ans++;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
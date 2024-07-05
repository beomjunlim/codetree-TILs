#include <iostream>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    char arr[16][16];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    int ans = 0;
    char start = arr[0][0];
    char end = arr[n-1][m-1];

    for(int i=1; i<n-2; i++){
        for(int j=1; j<m-2; j++){
            for(int k=i+1; k<n-1; k++){
                for(int l=j+1; l<m-1; l++){
                    if(arr[i][j]!=start){
                        if(arr[k][l]==start){
                            if(start!=end)
                                ans++;
                        }
                    }
                }
            }
        }
    }

    cout<<ans;
    return 0;
}
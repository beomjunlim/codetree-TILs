#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[11][11];

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char a;
            cin>>a;
            arr[i][j] = a - '0';
        }
    }

    int cnt = 0;
    for(int i=n-1; i>=0; i--){
        if(arr[i][i]==1){
            cnt++;
            for(int x=0; x<=i; x++){
                for(int y=0; y<=i; y++){
                    arr[x][y] ^= 1;
                }
            }
        }

        if(i-1>=0){
            for(int j=i-1; j>=0; j--){
                if(arr[i][j]==1){
                    cnt++;
                    for(int x=0; x<=i; x++){
                        for(int y=0; y<=j; y++){
                            arr[x][y] ^= 1;
                        }
                    }
                }

                if(arr[j][i]==1){
                    cnt++;
                    for(int x=0; x<=j; x++){
                        for(int y=0; y<=i; y++){
                            arr[x][y] ^= 1;
                        }
                    }
                }
            }
        }
    }

    cout<<cnt;
    return 0;
}
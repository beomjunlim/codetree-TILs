#include <iostream>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    int arr[101][101];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            arr[i][j] = (int)1e9;
        }
        arr[i][i] = 0;
    }

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        arr[a][b] = 1;
        arr[b][a] = 2;
    }


    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(arr[i][j]==(int)1e9){
                    if(arr[i][k]==arr[k][j])
                        arr[i][j] = arr[i][k];
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        int cnt = 0;
        for(int j=1; j<=n; j++){
            if(arr[i][j]==(int)1e9)
                cnt++;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
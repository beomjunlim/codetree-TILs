#include <iostream>
using namespace std;

int n,m;
int arr[101][101];

int main() {
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j)
                arr[i][j] = 1;
        }
    }

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        arr[a][b] = 1;
        arr[b][a] = -1;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(arr[i][k]==1&&arr[k][j]==1)
                    arr[i][j] = 1;
                if(arr[i][k]==-1&&arr[k][j]==-1)
                    arr[i][j] = -1;
            }
        }
    }    

    for(int i=1; i<=n; i++){
        int cnt = 0;
        for(int j=1; j<=n; j++){
            if(arr[i][j]==0)
                cnt++;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
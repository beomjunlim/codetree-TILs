#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,m,p,q;
    cin>>n>>m>>p>>q;

    int arr[201][201];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            arr[i][j] = (int)1e9;
        }
        arr[i][i] = 0;
    }

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[a][b] = c;
    }


    int ans = 0;
    long long cnt = 0;

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(arr[i][j]>arr[i][k]+arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    for(int i=0; i<q; i++){
        int a,b;
        cin>>a>>b;
        int distance =1e9;
        for(int j=1; j<=p; j++){
            distance = min(distance, arr[a][j] + arr[j][b]);
        }

        if(distance>=(int)1e9)
            continue;
        
        ans++;
        cnt += distance;
    }
    
    cout<<ans<<'\n';
    cout<<cnt<<'\n';
    return 0;
}
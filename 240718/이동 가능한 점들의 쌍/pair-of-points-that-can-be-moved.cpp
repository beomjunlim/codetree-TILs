#include <iostream>
using namespace std;

int main() {
    int n,m,p,q;
    cin>>n>>m>>p>>q;

    int arr[201][201];
    bool visited[201][201] = {false};

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
        if(a<=p||b<=p)
            visited[a][b] = true;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if((i<=p||j<=p)&&arr[i][j]!=(int)1e9)
                visited[i][j] = true;
        }
    }

    int ans = 0;
    long long cnt = 0;

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(arr[i][j]>arr[i][k]+arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];

                    if(k<=p||visited[i][k]||visited[k][j])
                        visited[i][j] = true;
                }
            }
        }
    }

    for(int i=0; i<q; i++){
        int a,b;
        cin>>a>>b;
        if(visited[a][b]){
            ans++;
            cnt+=arr[a][b];
        }
    }
    
    cout<<ans<<'\n';
    cout<<cnt<<'\n';
    return 0;
}
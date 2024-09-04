#include <iostream>
using namespace std;

int arr[4001];

int main() {
    int n,m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            arr[b] = c;
        }
        else if(a==2){
            for(int j=b; j<=c; j++){
                arr[j] ^= 1;
            }
        }
        else if(a==3){
            for(int j=b; j<=c; j++){
                arr[j] = 0;
            }

        }
        else if(a==4){
            for(int j=b; j<=c; j++){
                arr[j] = 1;
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
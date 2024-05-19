#include <iostream>
using namespace std;

int n,m,k;
int arr[100][100];

int main() {
    cin>>n>>k>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    
    bool sw;
    m = m-1;

    for(int i=0; i<n-1; i++){
        sw = false;
        for(int j=m; j<m+k; j++){
            if(arr[i+1][j]==1){
                sw = true;
            }
        }

        if(sw){
            for(int j=m; j<m+k; j++){
                arr[i][j] = 1;
            }
            break;
        }
    }

    if(n==1){
        for(int j=m; j<m+k; j++){
            arr[0][j] = 1;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
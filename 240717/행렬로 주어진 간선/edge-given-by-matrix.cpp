#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int arr[101][101];
    int dist[101][101];



    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dist[i][j] = (int)1e9;
        }
        dist[i][i] = 1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            dist[i][j] = arr[i][j];
        }
        dist[i][i] = 1;
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][k]!=0&&dist[k][j]!=0)
                    dist[i][j] = 1;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(dist[i][j]==(int)1e9)
                cout<<0<<" ";
            else
                cout<<dist[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int Map[501][501];
int Up[501][501];
int Down[501][501];

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>Map[i][j];
        }
    }   

    Up[n-1][0] = Map[n-1][0];
    Down[n-1][m-1] = Map[n-1][m-1];

    for(int i=n-2; i>=0; i--){
        Up[i][0] = Up[i+1][0] + Map[i][0];
        Down[i][m-1] = Down[i+1][m-1] + Map[i][m-1]; 
    }

    for(int i=1; i<m; i++){
        Up[n-1][i] = Up[n-1][i-1] + Map[n-1][i];
    }

    for(int i=m-2; i>=0; i--){
        Down[n-1][i] = Down[n-1][i+1] + Map[n-1][i];
    }

    for(int i=n-2; i>=0; i--){
        for(int j=1; j<m; j++){
            Up[i][j] = max(Up[i+1][j], Up[i][j-1]) + Map[i][j];
        }
    }

    for(int i=n-2; i>=0; i--){
        for(int j=m-2; j>=0; j--){
            Down[i][j] = max(Down[i+1][j], Down[i][j+1]) + Map[i][j];
        }
    }

    int ans = -987654321;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans = max(ans, Up[i][j] + Down[i][j]);
        }
    }

    cout<<ans;

    return 0;
}
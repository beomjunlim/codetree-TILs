#include <iostream>
using namespace std;

int arr[201][201];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        x += 100;
        y += 100;

        for(int j=x; j<x+8; j++){
            for(int k=y; k<y+8; k++){
                arr[k][j] = 1;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<201; i++){
        for(int j=0; j<201; j++){
            if(arr[i][j]==1)
                ans++;
        }
    }

    cout<<ans;
    return 0;
}
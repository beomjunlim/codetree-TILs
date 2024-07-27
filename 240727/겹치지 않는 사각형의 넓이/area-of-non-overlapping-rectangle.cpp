#include <iostream>
using namespace std;

int arr[2001][2001];
int main() {
    
    for(int i=0; i<2; i++){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        x1 += 1000;
        y1 += 1000;
        x2 += 1000;
        y2 += 1000;
        for(int j=x1; j<x2; j++){
            for(int k=y1; k<y2; k++){
                arr[k][j] = 1;
            }
        }
    }

    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    x1 += 1000;
    y1 += 1000;
    x2 += 1000;
    y2 += 1000;
    for(int i=x1; i<x2; i++){
        for(int j=y1; j<y2; j++){
            arr[j][i] = 0;
        }
    }

    int ans = 0;
    for(int i=0; i<2001; i++){
        for(int j=0; j<2001; j++){
            if(arr[i][j]==1)
                ans++;
        }
    }

    cout<<ans;
    return 0;
}
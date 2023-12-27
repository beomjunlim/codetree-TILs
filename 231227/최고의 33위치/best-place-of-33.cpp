#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 20

int arr[MAX][MAX];

int GetCoin(int x, int y){
    int num = 0;
    for(int i=x; i<x+3; i++){
        for(int j=y; j<y+3; j++){
            if(arr[i][j]==1)
                num +=1;
        }
    }
    return num;
}

int main() {
    int n;
    int max_coin = 0;
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i+2<n&&j+2<n){
                int num = GetCoin(i,j);
                max_coin = max(max_coin, num);
            }

        }
    }

    cout<<max_coin;
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int ans = 0;
int arr[21][21];

int getGold(int row, int col, int k){
    int num = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(abs(row-i) + abs(col-j) <=k)
                num += arr[i][j];
        }
    }
    return num;
}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=1; k<=2*(n-1); k++){
                int num = getGold(i,j,k);
                int price = k*k + (k+1)*(k+1);
                if(num*m >= price)
                    ans = max(ans, num);
            }
        }
    }
    
    cout<<ans;
    return 0;
}
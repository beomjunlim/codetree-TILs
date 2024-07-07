#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int ans = 0;
int arr[21][21];

void check(int low, int col, int size){
    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int a = abs(low-i);
            int b = abs(col-j);

            if(a+b<=size){
                if(arr[i][j]==1)
                    sum++;
            }
        }
    }
    int cost = (size*size + (size+1)*(size+1));

    if(sum*m>=cost)
        ans = max(ans,sum);
}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int k=0; k<=2*(n-1); k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                check(i,j,k);
            }
        }
    }

    cout<<ans;
    return 0;
}
#include <iostream>
#include <climits>
using namespace std;

#define MAX 500
int arr[MAX][MAX];
int ans[MAX][MAX];

int main() {
    int n, k;
    cin>>n>>k;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    ans[0][0] = arr[0][0];
    for(int i=1; i<n; i++){
        ans[0][i] = arr[0][i] + ans[0][i-1];
        ans[i][0] = arr[i][0] + ans[i-1][0];
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            ans[i][j] = arr[i][j] + ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1];
        }
    }

    int sum = INT_MIN;
    if(k==1){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                sum = max(sum, arr[i][j]);
            }
        }
    }
    else{
        for(int i=n-1; n-k<=i; i--){
            for(int j=n-1; n-k<=j; j--){
                if(i-k<0&&j-k<0){
                    sum = max(sum, ans[i][j]);
                }
                else if(i-k<0){
                    sum = max(sum, ans[i][j] - ans[i][j-k]);
                }
                else if(j-k<0){
                    sum = max(sum, ans[i][j] - ans[i-k][j]);
                }
                else{
                    sum = max(sum, ans[i][j] - ans[i-k][j] - ans[i][j-k] + ans[i-k][j-k]);
                }  
            }
        }
    }


    cout<<sum;
    return 0;
}
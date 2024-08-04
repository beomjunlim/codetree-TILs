#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[101][101];
int max_num[101][101];

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            max_num[i][j] = max(min(max_num[i-1][j], max_num[i][j-1]), arr[i][j]);
        }
    }

    int ans = (int)1e9;
    for(int lower_bound = 1; lower_bound<=100; lower_bound++){
        int upper_bound;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j]<lower_bound)
                    arr[i][j] = (int)1e9;
                max_num[i][j] = (int)1e9;
            }
        }

        max_num[0][0] = arr[0][0];

        for(int i=1; i<n; i++){
            max_num[0][i] = max(max_num[0][i-1], arr[0][i]);
            max_num[i][0] = max(max_num[i-1][0], arr[i][0]);
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<n; j++){
                max_num[i][j] = max(min(max_num[i-1][j], max_num[i][j-1]), arr[i][j]);
            }
        }

        upper_bound = max_num[n-1][n-1];

        if(upper_bound == (int)1e9)
            continue;
        
        ans = min(ans, upper_bound - lower_bound);
    }

    cout<<ans;
    return 0;
}
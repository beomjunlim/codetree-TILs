#include <iostream>
using namespace std;

int n,t;
int arr[3][201];

int main() {
    cin>>n>>t;

    for(int i=0; i<3; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<t; i++){
        int temp_one = arr[0][n-1];
        int temp_two = arr[1][n-1];
        int temp_thr = arr[2][n-1];

        for(int j=n-1; j>0; j--){
            arr[0][j] = arr[0][j-1];
            arr[1][j] = arr[1][j-1];
            arr[2][j] = arr[2][j-1];
        }
        arr[0][0] = temp_thr;
        arr[1][0] = temp_one;
        arr[2][0] = temp_two;
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
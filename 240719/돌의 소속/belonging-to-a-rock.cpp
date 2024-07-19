#include <iostream>
using namespace std;


int arr[100001] = {0};
int sum[100001][3] = {0};

int GetSum(int s, int e, int cnt) {
    if(s == 0) return sum[e][cnt];
    return sum[e][cnt] - sum[s - 1][cnt];
}

int main() {
    int n,q;
    cin>>n>>q;

    for(int i=1; i<=n; i++){
        int a = 0, b = 0, c = 0;
        cin>>arr[i];
        if(arr[i]==1)
            a = 1;
        else if(arr[i]==2)
            b = 1;
        else
            c = 1;
        sum[i][0] = sum[i-1][0] + a;
        sum[i][1] = sum[i-1][1] + b;
        sum[i][2] = sum[i-1][2] + c;
    }

    for(int i=0; i<q; i++){
        int a,b;
        cin>>a>>b;
        cout<<GetSum(a, b, 0)<<" "<<GetSum(a, b, 1)<<" "<<GetSum(a, b, 2)<<'\n';
    }
    return 0;
}
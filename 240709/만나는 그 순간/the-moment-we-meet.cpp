#include <iostream>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    long long A[1000001];
    long long B[1000001];

    int idx_a = 0;
    int idx_b = 0;
    A[idx_a++] = 0;
    B[idx_b++] = 0;

    for(int i=0; i<n; i++){
        char s;
        int x;
        cin>>s;
        cin>>x;
        for(int j=0; j<x; j++){
            if(s=='L'){
                A[idx_a] = A[idx_a-1] -1;
            }
            if(s=='R'){
                A[idx_a] = A[idx_a-1] + 1;
            }
            idx_a++;
        }
    }

    for(int i=0; i<m; i++){
        char s;
        int x;
        cin>>s;
        cin>>x;
        for(int j=0; j<x; j++){
            if(s=='L'){
                B[idx_b] = B[idx_b-1] -1;
            }
            if(s=='R'){
                B[idx_b] = B[idx_b-1] + 1;
            }
            idx_b++;
        }
    }


    int ans = -1;
    for(int i=1; i<idx_a; i++){
        if(A[i]==B[i]){
            ans = i;
            break;
        }
    }

    cout<<ans;
    return 0;
}
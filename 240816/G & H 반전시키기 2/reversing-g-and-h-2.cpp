#include <iostream>
using namespace std;

int A[1001];
int B[1001];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        char a;
        cin>>a;

        if(a=='G')
            A[i] = 0;
        if(a=='H')
            A[i] = 1;
    }

    for(int i=0; i<n; i++){
        char a;
        cin>>a;

        if(a=='G')
            B[i] = 0;
        if(a=='H')
            B[i] = 1;
    }

    int cnt = 0;
    for(int i=n-1; i>=0; i--){
        if(A[i]!=B[i]&&cnt%2==0)
            cnt++;
        if(A[i]==B[i]&&cnt%2==1)
            cnt++;
    }

    cout<<cnt;
    return 0;
}
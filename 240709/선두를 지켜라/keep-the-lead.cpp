#include <iostream>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    int A[10000001];
    int B[10000001];
    A[0] = 0;
    B[0] = 0;
    int a = 1;
    int b = 1;
    int sum = 0;

    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        for(int j=1; j<=y; j++){
            A[a] = A[a-1] + x;
            a++;
        }
        sum +=y;
    }

    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        for(int j=1; j<=y; j++){
            B[b] = B[b-1] + x;
            b++;
        }
    }

    int ans = 0;
    int num = 0;
    for(int i=1; i<=sum; i++){
        if(num==0&&A[i]!=B[i]){
            if(A[i]>B[i])
                num = 1;
            if(A[i]<B[i])
                num = 2;
        }
        if(num!=0&&A[i]!=B[i]){
            if(num==1){
                if(A[i]<B[i]){
                    ans++;
                    num = 2;
                }
            }
            else if(num==2){
                if(A[i]>B[i]){
                    ans++;
                    num = 1;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
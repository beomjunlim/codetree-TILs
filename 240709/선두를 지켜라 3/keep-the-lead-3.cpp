#include <iostream>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    int A[1000001];
    int B[1000001];
    int a = 1;
    int b = 1;
    A[0] = 0;
    B[0] = 0;

    int sum = 0;

    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        for(int j=0; j<y; j++){
            A[a] = A[a-1] + x;
            a++;
        }
        sum += y;
    }

    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        for(int j=0; j<y; j++){
            B[b] = B[b-1] + x;
            b++;
        }
    }


    int num = 0;
    int ans = 0;
    int pre = num;
    for(int i=0; i<sum; i++){
        if(A[i]!=B[i]){
            if(A[i]>B[i])
                num = 1;
            if(A[i]<B[i])
                num = 2;
        }
        if(A[i]==B[i])
            num = 0;
            
        if(pre!=num)
            ans++;
        
        pre = num;
    }
    cout<<ans;

    return 0;
}
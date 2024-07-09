#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    int A[1000001];
    int B[1000001];
    A[0] = 0;
    B[0] = 0;
    int a = 1;
    int b = 1;
    int sum_a = 0;

    for(int i=0; i<n; i++){
        int x;
        char y;
        cin>>x;
        cin>>y;
        for(int j=0; j<x; j++){
            if(y=='L'){
                A[a] = A[a-1] - 1;
            }
            if(y=='R'){
                A[a] = A[a-1] + 1;
            }
            a++;
        }
        sum_a +=x;
    }

    int sum_b = 0;
    for(int i=0; i<m; i++){
        int x;
        char y;
        cin>>x;
        cin>>y;
        for(int j=0; j<x; j++){
            if(y=='L'){
                B[b] = B[b-1] - 1;
            }
            if(y=='R'){
                B[b] = B[b-1] + 1;
            }
            b++;
        }
        sum_b += x;
    }
    
    int num = max(sum_b, sum_a);

    if(num==sum_b){
        int number = A[sum_a];
        for(int i=sum_a; i<num; i++)
            A[i] = number;
    }

    if(num==sum_a){
        int number = B[sum_b];
        for(int i=sum_b; i<num; i++)
            B[i] = number;
    }

    
    bool sw = true;
    int ans = 0;
    for(int i=1; i<=num; i++){
        if(A[i]==B[i]&&!sw){
            sw = true;
            ans++;
        }
        if(A[i]!=B[i]){
            sw = false;
        }
    }
    cout<<ans;
    return 0;
}
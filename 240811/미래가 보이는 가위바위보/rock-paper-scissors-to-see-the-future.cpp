#include <iostream>
#include <algorithm>
using namespace std;

int H[100001];
int S[100001];
int P[100001];
int h[100001];
int s[100001];
int p[100001];
int arr[100001]; // H 0 S 1 P 2
// H > S S > P P > H
// 0 > 1 1 > 2 2 > 0

int main() {
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        char a;
        cin>>a;
        int num;
        if(a=='H')
            num = 0;
        if(a=='S')
            num = 1;
        if(a=='P')
            num = 2;
        arr[i] = num;
    }

    for(int i=1; i<=n; i++){
        int a = 0, b = 0, c = 0;

        if(arr[i]==0)
            c = 1;
        if(arr[i]==1)
            a = 1;
        if(arr[i]==2)
            b = 1;
        
        H[i] = H[i-1] + a;
        S[i] = S[i-1] + b;
        P[i] = P[i-1] + c;
    }

    for(int i=n; i>=1; i--){
        int a = 0, b = 0, c = 0;
        if(arr[i]==0)
            c = 1;
        if(arr[i]==1)
            a = 1;
        if(arr[i]==2)
            b = 1;
        if(i==n){
            h[i] = a;
            s[i] = b;
            p[i] = c;
        }
        else{
            h[i] = h[i+1] + a;
            s[i] = s[i+1] + b;
            p[i] = p[i+1] + c;
        }
    }

    int ans = max(H[n], max(S[n], P[n]));
    
    for(int i=2; i<=n; i++){
        int a = 0, b = 0, c = 0;
        if(arr[i]==0)
            c = 1;
        if(arr[i]==1)
            a = 1;
        if(arr[i]==2)
            b = 1;
        
        ans = max(ans, max(H[i-1] + p[i], max(H[i-1] + s[i],
        max(S[i-1] + h[i], max(S[i-1] + p[i],
        max(P[i-1] + h[i], P[i-1] + s[i]))))));
    }

    cout<<ans;
    return 0;
}
/*
H -> S
H -> P
S -> P
S -> H
P -> S
P -> H
P
S
H
*/
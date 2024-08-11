#include <iostream>
#include <algorithm>
using namespace std;

int H[100001];
int S[100001];
int P[100001];
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

    int ans = max(H[n], max(S[n], P[n]));
    for(int i=1; i<n; i++){
        int a = 0, b = 0, c = 0;
        if(arr[i]==0)
            c = 1;
        if(arr[i]==1)
            a = 1;
        if(arr[i]==2)
            b = 1;
        
        ans = max(ans, max(H[i-1] + S[n] - S[i-1] + b, max(H[i-1] + P[n] - P[i-1] + c,
        max(S[i-1] + H[n] - H[i-1] + a, max(S[i-1] + P[n] - P[i-1] + c,
        max(P[i-1] + H[n] - H[i-1] + a, P[i-1] + S[n] - S[i-1] + b))))));
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
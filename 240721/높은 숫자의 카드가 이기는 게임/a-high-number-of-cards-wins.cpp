#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;

    int B[50001];
    unordered_set<int> b;
    for(int i=0; i<n; i++){
        cin>>B[i];
        b.insert(B[i]);
    }

    int A[50001];
    int idx = 0;
    for(int i=1; i<=2*n; i++){
        if(b.find(i)==b.end()){
            A[idx] = i;
            idx++;
        }
    }

    sort(A, A+n);
    sort(B, B+n);

    int ans = 0;
    int card = B[0];
    idx = 0;
    for(int i=0; i<n; i++){
        if(card < A[i]){
            ans++;
            idx++;
            card = B[idx];
        }
    }

    cout<<ans;
    return 0;
}
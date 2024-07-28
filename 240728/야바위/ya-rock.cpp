#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    char arr[4];
    arr[1] = 'A';
    arr[2] = 'B';
    arr[3] = 'C'; 
    int A = 0, B = 0, C = 0;
    for(int i=0; i<n; i++){
        int a,b,c;
        cin>>a>>b>>c;
        swap(arr[a],arr[b]);
        if(arr[c]=='A')
            A++;
        if(arr[c]=='B')
            B++;
        if(arr[c]=='C')
            C++;
    }

    int ans = max(A, max(B,C));
    cout<<ans;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int A[1001];
int B[1001];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        char a;
        cin>>a;
        int num;
        if(a=='G')
            num = 1;
        if(a=='H')
            num = 0;
        A[i] = num;
    }

    for(int i=0; i<n; i++){
        char a;
        cin>>a;
        int num;
        if(a=='G')
            num = 1;
        if(a=='H')
            num = 0;
        B[i] = num;
    }

    vector<int> v;
    for(int i=0; i<n; i++){
        if(A[i]!=B[i]){
            v.push_back(i);
        }
    }

    int ans = 0;
    int start = v[0];

    for(int i=1; i<v.size(); i++){
        if(v[i]-1!=start){
            ans++;
        }
        start = v[i];
    }
    ans++;
    cout<<ans;
    return 0;
}
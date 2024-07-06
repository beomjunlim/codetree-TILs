#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n,m;
    int A[101];
    unordered_map<int,int> B;

    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>A[i];

    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        B[x]++;
    }

    int ans = 0;

    for(int i=0; i<=n-m; i++){
        unordered_map<int,int> copy = B;
        for(int j=i; j<i+m; j++){
            if(copy.find(A[j])!=copy.end()){
                copy[A[j]]--;
                if(copy[A[j]]==0)
                    copy.erase(A[j]);
            }
        }
        if(copy.empty())
            ans++;
    }

    cout<<ans;
    return 0;
}
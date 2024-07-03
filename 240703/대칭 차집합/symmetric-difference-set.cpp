#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<long long> A;
unordered_set<long long> B;
int n,m;

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        long long a;
        cin>>a;
        A.insert(a);
    }

    for(int i=0; i<m; i++){
        long long a;
        cin>>a;
        B.insert(a);
    }


    int ans = 0;
    for(auto it : A){
        if(B.find(it)==B.end()){
            ans++;
        }
    }

    for(auto it : B){
        if(A.find(it)==A.end()){
            ans++;
        }
    }

    cout<<ans;

    return 0;
}
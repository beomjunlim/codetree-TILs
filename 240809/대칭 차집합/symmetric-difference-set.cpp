#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    unordered_set<int> A;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        A.insert(a);
    }

    unordered_set<int> B;
    
    int cnt = 0;
    for(int i=0; i<m; i++){
        int b;
        cin>>b;
        B.insert(b);
        if(A.find(b)!=A.end())
            cnt++;
    }

    cout<<A.size() + B.size() - 2*cnt;

    return 0;
}
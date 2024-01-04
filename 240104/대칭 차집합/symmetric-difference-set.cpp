#include <iostream>
#include <unordered_set>
using namespace std;

#define MAX 200000
int A[MAX];
int B[MAX];

int main() {
    unordered_set<int> s_A;
    unordered_set<int> s_B;
    int n, m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>A[i];
        s_A.insert(A[i]);
    }

    for(int i=0; i<m; i++){
        cin>>B[i];
        s_B.insert(B[i]);
    }

    int cnt = 0;

    for(int i=0; i<m; i++){
        if(s_A.find(B[i])!=s_A.end())
            s_A.erase(B[i]);
    }

    for(int i=0; i<n; i++){
        if(s_B.find(A[i])!=s_B.end())
            s_B.erase(A[i]);
    }
    cnt = (s_A.size() + s_B.size());
    cout<<cnt;
    return 0;
}
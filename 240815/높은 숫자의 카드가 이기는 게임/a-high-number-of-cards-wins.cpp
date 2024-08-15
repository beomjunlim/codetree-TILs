#include <iostream>
#include <set>
using namespace std;

int visited[100001];
int B[50001];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>B[i];
        visited[B[i]] = true;
    }

    set<int> A;

    for(int i=1; i<=2*n; i++){
        if(!visited[i])
            A.insert(i);
    }


    int ans = 0;
    for(int i=0; i<n; i++){
        auto it = A.upper_bound(B[i]);
        if(it!=A.end()){
            int num = *it;
            ans++;
            A.erase(num);
        }
    }

    cout<<ans;
    return 0;
}
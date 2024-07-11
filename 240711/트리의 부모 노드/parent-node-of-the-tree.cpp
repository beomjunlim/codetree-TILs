#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v[100001];

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v[y].push_back(x);
    }

    for(int i=2; i<=n; i++){
        cout<<v[i][0]<<'\n';
    }
    return 0;
}
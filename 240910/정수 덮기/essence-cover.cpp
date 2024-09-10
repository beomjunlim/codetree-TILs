#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n,l;
    cin>>n>>l;

    vector<int> v;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        v.push_back(a-1);
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int ans = 1;
    int start = v[0];
    for(int i=1; i<v.size(); i++){
        if(v[i]<=start+l)
            continue;
        else{
            start = v[i];
            ans++;
        }
    }

    cout<<ans;
    return 0;
}
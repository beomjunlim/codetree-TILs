#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    int num = 0;
    for(int i=n-1; i>=0; i--){
        num += (i+1)*v[n-1-i];
    }

    cout<<num;
    return 0;
}
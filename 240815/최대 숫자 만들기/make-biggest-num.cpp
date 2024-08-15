#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool cmp(int a, int b){
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

int main() {
    int n;
    cin>>n;

    vector<int> v;
    for(int i=0; i<n; i++){
        int str;
        cin>>str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<n; i++){
        cout<<v[i];
    }
    return 0;
}
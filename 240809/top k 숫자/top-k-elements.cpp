#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;

    set<int> s;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        s.insert(-a);
    }

    auto it = s.begin();
    for(int i=0; i<k; i++){
        cout<<-*it<<" ";
        it++;
    }
    return 0;
}
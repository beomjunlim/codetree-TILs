#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, k;
    cin>>n>>k;

    set<int> s;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        s.insert(a);
    }

    for(int i=0; i<k; i++){
        int num = *s.rbegin();
        cout<<num<<" ";
        s.erase(num);
    }
    return 0;
}
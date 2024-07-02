#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin>>n;
    unordered_set<long long> sets;

    for(int i=0; i<n; i++){
        long long a;
        cin>>a;
        sets.insert(a);
    }

    cout<<sets.size();
    return 0;
}
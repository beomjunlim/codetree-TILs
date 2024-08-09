#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin>>n;

    unordered_set<int> sets;

    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        sets.insert(num);
    }

    cout<<sets.size();
    return 0;
}
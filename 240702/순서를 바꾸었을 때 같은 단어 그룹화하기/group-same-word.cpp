#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

int n;
unordered_map<string, int> maps;

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        string a;
        cin>>a;
        sort(a.begin(), a.end());
        maps[a]++;
    }

    int ans = 0;
    for(auto it : maps){
        ans = max(ans, it.second);
    }
    cout<<ans;
    return 0;
}
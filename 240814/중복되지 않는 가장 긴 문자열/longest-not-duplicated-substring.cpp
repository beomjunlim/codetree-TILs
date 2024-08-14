#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    string str;
    cin>>str;

    int n = str.length();
    int ans = 0;
    set<char> arr;
    int j=0;
    for(int i=0; i<n; i++){
        while(j<n&&arr.find(str[j])==arr.end()){
            arr.insert(str[j]);
            j++;
        }

        ans = max(ans, j-i);
        arr.erase(str[i]);
    }

    cout<<ans;
    return 0;
}
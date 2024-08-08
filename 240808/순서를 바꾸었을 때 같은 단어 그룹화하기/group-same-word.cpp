#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int n;
vector<char> arr[1001];

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<s.length(); j++){
            arr[i].push_back(s[j]);
        }
    }

    unordered_map<string, int> word;

    for(int i=0; i<n; i++){
        sort(arr[i].begin(), arr[i].end());
    }

    for(int i=0; i<n; i++){
        string str = "";
        for(int j=0; j<arr[i].size(); j++){
            str += arr[i][j];
        }

        word[str]++;
    }

    int ans = 0;
    for(auto it : word)
        if(ans<it.second)
            ans = it.second;
        
    cout<<ans;

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int ans[26];

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        string a,b;
        cin>>a>>b;

        vector<int> freqA(26,0), freqB(26,0);

        for(char c : a){
            freqA[c - 'a']++;
        } 
        for(char c : b){
            freqB[c - 'a']++;
        }

        for(int j=0; j<26; j++){
            ans[j] += max(freqA[j],freqB[j]);
        }
    }

    for(int i=0; i<26; i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}
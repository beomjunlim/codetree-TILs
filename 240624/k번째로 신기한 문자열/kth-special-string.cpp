#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int main() {
    int n,k;
    string t;

    cin>>n>>k;
    cin>>t;

    vector<string> str(n);
    vector<string> word;

    for(int i=0; i<n; i++){
        cin>>str[i];

        if(str[i].find(t)==0)
            word.push_back(str[i]);
    }

    sort(word.begin(), word.end());

    cout<<word[k-1];
    return 0;
}
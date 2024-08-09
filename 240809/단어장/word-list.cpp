#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin>>n;

    map<string, int> word;

    for(int i=0; i<n; i++){
        string str;
        cin>>str;
        word[str]++;
    }

    for(auto it : word){
        cout<<it.first<<" "<<it.second<<'\n';
    }
    return 0;
}
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string str;
    cin>>str;

    unordered_map<char,int> maps;

    for(int i=0; i<str.length(); i++){
        maps[str[i]]++;
    }

    string ans = "None";
    for(int i=0; i<str.length(); i++){
        if(maps[str[i]]==1){
            ans = str[i];
            break;
        }
    }

    cout<<ans;
    return 0;
}
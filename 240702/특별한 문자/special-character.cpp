#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<char, int> maps;

int main() {
    bool sw = false;
    string str;
    cin>>str;

    for(int i=0; i<str.length(); i++){
        maps[str[i]]++;
    }

    for(auto it : maps){
        if(it.second==1){
            cout<<it.first;
            sw = true;
            break;
        }
    }

    if(!sw)
        cout<<"None";
    return 0;
}
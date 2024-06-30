#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    unordered_map<string, int> maps;

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        maps[s]++;
    }
    
    int num = 0;
    
    for(auto a : maps){
        if(num < a.second)
            num = a.second;
    }

    cout<<num;
    return 0;
}
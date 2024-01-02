#include <iostream>
#include <unordered_map>
using namespace std;

#define MAX 100000

int main() {
    int n;
    unordered_map<string,int> m;
    cin>>n;

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        m[s]+=1;
    }

    int max_num = 0;

    for(auto &s : m){
        if(max_num<s.second)
            max_num = s.second;
    }

    cout<<max_num;
    
    return 0;
}
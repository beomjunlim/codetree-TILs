#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    unordered_map<int, string> num;
    unordered_map<string, int> str;
    for(int i=1; i<=n; i++){
        string a;
        cin>>a;
        num[i] = a;
        str[a] = i;
    }

    for(int i=0; i<m; i++){
        string a;
        cin>>a;

        if(str.find(a)!=str.end())
            cout<<str[a]<<'\n';
        else
            cout<<num[stoi(a)]<<'\n';
    }
    return 0;
}
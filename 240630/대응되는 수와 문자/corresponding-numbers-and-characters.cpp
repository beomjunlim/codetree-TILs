#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    unordered_map<string, int> maps;
    string num[100001];

    for(int i=1; i<=n; i++){
        string a;
        cin>>a;
        maps[a] = i;
        num[i] = a;
    }

    for(int i=0; i<m; i++){
        string key;
        cin>>key;

        if('0'<=key[0]&&key[0]<='9')
            cout<<num[stoi(key)]<<'\n';
        else
            cout<<maps[key]<<'\n';
    }
    return 0;
}
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> arr;
    unordered_map<int, string> num;
    int n,m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        arr[s]=i;
        num[i]=s;
    }

    for(int i=0; i<m; i++){
        string s;
        cin>>s;
        if(arr[s]==0){
            cout<<num[stoi(s)]<<'\n';
        }
        else{
            cout<<arr[s]<<'\n';
        }
    }

    
    return 0;
}
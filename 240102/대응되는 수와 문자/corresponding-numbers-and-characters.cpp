#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> arr;
    int n,m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        arr[s]=i;
    }

    for(int i=0; i<m; i++){
        string s;
        cin>>s;
        if(arr[s]==0){
            for(auto & num : arr){
                if(num.second==stoi(s))
                    cout<<num.first<<'\n';
            }
        }
        else{
            cout<<arr[s]<<'\n';
        }
    }

    
    return 0;
}
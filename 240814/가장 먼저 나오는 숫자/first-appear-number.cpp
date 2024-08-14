#include <iostream>
#include <map>
using namespace std;

int arr[100001];

int main() {
    int n,m;
    cin>>n>>m;

    map<int,int> num;
    for(int i=1; i<=n; i++){
        cin>>arr[i];

        if(num.find(arr[i])==num.end())
            num[arr[i]] = i;
    }

    for(int i=0; i<m; i++){
        int a;
        cin>>a;
        if(num[a]==0)
            cout<<-1<<'\n';
        else
            cout<<num[a]<<'\n';
    }
    return 0;
}
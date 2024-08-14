#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int arr[100001];
int main() {
    int n,m;
    cin>>n>>m;
    
    map<int,int> num;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        num[arr[i]]++;
    }

    for(int i=0; i<m; i++){
        int a;
        cin>>a;
        cout<<num[a]<<'\n';
    }

    return 0;
}
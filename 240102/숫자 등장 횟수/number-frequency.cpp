#include <iostream>
#include <unordered_map>
using namespace std;

#define MAX 100000

int main() {
    unordered_map<int,int> arr;
    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        arr[a]+=1;
    }

    for(int i=0; i<m; i++){
        int a;
        cin>>a;
        cout<<arr[a]<<" ";
    }
    return 0;
}
#include <iostream>
#include <unordered_set>
using namespace std;

#define MAX 100000

int arr[MAX];
int num[MAX];

int main() {
    unordered_set<int> k;
    int n,m;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        k.insert(arr[i]);
    }

    cin>>m;

    for(int i=0; i<m; i++){
        int a;
        cin>>a;
        if(k.find(a)!=k.end())
            num[i] = 1;
        else
            num[i] = 0;
    }

    for(int i=0; i<m; i++){
        cout<<num[i]<<" ";
    }


    return 0;
}
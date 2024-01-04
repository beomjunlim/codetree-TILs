#include <iostream>
#include <unordered_set>
using namespace std;

#define MAX 100000
int arr[MAX];

int main() {
    unordered_set<int> s;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        s.insert(arr[i]);
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
        if(s.find(arr[i])!=s.end()){
            cnt+=1;
            s.erase(arr[i]);
        }
    }

    cout<<cnt;
    return 0;
}
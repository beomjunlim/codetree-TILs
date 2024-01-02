#include <iostream>
#include <unordered_map>
using namespace std;

#define MAX 100000

int arr[MAX];

int main() {
    unordered_map<long long, int> count;
    int n, k;
    cin>>n>>k;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int cnt = 0;

    for(int i=0; i<n; i++){
        long long diff = (long long)k - arr[i];

        cnt += count[diff];
        count[arr[i]]++;
    }

    cout<<cnt;
    return 0;
}
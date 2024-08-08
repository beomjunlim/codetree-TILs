#include <iostream>
#include <unordered_map>
using namespace std;

int arr[100001];

int main() {
    int n,k;
    cin>>n>>k;

    unordered_map<long long,int> num;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int cnt = 0;

    for(int i=0; i<n; i++){
        long long diff = (long long)k - arr[i];

        cnt += num[diff];
        num[arr[i]]++;
    }

    cout<<cnt;
    return 0;
}
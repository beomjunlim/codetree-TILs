#include <iostream>
#include <unordered_map>
using namespace std;

int arr[1001];

int main() {
    int n,k;
    cin>>n>>k;

    for(int i=0; i<n; i++)
        cin>>arr[i];

    int cnt = 0;

    for(int i=0; i<n-2; i++){
        int sum = k - arr[i];
        unordered_map<int,int> num;
        for(int j=i+1; j<n; j++){
            cnt += num[sum-arr[j]];
            num[arr[j]]++;
        }
    }

    cout<<cnt;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <map>
using namespace std; 

int arr[100001];

int main() {
    int n,m;
    cin>>n>>m;

    map<int,int> number;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        number[arr[i]] = i+1;
    }


    for(int i=0; i<m; i++){
        int num;
        cin>>num;
        int ans = -1;
        int start = 0;
        int end = n-1;

        while(start<=end){
            int mid = (start + end) / 2;

            if(arr[mid]==num){
                ans = mid+1;
                break;
            }

            if(arr[mid]<num)
                start = mid + 1;
            else
                end = mid - 1;
        }

        cout<<ans<<'\n';
    }

    return 0;
}
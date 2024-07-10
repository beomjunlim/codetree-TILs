#include <iostream>
using namespace std;

int main() {
    int n,m;
    long long arr[100001];

    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        int left = 0;
        int right = n-1;
        bool sw = false;

        while(left<=right){
            int mid = (left + right) / 2;
            if(arr[mid]==x){
                sw = true;
                cout<<mid+1<<'\n';
                break;
            }

            if(arr[mid]>x)
                right = mid - 1;
            if(arr[mid]<x)
                left = mid + 1;
        }
        if(!sw)
            cout<<-1<<'\n';
    }
    return 0;
}
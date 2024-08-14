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
        // int ans = -1;
        // int start = 0;
        // int end = n-1;

        // while(start<end){
        //     int mid = (start + end) / 2;

        //     if(arr[mid]==num){
        //         ans = number[num];
        //         break;
        //     }
        // }
        if(number[num]==0)
            cout<<-1<<'\n';
        else
            cout<<number[num]<<'\n';
    }
    return 0;
}
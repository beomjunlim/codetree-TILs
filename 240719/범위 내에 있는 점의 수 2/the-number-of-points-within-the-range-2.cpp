#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,q;
    cin>>n>>q;

    int arr[100001];
    int sum[100001] = {0};
    bool visited[100001] = {false};
    int max_num = 0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        visited[arr[i]] = true;
        max_num = max(max_num, arr[i]);
    }

    sort(arr, arr+n);
    int idx = 0;
    for(int i=1; i<=max_num; i++){
        if(i<arr[idx])
            sum[i] = sum[i-1];
        else{
            sum[i] = sum[i-1] + 1;
            idx++;
        }
    }

    for(int i=0; i<q; i++){
        int a,b;
        cin>>a>>b;
        if(a>max_num)
            sum[a] = sum[max_num];
        if(b>max_num)
            sum[b] = sum[max_num];
            
        if(visited[a]&&visited[b])
            cout<<sum[b] - sum[a] + 1<<'\n';
        else if(visited[a]&&!visited[b])
            cout<<sum[b] - sum[a] + 1<<'\n';
        else if(!visited[a]&&visited[b])
            cout<<sum[b] - sum[a]<<'\n';
        else if(!visited[a]&&!visited[b])
            cout<<sum[b] - sum[a]<<'\n';
    }

    return 0;
}
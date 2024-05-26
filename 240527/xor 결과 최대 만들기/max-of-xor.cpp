#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

int n,m;
int arr[20];
int ans[20];
int max_num = 0;
bool visited[20];


void backtracking(int num){
    if(num==m){
        int x,y,z;
        x = ans[0];
        for(int i=1; i<m; i++){
            y = ans[i];
            z = x^y;
            x = z;
        }
        max_num = max(max_num, x);
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            ans[num] = arr[i];
            backtracking(num+1);
            visited[i] = false;
        }
    }
}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    backtracking(0);
    cout<<max_num<<'\n';
    return 0;
}
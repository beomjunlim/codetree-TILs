#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100

int arr[MAX][MAX];
int n,m;

bool Column(int x){
    int max_cnt=0;
    int cnt =1;
    for(int i=1; i<n; i++){
        if(arr[i-1][x]==arr[i][x])
            cnt+=1;
        else
            cnt=1;
        max_cnt = max(max_cnt, cnt);
    }
    return max_cnt>=m;
}

bool Low(int x){
    int max_cnt=0;
    int cnt =1;
    for(int i=1; i<n; i++){
        if(arr[x][i-1]==arr[x][i])
            cnt+=1;
        else
            cnt=1;
        max_cnt = max(max_cnt, cnt);
    }
    return max_cnt>=m;
}


int main() {

    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    int cnt = 0;
    
    for(int i=0; i<n; i++){
        if(Column(i))
            cnt++;
        if(Low(i))
            cnt++;
    }
    cout<<cnt;
    return 0;
}
#include <iostream>
using namespace std;

int n,m;
int ans = 0;
int arr[21][21];

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

int check(int x, int y, int k, int l){
    int dx[] = {1,0,0,-1};
    int dy[] = {0,1,-1,0};
    int move[] ={k,l,l,k};

    if(!InRange(x+k-1,y+l-1))   return 0;

    for(int i=x; i<x+k; i++){
        for(int j=y; j<y+l; j++){
            if(arr[i][j]<0)
                return 0;
        }
    }
    return k*l;
}
int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=1; k<=n; k++){
                for(int l=1; l<=m; l++){
                    ans = max(ans,check(i,j,k,l));
                }
            }
        }
    }

    if(ans==0)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
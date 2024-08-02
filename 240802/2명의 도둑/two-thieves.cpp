#include <iostream>
#include <algorithm>
using namespace std;

int n,m,c; // m count c weight
int arr[11][11];
int a[11];
int ans = 0;
int max_val;

void FindMaxSum(int idx, int weight, int val){
    if(idx==m){
        if(weight<=c)
            max_val = max(max_val, val);
        return;
    }

    FindMaxSum(idx+1, weight, val); // 선택 하지 않음
    FindMaxSum(idx+1, weight + a[idx], val + a[idx]*a[idx]); // 선택함
}
int FindMax(int x, int y){
    for(int i=y; i<y+m; i++)
        a[i-y] = arr[x][i];
    
    max_val = 0;
    FindMaxSum(0,0,0);
    return max_val;
}

bool Possible(int x1, int y1, int x2, int y2){
    if(y1+m-1>=n||y2+m-1>=n)
        return false;
    
    if(x1!=x2)
        return true;
    
    int end_y1 = y1 + m -1;
    int end_y2 = y2 + m -1;

    if(y2<=y1&&y1<=end_y2)
        return false;
    if(y1<=y2&&y2<=end_y1)
        return false;
    
    return true;
}

int main() {
    cin>>n>>m>>c;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int x1=0; x1<n; x1++){
        for(int y1=0; y1<n; y1++){
            for(int x2=0; x2<n; x2++){
                for(int y2=0; y2<n; y2++){
                    if(Possible(x1,y1,x2,y2))
                        ans = max(ans,FindMax(x1,y1) + FindMax(x2,y2));
                }
            }
        }
    }

    cout<<ans;

    return 0;
}
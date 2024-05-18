#include <iostream>
#include <cstring>
using namespace std;

int n,m;
int arr[200][200];

void change(){
    int ans[200][200];
    memset(ans, 0, sizeof(ans));

    for(int j=0; j<n; j++){
        int idx = n-1;
        for(int i=n-1; i>=0; i--){
            if(arr[i][j]!=0){
                ans[idx][j] = arr[i][j];
                idx--;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j] = ans[i][j];
        }
    }
}

void bomb(int column){
    int num;
    int row;
    for(int i=0; i<n; i++){
        if(arr[i][column]!=0){
            row = i;
            num = arr[i][column];
            break;
        }
    }

    // 좌 우
    int start = 0;
    int end = n-1;

    if(column - num + 1>=0)
        start = column - num + 1;
    
    if(column + num -1 <n)
        end = column + num - 1;
    
    for(int i=start; i<=end; i++){
        arr[row][i] = 0;
    }

    // 위 아래
    start = 0;
    end = n-1;

    if(row - num + 1>=0)
        start = row - num + 1;
    
    if(row + num -1 <n)
        end = row + num - 1;
    
    for(int i=start; i<=end; i++){
        arr[i][column] = 0;
    }

    change();
}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<m; i++){
        int a;
        cin>>a;
        bomb(a-1);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
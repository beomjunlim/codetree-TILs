#include <iostream>
#include <cstring>
using namespace std;

int answer = 0;
int n;
int arr[50][50];
int ans[50][50];

void change(){
    int tmp[50][50];
    memset(tmp, 0, sizeof(tmp));

    for(int j=0; j<n; j++){
        int idx = n-1;
        for(int i=n-1; i>=0; i--){
            if(ans[i][j]!=0){
                tmp[idx][j] = ans[i][j];
                idx--;
            }
        }
    }

    int cnt = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int num = tmp[i][j];
            if(num!=0){
                if(j+1<n&&num==tmp[i][j+1]){
                    cnt++;
                }
                if(i+1<n&&num==tmp[i+1][j]){
                    cnt++;
                }
            }
        }
    }

    answer = max(answer, cnt);
}

void bomb(int row, int column){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans[i][j] = arr[i][j];
        }
    }

    int num = ans[row][column];

    // 좌 우
    int start = 0;
    int end = n-1;

    if(column - num + 1>=0)
        start = column - num + 1;
    
    if(column + num -1 <n)
        end = column + num - 1;
    
    for(int i=start; i<=end; i++){
        ans[row][i] = 0;
    }

    // 위 아래
    start = 0;
    end = n-1;

    if(row - num + 1>=0)
        start = row - num + 1;
    
    if(row + num -1 <n)
        end = row + num - 1;
    
    for(int i=start; i<=end; i++){
        ans[i][column] = 0;
    }

    change();
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            bomb(i, j);
        }
    }

    cout<<answer<<'\n';
    return 0;
}
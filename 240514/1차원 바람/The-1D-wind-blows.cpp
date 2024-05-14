#include <iostream>
#include <cstring>
using namespace std;

int n,m,q;
pair<int, char> wind[101];
int arr[101][101];
bool visited[101];

void func(int c_row, int c_dir){
    visited[c_row] = true;
        if(c_dir==0){
            int temp = arr[c_row][m-1];
            for(int i=m-2; i>=0; i--){
                arr[c_row][i+1] = arr[c_row][i];
            }
            arr[c_row][0] = temp;
        }
        else if(c_dir==1){
            int temp = arr[c_row][0];
            for(int i=0; i<m-1; i++){
                arr[c_row][i] = arr[c_row][i+1];
            }
            arr[c_row][m-1] = temp;
        }

        for(int i=0; i<m; i++){
            if(c_row-1>=0&&arr[c_row][i]==arr[c_row-1][i]&&!visited[c_row-1]){
                func(c_row-1, 1 - c_dir);
            }
        }

        for(int i=0; i<m; i++){
            if(c_row+1<n&&arr[c_row][i]==arr[c_row+1][i]&&!visited[c_row+1]){
                func(c_row+1, 1 - c_dir);
            }
        }
}

int main() {
    cin>>n>>m>>q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<q; i++){
        int a;
        char b;
        cin>>a>>b;
        wind[i].first = a;
        wind[i].second = b;
    }

    for(int i=0; i<q; i++){
        memset(visited, false, sizeof(visited));
        if(wind[i].second=='L'){
            func(wind[i].first-1, 0);
        }
        if(wind[i].second=='R'){
            func(wind[i].first-1, 1);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
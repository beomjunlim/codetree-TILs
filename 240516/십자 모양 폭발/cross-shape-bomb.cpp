#include <iostream>
using namespace std;

int n,r,c;
int arr[201][201];

void down(int y){
    for(int i=r; i>1; i--){
        arr[i][y] = arr[i-1][y];
    }
    arr[1][y] = 0;
}

void row(){
    int num = arr[r][c];
    int start = 1;
    int end = n;

    if(r-num+1>0)
        start = r - num + 1;
    
    if(r+num-1<=n)
        end = r + num - 1;

    for(int i=start-1; i>=1; i--){
        arr[end][c] = arr[i][c];
        end--;
    }

    for(int i=num+1; i>=1; i--){
        arr[i][c] = 0;
    }
}

void bomb(){
    int num = arr[r][c];
    int start = 1;
    int end = n;

    if(c-num+1>=1)
        start = c-num+1;
    
    if(c+num-1<=n)
        end = c+num-1;
    
    for(int i=start; i<=end; i++){
        if(i==c){
            row();
        }
        else{
            down(i);
        }
    }
}

int main() {
    cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    cin>>r>>c;
    bomb();
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }


    return 0;
}
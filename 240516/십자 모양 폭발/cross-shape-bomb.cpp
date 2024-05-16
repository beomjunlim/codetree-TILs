#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[201][201];

void Bomb(int x, int y){
    int num = arr[x][y];

    int start = 0;
    int end = n-1;

    if(y-num+1>=0)
        start = y - num + 1;

    if(y+num-1<n)
        end = y + num -1;
    
    for(int i=start; i<=end; i++){
        arr[x][i] = 0;
    }

    for(int i=start; i<=end; i++){
        if(i!=y){
            int idx = x;
            while(idx>0){
                swap(arr[idx][i], arr[idx-1][i]);
                idx--;
            }
        }
    }

    start = 0;
    end = n-1;

    if(x-num+1>=0)
        start = x - num + 1;
    
    if(x+num-1<n)
        end = x + num - 1;
    
    for(int i=start; i<=end; i++){
        arr[i][y] = 0;
    }

    while(start>=1){
        swap(arr[end][y], arr[start-1][y]);
        end--;
        start--;
    }
}

int main(){
    int r,c;
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    cin>>r>>c;

    Bomb(r-1,c-1);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
}
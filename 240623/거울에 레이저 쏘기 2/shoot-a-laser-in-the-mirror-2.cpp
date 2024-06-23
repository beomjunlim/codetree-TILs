#include <iostream>
using namespace std;

int n,k,x,y;
int dir = 0;
char arr[1001][1001];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

bool InRange(int a, int b){
    return 0<=a && a<n && 0<=b && b<n;
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    cin>>k;

    if(k%n==0){
        int quotient = k/n;
        if(quotient==1){
            x = 0;
            y = n-1;
            dir = 3;
        }
        else if(quotient==2){
            x = n-1;
            y = n-1;
            dir = 1;
        }
        else if(quotient==3){
            x = n-1;
            y = 0;
            dir = 2;
        }
        else if(quotient==4){
            x = 0;
            y = 0;
            dir = 0;
        }
    }
    else{
        int quotient = k/n;
        int remainder = k%n;

        if(quotient==0){
            x = 0;
            y = remainder - 1;
            dir = 3;
        }
        else if(quotient==1){
            x = remainder - 1;
            y = n - 1;
            dir = 1;
        }
        else if(quotient==2){
            x = n - 1;
            y = n - remainder;
            dir = 2;
        }
        else if(quotient==3){
            x = n - remainder;
            y = 0;
            dir = 0;
        }
    }

    int cnt = 0;

    while(InRange(x,y)){
        if(arr[x][y]=='/'){
            if(dir==0){
                dir = 2;
            }
            else if(dir==1){
                dir = 3;
            }
            else if(dir==2){
                dir = 0;
            }
            else if(dir==3){
                dir = 1;
            }
        }
        else{
            if(dir==0){
                dir = 3;
            }
            else if(dir==1){
                dir = 2;
            }
            else if(dir==2){
                dir = 1;
            }
            else if(dir==3){
                dir = 0;
            }
        }
        cnt++;
        x = x + dx[dir];
        y = y + dy[dir];
    }

    cout<<cnt<<'\n';

    return 0;
}
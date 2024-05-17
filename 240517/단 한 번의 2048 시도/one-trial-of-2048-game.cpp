#include <iostream>
#include <cstring>
using namespace std;

int arr[4][4];
int ans[4][4];

void change(char dir){
    memset(ans, 0, sizeof(ans));
    if(dir=='R'){
        for(int i=0; i<4; i++){
            int idx = 3;
            for(int j=3; j>=0; j--){
                if(arr[i][j]!=0){
                    ans[i][idx] = arr[i][j];
                    idx--;
                }
            }
        }
    }
    else if(dir=='L'){
        for(int i=0; i<4; i++){
            int idx = 0;
            for(int j=0; j<4; j++){
                if(arr[i][j]!=0){
                    ans[i][idx] = arr[i][j];
                    idx++;
                }
            }
        }
    }
    else if(dir=='U'){
        for(int j=0; j<4; j++){
            int idx = 0;
            for(int i=0; i<4; i++){
                if(arr[i][j]!=0){
                    ans[idx][j] = arr[i][j];
                    idx++;
                }
            }
        }
    }
    else if(dir=='D'){
        for(int j=0; j<4; j++){
            int idx = 3;
            for(int i=3; i>=0; i--){
                if(arr[i][j]!=0){
                    ans[idx][j] = arr[i][j];
                    idx--;
                }
            }
        }
    }

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            arr[i][j] = ans[i][j];
        }
    }
}

void shiftRight(int row){
    int num = arr[row][3];
    
    for(int i=2; i>=0; i--){
        if(num==arr[row][i]){
            arr[row][i+1] = num*2;
            arr[row][i] = 0;

        }
        num = arr[row][i];
    }
}

void shiftLeft(int row){
    int num = arr[row][0];

    for(int i=1; i<4; i++){
        if(num==arr[row][i]){
            arr[row][i-1] = num*2;
            arr[row][i] = 0;
        }
        num = arr[row][i];
    }
}

void shiftUp(int column){
    int num = arr[0][column];

    for(int i=1; i<4; i++){
        if(num==arr[i][column]){
            arr[i-1][column] = num*2;
            arr[i][column] = 0;
        }
        num = arr[i][column];
    }
}

void shiftDown(int column){
    int num = arr[3][column];

    for(int i=2; i>=0; i--){
        if(num==arr[i][column]){
            arr[i+1][column] = num*2;
            arr[i][column] = 0;
        }
        num = arr[i][column];
    }
}

int main() {
    char dir;

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin>>arr[i][j];
        }
    }

    cin>>dir;

    change(dir);


    if(dir=='L'){
        for(int i=0; i<4; i++){
            shiftLeft(i);
        }
    }

    else if(dir=='R'){
        for(int i=0; i<4; i++){
            shiftRight(i);
        }
    }

    else if(dir=='U'){
        for(int i=0; i<4; i++){
            shiftUp(i);
        }
    }
    else if(dir=='D'){
        for(int i=0; i<4; i++){
            shiftDown(i);
        }
    }

    change(dir);

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
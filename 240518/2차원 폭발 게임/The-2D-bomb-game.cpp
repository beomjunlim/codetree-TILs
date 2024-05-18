#include <iostream>
#include <cstring>
using namespace std;

int n,m,k;
int ans;
int arr[100][100];
void bomb();
void gravity();
void rotation();

void rotation(){
    int copy[100][100];
    memset(copy, 0, sizeof(copy));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            copy[j][i] = arr[n-i-1][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j] = copy[i][j];
        }
    }

    gravity();
}

void gravity(){
    int copy[100][100];
    memset(copy, 0, sizeof(copy));

    for(int i=0; i<n; i++){
        int idx = n-1;
        for(int j=n-1; j>=0; j--){
            if(arr[j][i]!=0){
                copy[idx][i] = arr[j][i];
                idx--;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j] = copy[i][j];
        }
    }
    bomb();
}

void bomb(){
    bool sw = false;
    int idx;
    int cnt;
    int num;

    for(int i=0; i<n; i++){
        idx=0;
        cnt=1;
        num=arr[idx][i];
        for(int j=idx+1; j<n; j++){
            if(num!=0){
                if(num==arr[j][i]){
                    cnt++;
                }
                else{
                    if(cnt>=m){
                        sw =true;
                        for(int l=idx; l<idx+cnt; l++){
                            ans--;
                            arr[l][i] = 0;
                        }
                    }
                    idx = j;
                    cnt = 1;
                    num = arr[idx][i];
                }
            }
            else{
                idx = j;
                cnt = 1;
                num = arr[idx][i];
            }
        }
        if(cnt>=m&&num!=0){
            sw = true;
            for(int l=idx; l<idx+cnt; l++){
                ans--;
                arr[l][i] = 0;
            }
        }
    }
    if(sw)
        gravity();
}

int main() {
    cin>>n>>m>>k;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            ans++;
        }
    }

    bomb();

    for(int i=0; i<k; i++){
        if(ans==0)
            break;
        rotation();
    }


    cout<<ans<<'\n';
    return 0;
}
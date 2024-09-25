#include <iostream>
#include <cstring>
using namespace std;

int n;
int answer = 0;
bool sw = false;
int arr[21];
int ans[21];

void backtracking(int cnt, int m){
    if(cnt==m){
        bool s = false;
        int carry[11] = {0};
        for(int i=0; i<cnt; i++){
            int num = ans[i];
            for(int j=0; num>0; j++, num/=10){
                carry[j] += num%10;
            }
        }

        for(int i=0; i<10; i++){
            if(carry[i]>=10)
                s = true;
        }
        if(!s){
            answer = m;
            sw = true;
        }
        return;
    }

    for(int i=0; i<n; i++){
        ans[cnt] = arr[i];
        backtracking(cnt+1, m);
    }
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=n; i>0; i--){
        memset(ans, 0, sizeof(ans));
        backtracking(0,i);

        if(sw)
            break;
    }    

    cout<<answer;
    return 0;
}
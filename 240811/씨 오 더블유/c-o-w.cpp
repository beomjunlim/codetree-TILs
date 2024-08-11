#include <iostream>
#include <set>
using namespace std;

char arr[100002];
int C[100002];
int W[100002];
int O[100002];

int main() {
    int n;
    cin>>n;

    set<int> O;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        if(arr[i]=='O'){
            O.insert(i);
        }
    }

    for(int i=1; i<=n; i++){
        if(arr[i]=='C')
            C[i] = C[i-1] + 1;
        else
            C[i] = C[i-1];
    }

    for(int i=n; i>0; i--){
        if(arr[i]=='W')
            W[i] = W[i+1] + 1;
        else
            W[i] = W[i+1];
    }

    long long cnt = 0;
    for(auto it : O){
        cnt += C[it-1]*W[it+1];
    }

    cout<<cnt;


    return 0;
}
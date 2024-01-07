#include <iostream>
using namespace std;

#define MAX 100000

int arr[MAX+1];
int one[MAX+1];
int two[MAX+1];
int thr[MAX+1];

int main() {
    int n,q;
    cin>>n>>q;

    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        arr[i] = x;

    }

    for(int i=1; i<=n; i++){
        if(arr[i]==1){
            one[i] = one[i-1] + 1;
            two[i] = two[i-1];
            thr[i] = thr[i-1];
        }
        else if(arr[i]==2){
            two[i] = two[i-1] + 1;
            one[i] = one[i-1];
            thr[i] = thr[i-1];
        }
        else{
            thr[i] = thr[i-1] + 1;
            one[i] = one[i-1];
            two[i] = two[i-1];
        }
    }

    while(q>0){
        int x,y;
        cin>>x>>y;
        cout<<one[y]-one[x-1]<<" "<<two[y]-two[x-1]<<" "<<thr[y]-thr[x-1]<<'\n';
        q--;
    }
    return 0;
}
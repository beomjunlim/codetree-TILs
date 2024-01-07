#include <iostream>
using namespace std;

#define MAX 1000000
int arr[MAX+1];
int num[MAX+1];

int main() {
    int n,q;
    cin>>n>>q;

    int max_num = 0;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr[x] = 1;
        max_num = max(max_num, x);
    }

    for(int i=1; i<=max_num; i++){
        num[i] = num[i-1] + arr[i];
    }

    while(q>0){
        int x,y;
        cin>>x>>y;
        if(x>max_num)
            num[x] = num[y] = num[max_num];
        
        else if(y>max_num)
            num[y] = num[max_num];

        cout<<num[y]-num[x-1]<<'\n';
        q--;
    }


    return 0;
}
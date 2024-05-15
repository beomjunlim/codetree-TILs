#include <iostream>
using namespace std;

int arr[101];
int temp[101];

int main() {
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }    

    int a,b;
    int size = n+1;
    int idx = 1;

    while(cin>>a>>b){
        idx = 1;
        for(int i=1; i<size; i++){
            if(i<a||i>b){
                temp[idx] = arr[i];
                idx++;
            }
        }

        for(int i=1; i<idx; i++){
            arr[i] = temp[i];
        }

        
        size = idx;
    }

    cout<<size-1<<'\n';
    for(int i=1; i<size; i++){
        cout<<arr[i]<<'\n';
    }


    return 0;
}
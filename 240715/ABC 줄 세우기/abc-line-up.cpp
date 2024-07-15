#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    char arr[27];
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(arr[i]-'A'!=i){
            int idx = i;
            for(int j=i+1; j<n; j++){
                if(arr[j]-'A'==idx){
                    int temp = arr[idx];
                    arr[idx] = arr[j];
                    for(int k=j; k>idx+1; k--){
                        arr[k] = arr[k-1];
                    }
                    arr[idx+1] = temp;
                    cnt += j-idx;
                }
            }
        }
    }

    cout<<cnt;
    return 0;
}
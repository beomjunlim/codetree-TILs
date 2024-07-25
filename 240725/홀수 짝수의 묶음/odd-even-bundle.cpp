#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int arr[1001];
    int odd = 0;
    int even = 0;

    for(int i=0; i<n; i++){
        cin>>arr[i];

        if(arr[i]%2==0)
            even++;
        if(arr[i]%2!=0)
            odd++;
    }

    if(even>odd+1){
        even = odd+1;
    }
    else{
        while(even<odd){
            odd-=2;
            even++;
        }
    }

    cout<<even+odd;
    return 0;
}
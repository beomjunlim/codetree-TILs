#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[21];

int main() {
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>arr[i];

    int ans = -1;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                bool carry = false;

                if(arr[i]%10 + arr[j]%10 + arr[k]%10 >= 10)
                    carry = true;

                if(arr[i]%100 / 10 + arr[j]%100 / 10 + arr[k]%100 / 10 >= 10)
                    carry = true;

                if(arr[i]%1000 / 100 + arr[j]%1000 / 100 + arr[k]%1000 / 100 >= 10)
                    carry = true;

                if(arr[i]%10000 / 1000 + arr[j]%10000 / 1000 + arr[k]%10000 / 1000 >= 10)
                    carry = true;
                
                if(carry == false)
                    ans = max(ans, arr[i] + arr[j] + arr[k]);
            }
        }
    }

    cout<<ans;
    return 0;
}
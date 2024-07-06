#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[101];
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<n; j++){
            int sum = 0;
            for(int k=j; k<j+i; k++){
                sum += arr[k];
            }

            double mean = (double)sum/i;
            bool sw = false;
            for(int k=j; k<j+i; k++){
                if(mean==arr[k]){
                    sw = true;
                }
            }

            if(sw)
                ans++;
        }
    }

    cout<<ans;
    return 0;
}
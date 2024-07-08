#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    int arr[101];
    cin>>n;

    int start = 101;
    int end = 0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        start = min(start, arr[i]);
        end = max(end, arr[i]);
    }

    int ans = 0;
    for(int i=start; i<=end; i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            for(int k=j+1; k<n; k++){
                int a = arr[j];
                int b = arr[k];
                if(abs(a-i)==abs(b-i))
                    sum++;
            }
        }
        ans = max(ans, sum);
    }
    cout<<ans;
    return 0;
}
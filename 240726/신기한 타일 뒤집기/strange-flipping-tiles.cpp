#include <iostream>
#include <algorithm>
using namespace std;

int arr[200001];

int main() {
    int n;
    cin>>n;

    int start = 100001;
    int end = -100001;
    int idx = 100000;

    for(int i=0; i<n; i++){
        int a;
        char b;
        cin>>a>>b;

        if(b=='R'){
            for(int j=idx; j<idx+a; j++)
                arr[j] = 1;
            idx = idx + a - 1;
        }
        else{
            for(int j=idx; j>idx-a; j--)
                arr[j] = 2;
            idx = idx - a + 1;
        }
        start = min(start, idx);
        end = max(end, idx);
    }

    int W = 0;
    int B = 0;
    for(int i=start; i<=end; i++){
        if(arr[i]==1)
            B++;
        if(arr[i]==2)
            W++;
    }

    cout<<W<<" "<<B;
    
    return 0;
}
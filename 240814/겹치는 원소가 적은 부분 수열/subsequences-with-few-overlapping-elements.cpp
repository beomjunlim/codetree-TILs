#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int arr[100001];

int main() {
    int n,k;
    cin>>n>>k;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    map<int,int> num;
    
    int ans = 0;
    int j=1;
    for(int i=1; i<=n; i++){
        while(j<=n){
            num[arr[j]]++;
            if(num[arr[j]]>k)
                break;

            j++;
        }


        ans = max(ans, j-i);
        num[arr[i]]--;
    }

    cout<<ans;
    return 0;
}
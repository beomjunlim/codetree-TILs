#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int arr[100001];

int main() {
    int n;
    cin>>n;

    set<int> height;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        height.insert(arr[i]);
    }

    int ans = 0;
    for(auto it : height){
        int count = 0;
        bool sw = false;
        for(int i=0; i<n; i++){
            if(arr[i]>it){
                sw = true;
            }
            else{
                if(sw)
                    count++;
                sw = false;
            }
        }
        if(sw)
            count++;
        ans = max(ans, count);
    }

    cout<<ans;
    return 0;
}
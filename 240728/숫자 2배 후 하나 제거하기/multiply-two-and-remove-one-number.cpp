#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[101];
    int temp[101];
    int ans = 987654321;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        temp[i] = arr[i];
    }
    
    for(int i=0; i<n; i++){
        temp[i] = 2*temp[i];
        
        for(int j=0; j<n; j++){
            int sum = 0;
            vector<int> v;
            for(int k=0; k<n; k++){
                if(k!=j){
                    v.push_back(temp[k]);
                }
            }

            for(int k=1; k<v.size(); k++){
                sum += abs(v[k-1] - v[k]);
            }
            ans = min(ans, sum);
        }

        temp[i] = arr[i];
    }


    cout<<ans;
    return 0;
}
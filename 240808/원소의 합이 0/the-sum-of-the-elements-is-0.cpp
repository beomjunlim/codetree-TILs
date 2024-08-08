#include <iostream>
#include <unordered_map>
using namespace std;

int arr[4][5001];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<4; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    unordered_map<int,int> freq_first;
    unordered_map<int,int> freq_second;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            freq_first[arr[0][i] + arr[1][j]]++;
            freq_second[arr[2][i] + arr[3][j]]++;
        }
    }

    int ans = 0;
    for(auto it : freq_first){
        int diff = -it.first;
        if(freq_second.find(diff)!=freq_second.end())
            ans += freq_second[diff]*it.second;
    }

    cout<<ans;
    return 0;
}
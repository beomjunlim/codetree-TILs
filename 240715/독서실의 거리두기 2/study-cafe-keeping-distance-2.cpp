#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    char arr[1001];

    cin>>n;

    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    vector<pair<int,int>> v;
    int idx = -1;

    for(int i=0; i<n; i++){
        if(arr[i]=='1'){
            if(idx==-1)
                v.push_back(make_pair(0,i));
            else{
                v.push_back(make_pair(idx,i));
            }
            idx = i;
        }

        if(i==n-1&&arr[i]=='0')
            v.push_back(make_pair(idx,i));
    }

    int ans = 0;
    for(int i=0; i<v.size(); i++){
        int x = v[i].first;
        int y = v[i].second;
        int num = (x+y)/2;
        if(arr[x]=='0'||arr[y]=='0')
            ans = max(ans, y-x);

        ans = max(ans, max(num-x,y-num));
    }

    cout<<ans;
    return 0;
}
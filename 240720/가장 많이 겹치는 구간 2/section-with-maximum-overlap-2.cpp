#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<pair<int,int>> arr;
    vector<pair<int,int>> point;

    int ans = 0;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        arr.push_back(make_pair(a,b));
    }

    for(int i=0; i<n; i++){
        int x = arr[i].first;
        int y = arr[i].second;
        point.push_back(make_pair(x,1));
        point.push_back(make_pair(y,-1));
    }

    sort(point.begin(), point.end());

    int sum = 0;
    for(int i=0; i<2*n; i++){
        int x = point[i].first;
        int y = point[i].second;
        sum += y;

        ans = max(ans, sum);
    }

    cout<<ans;
    return 0;
}
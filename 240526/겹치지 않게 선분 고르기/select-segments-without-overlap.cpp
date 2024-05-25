#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<pair<int,int>> line;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        line.push_back(make_pair(a,b));
    }

    sort(line.begin(), line.end(), cmp);

    int ans = 0;
    int end = 0;

    for(int i=0; i<n; i++){
        if(line[i].first>=end){
            ans++;
            end = line[i].second;
        }
    }

    cout<<ans<<'\n';
    return 0;
}
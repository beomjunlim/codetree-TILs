#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

int n,k;
int arr[100001];
unordered_set<int> num[100001];
vector<pair<int,int>> v;

int main() {
    cin>>n>>k;

    for(int i=1; i<=n; i++){
        arr[i] = i;
    }

    for(int i=0; i<k; i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }

    for(int i=1; i<=n; i++){
        num[i].insert(i);
    }

    for(int i=0; i<3*k; i++){
        int a = v[i%k].first;
        int b = v[i%k].second;

        swap(arr[a], arr[b]);

        if(num[arr[a]].find(a)==num[arr[a]].end())
            num[arr[a]].insert(a);
        
        if(num[arr[b]].find(b)==num[arr[b]].end())
            num[arr[b]].insert(b);
    }

    for(int i=1; i<=n; i++){
        cout<<num[i].size()<<'\n';
    }

    return 0;
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

pair<int, pair<int,int>> num[1001];

bool cmp(pair<int, pair<int,int>> a, pair<int, pair<int,int>> b){
    if(abs(a.second.first) + abs(a.second.second) == abs(b.second.first) + abs(b.second.second))
        return a.first < b.first;
    return abs(a.second.first) + abs(a.second.second) < abs(b.second.first) + abs(b.second.second);
}

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        num[i] = make_pair(i+1,make_pair(a,b));
    }

    sort(num, num+n, cmp);

    for(int i=0; i<n; i++){
        cout<<num[i].first<<'\n';
    }

    return 0;
}
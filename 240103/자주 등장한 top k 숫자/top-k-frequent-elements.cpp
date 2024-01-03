#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

#define MAX 100000

bool compare(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

int main() {
    unordered_map<int, int> num;
    vector<pair<int,int>> v;
    int n,k;
    cin>>n>>k;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        num[a]+=1;
    }

    for(auto & m : num){
            v.push_back(make_pair(m.first, m.second));
    }

    sort(v.begin(), v.end(), compare);
    
    for(int i=0; i<k; i++){
        cout<<v[i].first<<" ";
    }
    return 0;
}
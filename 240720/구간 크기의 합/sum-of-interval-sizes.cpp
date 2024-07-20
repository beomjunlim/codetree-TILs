#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
    int n;
    cin>>n;

    vector<pair<int,int>> arr;
    vector<pair<int,int>> point;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        arr.push_back(make_pair(a,b));    
    }

    for(int i=0; i<n; i++){
        int x = arr[i].first;
        int y = arr[i].second;
        point.push_back(make_pair(x,y));

    }

    sort(point.begin(), point.end(), cmp);
    
    int sum = 0;
    int start = point[0].first;
    int end = point[0].second;
    for(int i=1; i<n; i++){
        if(end<point[i].second){
            if(end<point[i].first){
                sum += end - start;
                start = point[i].first;
                end = point[i].second;
            }
            else{
                end = point[i].second;
            }
        }
    }

    sum += end - start;
    cout<<sum;

    return 0;
}
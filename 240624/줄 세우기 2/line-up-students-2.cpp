#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

pair<int, pair<int,int>> student[1001];

bool cmp(pair<int, pair<int,int>> a, pair<int, pair<int,int>> b){
    if(a.second.first == b.second.first)
        return a.second.second > b.second.second;
    return a.second.first < b.second.first;
}

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        student[i] = make_pair(i+1,make_pair(a,b));
    }

    sort(student, student + n, cmp);

    for(int i=0; i<n; i++){
        cout<<student[i].second.first<<" "<<student[i].second.second<<" "<<student[i].first<<'\n';
    }
    return 0;
}
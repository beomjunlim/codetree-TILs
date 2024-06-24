#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

pair<int, int> num[1001];

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

bool cmp_two(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        num[i] = make_pair(i+1,a);
    }

    sort(num, num+n, cmp);

    pair<int,int> sequence[1001];

    for(int i=0; i<n; i++){
        sequence[i] = make_pair(num[i].first, i+1);
    }

    sort(sequence, sequence + n, cmp_two);

    for(int i=0; i<n; i++){
        cout<<sequence[i].second<<" ";
    }
    return 0;
}
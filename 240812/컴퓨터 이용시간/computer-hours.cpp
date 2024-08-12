#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

int arr[1000001];
int ans[1000001];

int main() {
    int n;
    cin>>n;

    map<int,int> time;
    vector<pair<int,int>> v;
    map<int,int> people;
    set<int> seat;

    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        time[y] = x;
        v.push_back(make_pair(x,1));
        v.push_back(make_pair(y,-1));
        people[x] = i;
        seat.insert(i+1);
    }

    sort(v.begin(), v.end());

    for(int i=0; i<2*n; i++){
        if(v[i].second==1){
            int num = *seat.begin();
            ans[people[v[i].first]] = num;
            seat.erase(num);
        }
        else{
            seat.insert(ans[people[time[v[i].second]]]);
        }
    }

    for(int i=0; i<n; i++)
        cout<<ans[i]<<" ";
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> num;

    for(int i=1; i<=n; i++){
        int a;
        cin>>a;
        num.push_back(make_pair(a,1));
    }

    for(int j=1; j<=n; j++){
        int b;
        cin>>b;
        num.push_back(make_pair(b,-1));
    }

    sort(num.begin(), num.end());

    map<int,int> fire;
    bool sw = false;
    int A;

    for(int i=0; i<num.size(); i++){
        if(num[i].second==-1){
            A = num[i].first;
            sw = true;
        }
        else if(num[i].second==1){
            if(sw)
                fire[num[i].first] = num[i].first - A;
        }
    }

    sw = false;
    for(int i=num.size()-1; i>=0; i--){
        if(num[i].second==-1){
            A = num[i].first;
            sw = true;
        }
        else if(num[i].second==1){
            if(sw)
                fire[num[i].first] = min(fire[num[i].first], A - num[i].first);
        }
    }

    int ans = 0;
    for(auto it : fire){
        ans = max(ans, it.second);
    }

    cout<<ans;
    return 0;
}
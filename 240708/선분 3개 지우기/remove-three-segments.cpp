#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(), v.end(), cmp);
    
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                bool sw = false;
                int visited[101] = {};

                for(int x=0; x<n; x++){
                    if(x!=i&&x!=j&&x!=k){
                        for(int y=v[x].first; y<=v[x].second; y++){
                            visited[y]++;        
                        }
                    }
                }

                for(int x=0; x<=100; x++){
                    if(visited[x]>1)
                        sw = true;
                }

                if(!sw)
                    ans++;
            }
        }
    }

    cout<<ans;
    return 0;
}
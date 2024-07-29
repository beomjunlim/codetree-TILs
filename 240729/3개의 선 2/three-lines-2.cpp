#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<pair<int,int>> v;
vector<pair<int,int>> lines;
bool visited_x[11];
bool visited_y[11];

int main() {
    int n;
    cin>>n;
    unordered_set<int> X;
    unordered_set<int> Y;

    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
        X.insert(x);
        Y.insert(y);
    }

    for(auto it : X){
        lines.push_back(make_pair(it,1));
    }

    for(auto it : Y){
        lines.push_back(make_pair(it,-1));
    }

    int x[3] = {-1};
    int y[3] = {-1};
    int ans = 0;
    int num = lines.size();
    for(int i=0; i<num; i++){
        x[0] = -1;
        x[1] = -1;
        x[2] = -1;
        y[0] = -1;
        y[1] = -1;
        y[2] = -1;
        if(lines[i].second==1)
            x[0] = lines[i].first;
        if(lines[i].second==-1)
            y[0] = lines[i].first;
        for(int j=i+1; j<num; j++){
            if(lines[j].second==1){
                x[1] = lines[j].first;
                y[1] = -1;
            }
            if(lines[j].second==-1){
                x[1] = -1;
                y[1] = lines[j].first;
            }
            for(int k=j+1; k<num; k++){
                bool sw = true;
                if(lines[k].second==1){
                    x[2] = lines[k].first;
                    y[2] = -1;
                }
                if(lines[k].second==-1){
                    x[2] = -1;
                    y[2] = lines[k].first;
                }
                for(int m=0; m<n; m++){
                    if(v[m].first!=x[0]&&v[m].first!=x[1]&&v[m].first!=x[2]&&v[m].second!=y[0]&&v[m].second!=y[1]&&v[m].second!=y[2])
                        sw = false;
                }
                if(sw){
                    ans = 1;
                    break;
                }   
            }
        }
    }

    cout<<ans;
    


    return 0;
}
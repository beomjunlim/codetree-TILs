#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int main() {
    int n,g;
    cin>>n>>g;

    unordered_set<int> group[250001];
    unordered_set<int> people[100001];
    unordered_set<int> card;
    queue<int> q;

    for(int i=1; i<=g; i++){
        int num;
        cin>>num;
        for(int j=0; j<num; j++){
            int a;
            cin>>a;

            group[i].insert(a);
            people[a].insert(i);
        }
    }

    q.push(1);
    card.insert(1);
    
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto i : people[x]){
            int G = i;
            if(group[G].find(x)!=group[G].end()){
                group[G].erase(x);

                if(group[G].size()==1){
                    int y = *group[G].begin();
                    if(card.find(y)==card.end()){
                        q.push(y);
                        card.insert(y);
                    }
                }
            }
        }
    }

    cout<<card.size();
    return 0;
}
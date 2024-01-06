#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin>>n;

    priority_queue<pair<int,int>> pq;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x!=0){
            if(x>0){
                pq.push(make_pair(-x,-1));
            }
            else {
                pq.push(make_pair(x,1));
            }
        }
        else {
            if(pq.empty())
                cout<<0<<'\n';
            else{
                if(pq.top().second==-1)
                    cout<<-pq.top().first<<'\n';
                else
                    cout<<pq.top().first<<'\n';
                pq.pop();
            }
        }
    }
    return 0;
}
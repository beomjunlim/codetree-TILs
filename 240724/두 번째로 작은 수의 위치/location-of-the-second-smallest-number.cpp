#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin>>n;

    priority_queue<pair<int,int>> pq;

    for(int i=0; i<n; i++){
        int num;
        cin>>num;

        pq.push(make_pair(-num, i+1));
    }

    int ans = 0;
    bool find = false;
    int first = -pq.top().first;
    int second;
    int idx = -1;
    pq.pop();

    while(!pq.empty()){
        int num = -pq.top().first;

        if(find){
            if(second==num){
                idx = -1;
            }
            break;
        }

        if(first!=num&&!find){
            second = num;
            idx = pq.top().second;
            find = true;
        }   



        pq.pop();
    }

    cout<<idx;
    return 0;
}
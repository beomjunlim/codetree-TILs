#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin>>n;

    priority_queue<long long> min_pq;
    priority_queue<long long> max_pq;

    for(int i=0; i<n; i++){
        long long x;
        cin>>x;
        if(x==0){
            if(max_pq.empty()&&min_pq.empty())
                cout<<0<<'\n';
            else{
                if(max_pq.empty()&&!min_pq.empty()){
                    cout<<min_pq.top()<<'\n';
                    min_pq.pop();
                }
                else if(!max_pq.empty()&&min_pq.empty()){
                    cout<<-max_pq.top()<<'\n';
                    max_pq.pop();
                }
                else if(!max_pq.empty()&&!min_pq.empty()){
                    if(max_pq.top()>min_pq.top()){
                        cout<<-max_pq.top()<<'\n';
                        max_pq.pop();
                    }
                    else{
                        cout<<min_pq.top()<<'\n';
                        min_pq.pop();
                    }
                }
            }
        }
        else{
            if(x>0){
                max_pq.push(-x);
            }
            else{
                min_pq.push(x);
            }
        }
    }
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin>>n;

    priority_queue<int> pq;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        pq.push(-x);

        if(i<2){
            cout<<-1<<'\n';
        }

        else{
            int x1,x2,x3;
            x1 = -pq.top();
            pq.pop();
            x2 = -pq.top();
            pq.pop();
            x3 = -pq.top();
            pq.push(-x1);
            pq.push(-x2);

            int num = x1*x2*x3;
            cout<<num<<'\n';
        }
    }
    return 0;
}
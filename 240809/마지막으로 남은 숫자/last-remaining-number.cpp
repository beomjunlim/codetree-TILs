#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin>>n;

    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        pq.push(num);
    }

    while(pq.size()>1){
        int A = pq.top();
        pq.pop();
        int B = pq.top();
        pq.pop();

        int num = A - B;

        if(num!=0)
            pq.push(num);
    }

    if(pq.size()==0)
        cout<<-1<<'\n';
    else
        cout<<pq.top();
    return 0;
}
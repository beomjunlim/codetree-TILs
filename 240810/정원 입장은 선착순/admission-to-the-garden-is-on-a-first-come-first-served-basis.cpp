#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;

    priority_queue<pair<int,pair<int,int>>> pq; // start wait num

    for(int i=n; i>0; i--){ // 처음 나오는 사람을 우선 순위로 하기 위하여
        int a,b;
        cin>>a>>b;
        pq.push(make_pair(-a, make_pair(b,i))); // 시작 시간 빠른거부터 나올 수 있도록 하기 위하여
    }

    priority_queue<pair<int,pair<int,int>>> wait; // num start wait
    
    int time = -pq.top().first;
    time += pq.top().second.first;
    int ans = 0;

    pq.pop();

    while(!pq.empty()){
        int next = time + 1;
        int start = -pq.top().first;
        int end = pq.top().second.first;
        int num = pq.top().second.second;

        if(wait.empty()||start<=time){
            pq.pop();
            wait.push(make_pair(num, make_pair(start, end)));
        }

        if(!pq.empty())
            next = -pq.top().first;

        if(next<=time)
            continue;

        else{
            int w_start = wait.top().second.first;
            int w_wait = wait.top().second.second;
            wait.pop();


            if(time>w_start)
                ans = max(ans, time - w_start);
            time = max(time, w_start) + w_wait;
        }
    }

    while(!wait.empty()){
        int w_start = wait.top().second.first;
        int w_wait = wait.top().second.second;
        wait.pop();

        if(time>w_start)
            ans = max(ans, time - w_start);

        time = max(time, w_start) + w_wait;
    }

    cout<<ans;
    return 0;
}
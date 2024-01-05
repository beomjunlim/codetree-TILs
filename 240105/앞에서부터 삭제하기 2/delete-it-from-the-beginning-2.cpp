#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

#define MAX 100000

int arr[MAX+1];
float ans[MAX+1];

int main() {
    int n;
    cin>>n;

    priority_queue<int> pq;
    int sum = 0;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
        sum += arr[i];
        pq.push(-arr[i]);
    }

    float average = 0;

    for(int i=1; i<=n-2; i++){
        sum -=arr[i];
        if(pq.top()==(-arr[i])){
            pq.pop();
        }

        int num = pq.top();
        sum += num;
        pq.push(num);
        ans[i] = ((float)sum/(float)(n-i-1));
        average = max(ans[i], average);
    }

    cout<<fixed<<setprecision(2)<<average;

    return 0;
}
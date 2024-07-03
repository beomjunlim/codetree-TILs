#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    int arr[100001];

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    double ans = 0.00;
    priority_queue<int> pq;
    pq.push(-arr[n-1]);
    int sum = arr[n-1];

    for(int i=n-2; i>=1; i--){
        pq.push(-arr[i]);
        sum += arr[i];

        double avg = (double)(sum - (-pq.top())) / (n-i-1);

        if(ans < avg)
            ans = avg;
    }

    cout<<fixed;
    cout.precision(2);

    cout<<ans;
    return 0;
}
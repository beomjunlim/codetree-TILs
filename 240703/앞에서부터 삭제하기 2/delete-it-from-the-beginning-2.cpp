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
    int size = n - 1;

    for(int k=1; k<n-1; k++){
        priority_queue<int> pq;
        int sum = 0;
        size--;
        for(int i=k; i<n; i++){
            sum += arr[i];
            pq.push(-arr[i]);
        }
        sum += pq.top();
        double mean = double(sum/size);
        if(ans < mean)
            ans = mean;
    }

    cout<<fixed;
    cout.precision(2);

    cout<<ans;
    return 0;
}
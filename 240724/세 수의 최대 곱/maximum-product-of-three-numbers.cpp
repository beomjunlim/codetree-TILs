#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int n;
    cin>>n;

    int arr[100001];
    int zero = 0;
    priority_queue<int> plus;
    priority_queue<int> minus;

    for(int i=0; i<n; i++){
        cin>>arr[i];

        if(arr[i]>0)
            plus.push(arr[i]);
        if(arr[i]<0)
            minus.push(-arr[i]);
        if(arr[i]==0)
            zero++;
    }

    int ans = -(int)1e9;
    int A; // + + +
    int B; // + + -
    int C; // + - -
    int D; // - - - 
    int E; // 0

    if(plus.size()>2){
        int a = plus.top();
        plus.pop();
        int b = plus.top();
        plus.pop();
        int c = plus.top();
        A = a*b*c;
        ans = max(ans, A);
        plus.push(a);
        plus.push(b);
    }

    if(plus.size()>1&&minus.size()>0){
        int a = plus.top();
        plus.pop();
        int b = plus.top();
        plus.pop();
        int c = minus.top();
        B = -(a*b*c);
        ans = max(ans, B);
        plus.push(a);
        plus.push(b);
    }

    if(plus.size()>0&&minus.size()>1){
        int a = minus.top();
        minus.pop();
        int b = minus.top();
        minus.pop();
        int c = plus.top();
        C = a*b*c;
        ans = max(ans, C);
        minus.push(a);
        minus.push(b);
    }

    if(minus.size()>2){
        int a = minus.top();
        minus.pop();
        int b = minus.top();
        minus.pop();
        int c = minus.top();
        D = -(a*b*c);
        ans = max(ans, D);
        minus.push(a);
        minus.push(b);
    }

    if(zero!=0){
        E = 0;
        ans = max(ans, 0);
    }

    cout<<ans;
    return 0;
}
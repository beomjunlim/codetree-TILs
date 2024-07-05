#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int ans = 987654321;
int X[101];
int Y[101];

void check_sum(int a){
    int sum = 0;

    int start_x = X[0];
    int start_y = Y[0];

    for(int i=1; i<n; i++){
        if(i!=a){
            sum += (abs(start_x - X[i]) + abs(start_y - Y[i]));
            start_x = X[i];
            start_y = Y[i];
        }
    }
    ans = min(ans, sum);
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>X[i]>>Y[i];
    }

    for(int i=1; i<n-1; i++){
        check_sum(i);
    }

    cout<<ans;
    return 0;
}
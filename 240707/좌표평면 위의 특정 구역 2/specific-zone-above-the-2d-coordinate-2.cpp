#include <iostream>
#include <algorithm>
using namespace std;

int n;
int X[101];
int Y[101];

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>X[i]>>Y[i];
    }

    long long ans = 9876543210000;


    for(int i=0; i<n; i++){
        int min_x = 40001;
        int max_x = 0;
        int min_y = 40001;
        int max_y = 0;
        for(int j=0; j<n; j++){
            if(i!=j){
                min_x = min(min_x, X[j]);
                max_x = max(max_x, X[j]);
                min_y = min(min_y, Y[j]);
                max_y = max(max_y, Y[j]);
            }
        }
        int ans_x = max_x - min_x;
        int ans_y = max_y - min_y;
        long long area = ans_x * ans_y;
        ans = min(ans, area);
    }
    cout<<ans;
    return 0;
}
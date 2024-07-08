#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int X[101];
    int Y[101];
    cin>>n;

    long long ans = 0;
    for(int i=0; i<n; i++){
        cin>>X[i]>>Y[i];
    }

    for(int i=0; i<n; i++){
        int x = X[i];
        int y = Y[i];
        int x2,y2;
        for(int j=0; j<n; j++){
            if(i!=j){
                if(X[j]==x)
                    y2 = Y[j];
            }
        }

        for(int j=0; j<n; j++){
            if(i!=j){
                if(Y[j]==y)
                    x2 = X[j];
            }
        }

        long long area = abs(x-x2)*abs(y-y2);
        ans = max(ans, area);
    }
    cout<<ans;
    return 0;
}
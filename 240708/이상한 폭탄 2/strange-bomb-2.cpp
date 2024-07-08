#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n,k;

int main() {
    cin>>n>>k;

    int ans = -1;
    int bombs[101];
    for(int i=0; i<n; i++){
        cin>>bombs[i];
    }

    for(int i=0; i<n; i++){
        int bomb = bombs[i];

        for(int j=0; j<n; j++){
            if(i!=j){
                if(bomb==bombs[j]&&abs(i-j)<=3){
                    ans = max(ans,bomb);
                }
            }
        }
    }

    cout<<ans;
    return 0;
}
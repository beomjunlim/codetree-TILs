#include <iostream>
#include <algorithm>
using namespace std;

int n;
int A[101];
int B[101];

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>A[i]>>B[i];
    }

    int ans = 0;
    
    for(int i=0; i<n; i++){
        bool visited[1001] = {false,};

        for(int j=0; j<n; j++){
            if(i!=j){
                for(int k=A[j]; k<B[j]; k++){
                    visited[k] = true;
                }
            }
        }

        int time = 0;

        for(int j=0; j<1001; j++){
            if(visited[j])
                time++;
        }
        ans = max(ans, time);
    }

    cout<<ans;
    return 0;
}
#include <iostream>
using namespace std;

int A[100001];
int B[100001];

int main() {
    bool sw = true;
    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>A[i];
    }

    for(int i=0; i<m; i++){
        cin>>B[i];
    }

    int i=0;
    for(int j=0; j<m; j++){
        while(i<n&&A[i]!=B[j]){
            i++;
        }
        if(i==n)
            sw = false;
        else
            i++;
    }

    if(sw)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n,k;
    
    bool visited[10001];
    char arr[10001];
    cin>>n>>k;

    int max_size = 0;
    int min_size = 10001;
    for(int i=0; i<n; i++){
        int x;
        char y;
        cin>>x>>y;
        visited[x] = true;
        arr[x] = y;
        max_size = max(max_size, x);
        min_size = min(min_size, x);
    }

    int ans = 0;
    for(int i=min_size; i<=max_size-k; i++){
        int sum = 0;
        for(int j=i; j<=i+k; j++){
            if(visited[j]){
                if(arr[j]=='H')
                    sum +=2;
                if(arr[j]=='G')
                    sum +=1;
                    
            }
        }
        ans = max(ans, sum);
    }
    cout<<ans;
    return 0;
}
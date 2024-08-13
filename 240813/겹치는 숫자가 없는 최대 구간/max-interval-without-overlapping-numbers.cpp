#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int Count[100001];

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    int ans = 0;
    int j = 1;

    for(int i = 1; i <= n; i++) {
        while(j <= n && Count[arr[j]] == 0) {
            Count[arr[j]]++;
            j++;
        }
        

        ans = max(ans, j - i);

        Count[arr[i]]--;
    }
    
    cout << ans;
    return 0;
}
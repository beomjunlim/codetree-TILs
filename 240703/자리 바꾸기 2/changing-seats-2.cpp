#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int n,k;
int a[100000];
int b[100000];
int arr[100001];
int ans[100001];
unordered_set<int> sets[100001];

int main() {
    cin>>n>>k;

    for(int i=0; i<k; i++){
        cin>>a[i]>>b[i];
    }

    for(int i=1; i<=n; i++){
        arr[i] = i;
        sets[i].insert(i);
        ans[i] = 1;
    }

    for(int cnt=0; cnt<3; cnt++){
        for(int i=0; i<k; i++){
            swap(arr[a[i]], arr[b[i]]);

            if(sets[arr[a[i]]].find(a[i]) == sets[arr[a[i]]].end()){
                sets[arr[a[i]]].insert(a[i]);
                ans[arr[a[i]]]++;
            }

            if(sets[arr[b[i]]].find(b[i]) == sets[arr[b[i]]].end()){
                sets[arr[b[i]]].insert(b[i]);
                ans[arr[b[i]]]++;
            }
        }
    }

    for(int i=1; i<=n; i++)
        cout<<ans[i]<<'\n';
    return 0;
}
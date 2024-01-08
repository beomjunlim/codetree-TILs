#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

#define MAX 1000000

int arr[MAX];

int main() {
    int n,q;
    cin>>n>>q;
    
    set<int> num;
    unordered_map<int, int> mapper;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        num.insert(arr[i]);
    }

    int cnt = 1;
    for(auto & it: num){
        mapper[it] = cnt;
        cnt+=1;
    }

    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;
        int cnt_a = mapper[a];
        int cnt_b = mapper[b];
        cout<<cnt_b - cnt_a + 1 <<'\n';
    }


    return 0;
}
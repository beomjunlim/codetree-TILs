#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

#define MAX 100000

int arr[MAX];

int main() {
    unordered_map<int, int> num;
    vector<pair<int,int>> v;
    int n,k;
    cin>>n>>k;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        num[arr[i]]++;
    }

    for(unordered_map<int, int>::iterator it = num.begin(); it !=num.end(); it++){
        v.push_back({it->second, it->first});
    }

    sort(v.begin(), v.end());
    
    for(int i= (int)v.size()-1; i>=(int)v.size()-k; i--){
        cout<<v[i].second<<" ";
    }
    return 0;
}
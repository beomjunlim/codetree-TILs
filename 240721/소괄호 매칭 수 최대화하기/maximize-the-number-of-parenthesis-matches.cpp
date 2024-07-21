#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return (long long) a.first * b.second > (long long) b.first * a.second;
}

int main() {
    int n;
    cin>>n;

    long long ans =0;
    vector<pair<int,int>> arr;
    
    for(int i=0; i<n; i++){
        string str;
        cin>>str;

        int start = 0;
        int end = 0;
        for(int j=0; j<str.length(); j++){
            if(str[j]=='(')
                start++;
            else{
                end++;
                ans += start;
            }
        }
        arr.push_back(make_pair(start,end));
    }

    sort(arr.begin(), arr.end(), cmp);

    int sum = 0;
    for(int i=0; i<n; i++){
        int start = arr[i].first;
        int end = arr[i].second;

        ans += (long long)sum * end;
        sum += start;
    }
    cout<<ans;

    return 0;
}
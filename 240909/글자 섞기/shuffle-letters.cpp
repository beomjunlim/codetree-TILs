#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include<climits>
using namespace std;

string arr[50001];
string rev_arr[50001];
vector<pair<string,int>> v;
vector<pair<string,int>> rev_v;

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        sort(arr[i].begin(), arr[i].end());
        v.push_back(make_pair(arr[i],i));

        rev_arr[i] = arr[i];
        reverse(rev_arr[i].begin(), rev_arr[i].end());
        rev_v.push_back(make_pair(rev_arr[i],i));
    }

    sort(v.begin(), v.end());
    sort(rev_v.begin(), rev_v.end());

    for(int i=0; i<n; i++){
        int idx = 1;
        string temp = arr[i];

        for(int j=0; j<n; j++){
            if(temp>rev_v[j].first&&i!=rev_v[j].second){
                idx++;
            }
            else{
                break;
            }
        }
        cout<<idx<<" ";

        idx = 1;
        temp = rev_arr[i];

        for(int j=0; j<n; j++){
            if(temp<v[j].first&&i!=v[j].second){
                idx++;
            }
            else{
                break;
            }
        }
        cout<<idx<<'\n';
    }

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(y,x));
    }

    sort(v.begin(), v.end());

    int left = 0;
    int right = n-1;
    int ans = 0;

    while(left<=right){
        int A = v[left].first;
        int A_num = v[left].second;

        int B = v[right].first;
        int B_num = v[right].second;

        ans = max(ans, A+B);

        if(A_num<B_num){
            v[right].second = B_num - A_num;
            left++;
        }
        else if(A_num>B_num){
            v[left].second = A_num - B_num;
            right--;
        }
        else{
            left++;
            right--;
        }
    }
    cout<<ans;
    return 0;
}
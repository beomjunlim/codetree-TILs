#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,b;
vector<pair<int,int>> student;

int main() {
    cin>>n>>b;

    for(int i=0; i<n; i++){
        int product, delivery;
        cin>>product>>delivery;
        student.push_back(make_pair(product,delivery));
    }

    sort(student.begin(), student.end());
    int ans = 0;

    for(int i=0; i<n; i++){
        int sum = b;
        int num = student[i].first/2 + student[i].second;

        if(sum<num)
            break;
        
        sum -= num;
        int cnt = 1;

        for(int j=0; j<n; j++){
            if(i!=j){
                num = student[j].first + student[j].second;

                if(sum<num)
                    break;
                
                sum -= num;
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }

    cout<<ans;
    return 0;
}
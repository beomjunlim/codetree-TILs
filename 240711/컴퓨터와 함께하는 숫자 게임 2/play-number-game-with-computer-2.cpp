#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long a,b,m;
    cin>>m;
    cin>>a>>b;

    long long min_ans = 987654321;
    long long max_ans = 0;
    for(long long i=a; i<=b; i++){
        long long cnt = 0;
        long long num = i;
        long long left = 1;
        long long right = m;
        while(left<=right){
            cnt++;
            long long mid = (left + right) / 2;
            if(mid==num){
                min_ans = min(min_ans, cnt);
                max_ans = max(max_ans, cnt);
                break;
            }

            if(mid<num)
                left = mid + 1;
            if(mid>num)
                right = mid - 1;
        }
    }
    cout<<min_ans<<" "<<max_ans;
    return 0;
}
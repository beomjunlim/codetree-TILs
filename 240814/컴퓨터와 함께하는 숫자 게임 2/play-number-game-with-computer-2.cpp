#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n;
    cin>>n;

    long long a,b;
    cin>>a>>b;

    long long min_num = 1e19;
    long long max_num = 0;
    for(long long i=a; i<=b; i++){
        long long cnt = 0;
        long long start = 1;
        long long end = n;
        while(start<=end){
            long long mid = (start + end) / 2;
            cnt++;

            if(mid==i){
                break;
            }

            if(mid<i)
                start = mid + 1;
            else if(mid>i)
                end = mid - 1;
        }

        min_num = min(min_num, cnt);
        max_num = max(max_num, cnt);
    }

    cout<<min_num<<" "<<max_num;
    return 0;
}
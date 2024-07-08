#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x,y;

    cin>>x>>y;

    int ans = 0;

    for(int i=x; i<=y; i++){
        int num = i;
        int sum = 0;
        while(num>0){
            sum += num%10; 
            num -= num%10;
            num /=10;
        }
        ans = max(ans, sum);
    }

    cout<<ans;
    return 0;
}
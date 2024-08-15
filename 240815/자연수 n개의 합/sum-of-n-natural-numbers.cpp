#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n;
    cin>>n;

    long long sum = 0;
    long long num = 0;

    while(sum<n){
        num++;
        sum += num;
    }

    if(sum>n)
        cout<<num - 1;
    else
        cout<<num;
    return 0;
}
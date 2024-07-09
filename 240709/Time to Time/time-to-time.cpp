#include <iostream>
using namespace std;

int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    int hour = c - a;
    int minute;
    if(d-b>=0){
        minute = d-b;
    }
    else{
        int temp = 60 -b;
        minute = temp + d;
        hour--;
    }

    int ans = 60*hour + minute;
    cout<<ans;
    return 0;
}
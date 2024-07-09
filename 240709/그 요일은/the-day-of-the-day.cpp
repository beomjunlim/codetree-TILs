#include <iostream>
using namespace std;

int NumOfDays(int m, int d) {
    int days[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    int day = 0;

    for(int i=1; i<m; i++){
        day += days[i];
    }

    day += d;
    return day;
}

int main() {
    int m1,d1,m2,d2;
    string str;
    cin>>m1>>d1>>m2>>d2;
    cin>>str;

    int diff = NumOfDays(m2,d2) - NumOfDays(m1,d1);

    int num = diff/7;
    int dis = diff%7;

    int ans = num;

    if(str=="Mon")
        ans++;
    if(str=="Tue"&&dis>=1)
        ans++;
    if(str=="Wed"&&dis>=2)
        ans++;
    if(str=="Thu"&&dis>=3)
        ans++;
    if(str=="Fri"&&dis>=4)
        ans++;
    if(str=="Sat"&&dis>=5)
        ans++;
    if(str=="Sun"&&dis>=6)
        ans++;
    cout<<ans;
    return 0;
}
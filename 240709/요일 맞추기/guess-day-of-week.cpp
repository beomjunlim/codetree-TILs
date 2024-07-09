#include <iostream>
using namespace std;
/*
31 : 1 3 5 7 8 10 12
30 : 4 6 9 11
28 : 2
*/
int main() {
    int m1,d1,m2,d2;
    cin>>m1>>d1>>m2>>d2;
    bool sw = false;

    if(m1>m2||(m1==m2&&d1>d2)){
        int temp_m = m1;
        int temp_d = d1;
        m1 = m2;
        d1 = d2;
        m2 = temp_m;
        d2 = temp_d;
        sw = true;
    }

    int day = 0;
    for(int i=m1+1; i<m2; i++){
        if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
            day+=31;
        }
        else if(i==4||i==6||i==9||i==11){
            day+=30;
        }
        else if(i==2){
            day+=28;
        }
    }

    if(m1!=m2){
        if(m1==1||m1==3||m1==5||m1==7||m1==8||m1==10||m1==12){
            int temp = 31 - d1 + 1;
            day += temp;
        }
        else if(m1==4||m1==6||m1==9||m1==11){
            int temp = 30 - d1 + 1;
            day += temp;
        }
        else if(m1==2){
            int temp = 28 - d1 + 1;
            day += temp;
        }
        day += d2;
    }
    else{
        day += (d2-d1+1);
    }
    day--;
    int num = day&7;
    if(sw){
        if(num==0)
            cout<<"Mon";
        else if(num==1)
            cout<<"Sun";
        else if(num==2)
            cout<<"Sat";
        else if(num==3)
            cout<<"Fri";
        else if(num==4)
            cout<<"Thu";
        else if(num==5)
            cout<<"Wed";
        else if(num==6)
            cout<<"Tue";
    }
    else{
        if(num==0)
            cout<<"Mon";
        else if(num==1)
            cout<<"Tue";
        else if(num==2)
            cout<<"Wed";
        else if(num==3)
            cout<<"Thu";
        else if(num==4)
            cout<<"Fri";
        else if(num==5)
            cout<<"Sat";
        else if(num==6)
            cout<<"Sun";
    }
    return 0;
}
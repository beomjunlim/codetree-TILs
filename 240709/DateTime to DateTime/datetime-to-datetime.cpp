#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    cin>>a>>b>>c;

    int ans = 0;
    int day;
    int hour;
    int minute;

    if(a==11){
        hour += b- 11;
        if(c>=11){
            minute += c - 11;
        }
        else{
            hour--;
            c += 60;
            minute += c - 11;
        }
    }
    else{
        day+= a-11;
        if(b>=11){
            hour += b - 11;
            if(c>=11){
                minute += c -11;
            }
            else{
                hour--;
                if(hour<0){
                    day--;
                    hour += 24;
                }
                c += 60;
                minute += c - 11;
            }
        }
        else{
            day--;
            b += 24;
            hour += b - 11;
            if(c>=11){
                minute += c -11;
            }
            else{
                hour--;
                if(hour<0){
                    day--;
                    hour += 24;
                }
                c += 60;
                minute += c - 11;
            }
        }
    }

    hour += day*24;
    minute += hour*60;
    cout<<minute;
    return 0;
}
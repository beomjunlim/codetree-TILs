#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    string ans = "";

    int length = str.length();
    int count = 0;
    bool sw = true;

    for (int i = 0; i < length; i++) {
        if (str[i] == 'X') {
            count++;
        } else {
            if (count % 2 != 0) {
                sw = false;
                break;
            }

            
            for(int j=0; j<count/4; j++){
                ans += "aaaa";
            }
            
            count = count%4;

            for(int j=0; j<count/2; j++){
                ans +="bb";
            }        
            ans += '.';  
            count = 0;   
        }
    }

    if (count > 0) {
        if (count % 2 != 0) {
            sw = false;
        } else {
            for(int i=0; i<count/4; i++){
                ans += "aaaa";
            }
            count = count%4;

            for(int i=0; i<count/2; i++){
                ans += "bb";
            }
        }
    }

    if (!sw) {
        ans = "-1";  
    }

    cout << ans << endl;

    return 0;
}
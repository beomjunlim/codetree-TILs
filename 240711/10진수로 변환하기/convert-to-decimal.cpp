#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string str;
    cin>>str;

    int num = 0;
    for(int i=0; i<str.length(); i++){
        num += (str[i]-'0')*pow(2,str.length() - i - 1);
    }
    cout<<num;
    return 0;
}
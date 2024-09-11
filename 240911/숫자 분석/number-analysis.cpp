#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin>>str;

    int num = 0;
    for(int i=str.length()-1; i>=0; i--){
        cout<<str[i];
        num += str[i] - '0';
    }
    cout<<" "<<num;

    return 0;
}
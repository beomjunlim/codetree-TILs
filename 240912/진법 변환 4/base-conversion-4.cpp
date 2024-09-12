#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long num = 0;

    string str;
    cin>>str;

    int idx = 0;
    for(int i=str.length()-1; i>=0; i--){
        if(str[i]=='1'){
            num += pow(2,idx);
        }
        idx++;
    }
    cout<<num<<'\n';
    return 0;
}
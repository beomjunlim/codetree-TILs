#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string s;
    cin>>s;

    int num = 0;

    for(int i=0; i<s.length(); i++){
        num += (s[i]-'0')*pow(2, s.length() - i -1);
    }
    
    num *= 17;

    int arr[3000];
    int idx = 0;

    while(true){
        if(num<2){
            arr[idx] = num;
            break;
        }

        arr[idx] = num%2;
        num /= 2;
        idx++;
    }

    for(int i=idx; i>=0; i--)
        cout<<arr[i];
    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int min_num = 100;
string s;
char arr[11];

void shift(){
    int temp = arr[s.length()-1];

    for(int i=s.length()-1; i>0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;

    int num = 1;
    char alphabet = arr[0];
    string ans ="";

    for(int i=1; i<s.length(); i++){
        if(arr[i]==alphabet)
            num++;
        else{
            ans += alphabet;
            ans += to_string(num);
            alphabet = arr[i];
            num = 1;
        }
    }
    ans += alphabet;
    ans += to_string(num);
    int length = ans.length();
    min_num = min(min_num, length);
}

int main() {
    cin>>s;

    for(int i=0; i<s.length(); i++){
        arr[i] = s[i];
    }

    for(int i=0; i<s.length(); i++){
        shift();
    }
    cout<<min_num<<'\n';
    return 0;
}
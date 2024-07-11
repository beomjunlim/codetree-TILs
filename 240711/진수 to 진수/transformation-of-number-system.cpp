#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a,b;
    string str;

    cin>>a>>b;
    cin>>str;
    
    int num = 0;

    for(int i=0; i<str.length(); i++)
        num += (str[i] - '0')*pow(a, str.length() - i - 1);
    
    int arr[1000];
    int idx = 0;

    while(true){
        if(num<b){
            arr[idx] = num;
            break;
        }

        arr[idx] = num%b;
        num /= b;
        idx++;
    }

    for(int i=idx; i>=0; i--)
        cout<<arr[i];
    return 0;
}
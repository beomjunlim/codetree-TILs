#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin>>s;
    char arr[101];

    for(int i=0; i<s.length(); i++)
        arr[i] = s[i];
    
    sort(arr, arr + s.length());
    for(int i=0; i<s.length(); i++)
        cout<<arr[i];
    return 0;
}
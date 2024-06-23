#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string a;
    string b;
    cin>>a;
    cin>>b;

    int length = max(a.length(), b.length());
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    string ans = "Yes";

    for(int i=0; i<length; i++){
        if(a[i]!=b[i]){
            ans = "No";
            break;
        }
    }

    cout<<ans<<'\n';
    return 0;
}
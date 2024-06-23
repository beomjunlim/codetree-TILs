#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string a;
    string b;
    cin>>a;
    cin>>b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    string ans = "Yes";

    for(int i=0; i<a.length(); i++){
        if(a[i]!=b[i]){
            ans = "No";
            break;
        }
    }

    cout<<ans<<'\n';
    return 0;
}
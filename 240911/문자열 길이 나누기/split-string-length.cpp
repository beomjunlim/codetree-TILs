#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    string tmp = "";

    for(int i=0; i<n; i++){
        string str;
        cin>>str;
        tmp += str;
    }

    int size = tmp.length();

    for(int i=0; i<size/2; i++){
        cout<<tmp[i];
    }
    cout<<'\n';

    for(int i=size/2; i<size; i++){
        cout<<tmp[i];
    }
    return 0;
}
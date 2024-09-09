#include <iostream>
using namespace std;

int main() {
    string str;
    cin>>str;

    int A = 0, B = 0;
    for(int i=0; i<str.length()-2; i++){
        if(str[i]=='K'&&str[i+1]=='O'&&str[i+2]=='I')
            A++;

        if(str[i]=='I'&&str[i+1]=='O'&&str[i+2]=='I')
            B++;
    }

    cout<<A<<" "<<B;
    return 0;
}
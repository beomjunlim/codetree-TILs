#include <iostream>
using namespace std;

int main() {
    string str;
    cin>>str;

    int open = 0;
    int cnt = 0;

    for(int i=0; i<str.length(); i++){
        if(str[i]==')'){
            if(open>0)
                open--;
            else{
                cnt++;
                open++;
            }
        }

        if(str[i]=='('){
            open++;
        }
    }

    if(open>0)
        cnt += open/2;
        
    cout<<cnt;
    return 0;
}
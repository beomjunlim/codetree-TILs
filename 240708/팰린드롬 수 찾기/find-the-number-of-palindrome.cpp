#include <iostream>
#include <string>
using namespace std;

int main() {
    int x,y;
    cin>>x>>y;

    int ans = 0;
    for(int i=x; i<=y; i++){
        string str = to_string(i);
        int start = 0;
        int end = str.length()-1;
        bool sw = false;

        while(start<end){
            if(str[start]!=str[end]){
                sw = true;
                break;
            }
            else{
                start++;
                end--;
            }
        }
        if(!sw){
           ans++;
        }
    }

    cout<<ans;
    return 0;
}
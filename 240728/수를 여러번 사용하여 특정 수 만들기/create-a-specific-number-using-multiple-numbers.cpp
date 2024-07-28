#include <iostream>
using namespace std;

int a,b,c;
int ans = 0;
void function(int num){

    if(num<=c)
        ans = max(ans, num);
    
    if(num>c)
        return;
    function(num + a);
    function(num + b);
} 

int main() {    
    cin>>a>>b>>c;
    function(0);
    cout<<ans;
    
    return 0;
}
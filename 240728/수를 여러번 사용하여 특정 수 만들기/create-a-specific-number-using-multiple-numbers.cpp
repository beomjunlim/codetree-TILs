#include <iostream>
using namespace std;

int a,b,c;
int ans = 0;

int main() {    
    cin>>a>>b>>c;
    int A = c/a + 1;
    int B = c/b + 1;

    for(int i=0; i<A; i++){
        for(int j=0; j<B; j++){
            int num = a*i + b*j;
            if(num<=c)
                ans = max(ans, num);
        }
    }

    cout<<ans;
    return 0;
}
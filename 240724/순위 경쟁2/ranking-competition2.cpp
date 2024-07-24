#include <iostream>
using namespace std;

int main() {
    int n;

    cin>>n;
    
    int ans = 0;
    int first = -1;
    int A = 0;
    int B = 0;

    for(int i=0; i<n; i++){
        int temp = first;
        char a;
        int score;
        cin>>a>>score;
        if(a=='A')
            A += score;

        else if(a=='B')
            B += score;
        
        if(A==B)
            first = -1;
        if(A>B)
            first = 1;
        if(A<B)
            first = 2;
        
        if(first!=temp)
            ans++;
    }

    cout<<ans;
    return 0;
}
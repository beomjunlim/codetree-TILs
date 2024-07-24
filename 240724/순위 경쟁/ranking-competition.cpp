#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int ans = 0;
    int A = 0;
    int B = 0;
    int C = 0;
    int first = -1; 
    /*
    A 1
    B 2
    C 3
    A B 4
    A C 5 
    B C 6
    A B C - 1
    */

    for(int i=0; i<n; i++){
        int temp = first;
        char a;
        int num;
        cin>>a>>num;

        if(a=='A')
            A += num;
        if(a=='B')
            B += num;
        if(a=='C')
            C += num;

        if(A>B&&A>C)
            first = 1;
        
        if(B>A&&B>C)
            first = 2;
        
        if(C>A&&C>B)
            first = 3;
        
        if(A==B&&A>C)
            first = 4;
        
        if(A==C&&A>B)
            first = 5;
        
        if(B==C&&B>A)
            first = 6;
        
        if(A==B&&A==C)
            first = -1;

        if(temp!=first)
            ans++;
    }

    cout<<ans;


    return 0;
}
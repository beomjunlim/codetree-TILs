#include <iostream>
#include <algorithm>
using namespace std;

string str[5];

int main() {
    int length = 0;

    for(int i=0; i<5; i++){
        cin>>str[i];        
        int size = str[i].length();
        length = max(length, size);
    }

    for(int i=0; i<length; i++){
        for(int j=0; j<5; j++){
            if(i<str[j].length())
                cout<<str[j][i];
        }   
    }

    
    return 0;
}
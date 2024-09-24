#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[26];

int main() {
    string str;
    cin>>str;

    pair<int,int> alphabet[26];
    for(int i=0; i<52; i++){
        if(!visited[str[i]-'A']){
            visited[str[i]-'A'] = true;
            alphabet[str[i]-'A'].first = i;
        }
        else{
            alphabet[str[i]-'A'].second = i;
        }
    }

    int ans = 0;


    for(int i=0; i<52; i++){
        int second = alphabet[str[i]-'A'].second;
        for(int j=i+1; j<second; j++){
            int last = alphabet[str[j]-'A'].second;
            if(second<last){
                ans++;
            }
        }
    }

    cout<<ans;
    return 0;
}
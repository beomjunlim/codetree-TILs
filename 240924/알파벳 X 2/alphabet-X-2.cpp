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
        if(!visited[str[i-'a']]){
            visited[str[i-'a']] = true;
            alphabet[str[i]-'a'].first = i;
        }
        else{
            alphabet[str[i]-'a'].second = i;
        }
    }

    int ans = 0;
    for(int i=0; i<52; i++){
        int second = alphabet[str[i]-'a'].second;
        for(int j=i+1; j<second; j++){
            int last = alphabet[str[j]-'a'].second;
            if(second<last){
                ans++;
            }
        }
    }

    cout<<ans;
    return 0;
}
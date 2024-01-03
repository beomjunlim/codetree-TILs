#include <iostream>
#include <iomanip>
#include <map>
using namespace std;


int main() {
    map<string,int> m;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        m[s]+=1;
    }

    for(auto & word : m){
        float num;
        num = ((word.second*100.0000)/n);
        cout<<word.first<<" "<<fixed<<setprecision(4)<<num<<'\n';
    }
    return 0;
}
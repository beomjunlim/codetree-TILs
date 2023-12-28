#include <iostream>
#include <vector>
using namespace std;

int k,n;
vector<int> v;

void print(){
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<'\n';
}

void check(int num){
    if(num==n){
        print();
        return;
    }
    else {
        for(int i=1; i<=k; i++){
            v.push_back(i);
            check(num+1);
            v.pop_back();
        }
    }
}

int main() {
    cin>>k>>n;
    check(0);
    return 0;
}
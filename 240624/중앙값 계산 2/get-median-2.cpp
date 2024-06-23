#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> num;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        num.push_back(a);

        if(i==0)
            cout<<num[0]<<" ";
        else if(i%2==0){
            sort(num.begin(), num.end());
            cout<<num[i/2]<<" ";
        }
    }
    return 0;
}
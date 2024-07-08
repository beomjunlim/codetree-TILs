#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int x,y;
    cin>>x>>y;

    int sum = 0;
    for(int i=x; i<=y; i++){
        int num = i;
        unordered_set<int> sets;
        sets.insert(num%10);
        num -= num%10;
        num /= 10;
        while(num>0){
            sets.insert(num%10);
            num -= num%10;
            num /= 10;
        } 

        if(sets.size()==2)
            sum++;
    }
    cout<<sum;
    return 0;
}
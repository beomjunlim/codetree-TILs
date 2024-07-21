#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int q;
    cin>>q;

    unordered_set<int> sets;
    int bitmask = 0;
    for(int i=0; i<q; i++){
        string s;
        cin>>s;

        if(s=="add"){
            int x;
            cin>>x;
            bitmask |= (1<<x);
        }
        if(s=="delete"){
            int x;
            cin>>x;
            bitmask &= ~(1<<x);
        }
        if(s=="print"){
            int x;
            cin>>x;
            if(bitmask & (1<<x))
                cout<<1<<'\n';
            else
                cout<<0<<'\n';

        }
        if(s=="toggle"){
            int x;
            cin>>x;
            bitmask ^= (1<<x);
        }
        if(s=="clear"){
            bitmask = 0;
        }
    }
    return 0;
}
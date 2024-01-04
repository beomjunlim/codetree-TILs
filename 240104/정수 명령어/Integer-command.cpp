#include <iostream>
#include <set>
using namespace std;

int main() {
    int T;
    cin>>T;

    while(T>0){
        set<int> s;
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            string command;
            cin>>command;
            if(command=="I"){
                int a;
                cin>>a;
                s.insert(a);
            }
            if(command=="D"){
                int a;
                cin>>a;
                if(s.empty())
                    continue;
                if(a==1)
                    s.erase(*s.rbegin());
                if(a==-1)
                    s.erase(*s.begin());
            }
        }
        if(s.empty())
            cout<<"EMPTY"<<'\n';
        else
            cout<<*s.rbegin()<<" "<<*s.begin()<<'\n';
        T--;
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t>0){
        int m;
        cin>>m;
        
        priority_queue<int> big;
        priority_queue<int> small;
        int mid;

        for(int i=1; i<=m; i++){
            int num;
            cin>>num;
            if(i==1){
                mid = num;
                cout<<num<<" ";
            }
            else if(i%2==0){
                if(mid>num)
                    small.push(num);
                else
                    big.push(-num);
            }
            else if(i%2==1){
                if(num>mid){
                    int A = -big.top();
                    if(A>num){
                        small.push(mid);
                        mid = num;
                        cout<<mid<<" ";
                    }
                    else{
                        small.push(mid);
                        big.pop();
                        big.push(-num);
                        mid = A;
                        cout<<mid<<" ";
                    }
                }
                else{
                    int A = small.top();
                    if(A>num){
                        small.pop();
                        small.push(num);
                        big.push(-mid);
                        mid = A;
                        cout<<mid<<" ";
                    }
                    else{
                        big.push(-mid);
                        mid = num;
                        cout<<mid<<" ";
                    }
                }
            }
        }
        t--;
        cout<<'\n';
    }
    return 0;
}
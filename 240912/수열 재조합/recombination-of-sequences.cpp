#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

bool visited[100001];

int main() {
    int n;
    cin>>n;

    stack<int> st;
    queue<char> q;
    int num = 1;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        while(num<=a){
            st.push(num);
            q.push('+');
            num++;
        }
        
        if(st.top()==a){
            st.pop();
            q.push('-');
        }
        else{
            cout<<"NO"<<'\n';
            return 0;
        }
    }

    while(!q.empty()){
        char num = q.front();
        cout<<num<<'\n';
        q.pop();
    }
    
    return 0;
}
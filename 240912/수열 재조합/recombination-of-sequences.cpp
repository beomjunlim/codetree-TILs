#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int ans[100001];
bool visited[100001];

int main() {
    int n;
    cin>>n;

    stack<int> st;
    queue<char> q;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        for(int j=1; j<=a; j++){
            if(!visited[j]){
                q.push('+');
                st.push(j);
                visited[j] = true;
            }
        }
        if(st.top()!=a){
            cout<<"NO";
            return 0;
        }
        st.pop();
        q.push('-');
    }

    while(!q.empty()){
        char num = q.front();
        cout<<num<<'\n';
        q.pop();
    }
    
    return 0;
}
#include <iostream>
using namespace std;

int parent[100001];

int find(int x){
    if(parent[x]==x)
        return x;
    return find(parent[x]);
}

int main() {
    int n,m;
    cin>>n>>m;

    for(int i=1; i<=n; i++) {
        parent[i] = i;
    }

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;

        if(a==0){
            int B = find(b);
            int C = find(c);
            if(B!=C){
                parent[C] = B;
            }
        }
        else {
            if(find(b)==find(c))
                cout<<1<<'\n';
            else
                cout<<0<<'\n';
        }
    }
    return 0;
}
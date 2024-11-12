#include <iostream>
using namespace std;

int n,m,k;
int parent[100001];

int find(int x){
    if(parent[x]==x)
        return x;
    return find(parent[x]);
}

int main() {
    cin>>n>>m>>k;

    for(int i=1; i<=n; i++){
        parent[i] = i;
    }

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        
        int A = find(a);
        int B = find(b);

        if(A!=B){
            parent[A] = B;
        }
    }

    int a,b;
    cin>>a>>b;

    if(find(a)==find(b))
        cout<<1<<'\n';
    else
        cout<<0<<'\n';
    return 0;
}
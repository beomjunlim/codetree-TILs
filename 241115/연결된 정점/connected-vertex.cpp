#include <iostream>
using namespace std;

int n,m;
int parent[100001];
int count[100001];

int find(int x){
    if(parent[x]==x)
        return x;
    return parent[x] = find(parent[x]);
}

int main() {
    cin>>n>>m;
    
    for(int i=1; i<=n; i++){
        parent[i] = i;
        count[i] = 1;
    }


    for(int i=0; i<m; i++){
        char a;
        cin>>a;

        if(a=='x'){
            int x, y;
            cin>>x>>y;
            int X = find(x);
            int Y = find(y);

            if(X!=Y){
                parent[X] = Y;
                count[Y] += count[X];
            }
        }
        else{
            int x;
            cin>>x;
            cout<<count[find(x)]<<'\n';
        }
    }

    return 0;
}
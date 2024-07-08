#include <iostream>
#include <vector>
using namespace std;

int k,n;
vector<int> v[11];

int main() {
    cin>>k>>n;

    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            int x;
            cin>>x;
            v[i].push_back(x);
        }
    }

    int ans = 0;

    for(int i=1; i<=n; i++){
        int A = i;
        for(int j=1; j<=n; j++){
            if(j!=A){
                int B = j;
                int idx_A,idx_B;
                bool sw = false;
                for(int l=0; l<k; l++){
                    for(int z=0; z<n; z++){
                        if(v[l][z]==A)
                            idx_A = z;
                        if(v[l][z]==B)
                            idx_B = z;
                    }   

                    if(idx_A < idx_B)
                        sw = true;
                }

                if(!sw)
                    ans++;
            }
        }
    }

    cout<<ans;
    return 0;
}
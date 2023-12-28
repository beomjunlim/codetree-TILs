#include <iostream>
#include <vector>
using namespace std;

int n;
int ans = 0;
vector<int> seq;

bool IsBeautiful() {
    for(int i=0; i<n; i +=seq[i]){
        if(i+seq[i]-1>=n)
            return false;
        
        for(int j=i; j<i + seq[i]; j++){
            if(seq[j] !=seq[i])
                return false;
        }
    }
    return true;
}

void CountBeautiful(int cnt){
    if(cnt==n){
        if(IsBeautiful())
            ans++;
        return;
    }

    for(int i=1; i<=4; i++){
        seq.push_back(i);
        CountBeautiful(cnt+1);
        seq.pop_back();
    }
}
int main() {
    cin>>n;

    CountBeautiful(0);
    cout<<ans;
    return 0;
}
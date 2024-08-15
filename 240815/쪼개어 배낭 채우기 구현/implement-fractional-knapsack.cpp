#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    vector<pair<double,int>> arr;
    for(int i=0; i<n; i++){
        double a,b;
        cin>>a>>b;
        arr.push_back(make_pair(b/a,a));
    }

    sort(arr.begin(), arr.end());

    double bag = m;
    int idx = n-1;
    double value = 0;
    while(bag>0&&idx>=0){
        if(bag>=arr[idx].second){
            value += arr[idx].first*arr[idx].second;
            bag -= arr[idx].second;
        }
        else{
            value += arr[idx].first*bag;
            break;
        }
        idx--;
    }
    
    cout<<fixed<<setprecision(3)<<value;
    return 0;
}
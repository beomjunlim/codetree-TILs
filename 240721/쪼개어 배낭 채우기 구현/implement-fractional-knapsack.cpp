#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

bool cmp(pair<double,double>a, pair<double,double>b){
    double ratioA = a.second / a.first;
    double ratioB = b.second / b.first; 
    return ratioA > ratioB;
}
int main() {
    int n,m;
    vector<pair<double,double>> diamond;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        diamond.push_back(make_pair(a,b));
    }

    sort(diamond.begin(), diamond.end(), cmp);


    double ans = 0;
    double num = m;
    for(int i=0; i<n; i++){
        if(num >= diamond[i].first){
            ans += diamond[i].second;
            num -= diamond[i].first;
        }
        else{
            ans += diamond[i].second * (num/diamond[i].first); 
            break;
        }
    }

    cout<<fixed<<setprecision(3);
    cout<<ans;


    return 0;
}
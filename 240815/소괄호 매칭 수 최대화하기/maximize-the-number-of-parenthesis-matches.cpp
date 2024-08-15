#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(string a, string b){
    string A = a+b;
    long long cnt_A = 0;

    long long T=0;
    for(int i=A.length()-1; i>=0; i--){
        if(A[i]==')')
            T++;
        else if(A[i]=='(')
            cnt_A += T;
    }

    string B = b+a;
    long long cnt_B = 0;
    T = 0;
    for(int i=B.length()-1; i>=0; i--){
        if(B[i]==')')
            T++;
        else if(B[i]=='(')
            cnt_B += T;
    }

    return cnt_A > cnt_B;
}

int main() {
    int n;
    cin>>n;

    vector<string> v;

    for(int i=0; i<n; i++){
        string str;
        cin>>str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), cmp);

    string s ="";
    for(int i=0; i<v.size(); i++){
        s += v[i];
    }

    long long T = 0;
    long long ans = 0;
    for(long long i=s.length(); i>=0; i--){
        if(s[i]==')')
            T++;
        else if(s[i]=='(')
            ans += T;
    }

    cout<<ans;
    return 0;
}
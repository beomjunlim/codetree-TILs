#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(long long a, long long b){
    string A = to_string(a);
    string B = to_string(b);

    string temp = A;
    A += B;
    B += temp;

    long long num_A = stoll(A);
    long long num_B = stoll(B);
    return num_A > num_B;
}

int main() {
    int n;
    cin>>n;

    long long arr[50001];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    sort(arr, arr+n, cmp);

    for(int i=0; i<n; i++)
        cout<<arr[i];
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main() {
    int n;
    cin>>n;

    vector<int> arr;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end(), cmp);

    int idx = n-1;
    int sum = 0;
    while(arr.size()>1){
        int x = arr[idx];
        idx--;
        arr.pop_back();
        int y = arr[idx];
        arr.pop_back();
        arr.push_back(x+y);
        sum+= (x+y);
        sort(arr.begin(), arr.end(), cmp);
    }

    cout<<sum;


    return 0;
}
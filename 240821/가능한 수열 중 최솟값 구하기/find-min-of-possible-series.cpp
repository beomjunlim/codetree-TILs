#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> arr;
int num[3] = {4,5,6};

bool IsEqual(int s1, int e1, int s2, int e2){
    for(int i=0; i<=e1-s1; i++){
        if(arr[s1 + i]!=arr[s2 + i])
            return false;
    }
    return true;
}

bool Possible(){
    int len = 1;

    while(1){
        int end1 = arr.size() - 1, start1 = end1 - len + 1;
        int end2 = start1 - 1, start2 = end2 - len + 1;

        if(start2<0)
            break;
        if(IsEqual(start1, end1, start2, end2))
            return false;
        len++;
    }
    return true;
}

void backtracking(int cnt){
    if(cnt==n){
        for(int i=0; i<n; i++){
            cout<<arr[i];
        }
        exit(0);
        return;
    }

    for(int i=0; i<3; i++){
        arr.push_back(num[i]);

        if(Possible())
            backtracking(cnt+1);
        
        arr.pop_back();
    }
}

int main() {
    cin>>n;

    backtracking(0);
    return 0;
}
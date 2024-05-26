#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

int n;
vector<int> series;
int numbers[3] = {4,5,6};

bool IsEqual(int start1, int end1, int start2, int end2){
    for(int i=0; i<=end1-start1; i++){
        if(series[start1+i] != series[start2+i])
            return false;
    }
    return true;
}

bool IsPossibleSeries(){
    int len = 1;

    while(1){
        int end1 = (int) series.size() - 1, start1 = end1 - len + 1;
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
        for(int i=0; i<series.size(); i++)
            cout<<series[i];
        exit(0);
    }

    for(int i=0; i<3; i++){
        series.push_back(numbers[i]);

        if(IsPossibleSeries())
            backtracking(cnt+1);
        
        series.pop_back();
    }
}

int main() {
    cin>>n;

    backtracking(0);
    return 0;
}
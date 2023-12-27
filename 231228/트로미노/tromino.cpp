#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 200

int n,m;
int arr[MAX][MAX];



bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

int getCaseA(int i, int j){
    int max_sum = 0;
    if(InRange(i+1,j)&&InRange(i,j+1)){
        int min_num = min(arr[i][j], min(arr[i+1][j], min(arr[i+1][j+1], arr[i][j+1])));
        max_sum = (arr[i][j]+arr[i+1][j] + arr[i][j+1] + arr[i+1][j+1]- min_num);
    }
    return max_sum;
}

int getCaseB(int i, int j){
    int num_a = 0;
    int num_b = 0;
    if(InRange(i+2,j)){
        num_a = (arr[i][j]+arr[i+1][j]+arr[i+2][j]);
    }
    if(InRange(i,j+2)){
        num_b = (arr[i][j]+arr[i][j+1]+arr[i][j+2]);
    }
    return max(num_a, num_b);
}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    int caseA = 0;
    int caseB = 0;
    int ans = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            caseA = getCaseA(i,j);
            caseB = getCaseB(i,j);
            int max_case = max(caseA, caseB);
            ans = max(max_case, ans);
        }
    }

    cout<<ans;


    return 0;
}
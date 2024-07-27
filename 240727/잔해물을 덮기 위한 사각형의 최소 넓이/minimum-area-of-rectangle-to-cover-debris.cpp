#include <iostream>
#include <algorithm>
using namespace std;

int arr[2001][2001];

int main() { 
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;

    x1 += 1000;
    y1 += 1000;
    x2 += 1000;
    y2 += 1000;

    
    for(int i=x1; i<x2; i++){
        for(int j=y1; j<y2; j++){
            arr[j][i] = 1;
        }
    }

    int x3,x4,y3,y4;
    cin>>x3>>y3>>x4>>y4;

    x3 += 1000;
    y3 += 1000;
    x4 += 1000;
    y4 += 1000;

    for(int i=x3; i<x4; i++){
        for(int j=y3; j<y4; j++){
            arr[j][i] = 0;
        }
    }

    int start_x = x2;
    int start_y = y2;
    int end_x = x1;
    int end_y = y1;

    for(int i=x1; i<x2; i++){
        for(int j=y1; j<y2; j++){
            if(arr[j][i]==1){
                start_x = min(start_x,i);
                start_y = min(start_y,j);
                end_x = max(end_x,i);
                end_y = max(end_y,j);
            }
        }
    }

    int ans = 0;
    for(int i=start_x; i<=end_x; i++){
        for(int j=start_y; j<=end_y; j++){
            ans++;
        }
    }

    cout<<ans;


    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int cnt = 0;
    int arr[3];

    for(int i=0; i<3; i++)
        cin>>arr[i];

    while(true){
        if(arr[0]+1==arr[1]&&arr[1]+1==arr[2]){
            break;
        }
        else if(arr[0]+1==arr[1]&&arr[1]+1!=arr[2]){
            cnt++;
            arr[0] = arr[1] + 1;
        }
        else if(arr[0]+1!=arr[1]&&arr[1]+1==arr[2]){
            cnt++;
            arr[2] = arr[1] - 1;
        }
        else if(arr[0]+1!=arr[1]&&arr[1]+1!=arr[2]){
            if(arr[1]-arr[0]>arr[2]-arr[1]){
                cnt++;
                arr[2] = arr[1] - 1;
            }
            else{
                cnt++;
                arr[0] = arr[1] + 1;
            }
        }
        sort(arr, arr+3);
    }

    cout<<cnt;
    return 0;
}
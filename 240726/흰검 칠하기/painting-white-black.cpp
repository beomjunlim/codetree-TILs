#include <iostream>
#include <algorithm>
using namespace std;

/*
B 1 : 1
B 2 : 2
W 1 : 3
W 2 : 4
B 1 W 1 : B 5, W6
B 2 W 1 : B 7, W8
B 1 W 2 : B 9, W10
G : 11
*/

/*
B 1 2 5 7 9
W 3 4 6 8 10
G 11
*/


int arr[200001];
int num = 100000;
int main() {
    int n;
    cin>>n;

    int start = 100001;
    int end = -100001;

    for(int i=0; i<n; i++){
        int a;
        char b;
        cin>>a>>b;

        if(b=='R'){
            for(int j=num; j<num+a; j++){
                if(arr[j]==0)
                    arr[j] = 1;
                else if(arr[j]==1)
                    arr[j] = 2;
                else if(arr[j]==3)
                    arr[j] = 5;
                else if(arr[j]==4)
                    arr[j] = 9;
                else if(arr[j]==5)
                    arr[j] = 7;
                else if(arr[j]==6)
                    arr[j] = 7;
                else if(arr[j]==8)
                    arr[j] = 7;
                else if(arr[j]==9)
                    arr[j] = 11;
                else if(arr[j]==10)
                    arr[j] = 11;
            }
            num = num + a - 1;
        }

        else{
            for(int j=num; j>num-a; j--){
                if(arr[j]==0)
                    arr[j] = 3;
                else if(arr[j]==1)
                    arr[j] = 6;
                else if(arr[j]==2)
                    arr[j] = 8;
                else if(arr[j]==3)
                    arr[j] = 4;
                else if(arr[j]==5)
                    arr[j] = 6;
                else if(arr[j]==6)
                    arr[j] = 10;
                else if(arr[j]==7)
                    arr[j] = 11;
                else if(arr[j]==8)
                    arr[j] = 11;
                else if(arr[j]==9)
                    arr[j] = 10;

            }
            num = num - a + 1;
        }
        start = min(start, num);
        end = max(end, num);
    }    

    int B = 0;
    int W = 0;
    int G = 0;
    for(int i=start; i<=end; i++){
        if(arr[i]==1||arr[i]==2||arr[i]==5||arr[i]==7||arr[i]==9)
            B++;
        if(arr[i]==3||arr[i]==4||arr[i]==6||arr[i]==8||arr[i]==10)
            W++;
        if(arr[i]==11)
            G++;
    }
    cout<<W<<" "<<B<<" "<<G<<'\n';
    return 0;
}
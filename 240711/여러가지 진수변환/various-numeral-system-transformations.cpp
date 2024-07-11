#include <iostream>
using namespace std;

int main() {
    int n,b;
    cin>>n>>b;

    int arr[1001];
    int idx = 0;

    if(b==4){
        while(true){
            if(n<4){
                arr[idx] = n;
                break;
            }
            arr[idx] = n%4;
            n /= 4;
            idx++;
        }
    }
    else{
        while(true){
            if(n<8){
                arr[idx] = n;
                break;
            }

            arr[idx] = n%8;
            n /= 8;
            idx++;
        }
    }

    for(int i=idx; i>=0; i--)
        cout<<arr[i];
    return 0;
}
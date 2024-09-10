#include <iostream>
using namespace std;

int even[7];
int odd[7];
int zero[7];
int count[7];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        char a;
        int b;
        cin>>a>>b;

        if(a=='B'){
            count[0]++;
            if(b==0)
                zero[0]++;
            else if(b%2==0)
                even[0]++;
            else 
                odd[0]++;
        }
        else if(a=='E'){
            count[1]++;
            if(b==0)
                zero[1]++;
            else if(b%2==0)
                even[1]++;
            else 
                odd[1]++;
        }
        else if(a=='S'){
            count[2]++;
            if(b==0)
                zero[2]++;
            else if(b%2==0)
                even[2]++;
            else 
                odd[2]++;
        }
        else if(a=='I'){
            count[3]++;
            if(b==0)
                zero[3]++;
            else if(b%2==0)
                even[3]++;
            else 
                odd[3]++;
        }
        else if(a=='G'){
            count[4]++;
            if(b==0)
                zero[4]++;
            else if(b%2==0)
                even[4]++;
            else 
                odd[4]++;
        }
        else if(a=='O'){
            count[5]++;
            if(b==0)
                zero[5]++;
            else if(b%2==0)
                even[5]++;
            else 
                odd[5]++;
        }
        else if(a=='M'){
            count[6]++;
            if(b==0)
                zero[6]++;
            else if(b%2==0)
                even[6]++;
            else 
                odd[6]++;
        }
    }

    int num = 1;
    for(int i=0; i<7; i++){
        num *= count[i];
    }

    int odd_num = odd[6];
    int caseA = odd[0]*even[3] + odd[3]*even[0];
    int caseB = 0;

    // 홀수 1ㄱ개
    caseB += odd[1]*even[2]*even[4]*even[5];
    caseB += odd[2]*even[1]*even[4]*even[5];
    caseB += odd[4]*even[2]*even[1]*even[5];
    caseB += odd[5]*even[2]*even[4]*even[1];
    // 홀수 3개
    caseB += even[1]*odd[2]*odd[4]*odd[5];
    caseB += even[2]*odd[1]*odd[4]*odd[5];
    caseB += even[4]*odd[2]*odd[1]*odd[5];
    caseB += even[5]*odd[2]*odd[4]*odd[1];

    odd_num *=caseA;
    odd_num *=caseB;

    cout<<num-odd_num;
    return 0;
}
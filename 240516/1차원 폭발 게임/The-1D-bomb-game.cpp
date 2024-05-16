#include <iostream>
#include <vector>
using namespace std;

int Mysize;
int n,m;
int arr[101];

void change(int Presize){
    vector<int> copy;

    for(int i=0; i<Presize; i++){
        if(arr[i]!=0){
            copy.push_back(arr[i]);
        }
    }

    for(int i=0; i<Mysize; i++){
        arr[i] = copy[i];
    }
}

bool bomb(){
    bool sw = false;
    int num = arr[0];
    int start = 0;
    int cnt = 1;
    int Presize = Mysize;

    for(int i=1; i<Presize; i++){
        if(num==arr[i]){
            cnt++;
        }
        else{
            if(cnt>=m){
                sw = true;
                for(int j=start; j<i; j++){
                    Mysize--;
                    arr[j] = 0;
                }
            }
            cnt = 1;
            start = i;
        }
        num = arr[i];
    }

    if(cnt>=m){
        sw = true;
        for(int j=start; j<Presize; j++){
            Mysize--;
            arr[j] = 0;
        }
    }

    if(sw){
        change(Presize);
        return true;
    }
    else{
        return false;
    }

}

int main() {
    cin>>n>>m;

    for(int i=n-1; i>=0; i--){
        cin>>arr[i];
    }

    Mysize = n;

    while(bomb());

    cout<<Mysize<<'\n';
    for(int i=Mysize-1; i>=0; i--){
        cout<<arr[i]<<'\n';
    }


    return 0;
}
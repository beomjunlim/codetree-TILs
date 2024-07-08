#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int x,y;
    cin>>x>>y;

    int sum = 0;
    for(int i=x; i<=y; i++){
        int num = i;
        unordered_map<int,int> maps;
        while(num>0){
            maps[num%10]++;
            num /= 10;
        } 

        if(maps.size()==2){
            int arr[2];
            int idx = 0;
            for(auto it : maps){
                arr[idx] = it.second;
                idx++;
            }

            sort(arr, arr+2);
            if(arr[0]<=1)
                sum++;
        }
    }
    cout<<sum;
    return 0;
}
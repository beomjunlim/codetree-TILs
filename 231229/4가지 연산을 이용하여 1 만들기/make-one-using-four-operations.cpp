#include <iostream>
#include <queue>
using namespace std;

#define MAX 1000001

int arr[MAX];
bool visited[MAX] = {false,};
int n;

void BFS(int num){
    queue<int> q;
    visited[num] = true;
    q.push(num);

    while(!q.empty()){
        int m = q.front();
        q.pop();

        if(m==1){
            break;
        }

        if(m+1<1000000&&!visited[m+1]){
            arr[m+1] = arr[m] + 1;
            visited[m+1] = true;
            q.push(m+1);
        }
        if(m-1>=1&&!visited[m-1]){
            arr[m-1] = arr[m] + 1;
            visited[m-1] = true;
            q.push(m-1);
        }
        if(m%3==0&&!visited[m/3]){
            arr[m/3] = arr[m] + 1;
            visited[m/3] = true;
            q.push(m/3);
        }
        if(m%2==0&&!visited[m/2]){
            arr[m/2] = arr[m] + 1;
            visited[m/2] = true;
            q.push(m/2);
        }
    }
    
}

int main() {
    cin>>n;
    BFS(n);
    cout<<arr[1];
    return 0;
}
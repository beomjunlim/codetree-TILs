#include <iostream>
#include <vector>
using namespace std;

int n,m,q;
int arr[101][101];
vector<pair<int,int>> start;
vector<pair<int,int>> last;

bool InRange(int x, int y){
    return 0<x&&x<=n&&0<y&&y<=m;
}

void rotate(int r1, int c1, int r2, int c2){
    int temp[101][101];
    int tmp = arr[r1][c1];

    for(int i=r1; i<r2; i++){
        arr[i][c1] = arr[i+1][c1];
    }

    for(int i=c1; i<c2; i++){
        arr[r2][i] = arr[r2][i+1];
    }

    for(int i=r2; i>r1; i--){
        arr[i][c2] = arr[i-1][c2];
    }

    for(int i=c2; i>c1+1; i--){
        arr[r1][i] = arr[r1][i-1];
    }
    
    arr[r1][c1+1] = tmp;

    for(int i=r1; i<=r2; i++){
        for(int j=c1; j<=c2; j++){
            int num = 1;
            int sum = arr[i][j];
            temp[i][j] = 0;
            if(InRange(i+1,j)){
                num++;
                sum += arr[i+1][j];
            }

            if(InRange(i-1,j)){
                num++;
                sum += arr[i-1][j];
            }

            if(InRange(i,j+1)){
                num++;
                sum += arr[i][j+1];
            }

            if(InRange(i,j-1)){
                num++;
                sum += arr[i][j-1];
            }
            temp[i][j] = sum/num;
        }
    }

    for(int i=r1; i<=r2; i++){
        for(int j=c1; j<=c2; j++){
            arr[i][j] = temp[i][j];
        }
    }
}

int main() {
    cin>>n>>m>>q;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<q; i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        start.push_back(make_pair(a,b));
        last.push_back(make_pair(c,d));
    }

    for(int i=0; i<start.size(); i++){
        int r1 = start[i].first;
        int c1 = start[i].second;
        int r2 = last[i].first;
        int c2 = last[i].second;

        rotate(r1,c1,r2,c2);
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
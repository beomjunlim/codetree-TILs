#include <iostream>
using namespace std;

int arr[19][19];

int dx_a[] = {0,0,0,0};
int dy_a[] = {1,2,3,4};

int dx_b[] = {1,2,3,4};
int dy_b[] = {0,0,0,0};

int dx_c[] = {1,2,3,4};
int dy_c[] = {1,2,3,4};

int dx_d[] = {1,2,3,4};
int dy_d[] = {-1,-2,-3,-4};

bool InRange(int x, int y){
    return 0<=x&&x<19&&0<=y&&y<19;
}

bool check(int color, int row, int col){
    bool sw_a = false;
    bool sw_b = false;
    bool sw_c = false;
    bool sw_d = false;
    int i_a,i_b,i_c,i_d = 0;
    
    for(i_a; i_a<4; i_a++){
        int nx = row + dx_a[i_a];
        int ny = col + dy_a[i_a];
        if(InRange(nx,ny)){
            if(color!=arr[nx][ny])
                break;
        }
        else
            break;
    }

    if(i_a==4&&color==arr[row+dx_a[3]][col+dy_a[3]])
        sw_a = true;

    for(i_b=0; i_b<4; i_b++){
        int nx = row + dx_b[i_b];
        int ny = col + dy_b[i_b];
        if(InRange(nx,ny)){
            if(color!=arr[nx][ny])
                break;
        }
        else
            break;
    }

    if(i_b==4&&color==arr[row+dx_b[3]][col+dy_b[3]])
        sw_b = true;

    for(i_c=0; i_c<4; i_c++){
        int nx = row + dx_c[i_c];
        int ny = col + dy_c[i_c];
        if(InRange(nx,ny)){
            if(color!=arr[nx][ny])
                break;
        }
        else
            break;
    }

    if(i_c==4&&color==arr[row+dx_c[3]][col+dy_c[3]])
        sw_c = true;

    for(i_d=0; i_d<4; i_d++){
        int nx = row + dx_d[i_d];
        int ny = col + dy_d[i_d];
        if(InRange(nx,ny)){
            if(color!=arr[nx][ny])
                break;
        }
        else
            break;
    }

    if(i_d==4&&color==arr[row+dx_d[3]][col+dy_d[3]])
        sw_d = true;

    if(sw_a){
        cout<<color<<'\n';
        cout<<row+dx_a[1]+1<<" "<<col+dy_a[1]+1<<'\n';
        return true;
    }
    else if(sw_b){
        cout<<color<<'\n';
        cout<<row+dx_b[1]+1<<" "<<col+dy_b[1]+1<<'\n';
        return true;
    }
    else if(sw_c){
        cout<<color<<'\n';
        cout<<row+dx_c[1]+1<<" "<<col+dy_c[1]+1<<'\n';
        return true;
    }
    else if(sw_d){
        cout<<color<<'\n';
        cout<<row+dx_d[1]+1<<" "<<col+dy_d[1]+1<<'\n';
        return true;
    }
    return false;
}

int main() {
    for(int i=0; i<19; i++){
        for(int j=0; j<19; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<19; i++){
        for(int j=0; j<19; j++){
            if(arr[i][j]!=0){
                if(check(arr[i][j], i,j))
                    break;
            }
        }
    }   
    return 0;
}
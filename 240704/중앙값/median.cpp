#include <iostream>
#include <queue>
using namespace std;

int main() {
    int t,m;
    cin>>t;

    while(t>0){
        cin>>m;
        int median = 0;
        priority_queue<int> max_pq;
        priority_queue<int> min_pq;

        for(int i=1; i<=m; i++){
            int x;
            cin>>x;

            if(i%2!=0){
                if(i==1){
                    median = x;
                    cout<<median<<" ";
                }
                else{
                    int y;
                    if(max_pq.size() > min_pq.size()){
                        y = -max_pq.top();
                        max_pq.pop();

                        if(x>y){
                            int temp = median;
                            median = y;
                            max_pq.push(-x);
                            min_pq.push(temp);
                        }
                        else if(x>median){
                            int temp = median;
                            median = x;
                            max_pq.push(-y);
                            min_pq.push(temp);
                        }
                        else{
                            max_pq.push(-y);
                            min_pq.push(x);
                        }
                    }
                    else{
                        y = min_pq.top();
                        min_pq.pop();

                        if(x<y){
                            int temp = median;
                            median = y;
                            max_pq.push(-temp);
                            min_pq.push(x);
                        }
                        else if(x<median){
                            int temp = median;
                            median = x;
                            max_pq.push(-temp);
                            min_pq.push(y);
                        }
                        else{
                            max_pq.push(-x);
                            min_pq.push(y);
                        }
                    }
                    cout<<median<<" ";
                }
            }
            else{
                if(median < x)
                    max_pq.push(-x);
                else
                    min_pq.push(x);
            }
        }
        t--;
        cout<<'\n';
    }

    return 0;
}
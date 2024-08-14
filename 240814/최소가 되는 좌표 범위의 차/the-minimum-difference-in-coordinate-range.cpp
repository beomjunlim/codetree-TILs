// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <algorithm>
// #include <climits>
// using namespace std;

// int min_num[100001];
// int max_num[100001];

// int main() {
//     int n,d;
//     cin>>n>>d;

//     vector<pair<int,int>> num;
//     for(int i=0; i<n; i++){
//         int x,y;
//         cin>>x>>y;
//         num.push_back(make_pair(y,x));
//     }

//     sort(num.begin(), num.end());

//     vector<pair<int,int>> ans; 
//     int j=0;
//     for(int i=0; i<n; i++){
//         int A = num[i].first; // y
//         int B = num[i].second; // x

//         while(j<n&&abs(A-num[j].first)<d){
//             j++;
//         }
        
//         if(j<n)
//             ans.push_back(make_pair(i,j));
//     }

//     for(int i=0; i<ans.size(); i++){
//         cout<<ans[i].first<<" "<<ans[i].second<<'\n';
//     }
    
//     if(ans.size()==0)
//         cout<<-1;
    



//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    // x좌표 기준으로 정렬
    sort(points.begin(), points.end());

    // 우선순위 큐: 최소 힙과 최대 힙을 사용
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_y; // y좌표의 최소값을 추적
    priority_queue<pair<int, int>> max_y; // y좌표의 최대값을 추적

    int left = 0;
    int min_diff = INT_MAX;

    for (int right = 0; right < n; right++) {
        int x_right = points[right].first;
        int y_right = points[right].second;

        min_y.push({y_right, right});
        max_y.push({y_right, right});

        // y좌표 차이가 D 이상이 될 때까지 윈도우를 축소
        while (!min_y.empty() && !max_y.empty()) {
            int y_min = min_y.top().first;
            int y_max = max_y.top().first;

            if (y_max - y_min >= d) {
                int x_left = points[left].first;
                min_diff = min(min_diff, x_right - x_left);
                left++;
                while (!min_y.empty() && min_y.top().second < left) {
                    min_y.pop(); // 윈도우 밖의 값 제거
                }
                while (!max_y.empty() && max_y.top().second < left) {
                    max_y.pop(); // 윈도우 밖의 값 제거
                }
            } else {
                break;
            }
        }
    }

    if (min_diff == INT_MAX) {
        cout << -1 << endl; // 가능한 범위가 없는 경우
    } else {
        cout << min_diff << endl; // 최소 x좌표 차이
    }

    return 0;
}
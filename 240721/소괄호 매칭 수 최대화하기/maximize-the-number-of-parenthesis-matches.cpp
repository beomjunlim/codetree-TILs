// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// bool cmp(string a, string b){
//     int a_num = 0;
//     int a_sum = 0;
//     int b_num = 0;
//     int b_sum = 0;

//     for(int i=0; i<a.length(); i++){
//         if(a[i]=='(')
//             a_num++;
//         else
//             a_sum += a_num;
//     }

//     for(int i=0; i<b.length(); i++){
//         if(b[i]=='(')
//             b_num++;
//         else
//             b_sum += b_num;
//     }

//     return a_sum > b_sum;
// }

// int main() {
//     int n;
//     cin>>n;

//     vector<string> arr;
//     for(int i=0; i<n; i++){
//         string str;
//         cin>>str;
//         arr.push_back(str);
//     }

//     sort(arr.begin(), arr.end(), cmp);
//     string s = "";

//     for(int i=0; i<n; i++){
//         s += arr[i];
//     }

//     int num = 0;
//     int sum = 0;
//     for(int i=0; i<s.length(); i++){
//         if(s[i]=='(')
//             num++;
//         else
//             sum += num;
//     }

//     for(int i=0; i<s.length(); i++)
//         cout<<s[i];
//     cout<<sum;

//     return 0;
// }


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define MAX_N 100005
#define MAX_S 500005

int n;
vector<pair<int,int>> s;
long long ans = 0;

bool cmp(pair<int,int> a, pair<int,int> b) {
    long long sum1 = (long long) a.first * b.second;
    long long sum2 = (long long) b.first * a.second;

    return sum1 > sum2;
}

int main() {
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        int open = 0, close = 0;
        for (int j = 0; j < (int) str.length(); j++) {
            if (str[j] == '(') {
                open++;
            }
            else {
                close++;
                ans += open;
            }
        }
        s.push_back(make_pair(open, close));
    }

    sort(s.begin(), s.end(), cmp);

    int open_sum = 0;
    for (int i = 0; i < n; i++) {
        int open = s[i].first;
        int close = s[i].second;

        ans += (long long) open_sum * close;

        open_sum += open;
    }

    cout << ans;

    return 0;
}
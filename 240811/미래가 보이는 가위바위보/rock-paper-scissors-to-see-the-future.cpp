// #include <iostream>
// #include <algorithm>
// using namespace std;

// int H[100001];
// int S[100001];
// int P[100001];
// int arr[100001]; // H 0 S 1 P 2
// // H > S S > P P > H
// // 0 > 1 1 > 2 2 > 0

// int main() {
//     int n;
//     cin>>n;

//     for(int i=1; i<=n; i++){
//         char a;
//         cin>>a;
//         int num;
//         if(a=='H')
//             num = 0;
//         if(a=='S')
//             num = 1;
//         if(a=='P')
//             num = 2;
//         arr[i] = num;
//     }

//     for(int i=1; i<=n; i++){
//         int a = 0, b = 0, c = 0;

//         if(arr[i]==0)
//             c = 1;
//         if(arr[i]==1)
//             a = 1;
//         if(arr[i]==2)
//             b = 1;
        
//         H[i] = H[i-1] + a;
//         S[i] = S[i-1] + b;
//         P[i] = P[i-1] + c;
//     }

//     int ans = max(H[n], max(S[n], P[n]));
//     for(int i=2; i<=n; i++){
//         int a = 0, b = 0, c = 0;
//         if(arr[i]==0)
//             c = 1;
//         if(arr[i]==1)
//             a = 1;
//         if(arr[i]==2)
//             b = 1;
//         if(i==n){
//             ans = max(ans, max(H[n-1] + b, max(H[n-1] + c,
//             max(S[n-1] + a, max(S[n-1] + c,
//             max(P[n-1] + a, P[n-1] + b))))));
//         }
//         else{
//             ans = max(ans, max(H[i-1] + S[n] - S[i-1] + b, max(H[i-1] + P[n] - P[i-1] + c,
//             max(S[i-1] + H[n] - H[i-1] + a, max(S[i-1] + P[n] - P[i-1] + c,
//             max(P[i-1] + H[n] - H[i-1] + a, P[i-1] + S[n] - S[i-1] + b))))));
//         }
//         if(ans==84)
//             cout<<"i : "<<i<<'\n';
//     }

//     cout<<ans;
//     return 0;
// }
// /*
// H -> S
// H -> P
// S -> P
// S -> H
// P -> S
// P -> H
// P
// S
// H
// */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 계산 가능한 최대 승리 수를 계산하는 함수
int calculateMaxWins(const vector<char>& B, char firstChoice, char secondChoice, int N) {
    int maxWins = 0;

    // Iterate over all possible places to make the switch
    for (int switchPos = 0; switchPos <= N; switchPos++) {
        int wins = 0;

        // Count wins for the first part (constant choice)
        for (int i = 0; i < switchPos; i++) {
            if ((firstChoice == 'H' && B[i] == 'S') ||
                (firstChoice == 'S' && B[i] == 'P') ||
                (firstChoice == 'P' && B[i] == 'H')) {
                wins++;
            }
        }

        // Count wins for the second part (constant choice after the switch)
        for (int i = switchPos; i < N; i++) {
            if ((secondChoice == 'H' && B[i] == 'S') ||
                (secondChoice == 'S' && B[i] == 'P') ||
                (secondChoice == 'P' && B[i] == 'H')) {
                wins++;
            }
        }

        maxWins = max(maxWins, wins);
    }

    return maxWins;
}

int main() {
    int N;
    cin >> N;

    vector<char> B(N);

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    // Compute maximum wins for each possible combination of choices
    int maxWins = 0;

    // A starts with H, then switches to S
    maxWins = max(maxWins, calculateMaxWins(B, 'H', 'S', N));

    // A starts with H, then switches to P
    maxWins = max(maxWins, calculateMaxWins(B, 'H', 'P', N));

    // A starts with S, then switches to H
    maxWins = max(maxWins, calculateMaxWins(B, 'S', 'H', N));

    // A starts with S, then switches to P
    maxWins = max(maxWins, calculateMaxWins(B, 'S', 'P', N));

    // A starts with P, then switches to H
    maxWins = max(maxWins, calculateMaxWins(B, 'P', 'H', N));

    // A starts with P, then switches to S
    maxWins = max(maxWins, calculateMaxWins(B, 'P', 'S', N));

    cout << maxWins << endl;
    
    return 0;
}
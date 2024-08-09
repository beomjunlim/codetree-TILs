// #include <iostream>
// #include <vector>
// #include <unordered_set>
// using namespace std;

// bool visited[100001];
// vector<int> group[250001];

// int main() {
//     int n,g;
//     cin>>n>>g;

//     unordered_set<int> card;

//     for(int i=0; i<g; i++){
//         int num;
//         cin>>num;
//         for(int j=0; j<num; j++){
//             int a;
//             cin>>a;
//             group[i].push_back(a);
//             if(j==0)
//                 card.insert(a);        
//         }
//     }



//     return 0;
// }

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int n, g;
vector<vector<int>> groups; // 각 그룹의 멤버를 저장
vector<unordered_set<int>> person_groups; // 각 사람의 그룹 목록을 저장

// BFS 탐색을 통한 초대장 수신자 결정
int find_invited_count() {
    vector<bool> invited(n + 1, false);
    queue<int> q;

    // 그룹 1의 멤버들을 모두 초대장 받는 사람으로 설정
    for (int person : groups[1]) {
        invited[person] = true;
        q.push(person);
    }

    while (!q.empty()) {
        int person = q.front();
        q.pop();

        // 사람 `person`이 속한 그룹을 확인
        for (int group_id : person_groups[person]) {
            int count_invited = 0;
            vector<int> members;

            // 그룹의 모든 멤버를 확인
            for (int member : groups[group_id]) {
                members.push_back(member);
                if (invited[member]) {
                    count_invited++;
                }
            }

            // 그룹의 멤버 수가 초대장을 받은 멤버 수보다 1명 더 많다면
            if (count_invited == members.size() - 1) {
                for (int member : members) {
                    if (!invited[member]) {
                        invited[member] = true;
                        q.push(member);
                    }
                }
            }
        }
    }

    // 초대장을 받은 사람 수 계산
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (invited[i]) {
            count++;
        }
    }
    return count;
}

int main() {
    cin >> n >> g;

    groups.resize(g + 1); // 그룹 1부터 G까지
    person_groups.resize(n + 1); // 사람 1부터 N까지

    for (int i = 1; i <= g; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int person;
            cin >> person;
            groups[i].push_back(person);
            person_groups[person].insert(i);
        }
    }

    cout << find_invited_count() << endl;

    return 0;
}
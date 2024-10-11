#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;

struct Wait {
    int sequence, time;
    string url;

    bool operator<(const Wait& a) const {
        if (sequence != a.sequence)
            return sequence > a.sequence;
        return time > a.time;
    }
};

priority_queue<int> grade;
set<string> URL;
priority_queue<Wait> waitting;
map<string, pair<int, int>> progress; // 채점 시작, 채점기
map<string, pair<int, int>> End; // 채점 시작 채점 끝
map<int, pair<string, int>> Pgrade; // 채점 중인거 채점기 도메인 시작 시간

int main() {
    int Q;
    cin >> Q;

    while (Q > 0) {
        Q--;
        int cmd;
        cin >> cmd;

        if (cmd == 100) {
            int n;
            string str;
            cin >> n >> str;

            for (int i = 1; i <= n; i++)
                grade.push(-i);
            waitting.push({ 1,0,str });
            URL.insert(str);
        }
        else if (cmd == 200) {
            int t, p;
            string str;
            cin >> t >> p >> str;

            if (URL.find(str) != URL.end()) // 이미 있으면 종료
                continue;

            URL.insert(str); // 대기 큐 URL 관리
            waitting.push({ p,t,str }); // 대기 큐에 넣기
        }
        else if (cmd == 300) {
            int t;
            cin >> t;

            if(waitting.empty()) // 채점할 게 없다면 종료
                continue;

            string str = waitting.top().url;
            string Domain = str.substr(0, str.find("/")); // 도메인 추출

            if (progress.find(Domain) != progress.end()) // 해당 도메인 채점 중이면 종료
                continue;

            if (End.find(Domain) != End.end()) { // 채점 종료된 도메인 너무 일찍 나오면 종료
                int start = End[Domain].first;
                int gap = End[Domain].second - start;

                if (t < start + 3 * gap)
                    continue;
            }

            if (grade.empty()) // 채점할 채점기 없다면 종료
                continue;

            waitting.pop(); // 대기 큐에서 제거
            URL.erase(str); // 대기 큐 URL 관리
            int gradeNum = -grade.top(); // 채점 진행할 채점기
            grade.pop(); // 해당 채점기 제거
            progress[Domain] = { t, gradeNum }; // 진행 중으로 넣기
            Pgrade[gradeNum] = { Domain, t }; // 채점기 진행 
        }
        else if (cmd == 400) {
            int t, gradeNum;
            cin >> t >> gradeNum;
            string Domain = Pgrade[gradeNum].first; // 해당 채점기가 채점 중인 도메인
            int start = Pgrade[gradeNum].second; // 채점 시작 시간

            progress.erase(Domain); // 진행 중에서 제거
            Pgrade.erase(gradeNum); // 채점기 진행 중에서 제거
            grade.push(-gradeNum); // 채점기 대기 상태

            End[Domain] = { start, t }; // 종료에 넣기 
        }
        else if (cmd == 500) {
            int t;
            cin >> t;
            cout << waitting.size() << '\n';
        }
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
#include <cstring>
#include <cmath>
using namespace std;

struct Wait {
    int sequence, time, Idx;
    string ID;

    bool operator<(const Wait& a) const {
        if (sequence != a.sequence)
            return sequence > a.sequence;
        return time > a.time;
    }
};

int DomainIdx = 0;
int WaittingNum = 0;
unordered_map<string, int> Domain; // Domain 인덱스
priority_queue<int> grade; // 채점기
set<string> URL; // 대기 큐 URL 중복 검사
priority_queue<Wait>FirstDomain[301]; // DomainIdx 로 가장 빠른 거 비교

unordered_map<string, pair<int, int>> progress; // 채점 시작, 채점기
unordered_map<string, pair<int, int>> End; // 채점 시작 채점 끝
unordered_map<int, pair<string, int>> Pgrade; // 채점 중인거 채점기 도메인 시작 시간

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

            Domain[str.substr(0, str.find("/"))] = DomainIdx;
            FirstDomain[DomainIdx].push({ 1,0,DomainIdx,str.substr(str.find("/")) });
            URL.insert(str);
            DomainIdx++;
            WaittingNum++;
        }
        else if (cmd == 200) {
            int t, p;
            string str;
            cin >> t >> p >> str;

            if (URL.find(str) != URL.end()) // 이미 있으면 종료
                continue;

            string domain = str.substr(0, str.find("/"));
            string ID = str.substr(str.find("/"));

            if (Domain.find(domain) == Domain.end()) {   
                Domain[domain] = DomainIdx;
                DomainIdx++;
            }

            FirstDomain[Domain[domain]].push({ p,t,Domain[domain],ID }); // 대기 큐 Domain 기준 우선 순위
            URL.insert(str); // 대기 큐 URL 관리
            WaittingNum++;
        }
        else if (cmd == 300) {
            int t;
            cin >> t;

            if (WaittingNum == 0) // 채점할 게 없다면 종료
                continue;

            if (grade.empty()) // 채점할 채점기 없다면 종료
                continue;

            priority_queue<Wait> pq;
            for (auto it : Domain) {
                if (FirstDomain[it.second].empty())
                    continue;

                int P = FirstDomain[it.second].top().sequence;
                int T = FirstDomain[it.second].top().time;
                int Idx = it.second;
                string url = it.first;

                if (progress.find(url) != progress.end())
                    continue;

                if (End.find(url) != End.end()) {
                    int start = End[url].first;
                    int gap = End[url].second - start;
                    if (t < start + 3 * gap)
                        continue;
                }
                pq.push({ P,T,Idx, url});
            }

            if (pq.empty())
                continue;

            string domain = pq.top().ID;
            int idx = pq.top().Idx;

            string url = domain + FirstDomain[idx].top().ID;

            int gradeNum = -grade.top();
            grade.pop();

            progress[domain] = { t, gradeNum }; // 진행 중
            Pgrade[gradeNum] = { domain, t };

            URL.erase(url);
            FirstDomain[idx].pop();
            WaittingNum--;
        }
        else if (cmd == 400) {
            int t, gradeNum;
            cin >> t >> gradeNum;
            string Domain = Pgrade[gradeNum].first; // 해당 채점기가 채점 중인 도메인
            int start = Pgrade[gradeNum].second; // 채점 시작 시간

            if(progress.find(Domain)==progress.end())
                continue;
                
            progress.erase(Domain); // 진행 중에서 제거
            Pgrade.erase(gradeNum); // 채점기 진행 중에서 제거
            grade.push(-gradeNum); // 채점기 대기 상태
            End[Domain] = { start, t }; // 종료에 넣기 
        }
        else if (cmd == 500) {
            int t;
            cin >> t;
            cout << WaittingNum << '\n';
        }
    }
    return 0;
}
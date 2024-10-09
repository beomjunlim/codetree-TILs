#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include<set>

using namespace std;

struct Query {
    int cmd, t, x, n;
    string name;
};

int L, Q;
vector<Query> query;
map<string, vector<Query>> Make; // 사람마다 주어진 초밥
set<string> Name; // 들어온 사람
map<string, int> Entry; // 들어온 시간
map<string, int> Exit; // 나간 시간
map<string, int> Posistion; // 손님 위치

bool cmp(Query q1, Query q2) {
    if (q1.t != q2.t)
        return q1.t < q2.t;
    return q1.cmd < q2.cmd;
}

int main() {
    cin >> L >> Q;

    while (Q > 0) {
        int command;
        int t = -1, x = -1, n = -1;
        string name;
        cin >> command;
        if (command == 100) {
            cin >> t >> x >> name;
            Make[name].push_back({ command,t,x,n,name });
        }
        else if (command == 200) {
            cin >> t >> x >> name >> n;
            Name.insert(name);
            Entry[name] = t;
            Posistion[name] = x;
        }
        else if (command == 300) {
            cin >> t;
        }

        query.push_back({ command,t,x,n,name });
        Q--;
    }

    // 사람들이 언제 초밥 먹는 지
    for (auto it : Name) {
        Exit[it] = 0;
        
        for (Query q : Make[it]) {
            int time = 0;
            if (q.t < Entry[it]) {
                int sushi_x = (q.x + Entry[it] - q.t) % L;
                int add = (Posistion[it] - sushi_x + L) % L;
                time = Entry[it] + add;
            }
            else {
                int add = (Posistion[it] - q.x + L) % L;
                time = q.t + add;
            }
            Exit[it] = max(Exit[it], time);
            query.push_back({111, time, -1, -1, it}); // 초밥 사라지는 명령어
        }
    }

    // 사람들 마지막에 초밥 먹은 시간 계산
    for (auto it : Name)
        query.push_back({ 222, Exit[it], -1,-1, it });

    sort(query.begin(), query.end(), cmp); // 300 명령어 젤 늦게 오도록

    int people_num = 0, sushi_num =  0;
    for (int i = 0; i < query.size(); i++) {
        if (query[i].cmd == 100)
            sushi_num++;
        else if (query[i].cmd == 111)
            sushi_num--;
        else if (query[i].cmd == 200)
            people_num++;
        else if (query[i].cmd == 222)
            people_num--;
        else
            cout << people_num << " " << sushi_num << '\n';
    }

    return 0;
}
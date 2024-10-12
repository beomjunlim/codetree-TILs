#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;

struct Query {
    int cmd, t, x, n;
    string name;
};

int L, Q;

vector<Query> query;
map<string, vector<Query>> Make;
set<string> People;
map<string, int> Entry;
map<string, int> Exit;
map<string, int> Position;

bool cmp(Query a, Query b) {
    if (a.t != b.t)
        return a.t < b.t;
    return a.cmd < b.cmd;
}

int main() {
    cin >> L >> Q;

    while (Q--) {
        int cmd;
        int t = -1, x = -1, n = -1;
        string name;
        cin >> cmd;

        if (cmd == 100) {
            cin >> t >> x >> name;
            Make[name].push_back({ cmd,t,x,n,name });
        }
        else if (cmd == 200) {
            cin >> t >> x >> name >> n;
            People.insert(name);
            Entry[name] = t;
            Position[name] = x;
        }
        else if (cmd == 300) {
            cin >> t;
        }
        query.push_back({ cmd,t,x,n,name });
    }

    for (auto it : People) {
        Exit[it] = 0;
        
        for (Query q : Make[it]) {
            int time = 0;
            if (q.t < Entry[it]) {
                int sushiX = (q.x + Entry[it] - q.t) % L;
                int Add = (L - sushiX + Position[it]) % L;
                time = Entry[it] + Add;
            }
            else {
                int Add = (L - q.x + Position[it]) % L;
                time = q.t + Add;
            }

            Exit[it] = max(Exit[it], time);
            query.push_back({ 111,time,-1,-1,it });
        }
    }

    for (auto it : People) {
        query.push_back({ 222,Exit[it],-1,-1,it });
    }

    sort(query.begin(), query.end(), cmp);

    int peopleNum = 0;
    int sushiNum = 0;
    for (int i = 0; i < query.size(); i++) {
        if (query[i].cmd == 100) {
            sushiNum++;
        }
        else if (query[i].cmd == 111) {
            sushiNum--;
        }
        else if (query[i].cmd == 200) {
            peopleNum++;
        }
        else if (query[i].cmd == 222) {
            peopleNum--;
        }
        else if (query[i].cmd == 300) {
            cout << peopleNum << " " << sushiNum << '\n';
        }
    }
    return 0;
}
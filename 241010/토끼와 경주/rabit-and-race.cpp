#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;

struct Rabbit {
    int x, y;
    int id;
    int d;
    int count;

    bool operator<(const Rabbit& a) const {
        if (count != a.count)
            return count > a.count;
        if (x + y != a.x + a.y)
            return x + y > a.x + a.y;
        if (x != a.x)
            return x > a.x;
        return y > a.y;
    }
};

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    if (a.first + a.second != b.first + b.second)
        return a.first + a.second > b.first + b.second;
    if (a.first != b.first)
        return a.first > b.first;
    return a.second > b.second;
}

bool give(Rabbit a, Rabbit b) {
    if (a.x + a.y != b.x + b.y)
        return a.x + a.y > b.x + b.y;
    if (a.x != b.x)
        return a.x > b.x;
    if (a.y != b.y)
        return a.y > b.y;
    return a.id > b.id;
}

int N, M, P;
priority_queue<Rabbit> pq;
map<int, Rabbit> rabbit;
map<int, ll> score;

int main() {
    int Q;
    cin >> Q;
    while (Q > 0) {
        int command;
        cin >> command;

        if (command == 100) {
            cin >> N >> M >> P;

            for (int i = 1; i <= P; i++) {
                int id, d;
                cin >> id >> d;

                rabbit[id] = { 1,1,id,d,0 };
            }

            for (auto it : rabbit) {
                pq.push(it.second);
                score[it.first] = 0;
            }
        }
        else if (command == 200) {
            int K, S;
            cin >> K >> S;

            set<int> selected;

            for (int i = 0; i < K; i++) {
                int x = pq.top().x;
                int y = pq.top().y;
                int id = pq.top().id;
                int jump = pq.top().d;
                int count = pq.top().count;

                pq.pop();

                selected.insert(id);

                int mod_n = 2 * N - 2;
                int mod_m = 2 * M - 2;

                vector<pair<ll, ll>> coordinate;
                int nx = x;
                int ny = y;
                int dist = jump % mod_n;

                if (N - x >= dist) {
                    nx = x + dist;
                }
                else {
                    dist -= (N - x);
                    if (dist >= N) {
                        dist -= N - 1;
                        nx = 1 + dist;
                    }
                    else {
                        nx = N - dist;
                    }
                }
                coordinate.push_back(make_pair(nx, ny));
                nx = x;
                ny = y;
                dist = jump % mod_n;

                if (x - 1 >= dist) {
                    nx = x - dist;
                }
                else {
                    dist -= (x - 1);

                    if (dist >= N) {
                        dist -= N - 1;
                        nx = N - dist;
                    }
                    else {
                        nx = 1 + dist;
                    }
                }
                coordinate.push_back(make_pair(nx, ny));

                // 우
                nx = x;
                ny = y;
                dist = jump % mod_m;

                if (M - y >= dist) {
                    ny = y + dist;
                }
                else {
                    dist -= (M - y);
                    if (dist >= M) {
                        dist -= M - 1;
                        ny = 1 + dist;
                    }
                    else {
                        ny = M - dist;
                    }
                }
                coordinate.push_back(make_pair(nx, ny));

                // 좌
                nx = x;
                ny = y;
                dist = jump % mod_m;

                if (y - 1 >= dist) {
                    ny = y - dist;
                }
                else {
                    dist -= (y - 1);

                    if (dist >= M) {
                        dist -= M - 1;
                        ny = M - dist;
                    }
                    else {
                        ny = 1 + dist;
                    }
                }

                coordinate.push_back(make_pair(nx, ny));

                sort(coordinate.begin(), coordinate.end(), cmp);

                x = coordinate[0].first;
                y = coordinate[0].second;

                rabbit[id].x = x;
                rabbit[id].y = y;
                rabbit[id].count = count + 1;
                pq.push(rabbit[id]);


                for (auto& it : score) {
                    if (it.first != id)
                        it.second += x + y;
                }
            }

            vector<Rabbit> v;
            for (auto id : selected)
                v.push_back(rabbit[id]);

            sort(v.begin(), v.end(), give);

            score[v[0].id] += S;

        }
        else if (command == 300) {
            int id, l;
            cin >> id >> l;
            rabbit[id].d *= l;

            pq = priority_queue<Rabbit>();

            for (auto it : rabbit) {
                pq.push(it.second);
            }
        }
        else if (command == 400) {
            ll max_num = 0;

            for (auto it : score)
                max_num = max(max_num, it.second);
            cout << max_num;
        }
        Q--;
    }
    return 0;
}
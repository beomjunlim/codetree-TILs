#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
#include <cstring>
#include <climits>
using namespace std;

struct Sold {
    int price, id;
    bool operator<(const Sold& a) const {
        if (price != a.price)
            return price < a.price;
        return id > a.id;
    }
};

int n;
vector<pair<int, int>> Map[2001];
int cost[2001];
unordered_map<int, pair<int, int>> product;
priority_queue<Sold> CanP;

void dijkstra(int num) {
    for (int i = 0; i < n; i++) {
        cost[i] = INT_MAX;
    }
    cost[num] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,num });

    while (!pq.empty()) {
        int cnt = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (cost[node] < cnt)
            continue;

        for (int i = 0; i <Map[node].size(); i++) {
            int next = Map[node][i].first;
            int dist = cnt + Map[node][i].second;

            if (cost[next] > dist) {
                cost[next] = dist;
                pq.push({ -dist, next });
            }
        }
    }
}

int main() {
    int Q;
    cin >> Q;

    while (Q--) {
        int cmd;
        cin >> cmd;

        if (cmd == 100) {
            int m;
            cin >> n >> m;
            for (int i = 0; i < m; i++) {
                int a, b, c;
                cin >> a >> b >> c;
                Map[a].push_back({ b,c });
                Map[b].push_back({ a,c });
            }

            dijkstra(0);
        }
        else if (cmd == 200) {
            int id, price, dest;
            cin >> id >> price >> dest;

            product[id] = {price ,dest};
            int num = price - cost[dest];
            if (num >= 0)
                CanP.push({ num, id });
        }
        else if (cmd == 300) {
            int id;
            cin >> id;

            if (product.find(id) == product.end())
                continue;

            product.erase(id);
        }
        else if (cmd == 400) {
            int id;
            int dist = 0;
            if (CanP.empty())
                id = -1;

            bool sw = false;
            while (!CanP.empty()) {
                id = CanP.top().id;
                CanP.pop();
                
                if (product.find(id) != product.end()){
                    sw = true;
                    break;
                }
            }

            if(!sw)
                id = -1;
                
            if(id!=-1&&sw)
                product.erase(id);
            cout << id << '\n';
        }
        else if (cmd == 500) {
            int id;
            cin >> id;
            dijkstra(id);

            CanP = priority_queue<Sold>();
            for (auto& it : product) {
                int idx = it.first;
                int price = it.second.first;
                int dest = it.second.second;
                
                if (price - cost[dest] >= 0) {
                    CanP.push({ price - cost[dest], idx });
                }

            }
        }
    }
    return 0;
}
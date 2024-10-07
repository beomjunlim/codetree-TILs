#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <climits>
using namespace std;

int n, m;
vector<pair<int, int>> node[2001];
int cost[2001];
bool sold[30001];
map<int, pair<int, int>> product;
priority_queue<pair<int, int>> sale;

void dijkstra(int num) {
    for (int i = 0; i < n; i++) {
        cost[i] = INT_MAX;
    }

    priority_queue<pair<int, int>> pq;
    pq.push({ 0,num });
    cost[num] = 0;

    while (!pq.empty()) {
        int dis = -pq.top().first;
        int city = pq.top().second;
        pq.pop();

        if (cost[city] < dis)
            continue;

        for (int i = 0; i < node[city].size(); i++) {
            int next = node[city][i].first;
            int distance = dis + node[city][i].second;

            if (cost[next] > distance) {
                cost[next] = distance;
                pq.push({ -distance, next });
            }
        }
    }
}

bool CanSold(int id) {
    if (sold[id])
        return false;
    return true;
}

int main() {
    int Q;
    cin >> Q;

    while (Q > 0) {
        int command;
        cin >> command;
        if (command == 100) {
            cin >> n >> m;
            for (int i = 0; i < m; i++) {
                int a, b, c;
                cin >> a >> b >> c;
                node[a].push_back({ b,c });
                node[b].push_back({ a,c });
            }

            dijkstra(0);
        }
        else if (command == 200) {
            int id, pay, dest;
            cin >> id >> pay >> dest;
            product[id] = { pay,dest };

            if (pay >= cost[dest])
                sale.push({ pay - cost[dest], -id });
        }
        else if (command == 300) {
            int id;
            cin >> id;
            if (product.find(id) != product.end()) {
                //cout << id << " delete" << '\n';
                product.erase(id);
                sold[id] = true;
            }
        }
        else if (command == 400) {
            int answer = -1;

            if (sale.empty())
                answer = -1;
            else {
                bool sw = false;
                int id = -1;
                int pay = -1;
                while (!sale.empty()) {
                    id = -sale.top().second;
                    pay = sale.top().first;
                    sale.pop();
                    if (CanSold(id)) {
                        sw = true;
                        break;
                    }
                }
                
                if (sw) {
                   // cout << id << " " << pay << '\n';
                    product.erase(id);
                    sold[id] = true;
                    answer = id;
                }
            }

            cout << answer << '\n';
        }
        else if (command == 500) {
            int num;
            cin >> num;

            dijkstra(num);
            sale = priority_queue<pair<int, int>>();

            for (auto it : product) {
                int id = it.first;
                int pay = it.second.first;
                int dest = it.second.second;

                if (pay >= cost[dest])
                    sale.push({ pay - cost[dest], -id });
            }
        }
        Q--;
    }
    return 0;
}
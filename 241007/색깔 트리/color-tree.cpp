#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <climits>
#include <cstring>
#include <cmath>
using namespace std;

struct Node {
    int Pid, color, depth;
    vector<int> child;
};

Node node[100001];
set<int> idx;


int main() {
    int Q;
    cin >> Q;

    while (Q > 0) {
        int command;
        cin >> command;

        if (command == 100) {
            int id, Pid, color, depth;
            cin >> id >> Pid >> color >> depth;

            if (Pid == -1) {
                idx.insert(id);
                node[id] = { Pid,color,depth };
            }
            else {
                bool sw = true;
                int Parent = Pid;
                vector<pair<int, int>> p;
                int count = 0;
                while (Parent!=-1) {
                    count++;
                    p.push_back({ Parent, count });
                    Parent = node[Parent].Pid;
                }

                for (int i = 0; i < p.size(); i++) {
                    if (node[p[i].first].depth - p[i].second <= 0) {
                        sw = false;
                        break;
                    }
                }

                if (sw) {
                    for (int i = 0; i < p.size(); i++) {
                        node[p[i].first].child.push_back(id);
                    }

                   // cout << "insert" << id << '\n';
                    idx.insert(id);
                    node[id] = { Pid,color,depth };
                }
            }
        }
        else if (command == 200) {
            int id, color;
            cin >> id >> color;
            node[id].color = color;
            for (int i = 0; i < node[id].child.size(); i++) {
                node[node[id].child[i]].color = color;
            }
        }
        else if (command == 300) {
            int id;
            cin >> id;
            cout << node[id].color << '\n';
        }
        else if (command == 400) {
            int score = 0;
            for (auto it : idx) {
                set<int>Color;
                Color.insert(node[it].color);
                for (int i = 0; i < node[it].child.size(); i++) {
                    int ID = node[it].child[i];
                    Color.insert(node[ID].color);
                }
                score += pow(Color.size(), 2);
            }
            cout << score << '\n';
        }
        Q--;
    }
    return 0;
}
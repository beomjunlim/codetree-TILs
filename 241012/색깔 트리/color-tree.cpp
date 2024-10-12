#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;

struct Node {
    int id, Pid, color, depth;
    vector<int> child;
};

Node node[100001];
set<int> tree;

int main() {
    int Q;
    cin >> Q;

    while (Q--) {
        int cmd;
        cin >> cmd;

        if (cmd == 100) {
            int id, pid, color, depth;
            cin >> id >> pid >> color >> depth;

            if (pid == -1) {
                node[id] = { id,pid,color,depth };
                tree.insert(id);
            }
            else {
                bool sw = true;
                int Parent = pid;
                int cnt = 1;

                while (1) {
                    int Depth = node[Parent].depth;
                    if (Depth <= cnt) {
                        sw = false;
                        break;
                    }

                    Parent = node[Parent].Pid;
                    cnt++;
                    if (Parent == -1)
                        break;
                }

                if (sw) {
                    tree.insert(id);
                    node[id] = { id, pid, color, depth };
                    Parent = pid;
                    while (1) {
                        node[Parent].child.push_back(id);
                        Parent = node[Parent].Pid;

                        if (Parent == -1)
                            break;
                    }
                }
            }
        }
        else if (cmd == 200) {
            int id, color;
            cin >> id>>color;
            
            node[id].color = color;
            for (int i = 0; i < node[id].child.size(); i++) {
                node[node[id].child[i]].color = color;
            }
        }
        else if (cmd == 300) {
            int id;
            cin >> id;

            cout << node[id].color << '\n';
        }
        else if (cmd == 400) {
            int answer = 0;
            for (auto it : tree) {
                set<int> Color;
                Color.insert(node[it].color);
                for (int i = 0; i < node[it].child.size(); i++) {
                    Color.insert(node[node[it].child[i]].color);
                }

                answer += pow(Color.size(), 2);
            }

            cout << answer << "\n";
        }
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;

int n, m;
deque<pair<int, int>> belt[11];
set<int> check[11];
bool broke[11];
bool Discard[100001];
map<int, int> PID; // ID 값 i 값
int ID[100001];
int W[100001];

int main() {
    int Q;
    cin >> Q;

    while (Q--) {
        int cmd;
        cin >> cmd;

        if (cmd == 100) {
            cin >> n >> m;
            int idx = 1;
            int sub = n / m;
            for (int i = 1; i <= n; i++) {
                cin >> ID[i];
                PID[ID[i]] = i;
            }

            for (int i = 1; i <= n; i++) {
                cin >> W[i];
            }

            for (int i = 1; i <= n; i++) {
                belt[idx].push_back({ ID[i],W[i] });
                check[idx].insert(ID[i]);
                if (sub * idx == i)
                    idx++;
            }

        }
        else if (cmd == 200) {
            int weight;
            cin >> weight;

            int total = 0;
            for (int i = 1; i <= m; i++) {
                if (broke[i])
                    continue;
                int Id = belt[i].front().first;
                int num = belt[i].front().second;

                // for(int j=0; j<belt[i].size(); j++){
                //     cout<<"belt "<<i<<" Id "<<belt[i][j].first<<" w "<<belt[i][j].second<<" D "<<Discard[belt[i][j].first]<<'\n';
                // }
                while(1){
                    Id = belt[i].front().first;
                    num = belt[i].front().second;
                    belt[i].pop_front();

                    if(!Discard[PID[Id]]&&check[i].find(Id)!=check[i].end())
                        break;
                }

                if (num <= weight) {
                    Discard[PID[Id]] = true;
                    check[i].erase(Id);
                    total += num;
                }
                else {
                    belt[i].push_back({ Id,num });
                }
            }
            cout << total << '\n';
        }
        else if (cmd == 300) {
            int id;
            cin >> id;

            int discard = -1;
            if (!Discard[PID[id]]) {
                for (int i = 1; i <= m; i++) {
                    if (check[i].find(id) != check[i].end()) {
                        check[i].erase(id);
                        
                        Discard[id] = true;        
                        discard = id;   
                    }
                }
            }
            cout << discard << '\n';
        }
        else if (cmd == 400) {
            int id;
            cin >> id;

            int Look = -1;
            if (!Discard[PID[id]]) {
                for (int i = 1; i <= m; i++) {
                    if (check[i].find(id) != check[i].end()) {
                        Look = i;
                    }
                }

                if (Look != -1) {
                    int num = Look;
                    while (1) {
                        int IDX = belt[num].front().first;
                        int WEIGHT = belt[num].front().second;

                        if (IDX == id)
                            break;
                        
                        belt[num].pop_front();

                        if (Discard[PID[IDX]])
                            continue;
                        
                        belt[num].push_back({ IDX,WEIGHT });
                    }
                }
            }
            cout << Look << '\n';
        }
        else if (cmd == 500) {
            int num;
            cin >> num;
            int answer = -1;
            if (!broke[num]) {
                broke[num] = true;
                int beltNum = num + 1;
                int Id = -1;
                while (1) {
                    if (beltNum == m + 1)
                        beltNum = 1;
                    
                    if (!broke[beltNum]) {
                        Id = beltNum;
                        break;
                    }
                    beltNum++;
                }

                while (!belt[num].empty()) {
                    int idx = belt[num].front().first;
                    int weight = belt[num].front().second;
                    belt[num].pop_front();

                    if (Discard[idx])
                        continue;
                    belt[Id].push_back({ idx,weight });
                    check[Id].insert(idx);
                }
                check[num].clear();
                answer = num;
            }
            cout << answer << '\n';
        }

    }
        // for(int i=1; i<=m; i++){
        //     for(int j=0; j<belt[i].size(); j++){
        //             cout<<"belt "<<i<<" Id "<<belt[i][j].first<<" w "<<belt[i][j].second<<" D "<<Discard[belt[i][j].first]<<'\n';
        //         }
        // }
    return 0;
}
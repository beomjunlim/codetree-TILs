#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

int n,m,k;
int arr[11][11];
int attack[11][11];
bool visited[11][11];
int dx[] = {0,1,0,-1,-1,-1,1,1};
int dy[] = {1,0,-1,0,-1,1,-1,1};
priority_queue<pair<int, pair<int, pair<int, int>>>> small_turret; // 공격력 낮은, 가장 최근 공격, 행 열 합 높은, 열 높은
priority_queue<pair<int, pair<int, pair<int, int>>>> big_turret; // 공격력 높은, 가장 오래 전 공격, 행 열 합 낮은, 열 낮은

bool InRange(int x, int y){
    return 0<x&&x<=n&&0<y&&y<=m;
}

int main() {
    cin>>n>>m>>k;

    set<pair<int,int>> node;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
            attack[i][j] = 0;
            int sum = i + j;
            if(arr[i][j]!=0){
                small_turret.push(make_pair(-arr[i][j], make_pair(attack[i][j], make_pair(sum, j))));
                big_turret.push(make_pair(arr[i][j], make_pair(-attack[i][j], make_pair(-sum, -j))));
                node.insert(make_pair(i,j));
            }
        }
    }

    for(int sequence=1; sequence<=k; sequence++){
        int attack_power = -small_turret.top().first;
        int attack_x = small_turret.top().second.second.first - small_turret.top().second.second.second;
        int attack_y = small_turret.top().second.second.second;

        int defence_power = big_turret.top().first;
        int defence_x = -(big_turret.top().second.second.first - big_turret.top().second.second.second);
        int defence_y = -big_turret.top().second.second.second;

        if(attack_x==defence_x&&attack_y==defence_y)
            break;

        node.erase(make_pair(attack_x,attack_y)); // 공격자 제외
        

        small_turret = priority_queue<pair<int, pair<int, pair<int, int>>>> (); // 초기화
        big_turret = priority_queue<pair<int, pair<int, pair<int, int>>>> (); // 초기화

        
        attack_power += (n+m);
        arr[attack_x][attack_y] = attack_power;

    //    cout<<"attack "<<attack_x<<" "<<attack_y<<" ";
    //    cout<<"defence "<<defence_x<<" "<<defence_y<<'\n';
        
        memset(visited, 0, sizeof(visited));
        bool sw = false;

        queue<pair<int,int>> q;
        q.push(make_pair(attack_x, attack_y));
        visited[attack_x][attack_y] = true;
        pair<int,int> prev_node[11][11]; // 방문 경로를 저장하는 배열
        vector<pair<int,int>> path;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x==defence_x&&y==defence_y){
                // for(int i=1; i<=n; i++){
                //     for(int j=1; j<=m; j++){
                //         cout<<"{"<<prev_node[i][j].first<<" "<<prev_node[i][j].second<<"} ";
                //     }
                //     cout<<'\n';
                // }
                while(true){
                    if(x==attack_x&&y==attack_y)
                        break;

                    path.push_back(make_pair(x,y));
                    tie(x,y) = prev_node[x][y];  
                }

                // for(int i=0; i<path.size(); i++){
                //     cout<<path[i].first<<" "<<path[i].second<<'\n';
                // }
                // cout<<'\n';
                sw = true;
                break;
            }
            
            for(int j=0; j<4; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];

                if(InRange(nx,ny)){ // 범위 벗어나지 않을 경우
                    if(!visited[nx][ny]&&arr[nx][ny]!=0){
                        visited[nx][ny] = true;
                        prev_node[nx][ny] = make_pair(x,y);
                        q.push(make_pair(nx,ny));
                    }
                }
                else{ // 벗어날 경우
                    if(nx>n)
                        nx = 1;
                    if(nx==0)
                        nx = n;
                    if(ny>m)
                        ny = 1;
                    if(ny==0)
                        ny = m;

                    if(!visited[nx][ny]&&arr[nx][ny]!=0){
                        visited[nx][ny] = true;
                        prev_node[nx][ny] = make_pair(x,y);
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }


        if(sw){ // 레이저 공격
          //  cout<<"레이저"<<'\n';
            int half_power = attack_power / 2;
            for(int i=0; i<path.size(); i++){
                int x = path[i].first;
                int y = path[i].second;

                if(x==defence_x&&y==defence_y)
                    arr[x][y] = max(0, arr[x][y] - attack_power);
                else
                    arr[x][y] = max(0, arr[x][y] - half_power);
                node.erase(make_pair(x,y));
            }
        }
        else{ // 포탄 공격
         //   cout<<"포탄"<<'\n';
            int half_power = attack_power / 2;
            int x = defence_x;
            int y = defence_y;

            arr[x][y] = max(0, arr[x][y] - attack_power);
            node.erase(make_pair(x,y));

            for(int i=0; i<8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx==attack_x&&ny==attack_y)
                    continue;

                if(InRange(nx,ny)){
                    if(arr[nx][ny]!=0){
                        arr[nx][ny] = max(0, arr[nx][ny] - half_power);
                        node.erase(make_pair(nx,ny));
                    }
                }
                else{
                    if(nx>n&&ny>m){
                        nx = 1;
                        ny = 1;
                    }
                    else if(nx==0&&ny==0){
                        nx = n;
                        ny = m;
                    }
                    else if(nx>n&&ny==0){
                        nx = 1;
                        ny = m;
                    }
                    else if(nx==0&&ny>m){
                        nx = n;
                        ny = 1;
                    }
                    else if(nx>n&&ny<=m&&ny>0){
                        nx = 1;
                    }
                    else if(nx==0&&ny<=m&&ny>0){
                        nx = n;
                    }
                    else if(ny>m&&nx<=n&&nx>0){
                        ny = 1;
                    }
                    else if(ny==0&&nx<=n&&nx>0){
                        ny = m;
                    }
                    if(arr[nx][ny]!=0){
                        arr[nx][ny] = max(0, arr[nx][ny] - half_power);
                        node.erase(make_pair(nx,ny));
                    }
                }
            }
        }

        for(auto it : node){
            int x = it.first;
            int y = it.second;

            arr[x][y]++;
        }

        node.clear();

        attack[attack_x][attack_y] = sequence;
    //    cout<<"========================"<<'\n';
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int sum = i + j;
              //  cout<<arr[i][j]<<" ";
                if(arr[i][j]!=0){
                    small_turret.push(make_pair(-arr[i][j], make_pair(attack[i][j], make_pair(sum, j))));
                    big_turret.push(make_pair(arr[i][j], make_pair(-attack[i][j], make_pair(-sum, -j))));
                    node.insert(make_pair(i,j));
                }
            }
           // cout<<'\n';
        }
    }

    cout<<big_turret.top().first;
    return 0;
}



// #include <iostream>
// #include <stdio.h>
// using namespace std;

// #define MAX (10 + 5)

// int T;
// int N, M, K;

// int MAP[MAX][MAX];

// typedef struct st
// {
// 	int r;
// 	int c;
// }RC;

// int attackTime[MAX][MAX];

// // →, ↓, ←, ↑ 우/하/좌/상
// int dr[] = {0, 1, 0, -1};
// int dc[] = {1, 0, -1, 0};

// void input()
// {
// 	scanf("%d %d %d", &N, &M, &K);

// 	for (int r = 1; r <= N; r++)
// 		for (int c = 1; c <= M; c++)
// 			scanf("%d", &MAP[r][c]);

// 	// 시점 0에서 모두 공격
// 	for (int r = 1; r <= N; r++)
// 		for (int c = 1; c <= M; c++)
// 			attackTime[r][c] = 0;
// }

// void printMap()
// {
// 	for (int r = 1; r <= N; r++)
// 	{
// 		for (int c = 1; c <= M; c++)
// 			printf("%d ", MAP[r][c]);
// 		putchar('\n');
// 	}
			
// 	putchar('\n');
// }

// int getRecentTime(int minPower)
// {
// 	int recentTime = 0;
// 	for (int r = 1; r <= N; r++)
// 		for (int c = 1; c <= M; c++)
// 			if (attackTime[r][c] > recentTime && MAP[r][c] == minPower) 
// 				recentTime = attackTime[r][c];

// 	return recentTime;
// }

// int getLastTime(int maxPower)
// {
// 	int lastTime = 0x7fff0000;
// 	for (int r = 1; r <= N; r++)
// 		for (int c = 1; c <= M; c++)
// 			if (attackTime[r][c] < lastTime && MAP[r][c] == maxPower) 
// 				lastTime = attackTime[r][c];

// 	return lastTime;
// }

// RC getWeakestTower()
// {
// 	RC candidate[MAX * MAX] = { 0 };
// 	int cidx = 0;

// 	int power = 0;
// 	int minPower = 0x7fff0000;	
// 	for (int r = 1; r <= N; r++)
// 	{
// 		for (int c = 1; c <= M; c++)
// 		{
// 			if (MAP[r][c] == 0) continue;
// 			if (MAP[r][c] < minPower) minPower = MAP[r][c];
// 		}
// 	}

// 	for (int r = 1; r <= N; r++)
// 	{
// 		for (int c = 1; c <= M; c++)
// 		{			
// 			if (MAP[r][c] == minPower)
// 			{
// 				candidate[cidx].r = r;
// 				candidate[cidx++].c = c;
// 			}
// 		}
// 	}

// 	// 가장 약한 포탑이 1개인 경우
// 	if (cidx == 1) return candidate[0];

// 	int recentTime = getRecentTime(minPower);

// 	int length = cidx;
// 	cidx = 0;
// 	for (int i = 0; i < length; i++)
// 		if (attackTime[candidate[i].r][candidate[i].c] == recentTime)
// 			candidate[cidx++] = candidate[i];

// 	if (cidx == 1) return candidate[0];

// 	// 행과 열의 합이 가장 큰 포탑 구하기
// 	int maxRC = 0;
// 	for (int i = 0; i < cidx; i++)
// 		if (maxRC < (candidate[i].r + candidate[i].c))
// 			maxRC = (candidate[i].r + candidate[i].c);		

// 	length = cidx;
// 	cidx = 0;
// 	for (int i = 0; i < length; i++)
// 		if ((candidate[i].r + candidate[i].c) == maxRC)
// 			candidate[cidx++] = candidate[i];

// 	if (cidx == 1) return candidate[0];

// 	// 열 값이 가장 큰 포탑 구하기
// 	RC ret = { 0 };
// 	int maxC = 0;
// 	for (int i = 0; i < cidx; i++)
// 	{
// 		if (maxC < candidate[i].c)
// 		{
// 			maxC = candidate[i].c;
// 			ret = candidate[i];
// 		}
// 	}
	
// 	return ret;
// }

// RC getStrongestTower(RC attacker)
// {
// 	RC candidate[MAX * MAX] = { 0 };
// 	int cidx = 0;

// 	int power = 0;
// 	int maxPower = -1;
// 	for (int r = 1; r <= N; r++)
// 	{
// 		for (int c = 1; c <= M; c++)
// 		{
// 			// 공격자를 제외한 가장 강한 포탑
// 			if (attacker.r == r && attacker.c == c) continue;
// 			if (MAP[r][c] == 0) continue;
// 			if (MAP[r][c] > maxPower) maxPower = MAP[r][c];
// 		}
// 	}

// 	for (int r = 1; r <= N; r++)
// 	{
// 		for (int c = 1; c <= M; c++)
// 		{
// 			if (attacker.r == r && attacker.c == c) continue;

// 			if (MAP[r][c] == maxPower)
// 			{
// 				candidate[cidx].r = r;
// 				candidate[cidx++].c = c;
// 			}
// 		}
// 	}

// 	// 가장 강한 포탑이 1개인 경우
// 	if (cidx == 1) return candidate[0];

// 	int lastTime = getLastTime(maxPower);

// 	int length = cidx;
// 	cidx = 0;
// 	for (int i = 0; i < length; i++)
// 		if (attackTime[candidate[i].r][candidate[i].c] == lastTime)
// 			candidate[cidx++] = candidate[i];

// 	if (cidx == 1) return candidate[0];

// 	// 행과 열의 합이 가장 작은 포탑 구하기
// 	int minRC = 0x7fff0000;
// 	for (int i = 0; i < cidx; i++)
// 		if (minRC > (candidate[i].r + candidate[i].c))
// 			minRC = (candidate[i].r + candidate[i].c);

// 	length = cidx;
// 	cidx = 0;
// 	for (int i = 0; i < length; i++)
// 		if ((candidate[i].r + candidate[i].c) == minRC)
// 			candidate[cidx++] = candidate[i];

// 	if (cidx == 1) return candidate[0];

// 	// 열 값이 가장 작은 포탑 구하기
// 	RC ret = { 0 };
// 	int minC = 0x7fff0000;
// 	for (int i = 0; i < cidx; i++)
// 	{
// 		if (minC > candidate[i].c)
// 		{
// 			minC = candidate[i].c;
// 			ret = candidate[i];
// 		}
// 	}

// 	return ret;
// }

// int laser(RC start, RC end)
// {
// 	RC queue[MAX * MAX] = { 0 };
// 	int rp, wp;

// 	int visit[MAX][MAX] = { 0 };
// 	RC before[MAX][MAX] = { 0 }; // 코드트리 빵

// 	rp = wp = 0;

// 	int sr = start.r;
// 	int sc = start.c;
// 	int er = end.r;
// 	int ec = end.c;

// 	queue[wp].r = sr;
// 	queue[wp++].c = sc;
	
// 	before[sr][sc].r = -1;
// 	before[sr][sc].c = -1;

// 	visit[sr][sc] = 1;

// 	while (rp < wp)
// 	{
// 		RC out = queue[rp++];

// 		if (out.r == end.r && out.c == end.c)
// 		{
// 			int power = MAP[sr][sc];
			
// 			int tr = out.r;
// 			int tc = out.c;

// 			MAP[tr][tc] -= power;

// 			// 이전 좌표를 찾으면서 처리			
// 			while (1)
// 			{
// 				// 이전 좌표
// 				int br = before[tr][tc].r;
// 				int bc = before[tr][tc].c;
	 
// 				if (br == sr && bc == sc) break;

// 				MAP[br][bc] -= (power / 2);

// 				tr = br;
// 				tc = bc;
// 			}

// 			return 1;
// 		}

// 		for (int i = 0; i < 4; i++)
// 		{
// 			int nr = ((out.r + dr[i] + N) - 1) % N + 1;
// 			int nc = ((out.c + dc[i] + M) - 1) % M + 1;

// 			if (MAP[nr][nc] != 0 && visit[nr][nc] == 0)
// 			{
// 				queue[wp].r = nr;
// 				queue[wp++].c = nc;

// 				before[nr][nc].r = out.r; // 이전 좌표 기억
// 				before[nr][nc].c = out.c;

// 				visit[nr][nc] = 1;
// 			}
// 		}
// 	}
	
// 	return 0;
// }

// void attack(RC attacker, RC target, int time)
// {	
// 	attackTime[attacker.r][attacker.c] = time;

// 	if(laser(attacker, target) == 1){
//         cout<<"레이저 ";
//         return;
//     } 
//     cout<<"포탄 ";

// 	/* ←, ↖, ↑, ↗, →, ↘, ↓, ↙  */
// 	int dr8[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
// 	int dc8[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

// 	int sr = attacker.r;
// 	int sc = attacker.c;
// 	int er = target.r;
// 	int ec = target.c;

// 	int power = MAP[sr][sc];

// 	MAP[er][ec] -= power;
// 	for (int i = 0; i < 8; i++)
// 	{
// 		int nr = ((er + dr8[i] + N) - 1) % N + 1;
// 		int nc = ((ec + dc8[i] + M) - 1) % M + 1;

// 		if (MAP[nr][nc] == 0) continue;
// 		if (nr == sr && nc == sc) continue; // 공격자는 영향을 받지 않음.

// 		MAP[nr][nc] -= (power / 2);
// 	}
// }

// void setBrokenTower()
// {
// 	for (int r = 1; r <= N; r++)
// 		for (int c = 1; c <= M; c++)
// 			if (MAP[r][c] < 0) MAP[r][c] = 0;	
// }

// void maintainTower(int tempMAP[MAX][MAX])
// {
// 	for (int r = 1; r <= N; r++)
// 	{
// 		for (int c = 1; c <= M; c++)
// 		{
// 			if (tempMAP[r][c] == 0) continue;
// 			if (tempMAP[r][c] != MAP[r][c]) continue;
			
// 			MAP[r][c]++;
// 		}
// 	}
// }

// int simulate()
// {
// 	for (int time = 1; time <= K; time++)
// 	{
// 		// 0. 현재 상태 저장
// 		int tempMAP[MAX][MAX] = { 0 };
// 		for (int r = 1; r <= N; r++)
// 			for (int c = 1; c <= M; c++)
// 				tempMAP[r][c] = MAP[r][c];

// 		// 1. 공격자 선정
// 		RC attacker = getWeakestTower();

// 		// 2. 공격자의 공격
// 		// 2-1. target 탐색
// 		RC target = getStrongestTower(attacker);

//         cout<<"attack "<<attacker.r<<" "<<attacker.c<<" defecne "<<target.r<<" "<<target.c<<'\n';

// 		// 2-2. target이 없는 경우 종료 = 부서지지 않은 포탑이 1개가 되는 경우
// 		if (target.r == 0 && target.c == 0) break;

// 		// 2-3. target이 있는 경우 공격
// 		MAP[attacker.r][attacker.c] += (M + N);
// 		attack(attacker, target, time);

// 		// 3. 포탑 부서짐
// 		setBrokenTower();
        
//         cout<<'\n';
// 		// 4. 포탑 정비
// 		maintainTower(tempMAP);				
// 	}

// 	// 5. 가장 큰 값 탐색
// 	int maxPower = 0;
// 	for (int r = 1; r <= N; r++)
// 		for (int c = 1; c <= M; c++)
// 			if (maxPower < MAP[r][c]) maxPower = MAP[r][c];

// 	return maxPower;
// }

// int main(void)
// {
// 	// scanf("%d", &T);
// 	T = 1;
// 	for (int tc = 1; tc <= T; tc++)
// 	{
// 		input();
// 		printf("%d\n", simulate());
// 	}

// 	return 0;
// }
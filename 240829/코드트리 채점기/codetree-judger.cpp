// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <queue>
// #include <set>
// #include <map>
// #include <string>
// using namespace std;

// int N,t,p,id;
// string url;
// priority_queue<int> grader; // 채점기
// priority_queue<pair<int,pair<int, string>>> waiting_queue;
// map<string, pair<int,int>> waiting;  // 우선 순위, 들어온 시각
// map<string, pair<int,int>> grading; // 채점 중 도메인, 채점기 id, 시작 시각
// map<string, pair<int,int>> record; // 기록 도메인 채점 시작 시각, 끝나는 시각

// int main() {
//     int Q;
//     cin>>Q;

//     while(Q--){
//         int command;
//         cin>>command;

//         if(command==100){
//             cin>>N>>url;

//             for(int i=1; i<=N; i++){
//                 grader.push(-i);
//             }

//             waiting[url] = make_pair(1,0);
//             waiting_queue.push(make_pair(-1,make_pair(0,url)));
//         }
//         else if(command==200){
//             cin>>t>>p>>url;

//             if(waiting.find(url)!=waiting.end())
//                 continue;

//             waiting[url] = make_pair(p,t);
//             waiting_queue.push(make_pair(-p, make_pair(-t,url)));
//         }
//         // else if(command==300){
//         //     cin>>t;

//         //     if(grader.empty())
//         //         continue;

//         //     int min_P = N + 1;
//         //     int min_T = t + 1;
//         //     string deleted_url;
            
//         //     for(auto it : waiting){
//         //         string URL = it.first;
//         //         int P = it.second.first;
//         //         int T = it.second.second;

//         //         string result = URL.substr(0, URL.find('/'));

//         //         if(grading.find(result)!=grading.end()) // 이미 채점 중인 도메인
//         //             continue;
                
//         //         if(record.find(result)!=record.end()){
//         //             int start = record[result].first;
//         //             int gap = record[result].second - start;

//         //             if(t>=start+3*gap){
//         //                 if(min_P>P){
//         //                     min_P = P;
//         //                     min_T = T;
//         //                     deleted_url = URL;
//         //                 }
//         //                 else if(min_P==P){
//         //                     if(min_T>T){
//         //                         min_T = T;
//         //                         deleted_url = URL;
//         //                     }
//         //                 }
//         //             }
//         //         }
                
//         //         else{
//         //             if(min_P>P){
//         //                 min_P = P;
//         //                 min_T = T;
//         //                 deleted_url = URL;
//         //             }
//         //             else if(min_P==P){
//         //                 if(min_T>T){
//         //                     min_T = T;
//         //                     deleted_url = URL;
//         //                 }
//         //             }
//         //         }
//         //     }

//         //     if(min_P==N+1&&min_T==t+1)
//         //         continue;

//         //     string deleted_result = deleted_url.substr(0, deleted_url.find('/'));
//         //     waiting.erase(deleted_url);


//         //     int ID = -grader.top();
//         //     grader.pop();
//         //     grading[deleted_result] = make_pair(ID,t);
//         // }
//         else if(command==300){
//             cin>>t;

//             if(grader.empty())
//                 continue;

//             int min_P = N + 1;
//             int min_T = t + 1;
//             string deleted_url;
            
//             priority_queue<pair<int,pair<int, string>>> temp = waiting_queue;

//             while(!temp.empty()){
//                 string URL = temp.top().second.second;
//                 int P = -temp.top().first;
//                 int T = -temp.top().second.first;
//                 temp.pop();

//                 string result = URL.substr(0, URL.find('/'));

//                 if(grading.find(result)!=grading.end())
//                     continue;
                
//                 if(record.find(result)!=record.end()&&waiting.find(URL)!=waiting.end()){
//                     int start = record[result].first;
//                     int gap = record[result].second - start;

//                     if(t>=start+3*gap){
//                         if(min_P>P){
//                             min_P = P;
//                             min_T = T;
//                             deleted_url = URL;
//                         }
//                         else if(min_P==P){
//                             if(min_T>T){
//                                 min_T = T;
//                                 deleted_url = URL;
//                             }
//                         }
//                     }
//                 }
                
//                 else if(waiting.find(URL)!=waiting.end()){
//                     if(min_P>P){
//                         min_P = P;
//                         min_T = T;
//                         deleted_url = URL;
//                     }
//                     else if(min_P==P){
//                         if(min_T>T){
//                             min_T = T;
//                             deleted_url = URL;
//                         }
//                     }
//                 }
//             }
        

//             if(min_P==N+1&&min_T==t+1)
//                 continue;

//             string deleted_result = deleted_url.substr(0, deleted_url.find('/'));
//             waiting.erase(deleted_url);

//             int ID = -grader.top();
//             grader.pop();
//             grading[deleted_result] = make_pair(ID,t);
//         }
//         else if(command==400){
//             cin>>t>>id;

//             string str;
//             int start;
//             for(auto it : grading){
//                 if(it.second.first==id){
//                     str = it.first;
//                     start = it.second.second;
//                     break;
//                 }
//             }

//             grading.erase(str);
//             record[str] = make_pair(start,t);
//             grader.push(-id);
//         }
//         else if(command==500){
//             cin>>t;
//             cout<<waiting.size()<<'\n';
//         }
//     }
//     return 0;
// }


#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;
const int INF=1e9+1;

struct cmp {
    bool operator()(pair<pii,string>& a, pair<pii,string>& b) {
        if(a.first.first==b.first.first) {
            if(a.first.second==b.first.second)
                return a.second>b.second;
            return a.first.second>b.first.second;
        }
        return a.first.first>b.first.first;
    }
};

unordered_map<string,set<int>> waiting_urls; // (domain, problem_id), in waiting queue

unordered_map<string,int> retried; // domain, retried_time
unordered_map<string,int> process_start_time; // domain, start_time
unordered_map<string,bool> judging_domains; // domain, in judging

priority_queue<int,vector<int>,greater<int>> judger_idx; // judger index, sort asc
vector<string> judger; // judger

// waiting queue = (domain, priority queue)
// priority_queue.push((priority, insert_time), url)
unordered_map<string,priority_queue<pair<pii,string>,vector<pair<pii,string>>,cmp>> waiting_queue; 

int waiting_cnt=0;

pair<string,int> get_domain(string url) {
    // parsing domain from url
    int i=url.find('/');
    return {url.substr(0,i),stoi(url.substr(i+1))};
}

void init(int N, string url) {
    // 1 - N까지의 채점기
    judger=vector<string>(N+1,"");
    for(int i=1;i<=N;i++) judger_idx.push(i);
    auto [domain,problem_id]=get_domain(url);
    
    // url = (0초, 우선순위 1)
    waiting_queue[domain].push({{1,0},url});
    
    // 같은 url이 waiting queue에 들어오지 못하도록 관리
    waiting_urls[domain].insert(problem_id);
    
    waiting_cnt++;
}

void request(int mTime, int p, string url) { // newUrl
    auto [domain,problem_id]=get_domain(url);
    if(waiting_queue.find(domain)!=waiting_queue.end()) {
        // url의 도메인이 queue에 등록되어 있고 중복되지 않았다면 추가
        if(waiting_urls[domain].find(problem_id)!=waiting_urls[domain].end()) return;
        waiting_queue[domain].push({{p,mTime},url});
        waiting_urls[domain].insert(problem_id);
        waiting_cnt++;
    }
    else {
        // url의 도메인이 queue에 등록되지 않았다면 빈 pq에 url 추가
        priority_queue<pair<pii,string>,vector<pair<pii,string>>,cmp> temp;
        temp.push({{p,mTime},url});
        waiting_queue[domain]=temp;
        waiting_urls[domain]={problem_id};
        waiting_cnt++;
    }
}

void assign(int mTime) {
    // 빈 채점기가 없으면 무시
    if(judger_idx.empty()) return;
    
    // waiting_queue의 전체 url을 순회할 필요 없이 각 도메인별로 우선순위가 높은 url만 탐색한다
    pair<pii,string> x={{INF,INF},""};
    for(auto iter=waiting_queue.begin();iter!=waiting_queue.end();iter++) {
        string domain=iter->first;
        if(judging_domains[domain]) continue;
        if(!iter->second.empty()) {
            if(retried[domain]<=mTime) {
                if(x.first.first>iter->second.top().first.first)
                    x=iter->second.top();
                else if(x.first.first==iter->second.top().first.first && 
                    x.first.second>iter->second.top().first.second)
                    x=iter->second.top();
            }
        }
    }
    // 채점할 수 있는 url이 없다면 리턴
    if(x.second=="") return;
    
    // waiting_queue에서 url 제거
    auto [domain,problem_id]=get_domain(x.second);
    waiting_queue[domain].pop();
    waiting_urls[domain].erase(problem_id);
    waiting_cnt--;
    
    // assign
    int judger_id=judger_idx.top();
    judger_idx.pop();
    judger[judger_id]=domain;
    judging_domains[domain]=true;
    process_start_time[domain]=mTime;
}

void finish(int mTime, int mId) {
    // 채점 중이 아니라면 무시
    if(judger[mId]=="") return;
    
    // 채점기 초기화와 비어있는 채점기 번호를 judger_idx에 추가
    string domain=judger[mId];
    judger[mId]="";
    judger_idx.push(mId);
    judging_domains[domain]=false;
    
    // 채점을 재시도할 수 있는 시간을 기록
    retried[domain]=process_start_time[domain]+(mTime-process_start_time[domain])*3;
}

int check(int mTime) {
    return waiting_cnt;
}

int main() {
    fastio
    int query_cnt; cin>>query_cnt;
    while(query_cnt--) {
        int cmd; cin>>cmd;
        switch(cmd) {
            case 100: {
                int N;
                string url;
                cin>>N>>url;
                init(N,url);
                break;
            }
            case 200: {
                int mTime, p;
                string url;
                cin>>mTime>>p>>url;
                request(mTime, p, url);
                break;
            }
            case 300: {
                int mTime; cin>>mTime;
                assign(mTime);
                break;
            }
            case 400: {
                int mTime, mId; cin>>mTime>>mId;
                finish(mTime, mId);
                break;
            }
            case 500: {
                int mTime; cin>>mTime;
                cout<<check(mTime)<<endl;
                break;
            }
            default:
                break;
        }
    }
    return 0;
}
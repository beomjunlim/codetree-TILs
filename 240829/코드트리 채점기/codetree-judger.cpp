#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int N,t,p,id;
string url;
priority_queue<int> grader; // 채점기
//priority_queue<pair<int, pair<int,string>>> waiting_queue; // 대기 큐 우선순위, 들어온 시각 
//set<string> waiting; // 대기 중
map<string, pair<int,int>> waiting;  // 우선 순위, 들어온 시각
map<int, pair<int,string>> grading; // 채점 중 채점기 id, 시작 시각, 도메인
map<string, pair<int,int>> record; // 기록 채점 시작 시각, 끝나는 시각

int main() {
    int Q;
    cin>>Q;

    while(Q--){
        int command;
        cin>>command;

        if(command==100){
            cin>>N>>url;

            for(int i=1; i<=N; i++){
                grader.push(-i);
            }

            waiting[url] = make_pair(1,0);
        }
        else if(command==200){
            cin>>t>>p>>url;

            if(waiting.find(url)!=waiting.end())
                continue;

            waiting[url] = make_pair(p,t);
        }
        else if(command==300){
            cin>>t;

            if(grader.empty())
                continue;

            int min_P = N + 1;
            int min_T = t + 1;
            string deleted_url;
            
            //cout<<"start!"<<'\n';
            for(auto it : waiting){
                string URL = it.first;
                int P = it.second.first;
                int T = it.second.second;
                //cout<<URL<<" "<<P<<" "<<T<<'\n';
                string result = URL.substr(0, URL.find('/'));

                bool sw = false;
                for(auto graders :  grading){
                    if(graders.second.second==result){

                        sw = true;
                        break;
                    }
                }

                if(sw)
                    continue;
                
                if(record.find(result)!=record.end()){
                    int max_start = 0;
                    int max_end = 0;
                    for(auto records : record){
                        if(records.first==result){
                            int start = records.second.first;
                            int end = records.second.second;

                            if(end> max_end){
                                max_start = start;
                                max_end = end;
                            }
                        }
                    }

                    int gap = max_end - max_start;
                    if(t>=max_start+3*gap){
                        if(min_P>P){
                            min_P = P;
                            min_T = T;
                            deleted_url = URL;
                        }
                        else if(min_P==P){
                            if(min_T>T){
                                min_T = T;
                                deleted_url = URL;
                            }
                        }
                    }
                }
                else{
                    if(min_P>P){
                        min_P = P;
                        min_T = T;
                        deleted_url = URL;
                    }
                    else if(min_P==P){
                        if(min_T>T){
                            min_T = T;
                            deleted_url = URL;
                        }
                    }
                }
            }

            if(min_P==N+1&&min_T==t+1)
                continue;
            //cout<<"deleted"<<" "<<deleted_url<<'\n';
            string deleted_result = deleted_url.substr(0, deleted_url.find('/'));
            waiting.erase(deleted_url);


            int ID = -grader.top();
            grader.pop();
            grading[ID] = make_pair(t,deleted_result);
        }
        else if(command==400){
            cin>>t>>id;

            string deleted_url = grading[id].second;
            int start = grading[id].first;
            // cout<<"400 "<<grading.size()<<'\n';
            // for(auto it : grading){
            //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<'\n';
            // }
            grading.erase(id);

            //cout<<"400 after "<<grading.size()<<'\n';
            record[deleted_url] = make_pair(start, t);
            grader.push(-id);
        }
        else if(command==500){
            cin>>t;
            cout<<waiting.size()<<'\n';

            // for(auto it : waiting){
            //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<'\n';
            // }
        }
    }
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

class Spy{
    public:
        string secret_code;
        char meeting_point;
        int time;
        Spy(string secret_code, char meeting_point, int time){
            this->secret_code = secret_code;
            this->meeting_point = meeting_point;
            this->time = time;
        } 
};

int main() {
    string s;
    char m;
    int t;

    cin>>s>>m>>t;

    Spy spy = Spy(s,m,t);

    cout << "secret code : " << spy.secret_code << endl;
    cout << "meeting point : " << spy.meeting_point << endl;
    cout << "time : " << spy.time << endl;
    return 0;
}
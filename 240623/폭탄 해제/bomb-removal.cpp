#include <iostream>
using namespace std;

class a{
    public:
        string code;
        char color;
        int second;

        a(string code = "", char color = ' ', int second = 0){
            this->code = code;
            this->color = color;
            this->second = second;
        }
};

int main() {
    a A = a();

    string code;
    char color;
    int second;

    cin>>code;
    cin>>color;
    cin>>second;

    A.code = code;
    A.color = color;
    A.second = second;

    cout<<"code : "<<A.code<<'\n';
    cout<<"color : "<<A.color<<'\n';
    cout<<"second : "<<A.second<<'\n';
    return 0;
}
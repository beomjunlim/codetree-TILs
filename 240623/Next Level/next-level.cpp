#include <iostream>
using namespace std;

class Game{
    public:
        string id;
        int level;
        Game(string id = "", int level = 0){
            this->id = id;
            this->level = level;
        }
};

int main() {
    Game a = Game("codetree", 10);
    Game b = Game();
    string id;
    int level;
    cin>>id;
    cin>>level;

    b.id = id;
    b.level = level;
    cout<<"user "<<a.id<<" lv "<<a.level<<'\n';
    cout<<"user "<<b.id<<" lv "<<b.level<<'\n';
    return 0;
}
#include <iostream>
using namespace std;

class Spy{
    public:
        char name;
        int score;

        Spy(char name=' ', int score = 0){
            this->name = name;
            this->score = score;
        }
};

int main() {
    Spy spy[5];
    int num = 101;
    int idx = 0;

    for(int i=0; i<5; i++){
        char name;
        int score;
        cin>>name;
        cin>>score;
        spy[i].name = name;
        spy[i].score = score;

        if(num>score){
            num = score;
            idx = i;
        }
    }

    cout<<spy[idx].name<<" "<<spy[idx].score<<'\n';


    return 0;
}
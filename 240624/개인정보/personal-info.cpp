#include <iostream>
#include <algorithm>
using namespace std;

class Student{
    public:
        string name;
        int height;
        float weight;

        Student(string name ="", int height=0, float weight=0){
            this->name = name;
            this->height = height;
            this->weight =weight;
        }
};

bool cmp_name(const Student &a, const Student &b){
    return a.name < b.name;
}

bool cmp_height(const Student &a, const Student &b){
    return a.height > b.height;
}

int main() {
    Student student[5] = {
        Student("lee", 167, 40.1),
        Student("kim", 149, 32.9),
        Student("park", 161, 53.1),
        Student("choi", 183, 70.3),
        Student("jung", 155, 45.7)
    };

    sort(student, student+5, cmp_name);

    cout<<"name"<<'\n';
    for(int i=0; i<5; i++){
        cout<<student[i].name<<" "<<student[i].height<<" "<<student[i].weight<<'\n';
    }

    cout<<'\n';
    sort(student, student+5, cmp_height);

    cout<<"height"<<'\n';
    for(int i=0; i<5; i++){
        cout<<student[i].name<<" "<<student[i].height<<" "<<student[i].weight<<'\n';
    }
    return 0;
}
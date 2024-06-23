#include <iostream>
#include <vector>
using namespace std;

class paper{
    public:
        string name;
        string number;
        string region;

        paper(string name ="", string number="", string region=""){
            this->name = name;
            this->number = number;
            this->region = region;
        }
};

int main() {
    int n;
    cin>>n;

    string cmp = "";
    int idx = 0;
    vector<paper> P(n);

    for(int i=0; i<n; i++){
        string name;
        string number;
        string region;
        cin>>name;
        cin>>number;
        cin>>region;

        P[i].name = name;
        P[i].number = number;
        P[i].region = region;

        if(i==0){
            cmp = P[0].name;
        }
        else{
            if(cmp < P[i].name){
                cmp = P[i].name;
                idx= i;
            }
        }
    }

    cout<<"name "<<P[idx].name<<'\n';
    cout<<"addr "<<P[idx].number<<'\n';
    cout<<"city "<<P[idx].region<<'\n';
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Weather{
    public:
        string date;
        string day;
        string weather;

        Weather(string date ="", string day ="", string weather= ""){
            this->date = date;
            this->day = day;
            this->weather = weather;
        }
};

int main() {
    int n;
    cin>>n;

    vector<Weather> w(n);

    int idx = -1;
    string min_date = "";

    for(int i=0; i<n; i++){
        string date;
        string day;
        string weather;

        cin>>date;
        cin>>day;
        cin>>weather;
        w[i].date = date;
        w[i].day = day;
        w[i].weather = weather;

        if(weather =="Rain"&&idx==-1){
            idx = i;
            min_date = date;
        }
        else if(weather=="Rain"&&idx!=-1&&min_date > date){
            idx = i;
            min_date = date;
        }
    }

    cout<<w[idx].date<<" "<<w[idx].day<<" "<<w[idx].weather<<'\n';


    return 0;
}
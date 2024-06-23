#include <iostream>
using namespace std;

class Product{
    public:
        string name;
        int code;

        Product(string name ="", int code = 0){
            this->name = name;
            this->code = code;
        }
};
int main() {
    Product A = Product("codetree", 50);
    Product B = Product();

    string name;
    int code;
    cin>>name;
    cin>>code;

    B.name = name;
    B.code = code;

    cout<<"product "<<A.code<<" is "<<A.name<<'\n';
    cout<<"product "<<B.code<<" is "<<B.name<<'\n';
    return 0;
}
#include <iostream>
using namespace std;
class Bird{
public:
    Bird(const string& name_in)
    :name(name_in), age(0){
        cout << "bird constructor" << endl;
    }

    ~Bird(){
        cout << "bird desstructor" << endl;
    }

    void have_birthday(){
        age++;
        cout << "having birthday" << endl;
    }

    int get_age(){
        return age;
    }

    void talk(){
        cout << "tweet" << endl;
    }
private:
    string name;
    int age;
};

class Duck: public Bird {
public:
    Duck(const string& name_in)
    :Bird(name_in), children(0){
        cout << "duck constructor" << endl;
    }

    ~Duck(){
        cout << "duck destructor" << endl;
    }

    void have_children(){
        children++;
    }

    int get_children(){
        return children;
    }

    void talk(){
        cout << "gwak" << endl;
    }
private: 
    int children;
};

int main(){
    Bird david("david");
    david.have_birthday();
    david.talk();
    cout << "david's age: " << david.get_age() << endl; 

    Duck albert("albert");
    albert.have_birthday();
    cout << "albert's age: " << albert.get_age() << endl;
    albert.talk();
    albert.have_children();
    cout << "David's children: " << albert.get_children() << endl; 
    return 0;
}
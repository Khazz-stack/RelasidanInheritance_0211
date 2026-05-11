#include <iostream>
#include <string>
using namespace std;

class Jantung {
public:
    Jantung() {
        cout << "Jantung Ditambah\n";
    }
    ~Jantung() {
        cout << "Jantung Dimatikan\n";
    }
};

class Manusia {
private:
    string nama;
    Jantung jantung;
public:
    Manusia(const string& name) : nama(name) {
        cout << "Manusia " << nama << " Dibuat\n";
    }
    ~Manusia() {
        cout << "Manusia " << nama << " Dimatikan\n";
    }
};

int main()
{
    //deklarasi dan pemberian nilai object pointer varManusia
    Manusia* varManusia = new Manusia("jono");
    //mendelete pointer varManusia dari memori
    delete varManusia;
    return 0;
}
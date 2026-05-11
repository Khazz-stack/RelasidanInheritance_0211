#include <iostream>
#include <vector>
using namespace std;

//deklarasi class dokter
class dokter;

//deklarasi dan pembuatan class pasien
class pasien {
public:
    //deklarasi member variabel dari class pasien
    string nama;
    vector<dokter*> daftar_dokter;

    //pembuatan constructor dan destructor dari class pasien
    pasien(string pNama) :nama(pNama) {
        cout << "Pasien \"" << nama << "\" ada\n";
    };
}
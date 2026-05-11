#ifndef IBU_H
#define IBU_H

class anak;

//membuat class ibu pada file header ibu.h
class Ibu {
public:
    //deklarasi member variabel pada class ibu
    string nama;
    vector<anak*> daftar_anak;
    
    //membuat constructor dan destructor pada class ibu
    ibu(string pNama) :nama(pNama) {
        cout << "ibu \"" << nama << "\" ada\n";  
    };

    ~ibu(){
        cout << "ibu \"" << nama << "\" tidak ada\n";
    };

    //deklarasi prosedur tambahAnak() dan cetakAnak()
    void tambahAnak(anak pAnak);
    void cetakAnak();
};
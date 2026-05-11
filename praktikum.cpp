#include <iostream>
#include <string>
#include <vector>

// ============================================================
//  Class User (Parent)
// ============================================================
class User {
protected:
    static int globalId;   // shared counter untuk semua instance
    int        id;
    std::string nama;
    std::string email;

public:
    User(const std::string& nama, const std::string& email)
        : nama(nama), email(email) {
        id = generateId();
    }

    virtual ~User() = default;

    int generateId() {
        return ++globalId;
    }

    // Getter
    int         getId()    const { return id; }
    std::string getNama()  const { return nama; }
    std::string getEmail() const { return email; }
};

// Definisi static member di luar class
int User::globalId = 0;


// ============================================================
//  Class Member (turunan User)
// ============================================================
class Member : public User {
private:
    bool status;   // true = aktif, false = nonaktif

public:
    Member(const std::string& nama, const std::string& email)
        : User(nama, email), status(true) {}

    // Getter & setter status
    bool getStatus() const { return status; }
    void setStatus(bool s) { status = s; }

    void showProfile() const {
        std::cout << "========== Profil Member ==========\n";
        std::cout << "ID     : " << id                          << "\n";
        std::cout << "Nama   : " << nama                        << "\n";
        std::cout << "Email  : " << email                       << "\n";
        std::cout << "Status : " << (status ? "Aktif" : "Nonaktif") << "\n";
        std::cout << "====================================\n";
    }
};


// ============================================================
//  Class Admin (turunan User)
// ============================================================
class Admin : public User {
private:
    std::vector<Member*> daftarMember;

public:
    Admin(const std::string& nama, const std::string& email)
        : User(nama, email) {}

    // Daftarkan member ke dalam sistem
    void tambahMember(Member* m) {
        daftarMember.push_back(m);
    }

    // Tampilkan semua member
    void showAllMember() const {
        std::cout << "\n========== Daftar Semua Member ==========\n";
        if (daftarMember.empty()) {
            std::cout << "(belum ada member terdaftar)\n";
        } else {
            for (const auto& m : daftarMember) {
                std::cout << "ID: "    << m->getId()
                          << "  Nama: " << m->getNama()
                          << "  Email: "<< m->getEmail()
                          << "  Status: "<< (m->getStatus() ? "Aktif" : "Nonaktif")
                          << "\n";
            }
        }
        std::cout << "=========================================\n\n";
    }

    // Toggle status aktif/nonaktif berdasarkan ID
    void toggleActivationMember(int targetId) {
        for (auto& m : daftarMember) {
            if (m->getId() == targetId) {
                m->setStatus(!m->getStatus());
                std::cout << "Status member \"" << m->getNama() << "\" diubah menjadi "
                          << (m->getStatus() ? "Aktif" : "Nonaktif") << ".\n";
                return;
            }
        }
        std::cout << "Member dengan ID " << targetId << " tidak ditemukan.\n";
    }
};


// ============================================================
//  Main — demo penggunaan
// ============================================================
int main() {
    // Buat admin
    Admin admin("Budi Admin", "budi@admin.com");

    // Buat beberapa member
    Member m1("Andi",  "andi@mail.com");
    Member m2("Sari",  "sari@mail.com");
    Member m3("Reza",  "reza@mail.com");

    // Daftarkan ke admin
    admin.tambahMember(&m1);
    admin.tambahMember(&m2);
    admin.tambahMember(&m3);

    // Tampilkan semua member
    admin.showAllMember();

    // Tampilkan profil salah satu member
    m1.showProfile();

    // Toggle status member (nonaktifkan Sari)
    admin.toggleActivationMember(m2.getId());

    // Tampilkan ulang daftar member
    admin.showAllMember();

    return 0;
}
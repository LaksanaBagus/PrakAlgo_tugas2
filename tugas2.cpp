#include <iostream>
#include <string>
using namespace std;

struct Pesanan
{
    string nama;
    string jenis;
    int harga;
};

struct Node
{
    Pesanan data;
    Node *next;
};

struct Stack
{
    Pesanan data;
    Stack *next;
};

Node *depan = nullptr;
Node *belakang = nullptr;
Stack *top = nullptr;

bool antrianKosong()
{
    return depan == nullptr;
}

void tambahAntrean()
{
    system("cls");
    Pesanan p;
    cin.ignore();
    cout << "Nama Pelanggan : ";
    getline(cin, p.nama);
    cout << "Jenis Roti     : ";
    getline(cin, p.jenis);
    cout << "Total Harga    : ";
    cin >> p.harga;

    Node *baru = new Node{p, nullptr};
    if (antrianKosong())
    {
        depan = belakang = baru;
    }
    else
    {
        belakang->next = baru;
        belakang = baru;
    }
    cout << "Pesanan berhasil ditambahkan ke antrian" << endl;
}

void tampilAntrean()
{
    system("cls");
    if (antrianKosong())
    {
        cout << "Antrian kosong" << endl;
        return;
    }
    cout << "=== Daftar Antrean ===" << endl;
    Node *temp = depan;
    while (temp != nullptr)
    {
        cout << "Nama: " << temp->data.nama << "  Jenis: " << temp->data.jenis << "  Harga: " << temp->data.harga << endl;
        temp = temp->next;
    }
    cout << endl;
}

void simpanKeRiwayat(Pesanan p)
{
    Stack *baru = new Stack{p, top};
    top = baru;
}

void layaniPembeli()
{
    system("cls");
    if (antrianKosong())
    {
        cout << "Tidak ada pesanan dalam antrean.\n\n";
        return;
    }
    Node *hapus = depan;
    cout << "Melayani: " << hapus->data.nama << "  Jenis Roti: " << hapus->data.jenis << "  Harga: " << hapus->data.harga << endl;
    simpanKeRiwayat(hapus->data);
    depan = depan->next;
    if (depan == nullptr)
        belakang = nullptr;
    delete hapus;
    cout << "Pesanan telah diproses dan disimpan ke riwayat" << endl;
}

void batalkanPesanan()
{
    system("cls");
    if (antrianKosong())
    {
        cout << "Tidak ada pesanan yang bisa dibatalkan" << endl;
        return;
    }
    if (depan == belakang)
    {
        cout << "Membatalkan: " << belakang->data.nama << endl;
        delete belakang;
        depan = belakang = nullptr;
        return;
    }
    Node *temp = depan;
    while (temp->next != belakang)
    {
        temp = temp->next;
    }
    cout << "Membatalkan: " << belakang->data.nama << endl;
    delete belakang;
    belakang = temp;
    belakang->next = nullptr;
    cout << "Pesanan terakhir dibatalkan" << endl;
}

void tampilHistory()
{
    system("cls");
    if (top == nullptr)
    {
        cout << "Belum ada pesanan yang dilayani" << endl;
        return;
    }
    cout << "=== Riwayat Pesanan ===" << endl;
    Stack *temp = top;
    while (temp != nullptr)
    {
        cout << "Nama: " << temp->data.nama << "  Jenis: " << temp->data.jenis << "  Harga: " << temp->data.harga << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    system("cls");
    int pilihan;
    do
    {
        cout << "=== SISTEM ANTRIAN TOKO ROTI MANIS LEZAT ===" << endl;
        cout << "1. Ambil Antrean" << endl;
        cout << "2. Layani Pembeli" << endl;
        cout << "3. Tampilkan Pesanan" << endl;
        cout << "4. Batalkan Pesanan" << endl;
        cout << "5. Tampilkan History Pesanan" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan)
        {
        case 1:
            tambahAntrean();
            break;
        case 2:
            layaniPembeli();
            break;
        case 3:
            tampilAntrean();
            break;
        case 4:
            batalkanPesanan();
            break;
        case 5:
            tampilHistory();
            break;
        case 6:
            cout << "Terima kasih. Program selesai" << endl;
            break;
        default:
            cout << "Pilihan tidak valid";
        }
    } while (pilihan != 6);

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

int menu;

struct pesanan
{
    string nama;
    string jenis;
    int harga;
};

struct Queue
{
    pesanan *pesanan;
    Queue *next;
};

Queue *depan, *belakang;

struct stack
{
    pesanan *pesanan;
    stack *next;
};

void tambahPesanan()
{
    pesanan p;
    cout << "Nama pelanggan : ";
    getline(cin, p.nama);
    cout << "Jenis roti     : ";
    getline(cin, p.jenis);
    cout << "Total harga    : ";
    cin >> p.harga;
}

void buatQueue()
{
    depan = belakang = nullptr;
}

bool queueKosong()
{
    return depan == nullptr;
}

void enqueue(string namaPelanggan, string jenisRoti, int totalHarga)
{
    Queue *baru = new Queue;
    baru->pesanan = new pesanan;
    baru->pesanan->nama = namaPelanggan;
    baru->pesanan->nama = jenisRoti;
    baru->pesanan->nama = totalHarga;
    baru->next = nullptr;
    if (depan == nullptr)
    {
        depan = belakang = baru;
    }
    else
    {
        belakang->next = baru;
        belakang = baru;
    }
}

void dequeue()
{
    if (queueKosong())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        Queue *hapus = depan;
        cout << "===Pesanan yang Dihapus===" << endl
             << hapus->pesanan->nama << "-" << hapus->pesanan->jenis << "-" << hapus->pesanan->harga << endl;
        depan = depan->next;
        delete hapus;
        if (depan == nullptr)
        {
            belakang = nullptr;
        }
    }
}

void tampilQueue()
{
    if (queueKosong())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        Queue *baca = depan;
        cout << "===Isi Antrian===";
        int i;
        while (baca != nullptr)
        {
            cout << baca->pesanan->nama << " " << baca->pesanan->jenis << " " << baca->pesanan->harga << " ";
            i++;
            baca = baca->next;
        }
        cout << endl;
    }
}

int main()
{
    cout << "===Daftar Layanan Toko Roti Manis Lezat===";
    cout << "1. Tambah pesanan";
    cout << "2. Prosen pesanan";
    cout << "3. Batalkan pesanan";
    cout << "4. Tampilkan history pesanan";
    cout << "Pilih menu : ";
    cin >> menu;
    switch (menu)
    {
    case 1:
        tambahPesanan;
    case 2:
        enqueue;
    case 3:
        dequeue;
    case 4:
        tampilQueue;
    }

    return 0;

    // hehe kurang maksimal kak,vscode ku error kalo run code nya:)
}

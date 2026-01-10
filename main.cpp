#include "tubes.h"

int main()
{
    ListOrang L;
    createListOrang(L);

    int pilihan;
    do
    {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Tambah Orang" << endl;
        cout << "2. Tampilkan Daftar Orang" << endl;
        cout << "3. Tambah Belanjaan ke Orang" << endl;
        cout << "4. Tampilkan Belanjaan Orang" << endl;
        cout << "5. Hapus Belanjaan Orang" << endl;
        cout << "6. Hapus Orang" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {

        case 1:
        {
            int id;
            string nama;

            cout << "Masukkan ID Member : ";
            cin >> id;

            if (cekIdMemberOrang(L, id))
            {
                cout << "ID Member sudah digunakan! Gagal menambahkan orang." << endl;
                break;
            }

            cout << "Masukkan Nama      : ";
            cin >> nama;

            adrOrang p = createElelemenOrang(id, nama);
            addOrang(L, p);

            cout << "Orang berhasil ditambahkan." << endl;
            break;
        }

        case 2:
        {
            displayOrang(L);
            break;
        }

        case 3:
        {
            string namaOrang;
            cout << "Masukkan nama orang: ";
            cin >> namaOrang;

            adrOrang p = searchOrang(L, namaOrang);
            if (p == nullptr)
            {
                cout << "Orang tidak ditemukan!" << endl;
            }
            else
            {
                int idBarang;
                string namaBarang, harga;

                cout << "ID Barang   : ";
                cin >> idBarang;
                cout << "Nama Barang : ";
                cin >> namaBarang;
                cout << "Harga       : ";
                cin >> harga;

                adrBelanjaan q = createElemenBelanjaan(idBarang, namaBarang, harga);
                addBelanjaan(p, q);

                cout << "Belanjaan berhasil ditambahkan." << endl;
            }
            break;
        }

        case 4:
        {
            string nama;
            cout << "Masukkan nama orang: ";
            cin >> nama;

            displayList(L, nama);
            break;
        }

        case 5:
        {
            string nama;
            int idBarang;

            cout << "Masukkan nama orang : ";
            cin >> nama;

            adrOrang p = searchOrang(L, nama);
            if (p == nullptr)
            {
                cout << "Orang tidak ditemukan!" << endl;
            }
            else
            {
                cout << "Masukkan ID Barang : ";
                cin >> idBarang;

                deleteBelanjaan(p, idBarang);
            }
            break;
        }

        case 6:
        {
            int idMember;
            cout << "Masukkan ID Member yang akan dihapus: ";
            cin >> idMember;

            deleteOrang(L, idMember);
            break;
        }

        case 0:
            cout << "Terima kasih, program selesai." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 0);

    return 0;
}

#include "tubes.h"

void createListOrang(ListOrang &L)
{
    L.first = nullptr;
}

bool isEmptyOrang(ListOrang L)
{
    return (L.first == nullptr);
}

bool isEmptyBelanjaan(adrOrang p)
{
    if (p == nullptr)
        return true;
    return (p->firstBelanjaan == nullptr);
}

adrOrang createElelemenOrang(int idMember, string nama)
{
    adrOrang p = new elmOrang;
    p->info.idMember = idMember;
    p->info.nama = nama;
    p->next = nullptr;
    p->firstBelanjaan = nullptr;
    return p;
}
bool cekIdMemberOrang(ListOrang L, int idMember)
{
    adrOrang p = L.first;
    while (p != nullptr)
    {
        if (p->info.idMember == idMember)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}
adrBelanjaan createElemenBelanjaan(int idBarang, string nama, string harga)
{
    adrBelanjaan p = new elmBelanjaan;
    p->info.idBarang = idBarang;
    p->info.nama = nama;
    p->info.harga = harga;
    p->next = nullptr;
    return p;
}

void addOrang(ListOrang &L, adrOrang p)
{
    if (L.first == nullptr)
    {
        L.first = p;
    }
    else
    {
        adrOrang s = L.first;
        while (s->next != nullptr)
        {
            s = s->next;
        }
        s->next = p;
    }
}

void addBelanjaan(adrOrang p, adrBelanjaan q)
{
    if (p->firstBelanjaan == nullptr)
    {
        p->firstBelanjaan = q;
    }
    else
    {
        adrBelanjaan t = p->firstBelanjaan;
        while (t->next != nullptr)
        {
            t = t->next;
        }
        t->next = q;
    }
}

adrOrang searchOrang(ListOrang L, string nama)
{
    adrOrang p = L.first;
    while (p != nullptr)
    {
        if (p->info.nama == nama)
        {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void displayList(ListOrang L, string nama)
{
    adrOrang p = searchOrang(L, nama);

    if (p == nullptr)
    {
        cout << "Orang dengan nama " << nama << " tidak ditemukan" << endl;
        return;
    }

    if (p->firstBelanjaan == nullptr)
    {
        cout << nama << " belum memiliki belanjaan" << endl;
        return;
    }

    cout << "Daftar belanjaan milik " << nama << ":" << endl;

    adrBelanjaan q = p->firstBelanjaan;
    while (q != nullptr)
    {
        cout << "idBarang: " << q->info.idBarang << " | "
             << "Nama Barang: " << q->info.nama << " | "
             << "Harga: " << q->info.harga << endl;
        q = q->next;
    }
}
void displayOrang(ListOrang L)
{
    adrOrang p = L.first;
    if (p == nullptr)
    {
        cout << "Belum ada orang!";
    }
    else
    {
        while (p != nullptr)
        {
            cout << "Nama: " << p->info.nama << " | " << "idMember: " << p->info.idMember << endl;
            p = p->next;
        }
    }
}
void deleteBelanjaan(adrOrang p, int idBarang)
{
    if (p == nullptr || p->firstBelanjaan == nullptr)
    {
        cout << "Belanjaan tidak ada" << endl;
        return;
    }

    adrBelanjaan q = p->firstBelanjaan;
    if (q->info.idBarang == idBarang)
    {
        p->firstBelanjaan = q->next;
        delete q;
        cout << "Belanjaan berhasil dihapus" << endl;
        return;
    }

    adrBelanjaan prev = nullptr;
    while (q != nullptr && q->info.idBarang != idBarang)
    {
        prev = q;
        q = q->next;
    }

    if (q == nullptr)
    {
        cout << "Belanjaan dengan id " << idBarang << " tidak ditemukan" << endl;
        return;
    }

    prev->next = q->next;
    delete q;
    cout << "Belanjaan berhasil dihapus" << endl;
}
void deleteOrang(ListOrang &L, int idMember)
{
    if (L.first == nullptr)
    {
        cout << "List orang kosong" << endl;
        return;
    }

    adrOrang p = L.first;
    if (p->info.idMember == idMember)
    {
        L.first = p->next;
        adrBelanjaan q = p->firstBelanjaan;
        while (q != nullptr)
        {
            adrBelanjaan temp = q;
            q = q->next;
            delete temp;
        }

        delete p;
        cout << "Orang berhasil dihapus" << endl;
        return;
    }

    adrOrang prev = nullptr;
    while (p != nullptr && p->info.idMember != idMember)
    {
        prev = p;
        p = p->next;
    }

    if (p == nullptr)
    {
        cout << "Orang dengan id " << idMember << " tidak ditemukan" << endl;
        return;
    }

    prev->next = p->next;
    adrBelanjaan q = p->firstBelanjaan;
    while (q != nullptr)
    {
        adrBelanjaan temp = q;
        q = q->next;
        delete temp;
    }

    delete p;
    cout << "Orang berhasil dihapus" << endl;
}

#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct elmBelanjaan *adrBelanjaan;
typedef struct elmOrang *adrOrang;

struct Orang
{
    int idMember;
    string nama;
};

struct Belanjaan
{
    int idBarang;
    string nama;
    string harga;
};

struct elmOrang
{
    Orang info;
    adrOrang next;
    adrBelanjaan firstBelanjaan;
};
struct elmBelanjaan
{
    Belanjaan info;
    adrBelanjaan next;
};
struct ListOrang
{
    adrOrang first;
};
void createListOrang(ListOrang &L);
bool isEmptyOrang(ListOrang L);
bool isEmptyBelanjaan(adrOrang p);
adrOrang createElelemenOrang(int idMember, string nama);
bool cekIdMemberOrang(ListOrang L, int idMember);
adrBelanjaan createElemenBelanjaan(int idBarang, string nama, string harga);
adrOrang searchOrang(ListOrang L, string nama);
void addOrang(ListOrang &L, adrOrang p);
void addBelanjaan(adrOrang p, adrBelanjaan q);
void displayList(ListOrang L, string nama);
void displayOrang(ListOrang L);
void deleteBelanjaan(adrOrang p, int idBarang);
void deleteOrang(ListOrang &L, int idMember);

#endif // TUBES_H_INCLUDED

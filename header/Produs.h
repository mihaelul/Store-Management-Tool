#ifndef PRODUS_H
#define PRODUS_H
#include<iostream>
#include<string>
#include<time.h>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <stdexcept>

using namespace std;
class Produs
{
protected:
    string denumire;
    int nr_produse;
    double pret_brut;
    double pret;
    static int nextId;
    int id_unic;
public:
    Produs()=default;
    Produs(string , int , double );
    friend istream& operator>>(istream& dev,Produs& p);
    virtual void afisare() const
    {
        cout<<"Denumire: "<<denumire<<endl;
        cout<<"Stoc: "<<nr_produse<<endl;
        cout<<"Id: "<<id_unic<<endl;
        cout<<"Pret brut: "<<pret_brut<<endl;

    }
    virtual void calculPret()
    {
    }

    int get_ID()
    {
        return id_unic;
    }
    double get_pret_brut()
    {
        return pret_brut;
    }

    double get_pret()
    {
        return pret;
    }

    void modificareStoc(int nr)
    {
        nr_produse=nr;

    }

    void scadereStoc(int nr)
    {
        nr_produse=nr_produse-nr;
    }
    bool cautareProdus(string n, int i);

    virtual ~Produs()
    {

    }
    int get_stoc()
    {
        return nr_produse;
    }



};

#endif

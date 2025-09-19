#include "Produs.h"
int Produs::nextId = 100;

Produs::Produs(string d, int nr, double p)
{
    denumire=d;
    nr_produse=nr;
    pret_brut=p;
    id_unic=nextId;
    nextId++;
}

istream& operator>>(istream& dev,Produs& p)
{
    cout<<"Denumire produs: "<<endl;
    dev>>p.denumire;
    cout<<"Numar de produse: "<<endl;
    dev>>p.nr_produse;
    cout<<"Pret: "<<endl;
    dev>>p.pret_brut;

    p.id_unic=p.nextId;
    p.nextId++;

    return dev;
}

bool Produs::cautareProdus(string n, int i)
    {
        //Problema rezolvata: case sensitive
        string copie_Nume=denumire;
        transform(copie_Nume.begin(), copie_Nume.end(), copie_Nume.begin(), ::tolower);


        transform(n.begin(), n.end(), n.begin(), ::tolower);

        if(copie_Nume==n || id_unic==i)
        {
                return 0;
        }

        else
            return 1;


    }


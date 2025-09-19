#include "Produs.h"
#ifndef COMANDA_H
#define COMANDA_H

class Comanda
{
    string nume;
    string nume_album;
    string tip;
    int id;
    int cantitate;
public:

        Comanda()=default;
        Comanda(string n, int i, int c):nume(n),id(i),cantitate(c)
        {}
        friend istream& operator>>(istream& dev,Comanda& c)
        {

            if(c.nume=="CD" || c.nume== "Vinyl")
                {   getline(dev, c.nume_album);
                }
            else
                dev>>c.tip;

            dev>>c.id;
            dev>>c.cantitate;

            return dev;

        }
          void afisare() const {
            cout<<"ID Comanda: "<<id<<endl;
            cout<<"Nume Client: "<<nume<<endl;
            cout<<"Nume Album: "<<nume_album<<endl;
            cout<<"Tip Comanda: "<<tip<<endl;
            cout<<"Cantitate: "<<cantitate<<endl;
                }

        string get_tip()
        {
            return tip;
        }
        string get_nume()
        {
            if(nume=="CD" || nume=="Vinyl")
                return nume_album;
            else
                return nume;
        }
        string get_nume2() //pentru verificarea tipului de produse
        {
            return nume;
        }

        int get_ID()
        {
            return id;
        }

        void setnume(string n)
        {
        nume=n;
        }

        int get_cantitate()
        {
            return cantitate;
        }



};

#endif

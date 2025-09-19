#include <vector>
#include "Comanda.h"
#ifndef GESTIUNECOMANDA_H
#define GESTIUNECOMANDA_H

class vectorComanda {
private:
    vector<std::shared_ptr<Comanda>> comenzi;
    double pret_fara_livrare;
    double pret_total;
    int idcomanda;
    string eroare;
    struct tm data_comanda;

public:

    vectorComanda() : pret_total(0) {}

    void afisare() const {
        cout<<"ID Comanda: "<<idcomanda<<endl;
        cout<<"Pret fara costuri aditionale "<<pret_fara_livrare<<" RON"<<endl;
        cout<<"Pret Total: "<<pret_total<<" RON"<<endl;

        cout<<"Data Comenzii: "
                  <<setfill('0')<<setw(2)<<data_comanda.tm_mday<< "/"
                  <<setfill('0')<<setw(2)<<(data_comanda.tm_mon + 1)<<"/"
                  <<(data_comanda.tm_year + 1900)<<endl;


        cout << "Detalii comenzi:" <<endl;
        for (const auto& comanda : comenzi) {
            comanda->afisare();
        }
    }

    void set_id(int i)
    {
        idcomanda=i;
    }
    int get_ID()
    {
        return idcomanda;
    }

    int verificare_V_D()
    {
        int v=0;
        int d=0;
        for (const auto& comanda : comenzi)
        {
            if(comanda->get_tip()=="Vestimentar")
                v=v+comanda->get_cantitate();

            else if(comanda->get_nume2()=="CD" || comanda->get_nume2()=="Vinyl")
                d=d+comanda->get_cantitate();

        }
        if(v>3 && d>5)
            return 1;
        else
            return 0;

    }

    ~vectorComanda() {
        clear();
    }
    void insert_eroare(string e)
    {
        eroare=e;
    }

    string get_eroare()
    {
        return eroare;
    }


    void adaugaComanda(std::shared_ptr<Comanda> comanda) {
        comenzi.push_back(comanda);
    }

    void set_data()
    {
        time_t now = time(0);
        struct tm *lt = localtime(&now);
        data_comanda=*lt;
    }



    void clear() {
        comenzi.clear();
        pret_fara_livrare=0;
        pret_total=0;
    }


    bool isEmpty() const {
        return comenzi.empty();
    }

    vector<std::shared_ptr<Comanda>>& get_comenzi() {
        return comenzi;
    }

    void calculPretComanda(double p, double pp, int cantitate)
        {
             pret_fara_livrare=pret_fara_livrare+pp*cantitate;
             pret_total=pret_total+p*cantitate;
            //cout<<"Pret total: "<<pret_total<<endl;
        }
    double get_pret()
    {
        return pret_total;
    }
    double get_pret_brut()
    {
        return pret_fara_livrare;
    }
};
#endif

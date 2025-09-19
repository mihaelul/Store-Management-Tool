#include "Produs.h"

class Disc : public Produs
{
protected:
    string casa_discuri;
    struct tm data_vanzare;
    string trupa;
    string album;
public:
    Disc()
    {

    }
    Disc(string d, int nr, double p, string cd, struct tm dv, string t, string a):Produs(d,nr,p)
    {
        casa_discuri=cd;
        data_vanzare=dv;
        trupa=t;
        album=a;
        calculPret();
    }
    void calculPret() override
    {
        pret=pret_brut;
        pret=pret+5;
    }

    void afisare() const override
    {
        Produs::afisare();
        cout<<"Pret+costuri livrare: "<<pret<<endl;
        cout<<"Casa discuri: "<<casa_discuri<<endl;
        cout << "Data Vanzarii: "
             << setfill('0') << setw(2) << data_vanzare.tm_mday << "/"
             << setfill('0') << setw(2) << (data_vanzare.tm_mon + 1) << "/"
             << data_vanzare.tm_year + 1900 << endl;
        cout<<"Trupa: "<<trupa<<endl;
        cout<<"Album: "<<album<<endl;
    }
    friend istream& operator>>(istream& dev,Disc& d)
    {

        dev >> static_cast<Produs&>(d);

        cout << "Casa discuri: ";
        dev >> d.casa_discuri;

        cout << "Data vanzare: ";
        int zi, luna, an;
        dev >> zi >> luna >> an;
        d.data_vanzare.tm_mday = zi;
        d.data_vanzare.tm_mon = luna - 1;
        d.data_vanzare.tm_year = an - 1900;

        cout << "Trupa: ";
        dev >> d.trupa;

        cout << "Album: ";
        dev >> d.album;
        d.calculPret();

        return dev;
    }

};

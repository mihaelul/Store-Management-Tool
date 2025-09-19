#include "Produs.h"

class DV: public Disc
{
    bool mint;
    int raritate;
public:

    DV()
    {

    }
    DV(string d, int nr, double p, string cd, struct tm dv, string t, string a, bool m, int r):Disc(d,nr,p,cd,dv,t,a)
    {
        mint=m;
        raritate=r;
        calculPret();
    }
    void calculPret() override
    {
        Disc::calculPret();
        pret=pret+15*raritate;
    }
    void afisare() const override
    {
        Produs::afisare();
        cout<<"Pret+costuri livrare: "<<pret-15*raritate<<endl;
        cout<<"Pret total: "<<pret<<endl;
        if(mint==0)
            cout<<"Are mint"<<endl;
        else
            cout<<"Nu are mint"<<endl;

        cout<<"Raritate de la 1 la 5: "<<raritate<<endl;

    }
    friend istream& operator>>(istream& dev, DV& dv)
     {
         dev>>static_cast<Disc&>(dv);
         cout<<"Are mint? 0-da 1-nu: "<<endl;
         dev>>dv.mint;
         cout<<"Raritate: "<<endl;
         dev>>dv.raritate;
         dv.calculPret();

         return dev;
     }



};

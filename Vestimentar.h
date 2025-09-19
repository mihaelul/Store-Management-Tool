#include "Produs.h"

class AV : public Produs//articol vestimentar
{
    string culoare;
    string marca;
public:

    AV()
    {
        calculPret();
    }
    AV(string d, int nr, double p, string c, string m):Produs(d,nr,p)
    {
        culoare=c;
        marca=m;
        calculPret();
    }
    void calculPret() override
    {
        pret=pret_brut;
        pret=pret+20;
    }
    void afisare() const override
    {
        Produs::afisare();
        cout<<"Pret+costuri livrare: "<<pret<<endl;
        cout<<"Culoare: "<<culoare<<endl;
        cout<<"Marca: "<<marca<<endl;
    }
     friend istream& operator>>(istream& dev, AV& av)
     {
         dev>>static_cast<Produs&>(av);
         cout<<"Culoare: "<<endl;
         dev>>av.culoare;
         cout<<"Marca: "<<endl;
         dev>>av.marca;
         av.calculPret();

         return dev;
     }

};

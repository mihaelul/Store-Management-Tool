#include "Angajat.h"

class Manager: public Angajat
{
public:

    void calculSalariu() override
    {
        //Angajat::calculSalariu();
        salariu=salariu*1.25;
    }
     Manager(string n, string p, string c, struct tm dataAngajare):Angajat(n,p,c,dataAngajare)
     {
         calculSalariu();

     }
};

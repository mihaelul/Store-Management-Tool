#include "Angajat.h"

class Asistent: public Angajat
{
public:

    void calculSalariu() override
    {
        //Angajat::calculSalariu();
        salariu=salariu*0.75;
        time_t now = time(0);
        struct tm *lt = localtime(&now);
        int lunaCurent=lt->tm_mon;
        int ziCurent=lt->tm_mday;
        if(data_nastere.tm_mon==lunaCurent && data_nastere.tm_mday==ziCurent)
            salariu=salariu+100;
    }
    Asistent(string n, string p, string c, struct tm dataAngajare):Angajat(n,p,c,dataAngajare)
     {
         calculSalariu();
     }

     Asistent()
     {
         id = nextid++;
     }
};

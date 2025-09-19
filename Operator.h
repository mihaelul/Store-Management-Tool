#include "Angajat.h"
#include <thread>
#include <chrono>
#include <memory>
#include "Gestiunecomanda.h"

class Operator: public Angajat
{
    bool status=0;
    int nr_comenzi_active = 0;
    int nr_comenzi=0;
    double valoare_comenzi=0.0;

public:

    Operator()
    {
        id = nextid++;
    }
    Operator(string n, string p, string c, struct tm dataAngajare, bool s):Angajat(n,p,c,dataAngajare)
     {
         status=s;
         calculSalariu();
     }

     void afisare() const override
    {
        Angajat::afisare();
        cout<<"Total de comenzi procesate: "<<nr_comenzi<<endl;
        cout<<"Bonus: "<<valoare_comenzi<<endl;
    }

    void calculSalariu() override
    {
        //Angajat::calculSalariu();
        time_t now = time(0);
        struct tm *lt = localtime(&now);
        int lunaCurent=lt->tm_mon;
        int ziCurent=lt->tm_mday;
        if(data_nastere.tm_mon==lunaCurent && data_nastere.tm_mday==ziCurent)
            salariu=salariu+100;
    }
    void adaugareComanda(int p)
    {
        salariu=salariu+(5/1000)*salariu;
    }
    bool verificareStatus()
    {
        if(status==0)
            return 0;
        else
            return 1;

    }
    int get_nr_comenzi() const
    {
        return nr_comenzi;
    }

    double get_valoare_comenzi() const
    {
       return valoare_comenzi;
    }

void realizareComanda(vectorComanda& comandaPrimita)
{
    if (nr_comenzi_active >= 3)
    {
        cout << "Operatorul " << Nume << " " << Prenume << " are deja 3 comenzi active.\n";
        return;
    }

    nr_comenzi_active++;
    status = nr_comenzi_active >= 3;
    cout << "Operatorul " << Nume << " " << Prenume << " a preluat o comanda cu id " << comandaPrimita.get_ID() << ".\n";
    valoare_comenzi += comandaPrimita.get_pret()*0.005;
    salariu+= comandaPrimita.get_pret()*0.005;
    nr_comenzi++;

    auto comandaPtr = make_shared<vectorComanda>(comandaPrimita);

    thread([this,comandaPtr]() {

    this_thread::sleep_for(chrono::seconds(3));
        status = 0;
        nr_comenzi_active--;
        cout << "Comanda cu id-ul "<<comandaPtr->get_ID()<<" a fost finalizata.\n";
    }).detach();
}
};

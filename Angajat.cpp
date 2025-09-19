#include "Angajat.h"
int Angajat::nextid = 1;

Angajat::Angajat(string N, string P, string C,struct tm dataAngajare)
{
    //exceptii la nume, prenume si cnp
    if(N.length()<3 || N.length()>30)
        throw invalid_argument("Numele trebuia sa fie intre 3 si 20");
    if(P.length()<3 || P.length()>30)
        throw invalid_argument("Prenumele trebuia sa fie intre 3 si 20");
    Nume=N;
    Prenume=P;

    if(C.length()!=13)
        throw invalid_argument("CNP Invalid, dimensiune incorecta");
    int sex = C[0] - '0';
    int secol = 0;

    //timp

    if (sex == 1 || sex == 2)
    {
        secol = 1900;
    }
    else if (sex == 5 || sex == 6)
    {
        secol = 2000;
    }
    else
    {
        throw invalid_argument("CNP invalid");
    }
    if(secol==2000)
    {
        if(stoi(C.substr(1, 2))>7)
            throw invalid_argument("Angajatul trebuie sa fie major");
    }

    data_nastere.tm_year = secol + stoi(C.substr(1, 2))-1900;
    data_nastere.tm_mon = stoi(C.substr(3, 2))-1;
    data_nastere.tm_mday = stoi(C.substr(5, 2));


     if (data_nastere.tm_mon < 0 || data_nastere.tm_mon > 11 ||
        data_nastere.tm_mday < 1 || data_nastere.tm_mday > 31)
            {
                throw invalid_argument("Data extrasa din CNP este invalida.");
            }
        CNP=C;
        data_angajarii=dataAngajare;
        salariu=3500;
        calculSalariu(); //depinde de ce angajat e/daca e ziua lui
        id=nextid;
        nextid++;

}
istream& operator>>(istream& dev, Angajat& a)
{
    cout<<"Introduceti numele: "<<endl;
    dev>>a.Nume;
    if(a.Nume.length()<3 || a.Nume.length()>30)
        throw std::invalid_argument("Numele trebuia sa fie intre 3 si 20");

    cout<<"Introduceti prenumele: "<<endl;
    dev>>a.Prenume;
    if(a.Prenume.length()<3 || a.Prenume.length()>30)
        throw std::invalid_argument("Prenumele trebuia sa fie intre 3 si 20");

    cout<<"Introduceti CNP: "<<endl;
    dev>>a.CNP;
    if(a.CNP.length()!=13)
        throw std::invalid_argument("CNP Invalid, dimensiune incorecta");
    int sex = a.CNP[0] - '0';
    int secol = 0;

    //timp

    if (sex == 1 || sex == 2)
    {
        secol = 1900;
    }
    else if (sex == 5 || sex == 6)
    {
        secol = 2000;
    }
    else
    {
        throw invalid_argument("CNP invalid");
    }
    if(secol==2000)
    {
        if(stoi(a.CNP.substr(1, 2))>7)
            throw invalid_argument("Angajatul trebuie sa fie major");
    }


    a.data_nastere.tm_year = secol + stoi(a.CNP.substr(1, 2))-1900;
    a.data_nastere.tm_mon = stoi(a.CNP.substr(3, 2))-1;
    a.data_nastere.tm_mday = stoi(a.CNP.substr(5, 2));

     if (a.data_nastere.tm_mon < 0 || a.data_nastere.tm_mon > 11 ||
        a.data_nastere.tm_mday < 1 || a.data_nastere.tm_mday > 31)
        {
        throw invalid_argument("Data extrasa din CNP este invalida.");
        }
        time_t now = time(0);
        struct tm *lt = localtime(&now);
        a.data_angajarii=*lt;
        a.salariu=3500;
        a.calculSalariu();
    return dev;

}
void Angajat::schimbareNume(string n)
{
    Nume=n;
}

bool Angajat::cautareAngajat(string n, string p)
    {
        //Problema rezolvata: case sensitive
        string copie_Nume=Nume;
        string copie_Prenume=Prenume;
        transform(copie_Nume.begin(), copie_Nume.end(), copie_Nume.begin(), ::tolower);
        transform(copie_Prenume.begin(), copie_Prenume.end(), copie_Prenume.begin(), ::tolower);


        transform(n.begin(), n.end(), n.begin(), ::tolower);
        transform(p.begin(), p.end(), p.begin(), ::tolower);



        if(copie_Nume==n && copie_Prenume==p)
            return 0;
        else
            {
                return 1;
            }

    }


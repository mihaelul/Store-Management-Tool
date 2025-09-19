#ifndef ANGAJAT_H
#define ANGAJAT_H
#include<iostream>
#include<string>
#include<time.h>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <stdexcept>

using namespace std;

class Angajat
{
protected:
    string Nume;
    string Prenume;
    string CNP;
    int salariu;
    static int nextid;
    int id;
    struct tm data_nastere;
    struct tm data_angajarii;

public:
    Angajat()
    {
    }
    Angajat(string , string , string , struct tm dataAngajare);
    friend istream& operator>>(istream& dev, Angajat& a);
    virtual void afisare() const
    {
        cout<<"Nume: "<<Nume<<endl;
        cout<<"Prenume: "<<Prenume<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"CNP: "<<CNP<<endl;
        cout << "Data nasterii: "
             << setfill('0') << setw(2) << data_nastere.tm_mday << "/"
             << setfill('0') << setw(2) << (data_nastere.tm_mon + 1) << "/"
             << data_nastere.tm_year + 1900 << endl;
         cout << "Data angajarii: "
             << setfill('0') << setw(2) << data_angajarii.tm_mday << "/"
             << setfill('0') << setw(2) << (data_angajarii.tm_mon + 1) << "/"
             << data_angajarii.tm_year + 1900 << endl;
        cout<<"Salariu: "<<salariu<<endl;
    }
    void schimbareNume(string n);

    string get_nume() const
    {
        return Nume;
    }

    string get_prenume() const
    {
        return Prenume;
    }

     string get_nume_complet()
    {
        return Nume+" "+Prenume;
    }

    virtual void calculSalariu()
    {
        time_t now = time(0);
        struct tm *ltm = localtime(&now);
        int anCurent =ltm->tm_year;
        int diferenta=anCurent-data_angajarii.tm_year;
        salariu=salariu+100*diferenta; //calcul dupa vechime

    }
    double getSalariu() const
    {
        return salariu;
    }

    bool cautareAngajat(string , string );

    virtual ~Angajat(){};
};
#endif

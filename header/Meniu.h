#include"Manager.h"
#include"Operator.h"
#include"Asistent.h"

#include"Produs.h"
#include "Vestimentar.h"
#include "Disc.h"
#include "vintage.h"


#include "Gestiunecomanda.h"

#include<vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>

class Meniu
{

public:

    //angajati
    static void adaugareAngajat(vector<Angajat*>& angajati);
    //verificare angajati
    static int verificareAngajati(vector<Angajat*>& angajati);
    static void stergereAngajat(vector<Angajat*>& angajati);
    static void modificareAngajat(vector<Angajat*>& angajati);
    static void cautareAngajat(vector<Angajat*>& angajati);
    static void afisareAngajati(vector<Angajat*>& angajati);

    static void gestiuneAngajati(vector<Angajat*>& angajati);

    //produse

    static void adaugareProdus(vector<Produs*>& produse);
    static int verificareProdus(vector<Produs*>& produse);
    static void stergereProdus(vector<Produs*>& produse);
    static void modificareProdus(vector<Produs*>& produse);

    static void afisareProdus(vector<Produs*>& produse);
    static void afisareProduse(vector<Produs*>& produse);
    static int cautare(vector<Produs*>& produse, std::shared_ptr<Comanda> c, vectorComanda& comanda_curenta);

    static void gestiuneProduse(vector<Produs*>& produse);

    //static void citireComenzi(queue<Comanda*>& comenzi, string n);
    static int verificareComanda(vectorComanda& comanda_curenta, vector<Produs*>& produse);
    static void apelareOperator(vector<Angajat*>& angajati, vectorComanda& comanda_curenta);
    static void gestiuneComenzi(vector<Produs*>& produse, vector<Angajat*>& angajati, string n);
    static vector<Operator*> extragereOp(vector<Angajat*>& angajati);
    static void Raportare(vector<Angajat*>& angajati);


    static void meniu(vector<Angajat*>& angajati, vector<Produs*>& produse, string n);
};




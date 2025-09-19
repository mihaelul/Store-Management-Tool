#include "Meniu.h"

void Meniu::adaugareAngajat(vector<Angajat*>& angajati)
{
    cout<<"Ce fel de angajat doriti sa angajati?"<<endl;
    cout<<"-Operator comenzi(0) "<<endl;
    cout<<"-Asistent(1) "<<endl;
    int optiune=-1;
    while(optiune<0 || optiune>1)
    {
        cout<<"Optiunea dumneavoastra: "<<endl;
        cin>>optiune;
    }
    switch(optiune)
    {
    case 0:
    {
        auto* aux = new Operator();
        try
        {
            cin>>(*aux);
            angajati.push_back(aux);
            cout<<"Operator adaugat cu succes! "<<endl;
        }
        catch (const exception& e)
        {
            cout<<e.what()<<endl;
            delete aux;
        }
        break;
    }

    case 1:
    {
        auto* aux = new Asistent();
        try
        {
            cin>>(*aux);
            angajati.push_back(aux);
            cout<<"Asistent adaugat cu succes! "<<endl;
        }
        catch (const exception& e)
        {
            cout<<e.what()<<endl;
            delete aux;
        }
        break;
    }
    }
}
int Meniu::verificareAngajati(vector<Angajat*>& angajati)
{
    int numar_manageri = 0;
    int numar_operatori = 0;
    int numar_asistenti = 0;

    for (auto it = angajati.begin(); it != angajati.end(); ++it)
    {
        if(dynamic_cast<Manager*>(*it)) {
            numar_manageri++;
        } else if(dynamic_cast<Operator*>(*it)) {
            numar_operatori++;
        } else if(dynamic_cast<Asistent*>(*it)) {
            numar_asistenti++;
        }
    }

    if(numar_manageri<1)
    {
        cout<<"Magazinul are nevoie de minim un manager!"<<endl;
        return 1;
    }
    else if(numar_operatori<3)
    {
        cout<<"Magazinul are nevoie de minim trei operatori!"<<endl;
        return 1;
    }
    else if(numar_asistenti<1)
    {
        cout<<"Magazinul are nevoie de minim un asistent!"<<endl;
        return 1;
    }
    else
        return 0;


}
void Meniu::stergereAngajat(vector<Angajat*>& angajati)
{
    cout<<"Numele angajatului: "<<endl;
    string numeaux;
    cin>>numeaux;

    cout<<"Prenumele angajatului: "<<endl;
    string prenumeaux;
    cin>>prenumeaux;

    vector<Angajat*>::iterator it;
    for (it = angajati.begin(); it != angajati.end();)
    {
        bool cor;
        cor=(*it)->cautareAngajat(numeaux, prenumeaux);
        if(cor==0)
        {
            cout<<"Angajat gasit!"<<endl;
            Angajat* angajat_backup = *it;
            it = angajati.erase(it);
            if(verificareAngajati(angajati) == 0) //verificare daca dupa stergere, se incalca limita de angajat
            {
                cout<<"Angajat sters cu succes!"<<endl;
                break;
            }
            else
            {
                angajati.insert(it, angajat_backup); //daca nu, e bagat inapoi
                break;
            }
        }
        else
        {
            ++it; //se trece la urmatorul
        }
    }

    if (it==angajati.end())
    {
        cout<<"Angajatul nu a fost gasit!"<<endl;
    }
}


void Meniu::modificareAngajat(vector<Angajat*>& angajati)
{
    cout<<"Numele angajatului: "<<endl;
    string numeaux;
    cin>>numeaux;

    cout<<"Prenumele angajatului: "<<endl;
    string prenumeaux;
    cin>>prenumeaux;
    vector<Angajat*>::iterator it;
    for(it=angajati.begin(); it!=angajati.end(); it++)
    {
        bool cor;
        cor=(*it)->cautareAngajat(numeaux,prenumeaux);
        if(cor==0)
        {
            cout<<"Angajat gasit!"<<endl;
            cout<<"Introduceti numele pe care vreti sa-l schimbati"<<endl;
            cin>>numeaux;
            (*it)->schimbareNume(numeaux);
            cout<<"Informatiile actualizate"<<endl;
            (*it)->afisare();
            break;
        }
    }
}

void Meniu::cautareAngajat(vector<Angajat*>& angajati)
{
    cout<<"Numele angajatului: "<<endl;
    string numeaux;
    cin>>numeaux;

    cout<<"Prenumele angajatului: "<<endl;
    string prenumeaux;
    cin>>prenumeaux;
    vector<Angajat*>::iterator it;
    bool cor;
    for(it=angajati.begin(); it!=angajati.end(); it++)
    {
        cor=(*it)->cautareAngajat(numeaux,prenumeaux);
        if(cor==0)
        {
            cout<<"Angajat gasit!"<<endl;
            (*it)->afisare();
            break;
        }

    }
    if(cor==1)
         cout<<"Angajatul nu a fost gasit!"<<endl;
}


void Meniu::afisareAngajati(vector<Angajat*>& angajati)
{
    vector<Angajat*>::iterator it;
    for(it=angajati.begin(); it!=angajati.end(); it++)
    {
        (*it)->afisare();
    }

}

void Meniu::gestiuneAngajati(vector<Angajat*>& angajati)
{
    cout<<"Alegeti ce actiune doriti sa efectuati: "<<endl;
    cout<<"-Adaugare angajat(0) "<<endl;
    cout<<"-Stergere angajat(1) "<<endl;
    cout<<"-Modificare date angajat(2) "<<endl;
    cout<<"-Cautare angajat(3) "<<endl;
    cout<<"-Afisare toti angajatii(4) "<<endl;
    int optiune=-1;
    while(optiune<0 || optiune>5)
    {
        cout<<"Optiunea dumneavoastra: "<<endl;
        cin>>optiune;
    }

    switch(optiune)
    {
    case 0:
        adaugareAngajat(angajati);
        break;

    case 1:
        stergereAngajat(angajati);
        break;

    case 2:
        modificareAngajat(angajati);
        break;

    case 3:
        cautareAngajat(angajati);
        break;

    case 4:
        afisareAngajati(angajati);
        break;
    }

}

void Meniu::adaugareProdus(vector<Produs*>& produse)
{
    cout<<"Ce produs doriti sa adaugati?"<<endl;
    cout<<"-Articol vestimentar(0) "<<endl;
    cout<<"-CD/Vinyl(1) "<<endl;
    cout<<"-Disc Vintage(2) "<<endl;
    int optiune=-1;
    while(optiune<0 || optiune>2)
    {
        cout<<"Optiunea dumneavoastra: "<<endl;
        cin>>optiune;
    }

    switch(optiune)
    {
    case 0:
    {
        auto* aux = new AV();
        try
        {
            cin>>(*aux);
            produse.push_back(aux);
            cout<<"Articol vestimentar adaugat cu succes! "<<endl;
        }
        catch (const exception& e)
        {
            cout<<e.what()<<endl;
            delete aux;
        }
        break;
    }

    case 1:
    {
        auto* aux = new Disc();
        try
        {
            cin>>*aux;
            produse.push_back(aux);
            cout<<"Disc adaugat cu succes! "<<endl;
        }
        catch (const exception& e)
        {
            cout<<e.what()<<endl;
            delete aux;
        }

        break;
    }
        case 2:
    {
        auto* aux = new DV();
        try
        {
            cin>>*aux;
            produse.push_back(aux);
            cout<<"Disc vintage adaugat cu succes! "<<endl;
        }
        catch (const exception& e)
        {
            cout<<e.what()<<endl;
            delete aux;
        }

        break;
    }
    }
}

int Meniu::verificareProdus(vector<Produs*>& produse)
{
    int numar_vestimentare = 0;
    int numar_discuri = 0;

    for(auto it = produse.begin(); it != produse.end(); ++it)
    {
        if (dynamic_cast<AV*>(*it)) {
            numar_vestimentare++;
        } else if (dynamic_cast<Disc*>(*it)) {
            numar_discuri++;
        }
    }

    if(numar_vestimentare<2)
    {
        cout<<"Magazinul are nevoie de minim doua articole vestimentare!"<<endl;
        return 1;
    }
    else if(numar_discuri<2)
    {
        cout<<"Magazinul are nevoie de minim doua discuri/vinyluri!"<<endl;
        return 1;
    }
    else
        return 0;


}
void Meniu::stergereProdus(vector<Produs*>& produse)
{
    //numarare, daca sunt cate 2 AV, disc, DV
        cout<<"Numele produsului: "<<endl;
        string numeaux;
        getline(cin, numeaux); //daca am si spatii, imi citeste toata linia
        cout<<"ID: "<<endl;
        int i;
        cin>>i;

        vector<Produs*>::iterator it;
        bool cor;
        for(it=produse.begin(); it!=produse.end(); it++)
        {
            cor=(*it)->cautareProdus(numeaux,i);
            if(cor==0)
            {
                 cout<<"Produs gasit!"<<endl;
                 Produs* produs_backup = *it;
                 it = produse.erase(it);
                 if (verificareProdus(produse) == 0)
                {
                cout<<"Produs sters cu succes!"<<endl;
                break;
                }
                    else
                    {
                    produse.insert(it, produs_backup);
                    break;
                    }
        }
        else
        {
            ++it;
        }
        }

        if(cor==1)
             cout<<"Produsul nu a fost gasit!"<<endl;
}

void Meniu::modificareProdus(vector<Produs*>& produse)
{
    cout<<"Numele produsului: "<<endl;
    string numeaux;
    cin>>numeaux;
    int i;
    cin>>i;


    vector<Produs*>::iterator it;
    for(it=produse.begin(); it!=produse.end(); it++)
    {
        bool cor;
        cor=(*it)->cautareProdus(numeaux,i);
        if(cor==0)
        {
            cout<<"Produs gasit!"<<endl;
            cout<<"Introduceti ce stoc vreti sa introduceti"<<endl;
            int stoc;
            cin>>stoc;
            (*it)->modificareStoc(stoc);
            cout<<"Informatiile actualizate"<<endl;
            (*it)->afisare();
            break;
        }
    }
}



int Meniu::cautare(vector<Produs*>& produse, shared_ptr<Comanda> c, vectorComanda& comanda_curenta) //trimit direct obiectul din comanda, ca sa-i caulculez pretul
{

    vector<Produs*>::iterator it;
    bool cor=-1;
    string n=c->get_nume();
    int i=c->get_ID();
    int cant=c->get_cantitate();
    for(it=produse.begin(); it!=produse.end(); it++)
    {
        cor=(*it)->cautareProdus(n,i);
        if(cor==0)
        {
            //verificare stoc
            if(cant>(*it)->get_stoc())
            {
                 stringstream ss;
                 ss<<"Produsul "<<n<<" nu mai este in stoc";
                 comanda_curenta.insert_eroare(ss.str());
                return 1;
                break;
            }
            else
            {
                    (*it)->scadereStoc(cant);
            }

            //verificare daca sunt <3 vestimentare si < 5 discuri


            comanda_curenta.calculPretComanda((*it)->get_pret(), (*it)->get_pret_brut(),cant); //cu tot cu consturi de livrare

            return 0;
            break;
        }

    }
            if(cor==1)
            {
                 stringstream ss;
                 ss<<"Produsul "<<n<<" nu a fost gasit";
                 comanda_curenta.insert_eroare(ss.str());

                    return 1;
            }

}


void Meniu::afisareProdus(vector<Produs*>& produse)
{
    cout<<"Numele produsului: "<<endl;
    string numeaux;
    cin>>numeaux;

    cout<<"ID produsului: "<<endl;
    int i;
    cin>>i;


    vector<Produs*>::iterator it;
    for(it=produse.begin(); it!=produse.end(); it++)
    {
        bool cor;
        cor=(*it)->cautareProdus(numeaux,i);
        if(cor==0)
        {
            cout<<"Produs gasit!"<<endl;
            (*it)->afisare();
            break;
        }
    }
}

void Meniu::afisareProduse(vector<Produs*>& produse)
{
    vector<Produs*>::iterator it;
    for(it=produse.begin(); it!=produse.end(); it++)
    {
        (*it)->afisare();
    }

}

void Meniu::gestiuneProduse(vector<Produs*>& produse)
{
    cout<<"Alegeti ce actiune doriti sa efectuati: "<<endl;
    cout<<"-Adaugare produs(0) "<<endl;
    cout<<"-Stergere produs(1) "<<endl;
    cout<<"-Modificare stoc produs(2) "<<endl;
    cout<<"-Afisare produs(3) "<<endl;
    cout<<"-Afisarea tuturor produselor(4) "<<endl;
    int optiune=-1;
    while(optiune<0 || optiune>5)
    {
        cout<<"Optiunea dumneavoastra: "<<endl;
        cin>>optiune;
        cin.ignore();
    }

    switch(optiune)
    {
    case 0:
        adaugareProdus(produse);
        break;

    case 1:
         stergereProdus(produse);
        break;

    case 2:
         modificareProdus(produse);
        break;

    case 3:
         afisareProdus(produse);
        break;

    case 4:
        afisareProduse(produse);
        break;
    }
}



int Meniu::verificareComanda(vectorComanda& comanda_curenta, vector<Produs*>& produse)
{
    //cautare prima comanda dupa nume/ id
    vector<Produs*>::iterator it2;
    vector<shared_ptr<Comanda>>& comanda = comanda_curenta.get_comenzi();
    vector<shared_ptr<Comanda>>::iterator it; //iau vectorul cu produse
        int test1=0;
    //verificare daca se depasete limtia
    if(comanda_curenta.verificare_V_D()==1)
    {
        comanda_curenta.insert_eroare("Comanda trece de limita de 3 vestimentare si 5 discuri");
        return 1;

    }
    for(it=comanda.begin(); it!=comanda.end(); it++)
    {
        string numeaux=(*it)->get_nume();
        test1=cautare(produse,*it,comanda_curenta); //test 1: exista sau nu: cautare dupa id si nume, verificare stoc, verificare limita

        if(test1==1)
            break;

    }

    //se verifica: comanda>100 lei
    if(test1==0)
    {
        if(comanda_curenta.get_pret_brut()<100)
            {
                comanda_curenta.insert_eroare("Nu trece de 100 de lei");
                return 1;
            }
        else
            return 0;
    }

    if(test1==0)
        return 0;
    else
        return 1;

}

vector<Operator*> Meniu::extragereOp(vector<Angajat*>& angajati)
{
        vector<Operator*> operatori;
        for (auto& angajat : angajati)
        {
            Operator* op = dynamic_cast<Operator*>(angajat);
            if (op != nullptr)
            {
                operatori.push_back(op);
            }
        }

            return operatori;

}

void Meniu::apelareOperator(vector<Angajat*>& angajati, vectorComanda& comanda_curenta)
{
    static size_t index = 0;
    vector<Operator*> operatori = extragereOp(angajati);

    while (true)
    {
        bool toti_ocupati = true;

        for (size_t i = 0; i < operatori.size(); ++i)
        {
            size_t currentIndex = (index + i) % operatori.size();
            auto& op = operatori[currentIndex];

            if (!op->verificareStatus())
            {
                op->realizareComanda(comanda_curenta);
                index = (currentIndex + 1) % operatori.size();
                return;
            }
        }

        if (toti_ocupati)
        {
            cout << "Toti operatorii sunt ocupati. Astept 5 secunde...\n";
            this_thread::sleep_for(chrono::seconds(5));
        }
    }
}
void Meniu::gestiuneComenzi(vector<Produs*>& produse, vector<Angajat*>& angajati, string n)
{
    ifstream file(n);
    if (!file)
    {
        cerr << "Nu s-a putut deschide fisierul: " << n << endl;
        return;
    }

    vectorComanda comandaCurenta;
    string linie;
    int valid=-1;
    int id=300;

    while (getline(file, linie))
    {
        if (linie.empty()) // Finalul unei comenzi
        {
            valid=verificareComanda(comandaCurenta, produse);
            id++;
            if(valid==0)
           {
            cout << "Comanda cu id-ul "<<id<<" procesata!" << endl;
            comandaCurenta.set_id(id);
            comandaCurenta.set_data();
            /*cout<<"Detaliile comenzii"<<endl;
            comandaCurenta.afisare();*/
            apelareOperator(angajati, comandaCurenta);
           }
           else
             {
                 cout<<"Comanda cu id-ul "<<id<<" nu a putut fi procesata!"<<endl;
                 //print eroare
                 cout<<"Cauza: "<<comandaCurenta.get_eroare()<<endl;
             }

            comandaCurenta.clear();
            continue;
        }

        auto c = make_shared<Comanda>();
        c->setnume(linie);
        if (!(file >> *c)) {
        cerr << "Eroare la citirea comenzii. Verificati formatul fisierului.\n";
        return;
        }
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        comandaCurenta.adaugaComanda(c);
    }

    if (!comandaCurenta.isEmpty())
    {
        verificareComanda(comandaCurenta, produse);
        cout<<"Comanda finalizata!"<<endl;
        comandaCurenta.clear();
    }

}

void Meniu::Raportare(vector<Angajat*>& angajati)
{
    vector<Operator*> operatori=extragereOp(angajati);

    //sort dupa nr de comenzi
    sort(operatori.begin(), operatori.end(),
          [](const Operator* a, const Operator* b) {
              return a->get_nr_comenzi() > b->get_nr_comenzi();
          });

        ofstream fisierNrComenzi("raport_nr_comenzi.csv");
        fisierNrComenzi<<"Angajatul cu numarul de comenzi ce mai mare\n";
        fisierNrComenzi<<"Nume,numarul de comenzi,salariu\n";
        int count = 0;
        for (const auto& op : operatori) {
            if (count >= 1) break;
            fisierNrComenzi<<op->get_nume_complet()<<","
                            <<op->get_nr_comenzi()<< ","
                            <<op->getSalariu()<<"\n";
            count++;
                            }
            fisierNrComenzi<<"\n";

    //sort dupa bonusuri
    sort(operatori.begin(), operatori.end(),
          [](const Operator* a, const Operator* b) {
              return a->get_valoare_comenzi() > b->get_valoare_comenzi();
          });
          //scriere in csv
          count=0;
          fisierNrComenzi<<"TOP valoare comenzi\n";
          fisierNrComenzi<<"Nume,bonus,salariu\n";
        for (const auto& op : operatori) {
            if (count >= 3) break;
            fisierNrComenzi<<op->get_nume_complet()<<","
                            <<op->get_valoare_comenzi()<<","
                            <<op->getSalariu()<<"\n";
            count++;
                            }

        fisierNrComenzi<<"\n";

    //sort dupa salariu
    sort(angajati.begin(), angajati.end(),
     [](const Angajat* a, const Angajat* b) {
         if(a->getSalariu()!=b->getSalariu()) {
             return a->getSalariu() > b->getSalariu();
         }
         if(a->get_nume()!=b->get_nume()) {
             return a->get_nume() < b->get_nume();
         }
         return a->get_prenume()<b->get_prenume();
     });

          //scriere in csv
        count = 0;
        fisierNrComenzi<<"TOP salariu\n";
        fisierNrComenzi<<"Nume,salariu\n";
        for (const auto& angajat : angajati)
            {
            if (count >= 3) break;
            fisierNrComenzi<<angajat->get_nume_complet()<< ","
                            <<angajat->getSalariu() << "\n";
            count++;
            }
}
void Meniu::meniu(vector<Angajat*>& angajati, vector<Produs*>& produse, string n)
{
    cout<<"Compania X, alegeti ce actiune doriti sa efectuati:"<<endl;
    cout<<"-Gestiune angajati (0)"<<endl;
    cout<<"-Gestiune stoc (1)"<<endl;
    cout<<"-Procesare comenzi (2)"<<endl;
    cout<<"-Raportare (3)"<<endl;

    int optiune;
    while(optiune<0 || optiune>4)
    {
        cout<<"Optiunea dumneavoastra: "<<endl;
        cin>>optiune;
    }

    switch(optiune)
    {
    case 0:
        gestiuneAngajati(angajati);
        break;

    case 1:
        gestiuneProduse(produse);
        break;

    case 2:
        gestiuneComenzi(produse, angajati, n);
        break;

    case 3:
        Raportare(angajati);
        break;
    }

    cout << "Doriti sa faceti alta operatie? (0 pentru Da, orice altceva pentru Nu)" << endl;
    cin>>optiune;
    optiune=0;
    if(optiune==0)
        meniu(angajati,produse,n);

}

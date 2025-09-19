#include "Meniu.h"

struct tm parseDate(const string& dateStr)
{
    struct tm date = {};
    istringstream ss(dateStr);
    ss >> get_time(&date, "%d/%m/%Y");
    if (ss.fail())
    {
        throw runtime_error("Eroare la citirea datei: " + dateStr);
    }
    return date;
}

int main()
{

    //Initializare angajati: 1 manager, 3 operatori, 1 asistent
    Manager m1("Popescu","Marcel","1871025105025",parseDate("12/04/2019"));
    Operator o1("Marin","Denisa","6000619105025",parseDate("06/07/2022"),0);
    //Operator o4("Marin","Dnisa","6000619105025",parseDate("06/07/2022"),0);
    Operator o2("Ion","Darius","5010327105025",parseDate("26/12/2020"),0);
    Operator o3("Popa","Stefan","5030627105025",parseDate("21/11/2023"),0);
    Asistent a1("Zamfir","Ana","2991023105025",parseDate("17/01/2019"));
    //Operator a2;
    vector<Angajat*> angajati;
    angajati.push_back(&m1);
    angajati.push_back(&o1);
    angajati.push_back(&o2);
    angajati.push_back(&o3);
    //angajati.push_back(&o4);
    angajati.push_back(&a1);
    //angajati.push_back(&a2);

    //Initializare produse
    AV v1("Geaca de piele",50, 80, "Neagu", "Gotica"); //100
    AV v2("Lant Skeleton",30,40,"Argintiu", "RocksArt"); //101
    AV v3("Pantaloni",50,100,"Negru","Gotica"); //102
    AV v4("Tricou Korn",10,200,"Gri","Cropp"); //103
    AV v5("Bratara tepi",100,40,"Negru","Gotica"); //104

    Disc d1("CD",50,150,"Elektra Records",parseDate("03/03/1986"),"Metallica","Master of Puppets"); //105
    Disc d2("Vinyl",50,175,"Atco Records",parseDate("24/07/1990"),"Pantera","Cowboys from Hell"); //106
    Disc d3("CD",15,200,"Harvest Records",parseDate("01/03/1973"),"Pink Floyd","The Dark Side of the Moon"); //107
    Disc d4("Vinyl",20,250,"DGC Records",parseDate("24/09/1991"),"Nirvana","Nevermind"); //108
    Disc d5("CD",10,200,"Atlantic Records",parseDate("25/07/1980"),"AC/DC","Back in Black"); //109
    Disc d6("Vinyl",60,100,"Rolling Stones Records",parseDate("12/05/1972"),"The Rolling Stones","Exile on Main St."); //110

    DV dv1("Vinyl",3,700,"Atlantic",parseDate("28/03/1969"),"Led Zeppelin","Turquoise Lettering",0,2); //111
    DV dv2("Vinyl",5,500,"B&C Records",parseDate("06/09/1970"),"Atomic Rooster","Death Walks Behind You",1,1); //112
    DV dv3("Vinyl",1,1000,"United Artists Records",parseDate("18/02/1971"),"Can","Tago Mago",0,2); //113

    vector<Produs*> produse;
    produse.push_back(&v1);
    produse.push_back(&v2);
    produse.push_back(&v3);
    produse.push_back(&v4);
    produse.push_back(&v5);

    produse.push_back(&d1);
    produse.push_back(&d2);
    produse.push_back(&d3);
    produse.push_back(&d4);
    produse.push_back(&d5);
    produse.push_back(&d6);

    produse.push_back(&dv1);
    produse.push_back(&dv2);
    produse.push_back(&dv3);


    string nume_fisier="comenzi.txt";
    Meniu::meniu(angajati,produse,nume_fisier);



    return 0;
}

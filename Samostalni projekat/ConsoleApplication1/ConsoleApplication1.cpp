//Samostalni projekat - Prodavnica(simulacija trgovca)

#include <string>
#include <iostream>
#include <list>

enum pozicija {menadzer,radnik_za_kasom,radnik_u_magacinu,obezbedjenje};
enum energetska_klasa{G,F,E,D,C,B,A,AA,AAA,AAAA};
enum stanje{lose, osrednje, dobro};

class Razmere {
protected:
    float visina;
    float duzina;
    float sirina;
    float tezina;
public:

    float getVisina()  {
        return visina;
    }
    void setVisina(float visina_) {
        visina = visina_;
    }
    float getDuzina()  {
        return duzina;
    }
    void setDuzina(float duzina_) {
        duzina = duzina_;
    }
    float getSirina()  {
        return sirina;
    }
    void setSirina(float sirina_) {
        sirina = sirina_;
    }
    float getTezina()  {
        return tezina;
    }
    void setTezina(float tezina_) {
        tezina = tezina_;
    }
    virtual float getZapremina()  = 0;
};
class Artikal : public Razmere {
private:
    char naziv[40];
    char datum_proizvodnje[40];
    char uvezeno_iz[40];
    char rok_trajanja[40]; // datum kad istice
    bool pokvaren;
    float prodajna_cena;
    float nabavna_cena;
    int sifra;
    char deskripcija[400];
public:
    Artikal() {
        duzina = 10;
        visina = 1;
        sirina = 5;
        tezina = 0.2;
        strcpy_s(naziv, "Cokolada");
        strcpy_s(datum_proizvodnje, "20.04.2021");
        strcpy_s(uvezeno_iz, "Nemacke");
        strcpy_s(rok_trajanja, "20.07.2021");
        pokvaren = false;
        prodajna_cena = 200.00;
        nabavna_cena = 150.00;
        sifra = 205;
        strcpy_s(deskripcija, "Jestivo je.");
    }
    Artikal(float duzina_, float visina_, float sirina_, float tezina_, char* naziv_, char* datum_proizvodnje_, char* uvezeno_iz_, char* rok_trajanja_, bool pokvaren_, float prodajna_cena_, float cena_nabavke_, int sifra_, char* deskripcija_) {
        duzina = duzina_;
        visina = visina_;
        sirina = sirina_;
        tezina = tezina_;
        strcpy_s(naziv, naziv_);
        strcpy_s(datum_proizvodnje, datum_proizvodnje_);
        strcpy_s(uvezeno_iz, uvezeno_iz_);
        strcpy_s(rok_trajanja, rok_trajanja_);
        pokvaren = pokvaren_;
        prodajna_cena = prodajna_cena_;
        nabavna_cena = cena_nabavke_;
        sifra = sifra_;
        strcpy_s(deskripcija, deskripcija_);
    }
    Artikal(const Artikal& a) {
        duzina = a.duzina;
        visina = a.visina;
        sirina = a.sirina;
        tezina = a.tezina;
        strcpy_s(naziv, a.naziv);
        strcpy_s(datum_proizvodnje, a.datum_proizvodnje);
        strcpy_s(uvezeno_iz, a.uvezeno_iz);
        strcpy_s(rok_trajanja, a.rok_trajanja);
        pokvaren = a.pokvaren;
        prodajna_cena = a.prodajna_cena;
        nabavna_cena = a.nabavna_cena;
        sifra = a.sifra;
        strcpy_s(deskripcija, a.deskripcija);
    }
    float getZapremina() {
        return visina * duzina * sirina;
    }
    char* getNaziv() {
        return naziv;
    }
    char* getDatumProizvodnje() {
        return datum_proizvodnje;
    }
    char* getMestoUvoza() {
        return uvezeno_iz;
    }
    char* getRokTrajanja() {
        return rok_trajanja;
    }
    bool getPokvaren() {
        return pokvaren;
    }
    float getProdajnaCena() {
        return prodajna_cena;
    }
    float getNabavnaCena() {
        return nabavna_cena;
    }
    int getSifra() {
        return sifra;
    }
    char* getDeskripcija() {
        return deskripcija;
    }
    void setNaziv(char* naziv_) {
        strcpy_s(naziv, naziv_);
        
    }
    void setDatumProizvodnje(char* datum_proizvodnje_) {
        strcpy_s(datum_proizvodnje, datum_proizvodnje_);
        
    }
    void setMestoUvoza(char* uvezeno_iz_) {
        strcpy_s(uvezeno_iz, uvezeno_iz_);
        
    }
    void setRokTrajanja(char* rok_trajanja_) {
        strcpy_s(rok_trajanja, rok_trajanja_);
        
    }
    void setPokvaren(bool pokvaren_) {
        pokvaren = pokvaren_;
        
    }
    void setProdajnaCena(float prodajna_cena_) {
        prodajna_cena = prodajna_cena_;
        
    }
    void setNabavnaCena(float cena_nabavke_) {
        nabavna_cena = cena_nabavke_;
        
    }
    void setSifra(int sifra_) {
        sifra = sifra_;
        
    }
    void setDeskripcija(char* deskripcija_) {
        strcpy_s(deskripcija, deskripcija_);
    }
    friend std::ostream& operator<<(std::ostream& out, const Artikal& artikal) {
        out << std::endl << "Artikal:" << std::endl;
        out << "Naziv : " << artikal.naziv << std::endl;
        out << "Datum proizvodnje : " << artikal.datum_proizvodnje << std::endl;
        out << "Uvezeno iz :" << artikal.uvezeno_iz << std::endl;
        out << "Rok trajanja : " << artikal.rok_trajanja << std::endl;
        out << "Tezina u kg: " << artikal.tezina << std::endl;
        out << "Pokvaren : ";
        if (artikal.pokvaren) {
            out << "Da" << std::endl;
        }
        else
        {
            out << "Ne" << std::endl;
        }

        out << "Prodajna cena : " << artikal.prodajna_cena << std::endl;
        out << "Nabavna cena : " << artikal.nabavna_cena << std::endl;
        out << "Sifra : " << artikal.sifra << std::endl;
        out << "Deskripcija : " << artikal.deskripcija << std::endl;

        return out;
    }
};


class Korpa : public Razmere {
private:
    bool puna;
    int broj_artikala;
    float izdrzljivost; // koliko kg per pucanja drske
    stanje stanje_korpe;
    std::list<Artikal> lista_artikala; // u korpi
public:
    Korpa() {
        duzina = 50;
        sirina = 50;
        visina = 25; // cm
        tezina = 1; //kg
        puna = false;
        broj_artikala = 2;
        izdrzljivost = 10;
        stanje_korpe = osrednje;
        lista_artikala.push_back(Artikal());
        lista_artikala.push_back(Artikal());
    }
    Korpa(float duzina_, float sirina_, float visina_,float tezina_,bool puna_, int broj_artikala_, float izdrzljivost_, stanje stanje_korpe_, std::list<Artikal> lista_artikala_) {
        duzina = duzina_;
        sirina = sirina_;
        visina = visina_;
        tezina = tezina_;
        puna = puna_;
        broj_artikala = broj_artikala_;
        izdrzljivost = izdrzljivost_;
        stanje_korpe = stanje_korpe_;
        lista_artikala = lista_artikala_;

    }
    Korpa(const Korpa& k) {
        duzina = k.duzina;
        sirina = k.sirina;
        visina = k.visina;
        tezina = k.tezina;
        puna = k.puna;
        broj_artikala = k.broj_artikala;
        izdrzljivost = k.izdrzljivost;
        stanje_korpe = k.stanje_korpe;
        lista_artikala = k.lista_artikala;
    }
    float getZapremina() {
        return visina * duzina * sirina;
    }
    bool getPuna() {
        return puna;
    }
    int getBrojArtikala() {
        return broj_artikala;
    }
    float getIzdrzljivost() {
        return izdrzljivost;
    }
    stanje getStanjeKorpe() {
        return stanje_korpe;
    }
    void setPuna(bool puna_) {
         puna = puna_;
    }
    void setBrojArtikala(int broj) {
         broj_artikala = broj;
    }
    void setIzdrzljivost(float izd) {
         izdrzljivost = izd;
    }
    void setStanjeKorpe(stanje stannje) {
         stanje_korpe=stannje;
    }


    float getArtikalVisina(int koji)  {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getVisina();
        }
    }
    void setArtikalVisina(float visina_, int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
             it->setVisina(visina_);
        }
    }
    float getArtikalDuzina(int koji)  {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getDuzina();
        }
    }
    void setArtikalDuzina(float duzina_, int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            it->setDuzina(duzina_);
        }
    }
    float getArtikalSirina(int koji)  {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getSirina();
        }
    }
    void setArtikalSirina(float sirina_, int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            it->setSirina(sirina_);
        }
    }
    float getArtikalTezina(int koji)  {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getTezina();
        }
    }
    void setArtikalTezina(float tezina_, int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            it->setTezina(tezina_);
        }
    }
    float getArtikalZapremina(int koji)  {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getZapremina();
        }
    }


    char* getArtikalNaziv(int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getNaziv();
        }
    }
    char* getArtikalDatumProizvodnje(int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getDatumProizvodnje();
        }
    }
    char* getArtikalMestoUvoza(int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getMestoUvoza();
        }
    }
    char* getArtikalRokTrajanja(int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getRokTrajanja();
        }
    }
    bool getArtikalPokvaren(int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getPokvaren();
        }
    }
    float getArtikalProdajnaCena(int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getProdajnaCena();
        }
    }
    float getArtikalNabavnaCena(int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getNabavnaCena();
        }
    }
    int getArtikalSifra(int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getSifra();
        }
    }
    char* getArtikalDeskripcija(int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getDeskripcija();
        }
    }
    void setArtikalNaziv(char* naziv_, int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            it->setNaziv(naziv_);
        }

    }
    void setArtikalDatumProizvodnje(char* datum_proizvodnje_, int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            it->setDatumProizvodnje(datum_proizvodnje_);
        }

    }
    void setArtikalMestoUvoza(char* uvezeno_iz_, int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            it->setMestoUvoza(uvezeno_iz_);
        }

    }
    void setArtikalRokTrajanja(char* rok_trajanja_, int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            it->setRokTrajanja(rok_trajanja_);
        }

    }
    void setArtikalPokvaren(bool pokvaren_, int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            it->setPokvaren(pokvaren_);
        }

    }
    void setArtikalProdajnaCena(float prodajna_cena_, int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            it->setProdajnaCena(prodajna_cena_);
        }

    }
    void setArtikalNabavnaCena(float cena_nabavke_, int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            it->setNabavnaCena(cena_nabavke_);
        }

    }
    void setArtikalSifra(int sifra_, int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            it->setSifra(sifra_);
        }

    }
    void setArtikalDeskripcija(char* deskripcija_, int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            it->setDeskripcija(deskripcija_);
        }
    }
    friend std::ostream& operator<<(std::ostream& out, const Korpa& korpa) {

        out << std::endl << "KORPA : " << std::endl;
        out << "Puna :";
        if (korpa.puna) {
            out << "Da" << std::endl;
        }
        else
        {
            out << "Ne" << std::endl;
        }

        out << "Broj artikala : " << korpa.broj_artikala << std::endl;
        out << "Izdrzljivost : " << korpa.izdrzljivost << " kg"<< std::endl;
        out << "Stanje korpe : " << korpa.stanje_korpe << std::endl;
        out << "Lista artikala : " << std::endl;
        out << "Zapremina u cm^3 : " << korpa.visina * korpa.sirina * korpa.duzina << std::endl;
        out << "Tezina u kg:" << korpa.tezina << std::endl;

        std::list<Artikal>::const_iterator it = korpa.lista_artikala.begin();
        for (int i = 0; i < korpa.broj_artikala; i++, it++) {
            out << *it << std::endl;
        }

        return out;
    }
};


class Osoba {
protected:
    char ime[40];
    char prezime[40];
    int starost;
    int godine_radnog_staza;
    float snaga; // koliko kg moze da digne
public:
    Osoba() {
        strcpy_s(ime, "Petar");
        strcpy_s(prezime, "Petrovic");
        starost = 20;
        godine_radnog_staza = 2;
        snaga = 5;
    }
    Osoba(char* Ime, char* Prezime, int Starost, int Godine_radnog_staza,float snaga_) {
        strcpy_s(ime, Ime);
        strcpy_s(prezime, Prezime);
        starost = Starost;
        godine_radnog_staza = Godine_radnog_staza;
        snaga = snaga_;
    }
    Osoba(const Osoba& o) {
        strcpy_s(ime, o.ime);
        strcpy_s(prezime, o.prezime);
        starost = o.starost;
        godine_radnog_staza = o.godine_radnog_staza;
        snaga = o.snaga;
    }
    char* getIme() {
        return ime;
    }
    char* getPrezime() {
        return prezime;
    }
    int getStarost() const {
        return starost;
    }
    int getStaz() const {
        return godine_radnog_staza;
    }
    void setIme(char* ime_) {
        strcpy_s(ime, ime_);
    }
    void setPrezime(char* prezime_) {
        strcpy_s(prezime, prezime_);
    }
    void setStarost(int starost_) {
        starost = starost_;
    }
    void setStaz(int staz) {
        godine_radnog_staza = staz;
    }
    float getSnaga() const {
        return snaga;
    }
    void setSnaga(float snaga_) {
        snaga = snaga_;
    }
    friend std::ostream& operator<<(std::ostream& out, const Osoba& osoba) {

        out << "Ime : " << osoba.ime << std::endl;
        out << "Prezime : " << osoba.prezime << std::endl;
        out << "Starost : " << osoba.starost << std::endl;
        out << "Godine radnog staza : " << osoba.godine_radnog_staza << std::endl;
        out << "Snaga : " << osoba.snaga << " kg" << std::endl;

        return out;
    }
};
class Potrosac : public Osoba {
private:

    float budzet; // u dinarima
    bool u_redu;
    int pozicija_u_redu;
    Korpa korpa;
public:
    
    Potrosac() :Osoba() {
        budzet = 500;
        u_redu = 0;
        pozicija_u_redu = 0;
        korpa = Korpa();
    }
    Potrosac(char* ime, char* prezime, int starost, int godine_staza, float snaga, float budzet_, bool u_redu_, int pozicija_u_redu_, const Korpa& k) :Osoba(ime, prezime, starost, godine_staza, snaga) {
        budzet = budzet_;
        u_redu = u_redu_;
        pozicija_u_redu = pozicija_u_redu_;
        korpa = Korpa(k);
    }
    Potrosac(const Potrosac& o) : Osoba(o) {
        budzet = o.budzet;
        u_redu = o.u_redu;
        pozicija_u_redu = o.pozicija_u_redu;
        korpa = Korpa(o.korpa);
    }

    float getBudzet() const {
        return budzet;
    }
    bool getU_redu() const {
        return u_redu;
    }
    int getPozicija_u_redu()const {
        return pozicija_u_redu;
    }
    Korpa* getKorpa() {
        return &korpa;
    }
    void setBudzet(float budzet_) {
        budzet = budzet_;
    }
    void setU_redu(bool red) {
        u_redu = red;
    }
    void setPozicija_u_redu(int poz) {
        pozicija_u_redu = poz;
    }
    void setKorpa(const Korpa& korpa_) {
        korpa = Korpa(korpa);
    }
    friend std::ostream& operator<<(std::ostream& out, const Potrosac& potrosac) {
        out << std::endl << "Potrosac" << std::endl;
        out << (const Osoba&)potrosac;
        out << "Budzet : " << potrosac.budzet << std::endl;
        out << "Ceka u redu : ";
        if (potrosac.u_redu) {
            out << "Da" << std::endl;
            out << "Pozicija u redu : " << potrosac.pozicija_u_redu << std::endl;
        }
        else
        {
            out << "Ne" << std::endl;
        }

        out << std::endl << potrosac.korpa << std::endl;

        return out;
    }
};
class Radnik : public Osoba {
private:
    pozicija pozicija_na_poslu;
    float zarada_po_satu;
public:
    Radnik():Osoba(){
        pozicija_na_poslu = radnik_za_kasom;
        zarada_po_satu = 500;
    }
    Radnik(char* ime, char* prezime, int starost, int godine_staza,float snaga , pozicija poz,float zarada_po_satu_) :Osoba(ime,prezime,starost,godine_staza,snaga) {
        pozicija_na_poslu = poz;
        zarada_po_satu = zarada_po_satu_;
    }
    Radnik(const Radnik& o) :Osoba(o) {
        pozicija_na_poslu = o.pozicija_na_poslu;
        zarada_po_satu = o.zarada_po_satu;
    }
    pozicija getPozicija_na_poslu() {
        return pozicija_na_poslu;
    }
    float getZarada_po_satu() {
        return zarada_po_satu;
    }
    void setPozicija_na_poslu(pozicija poz) {
        pozicija_na_poslu = poz;
    }
    void setZarada_po_satu(float zarada) {
        zarada_po_satu = zarada;
    }
    friend std::ostream& operator<<(std::ostream& out, const Radnik& radnik) {
        out << std::endl << "Radnik" << std::endl;
        out << (const Osoba&)radnik << std::endl;
        out << "Pozicija na poslu : " << radnik.pozicija_na_poslu << std::endl;
        out << "Zarada po satu : " << radnik.zarada_po_satu << std::endl;
        return out;
    }
};
class Vlasnik_Prodavnice : public Osoba {
private:
    float mesecni_profit;
    float prosecna_cena_nabavke;
    float budzet;
    bool trenutno_u_prodavnici;
public:
    Vlasnik_Prodavnice() : Osoba(){
        mesecni_profit = 100000;
        prosecna_cena_nabavke = 10000;
        budzet = 400000;
        trenutno_u_prodavnici = false;
    }
    Vlasnik_Prodavnice(char* ime, char* prezime, int starost, int godine_staza, float snaga,  float budzet_, float cena, float profit , bool u_prodavnici) :Osoba(ime, prezime, starost, godine_staza, snaga) {
        budzet = budzet_;
        mesecni_profit = profit;
        prosecna_cena_nabavke = cena;
        trenutno_u_prodavnici = u_prodavnici;
    }
    Vlasnik_Prodavnice(const Vlasnik_Prodavnice& o) :Osoba(o) {
        budzet = o.budzet;
        mesecni_profit = o.mesecni_profit;
        prosecna_cena_nabavke = o.prosecna_cena_nabavke;
        trenutno_u_prodavnici = o.trenutno_u_prodavnici;
    }
    
    float getMesecni_profit() {
        return mesecni_profit;
    }
    float getProsecna_cena_nabavke() {
        return prosecna_cena_nabavke;
    }
    float getBudzet() {
        return budzet;
    }
    bool getTrenutno_u_prodavnici() {
        return trenutno_u_prodavnici;
    }
    void setMesecni_profit(float profit) {
        mesecni_profit = profit;
    }
    void setProsecna_cena_nabavke(float cena) {
        prosecna_cena_nabavke = cena;
    }
    void setBudzet(float budzet_) {
        budzet = budzet_;
    }
    void setTrenutno_u_prodavnici(bool u_prod) {
        trenutno_u_prodavnici = u_prod;
    }
    friend std::ostream& operator<<(std::ostream& out, const Vlasnik_Prodavnice& vlasnik) {
        out << std::endl << "VLASNIK" << std::endl;
        out << (const Osoba&)vlasnik;
        out << "Mesecni profit : " << vlasnik.mesecni_profit << std::endl;
        out << "Prosecna cena nabavke : " << vlasnik.prosecna_cena_nabavke << std::endl;
        out << "Budzet : " << vlasnik.budzet << std::endl;
        out << "Da li je trenutno u prodavnici : ";
        if (vlasnik.trenutno_u_prodavnici) {
            out << "Da" << std::endl;
        }
        else
        {
            out << "Ne" << std::endl;
        }

        return out;
    }
};
class Smena {
private:
    char vreme_pocetka[20];
    char vreme_pocetka_vikendom[20];
    char vreme_kraja[20];
    char vreme_kraja_vikendom[20];
    int broj_radnika;
    std::list<Radnik> lista_radnika;
public:
    Smena() {
        strcpy_s(vreme_pocetka, "07:30");
        strcpy_s(vreme_pocetka_vikendom, "07:30");
        strcpy_s(vreme_kraja, "20:30");
        strcpy_s(vreme_kraja_vikendom, "12:30");
        broj_radnika = 2;
        lista_radnika.push_back(Radnik());
        lista_radnika.push_back(Radnik());
    }
    Smena(char* pocetak, char* pocetak_v, char* kraj, char* kraj_v, int broj_r, std::list<Radnik> lista) {
        strcpy_s(vreme_pocetka, pocetak);
        strcpy_s(vreme_pocetka_vikendom, pocetak_v);
        strcpy_s(vreme_kraja, kraj);
        strcpy_s(vreme_kraja_vikendom, kraj_v);
        broj_radnika = broj_r;
        lista_radnika = lista;
    }
    Smena(const Smena& s) {
        strcpy_s(vreme_pocetka, s.vreme_pocetka);
        strcpy_s(vreme_pocetka_vikendom, s.vreme_pocetka_vikendom);
        strcpy_s(vreme_kraja, s.vreme_kraja);
        strcpy_s(vreme_kraja_vikendom, s.vreme_kraja_vikendom);
        broj_radnika = s.broj_radnika;
        lista_radnika = s.lista_radnika;
    }
    char* getVremePocetka() {
        return vreme_pocetka;
    }
    char* getVremePocetkaVikendom() {
        return vreme_pocetka_vikendom;
    }
    char* getVremeKraja() {
        return vreme_kraja;
    }
    char* getVremeKrajaVikendom() {
        return vreme_kraja_vikendom;
    }
    int getBrojRadnika() {
        return broj_radnika;
    }
    void setVremePocetka(char* pocetak) {
        strcpy_s(vreme_pocetka, pocetak);
        
    }
    void setVremePocetkaVikendom(char* pocetak_v) {
        strcpy_s(vreme_pocetka_vikendom, pocetak_v);
        
    }
    void setVremeKraja(char* kraj) {
        strcpy_s(vreme_kraja, kraj);
        
    }
    void setVremeKrajaVikendom(char* kraj_v) {
        strcpy_s(vreme_kraja_vikendom, kraj_v);
    }
    void setBrojRadnika(int broj) {
         broj_radnika = broj;
    }
    pozicija getRadnikPozicija_na_poslu(int koji) {
        if (koji > broj_radnika) {
            
        }
        else {
            std::list<Radnik>::iterator it = lista_radnika.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getPozicija_na_poslu();
        }
    }
    float getRadnikZarada_po_satu(int koji) {
        if (koji > broj_radnika) {
            
        }
        else {
            std::list<Radnik>::iterator it = lista_radnika.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getZarada_po_satu();
        }
    }
    void setRadnikPozicija_na_poslu(pozicija poz, int koji) {
        if (koji > broj_radnika) {
            
        }
        else {
            std::list<Radnik>::iterator it = lista_radnika.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            it->setPozicija_na_poslu(poz);
        }
    }
    void setRadnikZarada_po_satu(float zarada,int koji) {
        if (koji > broj_radnika) {
            
        }
        else {
            std::list<Radnik>::iterator it = lista_radnika.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            it->setZarada_po_satu(zarada);
        }
    }
    char* getRadnikIme(int koji) {
        if (koji > broj_radnika) {
            
        }
        else {
            std::list<Radnik>::iterator it = lista_radnika.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getIme();
        }
    }
    char* getRadnikPrezime(int koji) {
        if (koji > broj_radnika) {

        }
        else {
            std::list<Radnik>::iterator it = lista_radnika.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getPrezime();
        }
    }
    int getRadnikStarost(int koji) {
        if (koji > broj_radnika) {

        }
        else {
            std::list<Radnik>::iterator it = lista_radnika.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getStarost();
        }
    }
    int getRadnikStaz(int koji) {
        if (koji > broj_radnika) {

        }
        else {
            std::list<Radnik>::iterator it = lista_radnika.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getStaz();
        }
    }
    void setRadnikIme(char* ime_, int koji) {
        if (koji > broj_radnika) {
           
        }
        else {
            std::list<Radnik>::iterator it = lista_radnika.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            it->setIme(ime_);
        }
    }
    void setRadnikPrezime(char* prezime_, int koji) {
        if (koji > broj_radnika) {
            
        }
        else {
            std::list<Radnik>::iterator it = lista_radnika.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            it->setPrezime(prezime_);
        }
    }
    void setRadnikStarost(int starost_, int koji) {
        if (koji > broj_radnika) {
            
        }
        else {
            std::list<Radnik>::iterator it = lista_radnika.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            it->setStarost(starost_);
        }
    }
    void setRadnikStaz(int staz, int koji) {
        if (koji > broj_radnika) {
            
        }
        else {
            std::list<Radnik>::iterator it = lista_radnika.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            it->setStaz(staz);
        }
    }
    float getRadnikSnaga(int koji) {
        if (koji > broj_radnika) {
            
        }
        else {
            std::list<Radnik>::iterator it = lista_radnika.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            return it->getSnaga();
        }
    }
    void setRadnikSnaga(float snaga_, int koji) {
        if (koji > broj_radnika) {
            
        }
        else {
            std::list<Radnik>::iterator it = lista_radnika.begin();
            for (int i = 0; i < koji; i++, it++) {
            }
            it->setSnaga(snaga_);
        }
    }
    friend std::ostream& operator<< (std::ostream& out, const Smena& s) {

        out << std::endl << "SMENA: " << std::endl;
        out << "Vreme pocetka: " << s.vreme_pocetka << std::endl;
        out << "Vreme pocetka vikendom: " << s.vreme_pocetka_vikendom << std::endl;
        out << "Vreme kraja: " << s.vreme_kraja << std::endl;
        out << "Vreme kraja vikendom: " << s.vreme_kraja_vikendom << std::endl;
        out << "Broj radnika: " << s.broj_radnika << std::endl;

        std::list<Radnik>::const_iterator it = s.lista_radnika.begin();
        for (int i = 0; i < s.broj_radnika; i++, it++) {
            out << *it << std::endl;
        }
        out << std::endl;

        return out;
    }
};

class Racun {
private:
    int broj_kupljenih_artikala;
    std::list<Artikal> lista_kupljenih_artikala;
    float ukupan_iznos;
    float placeno;
    float povracaj;
public:
    Racun() {
        broj_kupljenih_artikala = 2;
        ukupan_iznos = 240;
        placeno = 500;
        povracaj = 260;
        lista_kupljenih_artikala.push_back(Artikal());
        lista_kupljenih_artikala.push_back(Artikal());
    }
    Racun(int broj_kupljenih_stvari_, float ukupan_iznos_, float placeno_, float povracaj_, std::list<Artikal> lista) {
        broj_kupljenih_artikala = broj_kupljenih_stvari_;
        ukupan_iznos = ukupan_iznos_;
        placeno = placeno_;
        povracaj = povracaj_;
        lista_kupljenih_artikala = lista;
    }
    Racun(const Racun& o) {
        broj_kupljenih_artikala = o.broj_kupljenih_artikala;
        ukupan_iznos = o.ukupan_iznos;
        placeno = o.placeno;
        povracaj = o.povracaj;
        lista_kupljenih_artikala = o.lista_kupljenih_artikala;
    }

    int getBrojKupljenihArtikala() {
        return broj_kupljenih_artikala;
    }
    float getUkupanIznos() {
        return ukupan_iznos;
    }
    float getPlaceno() {
        return placeno;
    }
    float getPovracaj() {
        return povracaj;
    }
    std::list<Artikal> getListaKupljenihArtikala() {
        return lista_kupljenih_artikala;
    }
    Artikal* getArtikal(int koji) {
        koji--;
        if (koji > broj_kupljenih_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_kupljenih_artikala.begin();
            for (int i = 0; i < koji; i++, it++);
            
            return &(*it);
        }
    }

    void setBrojKupljenihArtikala(int broj) {
         broj_kupljenih_artikala = broj;
    }
    void setUkupanIznos(float iznos) {
         ukupan_iznos = iznos;
    }
    void setPlaceno(float pla) {
         placeno = pla;
    }
    void setPovracaj(float pov) {
         povracaj = pov;
    }
    void setListaKupljenihArtikala(std::list<Artikal> lista) {
        lista_kupljenih_artikala = lista;
    }
    friend std::ostream& operator<<(std::ostream& out, const Racun& racun) {
        out << std::endl << "RACUN : " << std::endl;
        out << "Broj kupljenih artikala : " << racun.broj_kupljenih_artikala << std::endl;
        out << "Lista kupljenih artikala : " << std::endl;
        std::list<Artikal>::const_iterator it = racun.lista_kupljenih_artikala.begin();
        for (int i = 0; i < racun.broj_kupljenih_artikala; i++, it++) {
            out << *it << std::endl;
        }
        out << "Ukupan iznos : " << racun.ukupan_iznos << std::endl;
        out << "Placeno : " << racun.placeno << std::endl;
        out << "Povracaj  : " << racun.povracaj << std::endl;

        return out;
    }
};
class Kasa {
private:
    float novac; // u kasi
    int racuni; // koliko jos moze racuna da ispise
    int broj_ispisanih_racuna;
    std::list<Racun> lista_izdatih_racuna;
public:
    Kasa() {
        novac = 20000;
        racuni = 50;
        broj_ispisanih_racuna = 2;
        lista_izdatih_racuna.push_back(Racun());
        lista_izdatih_racuna.push_back(Racun());

    }
    Kasa(float novac_, int racuni_, int broj_ispisanih_racuna_, std::list<Racun> lista) {
        novac = novac_;
        racuni = racuni_;
        broj_ispisanih_racuna = broj_ispisanih_racuna_;
        lista_izdatih_racuna = lista;
    }
    Kasa(const Kasa& k) {
        novac = k.novac;
        racuni = k.racuni;
        broj_ispisanih_racuna = k.broj_ispisanih_racuna;
        lista_izdatih_racuna = k.lista_izdatih_racuna;
    }
    float getNovacUKasi() {
        return novac;
    }
    int getBrojMogucihNovihRacuna() {
        return racuni;
    }
    int getBrojIspisanihRacuna() {
        return broj_ispisanih_racuna;
    }
    std::list<Racun> getListaIzdatihRacuna() {
        return lista_izdatih_racuna;
    }
    Racun* getArtikal(int koji) {
        koji--;
        if (koji > broj_ispisanih_racuna) {

        }
        else {
            std::list<Racun>::iterator it = lista_izdatih_racuna.begin();
            for (int i = 0; i < koji; i++, it++);
            return &(*it);
        }
    }
    
    void getNovacUKasi(float novac_ ) {
        novac = novac_;
        
    }
    void getBrojMogucihNovihRacuna(int racuni_ ) {
        racuni = racuni_;
        
    }
    void getBrojIspisanihRacuna(int broj_ispisanih_racuna_ ) {
        broj_ispisanih_racuna = broj_ispisanih_racuna_;
        
    }
    void getListaIzdatihRacuna(std::list<Racun> lista) {
        lista_izdatih_racuna = lista;
    }
    friend std::ostream& operator<<(std::ostream& out, const Kasa& kasa) {
        out << std::endl << "KASA : " << std::endl;
        out << "Novac u kasi : " << kasa.novac << std::endl;
        out << "Moze ispisati jos : " << kasa.racuni << " racuna " << std::endl;
        out << "Broj ispisanih racuna : " << kasa.broj_ispisanih_racuna << std::endl;
        out << "Lista izdatih racuna : " << std::endl;
        std::list<Racun>::const_iterator it = kasa.lista_izdatih_racuna.begin();
        for (int i = 0; i < kasa.broj_ispisanih_racuna; i++, it++) {
            out << *it << std::endl;
        }

        return out;
    }
};

class Nabavka {

private:
    float cena;
    float profit;
    bool poruceno;
    bool placeno;
    bool isporuceno;
    int broj_artikala;
    std::list<Artikal> lista_artikala;

public:

    Nabavka() {

        cena = 5000.567;
        profit = 2000.43;
        poruceno = true;
        placeno = false;
        isporuceno = false;
        broj_artikala = 2;
        lista_artikala.push_back(Artikal());
        lista_artikala.push_back(Artikal());
    }

    Nabavka(float cena_, float profit_, bool poruceno_, bool placeno_, bool isporuceno_, int broj_artikala_, std::list<Artikal> artikli_) {

        cena = cena_;
        profit = profit_;
        poruceno = poruceno_;
        placeno = placeno_;
        isporuceno = isporuceno_;
        broj_artikala = broj_artikala_;
        lista_artikala = artikli_;
    }

    Nabavka(const Nabavka& nabavka) {

        cena = nabavka.cena;
        profit = nabavka.profit;
        poruceno = nabavka.poruceno;
        placeno = nabavka.placeno;
        isporuceno = nabavka.isporuceno;
        broj_artikala = nabavka.broj_artikala;
        lista_artikala = nabavka.lista_artikala;
    }

    float getCena()const {
        return cena;
    }

    float getProfit()const {
        return profit;
    }

    bool getPoruceno()const {
        return poruceno;
    }

    bool getPlaceno()const {
        return placeno;
    }

    bool getIsporuceno()const {
        return isporuceno;
    }

    int getBrojArtikala()const {
        return broj_artikala;
    }

    Artikal* getArtikal(int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = lista_artikala.begin();
            for (int i = 0; i < koji; i++, it++);

            return &(*it);
        }
    }

    std::list<Artikal> getListaArtikala()const {
        return lista_artikala;
    }

    void setCena(float cena_) {
        cena = cena_;
    }

    void setProfit(float profit_) {
        profit = profit_;
    }

    void setPoruceno(bool poruceno_) {
        poruceno = poruceno_;
    }

    void setPlaceno(bool placeno_) {
        placeno = placeno_;
    }

    void setIsporuceno(bool isporuceno_) {
        isporuceno = isporuceno_;
    }

    void setBrojArtikala(int broj_artikala_) {
        if (broj_artikala_ < 0) {

        }
        else
        {
            broj_artikala = broj_artikala_;
        }
    }

    void setListaArtikala(std::list<Artikal> artikli) {
        lista_artikala = artikli;
    }

    friend std::ostream& operator<<(std::ostream& out, const Nabavka& nabavka) {
        out << std::endl << "NABAVKA: " << std::endl;
        out << "Cena je : " << nabavka.cena << std::endl;
        out << "Profit je : " << nabavka.profit << std::endl;
        out << "Poruceno : ";
        if (nabavka.poruceno) {
            out << "Da" << std::endl;
        }
        else
        {
            out << "Ne" << std::endl;
        }

        out << "Placeno : ";
        if (nabavka.placeno) {
            out << "Da" << std::endl;
        }
        else
        {
            out << "Ne" << std::endl;
        }

        out << "Isporuceno : ";
        if (nabavka.isporuceno) {
            out << "Da" << std::endl;
        }
        else
        {
            out << "Ne" << std::endl;
        }

        out << "Broj artikala : " << nabavka.broj_artikala << std::endl;
        out << "Lista artikala : " <<std::endl;

        std::list<Artikal>::const_iterator it = nabavka.lista_artikala.begin();
        for (int i = 0; i < nabavka.broj_artikala; i++, it++) {
            out << *it << std::endl;
        }

        return out;
    }
};
class Magacin {
private:
    int broj_artikala;
    float ukupna_vrednost;
    float ukupna_nabavna_vrednost;
    float profit;
    std::list<Artikal> artikli;
public:
    Magacin() {
        broj_artikala = 3;
        ukupna_vrednost = 600;
        ukupna_nabavna_vrednost = 450;
        profit = 150;
        artikli.push_back(Artikal());
        artikli.push_back(Artikal());
        artikli.push_back(Artikal());
    }
    Magacin(int broj, float vrednost_u, float vrednost_nabavna_u, float profit_, std::list<Artikal> lista) {
        broj_artikala = broj;
        ukupna_vrednost = vrednost_u;
        ukupna_nabavna_vrednost = vrednost_nabavna_u;
        profit = profit_;
        artikli = lista;
    }
    Magacin(const Magacin& m) {
        broj_artikala = m.broj_artikala;
        ukupna_nabavna_vrednost = m.ukupna_nabavna_vrednost;
        ukupna_vrednost = m.ukupna_vrednost;
        profit = m.profit;
        artikli = m.artikli;
    }
    int getBrojArtikala() {
        return broj_artikala;
    }
    float getUkupnaVrednost() {
        return ukupna_vrednost;
    }
    float getUkupnaNabavnaVrednost() {
        ukupna_nabavna_vrednost;
    }
    float getProfit() {
        return profit;
    }
    Artikal* getArtikal(int koji) {
        koji--;
        if (koji > broj_artikala) {

        }
        else {
            std::list<Artikal>::iterator it = artikli.begin();
            for (int i = 0; i < koji; i++, it++);

            return &(*it);
        }
    }
    std::list<Artikal> getListaArtikala() {
        return artikli;
    }
    void setBrojArtikala(int broj) {
        broj_artikala = broj;
    }
    void setUkupnaVrednost(float vrednost) {
        ukupna_vrednost = vrednost;
    }
    void setUkupnaNabavnaVrednost(float vrednost) {
        ukupna_nabavna_vrednost = vrednost;
    }
    void setProfit(float profit_) {
        profit = profit_;
    }
    void setArtikli(std::list<Artikal> lista) {
        artikli = lista;
    }
    friend std::ostream& operator<<(std::ostream& out, const Magacin& magacin) {
        out << std::endl << "MAGACIN : " << std::endl;
        out << "Broja artikala : " << magacin.broj_artikala << std::endl;
        out << "Ukupna vrednost : " << magacin.ukupna_vrednost << std::endl;
        out << "Ukupna nabavna vrednost : " << magacin.ukupna_nabavna_vrednost << std::endl;
        out << "Profit : " << magacin.profit << std::endl;
        out << "Lista artikala : " << std::endl;
        std::list<Artikal>::const_iterator it = magacin.artikli.begin();
        for (int i = 0; i < magacin.broj_artikala; i++, it++) {
            out << *it << std::endl;
        }

        return out;

    }
};
class Tehnika : public Razmere{
private:
    char naziv[40];
    char datum_kupovine[40];
    bool ima_garanciju;
    bool pokvareno;
    float cena;
    float zivotni_vek; //pre nego sto treba da se zameni (u godinama)
    energetska_klasa klasa;
public:
    Tehnika() {
        strcpy_s(naziv, "Kamera");
        strcpy_s(datum_kupovine, "20.04.2020");
        ima_garanciju = true;
        pokvareno = false;
        cena = 5000;
        zivotni_vek = 2.6;
        visina = 10;
        sirina = 10;
        duzina = 20;
        tezina = 2;
        klasa = A;
    }
    Tehnika(char* naziv_, char* datum_kupovine_, bool ima_garanciju_, bool pokvareno_, float cena_, float zivotni_vek_,float visina_, float duzina_, float sirina_, float tezina_, energetska_klasa klasa_) {
        strcpy_s(naziv, naziv_);
        strcpy_s(datum_kupovine, datum_kupovine_);
        ima_garanciju = ima_garanciju_;
        pokvareno = pokvareno_;
        cena = cena_;
        zivotni_vek = zivotni_vek_;
        visina = visina_;
        sirina = sirina_;
        duzina = duzina_;
        tezina = tezina_;
        klasa = klasa_;
    }
    Tehnika(const Tehnika& t) {
            strcpy_s(naziv, t.naziv);
            strcpy_s(datum_kupovine, t.datum_kupovine);
            ima_garanciju = t.ima_garanciju;
            pokvareno = t.pokvareno;
            cena = t.cena;
            zivotni_vek = t.zivotni_vek;   
            visina = t.visina;
            sirina = t.sirina;
            duzina = t.duzina;
            tezina = t.tezina;
            klasa = t.klasa;
    }
    float getZapremina() {
        return visina * duzina * sirina;
    }
    char* getNaziv() {
        return naziv;
    }
    char* getDatumKupovine() {
        return datum_kupovine;
    }
    bool getGarancija() const{
        return ima_garanciju;
    }
    bool getPokvareno() const{
        return pokvareno;
    }
    float getCena() const{
        return cena;
    }
    float getZivotniVek() const{
        return zivotni_vek;
    }
    energetska_klasa getEnergetskaKlasa() {
        return klasa;
    }
    
    void setNaziv(char* naziv_) {
        strcpy_s(naziv, naziv_);
        
    }
    void setDatumKupovine(char* datum_kupovine_) {
        strcpy_s(datum_kupovine, datum_kupovine_);
        
    }
    void setGarancija(bool ima_garanciju_) {
        ima_garanciju = ima_garanciju_;
        
    }
    void setPokvareno(bool pokvareno_) {
        pokvareno = pokvareno_;
        
    }
    void setCena(float cena_) {
        cena = cena_;
        
    }
    void setZivotniVek(float zivotni_vek_) {
        zivotni_vek = zivotni_vek_;
    }
    void setEnergetskaKlasa(energetska_klasa klasa_) {
        klasa = klasa_;
    }
    friend std::ostream& operator<< (std::ostream& out, const Tehnika& t) {

        out << std::endl  << "Tehnika:" << std::endl;
        out << "Naziv: " << t.naziv << std::endl;
        out << "Datum kupovine: " << t.datum_kupovine << std::endl;
        out << "Ima garanciju: ";
        if (t.ima_garanciju) {
            out << "Da" << std::endl;
        }
        else {
            out << "Ne" << std::endl;
        }
        out << "Da li radi: ";
        if (t.pokvareno) {
            out << "Ne" << std::endl;
        }
        else {
            out << "Da" << std::endl;
        }
        out << "Energetska klasa: ";
        switch (t.klasa)
        {
        case 0: {
            out << "G";
            break;
        }
        case 1: {
            out << "F";
            break;
        }
        case 2: {
            out << "E";
            break;
        }
        case 3: {
            out << "D";
            break;
        }
        case 4: {
            out << "C";
            break;
        }
        case 5: {
            out << "B";
            break;
        }
        case 6: {
            out << "A";
            break;
        }
        case 7: {
            out << "AA";
            break;
        }
        case 8: {
            out << "AAA";
            break;
        }
        case 9: {
            out << "AAAA";
            break;
        }

        }
        out << std::endl;
        out << "Cena: " << t.cena << std::endl;
        out << "Zivotni vek: " << t.zivotni_vek << std::endl;
        out << "Visina: " << t.visina << " cm" << std::endl;
        out << "Duzina: " << t.duzina << " cm" << std::endl;
        out << "Sirina: " << t.sirina << " cm" << std::endl;
        out << "Tezina: " << t.tezina << " kg" << std::endl;
        out << std::endl;
        

        return out;
    }
};
class Vozilo :public Razmere{
private:
    char marka[40];
    int godina_nastanka;
    bool u_voznom_stanju;
    float cena; // u evrima
    float cena_popravke; //u evrima
    float predjeno_km;
    float gorivo; // procenti
    float preostalo_km; //dok se ne potrosi gorivo;
    float preostalo_do_kvara;// u km
public:
    Vozilo() {
        strcpy_s(marka, "BMW");
        godina_nastanka = 2010;
        u_voznom_stanju = true;
        cena = 5000;
        cena_popravke = 500;
        predjeno_km = 120000;
        gorivo = 50;
        preostalo_km = 320;
        preostalo_do_kvara = 12000;
        visina = 150;
        duzina = 250;
        sirina = 100;
        tezina = 1400;
    }
    Vozilo(char* marka_, int godina_, bool u_voznom_stanju_, float cena_, float cena_popravke_, float predjeno_km_, float gorivo_, float preostalo_km_, float preostalo_do_kvare, float visina_, float sirina_,float duzina_, float tezina_){
        strcpy_s(marka, marka_);
        godina_nastanka = godina_;
        u_voznom_stanju = u_voznom_stanju_;
        cena = cena_;
        cena_popravke = cena_popravke_;
        predjeno_km = predjeno_km_;
        gorivo = gorivo_;
        preostalo_km = preostalo_km_;
        preostalo_do_kvara = preostalo_do_kvare;
        visina = visina_;
        duzina = duzina_;
        sirina = sirina_;
        tezina = tezina_;
    }
    Vozilo(const Vozilo& v) {
        strcpy_s(marka, v.marka);
        godina_nastanka = v.godina_nastanka;
        u_voznom_stanju = v.u_voznom_stanju;
        cena = v.cena;
        cena_popravke = v.cena_popravke;
        predjeno_km = v.predjeno_km;
        gorivo = v.gorivo;
        preostalo_km = predjeno_km;
        preostalo_do_kvara = v.preostalo_do_kvara;
        visina = v.visina;
        duzina = v.duzina;
        sirina = v.sirina;
        tezina = v.tezina;
    }
    float getZapremina() {
        return visina * duzina * sirina;
    }
    char* getMarka() {
        return marka;
    }
    int getGodina() const {
        return godina_nastanka;
    }
    bool getUvoznomStanju() const {
        return u_voznom_stanju;
    }
    float getCena() const {
        return cena;
    }
    float getCenaPopravke()const {
        return cena_popravke;
    }
    float getPredjeno()const {
        return predjeno_km;
    }
    float getGorivo()const{
        return gorivo;
    }
    float getPreostalo()const {
        return preostalo_km;
    }
    float getPreostaloDoKvara() const {
        return preostalo_do_kvara;
    }

    void setMarka(char* marka_) {
        strcpy_s(marka, marka_);
        
    }
    void setGodina(int godina_)  {
        godina_nastanka = godina_;
        
    }
    void getUvoznomStanju(bool u_voznom_stanju_)  {
        u_voznom_stanju = u_voznom_stanju_;
        
    }
    void getCena(float cena_)  {
        cena = cena_;
        
    }
    void getCenaPopravke(float cena_popravke_) {
        cena_popravke = cena_popravke_;
        
    }
    void getPredjeno(float predjeno_km_) {
        predjeno_km = predjeno_km_;
        
    }
    void getGorivo(float gorivo_) {
        gorivo = gorivo_;
        
    }
    void getPreostalo(float preostalo_km_) {
        preostalo_km = preostalo_km_;
        
    }
    void getPreostaloDoKvara(float preostalo_do_kvare)  {
        preostalo_do_kvara = preostalo_do_kvare;
        
    }
    friend std::ostream& operator<<(std::ostream& out, const Vozilo& vozilo) {
        out << std::endl << "VOZILO : " << std::endl;
        out << "Marka vozila : " << vozilo.marka << std::endl;
        out << "Godina nastanka : " << vozilo.godina_nastanka << std::endl;
        out << "Da li je u voznom stanju : ";
        if (vozilo.u_voznom_stanju) {
            out << "Da" << std::endl;
        }
        else
        {
            out << "Ne" << std::endl;
        }
        out << "Cena vozila (u evrima) : " << vozilo.cena << std::endl;
        out << "Cena popravke (u evrima) : " << vozilo.cena_popravke << std::endl;
        out << "Predjeno kilometara : " << vozilo.predjeno_km << std::endl;
        out << "Gorivo u rezervoaru : " << vozilo.gorivo << "%" << std::endl;
        out << "Preostalo kilometara dok se ne potrosi gorivo : " << vozilo.preostalo_km << std::endl;
        out << "Preostalo kilometara do kvara : " << vozilo.preostalo_do_kvara << std::endl;
        out << "Duzina : " << vozilo.duzina << " cm" << std::endl;
        out << "Visina : " << vozilo.visina << " cm" << std::endl;
        out << "Sirina : " << vozilo.sirina << " cm" << std::endl;
        out << "Tezina : " << vozilo.tezina << " kg" << std::endl;

        return out;
    }
};

class Inventar {

private:
    int broj_tehnike;
    int broj_vozila;
    std::list<Vozilo> vozila;
    std::list<Tehnika> tehnika;
    float ukupna_vrednost;

public:
    Inventar() {

        broj_tehnike = 5;
        broj_vozila = 2;
        vozila.push_back(Vozilo());
        vozila.push_back(Vozilo());
        tehnika.push_back(Tehnika());
        tehnika.push_back(Tehnika());
        tehnika.push_back(Tehnika());
        tehnika.push_back(Tehnika());
        tehnika.push_back(Tehnika());
        ukupna_vrednost = 250000;
    }

    Inventar(int broj_tehnike_, int broj_vozila_, std::list<Vozilo> vozila_, std::list<Tehnika> tehnika_, float ukupna_vrednost_) {

        broj_tehnike = broj_tehnike_;
        broj_vozila = broj_vozila;
        vozila = vozila_;
        tehnika = tehnika_;
        ukupna_vrednost = ukupna_vrednost_;
    }

    Inventar(const Inventar& inventar) {

        broj_tehnike = inventar.broj_tehnike;
        broj_vozila = inventar.broj_vozila;
        vozila = inventar.vozila;
        tehnika = inventar.tehnika;
        ukupna_vrednost = inventar.ukupna_vrednost;
    }

    int getBrojTehnike()const {
        return broj_tehnike;
    }

    int getBrojVozila()const {
        return broj_vozila;
    }

    std::list<Vozilo> getListaVozila()const {
        return vozila;
    }

    std::list<Tehnika> getListaTehnike()const {
        return tehnika;
    }

    float getUkupnaVrednost()const {
        return ukupna_vrednost;
    }

    Tehnika* getTehnika(int koji) {
        koji--;
        if (koji > broj_tehnike) {

        }
        else {
            std::list<Tehnika>::iterator it = tehnika.begin();
            for (int i = 0; i < koji; i++, it++);

            return &(*it);
        }
    }

    Vozilo* getVozilo(int koji) {
        koji--;
        if (koji > broj_vozila) {

        }
        else {
            std::list<Vozilo>::iterator it = vozila.begin();
            for (int i = 0; i < koji; i++, it++);

            return &(*it);
        }
    }

    void setBrojTehnike(int broj_tehnike_) {
        broj_tehnike = broj_tehnike_;
    }

    void setBrojVozila(int broj_vozila_) {
        broj_vozila = broj_vozila_;
    }

    void setListaVozila(std::list<Vozilo> vozila_) {
        vozila = vozila_;
    }

    void setListaTehnike(std::list<Tehnika> tehnika_) {
        tehnika = tehnika_;
    }

    void setUkupnaVrednost(float ukupna_vrednost_) {
        ukupna_vrednost = ukupna_vrednost_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Inventar& inventar) {
        out << std::endl << "INVENTAR : " << std::endl;
        out << "Broj tehnike : " << inventar.broj_tehnike << std::endl;
        out << "Broj vozila : " << inventar.broj_vozila << std::endl;
        out << "Lista vozila : " << std::endl;
        std::list<Vozilo>::const_iterator it = inventar.vozila.begin();
        for (int i = 0; i < inventar.broj_vozila; i++, it++) {
            out << *it << std::endl;
        }
        out << "Lista tehnike : " << std::endl;
        std::list<Tehnika>::const_iterator it2 = inventar.tehnika.begin();
        for (int i = 0; i < inventar.broj_tehnike; i++, it2++) {
            out << *it2 << std::endl;
        }
        out << "Ukupna vrednost : " << inventar.ukupna_vrednost << std::endl;

        return out;
    }
};


class Prodavnica {
private:
    char naziv[50];
    char lokacija[50];
    char pocetak_rada[40];
    char pocetak_rada_vikendom[40];
    char kraj_rada[40];
    char kraj_rada_vikendom[40];
    bool radi;
    int broj_potrosaca_u_prodavnici;
    int broj_nabavka;
    std::list<Nabavka> lista_nabavka;
    std::list<Potrosac> lista_potrosaca;
    Smena smena[3];// tri smene
    Kasa kasa;
    Inventar inv;
    Magacin magacin;
    Vlasnik_Prodavnice vlasnik;
public:
    Prodavnica() {
        strcpy_s(naziv, "Univer");
        strcpy_s(lokacija, "ulica Banovica Strahinje 20");
        strcpy_s(pocetak_rada, "07:30");
        strcpy_s(pocetak_rada_vikendom, "07:30");
        strcpy_s(kraj_rada, "20:30");
        strcpy_s(kraj_rada_vikendom, "12:30");
        radi = true;
        broj_potrosaca_u_prodavnici = 2;
        lista_potrosaca.push_back(Potrosac());
        lista_potrosaca.push_back(Potrosac());
        smena[0] = Smena();
        smena[0].setVremeKraja((char*)"12:30");
        smena[0].setVremeKrajaVikendom((char*)"09:00");
        smena[1] = Smena();
        smena[1].setVremePocetka((char*)"12:30");
        smena[1].setVremePocetkaVikendom((char*)"09:00");
        smena[1].setVremeKraja((char*)"16:30");
        smena[1].setVremeKrajaVikendom((char*)"10:30");
        smena[2] = Smena();
        smena[2].setVremePocetka((char*)"16:30");
        smena[2].setVremePocetkaVikendom((char*)"10:30");
        smena[2].setVremeKraja((char*)"20:30");
        smena[2].setVremeKrajaVikendom((char*)"12:30");
        broj_nabavka = 2;
        lista_nabavka.push_back(Nabavka());
        lista_nabavka.push_back(Nabavka());
        kasa = Kasa();
        inv = Inventar();
        magacin = Magacin();
        vlasnik = Vlasnik_Prodavnice();
    }
    Prodavnica(char* naziv_, char* lokacija_, char* pocetak_rada_, char* pocetak_rada_vikendom_, char* kraj_rada_, char* kraj_rada_vikendom_, int broj_nabavka_, std::list<Nabavka> lista_nabavka_, bool radi_, int broj_potrosaca_u_prodavnici_, std::list<Potrosac> lista_potrosaca_, Smena smena1_, Smena smena2_, Smena smena3_, Kasa kasa_, Inventar inv_, Magacin magacin_, Vlasnik_Prodavnice vlasnik_) {
        strcpy_s(naziv, naziv_);
        strcpy_s(lokacija, lokacija_);
        strcpy_s(pocetak_rada, pocetak_rada_);
        strcpy_s(pocetak_rada_vikendom, pocetak_rada_vikendom_);
        strcpy_s(kraj_rada, kraj_rada_);
        strcpy_s(kraj_rada_vikendom, kraj_rada_vikendom_);
        radi = radi_;
        broj_nabavka = broj_nabavka_;
        lista_nabavka = lista_nabavka_;
        broj_potrosaca_u_prodavnici = broj_potrosaca_u_prodavnici_;
        lista_potrosaca = lista_potrosaca_;
        smena[0] = Smena(smena1_);
        smena[1] = Smena(smena2_);
        smena[2] = Smena(smena3_);
        kasa = Kasa(kasa_);
        inv = Inventar(inv_);
        magacin = Magacin(magacin_);
        vlasnik = Vlasnik_Prodavnice(vlasnik_);
    }
    Prodavnica(const Prodavnica& p) {
        strcpy_s(naziv, p.naziv);
        strcpy_s(lokacija, p.lokacija);
        strcpy_s(pocetak_rada, p.pocetak_rada);
        strcpy_s(pocetak_rada_vikendom, p.pocetak_rada_vikendom);
        strcpy_s(kraj_rada, p.kraj_rada);
        strcpy_s(kraj_rada_vikendom, p.kraj_rada_vikendom);
        radi = p.radi;
        broj_potrosaca_u_prodavnici = p.broj_potrosaca_u_prodavnici;
        lista_potrosaca = p.lista_potrosaca;
        broj_nabavka = p.broj_nabavka;
        lista_nabavka = p.lista_nabavka;
        smena[0] = Smena(p.smena[0]);
        smena[1] = Smena(p.smena[1]);
        smena[2] = Smena(p.smena[2]);
        kasa = Kasa(p.kasa);
        inv = Inventar(p.inv);
        magacin = Magacin(p.magacin);
        vlasnik = Vlasnik_Prodavnice(p.vlasnik);
    }
    char* getNaziv() {
        return naziv;
    }
    char* getLokacija() {
        return lokacija;
    }
    char* getPocetakRada() {
        return pocetak_rada;
    }
    char* getPocetakRadaVikendom() {
        return pocetak_rada_vikendom;
    }
    char* getKrajRada() {
        return kraj_rada;
    }
    char* getKrajRadaVikendom() {
        return kraj_rada_vikendom;
    }
    bool getRadi() {
        return radi;
    }
    int getBrojNabavka() {
        return broj_nabavka;
    }
    std::list<Nabavka> getListaNabavka() {
        return lista_nabavka;
    }
    Nabavka* getNabavka(int koji) {
        koji--;
        if (koji > broj_nabavka) {

        }
        else {
            std::list<Nabavka>::iterator it = lista_nabavka.begin();
            for (int i = 0; i < koji; i++, it++);

            return &(*it);
        }
    }
    int getBrojPotrosaca() {
        return broj_potrosaca_u_prodavnici;
    }
    std::list<Potrosac> getListaPotrosaca(){
        return lista_potrosaca;
    }
    Potrosac* getPotrosac(int koji) {
        koji--;
        if (koji > broj_potrosaca_u_prodavnici) {

        }
        else {
            std::list<Potrosac>::iterator it = lista_potrosaca.begin();
            for (int i = 0; i < koji; i++, it++);

            return &(*it);
        }
    }

    Smena* getSmena1() {
        return &smena[0];
    }
    Smena* getSmena2() {
        return &smena[1];
    }
    Smena* getSmena3() {
        return &smena[2];
    }
    Kasa* getKasa() {
        return &kasa;
    }
    Inventar* getInventar() {
        return &inv;
    }
    Magacin* getMagacin() {
        return &magacin;
    }
    Vlasnik_Prodavnice* getVlasnik() {
        return &vlasnik;
    }


    void setNaziv(char* naziv_) {
        strcpy_s(naziv, naziv_);
        
    }
    void setLokacija(char* lokacija_) {
        strcpy_s(lokacija, lokacija_);
        
    }
    void setPocetakRada(char* pocetak_rada_) {
        strcpy_s(pocetak_rada, pocetak_rada_);
        
    }
    void setPocetakRadaVikendom(char* pocetak_rada_vikendom_) {
        strcpy_s(pocetak_rada_vikendom, pocetak_rada_vikendom_);
        
    }
    void setKrajRada(char* kraj_rada_) {
        strcpy_s(kraj_rada, kraj_rada_);
        
    }
    void setKrajRadaVikendom(char* kraj_rada_vikendom_) {
        strcpy_s(kraj_rada_vikendom, kraj_rada_vikendom_);
        
    }
    void setRadi(bool radi_) {
        radi = radi_;
        
    }
    void setBrojNabavka(int broj) {
        broj_nabavka = broj;

    }
    void setListaNabavka(std::list<Nabavka> lista) {
        lista_nabavka = lista;

    }
    void setBrojPotrosaca(int broj_potrosaca_u_prodavnici_) {
        broj_potrosaca_u_prodavnici = broj_potrosaca_u_prodavnici_;
        
    }
    void setListaPotrosaca(std::list<Potrosac> lista_potrosaca_) {
        lista_potrosaca = lista_potrosaca_;
        
    }
    void setSmena1(Smena smena1_ ) {
        smena[0] = Smena(smena1_);
        
    }
    void setSmena2(Smena smena2_) {
        smena[1] = Smena(smena2_);
        
    }
    void setSmena3(Smena smena3_) {
        smena[2] = Smena(smena3_);
        
    }
    void setKasa(Kasa kasa_) {
        kasa = Kasa(kasa_);
        
    }
    void setInventar(Inventar inv_ ) {
        inv = Inventar(inv_);
        
    }
    void setMagacin(Magacin magacin_ ) {
        magacin = Magacin(magacin_);
        
    }
    void setVlasnik(Vlasnik_Prodavnice vlasnik_) {
        vlasnik = Vlasnik_Prodavnice(vlasnik_);
    }


    friend std::ostream& operator<<(std::ostream& out, const Prodavnica& prodavnica) {
        out << std::endl << "PRODAVNICA : " << std::endl;
        out << "Naziv prodavnice : " << prodavnica.naziv << std::endl;
        out << "Lokacija prodavnice : " << prodavnica.lokacija << std::endl;
        out << "Pocetak rada radnim danima : " << prodavnica.pocetak_rada << std::endl;
        out << "Pocetak rada vikendom : " << prodavnica.pocetak_rada_vikendom << std::endl;
        out << "Kraj rada radnim danima : " << prodavnica.kraj_rada << std::endl;
        out << "Kraj rada vikendom : " << prodavnica.kraj_rada_vikendom << std::endl;
        out << "Da li prodavnica radi : ";
        if (prodavnica.radi) {
            out << "Da" << std::endl;
        }
        else
        {
            out << "Ne" << std::endl;
        }

        out << "Broj potrosaca u prodavnici : " << prodavnica.broj_potrosaca_u_prodavnici << std::endl;
        out << "Lista potrosaca u prodavnici: " << std::endl;
        std::list<Potrosac>::const_iterator it = prodavnica.lista_potrosaca.begin();
        for (int i = 0; i < prodavnica.broj_potrosaca_u_prodavnici; i++, it++) {
            out << *it << std::endl;
        }
        out << "Broj nabavka : " << prodavnica.broj_nabavka << std::endl;

        std::list<Nabavka>::const_iterator it2 = prodavnica.lista_nabavka.begin();
        for (int i = 0; i < prodavnica.broj_nabavka; i++, it2++) {
            out << *it2 << std::endl;
        }
            out << "Prva smena : " << std::endl;
            
        
        
        out << prodavnica.smena[0] << std::endl;
        out << "Druga smena : " << std::endl;
        out << prodavnica.smena[1] << std::endl;
        out << "Treca smena : " << std::endl;
        out << prodavnica.smena[2] << std::endl;
        out << prodavnica.kasa << std::endl;
        out  << std::endl;
        out << prodavnica.inv << std::endl;
        out <<  std::endl;
        out << prodavnica.magacin << std::endl;
        out << "Vlasnik prodavnice : " << std::endl;
        out << prodavnica.vlasnik << std::endl;

        return out;
    }
};



int main()
{
    Prodavnica p;
    std::list<Nabavka> listan;
    std::list<Artikal> listaa;
    std::list<Potrosac> listap;
    std::list<Radnik> listar;
    std::list<Racun> listaR;
    std::list<Vozilo> listav;
    std::list<Tehnika> listat;
    listaa.push_back(Artikal(0, 0, 0, 0, (char*)"test", (char*)"test", (char*)"test", (char*)"test", 0, 0, 0, 0, (char*)"test"));
    listan.push_back(Nabavka(0, 0, false, false, false, 1, listaa));
    Korpa k(0, 0, 0, 0, false, 1, 0, (stanje)1, listaa);
    listap.push_back(Potrosac((char*)"test", (char*)"test", 0, 0, 0, 0, 0, 0, Korpa(k)));
    listav.push_back(Vozilo((char*)"test", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    listat.push_back(Tehnika((char*)"test", (char*)"test",0,0,0,0,0,0,0,0,(energetska_klasa)0));
    listaR.push_back(Racun(1, 0, 0, 0, listaa));
    listar.push_back(Radnik((char*)"test", (char*)"test", 0, 0, 0, (pozicija)0, 0));
    Inventar i(1, 1, listav, listat, 0);
    Kasa ka(0,0,1,listaR);
    Smena smena1((char*)"test", (char*)"test", (char*)"test", (char*)"test",1,listar);
    Magacin m(1, 0, 0, 0, listaa);
    Prodavnica p2((char*)"test", (char*)"test", (char*)"test", (char*)"test", (char*)"test", (char*)"test", 1, listan, 0, 1, listap,Smena(smena1), Smena(smena1), Smena(smena1),Kasa(ka),i,m,Vlasnik_Prodavnice((char*)"test", (char*)"test",0,0,0,0,0,0,0));
    Prodavnica p1(p2);
    std::cout << p1;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu



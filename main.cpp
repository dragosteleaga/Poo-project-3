#include <iostream>
#include <list>
using namespace std;
class vietate {
protected:
    string ecosistem;

public:
    void deplasare();
    void respira();

    vietate();
    vietate(string ecosistem);
    vietate(const vietate &v);
    vietate &operator=(const vietate &v);

    friend istream &operator>>(istream &in, vietate &v);
    friend ostream &operator<<(ostream &out, const vietate &v);

    const string &getEcosistem() const;
    void setEcosistem(const string &ecosistem);

    ~vietate();
};
vietate::vietate() : ecosistem("Anonim") {}
vietate::vietate(string ecosistem) : ecosistem(ecosistem) {}
vietate::vietate(const vietate &v) : ecosistem(v.ecosistem) {}
vietate &vietate::operator=(const vietate &v) {
    if (this != &v) {
        this->ecosistem = v.ecosistem;
    }
    return *this;
}
istream &operator>>(istream &in, vietate &v) {
    cout << "\nCitire vietate...";

    cout << "\nEcosistem :\n1. Terestru\n2. Acvatic\n3. Amfibian\n";
    int comanda;
    cin >> comanda;
    switch (comanda) {
        case 1: {
            v.ecosistem = "terestru";
            break;
        }
        case 2: {
            v.ecosistem = "acvatic";
            break;
        }
        case 3: {
            v.ecosistem = "amfibian";
            break;
        }
        default: {
            cout << "\nAti introdus o varianta gresita !";

            break;
        }
    }
    return in;
}
ostream &operator<<(ostream &out, vietate &v) {
    cout << "\nVietatea traieste intr-un ecosistem : ";
    out << v.getEcosistem();
    return out;
}
const string &vietate::getEcosistem() const {
    return ecosistem;
}
void vietate::setEcosistem(const string &ecosistem) {
    vietate::ecosistem = ecosistem;
}
vietate::~vietate() {}
void vietate::deplasare() {
    cout << "\nS-a deplasat cu succes !";
}
void vietate::respira() {
    cout << "\nCe aer curat !";
}
class mamifer : public vietate {
    bool carnivor;

public:
    mamifer();
    mamifer(string ecosistem, bool carnivor);
    mamifer(const mamifer &m);
    mamifer &operator=(const mamifer &m);

    friend istream &operator>>(istream &in, mamifer &m);
    friend ostream &operator<<(ostream &out, const mamifer &m);

    void hranesteCopil();
    void mananca();
    void vaneaza();

    bool isCarnivor() const;
    void setCarnivor(bool carnivor);

    ~mamifer();
};
mamifer::mamifer() : vietate(), carnivor(0) {}
mamifer::mamifer(string ecosistem, bool carnivor) : vietate(ecosistem), carnivor(carnivor) {}
mamifer::mamifer(const mamifer &m) : vietate(m.ecosistem), carnivor(m.carnivor) {}
mamifer &mamifer::operator=(const mamifer &m) {
    if (this != &m) {
        vietate::operator=(m);
        this->carnivor = m.carnivor;
    }
    return *this;
}
istream &operator>>(istream &in, mamifer &m) {
    cout << "\nCitire mamifer...";

    cout << "\nEcosistem :\n1. Terestru\n2. Acvatic\n3. Amfibian\n";
    int comanda;
    cin >> comanda;
    switch (comanda) {
        case 1: {
            m.ecosistem = "terestru";
            break;
        }
        case 2: {
            m.ecosistem = "acvatic";
            break;
        }
        case 3: {
            m.ecosistem = "amfibian";
            break;
        }
        default: {
            cout << "\nAti introdus o varianta gresita !";
            break;
        } break;
    }

    cout << "\nEste carnivor \n1. Da\n2. Nu\n";
    int comanda1;
    cin >> comanda1;
    switch (comanda1) {
        case 1: {
            m.carnivor = 1;
            break;
        }
        case 2: {
            m.carnivor = 0;
            break;
        }
        default: {
            cout << "\nAti introdus o varianta gresita !";
            break;
        }
    }
    return in;
}
ostream &operator<<(ostream &out, const mamifer &m) {
    cout << "\nMamiferul traieste in ecosistemul " << m.ecosistem;
    if (m.carnivor)
        cout << " si este carnivor";
    else
        cout << " si nu este carnivor";
    return out;
}
void mamifer::hranesteCopil() {
    cout << "\nCopilul a fost hranit !";
}
void mamifer::mananca() {
    cout << "\n Mamiferul este satul";
}
void mamifer::vaneaza() {
    cout << "\nMamiferul a iesit la vanatoare";
}
mamifer::~mamifer() {}
bool mamifer::isCarnivor() const {
    return carnivor;
}
void mamifer::setCarnivor(bool carnivor) {
    this->carnivor = carnivor;
}
class caine : public mamifer {
protected:
    string rasa;
    bool aptPentruConcursuriCanine;

public:
    caine();
    caine(string ecosistem, bool carnivor, string rasa, bool aptPentruConcursuriCanine);
    caine(const caine &c);
    caine &operator=(const caine &c);
    friend ostream &operator<<(ostream &out, caine &c);
    friend istream &operator>>(istream &in, caine &c);

    bool isAptPentruConcursuriCanine() const;
    void setAptPentruConcursuriCanine(bool aptPentruConcursuriCanine);

    const string &getRasa() const;
    void setRasa(const string &rasa);

    void latra();
    void aleargaInJurulCozii();
    ~caine();
};
caine::caine() : mamifer("terestru", 1), rasa("Anonim"), aptPentruConcursuriCanine(0) {}
caine::caine(string ecosistem, bool carnivor, string rasa, bool aptPentruConcursuriCanine) : mamifer("terestru", 1), rasa(rasa), aptPentruConcursuriCanine(aptPentruConcursuriCanine) {}
caine::caine(const caine &c) : mamifer(c), rasa(c.rasa), aptPentruConcursuriCanine(c.aptPentruConcursuriCanine) {}
caine &caine::operator=(const caine &c) {
    if (this != &c) {
        mamifer::operator=(c);
        this->rasa = c.rasa;
        this->aptPentruConcursuriCanine = c.aptPentruConcursuriCanine;
    }
    return *this;
}
ostream &operator<<(ostream &out, caine &c) {
    out << "\nCainele cu rasa " << c.rasa << " traieste in ecosistemul " << c.ecosistem << " , este carnivor si ";
    if (c.aptPentruConcursuriCanine)
        cout << "este apt pentru concursuri canine !";
    else
        cout << "nu este apt pentru concursuri canine !";

    return out;
}
istream &operator>>(istream &in, caine &c) {
    cout << "\nCitirea cainelui ...";
    cout << "\nRasa :";
    in >> c.rasa;
    cout << "\nApt pentru concursuri canine [0/1]: ";
    in >> c.aptPentruConcursuriCanine;
    return in;
}
const string &caine::getRasa() const {
    return rasa;
}
void caine::setRasa(const string &rasa) {
    this->rasa = rasa;
}
bool caine::isAptPentruConcursuriCanine() const {
    return aptPentruConcursuriCanine;
}
void caine::setAptPentruConcursuriCanine(bool aptPentruConcursuriCanine) {
    this->aptPentruConcursuriCanine = aptPentruConcursuriCanine;
}
void caine::aleargaInJurulCozii() {
    cout << "\n Acest caine este fericit si alearga in jurul cozii !";
}
void caine::latra() {
    cout << "\nWOUF ! WOUF !";
}
caine::~caine() {}
class vaca : public mamifer {
protected:
    float raportGrasimeGreutate;
    bool bunaPentruLapte, bunaPentruCarne;

public:
    vaca();
    vaca(float raportGrasimeGreutate, bool bunaPentruLapte, bool bunaPentruCarne);
    vaca(const vaca &v);
    vaca &operator=(const vaca &v);


    friend istream &operator>>(istream &in, vaca &v);
    friend ostream &operator<<(ostream &out, const vaca &v);


    void pasca();
    void muu();

    float getraportGrasimeGreutate() const;
    void setraportGrasimeGreutate(float raportGrasimeGreutate);
    bool isBunaPentruLapte() const;
    void setBunaPentruLapte(bool bunaPentruLapte);
    bool isBunaPentruCarne() const;
    void setBunaPentruCarne(bool bunaPentruCarne);

    virtual ~vaca() {
    }
};
void vaca::pasca() {
    cout<<"\nVaca este fericita !";
}
void vaca::muu() {
    cout<<"\nMUUUU";
}
ostream &operator<<(ostream &out, const vaca &v){
    cout<<"\nVaca este un animal terestru ierbivor ";
    if(v.bunaPentruCarne)
        cout<<" buna pentru carne ";
    if(v.bunaPentruLapte)
        cout<<" buna pentru lapte ";
    cout<<"cu raportul grasime greutate = "<<v.raportGrasimeGreutate;

        return out;
}
istream &operator>>(istream &in, vaca &v) {
    cout << "\nCitim vaca...";
    cout << "\nRaport grasime greutate :";
    in >> v.raportGrasimeGreutate;
    cout << "\nBuna pentru lapte [0/1] :";
    in >> v.bunaPentruLapte;
    cout << "\nBuna pentru carne [0/1] :";
    in >> v.bunaPentruCarne;
    return in;
}
vaca::vaca() : mamifer("terestru", 0), raportGrasimeGreutate(0), bunaPentruCarne(0), bunaPentruLapte(0) {}
vaca::vaca(const vaca &v) : mamifer(v), raportGrasimeGreutate(v.raportGrasimeGreutate), bunaPentruLapte(v.bunaPentruLapte), bunaPentruCarne(v.bunaPentruCarne) {}
vaca &vaca::operator=(const vaca &v) {
    if (this != &v) {
        mamifer::operator=(v);
        this->bunaPentruCarne = v.bunaPentruCarne;
        this->bunaPentruLapte = v.bunaPentruLapte;
        this->raportGrasimeGreutate = v.raportGrasimeGreutate;
    }
    return *this;
}
float vaca::getraportGrasimeGreutate() const {
    return raportGrasimeGreutate;
}
void vaca::setraportGrasimeGreutate(float raportGrasimeGreutate) {
    vaca::raportGrasimeGreutate = raportGrasimeGreutate;
}
bool vaca::isBunaPentruLapte() const {
    return bunaPentruLapte;
}
void vaca::setBunaPentruLapte(bool bunaPentruLapte) {
    vaca::bunaPentruLapte = bunaPentruLapte;
}
bool vaca::isBunaPentruCarne() const {
    return bunaPentruCarne;
}
void vaca::setBunaPentruCarne(bool bunaPentruCarne) {
    vaca::bunaPentruCarne = bunaPentruCarne;
}
vaca::vaca(float raportGrasimeGreutate, bool bunaPentruLapte, bool bunaPentruCarne) : mamifer("terestru", 0), raportGrasimeGreutate(raportGrasimeGreutate), bunaPentruLapte(bunaPentruLapte), bunaPentruCarne(bunaPentruCarne) {}
class pisica : public mamifer {
protected:
    string rasa;
    bool concursFrumusete;

public:
    pisica();
    pisica(const string &ecosistem, bool carnivor, const string &rasa, bool concursFrumusete);
    pisica(const pisica &p);
    pisica &operator=(const pisica &p);

    friend istream &operator>>(istream &in, pisica &p);
    friend ostream &operator<<(ostream &out, const pisica &p);


    const string &getRasa() const;
    void setRasa(const string &rasa);
    bool isConcursFrumusete() const;
    void setConcursFrumusete(bool concursFrumusete);
    void miau();
    virtual ~pisica();
};
void pisica::miau() {
    cout << "MIAU!";
}
istream &operator>>(istream &in, pisica &p) {
    cout << "\nCitire pisica ...";
    cout << "\nRasa : ";
    in >> p.rasa;
    cout << "\nA participat la concusuri de frumusete [0/1] :";
    in >> p.concursFrumusete;
    return in;
}
ostream &operator<<(ostream &out, const pisica &p) {
    cout << "Pisica e un mamifer terestru , carnivor de rasa " << p.rasa << "." << endl;
    if (p.concursFrumusete)
        cout << "A participat la concursuri de frumusete !";
    return out;
}

pisica::pisica() : mamifer("terestru", 1), concursFrumusete(0), rasa("Anonima") {}
pisica::pisica(const pisica &p) : mamifer(p), concursFrumusete(p.concursFrumusete), rasa(p.rasa) {}
pisica &pisica::operator=(const pisica &p) {
    if (this != &p) {
        mamifer::operator=(p);
        this->concursFrumusete = p.concursFrumusete;
        this->rasa = p.rasa;
    }
    return *this;
}
const string &pisica::getRasa() const {
    return rasa;
}
void pisica::setRasa(const string &rasa) {
    pisica::rasa = rasa;
}
bool pisica::isConcursFrumusete() const {
    return concursFrumusete;
}
void pisica::setConcursFrumusete(bool concursFrumusete) {
    pisica::concursFrumusete = concursFrumusete;
}
pisica::~pisica() {
}
pisica::pisica(const string &ecosistem, bool carnivor, const string &rasa, bool concursFrumusete) : mamifer("terestru", 1), rasa(rasa), concursFrumusete(concursFrumusete) {}
class cal : public mamifer {
protected:
    bool armasar, aptPentruCompetitie, copiteleAranjate;
    string rasa;

public:
    cal();
    cal(const string &ecosistem, bool carnivor, bool armasar, bool aptPentruCompetitie, bool copiteleAranjate, const string &rasa);
    cal(const cal &c);
    cal &operator=(const cal &c);


    bool isArmasar() const;
    void setArmasar(bool armasar);
    bool isAptPentruCompetitie() const;
    void setAptPentruCompetitie(bool aptPentruCompetitie);
    bool isCopiteleAranjate() const;
    void setCopiteleAranjate(bool copiteleAranjate);
    const string &getRasa() const;
    void setRasa(const string &rasa);

    friend istream &operator>>(istream &in, cal &c);
    friend ostream &operator<<(ostream &out, const cal &c);


    void mancaMorcov();

    virtual ~cal();
};
void cal::mancaMorcov() {
    cout << "\nCalul iti multumeste !";
}
istream &operator>>(istream &in, cal &c) {
    cout << "\nCitire cal...";
    cout << "\nArmasar[0/1] :";
    in >> c.armasar;
    cout << "\nApt pentru competitie [0/1] :";
    in >> c.aptPentruCompetitie;
    cout << "\nRasa :";
    in >> c.rasa;
    cout << "\nCopite aranjate [0/1] :";
    in >> c.copiteleAranjate;
    return in;
}
ostream &operator<<(ostream &out, const cal &c) {
    out << "Calul este un mamifer terestru ierbivor ,";
    if (c.isArmasar())
        out << " armasar ";
    out << "de rasa " << c.getRasa();
    if (c.isCopiteleAranjate())
        out << " cu copite aranjate ";
    cout << endl;
    if (c.isAptPentruCompetitie())
        cout << "si apt pentru competitie fizica !";
    else
        cout << "si nu e apt pentru competitie fizica !";

    return out;
}


bool cal::isArmasar() const {
    return armasar;
}
void cal::setArmasar(bool armasar) {
    cal::armasar = armasar;
}
bool cal::isAptPentruCompetitie() const {
    return aptPentruCompetitie;
}
void cal::setAptPentruCompetitie(bool aptPentruCompetitie) {
    cal::aptPentruCompetitie = aptPentruCompetitie;
}
bool cal::isCopiteleAranjate() const {
    return copiteleAranjate;
}
void cal::setCopiteleAranjate(bool copiteleAranjate) {
    cal::copiteleAranjate = copiteleAranjate;
}
const string &cal::getRasa() const {
    return rasa;
}
void cal::setRasa(const string &rasa) {
    cal::rasa = rasa;
}
cal::cal(const string &ecosistem, bool carnivor, bool armasar, bool aptPentruCompetitie, bool copiteleAranjate, const string &rasa) : mamifer("terestru", 0), armasar(armasar), aptPentruCompetitie(aptPentruCompetitie), copiteleAranjate(copiteleAranjate), rasa(rasa) {}
cal::~cal() {
}
cal::cal() : mamifer("terestru", 0), armasar(0), aptPentruCompetitie(0), rasa("Anonima"), copiteleAranjate(0) {}
cal::cal(const cal &c) : mamifer(c), aptPentruCompetitie(c.aptPentruCompetitie), rasa(c.rasa), armasar(c.armasar), copiteleAranjate(c.copiteleAranjate) {}
cal &cal::operator=(const cal &c) {
    if (this != &c) {
        mamifer::operator=(c);
        this->rasa = c.rasa;
        this->armasar = c.armasar;
        this->aptPentruCompetitie = c.aptPentruCompetitie;
        this->copiteleAranjate = c.copiteleAranjate;
    }
    return *this;
}
class delfin : public mamifer {
protected:
    bool mascul, dresat;

public:
    void danseaza();
    delfin();
    delfin(const string &ecosistem, bool carnivor, bool mascul, bool dresat);
    delfin(const delfin &d);
    delfin &operator=(const delfin &d);
    friend istream &operator>>(istream &in, delfin &d);
    friend ostream &operator<(ostream & out, const delfin &d);

    bool isMascul() const;
    void setMascul(bool mascul);
    bool isDresat() const;
    void setDresat(bool dresat);

    ~delfin();
};
void delfin::danseaza() {
    cout << "Delfinul danseaza !";
}
delfin::delfin() : mamifer("acvatic", 1), mascul(0), dresat(0) {}
delfin::delfin(const string &ecosistem, bool carnivor, bool mascul, bool dresat) : mamifer("acvatic", 1), mascul(mascul), dresat(dresat) {}
delfin::delfin(const delfin &d) : mamifer(d), mascul(d.mascul), dresat(d.dresat) {}
istream &operator>>(istream &in, delfin &d) {
    cout << "\nCitire delfin ...";
    cout << "\nMascul [0/1] :";
    in >> d.mascul;
    cout << "\nDresat[0/1] :";
    in >> d.dresat;
    return in;
}
ostream &operator<<(ostream &out, delfin &d) {
    cout << "Delfinul este un ";
    if (d.isMascul())
        cout << "mascul";
    else
        cout << "femela";
    cout << " acvatic ";
    if (d.isDresat())
        cout << "dresat !";
    return out;
}
delfin &delfin::operator=(const delfin &d) {
    if (this != &d) {
        mamifer::operator=(d);
        this->dresat = d.dresat;
        this->mascul = d.mascul;
    }
    return *this;
}
bool delfin::isMascul() const {
    return mascul;
}
void delfin::setMascul(bool mascul) {
    delfin::mascul = mascul;
}
bool delfin::isDresat() const {
    return dresat;
}
void delfin::setDresat(bool dresat) {
    delfin::dresat = dresat;
}

delfin::~delfin() {}
class ornitorinc : public mamifer {
protected:
    bool veninPuternic, electroLocatie;
    string rasa;

public:
    ornitorinc();
    ornitorinc(const string &ecosistem, bool carnivor, bool veninPuternic, bool electroLocatie, const string &rasa);
    ornitorinc(const ornitorinc &o);
    ornitorinc &operator=(const ornitorinc &o);

    friend ostream &operator<<(ostream &out, const ornitorinc &o);
    friend istream &operator>>(istream &in, ornitorinc &o);

    bool isVeninPuternic() const;
    void setVeninPuternic(bool veninPuternic);
    bool isElectroLocatie() const;
    void setElectroLocatie(bool electroLocatie);
    const string &getRasa() const;
    void setRasa(const string &rasa);
    void camuflareInApa();
};
ornitorinc::ornitorinc(const string &ecosistem, bool carnivor, bool veninPuternic, bool electroLocatie, const string &rasa) : mamifer("amfibian", 1), veninPuternic(veninPuternic), electroLocatie(electroLocatie), rasa(rasa) {}
ornitorinc::ornitorinc() : mamifer("amfibian", 1), rasa("Anonim"), electroLocatie(0), veninPuternic(0) {}
ornitorinc::ornitorinc(const ornitorinc &o) : mamifer(o), veninPuternic(o.veninPuternic), electroLocatie(o.electroLocatie), rasa(o.rasa) {}
ornitorinc &ornitorinc::operator=(const ornitorinc &o) {
    if (this != &o) {
        mamifer::operator=(o);
        this->rasa = o.rasa;
        this->electroLocatie = o.electroLocatie;
        this->veninPuternic = o.veninPuternic;
    }
    return *this;
}
istream &operator>>(istream &in, ornitorinc &o) {
    cout << "\nCitirea ornitorincului ...";
    cout << "\nVenin puternic [0/1]:";
    in >> o.veninPuternic;
    cout << "\nElectrolocatie[0/1]:";
    in >> o.electroLocatie;
    cout << "\nRasa :";
    in >> o.rasa;
    return in;
}
ostream &operator<<(ostream &out, const ornitorinc &o) {
    out << "\nOrnitorincul cu rasa " << o.rasa;
    if (o.veninPuternic)
        cout << " si cu venin puternic ";
    else
        cout << " si cu venin ";
    cout << "este " << o.ecosistem;
    if (o.isCarnivor())
        cout << " , carnivor ";
    else
        cout << " , nu e carnivor ";
    cout << " si ";
    if (o.electroLocatie)
        cout << "are electrolocatie !";
    else
        cout << "nu are electrolocatie !";
    return out;
}
bool ornitorinc::isVeninPuternic() const {
    return veninPuternic;
}
void ornitorinc::setVeninPuternic(bool veninPuternic) {
    ornitorinc::veninPuternic = veninPuternic;
}
bool ornitorinc::isElectroLocatie() const {
    return electroLocatie;
}
void ornitorinc::setElectroLocatie(bool electroLocatie) {
    ornitorinc::electroLocatie = electroLocatie;
}
const string &ornitorinc::getRasa() const {
    return rasa;
}
void ornitorinc::setRasa(const string &rasa) {
    ornitorinc::rasa = rasa;
}


template<typename T>
class cabinetVeterinar {
private:
    string numeBoala;
    float costProceduri;


public:
    cabinetVeterinar();
    cabinetVeterinar(string numeBoala, float costProceduri);
    cabinetVeterinar(const cabinetVeterinar<T> &c);
    cabinetVeterinar &operator=(const cabinetVeterinar<T> &c);


    const string &getNumeBoala() const;
    void setNumeBoala(const string &numeBoala);
    float getCostProceduri() const;
    void setCostProceduri(float costProceduri);

    void vindecaBoala();
    void adaugareListaPacienti();
    template<typename U>
    friend ostream &operator<<(ostream &out, const cabinetVeterinar<U> &classObj);
    template<typename U>
    friend istream &operator>>(istream &in, cabinetVeterinar<U> &classObj);


    virtual ~cabinetVeterinar();
};
//costructori si =
template<typename T>
cabinetVeterinar<T>::cabinetVeterinar() : numeBoala("Anonim"), costProceduri(0) {}
template<typename T>
cabinetVeterinar<T>::cabinetVeterinar(string numeBoala, float costProceduri) : numeBoala(numeBoala), costProceduri(costProceduri) {}
template<typename T>
cabinetVeterinar<T>::cabinetVeterinar(const cabinetVeterinar<T> &c) : numeBoala(c.numeBoala), costProceduri(c.costProceduri) {}
template<typename T>
cabinetVeterinar<T> &cabinetVeterinar<T>::operator=(const cabinetVeterinar<T> &c) {
    if (this != &c) {
        this->numeBoala = c.numeBoala;
        this->costProceduri = c.costProceduri;
    }
    return *this;
}


//setteri si getter
template<typename T>
const string &cabinetVeterinar<T>::getNumeBoala() const {
    return numeBoala;
}
template<typename T>
void cabinetVeterinar<T>::setNumeBoala(const string &numeBoala) {
    cabinetVeterinar::numeBoala = numeBoala;
}
template<typename T>
float cabinetVeterinar<T>::getCostProceduri() const {
    return costProceduri;
}
template<typename T>
void cabinetVeterinar<T>::setCostProceduri(float costProceduri) {
    cabinetVeterinar::costProceduri = costProceduri;
}

//deconstructor
template<typename T>
cabinetVeterinar<T>::~cabinetVeterinar() {
}
//IO
template<typename U>
ostream &operator<<(ostream &out, const cabinetVeterinar<U> &classObj) {
    out << "\nCost proceduri :" << classObj.costProceduri << "\nNume boala :" << classObj.numeBoala;
    return out;
}
template<typename U>
istream &operator>>(istream &in, cabinetVeterinar<U> &classObj) {
    cout << "\nNume boala :";
    in >> classObj.numeBoala;
    cout << "\nCost proceduri :";
    in >> classObj.costProceduri;
    return in;
}

//metode
template<typename T>
void cabinetVeterinar<T>::adaugareListaPacienti() {
    cout << "\nPacient adaugat in lista !";
}
template<typename T>
void cabinetVeterinar<T>::vindecaBoala() {
    cout << "\nBoala vindecata !";
}
int main() {
    vaca d;
    cin >> d;
    cout << d;


    return 0;
}
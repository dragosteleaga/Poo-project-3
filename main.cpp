#include <exception>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <stdexcept>
#include <vector>
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

    virtual ~mamifer();
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

bool mamifer::isCarnivor() const {
    return carnivor;
}
void mamifer::setCarnivor(bool carnivor) {
    this->carnivor = carnivor;
}
mamifer::~mamifer() {
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
    string rasa;

public:
    vaca();
    vaca(float raportGrasimeGreutate, bool bunaPentruLapte, bool bunaPentruCarne, string rasa);
    vaca(const vaca &v);
    vaca &operator=(const vaca &v);


    friend istream &operator>>(istream &in, vaca &v);
    friend ostream &operator<<(ostream &out, const vaca &v);


    void pasca();
    void muu();
    const string &getRasa() const;
    void setRasa(const string &rasa);
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
    cout << "\nVaca este fericita !";
}
void vaca::muu() {
    cout << "\nMUUUU";
}
ostream &operator<<(ostream &out, const vaca &v) {
    cout << "\nVaca este un animal terestru ierbivor ";
    if (v.bunaPentruCarne)
        cout << " buna pentru carne ";
    if (v.bunaPentruLapte)
        cout << " buna pentru lapte ";
    cout << "cu raportul grasime greutate = " << v.raportGrasimeGreutate;

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
vaca::vaca() : mamifer("terestru", 0), raportGrasimeGreutate(0), bunaPentruCarne(0), bunaPentruLapte(0), rasa("Anonim") {}
vaca::vaca(const vaca &v) : mamifer(v), raportGrasimeGreutate(v.raportGrasimeGreutate), bunaPentruLapte(v.bunaPentruLapte), bunaPentruCarne(v.bunaPentruCarne), rasa(v.rasa) {}
vaca &vaca::operator=(const vaca &v) {
    if (this != &v) {
        mamifer::operator=(v);
        this->bunaPentruCarne = v.bunaPentruCarne;
        this->bunaPentruLapte = v.bunaPentruLapte;
        this->raportGrasimeGreutate = v.raportGrasimeGreutate;
        this->rasa = v.rasa;
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
const string &vaca::getRasa() const {
    return rasa;
}
void vaca::setRasa(const string &rasa) {
    vaca::rasa = rasa;
}
vaca::vaca(float raportGrasimeGreutate, bool bunaPentruLapte, bool bunaPentruCarne, string rasa) : mamifer("terestru", 0), raportGrasimeGreutate(raportGrasimeGreutate), bunaPentruLapte(bunaPentruLapte), bunaPentruCarne(bunaPentruCarne), rasa(rasa) {}
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
    string rasa;

public:
    void danseaza();
    delfin();
    delfin(const string &ecosistem, bool carnivor, bool mascul, bool dresat, string rasa);
    delfin(const delfin &d);
    delfin &operator=(const delfin &d);
    friend istream &operator>>(istream &in, delfin &d);
    friend ostream &operator<(ostream & out, const delfin &d);

    const string &getRasa() const;
    void setRasa(const string &rasa);
    bool isMascul() const;
    void setMascul(bool mascul);
    bool isDresat() const;
    void setDresat(bool dresat);

    ~delfin();
};
void delfin::danseaza() {
    cout << "Delfinul danseaza !";
}
delfin::delfin() : mamifer("acvatic", 1), mascul(0), dresat(0), rasa("Anonim") {}
delfin::delfin(const string &ecosistem, bool carnivor, bool mascul, bool dresat, string rasa) : mamifer("acvatic", 1), mascul(mascul), dresat(dresat), rasa(rasa) {}
delfin::delfin(const delfin &d) : mamifer(d), mascul(d.mascul), dresat(d.dresat), rasa(d.rasa) {}
istream &operator>>(istream &in, delfin &d) {
    cout << "\nCitire delfin ...";
    cout << "\nMascul [0/1] :";
    in >> d.mascul;
    cout << "\nDresat[0/1] :";
    in >> d.dresat;
    cout << "\nRasa :";
    in >> d.rasa;
    return in;
}
ostream &operator<<(ostream &out, delfin &d) {
    cout << "Delfinul de rasa " << d.getRasa() << " este un ";
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
        this->rasa = d.rasa;
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
const string &delfin::getRasa() const {
    return rasa;
}
void delfin::setRasa(const string &rasa) {
    delfin::rasa = rasa;
}
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
void ornitorinc::camuflareInApa() {
    cout << "\nOrnitorincul este ascuns acum !";
}
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

class ExceptiaMea : public exception {
public:
    virtual const char *what() const throw() {

        return "Exceptia Mea";
    }


} exceptiaMea;

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
list<mamifer *> ierbivore;
set<string> raseCaini;
vector<caine> caini;
vector<vaca> vaci;
vector<pisica> pisici;
vector<cal> cai;
vector<delfin> delfini;
vector<ornitorinc> ornitorinci;
map<int, string> raseAnimale;
int numarRase = 0;


class meniuInteractiv {
private:
    static meniuInteractiv *obiect;
    meniuInteractiv() {}

public:
    static meniuInteractiv *getInstance() {
        if (!obiect)
            obiect = new meniuInteractiv();
        return obiect;
    }
    void meniu();
};
void meniuInteractiv::meniu() {
    int k = 1;
    while (k) {
        cout << "\n1. Adauga animal\n2. Afiseaza animal\n3. Actiuni animal\n4. Actualizeaza animal\n5. Sterge animal\n6. Adauga animal la veterinar \n7. Iesire\n";
        int comanda;
        cin >> comanda;
        switch (comanda) {
                //adauga
            case 1: {
                cout << "\nCe animal doriti sa adaugati ?\n1. Caine\n2. Vaca\n3. Pisica\n4. Cal\n5. Delfin\n6. Ornitorinc\n7. Intoarcere la meniu principal\n";
                int comanda1;
                cin >> comanda1;
                switch (comanda1) {
                    case 1: {
                        cout << "\nAti ales sa creati un caine !";
                        caine c;
                        cin >> c;
                        caini.push_back(c);
                        raseCaini.insert(c.getRasa());
                        raseAnimale.insert(pair<int, string>(numarRase, c.getRasa()));
                        numarRase++;
                        cout << "\nCaine creat cu succes !";
                        break;
                    }
                    case 2: {
                        cout << "\nAti ales sa creati o vaca !";
                        vaca c;
                        cin >> c;
                        vaci.push_back(c);
                        mamifer *c1 = new vaca();
                        c1 = &c;
                        ierbivore.push_back(c1);
                        raseAnimale.insert(pair<int, string>(numarRase, c.getRasa()));

                        numarRase++;
                        cout << "\nVaca creata cu succes !";
                        break;
                    }
                    case 3: {
                        cout << "\nAti ales sa creati o pisica !";
                        pisica c;
                        cin >> c;
                        pisici.push_back(c);
                        raseAnimale.insert(pair<int, string>(numarRase, c.getRasa()));
                        numarRase++;
                        cout << "\nPisic creata cu succes !";
                        break;
                    }
                    case 4: {
                        cout << "\nAti ales sa creati un cal !";
                        cal c;
                        cin >> c;
                        cai.push_back(c);
                        raseAnimale.insert(pair<int, string>(numarRase, c.getRasa()));


                        mamifer *c1 = new cal();
                        c1 = &c;
                        ierbivore.push_back(c1);
                        numarRase++;


                        cout << "\nCal creat cu succes !";
                        break;
                    }
                    case 5: {
                        cout << "\nAti ales sa creati un delfin !";
                        delfin c;
                        cin >> c;
                        delfini.push_back(c);
                        raseAnimale.insert(pair<int, string>(numarRase, c.getRasa()));
                        numarRase++;
                        cout << "\nDelfin creat cu succes !";
                        break;
                    }
                    case 6: {
                        cout << "\nAti ales sa creati un ornitorinc !";
                        ornitorinc c;
                        cin >> c;
                        ornitorinci.push_back(c);
                        raseAnimale.insert(pair<int, string>(numarRase, c.getRasa()));
                        numarRase++;
                        cout << "\nOrnitorinc creat cu succes !";
                        break;
                    }
                    case 7: {
                        break;
                    }
                    default: {
                        cout << "\nAti introdus o varianta gresita !";
                        break;
                    }
                }

                break;
            }
                //afisare
            case 2: {
                cout << "Ce doriti sa afisati ?\n1. Caine\n2. Vaca\n3. Pisica\n4. Cal\n5. Delfin\n6. Ornitorinc\n7. Afisati toate rasele de caini\n8. Afisati toate rasele create\n9. Afisati toate mamiferele ierbivore create\n10. Intoarcere la meniul principal\n";
                int comanda1;
                cin >> comanda1;
                switch (comanda1) {
                    case 1: {
                        try {
                            if (!caini.size())
                                throw exceptiaMea;
                            cout << "\nAti ales sa afisati un caine !\nCe caine doriti sa afisati ?\n";
                            for (int i = 0; i < caini.size(); i++)
                                cout << "\nCainele cu rasa " << i + 1 << ". " << caini[i].getRasa() << endl;
                            int y;
                            cin >> y;
                            cout << caini[y - 1];

                            cout << "\nCaine afisat cu succes !";
                        } catch (ExceptiaMea &e) {

                            cout << "\nNu exista niciun caine creat !";
                        }

                        break;
                    }
                    case 2: {
                        try {
                            if (!vaci.size())
                                throw exceptiaMea;
                            cout << "\nAti ales sa afisati o vaca !\nCe vaca doriti sa afisati ?\n";
                            for (int i = 0; i < caini.size(); i++)
                                cout << "\nVaca cu rasa " << i + 1 << ". " << vaci[i].getRasa() << endl;
                            int y;
                            cin >> y;
                            cout << vaci[y - 1];

                            cout << "\nVaca afisata cu succes !";
                        } catch (ExceptiaMea &e) {

                            cout << "\nNu exista nicio vaca creata !";
                        }

                        break;
                    }
                    case 3: {
                        try {
                            if (!pisici.size())
                                throw exceptiaMea;
                            cout << "\nAti ales sa afisati o pisica !\nCe pisica doriti sa afisati ?\n";
                            for (int i = 0; i < pisici.size(); i++)
                                cout << "\nPisica cu rasa " << i + 1 << ". " << pisici[i].getRasa() << endl;
                            int y;
                            cin >> y;
                            cout << pisici[y - 1];

                            cout << "\nPisica afisata cu succes !";
                        } catch (ExceptiaMea &e) {

                            cout << "\nNu exista nicio pisica creata !";
                        }

                        break;
                    }
                    case 4: {
                        try {
                            if (!cai.size())
                                throw exceptiaMea;
                            cout << "\nAti ales sa afisati un cal !\nCe cal doriti sa afisati ?\n";
                            for (int i = 0; i < cai.size(); i++)
                                cout << "\nCalul cu rasa " << i + 1 << ". " << cai[i].getRasa() << endl;
                            int y;
                            cin >> y;
                            cout << caini[y - 1];

                            cout << "\nCal afisat cu succes !";
                        } catch (ExceptiaMea &e) {

                            cout << "\nNu exista niciun cal creat !";
                        }
                        break;
                    }
                    case 5: {
                        try {
                            if (!delfini.size())
                                throw exceptiaMea;
                            cout << "\nAti ales sa afisati un delfin !\nCe delfin doriti sa afisati ?\n";
                            for (int i = 0; i < delfini.size(); i++)
                                cout << "\nDelfinul cu rasa " << i + 1 << ". " << delfini[i].getRasa() << endl;
                            int y;
                            cin >> y;
                            cout << delfini[y - 1];

                            cout << "\nDelfin afisat cu succes !";
                        } catch (ExceptiaMea &e) {

                            cout << "\nNu exista niciun delfin creat !";
                        }

                        break;
                    }
                    case 6: {
                        try {
                            if (!delfini.size())
                                throw exceptiaMea;
                            cout << "\nAti ales sa afisati un ornitorinc !\nCe ornitorinc doriti sa afisati ?\n";
                            for (int i = 0; i < ornitorinci.size(); i++)
                                cout << "\nOrnitorincul cu rasa " << i + 1 << ". " << ornitorinci[i].getRasa() << endl;
                            int y;
                            cin >> y;
                            cout << ornitorinci[y - 1];

                            cout << "\nOrnitorinc afisat cu succes !";
                        } catch (ExceptiaMea &e) {

                            cout << "\nNu exista niciun ornitorinc creat !";
                        }
                        break;
                    }
                    case 7: {
                        for (auto x: raseCaini)
                            cout << x << " ";


                        break;
                    };
                    case 8: {
                        for (auto x: raseAnimale)
                            cout << x.first + 1 << ". " << x.second << endl;
                        break;
                    }
                    case 9: {

                        for (auto x: ierbivore)
                            if (vaca *cal2 = dynamic_cast<vaca *>(x))
                                cout << cal2->getRasa();
                            else if (cal *cal2 = dynamic_cast<cal *>(x))
                                cout << cal2->getRasa();

                        break;
                    }
                    case 10: {
                        break;
                    }
                    default: {
                        cout << "\nAti introdus o varianta gresita !";
                        break;
                    }

                    break;
                }
            } break;
                //actiuni
            case 3: {
                cout << "Actiunile animalelor ...\n1. Animalele ierbivore\n2. Toate animalele\n";
                int comanda1;
                cin >> comanda1;
                switch (comanda1) {
                        //ierbivore
                    case 1: {
                        cout << "\nAti ales actiunile animalelor ierbivore !";
                        cout << "\nDoriti actiunile de la :\n1. Cal\n2. Vaca \n";
                        int k;
                        cin >> k;
                        switch (k) {
                            case 1: {
                                try {
                                    if (!cai.size())
                                        throw runtime_error("Nu exista cai");
                                    for (auto x: ierbivore)
                                        if (cal *cal2 = dynamic_cast<cal *>(x)) {
                                            cout << "\nCalul a mancat morcov!";
                                            cal2->mancaMorcov();
                                        }
                                } catch (...) {
                                    cout << "\nNu exista cai!";
                                }


                                break;
                            }
                            case 2: {
                                try {
                                    if (!vaci.size())
                                        throw runtime_error("Nu exista vaci");
                                    for (auto x: ierbivore)
                                        if (vaca *vaca2 = dynamic_cast<vaca *>(x)) {
                                            vaca2->muu();
                                        }
                                } catch (...) {
                                    cout << "\nNu exista vaci!";
                                }
                                break;
                            }
                            default: {
                                cout << "Ati intodus o varianta gresita !";
                                break;
                            }
                        }
                        break;
                    }
                        //toate animalele
                    case 2: {
                        cout << "\nLa ce animal doriti sa vedeti actiunile ?\n1. Caine\n2. Vaca\n3. Pisica\n4. Cal\n5. Delfin\n6. Ornitorinc\n7.Inapoi \n";
                        int k;
                        cin >> k;
                        switch (k) {
                            case 1: {
                                caine c;
                                c.latra();
                                break;
                            }
                            case 2: {
                                vaca v;
                                v.muu();
                                break;
                            }
                            case 3: {
                                pisica p;
                                p.miau();
                                break;
                            }
                            case 4: {
                                cal c;
                                c.mancaMorcov();
                                break;
                            }
                            case 5: {
                                delfin d;
                                d.danseaza();
                                break;
                            }
                            case 6: {
                                ornitorinc o;
                                o.camuflareInApa();
                                break;
                            }
                            case 7: {
                                break;
                            }
                            default: {
                                cout << "\nAti introdus o varianta gresita !";
                                break;
                            }
                        }
                        break;
                    }
                    default: {
                        cout << "Ati introdus o varianta gresita !";
                        break;
                    }
                }
                break;
            }
                //actualizare
            case 4: {
                cout << "\nLa ce animal doriti sa actualizati datele ?\n1. Caine\n2. Vaca\n3. Pisica\n4. Cal\n5. Delfin\n6. Ornitorinc\n7.Inapoi \n";
                int k;
                cin >> k;
                switch (k) {
                        //actualizre caine
                    case 1: {
                        cout << "\nLa ce caine doriti sa actualizati datele ?:\n";
                        for (int i = 0; i < caini.size(); i++)
                            cout << i + 1 << ". pentru cainele cu rasa " << caini[i].getRasa() << endl;
                        int k;
                        cin >> k;
                        cout << "\nCe doriti sa actualizati ?\n1. rasa\n2. Apt pentru concursuri canine\n3.Intoarcere la meniul principal\n";
                        int comanda3;
                        cin >> comanda3;
                        switch (comanda3) {
                            case 1: {
                                string rasa1;
                                cout << "\nRasa noua :";
                                cin >> rasa1;
                                caini[k - 1].setRasa(rasa1);
                                cout << "\nRasa actualizata cu succes !";
                                break;
                            }
                            case 2: {
                                caini[k - 1].setAptPentruConcursuriCanine(!caini[k - 1].isAptPentruConcursuriCanine());
                                cout << "\nActualizarea a avut succes !";
                                break;
                            }
                            case 3: {
                                break;
                            }
                            default: {
                                cout << "\nAti introdus o varianta gresita !";
                                break;
                            }
                        }

                        break;
                    }
                        //actualizare vaca
                    case 2: {
                        cout << "\nLa ce vaca doriti sa actualizati datele ?:\n";
                        for (int i = 0; i < vaci.size(); i++)
                            cout << i + 1 << ". pentru vaca cu rasa " << vaci[i].getRasa() << endl;
                        int k;
                        cin >> k;
                        cout << "\nCe doriti sa actualizati la vaca\n1. Buna pentru lapte\n2. Buna pentru carne\n3. rasa";
                        int comanda2;
                        cin >> comanda2;
                        switch (comanda2) {
                            case 1: {
                                vaci[k - 1].setBunaPentruLapte(!vaci[k - 1].isBunaPentruLapte());
                                cout << "\nActualizarea a avut succes !";
                                break;
                            }
                            case 2: {
                                vaci[k - 1].setBunaPentruCarne(!vaci[k - 1].isBunaPentruCarne());
                                cout << "\nActualizarea a avut succes !";
                                break;
                            }
                            case 3: {
                                string rasa1;
                                cout << "\nRasa noua : ";
                                cin >> rasa1;
                                vaci[k - 1].setRasa(rasa1);
                                cout << "\nActualizarea a avut succes !";
                                break;
                            }
                            default: {
                                break;
                            }
                        }

                        break;
                    }
                        //act pisica
                    case 3: {
                        cout << "\nLa ce pisica doriti sa actualizati datele ?:\n";
                        for (int i = 0; i < pisici.size(); i++)
                            cout << i + 1 << ". pentru pisica cu rasa " << pisici[i].getRasa() << endl;
                        int k;
                        cin >> k;
                        cout << "\nCe doriti sa actualizati ?\n1. rasa\n2. A fost la concursuri de frumusete \n3.Intoarcere la meniul principal\n";
                        int comanda3;
                        cin >> comanda3;
                        switch (comanda3) {
                            case 1: {
                                string rasa1;
                                cout << "\nRasa noua :";
                                cin >> rasa1;
                                pisici[k - 1].setRasa(rasa1);
                                cout << "\nRasa actualizata cu succes !";
                                break;
                            }
                            case 2: {
                                pisici[k - 1].setConcursFrumusete(!pisici[k - 1].isConcursFrumusete());
                                cout << "\nActualizarea a avut succes !";
                                break;
                            }
                            case 3: {
                                break;
                            }
                            default: {
                                cout << "\nAti introdus o varianta gresita !";
                                break;
                            }
                        }
                        break;
                    }
                    case 4: {
                        cout << "\nLa ce cal doriti sa actualizati datele ?:\n";
                        for (int i = 0; i < cai.size(); i++)
                            cout << i + 1 << ". pentru calul cu rasa " << cai[i].getRasa() << endl;
                        int k;
                        cin >> k;
                        cout << "\nCe doriti sa actualizati ?\n1. rasa\n2. Armasar\n3. Apt pentru competitie \n4. Copitele aranjate\n5.Intoarcere la meniul principal\n";
                        int comanda3;
                        cin >> comanda3;
                        switch (comanda3) {
                            case 1: {
                                string rasa1;
                                cout << "\nRasa noua :";
                                cin >> rasa1;
                                cai[k - 1].setRasa(rasa1);
                                cout << "\nRasa actualizata cu succes !";
                                break;
                            }
                            case 2: {
                                cai[k - 1].setArmasar(!cai[k - 1].isArmasar());
                                cout << "\nActualizarea a avut succes !";
                                break;
                            }
                            case 3: {
                                cai[k - 1].setAptPentruCompetitie(!cai[k - 1].isAptPentruCompetitie());
                                cout << "\nActualizarea a avut succes !";
                                break;
                            }

                            case 4: {
                                cai[k - 1].setCopiteleAranjate(!cai[k - 1].isCopiteleAranjate());
                                cout << "\nActualizarea a avut succes !";
                                break;
                            }
                            case 5: {
                                break;
                            }
                            default: {
                                cout << "\nAti introdus o varianta gresita !";
                                break;
                            }
                        }
                        break;
                    }
                    case 5: {
                        cout << "\nLa ce delfin doriti sa actualizati datele ?:\n";
                        for (int i = 0; i < delfini.size(); i++)
                            cout << i + 1 << ". pentru delfinul cu rasa " << delfini[i].getRasa() << endl;
                        int k;
                        cin >> k;
                        cout << "\nCe doriti sa actualizati ?\n1. rasa\n2. Mascul\n3. Dresat \n4. Intoarcere la meniul principal\n";
                        int comanda3;
                        cin >> comanda3;
                        switch (comanda3) {
                            case 1: {
                                string rasa1;
                                cout << "\nRasa noua :";
                                cin >> rasa1;
                                delfini[k - 1].setRasa(rasa1);
                                cout << "\nRasa actualizata cu succes !";
                                break;
                            }
                            case 2: {
                                delfini[k - 1].setMascul(!delfini[k - 1].isMascul());
                                cout << "\nActualizarea a avut succes !";
                                break;
                            }
                            case 3: {
                                delfini[k - 1].setDresat(!delfini[k - 1].isDresat());
                                cout << "\nActualizarea a avut succes !";
                                break;
                            }
                            case 4: {
                                break;
                            }
                            default: {
                                cout << "\nAti introdus o varianta gresita !";

                                break;
                            }
                        }
                        break;
                    }
                    case 6: {
                        cout << "\nLa ce ornitorinc doriti sa actualizati datele ?:\n";
                        for (int i = 0; i < ornitorinci.size(); i++)
                            cout << i + 1 << ". pentru ornitorincul cu rasa " << ornitorinci[i].getRasa() << endl;
                        int k;
                        cin >> k;
                        cout << "\nCe doriti sa actualizati ?\n1. rasa\n2. Venin puternic\n3. Electrolocatie\n4. Intoarcere la meniul principal\n";
                        int comanda3;
                        cin >> comanda3;
                        switch (comanda3) {
                            case 1: {
                                string rasa1;
                                cout << "\nRasa noua :";
                                cin >> rasa1;
                                ornitorinci[k - 1].setRasa(rasa1);
                                cout << "\nRasa actualizata cu succes !";
                                break;
                            }
                            case 2: {
                                ornitorinci[k - 1].setVeninPuternic(!ornitorinci[k - 1].isVeninPuternic());
                                cout << "\nActualizarea a avut succes !";
                                break;
                            }
                            case 3: {
                                ornitorinci[k - 1].setElectroLocatie(!ornitorinci[k - 1].isElectroLocatie());
                                cout << "\nActualizarea a avut succes !";
                                break;
                            }
                            case 4: {
                                break;
                            }
                            default: {
                                cout << "\nAti introdus o varianta gresita !";

                                break;
                            }
                        }
                        break;
                    }
                    case 7: {
                        break;
                    }
                    default: {
                        cout << "\nAti introdus o varianta gresita !";
                        break;
                    }
                }
                break;
            }
                //sterge
            case 5: {
                cout << "\nCe animal doriti sa stergeti ?\n1. Caine\n2. Vaca\n3. Pisica\n4. Cal\n5. Delfin\n6. Ornitorinc\n7. Intoarcere la meniul principal";
                int comand1;
                cin >> comand1;
                switch (comand1) {
                    case 1: {
                        try {
                            if (!caini.size())
                                throw exceptiaMea;
                            cout << "\nCe caine doriti sa stergeti ?\n";
                            for (int i = 0; i < caini.size(); i++)
                                cout << i + 1 << ". pentru cainile cu rasa " << caini[i].getRasa() << endl;
                            int k;
                            cin >> k;
                            caini.erase(caini.begin() + k - 1);
                            break;
                        } catch (ExceptiaMea &e) {

                            cout << "\nNu exista niciun caine creat !";
                        }
                        break;
                    }
                    case 2: {
                        try {
                            if (!vaci.size())
                                throw exceptiaMea;
                            cout << "\nCe vaca doriti sa stergeti ?\n";
                            for (int i = 0; i < vaci.size(); i++)
                                cout << i + 1 << ". pentru vaca cu rasa " << vaci[i].getRasa() << endl;
                            int k;
                            cin >> k;
                            vaci.erase(vaci.begin() + k - 1);
                            break;
                        } catch (ExceptiaMea &e) {

                            cout << "\nNu exista nicio vaca creata !";
                        }
                        break;
                    }
                    case 3: {
                        try {
                            if (!pisici.size())
                                throw exceptiaMea;
                            cout << "\nCe pisica doriti sa stergeti ?\n";
                            for (int i = 0; i < pisici.size(); i++)
                                cout << i + 1 << ". pentru pisica cu rasa " << pisici[i].getRasa() << endl;
                            int k;
                            cin >> k;
                            pisici.erase(pisici.begin() + k - 1);
                            break;
                        } catch (ExceptiaMea &e) {

                            cout << "\nNu exista nicio pisica creata !";
                        }
                        break;
                    }
                    case 4: {
                        try {
                            if (!cai.size())
                                throw exceptiaMea;
                            cout << "\nCe cal doriti sa stergeti ?\n";
                            for (int i = 0; i < cai.size(); i++)
                                cout << i + 1 << ". pentru calul cu rasa " << cai[i].getRasa() << endl;
                            int k;
                            cin >> k;
                            cai.erase(cai.begin() + k - 1);
                            break;
                        } catch (ExceptiaMea &e) {

                            cout << "\nNu exista niciun cal creat !";
                        }
                        break;
                    }
                    case 5: {
                        try {
                            if (!delfini.size())
                                throw exceptiaMea;
                            cout << "\nCe delfin doriti sa stergeti ?\n";
                            for (int i = 0; i < delfini.size(); i++)
                                cout << i + 1 << ". pentru delfinul cu rasa " << delfini[i].getRasa() << endl;
                            int k;
                            cin >> k;
                            delfini.erase(delfini.begin() + k - 1);
                            break;
                        } catch (ExceptiaMea &e) {

                            cout << "\nNu exista niciun delfin creat !";
                        }
                        break;
                    }
                    case 6: {
                        try {
                            if (!ornitorinci.size())
                                throw exceptiaMea;
                            cout << "\nCe ornitorinc doriti sa stergeti ?\n";
                            for (int i = 0; i < ornitorinci.size(); i++)
                                cout << i + 1 << ". pentru ornitorincul cu rasa " << ornitorinci[i].getRasa() << endl;
                            int k;
                            cin >> k;
                            ornitorinci.erase(ornitorinci.begin() + k - 1);
                            break;
                        } catch (ExceptiaMea &e) {

                            cout << "\nNu exista niciun ornitorinc creat !";
                        }
                        break;
                    }
                    case 7: {
                        break;
                    }
                    default: {
                        cout << "\nAti introdus o varianta gresita !";
                        break;
                    }
                }


                break;
            }
                //Adauga animal la veterinar
            case 6: {
                cout << "\nCe animal doriti sa duceti la veterinar ?\n1. Caine\n2. Vaca\n3. Pisica\n4. Cal\n5. Delfin\n6. Ornitorinc\n7.Inapoi \n";
                int k;
                cin >> k;
                switch (k) {
                    case 1: {
                        try {
                            if (!caini.size())
                                throw exceptiaMea;
                            caine c;
                            cabinetVeterinar<caine> cv;
                            cv.adaugareListaPacienti();
                            cv.vindecaBoala();
                        } catch (ExceptiaMea &e) {

                            cout << "\nNu exista niciun caine creat !";
                        }


                        break;
                    }
                    case 2: {
                        try {
                            if (!vaci.size())
                                throw exceptiaMea;
                            vaca c;
                            cabinetVeterinar<vaca> cv;
                            cv.adaugareListaPacienti();
                            cv.vindecaBoala();
                        } catch (ExceptiaMea &e) {

                            cout << "\nNu exista nicio vaca creata !";
                        }
                        break;
                    }

                    case 3: {


                        try {
                            if (!pisici.size())
                                throw exceptiaMea;
                            pisica c;
                            cabinetVeterinar<pisica> cv;
                            cv.adaugareListaPacienti();
                            cv.vindecaBoala();
                        } catch (ExceptiaMea &e) {

                            cout << "\nNu exista nicio pisica creata !";
                        }

                        break;
                    }
                    case 4: {


                        try {
                            if (!cai.size())
                                throw exceptiaMea;
                            cal c;
                            cabinetVeterinar<cal> cv;
                            cv.adaugareListaPacienti();
                            cv.vindecaBoala();
                            break;
                        } catch (ExceptiaMea &e) {

                            cout << "\nNu exista niciun cal creat !";
                        }

                        break;
                    }
                    case 5: {


                        try {
                            if (!delfini.size())
                                throw exceptiaMea;
                            delfin c;
                            cabinetVeterinar<delfin> cv;
                            cv.adaugareListaPacienti();
                            cv.vindecaBoala();
                            break;
                        } catch (ExceptiaMea &e) {

                            cout << "\nNu exista niciun delfin creat !";
                        }

                        break;
                    }
                    case 6: {
                        try {
                            if (!ornitorinci.size())
                                throw exceptiaMea;
                            ornitorinc c;
                            cabinetVeterinar<ornitorinc> cv;
                            cv.adaugareListaPacienti();
                            cv.vindecaBoala();
                            break;
                        } catch (ExceptiaMea &e) {

                            cout << "\nNu exista niciun ornitorinc creat !";
                        }
                        break;
                    }
                    case 7: {
                        break;
                    }
                    default: {
                        cout << "\nAti introdus o varianta gresita !";
                        break;
                    }
                }
                break;
            }
                //iesire
            case 7: {
                k = 0;

                break;
            } break;
            default: {
                cout << "\nAti introdus o varianta gresita !";
                break;
            }
        }
    }
}

meniuInteractiv *meniuInteractiv::obiect = 0;
int main() {
    meniuInteractiv *meniulMeu = meniulMeu->getInstance();
    meniulMeu->meniu();


    return 0;
}
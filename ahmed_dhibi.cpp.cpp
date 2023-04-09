
#include <iostream>
 using namespace std;

class Personne
{
    private:
    string nom;
    int age;
    int ncin;

    public:
    void incrementerAge();
    int getAge()const;
    string getNom()const;
    void setAge(int a);
    void setNom(string n);
    int getncin()const;
    void afficher();
    Personne( string n , int c, int a);

};
void Personne::incrementerAge()
    {
        age++;
    }
int Personne::getAge()const
    {
        return age;
    }
string Personne::getNom()const
    {
        return nom;
    }
int Personne::getncin()const
{
    return ncin;
}

void Personne::setAge(int a)
    {
        age=a;
    }

void Personne::setNom(string n)
    {
        nom=n;
    }
void Personne::afficher()
    {
        cout<<"votre nom:"<<nom<< endl;
        cout<<"votre age:"<<age<< endl;
        cout<<"votre num.cin"<<ncin<< endl;

    }

Personne::Personne( string n , int c, int a= -1)
    {
        nom=n;
        age=a;
        ncin=c;
    }
class Compte
{
    private:
     const int numero;
    int solde;
    Personne titulaire;
    public:
    Compte(int n,Personne t,int sd);
    bool deposer (double montant);
    bool retirer(double montant);
    double getSolde()const;
    int getNumero()const;
    void afficher();

};
Compte::Compte(int n,Personne t,int sd=0) :numero(n),titulaire(t){
     if (sd>=0){
        solde=sd;

    }
}
bool Compte::deposer (double montant){
    bool test=false;
    if(montant>0){


    solde+= montant;
    test=true;

    }

    return test;
}
bool Compte::retirer(double montant){
    bool test=false;
    if(solde >= montant){
        solde -= montant ;
        test=true;

    }
    return test;

}
double Compte::getSolde()const{
    return solde ;
}
int Compte::getNumero()const{
    return numero;
}
void Compte::afficher()
     {
         cout<<"votre solde est :"<<solde<< endl;
         cout<<"le numero de votre compte est :"<<numero<< endl;
         cout<<"le nom du titulaire est :"<<titulaire.getNom()<<endl;
         cout<<"le num.cin du titulaire est :"<<titulaire.getncin()<<endl;
     }
class Banque {
    private:
    string nom ;
    Compte* comptes[100];
    public:
    Banque(string nom );
    void ouvrirUnCompte(Compte* c);
    void fermerUnCompte(int numero);
    bool deposerArgent(int numero,double montant);
    bool retirerArgent(int numero,double montant);
    Compte* rechercherCompte(int numero);
    void afficher();


};

bool Banque::deposerArgent(int numero,double montant){
    Compte* pt =rechercherCompte(numero);
    bool test=false;
    if (pt!=NULL){
        pt->deposer(montant);
        test=true;
    }
    return test;

}
bool Banque::retirerArgent(int numero,double montant){
    Compte* pt =rechercherCompte(numero);
    bool test=false;
    if (pt!=NULL){
        pt->retirer(montant);
        test=true;
    }
    return test;
}
Compte* Banque::rechercherCompte(int numero){
    for(int i=0;i<100;i++){
        if(comptes[i]!= NULL && comptes[i]->getNumero()==numero ){
            return comptes[i];
        }
    }
    return NULL;
}
Banque::Banque(string n):nom(n){
    for(int i=0;i<100;i++){
        comptes[i]=NULL;
    }
}
void Banque::fermerUnCompte(int numero)
{
        Compte* p=rechercherCompte(numero);
        if (p!=NULL )
        {
            delete p;
            p=NULL;

        }
}
void Banque::ouvrirUnCompte(Compte *c)
{
    for(int i=0;i<100;i++)
    {

        if(comptes[i]==NULL)
        {
            comptes[i]=c;

        }
        break;
    }
}
void Banque::afficher()
{
    cout<<"le nom de la banque est :"<<nom<<endl;


    for(int i=0;i<100;i++)
    {
        if(comptes[i]!=NULL)
        {
            comptes[i]->afficher();
        }
    }
}
/*
int main(){
    int choix=0;
    string name;
    cout<<"donner le nom de la banque"<<endl;
    cin>>name;
    Banque b(name);
    while(1){
        cout<<"*******************************"<<endl;
        cout<<"             menu              "<<endl;
        cout<<"*******************************"<<endl;

        cout<<"1-ouvrir un compte."<<endl;
        cout<<"2-retirer."<<endl;
        cout<<"3-deposer."<<endl;
        cout<<"4-fermer un compte."<<endl;
        cout<<"5-afficher les comptes de la banque"<<endl;
        cout<<"6-fermer l'appli."<<endl;
        cout<<"introduir votre choix"<<endl;
        cin>>choix ;
        switch(choix)
        {

        case 1 :
            {

                Compte *c;
                int n;
                string nom;
                int ncin,age;
                cout<<"donner le nom de l'etulisateur"<<endl;
                cin>>nom;
                cout<<"donner l'age"<<endl;
                cin>>age;
                cout<<"donner le num.cin de l'etulisateur"<<endl;
                cin>>ncin;
                Personne t(nom,ncin,age);
                int solde;
                cout<<"donner le numero de la compte"<<endl;
                cin>>n;
                cout<<"donner le solde "<<endl;
                cin>>solde;

                c=new Compte(n,t,solde);
                b.ouvrirUnCompte(c);
                c->afficher();
                break;
            }
        case 2 :
            {

                bool test;
                int n;
                double montant;
                cout<<"donne le numero du compte"<<endl;
                cin>>n;
                cout<<"donner le montant a retirer"<<endl;
                cin>>montant;
                test=b.retirerArgent(n,montant);
                if(test==true)
                {
                    cout<<"succee"<<endl;

                }
                else
                    cout<<"solde insuffisant"<<endl;
                break;


            }
        case 3 :
            {
                bool test;
                int n;
                double montant;
                cout<<"donne le numero du compte"<<endl;
                cin>>n;
                cout<<"donner le montant a deposer"<<montant<<endl;
                cin>>montant;
                test=b.deposerArgent(n,montant);
                 if(test==true)
                {
                    cout<<"succee"<<endl;

                }
                else
                    cout<<"verifier votre montant"<<endl;
                break;

            }
        case 4 :
            {
                int n;
                cout<<"donnee le numero de la compte a fermer"<<endl;
                cin>>n;
                b.fermerUnCompte(n);
                break;
            }
        case 5 :
            {
                b.afficher();
                break;
            }
        case 6 :
            {
                exit(0);
            }
        default:
            cout<<"saisir un choix entre 1 et 6"<<endl;
        }
    }
    return 0;

}
*/
int main()
{
    int choix=0;

    Banque b("BIAT");
    while(1){
        cout<<"*******************************"<<endl;
        cout<<"             menu              "<<endl;
        cout<<"*******************************"<<endl;

        cout<<"1-ouvrir un compte."<<endl;
        cout<<"2-retirer."<<endl;
        cout<<"3-deposer."<<endl;
        cout<<"4-fermer un compte."<<endl;
        cout<<"5-afficher les comptes de la banque"<<endl;
        cout<<"6-fermer l'appli."<<endl;
        cout<<"introduir votre choix"<<endl;
        cin>>choix ;
        switch(choix)
        {

        case 1 :
            {

                Compte *c;


                Personne t("ahmed",11636917,22);



                c=new Compte(10,t,120);
                b.ouvrirUnCompte(c);
                c->afficher();
                break;
            }
        case 2 :
            {

                bool test;


                test=b.retirerArgent(10,50.5);
                if(test==true)
                {
                    cout<<"succee"<<endl;

                }
                else
                    cout<<"solde insuffisant"<<endl;
                break;


            }
        case 3 :
            {
                bool test;

                test=b.deposerArgent(10,60);
                 if(test==true)
                {
                    cout<<"succee"<<endl;

                }
                else
                    cout<<"verifier votre montant"<<endl;
                break;

            }
        case 4 :
            {

                b.fermerUnCompte(10);
                break;
            }
        case 5 :
            {
                b.afficher();
                break;
            }
        case 6 :
            {
                exit(0);
            }
        default:
            cout<<"saisir un choix entre 1 et 6"<<endl;
        }
    }
    return 0;
}

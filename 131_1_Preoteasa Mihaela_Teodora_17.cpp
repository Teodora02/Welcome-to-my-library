///Tema 17. Clasa „carte”

///-membri privati:
/*
denumire carte,
autor principal,
al doilea autor,
numar de pagini,
pret,
rating (goodreads).
*/

///-metode:
/*
constructori,
destructor,
supraincarcare pe >> si <<,
constructor de copiere,
supraincarcare pe =,
supraincarcare pe operatorii specifici de comparare
(compararea se face pe baza ratingului).
*/

///-cerinte:
/*
sa se citeasca de la tastatura un vector
declarat dinamic de carti,
sa se poata compara doua carti,
sa se poata modifica informatiile unei carti din meniu
si sa se afiseze toate cartile.
*/

#include <iostream>
#include <string>

using namespace std;


class Carte
{
private:
    string m_titlu;
    string m_autor1;
    string m_autor2;
    int    m_pagini;
    float  m_pret;
    float  m_rating;

public:

     /// set
    void set_titlu( string titlu ) {m_titlu = titlu;}
    void set_autor1( string autor1 ){m_autor1 = autor1;}
    void set_autor2( string autor2 ){m_autor2 = autor2;}
    void set_pagini( int pagini ){m_pagini = pagini;}
    void set_pret( float pret ){m_pret = pret;}
    void set_rating( float rating ){m_rating = rating;}

    /// get
    string get_titlu() {return m_titlu;}
    string get_autor1(){return m_autor1;}
    string get_autor2(){return m_autor2;}
    int get_pagini(){return m_pagini;}
    float get_pret(){return m_pret;}
    float get_rating(){return m_rating;}

    /// constructor cu param. impliciti
    Carte( string titlu = "", string autor1 = "", string autor2 = "", int pagini = 0, float pret = 0., float rating = 0. );

    friend istream &operator>>( istream &in, Carte &c );
    friend ostream &operator<<( ostream &out, Carte &c );
    friend bool operator<( const Carte &c1, const Carte &c2 );

    void print();
    /// constructor de copiere explicit
    Carte( const Carte & );

    ~Carte();  /// destructor
};

const int SIZE = 10;               /// pentru vectorul de 10 carti

Carte::Carte( string titlu, string autor1, string autor2, int pagini, float pret, float rating ) :
    m_titlu(titlu), m_autor1(autor1), m_autor2(autor2), m_pagini(pagini), m_pret(pret), m_rating(rating)
{}

/// def destructor
Carte::~Carte()
{
    cout << "" ;
}

/// constructor de copiere explicit
Carte::Carte( const Carte &c )
{
    cout << "\n Constructor de copiere explicit.\n";
    m_titlu        = c.m_titlu;
    m_autor1       = c.m_autor1;
    m_autor2       = c.m_autor2;
    this->m_pagini = c.m_pagini;
    this->m_pret   = c.m_pret;
    this->m_rating = c.m_rating;
}

void Carte::print()
{
    cout << "Titlu: " << m_titlu << '\n'
         << "Autor principal: " << m_autor1 << '\n';

    if( !m_autor2.empty() )  /// verificam daca exista un al doilea autor
    {
        cout << "Autor secundar: " << m_autor2 << '\n';
    }

    cout << "Pagini: " << m_pagini << '\n'
         << "Pret: " << m_pret << '\n'
         << "Rating: " << m_rating << '\n'
         << '\n';
}


istream &operator>>( istream &in, Carte &c )
{
    cout << "Titlu: ";
    getline( in >> ws, c.m_titlu );
    cout << "Autor principal: ";
    getline( in >> ws, c.m_autor1 );
    cout << "Autor secundar: ";
    getline( in, c.m_autor2 );          /// daca nu completam campul cu autor2 la citire, nu il mai afisam
    cout << "Pagini: ";
    in >> c.m_pagini;
    cout << "Pret: ";
    in >> c.m_pret;
    cout << "Rating: ";
    in >> c.m_rating;
    cout << endl;
    return in;
}

ostream &operator<<( ostream &out, Carte &c )
{
    out << "Titlu: " << c.m_titlu << '\n'
        << "Autor principal: " << c.m_autor1 << '\n';

    if( !c.m_autor2.empty() )  /// verificam daca exista un al doilea autor
    {
        out << "Autor secundar: " << c.m_autor2 << '\n';
    }

    out << "Pagini: " << c.m_pagini << '\n'
        << "Pret: " << c.m_pret << '\n'
        << "Rating: " << c.m_rating << '\n'
        << '\n';
    return out;
}

bool operator<( const Carte &c1, const Carte &c2 )
{
    if (c1.m_rating < c2.m_rating)
    {
        return true;
    }
    return false;
}

void search(Carte c[SIZE])          /// echiv cu Carte *c
{
    int i, alegere;
    string t;
    cout << "Titlul cartii este: ";
    getline( cin >> ws, t );
    cout << endl;

    for ( i = 0; i < SIZE; i++)         /// parcurg vectorul cu 10 elemente
    {
        if ( t == c[i].get_titlu() )    /// daca titlul citit de la tastatura coincide cu un titlu din vector -> ok
        {
            break;
        }
    }

    if(i == SIZE)
    {
        cout << "Cartea nu exista.\n";
        return;
    }

    while(1)
    {
        cout << "Ce informatii doresti sa modifici?\n"
             << "1 - Titlu;\n"
             << "2 - Autor principal;\n"
             << "3 - Autor secundar;\n"
             << "4 - Pagini;\n"
             << "5 - Pret;\n"
             << "6 - Rating;\n"
             << "0 - exit\n";
        cout << "Alegerea ta este: ";
        cin >> alegere;
        cout << endl;


        switch ( alegere )
        {
            case 1:
            {
                string t;
                cout << "Titlul dat se modifica in: ";
                getline( cin >> ws, t );
                c[i].set_titlu(t);
                cout << endl;

                break;
            }
            case 2:
            {
                string a1;
                cout << "Autorul principal se modifica in: ";
                getline( cin >> ws, a1);
                c[i].set_autor1(a1);
                cout << endl;

                break;
            }
            case 3:
            {
                string a2;
                cout << "Autorul secundar se modifica in: ";
                getline( cin >> ws, a2 );
                c[i].set_autor2(a2);
                cout << endl;

                break;
            }
            case 4:
            {
                int p;
                cout << "Numarul de pagini se modifica in: ";
                cin >> p;
                c[i].set_pagini(p);
                cout << endl;

                break;
            }
            case 5:
            {
                float pr;
                cout << "Pretul se modifica in: ";
                cin >> pr;
                c[i].set_pret(pr);
                cout << endl;

                break;
            }
            case 6:
            {
                float r;
                cout << "Rating-ul se modifica in: ";
                cin >> r;
                c[i].set_rating(r);
                cout << endl;

                break;
            }
            case 0:
            {
                return;
            }
        }

        cout << "Modificare efectuata! Cartea arata in felul urmator:\n" << endl;
        cout << c[i] << endl;
    }
    return;
}

void meniu()

{
    int optiune;
    cout << "Optiuni: " << '\n'
         << "1 - Utilizare set si get;" << '\n'
         << "2 - Citirea info despre carti vector dinamic;" << '\n'
         << "3 - Comparare a doua carti;" << '\n'
         << "4 - Modificare carte;" << '\n'
         << "5 - Afisare carti; " << '\n'
         << "0 - Exit" << '\n' << endl;
    cout << "Optiunea ta este: ";
    cin >> optiune;
    cout << endl;

    Carte c[SIZE] = { Carte( "Curajul de a fi fericit", "Ichiro Kishimi", "Fumitake Koga", 288, 33.67, 4.13 ),
                      Carte( "In cautarea fericirii", "Bertrand Russel", "", 224, 21.60, 4.02 ),
                      Carte( "Arta subtila a nepasarii", "Mark Manson", "", 240, 28.53, 3.93 ),
                      Carte( "Cafeneaua de la capatul lumii", "John Strelecky", "", 144, 29.93, 3.68 ),
                      Carte( "Biblioteca de la Miezul Noptii", "Matt Haig", "", 300, 28.49, 4.20 ),
                      Carte( "Secretele succesului", "Dale Carnegie", "", 296, 35.25, 4.50 ),
                      Carte( "Despre destin", "Gabriel Liiceanu", "Andrei Plesu", 248, 43.47, 3.98 ),
                      Carte( "Inferno", "Dan Brown", "", 576, 24.52, 3.86 ),
                      Carte( "Un IQ financiar mai bun", "Robert Kiyosaki", "", 256, 42.57, 4.07 ),
                      Carte( "Plansul lui Nietzsche", "Irvin Yalom", "", 400, 34.60, 4.34 )
                    };

    while( optiune )
    {
        switch( optiune )
        {
            /// set si get
            case 1:
            {
                Carte c;
                cin >> c;
                cout << c;
                break;
            }
            /// citire informatii despre carti cu vector dinamic
            case 2:
            {
                int i, n;
                cout << "Numarul de carti pentru care introduci informatii este: ";
                cin >> n;
                cout << endl;
                Carte *v = new Carte[n];

                if( v == nullptr )
                    cout << "Eroare: memoria nu poate fi alocata.";
                else
                {
                    for( i = 0; i < n; i++ )
                    {
                        ///cout << "Introducere informatii despre carti: " << '\n';
                        cin >> v[i];
                    }
                    delete[] v;
                }
                break;
            }
            /// comparare a doua carti
            case 3:
            {
                Carte c1, c2;
                cin >> c1 >> c2;
                if (c1 < c2)
                {
                    cout << "Rating-ul cartii c2 este mai bun decat rating-ul cartii c1";
                }
                else
                {
                    cout << "Rating-ul cartii c1 este mai bun decat rating-ul cartii c2.\n\n";
                }
                break;
            }
            /// modificare informatii carte
            case 4:
            {
                search(c);
                break;
            }
            /// afisare informatii carti
            case 5:
            {
                int   i;
                for( i = 0; i < SIZE; i++ )  /// afisare inform despre cele 10 carti
                    c[i].print();
                break;
            }
        }
        cout << "Alta optiune?" << '\n'
             << "1 - Utilizare set si get;" << '\n'
             << "2 - Citirea info despre carti vector dinamic;" << '\n'
             << "3 - Comparare a doua carti;" << '\n'
             << "4 - Modificare carte;" << '\n'
             << "5 - Afisare carti; " << '\n'
             << "0 - Exit" << '\n' << endl;
        cout << "Optiunea ta este: ";
        cin >> optiune;
        cout << endl;
    }
}

int main()
{
    meniu();

    return 0;
}

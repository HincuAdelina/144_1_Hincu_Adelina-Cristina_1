#include <iostream>
#include<cmath>
using namespace std;

class Complex
{
    double m_real;
    double m_imaginary;

public:
    Complex() {}
    Complex(double real) : m_real(real), m_imaginary(0) {}
    Complex(double real, double imaginary)
        : m_real(real), m_imaginary(imaginary) {}
    Complex(Complex &complex)
        : m_real(complex.m_real), m_imaginary(complex.m_imaginary) {}
    ~Complex() {}

    Complex& operator=(const Complex& complex)
    {
        m_real = complex.m_real;
        m_imaginary = complex.m_imaginary;
        return *this;
    }

    // Getteri
    double GetReal()
    {
        return m_real;
    }
    double GetImaginary()
    {
        return m_imaginary;
    }
    // Setteri
    void SetReal(double real)
    {
        m_real = real;
    }
    void SetImaginary(double imaginary)
    {
        m_imaginary = imaginary;
    }

    // modulul unui numar complex
    double Abs()
    {
        return sqrt(m_real * m_real + m_imaginary * m_imaginary);
    }

    friend Complex operator+ (Complex complex1, Complex complex2);

    friend Complex operator*(Complex c1, Complex c2);

    friend Complex operator/(Complex c1, Complex c2);

    friend std::istream &operator>>(std::istream &in, Complex &complex)
    {
        in >> complex.m_real >> complex.m_imaginary;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, Complex &complex)
    {
        if (complex.m_real != 0 && complex.m_imaginary != 0)
        {
            //afisare a+i*b sau a-i*b
            if (complex.m_imaginary < 0)
            {
                //afisare a-i*b
                out << complex.m_real << "-i*" << -complex.m_imaginary;
            }
            else
            {
                //afisare a+i*b
                out << complex.m_real << "+i*" << complex.m_imaginary;
            }
        }
        else if (complex.m_imaginary == 0)
        {
            out << complex.m_real;
        }
        else
        {
            // complex.m_real == 0
            if (complex.m_imaginary < 0)
            {
                out << "-i*" << -complex.m_imaginary;
            }
            else
                out << "i*" << complex.m_imaginary;
        }
        return out;
    }
};
Complex operator+  (Complex complex1, Complex complex2)
{
    Complex result;
    result.m_real = complex1.m_real + complex2.m_real;
    result.m_imaginary = complex1.m_imaginary + complex2.m_imaginary;
    return result;
}

Complex operator*(Complex c1, Complex c2)
{
    // (a + bi)(c + di) = ac - bd + i(ad + bc)
    Complex result;
    result.m_real = c1.m_real * c2.m_real - c1.m_imaginary * c2.m_imaginary;
    result.m_imaginary = c1.m_real * c2.m_imaginary + c1.m_imaginary * c2.m_real;
    return result;
}

Complex operator/(Complex c1, Complex c2)
{
    // ((a1*a2+b1*b2)+(a2*b1-a1*b2)i) / a2^2+b2^2
    Complex result;
    double numitor = c2.m_real * c2.m_real + c2.m_imaginary * c2.m_imaginary;
    result.m_real =(c1.m_real * c2.m_real + c1.m_imaginary * c2.m_imaginary)/ numitor;
    result.m_imaginary =(c2.m_real * c1.m_imaginary - c1.m_real * c2.m_imaginary)/ numitor;

    return result;
}

Complex *readNComplexNumbers(int& n)
{
    cout << "Number of complex numbers to read:" << endl;
    cin >> n;
    cout << "Write n complex numbers." << endl;
    Complex *numbers = new Complex[n];
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    cout << "You read the following " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << numbers[i] << endl;
    }
    return numbers;
}


class Vector_Complex
{

    int m_Nr;           //nr componente
    Complex *m_Vector;  //vector alocat dinamic

public:
    //constructor de initializare fara parametri
    Vector_Complex()
    {
        m_Nr=0;
        m_Vector=NULL;
    }

    //constructor de initializare cu o valoare data pe toate componentele
    Vector_Complex(int n, Complex valoare_initiala)
    {
        m_Nr = n;
        m_Vector = new Complex[m_Nr];
        for(int i=0; i<m_Nr; i++)
            m_Vector[i]=valoare_initiala;
    }

    //constructor cu parametri
    //Vector_Complex(int n, Complex* vec): m_Nr(n), m_Vector(vec) {} //nu stiu daca e bine

    //constructor de copiere
    Vector_Complex(const Vector_Complex &vec)
    {
        m_Nr=vec.m_Nr;
        m_Vector=new Complex[m_Nr];
        for(int i=0; i<m_Nr; i++)
            m_Vector[i]=vec.m_Vector[i];
    }

    //destructor
    ~Vector_Complex()
    {
        m_Nr=0;
        delete[] m_Vector;
        m_Vector=NULL;
    }

    //setteri
    void SetVector(Complex* vec)
    {
        m_Vector = vec;
    }

    void SetNr(int n)
    {
        m_Nr = n;
    }

    //getteri
    Complex* GetVector()
    {
        return m_Vector;
    }

    int GetNr()
    {
        return m_Nr;
    }

    //supraincarcarea operatorilor
    friend std::ostream& operator <<(std::ostream& out, const Vector_Complex& vec);
    friend std::istream& operator >>(std::istream& in,  Vector_Complex& vec);

    Vector_Complex& operator= (const Vector_Complex& vec)
    {
        //mai intai trebuie sa dezalocam memoria pe care o avea _arr
        delete[] m_Vector;
        m_Nr=0;
        m_Vector=NULL;

        //acum facem assignment-ul
        m_Nr=vec.m_Nr;
        m_Vector=new Complex[m_Nr];
        for(int i=0; i<m_Nr; i++)
        {
            m_Vector[i]=vec.m_Vector[i];
        }
    }

    //determinarea vectorului modulelor
    Vector_Complex modul()
    {
        Complex x(0);
        Vector_Complex vec(m_Nr,x); //vec va fi vectorul modulelor,il initializam cu nr complex 0
        for(int i=0; i<m_Nr; i++)
            vec.m_Vector[i]=m_Vector[i].Abs();
        return vec;
    }

    //ordonarea crescatoare a vectorului modulelor
    void ordonare_crescatoare(Vector_Complex v)
    {
        Vector_Complex vec;
        vec=v.modul();      //vectorul modulelor
        Complex aux;
        for(int i=0; i<vec.m_Nr-1; i++)     //deoarece metoda modul() intoarce un Vector_Complex,
        {                                        //care are partea reala a numerelor complexe egala cu modulul,
            for(int j=i+1; j<vec.m_Nr; j++)     //iar partea imaginara = 0,
                if(vec.m_Vector[i].GetReal() > vec.m_Vector[j].GetReal()) //comparam partile reale, de tip double
                {
                    aux=vec.m_Vector[i];
                    vec.m_Vector[i]=vec.m_Vector[j];
                    vec.m_Vector[j]=aux;
                }
        }
        cout<<vec;
    }

    //determinarea sumei tuturor componentelor vectorului
    Complex suma()
    {
        Complex s(0);
        for(int i=0; i<m_Nr; i++)
            s=s+m_Vector[i];
        return s;
    }
};

std::ostream& operator <<(std::ostream& out, const Vector_Complex& vec)
{
    for(int i=0; i<vec.m_Nr; i++)
        out<<vec.m_Vector[i]<<" ";
    return out;
}

std::istream& operator >>(std::istream& in,  Vector_Complex& vec)
{
    cout<<"Numarul de elemente ale vectorului: ";
    in>>vec.m_Nr;
    vec.m_Vector=new Complex[vec.m_Nr];
    for(int i=0; i<vec.m_Nr; i++)
    {
        cout<<"Numarul complex: ";
        in>>vec.m_Vector[i];
    }
    return in;
}

//citirea a n obiecte
Vector_Complex *citesteNobiecte(int& n)
{
    cout<<"Numarul de obiecte: "<<endl;
    cin>>n;
    Vector_Complex *vec = new Vector_Complex[n];
    for (int i=0; i<n; i++)
    {
        cin>>vec[i];
    }
    cout<<"Cele "<<n<<" obiecte citite:"<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<vec[i]<<endl;
    }
    return vec;
}

//TREBUIE CITIT UN VECTOR LA OPTIUNEA 2 PENTRU A FOLOSI OPTIUNILE 3,4,5
//vectorul poate fi schimbat prin accesarea optiunii 2 inca o data
void OptiuniMeniu()
{
    cout<< "0. Oprire." <<endl;
    cout<< "1. Initializati un vector complex cu un numar dat pe toate componentele." <<endl;
    cout<< "2! Cititi, memorati si afisati un vector complex. (SAU schimbati vectorul)" <<endl;
    cout<< "3. Afisati vectorul modulelor." <<endl;
    cout<< "4. Afisati vectorul sortat crescator dupa module." <<endl;
    cout<< "5. Afisati suma tuturor elementelor." <<endl;
    cout<< "6. Cititi, memorati si afisati n obiecte." <<endl;
    cout<< endl;
}

void Meniu()
{
    cout<< "Alegeti o optiune: " <<endl;
    OptiuniMeniu();
    int optiune = 0;
    int stop = 0;
    int nr = 0;
    Vector_Complex *numbers = NULL;
    Vector_Complex vector_general;  //vectorul memorat la optiunea 2

    cin>>optiune;
    while(optiune != stop)
    {
        if(optiune == 1)
        {
            int lungime;
            Complex a;
            cout<<"Lungimea vectorului: "<<endl;
            cin>>lungime;
            cout<<"Numarul complex: "<<endl;
            cin>>a;
            Vector_Complex v(lungime, a);   //initializam vectorul cu a pe toate componentele
            cout<<"Vectorul: "<<v<<endl;
        }
        else if(optiune == 2)
        {
            cin>>vector_general;
            cout<<"Vectorul: "<<vector_general<<endl;
        }
        else if(optiune == 3)
        {
            Vector_Complex v;
            v=vector_general.modul();
            cout<<v<<endl;
        }
        else if(optiune == 4)
        {
            Vector_Complex v;
            vector_general.ordonare_crescatoare(vector_general);
            cout<<endl;
        }
        else if(optiune == 5)
        {
            Complex s;
            s=vector_general.suma();
            cout<<s<<endl;
        }
        else if(optiune == 6)
        {
            numbers = citesteNobiecte(nr);
        }
        //reafisam meniul
        cout<<endl;
        OptiuniMeniu();
        //citim noua optiune
        cin>>optiune;
    }

    //eliberam memoria
    delete[] numbers;
}
int main()
{

    /* Complex a;
     a.SetReal(1);
     a.SetImaginary(2);
     cout<<a<<endl;
     Vector_Complex v1(2,a),v;
     cin>>v;
     cout<<v;
     cout<<v1<<endl;
     Vector_Complex v2(v1);
     cout<<v2<<endl;
     cout<<v1.GetNr()<<endl;
     cout<<v1.GetVector()<<endl;
     v1.SetNr(3);
     //v1.SetVector(a);
     cout<<v1<<endl;
    Vector_Complex v1,v2;
    cin>>v1;
    v2=v1;
    cout<<v2;
    */
//   Complex b;
//   int nr;
//   Vector_Complex *v1;
/* Complex* v2;
    cin>>v;
    //cout<<v;
    b=v.suma();
    cout<<b<<endl;
    v1=v.modul();
    cout<<"v1= "<<v1<<endl<<"v= "<<v<<endl;
    v1.ordonare_crescatoare(v1);
    cout<<"  dupa ordonare";
    cout<<endl<<"v1= "<<v1;
*/
    // v1=citesteNobiecte(nr);

    //OptiuniMeniu();


    Meniu();

    return 0;
}

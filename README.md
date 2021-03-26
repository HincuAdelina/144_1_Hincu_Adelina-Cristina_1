# POO-Proiectul 1 Tema 1

Cerinte comune tuturor temelor :
- implementare in C++ folosind clase
- datele membre private
- constructori de initializare (cu si fara parametrii), constructor de copiere
- get, set pentru toate datele membre
- ATENTIE: functiile pe care le-am numit mai jos metode (fie ca sunt supraincarcari de operatori, fie altfel de functii), pot fi implementate ca functii prieten in loc de metode ale claselor respective, daca se considera ca aceasta alegere este mai naturala;
- supraincarcarea operatorilor << si >> pentru iesiri si intrari de obiecte, dupa indicatiile de mai jos, astfel incat sa fie permise (si ilustrate in program):
- sa existe o metoda publica prin care se realizeaza citirea informațiilor complete a n obiecte, memorarea și afisarea acestora.
- programul sa aiba un meniu interactiv

Tema 1. Clasa ”Vector_Complex”
- clasa este prietena a clasei Numar_Complex definita în Tema 0
- membri privati pentru vectorul propriuzis si numarul de elemente;
- constructor pentru initializarea cu un numar dat pe toate componentele (primeste ca parametru numarul respectiv si numarul componentelor);
- constructori pentru initializare si copiere;
- destructor (în cazul alocarii statice, se seteaza dimensiunea vectorului la zero, iar în cazul alocarii dinamice, se dezaloca zona de memorie utilizata);
- supraincarcarea operatorilor << și >> sa utilizeze supraincarea acestora în cadrul clasei Numar_Complex;
- metoda publica pentru determinarea vectorului modulelor, folosind metoda de determinare a modulului din clasa numar complex;
- metoda publica pentru sortarea crescatoare dupa module a vectorului;
- metoda publica pentru calculul sumei tuturor elementelor vectorului, care sa utilizeze operatorul + din clasa de numere complexe;

Lista cerintelor bonus pentru prima lucrare practica (pentru maxim 0.2 puncte bonus)
Tema 1:
- suprascriere operator =
- operator == si operator !=
- operatorii + si –   – operatorii unari, exp: “+v”, “-v”
– operatorii binari, sa functioneze in forma vector - vector, complex + vector, vector + complex (in ultimele 2 cazuri, rezultatul trebuie sa fie echivalent cu adunarea dintre vector si un alt vector de aceeasi dimensiune, cu toti membrii de valuarea complexului dat ca parametru); la fel si pentru scadere
- operatorii +=, -=
- operatorul !    – testeaza pozitiv, daca vectorul are cel putin un element diferit de 0
- operator []    – furnizeaza o referinta la al n-lea element din vector
– sa fie posibile constructii ca: "cin>>v[i]", "cout<<v[i]", "v[i]=x", "x=v[i]", cu efectul obisnuit

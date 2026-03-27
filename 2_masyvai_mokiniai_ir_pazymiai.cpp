// Bibliotekas
#include <iostream>
#include <string>
using namespace std; // kad nereiketu rasyti std:: pries kiekviena cout, cin ir t.t.
// Vienmatis masyvas mokiniu vardams saugoti, maksimaliai 100 vardu
string vardai[100];
// Dvimatis masyvas pazymiams saugoti
// Pirmas skaicius [100] - eilutes (mokiniai), antras [10] - stulpeliai (pazymiai)
// Kiekvienas mokinys turi 10 pazymiu
int pazymiai[100][10];
// Kintamasis, kuris saugo kiek mokiniu siuo metu yra sarase
int mokiniuSk = 0;
// Kas yra bool - tai tipas, kuris grazina tik true arba false
// unkcija tikrina ar toks vardas jau yra sarase
// Parametras: string vardas - kuri norim patikrinti
bool arVardasEgzistuoja(string vardas)
{
    // for ciklas - kartoja veiksmus nurodyta kiekti kartu
    // int i = 0 - pradedame nuo pirmo mokinio (1-1=0(pirmas), 2-1=1(antras) ir t.t.)
    // i < mokiniuSk - kartojame tol, kol i mazesnis uz mokiniu skaiciu
    // i++ - po kiekvieno pakartojimo padidinm vienetu
    for (int i = 0; i < mokiniuSk; i++)
    {
        // if - salyginis sakinys, tikrina ar salyga teisinga
        // Lyginame ar masyve esantis vardas sutampa su ivestuoju
        if (vardai[i] == vardas)
        {
            return true; // Radome tokiu pat varda - graziname true (taip, egzistuoja)
        }
    }
    return false; // Perejome visus vardus ir neradome - graziname false (ne, neegzistuoja)
}
// Kas yra void? - tai funkcijos tipas, kuris reiskia kad funkcija nieko negrazina,
// ji tik atlieka veiksmus (pvz. iraso duomenis, atspausdina teksta)
// Si funkcija leidzia vartotojui ivesti nauja mokini su 10 pazymiu
void ivistiMokini()
{
    // Tikriname ar dar galima prideti mokiniu (masyve telpa tik 100)
    if (mokiniuSk >= 100)
    {
        cout << "Negalima prideti daugiau mokiniu! Maksimumas - 100." << endl;
        return; // return void funkcijoje - tiesiog baigia funkcija, nieko negrazina
    }
    string vardas;
    cout << "Iveskite mokinio varda: ";
    cin >> vardas;
    // Tikriname ar toks vardas jau egzistuoja sarase
    if (arVardasEgzistuoja(vardas))
    {
        cout << "Toks vardas jau egzistuoja! Negalima ivesti pasikartojancio vardo." << endl;
        return;
    }
    // Irasom varda i masyva i dabartine pozicija
    vardai[mokiniuSk] = vardas;
    cout << "Iveskite 10 pazymiu (nuo 0 iki 10):" << endl;
    // for ciklas 10-ciai pazymiu ivesti
    // int j = 0 - kintamasis j yra pazymio numeris, pradedame nuo 0
    // j < 10 - kartojame 10 kartu (0,1,2,3,4,5,6,7,8,9)
    // j++ - po kiekvieno pazymio padidiname j vienetu
    for (int j = 0; j < 10; j++)
    {
        int pazymys;
        // while ciklas - kartoja tol, kol salyga teisinga
        // while(true) - begalis ciklas, kuris baigsis tik kai panaudosime break
        while (true)
        {
            cout << "  Pazymys " << j + 1 << ": "; // j+1 kad rodytume nuo 1, ne nuo 0
            cin >> pazymys;

            // Tikriname ar pazymys tinkamas (nuo 0 iki 10)
            if (pazymys >= 0 && pazymys <= 10)
            {
                break; // break - nutraukia cikla, iseiname is while
            }
            else
            {
                cout << "  Klaida! Pazymys turi buti nuo 0 iki 10. Bandykite dar karta." << endl;
            }
        }
        // Irasyme pazymi i dvimati masyva
        // pazymiai[mokiniuSk] - dabartinio mokinio eilute
        // [j] - pazymio stulpelis
        pazymiai[mokiniuSk][j] = pazymys;
    }
    mokiniuSk++; // Padidiname mokiniu skaiciu vienetu
    cout << "Mokinys sekmingai pridetas!" << endl;
}
// void - nieko negrazina, tik atspausdina informacija i ekrana
// Si funkcija parodo visu mokiniu vardus ir ju pazymius
void rodytiVisus()
{
    // Tikriname ar yra bent vienas mokinys
    if (mokiniuSk == 0)
    {
        cout << "Mokiniu sarasas tuscias." << endl;
        return;
    }
    cout << endl
         << "Visu mokiniu pazymiai" << endl;
    // Isoriniu ciklas - eina per kiekviena mokini
    // int i = 0 - pradedame nuo pirmo mokinio
    for (int i = 0; i < mokiniuSk; i++)
    {
        cout << i + 1 << ". " << vardai[i] << ": ";
        // Vidinis ciklas - eina per kiekvieno mokinio pazymius
        // int j = 0 - pradedame nuo pirmo pazymio
        for (int j = 0; j < 10; j++)
        {
            cout << pazymiai[i][j]; // Atspausdiname pazymi
            // Jei tai ne paskutinis pazymys, dedam kableli
            if (j < 9)
            {
                cout << ", ";
            }
        }
        cout << endl; // endl - pereina i nauja eilute
    }
}
// Funkcija: rodytiViena
// void - nieko negrazina, tik atspausdina vieno mokinio duomenis
// Si funkcija suranda mokini pagal varda ir parodo jo pazymius
void rodytiViena()
{
    if (mokiniuSk == 0)
    {
        cout << "Mokiniu sarasas tuscias." << endl;
        return;
    }
    string vardas;
    cout << "Iveskite mokinio varda: ";
    cin >> vardas;
    // Ieskome mokinio pagal varda
    for (int i = 0; i < mokiniuSk; i++)
    {
        if (vardai[i] == vardas)
        {
            // Radome mokini - spausdiname jo pazymius
            cout << vardas << " pazymiai: ";
            for (int j = 0; j < 10; j++)
            {
                cout << pazymiai[i][j];
                if (j < 9)
                {
                    cout << ", ";
                }
            }
            cout << endl;
            return; // Radome ir atspausdinome - baigiame funkcija
        }
    }
    // Jei ciklas baigesi ir neradome - pranesame apie tai
    cout << "Mokinys su vardu \"" << vardas << "\" nerastas." << endl;
}
// Funkcija: atnaujintiPazymi
// void - nieko negrazina, tik pakeicia pazymi masyve
// Si funkcija leidzia pakeisti konkretu mokinio pazymi
void atnaujintiPazymi()
{
    if (mokiniuSk == 0)
    {
        cout << "Mokiniu sarasas tuscias." << endl;
        return;
    }
    string vardas;
    cout << "Iveskite mokinio varda: ";
    cin >> vardas;
    // Ieskome mokinio
    for (int i = 0; i < mokiniuSk; i++)
    {
        if (vardai[i] == vardas)
        {
            int numeris;
            // while ciklas tikrina ar pazymio numeris tinkamas
            while (true)
            {
                cout << "Iveskite pazymio numeri (1-10): ";
                cin >> numeris;
                // Tikriname ar numeris nuo 1 iki 10
                if (numeris >= 1 && numeris <= 10)
                {
                    break; // Tinkamas numeris - iseiname is ciklo
                }
                else
                {
                    cout << "Klaida! Numeris turi buti nuo 1 iki 10." << endl;
                }
            }
            int naujasPazymys;
            // while ciklas tikrina ar naujas pazymys tinkamas
            while (true)
            {
                cout << "Iveskite nauja pazymi (0-10): ";
                cin >> naujasPazymys;
                if (naujasPazymys >= 0 && naujasPazymys <= 10)
                {
                    break;
                }
                else
                {
                    cout << "Klaida! Pazymys turi buti nuo 0 iki 10." << endl;
                }
            }
            // numeris-1 nes vartotojas iveda 1-10, bet masyve numeruojama 0-9
            pazymiai[i][numeris - 1] = naujasPazymys;
            cout << "Pazymys sekmingai atnaujintas!" << endl;
            return;
        }
    }
    cout << "Mokinys su vardu \"" << vardas << "\" nerastas." << endl;
}
// Funkcija: pasalintiMokini
// void - nieko negrazina, tik pasalina mokini is masyvu
// Si funkcija suranda mokini ir pasalina ji, paslinkdama kitus mokinius
void pasalintiMokini()
{
    if (mokiniuSk == 0)
    {
        cout << "Mokiniu sarasas tuscias." << endl;
        return;
    }
    string vardas;
    cout << "Iveskite mokinio varda, kuri norite pasalinti: ";
    cin >> vardas;
    // Ieskome mokinio
    for (int i = 0; i < mokiniuSk; i++)
    {
        if (vardai[i] == vardas)
        {
            // Randam mokini - dabar reikia ji pasalinti
            // Tai darome paslinkdami visus mokinius po jo per viena pozicija i kaire
            // Pvz: [0, 1, 2, 3] salinant 1 -> [0, 2, 3]
            for (int k = i; k < mokiniuSk - 1; k++)
            {
                // Perkeliame sekancio mokinio duomenis i dabartine pozicija
                vardai[k] = vardai[k + 1]; // Perkeliame varda
                // Perkeliame visus 10 pazymiu
                for (int j = 0; j < 10; j++)
                {
                    pazymiai[k][j] = pazymiai[k + 1][j];
                }
            }
            mokiniuSk--; // Sumaziname mokiniu skaiciu vienetu
            cout << "Mokinys \"" << vardas << "\" sekmingai pasalintas!" << endl;
            return;
        }
    }
    cout << "Mokinys su vardu \"" << vardas << "\" nerastas." << endl;
}
// int - grazina sveikaji skaiciu (0 reiskia kad programa baigesi sekmingai)
int main()
{
    // while(true) - begalis ciklas, programa veiks tol, kol vartotojas pasirinks iseiti
    while (true)
    {
        cout << "Mokiniu pazymiu sistema" << endl;
        cout << "1. Ivesti nauja mokini" << endl;
        cout << "2. Rodyti visu mokiniu pazymius" << endl;
        cout << "3. Rodyti konkretaus mokinio pazymius" << endl;
        cout << "4. Atnaujinti pazymi" << endl;
        cout << "5. Pasalinti mokini" << endl;
        cout << "6. Iseiti is programos" << endl;
        cout << "Pasirinkite veiksma (1-6): ";
        int pasirinkimas;
        cin >> pasirinkimas; // Nuskaito vartotojo pasirinkima
        // Kuri salyga pirma teisinga - tas blokas ivykdomas
        if (pasirinkimas == 1)
        {
            ivistiMokini(); // Mokinio ivedimo funkcija
        }
        else if (pasirinkimas == 2)
        {
            rodytiVisus(); // Visu mokiniu rodymo funkcija
        }
        else if (pasirinkimas == 3)
        {
            rodytiViena(); // Vieno mokinio rodymo funkcija
        }
        else if (pasirinkimas == 4)
        {
            atnaujintiPazymi(); // Pazymio atnaujinimo funkcija
        }
        else if (pasirinkimas == 5)
        {
            pasalintiMokini(); // Mokinio pasalinimo funkcija
        }
        else if (pasirinkimas == 6)
        {
            return 0; // Baigiama programa
        }
        else
        {
            // Jei vartotojas ivede kazka kita (ne 1-6)
            cout << "Neteisingas pasirinkimas! Bandykite dar karta." << endl;
        }
    }
    return 0; // Techniskai cia niekada nepasieksime, bet gera praktika tureti
}
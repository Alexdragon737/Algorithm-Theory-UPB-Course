#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

/*Coman Alexandru, grupa 1331, semigrupa B*/

//Definitii de tipuri de variabile

//Variabile globale
int x[100];

// Functii

/**
Citirea unui array de m elemente.
*/
void citireSir(int arr[], int& m)
{
    for (int i = 0; i < m; i++)
        cin >> arr[i];
}

/**
Afisarea unui array de m elemente.
Elementele vor fi separate de un singur spatiu.
La afisarea ultimului element, se va trece la linia urmatoare
*/
void afisareSir(int arr[], int& m)
{
    for (int i = 0; i < m; i++)
    {
        if (i == m - 1)
            cout << arr[i] << endl;
        else cout << arr[i] << " ";
    }
}

/**
Interschimbarea a doua numere intregi.
a -> b
b <- a
*/
void interschimbare(int* a, int* b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}


/**
 Calculam norma infinit a unei matrice M de dimensiuni m*m
*/
float norma_infinit(int m, float M[10][10])
{
    float norma = 0;
    for (int i = 0; i < m; i++)
    {
        float suma = 0;
        for (int j = 0; j < m; j++)
            suma += fabs(M[i][j]);
        if (suma > norma)
            norma = suma;
    }
    return norma;
}


/**
 Calculam norma 1 a unei matrice M de dimensiuni m*m
*/
float norma_1(int m, float M[10][10])
{
    float norma1 = 0;
    for (int i = 0; i < m; i++)
    {
        float suma = 0;
        for (int j = 0; j < m; j++)
            suma += fabs(M[j][i]);
        if (suma > norma1)
            norma1 = suma;
    }
    return norma1;
}


/**
 Functia f(x) = x^2
*/
double f(double x)
{
    return x * x - 2;
}

/**
Functia f'(x) = 2*x (derivata functiei f(x) = x^2)
*/
double g(double x)
{
    return 2 * x;
}

/**
 Rezolva o ecuatie in R cu metoda coardei
*/
void rezolva_ecuatie()
{

    int a, b, n = 1;
    cout << "Dati intervalul de rezolvare a ecuatiei ";
    cin >> a >> b;
    double er, eps, x2;
    cout << "Dati marja de eroare ";
    cin >> eps;
    double x1 = a - f(a) * (b - a) / (f(b) - f(a));
    cout << "x1=" << x1 << endl;
    do
    {
        x2 = x1 - f(x1) * (b - x1) / (f(b) - f(x1));
        cout << "x2=" << x2 << endl;
        er = fabs(x2 - x1);
        x1 = x2;
        n++;
    } while (er > eps);
    cout << "Solutia ec este " << x1 << " obtinuta in " << n << " iteratii" << endl;
}

/**
 Rezolva o ecuatie cu metoda Newton(numita si metoa tangentei)
*/
void metoda_Newton()
{
    int a, b;
    cout << "Dati intervalul [a,b] de rezolvare a ecuatiei ";
    cin >> a >> b;
    int n;
    n = 1;
    double eps;
    cout << "Dati marja de eroare ";
    cin >> eps;
    double x0;
    x0 = b;
    cout << x0 << endl;
    double x1 = b - f(b) / g(b);
    cout << x1 << endl;
    double x2;
    double er;
    do
    {
        x2 = x1 - f(x1) / g(x1);
        cout << x2 << endl;
        er = fabs(x2 - x1);
        x1 = x2;
        n++;
    }     while (er > eps);
    cout << "Solutia ecuatiei este: " << scientific << setprecision(10) << x1 << " obtinuta in " << n << " iteratii" << endl;
}


/**
 Conditia de validare pentru permutari
*/
bool validarePermutari(int y, int k, int x[10])
{
    for (int j = 0; j < k; j++)
    {
        if (x[j] == y)
            return false;
    }
    return true;
}


/**
 Genereaza toate permutarile
*/
void generare_permutari()
{
    int n, k, nr_sol, x[10], v;
    cout << "Generare permutari de n=";
    cin >> n;
    k = 0;
    nr_sol = 0;
    x[0] = 0;
    while (k > -1)
    {
        v = 0;
        while (v == 0 && x[k] + 1 <= n)
        {
            x[k] = x[k] + 1;
            if (validarePermutari(x[k], k, x) == true)
                v = 1;
        }
        if (v == 0)
            k--;
        else
        {
            if (k == n - 1) // Am gasit solutie
            {
                nr_sol++;
                for (int i = 0; i < n; i++)
                    cout << x[i] << " ";
                cout << endl;
            }
            else
            {
                k++;
                x[k] = 0;
            }
        }
    }
    cout << "Nr permutarilor de " << n << " este " << nr_sol << endl;
}


/**
* Calculeaza factorialul unui numar n
*/
long factorial(int n)
{
    if (n == 0)
        return 1;
    else return n * factorial(n - 1);
}


/**
* Calculeaza al n-lea termen din sirul Fibonacci
*/
long fibonacci(int n)
{
    if (n <= 1)
        return n;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}

/**
* Calculeaza functia Ackermann pentru doua valori A si B
*/
int ackermann_recursiv(int a, int b)
{
    if (a == 0)
        return b + 1;
    else if (a > 0 && b == 0)
        return ackermann_recursiv(a - 1, 1);
    else if (a > 0 && b > 0)
        return ackermann_recursiv(a - 1, ackermann_recursiv(a, b - 1));
    return -1; // nu o sa se intample;
}


void ackermann_iterativ(int &k)
{
    int m, n, a[100] = { 0 };
    cout << "m="; cin >> m;
    cout << "n="; cin >> n;
    a[1] = m;
    a[2] = n;
    while (k > 1)
    {
        if (a[k - 1] == 0)
        {
            a[k - 1] = a[k] + 1;
            k--;
        }
        else if (a[k] == 0)
        {
            a[k - 1] = a[k - 1] - 1;
            a[k] = 1;
        }
        else
        {
            a[k + 1] = a[k] - 1;
            a[k] = a[k - 1];
            a[k - 1] = a[k - 1] - 1;
            k++;
        }
    }
    cout << a[1] << endl;
}

/**
* Conditia de validare pentru combinari
*/
bool validare_combinari(int y, int k, int x[10])
{
    if (k == 1)
        return true;
    else
    {
        if (y > x[k - 1])
            return true;
        else
            return false;
    }
}

/**
* Conditia de validare pentru aranjamente
*/
bool validare_aranjamente(int y, int k, int x[10])
{
    if (k == 1)
        return true;
    int l = 1;
    for (int i = 1; i < k; i++)
        if (y == x[i])
            l = 0;
    if (l == 0)
        return false;
    else
        return true;
}



/**
* Conditia de validare pentru problema reginelor
*/
bool validare_regine(int y, int k, int x[20])
{
    for (int j = 1; j < k; j++)
        if (y == x[j] || (abs(y - x[j]) == abs(k - j)))
            return false;
    return true;
}


/**
* Conditia de validare pentru problema turelor
*/
bool validare_ture(int y, int k, int x[20])
{
    for (int j = 1; j < k; j++)
        if (y == x[j])
            return false;
    return true;
}


/**
* Conditia de validare pentru problema calutilor
*/
bool validare_caluti(int y, int k, int x[10])
{
    if (x[k] - 2 == x[k - 1] || x[k] + 2 == x[k - 1] ||
        x[k] - 1 == x[k - 2] || x[k] + 1 == x[k - 2])
        return false;
    return true;
}

/**
* Conditia de validare pentru problema comisului voiajor
*/
bool validareComisVoiajor(int k, int a[10][10], int x[20], int n)
{
    if (a[x[k]][x[k - 1]] == 0)
        return false;
    if (k == n - 1 && a[x[k]][x[1]] == 0)
        return false;
    for (int i = 0; i < n; i++)
        if (x[k] == x[i])
            return false;
    return true;
}

/**
* Conditia de validare pentru problema parantezelor
*/
int cond_paranteze(int k)
{
    int i = 1, nr1 = 0, nr2 = 0, g, nr = 0;
    if (x[1] == 1)
    {
        for (i = 1; i <= k; i++)
        {
            if (x[i] == 1)
                nr1++;
            if (x[i] == 0)
                nr2++;
        }
        if (nr1 == k / 2 && nr2 == k / 2)
        {
            for (i = 1; i <= k; i++)
            {
                if (x[i] == 1)
                {
                    for (g = i + 1; g <= k; g++)
                        if (x[g] == 0)
                        {
                            x[g] = 2;
                            nr++;
                            g = k + 1;
                        }
                }
            }
            for (g = 1; g <= k; g++)
                if (x[g] == 2)
                    x[g] = 0;
            if (nr == k / 2)
                return 1;
            else return 0;
        }
        else return 0;
    }
    else return 0;
}


/**
* Generam combinari de n luate cate k
*/
void generare_combinari()
{
    int n, p;
    cout << "Generare combinari de n=";
    cin >> n;
    cout << "Luate cate p=";
    cin >> p;
    int k = 1;
    int nrsol = 0;
    int x[10];
    x[0] = 0;
    int v;
    while (k > 0)
    {
        if (x[k] < n)
        {
            x[k] = x[k] + 1;
            if (validare_combinari(x[k], k, x))
            {
                if (p == k)
                {
                    v = 1;
                    for (int i = 1; i <= p; i++)
                    {
                        cout << x[i] << " ";
                    }
                    cout << endl;
                    nrsol++;
                }
                else
                    k++;
            }
        }
        else
        {
            x[k] = 0;
            k--;
        }
    }
    cout << "Nr combinarilor de n=" << n << " luate cate p=" << p << " este " << nrsol << endl;
}


/**
* Generam aranjamente de n luate cate k
*/
void generare_aranjamente()
{
    int n, p;
    cout << "Generare aranjamente de n=";
    cin >> n;
    cout << "Luate cate p=";
    cin >> p;
    int k = 1;
    int nrsol = 0;
    int x[10];
    x[1] = 0;
    int v;
    while (k > 0)
    {
        if (x[k] < n)
        {
            x[k] = x[k] + 1;
            if (validare_aranjamente(x[k], k, x))
                if (p == k)
                {
                    nrsol++;
                    for (int i = 1; i <= p; i++)
                        cout << x[i] << " ";
                    cout << endl;

                }
                else k++;
        }
        else
        {
            x[k] = 0;
            k--;
        }
    }
}

/**
* Algoritmul pentru problema reginelor
*/
void generare_regine(int n)
{
    int k = 1, nr_sol = 0, v = 0, x[20] = { 0 };
    x[1] = 0;
    while (k > 0)
    {
        v = 0;
        while (v == 0 && x[k] + 1 <= n)
        {
            x[k] = x[k] + 1;
            if (validare_regine(x[k], k, x) == true)
                v = 1;
        }
        if (v == 0)
            k--;
        else
        {
            if (k == n)
            {
                nr_sol++;
                afisareSir(x, n);
            }
            else
            {
                k++;
                x[k] = 0;
            }
        }
    }
    cout << "Numarul de posibilitati: " << nr_sol << endl;
}

/**
* Algoritmul pentru problema turelor
*/
void generare_ture(int n)
{
    int k = 1, nr_sol = 0, v = 0, x[20] = { 0 };
    x[1] = 0;
    while (k > 0)
    {
        v = 0;
        while (v == 0 && x[k] + 1 <= n)
        {
            x[k] = x[k] + 1;
            if (validare_ture(x[k], k, x) == true)
                v = 1;
        }
        if (v == 0)
            k--;
        else
        {
            if (k == n)
            {
                nr_sol++;
                afisareSir(x, n);
            }
            else
            {
                k++;
                x[k] = 0;
            }
        }
    }
    cout << "Numarul de posibilitati: " << nr_sol << endl;
}


/**
* Algoritmul pentru problema calutilor
*/
void generare_caluti(int &n)
{
    int x[10];
    int k = 0;
    x[0] = -1;
    int nr_sol = 0;
    int v = 0;
    while (k > -1)
    {
        v = 0;
        while (v == 0 && x[k] + 1 <= n - 1)
        {
            x[k]++;
            if (validare_caluti(x[k], k, x) == true)
                v = 1;
        }
        if (v == 0)
            k--;
        else
        {
            if (k == n - 1)
            {
                nr_sol++;
                for (int i = 0; i <= n - 1; i++)
                {
                    for (int j = 0; j <= n - 1; j++)
                    {
                        if (x[i] == j)
                            cout << "* ";
                        else
                            cout << "- ";
                    }
                    cout << endl;
                }
                cout << endl;

            }
            else
            {
                k++;
                x[k] = -1;
            }
        }
    }
    cout << nr_sol << endl;
}

/**
* Algoritmul pentru problema comisului voiajor
*/
void generareComisVoiajor()
{
    int n, m, b, y, x[20] = { 0 }, a[10][10] = { 0 };
    cout << "n="; cin >> n;
    cout << "m="; cin >> m;
    for (int i = 0; i < m; i++)
    {
        cout << "b="; cin >> b;
        cout << "y="; cin >> y;
        a[b][y] = a[y][b] = 1;
    }
    x[n] = 1;
    int k = 1;
    x[0] = 1;
    while (k > 0)
    {
        if (k == n)
        {
            for (int i = 0; i < n; i++)
                cout << x[i] << endl;
            k--;
        }
        else
        {
            if (x[k] < n - 1)
                x[k] = x[k] + 1;
            if (validareComisVoiajor(k, a, x, n))
                k++;
            else
            {
                x[k] = 0;
                k--;
            }
        }
    }
}


/**
* Generam toate modurile in care putem deschide si inchide o paranteza
*/
void generare_paranteze(int k)
{
    int i;
    for (i = 1; i <= k; i++)
        if (x[i] == 1)
            cout << "(";
        else if (x[i] == 0)
            cout << ")";
    cout << endl;
}


/**
* Plata cu bancnote nelimitate.
*/
void plataNelimitat()
{
    int n;
    int v[10], N[10];
    int s;
    cout << "nr de bancnote n=";
    cin >> n;
    cout << "valorile bancnotelor sunt in ordine descrescatoare" << endl;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << "Dati suma s=";
    cin >> s;
    int sc = s;
    int T = 0;
    for (int i = 0; i < n; i++)
    {
        N[i] = sc / v[i];
        sc = sc % v[i];
        T = T + N[i] * v[i];
    }
    if (s == T)
    {
        cout << s << "=";
        for (int i = 0; i < n; i++)
        {
            cout << N[i] << "*" << v[i];
            if (i < n - 1)
                cout << "+";
        }
        cout << endl;
    }
    else
        cout << "Algoritmul Greedy nu a gasit solutia";
}

/**
* Problema platii cu bancnote limitate
*/
void bancnoteLimitate(int s, int nrb, int n[], int v[], int k[])
{
    int t = 0;
    int sc = s;
    int sg = 0;
    int i;

    for (int i = 0; i < nrb; i++)
    {
        n[i] = sc / v[i];
        if (n[i] <= k[i])
        {
            sc = sc % v[i];
            k[i] = k[i] - n[i];
        }
        else
        {
            n[i] = k[i];
            sc = sc - n[i] * v[i];
            k[i] = 0;
        }
        t = t + n[i] * v[i];
    }
    if (t == s)
    {
        cout << "Suma este: " << t << " = ";
        for (i = 0; i < nrb; i++)
        {
            cout << n[i] << "*" << v[i];
            if (i < nrb - 1)
                cout << "+";
        }
        cout << "\n";
    }
    else
    {
        cout << "Nu gasim solutia cu algoritmul Greedy" << endl;
    }
}

/**
Partitionarea sirului pentru quick sort.
*/
int Partitionare(int arr[], int low, int high)
{
    int pivot = arr[high];
    int a = (low - 1);
    for (int i = low; i <= high - 1; i++)
    {
        if (arr[i] < pivot)
        {
            a++;
            interschimbare(&arr[a], &arr[i]);
        }
    }
    interschimbare(&arr[a + 1], &arr[high]);
    return (a + 1);
}


/**
Algoritmul de sortare rapida
*/
void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int part = Partitionare(arr, low, high);
        quick_sort(arr, low, part - 1);
        quick_sort(arr, part + 1, high);
    }
}


/**
* Interclasarea pentru Merge Sort
*/
void merge(int arr[], int stanga, int mijloc, int dreapta) 
{
    int n1 = mijloc - stanga + 1;
    int n2 = dreapta - mijloc;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[stanga +i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mijloc + 1 + j];
    int i, j, k;
    i = 0;
    j = 0;
    k = stanga;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


/**
* Algoritmul de sortare prin interclasare
*/
void merge_sort(int arr[], int stanga, int dreapta) {
    if (stanga < dreapta) {
        int m = stanga + (dreapta - stanga) / 2;
        merge_sort(arr, stanga, m);
        merge_sort(arr, m + 1, dreapta);
        merge(arr, stanga, m, dreapta);
    }
}


/**
* Algoritmul de cautare binara
*/
int cautare_binara(int arr[], int stanga, int dreapta, int x)
{
    if (dreapta >= stanga)
    {
        int mijloc = stanga + (dreapta - stanga) / 2;
        if (arr[mijloc] == x)
            return mijloc;
        if (arr[mijloc] > x)
            return cautare_binara(arr, stanga, mijloc - 1, x);
        return cautare_binara(arr, mijloc + 1, dreapta, x);
    }
    return -1;
}


/**
* Turnurile din Hanoi
*/
void Hanoi(int n, char turn_sursa, char turn_destinatie, char turn_auxiliar)
{
    if (n == 1)
    {
        cout << "Miscam discul 1 de pe turnul " << turn_sursa << " pe turnul " << turn_destinatie << endl;
        return;
    }
    Hanoi(n - 1, turn_sursa, turn_auxiliar, turn_destinatie);
    cout << "Miscam discul " << n << " de pe turnul " << turn_sursa << " pe turnul " << turn_destinatie << endl;
    Hanoi(n - 1, turn_auxiliar, turn_destinatie, turn_sursa);
}

/**
* Conditia de validare pentru problema de backtracking recursiv
*/
bool validRecursiv(int st[20], int k)
{
    for (int i = 1; i < k; i++)
        if (st[i] == st[k])
            return false;
    return true;
}

/**
* Problema rezolvata cu Backtracking recursiv
*/
void rBacktracking(int st[20], int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        st[k] = i;
        if (validRecursiv(st, k) == true)
            if (k == n)
                afisareSir(st, n);
            else rBacktracking(st, k + 1, n);
    }
}

/**
* Maximul dintr-un sir
*/
int maxim(int v[], int s, int d)
{
    int mij, max1, max2;
    if (s == d)
        return v[s];
    else
    {
        mij = (s + d) / 2;
        max1 = maxim(v, s, mij);
        max2 = maxim(v, mij + 1, d);
        if (max1 > max2)
            return max1;
        else
            return max2;
    }
}


/**
* Minimul dintr-un sir
*/
int minim(int v[], int s, int d)
{
    int mij, min1, min2;
    if (s == d)
        return v[s];
    else
    {
        mij = (s + d) / 2;
        min1 = minim(v, s, mij);
        min2 = minim(v, mij + 1, d);
        if (min1 < min2)
            return min1;
        else
            return min2;
    }
}

void arculLuiBuffon()
{
    double x; // Coordonatele centrului acului
    double k; // Unghiul dintre poz verticala si ac
    double l; // Lungimea acului
    double n; // Nr de incercari
    double p = 0; // Nr de incercari pozitive
    double y; // sin(k) * l
    double pi;
    long i; // Nr de iteratii

    srand(time(NULL));
    cout << "numar de incercari" << endl;;
    cin >> n;
    l = 1;
    for (i = 0; i < n; i++)
    {
        k = (double)rand() / (RAND_MAX) * 360;// Unghi aleator
        x = (double)rand() / (RAND_MAX * 2);// poz aleatoare
        y = (l / 2) * sin(k);
        if (x <= y)
        {
            p++;
        }
    }
    pi = (l * n) / (p);
    cout << endl << p;
    cout << endl << pi << endl;
}


int main()
{
    int op, op1, op2, op3, op4, op5, op6, op7, op8;
    float A[10][10];
    float n_1, n_inf;
    do {
        cout << "Programe T.A. " << endl;
        cout << "  1. Exemple de algoritmi" << endl;
        cout << "  2. Metoda Backtracking" << endl;
        cout << "  3. Recursivitate" << endl;
        cout << "  4. Divide et Impera" << endl;
        cout << "  5. Metoda Greedy" << endl;
        cout << "  6. Programare dinamica" << endl;
        cout << "  7. Metoda \"Branch and Bound\"" << endl;
        cout << "  0. Stop" << endl;
        cout << " Introduceti optiunea dorita: ";
        cin >> op;
        switch (op)
        {
            case 1:
            {
                do
                {
                    cout << "Exemple de algoritmi" << endl;
                    cout << "1.1 Norme de matrice" << endl;
                    cout << "1.2 Metoda coardei pentru ecuatii in R" << endl;
                    cout << "1.3 Metoda Newton" << endl;
                    cout << "1.0 Stop" << endl;
                    cout << "Introdu optiunea dorita: " << endl;
                    cin >> op1;
                    switch (op1)
                    {
                    case 1: // Norme de matrice
                    {   
                        int m;
                        cout << "Dimensiune matrice =  " << endl;
                        cin >> m;
                        for (int i = 0; i < m; i++)
                            for (int j = 0; j < m; j++)
                            {
                                cout << "Elementul [" << i + 1 << "][" << j + 1 << "] = ";
                                cin >> A[i][j];
                            }
                        for (int i = 0; i < m; i++)
                        {
                            for (int j = 0; j < m; j++)
                                cout << A[i][j] << " ";
                            cout << endl;
                        }
                        n_inf = norma_infinit(m, A);
                        cout << "Norma infinit a matricei A este: " << n_inf << endl;
                        n_1 = norma_1(m, A);
                        cout << "Norma 1 a matricei A este: " << n_1 << endl;
                        break;
                    }
                    case 2: // Metoda coardei pentru ecuatii in R
                    {
                        rezolva_ecuatie();
                        break; 
                    }
                    case 3: // Metoda Newton
                    {
                        metoda_Newton();
                        break;
                    }
                    case 0:
                    {
                        cout << "Iesire submeniu 1" << endl;
                    }
                    default:
                    {
                        cout << "Optiune invalida, introduceti doar valori numerice in intervalul [0, 3]" << endl;
                    }
                    }
                }                 
                while (op1 != 0);
                break; // End submenu 1
            }
            case 2: // Metoda Backtracking
            {
                do
                {
                    cout << "Metoda backtracking" << endl;
                    cout << "  2.1. Generarea permutarilor" << endl;
                    cout << "  2.2. Generarea combinarilor" << endl;
                    cout << "  2.3. Generarea aranjamentelor" << endl;
                    cout << "  2.4. Problema reginelor " << endl;
                    cout << "  2.5. Problema turelor " << endl;
                    cout << "  2.6. Problema calutilor " << endl;
                    cout << "  2.7. Problema comis voiajor " << endl;
                    cout << "  2.8. Problema parantezelor " << endl;
                    cout << "  2.0. Stop" << endl;
                    cout << "Introduceti optiunea dorita:  ";
                    cin >> op2;
                    switch (op2)
                    {
                        case 1:
                        {    
                            generare_permutari();
                            break; 
                        }
                        case 2:
                        {
                            generare_combinari();
                            break; 
                        }
                        case 3:
                        {    
                            generare_aranjamente();
                            break;
                        }
                        case 4:
                        {
                            int n;
                            cout << "Introdu numarul de regine n=";
                            cin >> n;
                            generare_regine(n);
                            break;
                        }
                        case 5:
                        {
                            int n;
                            cout << "Introdu numarul de ture n=";
                            cin >> n;
                            generare_ture(n);
                            break;
                        }
                        case 6:
                        {
                            int n;
                            cout << "Introdu numarul de caluti n=";
                            cin >> n;
                            generare_caluti(n);
                            break;
                        }
                        case 7:
                        {
                            generareComisVoiajor();
                            break;
                        }
                        case 8:
                        {
                            int k,n;
                            cout << "n=";  cin >> n;
                            k = 1;
                            x[k] = -1;
                            while (k)
                            {
                                x[k]++;
                                if (x[k] > 1) k--;
                                else if (k == n)
                                {
                                    if (cond_paranteze(k))
                                        generare_paranteze(k);
                                }
                                else x[++k] = -1;
                            }
                            break;
                        }
                        case 0:
                        {
                            cout << "Incheiere submeniu 2" << endl;
                            break; 
                        }
                        default:
                        {
                            cout << "Optiune invalida, introduceti doar valori numerice in intervalul [0, 8]" << endl;
                            break;
                        }

                    } // End op 2
                }                 
                while (op2 != 0);
                break;
            }
            case 3: // Recursivitate
            { 
                do 
                {
                    cout << "Recursivitate" << endl;
                    cout << "  3.1 Factorialul unui numar " << endl;
                    cout << "  3.2 Sirul lui Fibonacci " << endl;
                    cout << "  3.3 Functia Ackermann" << endl;
                    cout << "  3.4 Functia Ackermann - varianta iterativa" << endl;
                    cout << "  3.5 Varianta recursiva Backtracking(o problema)" << endl;
                    cout << "  3.6 Problema labirintului" << endl;
                    cout << "  3.0 Stop" << endl;
                    cout << "Introdu optiunea dorita ";
                    cin >> op3;
                    switch (op3)
                    {
                        int n;
                        case 1: // Factorial
                        {
                            cout << "Introdu numarul caruia vrei sa-i calculezi factorialul ";
                            cin >> n;
                            cout << "Factorialul numarului " << n << " este " << factorial(n) << endl;
                            break; 
                        }
                        case 2:
                        { 
                            cout << "Introdu numarul n pentru a obtine al n-lea termen din sirul Fibonnacci ";
                            cin >> n;
                            cout << "Al " << n << "-lea termen din sirul Fibonacci este " << fibonacci(n) << endl;
                            break;
                        }
                        case 3:
                        {    
                            cout << "Functia Ackermann recursiva ";
                            int a, b;
                            cout << "Introdu valorile a si b pentru calcularea functiei Ackermann" << endl;
                            cin >> a >> b;
                            cout << "Pentru valorile " << a << " si " << b << " functia Ackermann intoarce valoarea " << ackermann_recursiv(a, b) << endl;
                            break;
                        }
                        case 4:
                        {
                            int k;
                            cout << "Functia Ackermann iterativa ";
                            cout << "Introdu termenul k=" << endl;
                            cin >> k;
                            ackermann_iterativ(k);
                            break; 
                        }
                        case 5:
                        {
                            int st[20];
                            int n;
                            cout << "n="; cin >> n;
                            rBacktracking(st, 1, n);
                            break;
                        }
                        case 0:
                        {
                            cout << "Iesire din submeniul 3 " << endl;
                            break; 
                        }
                        default:
                        {
                            cout << "Optiune invalida, introduceti doar valori numerice in intervalul [0, 6]" << endl;
                            break;
                        }
                    }
                }                 
                while (op3 != 0); // End op 3
                break;
            }
            case 4: // Divide et Impera
            {
                do {
                    cout << "Divide et Impera" << endl;
                    cout << "  4.1. Sortarea prin interclasare" << endl;
                    cout << "  4.2. Sortarea rapida" << endl;
                    cout << "  4.3. Cautarea binara" << endl;
                    cout << "  4.4. Maximul unui sir de numere" << endl;
                    cout << "  4.5. Minimul unui sir de numere" << endl;
                    cout << "  4.6. Turnurile din Hanoi" << endl;
                    cout << "  4.0. Iesire din submeniu 4" << endl;
                    cout << "Introdu optiunea dorita " << endl;
                    cin >> op4;
                    switch (op4)
                    {
                        case 1:
                        { 
                            int m;
                            cout << "Introdu nr de elemente ale sirului" << endl;
                            cin >> m;
                            int* arr = (int*)malloc(m * sizeof(int));
                            citireSir(arr, m);
                            merge_sort(arr, 0, m - 1);
                            afisareSir(arr, m);
                            break; 
                        }
                        case 2:
                        {
                            int m;
                            cout << "Introdu nr de elemente ale sirului" << endl;
                            cin >> m;
                            int *arr = (int*)malloc(m * sizeof(int));
                            citireSir(arr, m);
                            quick_sort(arr, 0, m-1);
                            afisareSir(arr,m);
                            break; 
                        }
                        case 3:
                        {
                            int m;
                            cout << "Introdu nr de elemente ale sirului" << endl;
                            cin >> m;
                            cout << "Introdu elementul x pe care il cauti in sir" << endl;
                            int x;
                            cin >> x;
                            int* arr = (int*)malloc(m * sizeof(int));
                            citireSir(arr, m);
                            int rezultat =cautare_binara(arr, 0, m - 1,x);
                            // Am folosit short-hand "if" fiindca evaluez ceva simplu
                            // Altfel as fi scris "if"-ul in forma lui clasica
                            // Si pare mai elegant in cod, chit ca in general e greu sa citesti asa ceva
                            (rezultat == -1) ? cout << "Elementul nu se afla in sir"<<endl 
                                             : cout << "Elementul este prezent pe pozitia " << rezultat+1 << endl;
                        }
                        case 4:
                        {
                            int n;
                            cout << "n=";
                            cin >> n;
                            int* v = (int*)malloc(n * sizeof(int));
                            citireSir(v, n);
                            cout << "Maximul din sir este " << maxim(v, 0, n - 1);
                            break;
                        }
                        case 5:
                        {
                            int n;
                            cout << "n=";
                            cin >> n;
                            int* v = (int*)malloc(n * sizeof(int));
                            citireSir(v, n);
                            cout << "Minimul din sir este " << minim(v, 0, n - 1);
                            break;
                        }
                        case 6:
                        {
                            int m;
                            cout << "Introdu numarul de discuri pentru problema " << endl;
                            cin >> m;
                            Hanoi(m, 'A', 'B', 'C');
                        }
                        case 0:
                        {
                            cout << "Iesire din submeniul 4 " << endl; 
                            break;
                        }
                        default:
                        {
                            cout << "Optiune invalida, introduceti doar valori numerice in intervalul [0, 6]" << endl;
                            break;
                        }
                    }
                }                 
                while (op4 != 0); // End op4
            }
            case 5://Metoda Greedy
            {
                do
                {
                    cout << "Metoda Greedy" << endl;
                    cout << "  5.1. Problema comisului voiajor" << endl;
                    cout << "  5.2. Plata unei sume cu nr nelimitat de bacnote" << endl;
                    cout << "  5.3. Plata unei sume cu nr limitat de bacnote" << endl;
                    cout << "  5.4. Acoperirea unei table de sah cu mutari calut" << endl;
                    cout << "  5.0. Iesire din submeniu 5" << endl;
                    cout << "Introdu optiunea dorita: " << endl;
                    cin >> op5;
                    switch (op5)
                    {
                        case 1:
                        {
                            break;
                        }
                        case 2:
                        {
                            //Plata cu nr nelimitat de bacnote
                            plataNelimitat();
                            break;
                        }
                        case 3:
                        {
                            int nrb, s, i, j, l;
                            int k[10], n[10], v[10];
                            cout << "Dati suma "; cin >> s;
                            cout << "Dati nr de bancnote "; cin >> nrb;
                            cout << "Dati valorile bancnotelor din fiecare tip ";
                            for (i = 0; i < nrb; i++)
                                cin >> v[i];
                            cout << "Dati numarul de bancnote din fiecare tip ";
                            for (j = 0; j < nrb; j++)
                                cin >> k[j];
                            for (l = 0; l < nrb; l++)
                                n[l] = 0;
                            bancnoteLimitate(s, nrb, n, v, k);
                            cout << endl;
                            break;
                        }
                        case 0:
                        {
                            cout << "Iesire din submeniu 5" << endl;
                            break;
                        }
                        default:
                        {    
                            cout << "Optiune invalida, introduceti doar valori numerice in intervalul [0, 4]" << endl;
                            break; 
                        }
                    }
                }         
                while (op5 != 0); //End op5
                break;
            }
            case 6:
            {
                do
                {
                    cout << "Programare dinamica" << endl;
                    cout << "   6.1 Produs de matrici cu nr, minim de inmultiri" << endl;
                    cout << "   6.2 Suma maxima intr-un triunghi de numere" << endl;
                    cout << "   6.3 Verificare compunere sir intr-un alfabet dat" << endl;
                    cout << "   6.0 Iesire din meniul 6" << endl;
                    cout << "   Citeste optiunea din meniul 6:";
                    cin >> op6;
                    switch (op6)
                    {
                        case 1:
                            break;
                        case 0:
                            break;
                    }
                }                 
                while (op6 != 0); // End op6
                break;
            }
            case 7:
            {
                do
                {
                    cout << "Metoda \"Branch and Bound\"" << endl;
                    cout << "   7.1 Jocul Perspico" << endl;
                    cout << "   7.0 Iesire din submeniul 7" << endl;
                    cout << "Introdu optiunea dorita: ";
                    cin >> op7;
                    switch (op7)
                    {
                        case 1:
                            break;
                        case 0:
                            break;
                    }
                }                 
                while (op7 != 0); // End op7
                break;
            }
            case 8:
            {
                do
                {
                    cout << "Metode probabiliste" << endl;
                    cout << "  8.1. Arcul lui Buffon" << endl;
                    cout << "  8.2. Aruncare sageata" << endl;
                    cout << "  8.3. Aproximare integrala" << endl;
                    cout << "  8.4. Gasire element mai mare decat media aritmetica" << endl;
                    cout << "  8.5. Algoritm probabilist pentru problema a N regine" << endl;
                    cin >> op8;
                    switch (op8)
                    {
                        case 1:
                            arculLuiBuffon();
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;
                        case 5: 
                            break;
                        case 0:
                            break;
                    }
                }                 
                while (op8 != 0);
                break;
            }
            case 0: // Exit meniu principal
            { 
                break; 
            }
            default:
            {
                cout << "Optiune invalida, introduceti doar valori numerice in intervalul [0, 8]" << endl;
                break; 
            }
        }
    }    
    while (op != 0); // End program
    return 0;
}


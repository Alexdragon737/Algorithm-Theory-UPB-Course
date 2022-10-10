#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>

using namespace std;

// Functii

/**
Citirea unui array de m elemente.
*/
void citireSir(int arr[],int &m)
{
    for (int i = 0; i < m; i++)
        cin >> arr[i];
}

/**
Afisarea unui array de m elemente.
Elementele vor fi separate de un singur spatiu.
*/
void afisareSir(int arr[], int&m)
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
void interschimbare(int& a, int& b)
{
    int aux = a;
    a = b;
    b = aux;
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
    }     while (er > eps);
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
    }     
    while (er > eps);
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
    if (n<=1)
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
        return ackermann_recursiv(a - 1, ackermann_recursiv(a,b-1));
    return -1; // nu o sa se intample;
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
    cout << "Nr combinarilor de n=" << n << " luate cate p=" << p << " este " << nrsol << "\n";
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
            i++;
            interschimbare(arr[i], arr[high]);
        }
    }
    interschimbare(arr[a + 1], arr[high]);
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
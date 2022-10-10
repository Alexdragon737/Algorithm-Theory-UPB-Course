/*
I
2. Program de conversie a unui numar din baza 10 in baza 2 folosind stiva.
*/

#include<iostream>
#include<stack>

using namespace std;

void conversie_binar(int num) {
	stack<int> st;
	while (num > 0) {
		int rem = num % 2; // Restul impartirii la 2
		num = num / 2; //Un numar nou rezultat prin impartire la 2
		st.push(rem); //Restul este introdus in stiva
	}
	while (!st.empty()) {
		int elem;
		elem = st.top(); // Accesam urmatorul element
		st.pop(); //Scoatem elementul de sus
		cout << elem;
	}
	cout << endl;
}

int main() {
	conversie_binar(141);
	conversie_binar(65535);
}
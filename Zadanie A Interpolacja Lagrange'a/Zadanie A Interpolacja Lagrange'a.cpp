// Zadanie A Interpolacja Lagrange'a.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void menu(int &wybor)
{
	cout << "====================================================================================================";
	cout << "\nProgram do obliczania Wartosci Interpolowanych oraz Ekstrapolowanych metoda wielomianowa Lagrange'a" << endl;
	cout << "====================================================================================================\n" << endl;
	cout << "Czy chcesz wczytac plik? czy wolisz podac liczby z klawiatury?\n" << endl;
	cout << "1: Klawiatura" << endl;
	cout << "2: Wczesniej przygotowany plik\n" << endl;
	cout << "Twoj wybor: "; cin >> wybor;	
}

void obliczenia(int ilosc, double wartosc, double x[], double y[])
{

	double wynik[100] = {0};
	double suma = 0;

	for (int i = 0; i < ilosc; i++) {

		wynik[i] = y[i];
		for (int j = 0; j < ilosc; j++)
		{
			if (x[i] != x[j])
			{
				wynik[i] *= (1.0 * wartosc - x[j]);
			}
		}
		for (int j = 0; j < ilosc; j++)
		{
			if (x[i] != x[j])
			{
				wynik[i] /= (1.0 * x[i] - x[j]);
			}
		}
	}
	cout << "\nWartosc szukanego wyrazenia: ";
	for (int i = 0; i < ilosc; i++)
	{	
		suma += (wynik[i] * 1.0);
	}
	cout << " = " << suma << endl;
}


int main()
{
	int wybor;
	string odp;

	menu(wybor);
	switch (wybor)
	{
		case 1:
			{
				do {

					const int n = 100;
					
					int ilosc = 0;
					double wartosc = 0;
					double xTablica[n] = {0};
					double yTablica[n] = {0};

					cout << "\n<test> ile jest danych: "; cin >> ilosc;
					cout << "Podaj szukana wartosc: "; cin >> wartosc;
					cout << "\n";

					for (int i = 0; i < ilosc; i++)
					{
						cout << "wpisz x nr. " << i + 1 << ": "; cin >> xTablica[i];
						cout << "wpisz y nr. " << i + 1 << ": "; cin >> yTablica[i];
					}

					obliczenia(ilosc, wartosc, xTablica, yTablica);

				cout << "\n\nCzy chcesz powtorzyc dzialania ? (T/N): "; cin >> odp;
				} while (odp == "T" || odp == "t");
			}
			break;
		case 2:
			{
				do {
					const int n = 100;
					
					int iloscEl = 0;
					double wartosc = 0;
					double xTablica[n] = { 0 };
					double yTablica[n] = { 0 };
					int TestTablica[n] = { 0 };

					fstream fileOpen;
					fileOpen.open("przyklad.txt");
						
					if (!fileOpen.is_open()) 
					{
						cout << "Blad! Brak pliku badz problem z uprawnieniami :(" << endl;
					}
					else
					{	

						for (int i = 0; i < n; i++)
							if (!fileOpen.eof()) 
							{
								{
									fileOpen >> xTablica[i] >> yTablica[i];
								}
								
								iloscEl++;
							}

						cout << "\nZaczytane wartosci do tablicy: " << endl;
						cout << "Z pliku: przyklad.txt" << endl << endl;

						for (int i = 0; i < iloscEl; i++)
						{
							cout << setw(3) << xTablica[i] << " " << setw(5) << yTablica[i];
							cout << "\n";
						}

						cout << "\n\nPodaj szukana wartosc: "; cin >> wartosc;

						obliczenia(iloscEl, wartosc, xTablica, yTablica);

					}
				cout << "\n\nCzy chcesz powtorzyc dzialania ? (T/N): "; cin >> odp;
				}while (odp == "T" || odp == "t");			
			}
			break;
		default:
		{
			cout << "\nNie ma takiego numeru" << endl;
			break;
		}
	}		
	return 0;
}

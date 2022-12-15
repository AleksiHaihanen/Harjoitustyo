#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

int varatut[70];



int arvoHuone(int huonemaara) //Aliohjema asiakkaiden huoneennumeron arpomista varten
{
	int huoneennro = 1 + (rand() % huonemaara);
	int a = 1;
	int n = sizeof(varatut) / sizeof(*varatut);


	while (a == 1)
	{
		
		bool exists = find(varatut, varatut + n, huoneennro) != varatut + n;
		if (exists) {
			huoneennro = 1 + (rand() % huonemaara);
			a = 1;
			//T�ss� jatketaan uuden numeron arpomista kunnes numero on sellainen mit� ei olla viel� varattu.
		}


		else
		a = 0;
		
	}
	a = 1;
	return huoneennro;
}


int main()
{
	setlocale(LC_ALL, "fi_FI");

	int toiminto, saatuarvo, varattu=1, asiakasnumero,i=0,a=0;
	int huonemaara = 30 + (rand() % 40);
	int hinta = 80 + (rand() % 20);
	int vapaana = huonemaara;
	bool virhe;
	char etunimet[70][20];
	char sukunimet[70][20];//Asiakkaan tiedot n�ihin
	char pnumero[70][15];
	int huoneennumero[70];
	int oidenmaara[70];

	
	cout << "#########################################################\n"
		<< "#          Tervetuloa varausj�rjestelm��n!              #\n"
		<<"#Valitse toiminto (1.Tee varaus, 2.Tarkastele varauksia)#\n"//Tervetuloilmoitus
		<< "#########################################################\n";
	cin >> toiminto;
	

		while (true)
		{
			if (toiminto == 1) //Varauksen tekemiseen tarvittava koodi t�h�n
			{
				
				i++;
				cout << "\n*********************************************************";
				cout << "\nVarauksen tekeminen valittu!\nHuoneita saatavilla: " << vapaana << "\nYhden y�n hinta: " << hinta <<" euroa" << "\n\n";
				cout << "Etunimi: ";		//Kysell��n asiakkaan tideot ja tallenetaan ne asiakasnumero j�rjestyksess�
				cin >> etunimet[i];
				cout << "Sukunimi: ";
				cin >> sukunimet[i];
				cout << "Puhelinnumero: ";
				cin >> pnumero[i];


				do
				{
					virhe = false;
					cout << "Varattavien �iden m��r�: ";
					cin >> oidenmaara[i];
					if (cin.fail())//Varmistetaan ett� annettu �iden m��r� on luku
					{
						cout << "Virhe. Anna �iden m��r� uudestaan!\n";
						virhe = true;
						cin.clear();
						cin.ignore(80, '\n');
					}
				} while (virhe);

				vapaana--;

				if (vapaana <= -1)  //Tarkistetaan onko huoneita en�� j�ljell� ennen aliohjelman kutsumista ettei looppi j�� jumiin
				{
					varattu = 0;
					cout << "Hotelli t�ynn�,huonetta ei voida varata!";
				}
				else
	
				
			
				if (varattu == 1)
				{
					saatuarvo = arvoHuone(huonemaara); //Haetaan aliohjelmassa arvottu huoneennumero ja tulostetaan varauksen yhteenveto
					cout << "\nVarauksen hinta on " << oidenmaara[i] * hinta << " euroa." << "\nHuoneenne on numero ";
					cout << saatuarvo;
					cout << "\nAsiakasnumeronne on " << i;
					huoneennumero[i] = saatuarvo;
					varatut[i] = saatuarvo;
					cout << "\n*********************************************************";
				}
				else
					cout << "Hotelli t�ynn�,huonetta ei voida varata!";

			}
			else
				if (toiminto == 2) //Varausten hakuun tarvittava koodi t�h�n
				{
					cout << "\n*********************************************************";
					cout << "\nVarausten tarkastelu valittu!\n\n";

					do
					{
						virhe = false;
						cout << "Anna asiakasnumero: ";
						cin >> asiakasnumero; //Haetaan asiakkaan tiedot asiakasnumeron perusteella
						if (cin.fail())
						{
							cout << "Virhe. Anna asiakasnumero uudestaan!\n";
							virhe = true;
							cin.clear();//Varmistetaan ett� annettu sy�te on numero
							cin.ignore(80, '\n');
						}
					} while (virhe);


					cout << "\nAsiakasnumero " << asiakasnumero << "\nNimi: " << etunimet[asiakasnumero] << " " << sukunimet[asiakasnumero]
						<< "\nPuhelinnumero: " << pnumero[asiakasnumero] << "\nVaratun huoneen numero: " << huoneennumero[asiakasnumero]
						<< "\nVarauksen kesto: " << oidenmaara[asiakasnumero] << " y�t�.";
					cout << "\n*********************************************************";//Tulostetaan asiakkaan tiedot

				}
			if (huonemaara <= i)//Jos asiakkaiden m��r�on suurempi kuin huoneiden m��r�, ilmoitetaan ett� hotelli on t�ysi
			{
				varattu = 0;
			}
			
			do
			{
				virhe = false;
				cout << "\n\nValitse seuraava toiminto (1.Tee toinen varaus, 2.Tarkastele varauksia, 3.Lopeta)";
				cin >> toiminto; //Kysyt��n k�ytt�j�lt� seuraava toiminto
				if (cin.fail())
				{
					cout << "Virhe. Valitse toiminto uudestaan!\n";
					virhe = true;//Varmistetaan ett� annettu toiminto on ohjeen mukainen
					cin.clear();
					cin.ignore(80, '\n');
				}
			} while (virhe);
				


			if (toiminto == 3)
				break;

		}


			
	return 0;

}
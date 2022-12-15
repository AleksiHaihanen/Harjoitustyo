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
			//Tässä jatketaan uuden numeron arpomista kunnes numero on sellainen mitä ei olla vielä varattu.
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
	char sukunimet[70][20];//Asiakkaan tiedot näihin
	char pnumero[70][15];
	int huoneennumero[70];
	int oidenmaara[70];

	
	cout << "#########################################################\n"
		<< "#          Tervetuloa varausjärjestelmään!              #\n"
		<<"#Valitse toiminto (1.Tee varaus, 2.Tarkastele varauksia)#\n"//Tervetuloilmoitus
		<< "#########################################################\n";
	cin >> toiminto;
	

		while (true)
		{
			if (toiminto == 1) //Varauksen tekemiseen tarvittava koodi tähän
			{
				
				i++;
				cout << "\n*********************************************************";
				cout << "\nVarauksen tekeminen valittu!\nHuoneita saatavilla: " << vapaana << "\nYhden yön hinta: " << hinta <<" euroa" << "\n\n";
				cout << "Etunimi: ";		//Kysellään asiakkaan tideot ja tallenetaan ne asiakasnumero järjestyksessä
				cin >> etunimet[i];
				cout << "Sukunimi: ";
				cin >> sukunimet[i];
				cout << "Puhelinnumero: ";
				cin >> pnumero[i];


				do
				{
					virhe = false;
					cout << "Varattavien öiden määrä: ";
					cin >> oidenmaara[i];
					if (cin.fail())//Varmistetaan että annettu öiden määrä on luku
					{
						cout << "Virhe. Anna öiden määrä uudestaan!\n";
						virhe = true;
						cin.clear();
						cin.ignore(80, '\n');
					}
				} while (virhe);

				vapaana--;

				if (vapaana <= -1)  //Tarkistetaan onko huoneita enää jäljellä ennen aliohjelman kutsumista ettei looppi jää jumiin
				{
					varattu = 0;
					cout << "Hotelli täynnä,huonetta ei voida varata!";
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
					cout << "Hotelli täynnä,huonetta ei voida varata!";

			}
			else
				if (toiminto == 2) //Varausten hakuun tarvittava koodi tähän
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
							cin.clear();//Varmistetaan että annettu syöte on numero
							cin.ignore(80, '\n');
						}
					} while (virhe);


					cout << "\nAsiakasnumero " << asiakasnumero << "\nNimi: " << etunimet[asiakasnumero] << " " << sukunimet[asiakasnumero]
						<< "\nPuhelinnumero: " << pnumero[asiakasnumero] << "\nVaratun huoneen numero: " << huoneennumero[asiakasnumero]
						<< "\nVarauksen kesto: " << oidenmaara[asiakasnumero] << " yötä.";
					cout << "\n*********************************************************";//Tulostetaan asiakkaan tiedot

				}
			if (huonemaara <= i)//Jos asiakkaiden määräon suurempi kuin huoneiden määrä, ilmoitetaan että hotelli on täysi
			{
				varattu = 0;
			}
			
			do
			{
				virhe = false;
				cout << "\n\nValitse seuraava toiminto (1.Tee toinen varaus, 2.Tarkastele varauksia, 3.Lopeta)";
				cin >> toiminto; //Kysytään käyttäjältä seuraava toiminto
				if (cin.fail())
				{
					cout << "Virhe. Valitse toiminto uudestaan!\n";
					virhe = true;//Varmistetaan että annettu toiminto on ohjeen mukainen
					cin.clear();
					cin.ignore(80, '\n');
				}
			} while (virhe);
				


			if (toiminto == 3)
				break;

		}


			
	return 0;

}
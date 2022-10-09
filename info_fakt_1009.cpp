
#include <fstream>
#include <iostream>
#include <map>
using namespace std;

struct Entry {
	string o;
	string v;
	int j;
	int u;
};

Entry t[200];
int n;

void beolvasas() {
	ifstream f("bud.txt");
	int i = 0;
	while (f.good()) {
		f >> t[i].o;
		f >> t[i].v;
		f >> t[i].j;
		f >> t[i].u;
		i++;
	}
	n = i - 1;//vége üres karakter
}

void f2() {
	cout << endl << "Masodik feladat" << endl;

	cout << n << " db varosba mennek jaratok!" << endl;
}
void f3() {
	cout << endl << "Harmadik feladat" << endl;

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += t[i].u;
	}
	cout << "Az osszes utasszam: " << sum << endl;
}

void f4() {
	cout << endl << "Negyedik feladat" << endl;

	cout << "Kerek egy orszagotkodot!" << endl;
	string azon;
	cin >> azon;
	int nummer = 0;
	int summer = 0;
	for (int i = 0; i < n; i++)
	{
		if (t[i].o == azon) {
			nummer++;
			summer += t[i].u;
		}
	}
	double atlag;
	if (nummer == 0) {
		atlag = 0;
	}
	else atlag = 1.0 * summer / nummer;
	cout << "Atlagosan ide " << atlag << " utas utazott." << endl;
}
void f5() {
	cout << endl << "Otodik feladat" << endl;

	int fin = 0;
	int nor = 0;
	int swe = 0;
	for (int i = 0; i < n; i++)
	{
		if (t[i].o == "NOR") nor += t[i].u;
		if (t[i].o == "SWE") swe += t[i].u;
		if (t[i].o == "FIN") fin += t[i].u;
	}
	if (nor > swe && nor > fin) cout << "NOR-ba utaztak a legtobben." << endl;
	if (swe > nor && swe > fin) cout << "SWE-ba utaztak a legtobben." << endl;
	else cout << "FIN-ba utaztak a legtobben." << endl;
	//Csak azért, hogy valamit kiírjon, akkor is, ha egyenlõ mind a három
}

//map<string, int> varosok;
//
//void hatodik() {
//    for (int i = 0; i < n; i++)
//    {
//        varosok.insert(pair<string, int>(t[i].o, 1));
//    }
//    cout<< varosok.size();
//}

struct varosseged {
	string kod;//Az ország kódja
	int varosszam;//Az ottani városok száma
	int utasszam;//Az oda utazó emberek száma
};

int orszagszam = 0;
varosseged orszagok[200];

void segedgen() {
	for (int i = 0; i < 200; i++)
	{
		orszagok[i].kod = "NULLÉRTÉK!!!!";
		orszagok[i].utasszam = 0;
		orszagok[i].varosszam = 0;
	}
	for (int i = 0; i < n; i++)
	{

		int index = -1;
		for (int j = 0; j < orszagszam; j++)
		{
			if (orszagok[j].kod == t[i].o) {
				index = j;
			}
		}
		if (index == -1) {
			orszagok[orszagszam].kod = t[i].o;
			orszagok[orszagszam].varosszam = 1;
			orszagok[orszagszam].utasszam = t[i].u;
			orszagszam++;
		}
		else
		{
			orszagok[index].varosszam++;
			orszagok[index].utasszam += t[i].u;
		}
	}
}
void f6() {//csak megszámolja az országok tömb hosszát
	cout << endl << "Hatodik feladat" << endl;

	cout << "A kulonbozo orszagok szama: " << orszagszam;
}

void f7() {

}
void f8() {
	cout << endl << "Nyolcadik feladat" << endl;

	ofstream f("nemet.txt");
	for (int i = 0; i < n; i++)
	{
		if (t[i].o == "DEU") {
			f << t[i].v << "\t" << 1.0 * t[i].u / t[i].j << endl;
		}
	}
	f.close();
}
void f9() {
	cout << endl << "Kilencedik feladat" << endl;

	ofstream f("varos.txt");
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (t[i].v > t[j].v) swap(t[i], t[j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		f << t[i].v << ", ";
	}
}
void f10() {
	cout << endl << "Tizedik feladat" << endl;
	bool volte = false;
	for (int i = 0; i < 200; i++)
	{
		if (orszagok[i].varosszam >= 3 && orszagok[i].utasszam < 1000) {
			volte = true;
			cout << orszagok[i].kod << "\t" << orszagok[i].varosszam << "\t" << orszagok[i].utasszam << endl;
		}

	}
	if (!volte) {
		cout << "Nem volt ilyen varos!" << endl;
	}
}
void f11() {
	cout << endl << "Tizenegyedik feladat" << endl;
	int kevesutas = 999999;
	string kevesvaros;
	for (int i = 0; i < n; i++)
	{
		if (t[i].j == 1 && kevesutas > t[i].u) {
			kevesvaros = t[i].v;
			kevesutas = t[i].u;
		}
	}
	cout << "A legkevesebben " << kevesvaros << "-ba repultek, " << kevesutas << " ember" << endl;
}
void f12() {
	cout << endl << "Tizenkettedik feladat" << endl;

	ofstream f("kisforgalmu.txt");
	for (int i = 0; i < n; i++)
	{
		if ((t[i].u / t[i].j) < 100) {
			f << t[i].v << ", ";
		}
	}
	f.close();
}
int main()
{
	beolvasas();
	f2();
	f3();
	f4();
	f5();
	segedgen();
	f6();
	f7();
	f8();
	f9();
	f10();
	f11();
	f12();//Kell neki a sorrend miatt a 9-es
}
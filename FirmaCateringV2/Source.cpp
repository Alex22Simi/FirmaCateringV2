#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class FirmaCatering
{
	const int idEveniment;
	char* denumireClient;
	int nrProduseOferite;
	string* denumireProdus;
	float pret;
public:
	FirmaCatering():idEveniment(0)
	{
		this->denumireClient = new char[strlen("Necunoscut") + 1];
		strcpy(this->denumireClient, "Necunoscut");
		this->nrProduseOferite = 0;
		this->denumireProdus = nullptr;
		this->pret = 0;
	}
	FirmaCatering( int idEveniment, const char* denumireClient, int nrProduseOferite, string* denumireProdus,
		float pret) :idEveniment(idEveniment)
	{
		this->denumireClient = new char[strlen(denumireClient) + 1];
		strcpy(this->denumireClient, denumireClient);
		this->nrProduseOferite = nrProduseOferite;
		this->denumireProdus = new string[this->nrProduseOferite];
		for (int i = 0; i < nrProduseOferite; i++)
		{
			this->denumireProdus[i] = denumireProdus[i];
		}
		this->pret = pret;
	}
	FirmaCatering(const FirmaCatering& f):idEveniment(f.idEveniment)
	{
		this->denumireClient = new char[strlen(f.denumireClient) + 1];
		strcpy(this->denumireClient, f.denumireClient);
		this->nrProduseOferite = f.nrProduseOferite;
		this->denumireProdus = new string[this->nrProduseOferite];
		for (int i = 0; i < f.nrProduseOferite; i++)
		{
			this->denumireProdus[i] = f.denumireProdus[i];
		}
		this->pret = f.pret;

	}
	float getPret()
	{
		return this->pret;
	}
	void setPret(float pret)
	{
		this->pret = pret;
	}
	FirmaCatering& operator=(const FirmaCatering& f) // a = b = c  -> 
	{
		if (this != &f)
		{
			if (this->denumireClient != NULL)
			{
				delete[] this->denumireClient;
			}
			if (this->denumireProdus != NULL)
			{
				delete[] this->denumireProdus;
			}
			this->denumireClient = new char[strlen(f.denumireClient) + 1];
			strcpy(this->denumireClient, f.denumireClient);
			this->nrProduseOferite = f.nrProduseOferite;
			this->denumireProdus = new string[f.nrProduseOferite];
			for (int i = 0; i < nrProduseOferite; i++)
			{
				this->denumireProdus[i] = f.denumireProdus[i];
			}
			this->pret = f.pret;
			return *this;
		}
	}
	friend ostream& operator<<(ostream& out, const FirmaCatering& f)
	{
		out << f.idEveniment << endl;
		out << f.denumireClient << endl;
		out << f.nrProduseOferite << endl;
		for (int i = 0; i < f.nrProduseOferite; i++)
		{
			out << f.denumireProdus[i] << ", ";
		}
		out << endl;
		out << f.pret << endl;
		return out;
	}
	friend istream& operator>>(istream& in,  FirmaCatering& f)
	{
		cout << "Denumire client" << endl;
		char aux[100];
		in.getline(aux, 100);
		if (f.denumireClient != NULL)
		{
			delete[] f.denumireClient;
		}
		f.denumireClient = new char[strlen(aux) + 1];
		strcpy(f.denumireClient, aux);

		cout << "Numar produse: " << endl;
		in >> f.nrProduseOferite;

		cout << "Produse: " << endl;
		if (f.denumireProdus != NULL)
		{
			delete[] f.denumireProdus;
		}
		f.denumireProdus = new string[f.nrProduseOferite];
		for (int i = 0; i < f.nrProduseOferite; i++)
		{
			in >> f.denumireProdus[i];
		}
		cout << "Introduceti pretul:" << endl;
		in >> f.pret;
		return in;
	}
	~FirmaCatering()
	{
		if (this->denumireClient != NULL)
		{
			delete[] this->denumireClient;
		}
		if (this->denumireProdus != NULL)
		{
			delete[] this->denumireProdus;
		}
	}

	//string operator[](int index)
	//{
	//	if (nrProduseOferite > 0 && index < nrProduseOferite)
	//	{
	//		return denumireProdus[index];
	//	}
	//	else return "";
	//}
	//FirmaCatering operator++() //++i ->pre (prima data ++)

	//{
	//	pret++;
	//	return *this;
	//}
	//FirmaCatering operator++(int x) // i++  -> post (se face dupa ++ )
	//{
	//	FirmaCatering copy = *this;
	//	this->pret++;
	//	return copy;
	//}
	string& operator[](int index)
	{
		if (nrProduseOferite > 0 && index < nrProduseOferite)
		{
			return denumireProdus[index]; 
		}
		
	}
	//pre -> ++
	FirmaCatering operator++()
	{
		pret++;
		return *this;
	}
	//post -> ++
	FirmaCatering operator++(int i)
	{
		FirmaCatering copy = *this;
		this->pret++;
		return copy;

	}
	friend ofstream& operator<<(ofstream& out, const FirmaCatering& f)
	{
		out << f.denumireClient << endl;
		out << f.nrProduseOferite << endl;
		for (int i = 0; i < f.nrProduseOferite; i++)
		{
			out << f.denumireProdus[i] << ", ";
		}
		out << endl;
		out << f.pret << endl;
		return out;
}
	friend ifstream& operator>>(ifstream& in, FirmaCatering& f)
	{
		in >> ws;
		char aux[100];
		in.getline(aux, 100);
		if (f.denumireClient != NULL)
		{
			delete[] f.denumireClient;
		}
		f.denumireClient = new char[strlen(aux) + 1];
		strcpy(f.denumireClient, aux);

		in >> ws;
		in >> f.nrProduseOferite;

		in >> ws;
		if (f.denumireProdus != NULL)
		{
			delete[] f.denumireProdus;
		}
		f.denumireProdus = new string[strlen(aux) + 1];
		for (int i = 0; i < f.nrProduseOferite; i++)
		{
			getline(in, f.denumireProdus[i]);
		}

		in >> f.pret;

		return in;

		
	}
};
class Firma:FirmaCatering
{
	string nume;
public:
	Firma() :FirmaCatering()
	{
		this->nume = "Necunoscut";
	}
	Firma(int idEveniment, const char* denumireClient, int nrProduseOferite, string* denumireProdus,
		float pret, string nume) :FirmaCatering(idEveniment, denumireClient, nrProduseOferite,
			denumireProdus,pret)
	{
		this->nume = nume;
	}
	Firma(const Firma& f) :FirmaCatering(f)
	{
		this->nume = f.nume;
	}
	Firma& operator=(const Firma& f)
	{
		if (this != &f)
		{
			Firma::operator=(f);
			this->nume = f.nume;
		}
		return *this;
	}
	~Firma()
	{

	}
	friend ostream& operator << (ostream& out,const  Firma& f)
	{
		out << (FirmaCatering&)f;
		out << f.nume << endl;
		return out;
	}


};

int main()
{
	FirmaCatering fff;
	cout << fff << endl;
	string numeProd[] = { "muzica", "artificii" };
	FirmaCatering f1(1,"Emil", 2, numeProd, 100);
	cout << f1 << endl;
	string numeProd1[] = { "muzica", "artificii", "mancare"};
	FirmaCatering f2(2, "Ionut", 3, numeProd1, 500);
	cout << f2 << endl;

	FirmaCatering f3(f2);
	cout << f3 << endl;
	f3 = fff;
	cout << f3 << endl;

	string numeProd2[] = { "muzica", "artificii", "mancare", "bautura"};
	FirmaCatering f4(2, "Alin", 4, numeProd2, 400);
	cout << f4 << endl;


	//sa se scoata maxim de pret prod oferite
	FirmaCatering vectMax[] = { f1, f2, f4 };
	FirmaCatering rezultatMax;
	float max = 0;
	int nrElem = 3;
	for (int i = 0; i < nrElem; i++)
	{
		if (vectMax[i].getPret() > max)
		{
			max = vectMax[i].getPret();
			rezultatMax = vectMax[i];
		}

	}
	cout << rezultatMax << endl;

	//sa se scoata pretul minim
	FirmaCatering vectMinim[] = { f1,f2,f4 };
	float minim = vectMinim[0].getPret();
	FirmaCatering rezultat = vectMinim[0];
	int nrElemMin = 3;
	for (int i = 0; i < nrElemMin; i++)
	{
		if (vectMinim[i].getPret() < minim)
		{
			minim = vectMinim[i].getPret();
			rezultat = vectMinim[i];
		}
	}
	cout << rezultat << endl;

	/*cin >> f3;
	cout << f3 << endl;*/

	Firma ff;
	cout << ff << endl;

	Firma ff1(10, "Vasile", 3, numeProd1, 777, "Evelin"); 
		cout << ff1 << endl;

		/*cout << f1[1] << endl;
		cout << endl << endl;
		cout << f1 << endl;
		cout << f2 << endl;
		f2 = ++f1;
		cout << f1 << endl;
		cout << f2 << endl;

		f2 = f1++;
		cout << f1 << endl;
		cout << f2 << endl;*/

		ofstream f("fiser.txt", ios::out);
		f << f1;
		f.close();
		cout << f1 << endl;
		cout << endl << endl;
		ifstream g("fiser.txt", ios::in);
		cout << f2 << endl;
		cout << "aici" << endl;
		g >> f2;
		cout << f2 << endl;
		cout << f1[0] << endl;
		f1[0] = "cantare";
		cout << f1[0] << endl;
		cout << endl << endl;
		/*cout << f1 << endl;
		cout << f2 << endl;
		f2 = ++f1;
		cout << f1 << endl;
		cout << f2 << endl;*/

		cout << endl << endl;
		cout << f1 << endl;
		cout << f2 << endl;
		f2 = f1++;
		cout << f1 << endl;
		cout << f2 << endl;
}
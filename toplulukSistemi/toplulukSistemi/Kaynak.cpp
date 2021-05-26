#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class topluluklar {
protected:
	struct uyeler {
		string* ad, * soyad, * yas, * bolumu;
	}uyeBilgisi[100];
	int uyeSayisi;
	char kullaniciAdi[20];

	enum doluluk {
		dolu, bos
	}uye[100];
public:

	topluluklar()
	{
		for (int i = 0; i < 100; i++)
		{
			uye[i] = bos;
		}
		uyeSayisi = 0;
		ilkEkran();

	}
	virtual 	void uyeEkle();
	void uyeSil();
	void uyeGor();
	void ilkEkran();
	void ikinciEkran();




}duzceUni;
class izciKlubu :public topluluklar {
public:
	izciKlubu() {};
	void Kisisel_Verileri_Dosyaya_Aktar_Izci();
	~izciKlubu()
	{
		Kisisel_Verileri_Dosyaya_Aktar_Izci();
	}
}izciler;
class kisiselGelisimToplulugu :public topluluklar {
public:
	kisiselGelisimToplulugu() {
	};
	void Kisisel_verileri_Dosyaya_Aktar();
	~kisiselGelisimToplulugu()
	{
		Kisisel_verileri_Dosyaya_Aktar();
	}
}gelisimci;
class BiyomedikalToplulugu :public topluluklar {
public:
	BiyomedikalToplulugu() {};
	void Kisisel_Verileri_Dosyaya_Aktar_Biyomedikal();
	~BiyomedikalToplulugu()
	{
		Kisisel_Verileri_Dosyaya_Aktar_Biyomedikal();
	}
}biyomedikal;


void topluluklar::ilkEkran()
{
	int secim;
	cout << "\t\tDUZCE UNIVERSITESI TOPLULUK YONETIM SISTEMI\n" << endl;
	cout << "Lutfen Secim islemini tamamlayiniz:\n" << endl;
	cout << "\t\t1-)Kisisel Gelisim Toplulugu" << endl;
	cout << "\t\t2-)Biyomedikal Toplulugu" << endl;
	cout << "\t\t3-)Izci Klubu Toplulugu" << endl;
	cout << "\t\t4-)Cikis" << endl;
	cin >> secim;
	switch (secim)
	{

	case 1:
	{
		cout << "\t\tKISISEL GELISIM TOPLULUGU YONETIM EKRANI" << endl;
	
		gelisimci.ikinciEkran();
		break;
	}
	case 2:
	{

		cout << "\t\tBIYOMEDIKAL TOPLULUGU YONETIM EKRANI" << endl;

		
		biyomedikal.ikinciEkran();

		break;
	}
	case 3:
	{
		cout << "\t\tIZCI KLUBU TOPLULUGU YONETIM EKRANI" << endl;
	
		izciler.ikinciEkran();
	case 4:
	{
		cout << "Cikis yapiliyor!!" << endl;
		exit(1);
		break;
	}

	}
	default:cout << "Eksik veya hatali tuslama yaptiniz!!!!" << endl;
		duzceUni.ilkEkran();

	}

}
void topluluklar::uyeEkle() {
	string adi, soyadi, yasi, bolumu;

	for (int i = 0; i < 100; i++)
	{
		if (uye[i] != dolu)
		{
			uye[i] = dolu;
			uyeSayisi++;
			cout << "Uyenin adini giriniz:";
			cin >> adi;
			cout << "Uyenin Soyadini giriniz:";
			cin >> soyadi;
			cout << "Uyenin yasini giriniz:";
			cin >> yasi;
			cout << "Uyenin bolumunu giriniz:";
			cin >> bolumu;
			uyeBilgisi[i].ad = new string;
			*uyeBilgisi[i].ad = adi;
			uyeBilgisi[i].soyad = new string;
			*uyeBilgisi[i].soyad = soyadi;
			uyeBilgisi[i].yas = new string;
			*uyeBilgisi[i].yas = yasi;
			uyeBilgisi[i].bolumu = new string;
			*uyeBilgisi[i].bolumu = bolumu;

			break;

		}
		if (i == 100)
		{
			cout << "Malesef Toplulukta bo� yer bulunmamaktadir!!" << endl;

			break;

		}


	}

	ilkEkran();


}
void topluluklar::uyeSil() {
	int sira;
	cout << "Silmek istediginiz uyenin sira numarasini giriniz:";
	cin >> sira;
	if (uye[sira] == dolu)
	{
		uyeSayisi--;
		uye[sira] = bos;
		delete uyeBilgisi[sira].ad;
		delete uyeBilgisi[sira].soyad;
		delete uyeBilgisi[sira].bolumu;
		delete uyeBilgisi[sira].yas;
		cout << "Silme isleminiz basarili bir sekilde gerceklestirildi!!" << endl;

	}
	else
	{
		cout << "Eksik veya Hatali tuslama yapptiniz!!" << endl;
	}
	ilkEkran();
}
void topluluklar::uyeGor()
{
	cout << "  toplam uye sayisi[" << uyeSayisi << "]" << endl;
	cout << "Uyenin Adi:" << " Uyenin Soyadi" << " Uyenin Yasi" << " Uyenin Bolumu:" << endl;
	for (int t = 0; t < 100; t++)
	{
		if (uye[t] != bos)
		{
			cout << "Uye sira numarasi:[" << t << "]" << endl;
			cout << *uyeBilgisi[t].ad;
			cout << " " << *uyeBilgisi[t].soyad;
			cout << " " << *uyeBilgisi[t].yas;
			cout << " " << *uyeBilgisi[t].bolumu << endl;
		}
	}
	ilkEkran();
}
void topluluklar::ikinciEkran() {
	int sec;
	cout << "\t\tDUZCE UNIVERSITESI TOPLULUK YONETIM SISTEMI\n\n" << endl;
	cout << "Islem yapacaginiz toplulugu seciniz:" << endl;
	cout << "1-)Uye ekle" << endl;
	cout << "2-)Uye kaydi sil" << endl;
	cout << "3-)Uye goruntule" << endl;
	cout << "4-)Onceki menu" << endl;
	cin >> sec;
	switch (sec)
	{
	case 1:
		uyeEkle();

		break;
	case 2:
		uyeSil();
		break;
	case 3:
		uyeGor();
		break;
	case 4:
		ilkEkran();
		break;
	default:cout << "Hatali Tuslama Yaptiniz!!" << endl;
		ikinciEkran();

	}
}
void kisiselGelisimToplulugu::Kisisel_verileri_Dosyaya_Aktar()
{
	ofstream kisiselGelisimDosya;
	kisiselGelisimDosya.open("C:\\Users\\emre\\Desktop\\deneyler\\dev c++deney\\TOPLULUKLAR\\kisiselGelisimtoplulugu.xls", ios::app);
	if (!kisiselGelisimDosya)
	{
		cerr << "K�s�sel gel�s�m toplulugu dosyasi acilamadi!!" << endl << endl;
	}

	string a, s, y, b;
	for (int i = 0; i < 100; i++)
	{
		if (uye[i] != bos)
		{
			a = *(uyeBilgisi[i].ad);
			s = *(uyeBilgisi[i].soyad);
			y = *(uyeBilgisi[i].yas);
			b = *(uyeBilgisi[i].bolumu);

			kisiselGelisimDosya << a << " ";
			kisiselGelisimDosya << s << " ";
			kisiselGelisimDosya << y << " ";
			kisiselGelisimDosya << b << endl;

		}

	}
	kisiselGelisimDosya.close();
}
void BiyomedikalToplulugu::Kisisel_Verileri_Dosyaya_Aktar_Biyomedikal()
{
	ofstream biyomedikalDosya;
	biyomedikalDosya.open("C:\\Users\\emre\\Desktop\\deneyler\\dev c++deney\\TOPLULUKLAR\\biyomedikalTop.xls", ios::app);
	if (!biyomedikalDosya)
	{
		cerr << "Biyomedikal Toplulugu dosyasi acilamadi!!" << endl;
	}
	string a, s, y, b;
	for (int i = 0; i < 100; i++)
	{
		if (uye[i] != bos)
		{
			a = *(uyeBilgisi[i].ad);
			s = *(uyeBilgisi[i].soyad);
			y = *(uyeBilgisi[i].yas);
			b = *(uyeBilgisi[i].bolumu);
			biyomedikalDosya << a << " ";
			biyomedikalDosya << s << " ";
			biyomedikalDosya << y << " ";
			biyomedikalDosya << b << endl;

		}
	}
	biyomedikalDosya.close();
}
void izciKlubu::Kisisel_Verileri_Dosyaya_Aktar_Izci()
{

	ofstream izciKlubuDosya;
	izciKlubuDosya.open("C:\\Users\\emre\\Desktop\\deneyler\\dev c++deney\\TOPLULUKLAR\\izciKlubuToplulugu.xls", ios::app);
	if (!izciKlubuDosya)
	{
		cerr << "Izci Klubu  Toplulugu dosyasi acilamadi!!" << endl;
	}
	string a, s, y, b;
	for (int i = 0; i < 100; i++)
	{
		if (uye[i] != bos)
		{
			a = *(uyeBilgisi[i].ad);
			s = *(uyeBilgisi[i].soyad);
			y = *(uyeBilgisi[i].yas);
			b = *(uyeBilgisi[i].bolumu);
			izciKlubuDosya << a << " " << s << " " << y << " " << b << endl;

		}
	}
	izciKlubuDosya.close();
}


int main()
{



	return 0;
}
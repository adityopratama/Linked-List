#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
using namespace std;

typedef int typeinfo;
typedef struct typenode *typeptr;
struct typenode
		{ typeinfo info;
			typeptr next;
		};

typeptr awal, akhir;
void buatlistbaru();
void sisipdepan(typeinfo IB);
void sisipbelakang(typeinfo IB);
void sisiptengah (typeinfo IB);
void hapuslist (typeinfo IH);
void cetaklist();
void NodeDepan ();
void NodeBelakang ();
void NodeTengah ();
void HapusNode ();
typeinfo angka;
	char ulangi = 'y';

int main ()
{
	
	buatlistbaru();
	int pilih;
	do{
	cout<<"\t\t Menu \n";
	cout<<"1.Sisip Depan\n2.Sisip Belakang\n";
	cout<<"3.Sisip Tengah\n4.Hapus Node\n5.Keluar\n";
	cout<<"Pilih : ";
	cin >>pilih;
	switch(pilih){
		case 1:
		cout<<"\t\tSisip Depan\n";
		NodeDepan ();
		cout<<"\n";
		ulangi = 'y';
		break;
		case 2:
		cout<<"\t\tSisip Belakang\n";
		NodeBelakang ();
		cout<<"\n";
		ulangi = 'y';
		break;
		case 3:
		cout<<"\t\tSisip Tengah\n";
		NodeTengah ();
		cout<<"\n";
		ulangi = 'y';
		break;
		case 4:
		cout<<"\t\tHapus Node\n";
		HapusNode ();
		cout<<"\n";
		ulangi = 'y';
		break;
		case 5:
		cout<<"\t\tTerima kasih\n";
		exit(0);
	}
	}while (pilih!=5);	
}

void NodeDepan ()
{
	while(ulangi == 'y')
		{
			printf("Menyisipkan depan : ");
			cin >> angka;
			sisipdepan(angka);
			printf("\n");
			cetaklist();
			printf("\n");
			printf("\n");
			printf("Apakah kamu mau mengulang?\n");
			printf("Jawab (y/t): ");
			cin >> ulangi;
			printf("\n");
			
		}
}

void NodeBelakang ()
{
	while(ulangi == 'y')
		{
			printf("Menyisipkan Belakang : ");
			cin >> angka;
			sisipbelakang(angka);
			printf("\n");
			cetaklist();
			printf("\n");
			printf("\n");
			printf("Apakah kamu mau mengulang?\n");
			printf("Jawab (y/t): ");
			cin >> ulangi;
			printf("\n");
		}
}

void NodeTengah ()
{
	while(ulangi == 'y')
		{
			printf("Menyisipkan Tengah : ");
			cin >> angka;
			sisiptengah(angka);
			printf("\n");
			cetaklist();
			printf("\n");
			printf("\n");
			printf("Apakah kamu mau mengulang?\n");
			printf("Jawab (y/t): ");
			cin >> ulangi;
			printf("\n");
			
		}
}
void HapusNode ()
{
	while(ulangi == 'y')
		{
			printf("Hapus List : ");
			cin >> angka;
			hapuslist(angka);
			printf("\n");
			cetaklist();
			printf("\n");
			printf("\n");
			printf("Apakah kamu mau mengulang?\n");
			printf("Jawab (y/t): ");
			cin >> ulangi;
			printf("\n");
			
		}
	
}


void buatlistbaru()
{
	typeptr list;
	list=(typenode *) malloc (sizeof(typenode));
	list=NULL;
	awal=list;
	akhir=list;
}

void sisipdepan(typeinfo IB)
{
	typeptr NB;
	NB=(typenode *) malloc(sizeof(typenode));
	NB->info=IB;
	if (awal==NULL)
	{	awal=NB;
		akhir=NB;
		awal->next = NULL;
	}
	else
		{
			NB->next=awal;
		}
	awal=NB;
}

void sisipbelakang(typeinfo IB)
{
	typeptr NB;
	NB=(typenode *) malloc(sizeof(typenode));
	NB->info=IB;
	if (awal==NULL)
	{	awal=NB;
		akhir=NB; } 
	else
	{	akhir->next=NB; }
		akhir=NB;
		akhir->next=NULL;
}

void sisiptengah (typeinfo IB)
{
	typeptr NB, bantu;
	NB=(typenode *) malloc(sizeof(typenode));
	NB->info=IB;
	if (awal==NULL)
	{	awal=NB;
		akhir=NB;
	}
	else
		{
			bantu=awal;
			while ((IB > bantu->next->info) && (bantu->next!=NULL))
			{	bantu=bantu->next;}
			NB->next=bantu->next;
			bantu->next=NB;
		}
}

void hapuslist (typeinfo IH)
{
	typeptr hapus, bantu;
	if (awal==NULL)
		{ printf("List masih kosong");}
	else
		{ if (awal->info==IH) /* hapus awal list */
			{ hapus=awal;
			  awal=hapus->next;
			  free(hapus);}
		  else
			{ bantu = awal;  /*cari list yang akan dihapus*/
				while ((bantu->next->info!=IH) && (bantu->next!=NULL))
				{ bantu=bantu->next; }
			 hapus=bantu->next;
			 if (hapus==NULL)
			 { printf("List tidak ditemukan\n");
			 }
			 else
			 { if (hapus==akhir)	/* hapus akhir list */
				  { akhir=bantu;
					akhir->next=NULL;}
			   else
			   { bantu->next=hapus->next; }
			   free (hapus);}
			}
		}
}

void cetaklist()
{	typeptr bantu;
	bantu=awal;
	while (bantu!=NULL)
	{
		printf(" %d ",bantu->info);
		bantu=bantu->next;
	}
}

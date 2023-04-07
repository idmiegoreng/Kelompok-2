#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctime>
#define MAX 10

using namespace std;

//tampilan queue
struct queue {
	int data[20];
	int awal, akhir;
	string tambahan[3] = {"PC", "PO", "CO"};
	int harga[3] = {100000,30000,75000};
} antrian;

//fungsi untuk mengkosongkan antrian
void init(){
	antrian.awal=-1;
	antrian.akhir=-1;
}

//fungsi untuk melihat antrian
bool full(){
	if(antrian.akhir == MAX-1) {
		return true;}
	else {
		return false;}
}
bool empty() {
	if (antrian.akhir == -1){
		return true;}
	else {
		return false;}
}
//fungsi menambahkan antrian
void inQueue(){
	int elemen, *elemenx;
	elemenx = &elemen;
	cout<<"Data yang akan dimasukkan : ";
	cin>>elemen;
	if(empty()) {
		antrian.awal = 0;
		antrian.akhir = 0;
		antrian.data[antrian.awal]= *elemenx;}
	else {
		if(!full()) {
			antrian.akhir++;
			cout<<"Data berhasil ditambahkan\n";
			antrian.data[antrian.akhir]= *elemenx;}
		else {
			cout<<"Antrian penuh \n";}
	}
	getchar();
}

//fungsi untuk menghapus antrian
void deQueue(){
	int i;
	string jenisM;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	if(!empty()) {
		if (antrian.data[antrian.awal]==1){
			cout<<"===== Nota eShine Motor Care =====";
			cout<<"\nPaket 1. Reguler Wash";
			cout<<"\nTanggal	: "<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<" ";
			cout<<"\nJenis Motor	: "; cin>>jenisM;
			cout<<"Total Pembayaran	: Rp18.000";
			for(i=antrian.awal; i<antrian.akhir; i++){
			antrian.data[i]<antrian.data[i+1];}
		
		} else if (antrian.data[antrian.awal]==2){
			cout<<"\n===== Nota eShine Motor Care =====";
			cout<<"\nPaket 2. Wash And Wax";
			cout<<"\nTanggal	: "<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<" ";
			cout<<"\nJenis Motor	: "; cin>>jenisM;
			cout<<"Total Pembayaran	: Rp40.000";
			for(i=antrian.awal; i<antrian.akhir; i++){
			antrian.data[i]<antrian.data[i+1];}
			
		} else if (antrian.data[antrian.awal]==3){
			cout<<"\n===== Nota eShine Motor Care =====";
			cout<<"\nPaket 3. Premium Wax";
			cout<<"\nTanggal	: "<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<" ";
			cout<<"\nJenis Motor	: "; cin>>jenisM;
			cout<<"Total Pembayaran	: Rp55.000";
			for(i=antrian.awal; i<antrian.akhir; i++){
			antrian.data[i]<antrian.data[i+1];}
		}
		
		antrian.akhir--;}
	else {
		cout<<"Antrian kosong";}
	getchar();
	}
	
//fungsi untuk menampilkan antrian
void tampilData(){
	int i;
		for(int i=antrian.awal; i <= antrian.akhir; i++) {
			cout<<antrian.data[i]<< " = [" << i << "] | ";}
	cout<<"\n";
}

//fungsi menghapus semua antrian
void clear(){
	antrian.awal = -1;
	antrian.akhir = -1;
}

//fungsi info paket
void infoPaket() {
	
	char nama [4][30];
	strcpy(nama[0],"> Photo + Cinematic	[PC]");
	strcpy(nama[1],"> Photo Only		[PO]");
	strcpy(nama[2],"> Cinematic Only	[CO]");
	
	for(int a=0;a<4;a++){ 
		
			int j,bd;
			j=a;
			for(int k=a+1;k<3;k++)
			{
					bd=strcmp(nama[j], nama[k]);
					if(bd==1) j=k; 		/* angka 1 merupakan urut data secara ascending, untuk descending ganti dengan -1 */
					}
								if(j!=a){
							 char temp[1][30]; /* Swapping */
							 strcpy(temp[0],nama[j]);
							 strcpy(nama[j],nama[a]);
							 strcpy(nama[a],temp[0]);}	
					}
	for (int i=0;i<3;i++){ /* Menampilkan hasil */
		puts(nama[i]);
		}
		
		string dtCari, tambahan_ketemu;
		bool ketemu = false;
		
		cout<<"Produk yang dicari : ";
		cin>>dtCari;
		
		for(int i=0;i<3;i++){
			if(antrian.tambahan[i] == dtCari){
		ketemu = true;
		tambahan_ketemu = antrian.tambahan[i];
		}
		}
		
		if(ketemu = true){
			cout<<"Jasa Tambahan ditemukan!\n\n";
		cout<<"Hasil Pencarian Jasa Tambahan "<<tambahan_ketemu<<" :";
		if (tambahan_ketemu=="CO")
			cout<<antrian.harga[2];
		if (tambahan_ketemu=="PO")
			cout<<antrian.harga[1];
		if (tambahan_ketemu=="PC")
			cout<<antrian.harga[0];
		}
		else {
			cout<<"Menu tidak ditemukan!"<<endl;
		}
}

//inti program
int main(){
	int pilihan, elemen;
	
	cout<<"========== eSHINE MOTOR CARE =========="<<endl;
	cout<<"Paket 1. Reguler Wash	= Rp18.000";
	cout<<"\nPaket 2. Wash And Max	= Rp40.000";
	cout<<"\nPaket 3. Premium Max	= Rp55.000"; init();
	
	do {
		cout<<"\n\nMenu Utama\n";
		cout<<"=======================\n";
		cout<<"[1] Masukan Antrian\n[2] Pembayaran \n[3] Melihat Antrian \n[4] Jasa Tambahan \n[5] Menghapus Antrian \n[0] Keluar\n";
		cout<<"=======================\n";
		cout<<"\nMasukkan pilihan : "; cin>>pilihan;
		cout<<"=======================\n";
		switch(pilihan) {
			case 1: inQueue(); break;
			case 2: deQueue(); break;
			case 3: tampilData(); break;
			case 4: infoPaket(); break;
			case 5: clear(); break;
		}
	}
	while(pilihan!=0);
	
	return 0;
}

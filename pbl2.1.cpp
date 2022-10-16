#include <bits/stdc++.h>
#include "supply.cpp"
using namespace std;

Supply* Head=NULL;
int cnt;

void option1(){
	int n,c;
	cout<<"Nhap so luong vat tu muon nhap: "; cin>>n;
	Supply S;
	while((c=getchar())!='\n' && c!=EOF);
	for(int i=0;i<n;i++){
		cout<<"Vat tu thu "<<i+1<<":\n";
		cin>>S;
		insert(Head, S);
		cnt++;
	}
}

void option2(){
	Supply* Temp = Head;
	int i=0;
	while(Temp!=NULL){
		cout<<"Vat tu thu "<<i+1<<":\n";
		cout<<*Temp;
		Temp = Temp->next;
		i++;
	}
}

void option3(){
	string code;
	cout<<"Nhap ma vat tu can bo sung: "; getline(cin, code);
	Supply* Temp = Head;
	codeSearch(Temp, code);
	if(Temp!=NULL){
		int qty;
		cout<<"Nhap so luong can bo sung: "; cin>>qty;
		*Temp = *Temp + qty;
	} else cout<<"Khong tim thay vat tu can bo sung!\n";
}
int main(){
	int control1=-1;
	char control2='y';
	ifstream dbin;
	dbin.open("database.txt", ifstream::in);
	dbin>>cnt;
	Supply S;
	for(int i=0;i<cnt;i++){
		dbInput(dbin, S);
		insert(Head, S);
	}
	dbin.close();
	while(true){
		system("cls");
		cout <<"---------------Menu---------------"<<endl;
		cout <<"1. Nhap vat tu."<<endl;
		cout <<"2. Xuat danh sach vat tu."<<endl;
		cout <<"3. Bo sung vat tu."<<endl;
		cout <<"4. Giam bot vat tu."<<endl;
		cout <<"5. Sap xep danh sach vat tu."<<endl;
		cout <<"6. Xoa vat tu."<<endl;
		cout <<"7. Ket thuc."<<endl;
		reinput:
		cout <<"Lua chon cua ban la: ";
		scanf("%d", &control1);
		int c;
		while((c=getchar())!='\n' && c!=EOF);
		cout <<"----------------------------------"<<endl;
		switch(control1){
			case 1:
				option1();
				break;
			case 2:
				option2();
				break;
			case 3:
				option3();
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				goto ketthuc;
				break;	
			default:
				cout<<"Input khong hop le!\nMoi ban nhap lai.\n";
				cout<<control1<<endl;
				goto reinput;
		}
		control1=-1;
		cout<<"Thuc hien thanh cong!\nNhan phim bat ki de tiep tuc.\n";
	}
	ketthuc:{
		ofstream dbout;
		dbout.open("database.txt", ofstream::out);
		dbout<<cnt<<endl;
		while(Head!=NULL){
			dbOutput(dbout, *Head);
			Head=Head->next;
		}
		dbout.close();
		cout<<"Chuong trinh da ket thuc!\n";
	}
	return 0;
}

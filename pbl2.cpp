#include <bits/stdc++.h>
#include "bill.cpp"
using namespace std;

supList sL;

void option1(){
	bill b;
	int tmpCnt;
	b.create();
    cout<<"Nhap so luong vat tu: "; cin>>tmpCnt; cin.ignore();
    cout<<"Nhap danh sach vat tu:\n";
	for(int i=0;i<tmpCnt;i++){
        Supply S;
	    cout<<"Nhap thong tin vat tu thu "<<i+1<<":\n"; cin>>S;
	    if(S.isValid() && sL.Search(S)==-1){ 
			sL.insertTail(S);
			b.insertTail(S);
		}
    }
	b.print();
}

void option2(){
	
}

void option3(){
	int ch1=0, ch2=0;
	cout<<"Chon thuoc tinh sap xep\n";
	cout<<"(1: ma vat tu\n2: ten vat tu\n3: loai vat tu\n";
	cout<<"4: don vi tinh\n5: ngay nhap hang\n6: nha san xuat\n";
	cout<<"7: so luong\n8: don gia\n9: thanh tien): "; cin>>ch1;
	cout<<"Chon thu tu sap xep\n";
	cout<<"(1: tang dan\n2: giam dan): "; cin>>ch2;
	sL.Sort(ch2, ch1);
}

void option4(){
	sL.show();
}

void option5(){
}

int main(){
	int control1=-1;
	char control2='y';
	ifstream dbin;
	dbin.open("database.txt", ifstream::in);
	dbin>>sL;
	dbin.close();
	while(true){
		system("cls");
		cout<<"---------------Menu---------------"<<endl;
		cout<<"1. Tao phieu nhap vat tu (nhap vat tu)."<<endl;
		cout<<"2. Tao phieu xuat vat tu (xuat vat tu)."<<endl;
		cout<<"3. Sap xep danh sach vat tu."<<endl;
		cout<<"4. Hien thi danh sach vat tu."<<endl;
		cout<<"5. Hien thi lich su xuat nhap kho"<<endl;
		cout<<"6. "<<endl;
		cout<<"7. Ket thuc."<<endl;
		reinput:
		cout<<"\nLua chon cua ban la: ";
		cin>>control1;
		cin.ignore();
		// int c;
		// while((c=getchar())!='\n' && c!=EOF);
		cout<<"----------------------------------"<<endl;
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
				option4();
				break;
			case 5:
				option5();
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
		cout<<"\nThuc hien thanh cong!\nNhan phim bat ki de tiep tuc.\n";
	}
	ketthuc:{
		ofstream dbout;
		dbout.open("database.txt", ofstream::out);
		dbout<<sL;
		dbout.close();
		cout<<"Chuong trinh da ket thuc!\n";
	}
	return 0;
}

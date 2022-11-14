#include <bits/stdc++.h>
#include "billList.cpp"
using namespace std;

goodsList khoNhap;
billList phieuNhap;
billList phieuXuat;

bool option1(){
	bill b(1);
	int tmpCnt;
	if(!b.create()) return false;
    cout<<"Nhap so luong hang hoa: "; cin>>tmpCnt; cin.ignore();
    cout<<"Nhap danh sach hang hoa:\n";
	for(int i=0;i<tmpCnt;i++){
        goods S;
	    cout<<"Nhap thong tin hang hoa thu "<<i+1<<":\n"; cin>>S;
	    if(!S.isValid()){
			cout<<"Hang hoa nhap vao khong hop le (so luong hoac don gia be hon hoac bang 0)!\n";
			return false;
		}
		else if(khoNhap.Search(S)!=-1){
			cout<<"Hang hoa nhap vao khong hop le (ma hang hoa trung voi hang hoa co san trong kho)!\n";
			return false;
		}
		else{ 
			S.setDT(b.ngayNhapXuat_());
			khoNhap.insertTail(S);
			b.add(S);
		}
    }
	b.print();
    phieuNhap.insertTail(b);
	return true;
}

bool option2(){
	bill b(0);
	int tmpCnt;
	if(!b.create()) return false;
    cout<<"Nhap so luong hang hoa: "; cin>>tmpCnt; cin.ignore();
    cout<<"Nhap danh sach hang hoa:\n";
	for(int i=0;i<tmpCnt;i++){
        goods S;
	    cout<<"Nhap thong tin hang hoa thu "<<i+1<<":\n"; cin>>S;
	    if(!S.isValid()){
			cout<<"Hang hoa nhap vao khong hop le (so luong hoac don gia be hon hoac bang 0)!\n";
			return false;
		}
		else if(khoNhap.Search(S)==-1){
			cout<<"Hang hoa nhap vao khong hop le (khong tim thay hang hoa tuong ung trong kho)!\n";
			return false;
		}
		else if(!khoNhap.reduce(S)){
			return false;
		}
		else{
			b.add(S);
		}
    }
	b.print();
    phieuXuat.insertTail(b);
	return true;
}

bool option3(){
	int ch1=0, ch2=0;
	cout<<"Chon thuoc tinh sap xep\n";
	cout<<"(1: ma hang hoa\n2: ten hang hoa\n3: loai hang hoa\n";
	cout<<"4: don vi tinh\n5: ngay nhap hang\n6: nha san xuat\n";
	cout<<"7: so luong\n8: don gia\n9: thanh tien): "; cin>>ch1;
	cout<<"Chon thu tu sap xep\n";
	cout<<"(1: tang dan\n2: giam dan): "; cin>>ch2;
	khoNhap.Sort(ch2, ch1);
    return true;
}

bool option4(){
	khoNhap.show();
	return true;
}

bool option5(){
	date start;
	date end;
	cout<<"Nhap ngay bat dau:\n"; cin>>start;
	cin.ignore();
	cout<<"Nhap ngay ket thuc:\n"; cin>>end;
	cin.ignore();
	if(start>end){
		cout<<"Ngay bat dau khong the lon hon ngay ket thuc!\n";
		return false;
	}
	cout<<"Lich su nhap:\n"; phieuNhap.history(start, end);
	cout<<"Lich su xuat:\n"; phieuXuat.history(start, end);
	return true;
}

int main(){
	int control1=-1;
	bool isS;
	ifstream dbin;
	dbin.open("database.txt", ifstream::in);
	dbin>>khoNhap;
	dbin.close();
    ifstream dsPNin;
    dsPNin.open("dsPhieuNhap.txt", ifstream::in);
	dsPNin>>phieuNhap;
    dsPNin.close();
	ifstream dsPXin;
    dsPXin.open("dsPhieuXuat.txt", ifstream::in);
	dsPXin>>phieuNhap;
    dsPXin.close();
	while(true){
		system("clear");
		cout<<"---------------Menu---------------"<<endl;
		cout<<"1. Tao phieu nhap hang hoa (nhap hang hoa)."<<endl;
		cout<<"2. Tao phieu xuat hang hoa (xuat hang hoa)."<<endl;
		cout<<"3. Sap xep danh sach hang hoa."<<endl;
		cout<<"4. Hien thi danh sach hang hoa."<<endl;
		cout<<"5. Hien thi lich su xuat nhap kho."<<endl;
		cout<<"6. Hien thi danh sach phieu nhap kho."<<endl;
		cout<<"7. Hien thi danh sach phieu xuat kho."<<endl;
		cout<<"8. Ket thuc."<<endl;
		reinput:
		cout<<"\nLua chon cua ban la: ";
		cin>>control1;
		cin.ignore();
		cout<<"----------------------------------"<<endl;
		switch(control1){
			case 1:
				isS = option1();
				break;
			case 2:
				isS = option2();
				break;
			case 3:
				isS = option3();
				break;
			case 4:
				isS = option4();
				break;
			case 5:
				isS = option5();
				break;
			case 6:
				break;
			case 8:
				goto ketthuc;
				break;	
			default:
				cout<<"Input khong hop le!\nMoi ban nhap lai.\n";
				cout<<control1<<endl;
				goto reinput;
		}
		control1=-1;
		cout<<"\nThuc hien "<<((isS)?"":"khong ")<<"thanh cong!\nNhan phim bat ki de tiep tuc.\n";
		getchar();
	}
	ketthuc:{
		ofstream dbout;
		dbout.open("database.txt", ofstream::out);
		dbout<<khoNhap;
		dbout.close();
		ofstream dsPNout;
		dsPNout.open("dsPhieuNhap.txt", ofstream::out);
		dsPNout<<phieuNhap;
		dsPNout.close();
		ofstream dsPXout;
		dsPXout.open("dsPhieuXuat.txt", ofstream::out);
		dsPXout<<phieuXuat;
		dsPXout.close();
		cout<<"Chuong trinh da ket thuc!\n";
	}
	return 0;
}

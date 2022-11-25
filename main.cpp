#include <bits/stdc++.h>
#include <sstream>
#include "billList.cpp"
using namespace std;

goodsList khoNhap;
billList phieuNhap;
billList phieuXuat;

bool option1(){
	bill b(1);
	int tmpCnt;
	try{
		phieuNhap.create(b);
	}
	catch(const int &ern){
		if(ern==1){
        	cout<<"Khong the tao phieu (ngay thang nam khong hop le)!\n";
			return false;
		} else if(ern==2){
			cout<<"Khong the tao phieu (phieu da duoc tao truoc)!";
			return false;
		}
	}
    cout<<"Nhap so luong mat hang: "; cin>>tmpCnt; cin.ignore();
    cout<<"Nhap danh sach hang hoa:\n";
	for(int i=0;i<tmpCnt;i++){
        goods S;
	    cout<<"Nhap thong tin hang hoa thu "<<i+1<<":\n";
		try{
			khoNhap.nhap(S);
			S.setDT(b.ngayNhapXuat_());
			khoNhap.insertTail(S);
			b.add(S);
		}
		catch(int &ern){
			if(ern==1){
				cout<<"Hang hoa nhap vao khong hop le (so luong hoac don gia be hon hoac bang 0)!\n";
				return false;
			} else if(ern==2){
				cout<<"Hang hoa nhap vao khong hop le (ma hang hoa trung voi hang hoa co san trong kho)!\n";
				return false;
			}
		}
    }
	b.print();
    phieuNhap.insertTail(b);
	return true;
}

bool option2(){
	if(khoNhap.isEmpty()){
		cout<<"Kho trong!\n";
		return false;
	}
	bill b(0);
	int tmpCnt;
	try{
		phieuXuat.create(b);
	} catch(const int &ern){
		if(ern==1){
        	cout<<"Khong the tao phieu (ngay thang nam khong hop le)!\n";
			return false;
		} else if(ern==2){
			cout<<"Khong the tao phieu (phieu da duoc tao truoc)!";
			return false;
		}
	}
    cout<<"Nhap so luong mat hang: "; cin>>tmpCnt; cin.ignore();
    cout<<"Nhap danh sach hang hoa:\n";
	for(int i=0;i<tmpCnt;i++){
        goods S;
	    cout<<"Nhap thong tin hang hoa thu "<<i+1<<":\n";
		try{
			khoNhap.xuat(S);
			if(S.DT()>b.ngayNhapXuat_()) throw(2);
    		khoNhap.reduce(S);
			b.add(S);
		} catch(int &ern){
			if(ern==1){
				cout<<"Khong the xuat hang hoa (khong tim thay hang hoa tuong ung trong kho)!\n";
				return false;
			}
			if(ern==2){
				cout<<"Khong the xuat hang hoa (ngay xuat hang truoc ngay nhap hang)!\n";
				return false;
			}
			if(ern==3){
				cout<<"Khong the xuat hang hoa (so luong hoac don gia can xuat be hon hoac bang 0)!\n";
				return false;
			}
			if(ern==4){
				cout<<"Khong the xuat hang hoa (so luong can xuat lon hon so luong hang hoa trong kho)!\n";
				return false;
			}
		}
    }
	b.print();
    phieuXuat.insertTail(b);
	return true;
}

bool option3(){
	if(khoNhap.isEmpty()){
		cout<<"Kho trong!\n";
		return false;
	}
	int ch1=0, ch2=0;
	cout<<"Chon thuoc tinh sap xep\n";
	cout<<"(1: ma hang hoa\n2: ten hang hoa\n3: loai hang hoa\n";
	cout<<"4: don vi tinh\n5: ngay nhap hang\n6: nha san xuat\n";
	cout<<"7: so luong\n8: don gia\n9: thanh tien): "; cin>>ch1;
	cout<<"Chon thu tu sap xep\n";
	cout<<"(1: tang dan\n2: giam dan): "; cin>>ch2;
	khoNhap.Sort(ch2, ch1);
	cin.get();
    return true;
}

bool option4(){
	if(phieuNhap.isEmpty()){
		cout<<"Chua co phieu duoc tao!\n";
		return false;
	}
	int ch1=0, ch2=0;
	cout<<"Chon thuoc tinh sap xep\n";
	cout<<"(1: ma phieu\n2: nguoi tao\n3: ngay tao\n";
	cout<<"4: ngay nhap xuat\n5: so mat hang\n6: tong gia tien\n"; cin>>ch1;
	cout<<"Chon thu tu sap xep\n";
	cout<<"(1: tang dan\n2: giam dan): "; cin>>ch2;
	phieuNhap.Sort(ch2, ch1);
	cin.get();
    return true;
}

bool option5(){
	if(phieuXuat.isEmpty()){
		cout<<"Chua co phieu duoc tao!\n";
		return false;
	}
	int ch1=0, ch2=0;
	cout<<"Chon thuoc tinh sap xep\n";
	cout<<"(1: ma phieu\n2: nguoi tao\n3: ngay tao\n";
	cout<<"4: ngay nhap xuat\n5: so mat hang\n6: tong gia tien\n"; cin>>ch1;
	cout<<"Chon thu tu sap xep\n";
	cout<<"(1: tang dan\n2: giam dan): "; cin>>ch2;
	phieuXuat.Sort(ch2, ch1);
	cin.get();
    return true;
}

bool option6(){
	try{
		khoNhap.show();
	} catch(const char* err){
		cerr<<err;
	}
	return true;
}

bool option7(){
	date start;
	date end;
	try{
		try{
			cout<<"Nhap ngay bat dau:\n"; cin>>start;
			cin.ignore();
			if(!start.isValid()) throw(0);
		} catch(...){
			cout<<"Ngay thang nam khong hop le!\n";
			return false;
		}
		try{
			cout<<"Nhap ngay ket thuc:\n"; cin>>end;
			cin.ignore();
			if(!end.isValid()) throw(0);
		} catch(...){
			cout<<"Ngay thang nam khong hop le!\n";
			return false;
		}
		if(start>end){
			throw(0);
		}
		cout<<"Lich su nhap:\n"; phieuNhap.history(start, end);
		cout<<endl;
		cout<<"Lich su xuat:\n"; phieuXuat.history(start, end);
		return true;
	} catch(...){
		cout<<"Ngay bat dau khong the lon hon ngay ket thuc!\n";
		return false;
	}
}

bool option8(){
	try{
		phieuNhap.show();
	} catch(const char* err){
		cerr<<err;
	}
	return true;
}

bool option9(){
	try{
		phieuXuat.show();
	} catch(const char* err){
		cerr<<err;
	}
	return true;
}

bool option10(){
	int att;
	cout<<"Ban muon tim kiem theo (1: code, 2: filter): "; cin>>att;
	cin.ignore();
	try{
		khoNhap.Search(att);
	}
	catch(const int &ern){
		switch(ern){
			case 1:
				cout<<"Input khong hop le!\n";
				break;
			case 2:
				cout<<"Ngay thang nam khong hop le!\n";
				break;
			case 3:
				cout<<"Ngay ket thuc khong the truoc ngay nhap hang!\n";
				break;
			case 4:
				cout<<"So luong khong the be hon hoac bang 0\n";
				break;
			case 5:
				cout<<"So luong max khong the be hon so luong min\n";
				break;
			case 6:
				cout<<"Don gia khong the be hon hoac bang 0\n";
				break;
			case 7:
				cout<<"Don gia max khong the be hon don gia min\n";
				break;
		}
		return false;
	}
	return true;
}

bool option11(){
	int att;
	cout<<"Ban muon tim kiem theo (1: code, 2: filter): "; cin>>att;
	cin.ignore();
	try{
		phieuNhap.Search(1, att);
	}
	catch(const int &ern){
		switch(ern){
			case 1:
				cout<<"Input khong hop le!\n";
				break;
			case 2:
				cout<<"Ngay thang nam khong hop le!\n";
				break;
			case 3:
				cout<<"Ngay ket thuc khong the truoc ngay nhap hang!\n";
				break;
			case 4:
				cout<<"So mat hang khong the be hon hoac bang 0\n";
				break;
			case 5:
				cout<<"So mat hang max khong the be hon so mat hang min\n";
				break;
			case 6:
				cout<<"Tong gia tien khong the be hon hoac bang 0\n";
				break;
			case 7:
				cout<<"Tong gia tien max khong the be hon tong gia tien min\n";
				break;
		}
		return false;
	}
	return true;
}

bool option12(){
	int att;
	cout<<"Ban muon tim kiem theo (1: code, 2: filter): "; cin>>att;
	try{
		phieuXuat.Search(0, att);
	}
	catch(const int &ern){
		switch(ern){
			case 1:
				cout<<"Input khong hop le!\n";
				break;
			case 2:
				cout<<"Ngay thang nam khong hop le!\n";
				break;
			case 3:
				cout<<"Ngay ket thuc khong the truoc ngay nhap hang!\n";
				break;
			case 4:
				cout<<"So mat hang khong the be hon hoac bang 0\n";
				break;
			case 5:
				cout<<"So mat hang max khong the be hon so mat hang min\n";
				break;
			case 6:
				cout<<"Tong gia tien khong the be hon hoac bang 0\n";
				break;
			case 7:
				cout<<"Tong gia tien max khong the be hon tong gia tien min\n";
				break;
		}
		return false;
	}
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
    dsPNin.open("dbBillin.txt", ifstream::in);
	dsPNin>>phieuNhap;
    dsPNin.close();
	ifstream dsPXin;
    dsPXin.open("dbBillout.txt", ifstream::in);
	dsPXin>>phieuXuat;
    dsPXin.close();
	while(true){
		khoNhap.print();
		phieuNhap.print(1);
		phieuXuat.print(0);
		system("clear");
		cout<<"---------------Menu---------------\n";
		cout<<" 1. Tao phieu nhap hang hoa (nhap hang hoa).\n";
		cout<<" 2. Tao phieu xuat hang hoa (xuat hang hoa).\n";
		cout<<" 3. Sap xep danh sach hang hoa.\n";
		cout<<" 4. Sap xep danh sach phieu nhap.\n";
		cout<<" 5. Sap xep danh sach phieu xuat.\n";
		cout<<" 6. Hien thi danh sach hang hoa.\n";
		cout<<" 7. Hien thi lich su xuat nhap kho.\n";
		cout<<" 8. Hien thi danh sach phieu nhap kho.\n";
		cout<<" 9. Hien thi danh sach phieu xuat kho.\n";
		cout<<"10. Tim kiem hang hoa.\n";
		cout<<"11. Tim kiem phieu nhap kho.\n";
		cout<<"12. Tim kiem phieu xuat kho.\n";
		cout<<"13. Ket thuc.\n";
		reinput:
		cout<<"\nLua chon cua ban la: ";
		string line;
		while(getline(cin, line)){
			stringstream ss(line);
			if(ss>>control1){
				if(ss.eof()){
					break;
				}
			}
			cout<<"----------------------------------\n";
			cout<<"Input khong hop le!\nMoi ban nhap lai.\n";
			cout<<"\nLua chon cua ban la: ";
		}
		cout<<"----------------------------------\n";
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
				isS = option6();
				break;
			case 7:
				isS = option7();
				break;
			case 8:
				isS = option8();
				break;
			case 9:
				isS = option9();
				break;
			case 10:
				isS = option10();
				break;
			case 11:
				isS = option11();
				break;
			case 12:
				isS = option12();
				break;
			case 13:
				goto ketthuc;
				break;	
			default:
				cout<<"Input khong hop le!\nMoi ban nhap lai.\n";
				goto reinput;
				break;
		}
		control1=-1;
		cout<<"\nThuc hien "<<((isS)?"":"khong ")<<"thanh cong!\nNhan phim Enter de tiep tuc.\n";
		int c;
		while((c=getchar())!='\n' && c!=EOF);
	}
	ketthuc:{
		ofstream dbout;
		dbout.open("database.txt", ofstream::out);
		dbout<<khoNhap;
		dbout.close();
		ofstream dsPNout;
		dsPNout.open("dbBillin.txt", ofstream::out);
		dsPNout<<phieuNhap;
		dsPNout.close();
		ofstream dsPXout;
		dsPXout.open("dbBillout.txt", ofstream::out);
		dsPXout<<phieuXuat;
		dsPXout.close();
		cout<<"Chuong trinh da ket thuc!\n";
	}
	return 0;
}

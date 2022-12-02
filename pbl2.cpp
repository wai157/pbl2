#include <bits/stdc++.h>
#include "pbl2.h"
using namespace std;

pbl2::pbl2(){
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
	welcome();
	menu();
}

pbl2::~pbl2(){
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
    cout<<"\u001b[32;1mChuong trinh da ket thuc!\u001b[0m\n";
}

void pbl2::welcome(){
	system("clear");
	cout<<" _____    _    _              _   _     __  __   ______   __  __ \n";    
    cout<<"|  __ \\  | |  | |     /\\     | \\ | |   |  \\/  | |  ____| |  \\/  |\n"; 
    cout<<"| |__) | | |__| |    /  \\    |  \\| |   | \\  / | | |__    | \\  / |\n";  
    cout<<"|  ___/  |  __  |   / /\\ \\   | . ` |   | |\\/| | |  __|   | |\\/| |\n";  
    cout<<"| |      | |  | |  / ____ \\  | |\\  |   | |  | | | |____  | |  | |\n";   
    cout<<"|_|      |_|  |_| /_/    \\_\\ |_| \\_|   |_|  |_| |______| |_|  |_|\n";   
    cout<<"  ____    _    _              _   _     _        _____ \n";
    cout<<" / __ \\  | |  | |     /\\     | \\ | |   | |      |_   _|\n";
    cout<<"| |  | | | |  | |    /  \\    |  \\| |   | |        | |  \n";
    cout<<"| |  | | | |  | |   / /\\ \\   | . ` |   | |        | |  \n";
    cout<<"| |__| | | |__| |  / ____ \\  | |\\  |   | |____   _| |_ \n";
    cout<<" \\___\\_\\  \\____/  /_/    \\_\\ |_| \\_|   |______| |_____|\n";                                                                                                                                                                                                                                                                                                                                    
    cout<<"__   __  _    _              _______     _   _   _    _              _____      _  __  _    _    ____  \n";
    cout<<"\\ \\ / / | |  | |     /\\     |__   __|   | \\ | | | |  | |     /\\     |  __ \\    | |/ / | |  | |  / __ \\ \n";
    cout<<" \\ V /  | |  | |    /  \\       | |      |  \\| | | |__| |    /  \\    | |__) |   | ' /  | |__| | | |  | |\n";
    cout<<"  > <   | |  | |   / /\\ \\      | |      | . ` | |  __  |   / /\\ \\   |  ___/    |  <   |  __  | | |  | |\n";
    cout<<" / . \\  | |__| |  / ____ \\     | |      | |\\  | | |  | |  / ____ \\  | |        | . \\  | |  | | | |__| |\n";
    cout<<"/_/ \\_\\  \\____/  /_/    \\_\\    |_|      |_| \\_| |_|  |_| /_/    \\_\\ |_|        |_|\\_\\ |_|  |_|  \\____/ \n"; 
    cout<<"\nThuc hien boi:\n";
	cout<<"\tPhan Minh Nhat\n";
	cout<<"\tHo Quoc Thien Anh\n";
	cout<<"\tNguyen Van Thanh Hoang\n";
	cout<<"\nNhan phim Enter de vao chuong trinh.\n";
	int c;
	while((c=getchar())!='\n' && c!=EOF);
}

void pbl2::menu(){
    int control1=-1;
	bool isS;
	while(true){
		khoNhap.print();
		phieuNhap.print(1);
		phieuXuat.print(0);
		system("clear");
		cout<<"\u001b[44;1m-------------------------MENU-------------------------\u001b[0m\n";
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
		cout<<"\n\u001b[36mLua chon cua ban la:\u001b[0m ";
		string line;
		while(getline(cin, line)){
			stringstream ss(line);
			if(ss>>control1){
				if(ss.eof()){
					break;
				}
			}
			cout<<"------------------------------------------------------\n";
			cout<<"\u001b[31mInput khong hop le!\nMoi ban nhap lai.\u001b[0m\n";
			cout<<"\n\u001b[36mLua chon cua ban la:\u001b[0m ";
		}
		cout<<"------------------------------------------------------\n";
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
				return;
			default:
				cout<<"\u001b[31mInput khong hop le!\nMoi ban nhap lai.\u001b[0m\n";
				goto reinput;
				break;
		}
		control1=-1;
		if(isS==1)
			cout<<"\n\u001b[32mThuc hien thanh cong!\u001b[0m\n";
		else cout<<"\n\u001b[31mThuc hien khong thanh cong!\u001b[0m\n";
		cout<<"\u001b[36mNhan phim Enter de tiep tuc.\u001b[0m\n";
		int c;
		while((c=getchar())!='\n' && c!=EOF);
	}
}

bool pbl2::option1(){
	bill b(1);
	int tmpCnt;
	try{
		phieuNhap.create(b);
	}
	catch(const char *errt){
		cerr<<"\u001b[31m"<<errt<<"\u001b[0m";
		return false;
	}
    cout<<"Nhap so luong mat hang: "; cin>>tmpCnt; cin.ignore();
    cout<<"Nhap danh sach hang hoa:\n";
	for(int i=0;i<tmpCnt;i++){
        goods S;
	    cout<<"Nhap thong tin hang hoa thu "<<i+1<<":\n";
		try{
			khoNhap.nhap(S);
			S.setDT(b.ngayNhapXuat_());
			b.add(S);
		}
		catch(const char *errt){
			cerr<<"\u001b[31m"<<errt<<"\u001b[0m";
			return false;
		}
    }
	khoNhap.addBill(b);
	b.print();
    phieuNhap.insertTail(b);
	return true;
}

bool pbl2::option2(){
	if(khoNhap.isEmpty()){
		cout<<"Kho trong!\n";
		return false;
	}
	bill b(0);
	int tmpCnt;
	try{
		phieuXuat.create(b);
	} catch(const char *errt){
		cerr<<"\u001b[31m"<<errt<<"\u001b[0m";
		return false;
	}
    cout<<"Nhap so luong mat hang: "; cin>>tmpCnt; cin.ignore();
    cout<<"Nhap danh sach hang hoa:\n";
	for(int i=0;i<tmpCnt;i++){
        goods S;
	    cout<<"Nhap thong tin hang hoa thu "<<i+1<<":\n";
		try{
			khoNhap.xuat(S);
			if(S.DT()>b.ngayNhapXuat_()) throw("Khong the xuat hang hoa (ngay xuat hang truoc ngay nhap hang)!\n");
			b.add(S);
		} catch(const char *errt){
			cerr<<"\u001b[31m"<<errt<<"\u001b[0m";
			return false;
		}
    }
	try{
		khoNhap.subBill(b);
	} catch(const char *errt){
		cerr<<"\u001b[31m"<<errt<<"\u001b[0m";
		return false;
	}
	b.print();
    phieuXuat.insertTail(b);
	return true;
}

bool pbl2::option3(){
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

bool pbl2::option4(){
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

bool pbl2::option5(){
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

bool pbl2::option6(){
	try{
		khoNhap.show();
	} catch(const char *errt){
		cerr<<"\u001b[31m"<<errt<<"\u001b[0m";
	}
	return true;
}

bool pbl2::option7(){
	date start;
	date end;
	try{
		try{
			cout<<"Nhap ngay bat dau:\n"; cin>>start;
			cin.ignore();
			if(!start.isValid()) throw("Ngay thang nam khong hop le!\n");
		} catch(const char *errt){
			cerr<<"\u001b[31m"<<errt<<"\u001b[0m";
			return false;
		}
		try{
			cout<<"Nhap ngay ket thuc:\n"; cin>>end;
			cin.ignore();
			if(!end.isValid()) throw("Ngay thang nam khong hop le!\n");
		} catch(const char *errt){
			cerr<<"\u001b[31m"<<errt<<"\u001b[0m";
			return false;
		}
		if(start>end){
			throw("Ngay bat dau khong the lon hon ngay ket thuc!\n");
		}
		cout<<"\n\u001b[42;1mLich su nhap:\u001b[0m\n"; phieuNhap.history(start, end);
		cout<<endl;
		cout<<"\u001b[42;1mLich su xuat:\u001b[0m\n"; phieuXuat.history(start, end);
		return true;
	} catch(const char *errt){
		cerr<<"\u001b[31m"<<errt<<"\u001b[0m";
		return false;
	}
}

bool pbl2::option8(){
	try{
		phieuNhap.show();
	} catch(const char *errt){
		cerr<<"\u001b[31m"<<errt<<"\u001b[0m";
	}
	return true;
}

bool pbl2::option9(){
	try{
		phieuXuat.show();
	} catch(const char *errt){
		cerr<<"\u001b[31m"<<errt<<"\u001b[0m";
	}
	return true;
}

bool pbl2::option10(){
	int att;
	cout<<"Ban muon tim kiem theo (1: code, 2: filter): "; cin>>att;
	cin.ignore();
	try{
		khoNhap.Search(att);
	}
	catch(const int &ern){
		cout<<"\u001b[31m";
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
				cout<<"So luong khong the be hon hoac bang 0!\n";
				break;
			case 5:
				cout<<"So luong max khong the be hon so luong min!\n";
				break;
			case 6:
				cout<<"Don gia khong the be hon hoac bang 0!\n";
				break;
			case 7:
				cout<<"Don gia max khong the be hon don gia min!\n";
				break;
		}
		cout<<"\u001b[0m";
		return false;
	}
	return true;
}

bool pbl2::option11(){
	int att;
	cout<<"Ban muon tim kiem theo (1: code, 2: filter): "; cin>>att;
	cin.ignore();
	try{
		phieuNhap.Search(1, att);
	}
	catch(const int &ern){
		cout<<"\u001b[31m";
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
				cout<<"So mat hang khong the be hon hoac bang 0!\n";
				break;
			case 5:
				cout<<"So mat hang max khong the be hon so mat hang min!\n";
				break;
			case 6:
				cout<<"Tong gia tien khong the be hon hoac bang 0!\n";
				break;
			case 7:
				cout<<"Tong gia tien max khong the be hon tong gia tien min!\n";
				break;
		}
		cout<<"\u001b[0m";
		return false;
	}
	return true;
}

bool pbl2::option12(){
	int att;
	cout<<"Ban muon tim kiem theo (1: code, 2: filter): "; cin>>att;
	try{
		phieuXuat.Search(0, att);
	}
	catch(const int &ern){
		cout<<"\u001b[31m";
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
				cout<<"So mat hang khong the be hon hoac bang 0!\n";
				break;
			case 5:
				cout<<"So mat hang max khong the be hon so mat hang min!\n";
				break;
			case 6:
				cout<<"Tong gia tien khong the be hon hoac bang 0!\n";
				break;
			case 7:
				cout<<"Tong gia tien max khong the be hon tong gia tien min!\n";
				break;
		}
		cout<<"\u001b[0m";
		return false;
	}
	return true;
}                                                                                                                                                                    
                                                                                                                                                               
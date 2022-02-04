#include<iostream>
#include<iomanip>
#include<vector> 
#include<windows.h>
#include<string>

using namespace std;

class NhanVien{
    protected:
        string MaSo, HoTen;
        int Tuoi;
        float Luong;
        string GioiTinh, QueQuan;
        bool Check;
    public:
    	void textcolor(int x);  
    	NhanVien(){
			MaSo = " ";
			HoTen = " ";
			Tuoi = 0;
			GioiTinh = " ";
			QueQuan = " ";
			Luong = 0;
		}
		~NhanVien(){}
		
        virtual void Nhap();
        
       	virtual void Xuat();
       	
        virtual float TinhLuong()=0;
        
        bool Get_KieuNV(){
        return this->Check;
    	}
    	
    	void Set_KieuNV(bool check){
        this->Check = check;
    	}
    	
    	string GetMaSo(){
    		return this->MaSo;
		}
        
        int GetTuoi(){
        	return this->Tuoi;
		}
        
        string GetQue(){
        	return this->QueQuan;                    
        }
        
        string GetTen(){
			return this->HoTen;
		}
		
};

void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle

		(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void NhanVien::Nhap(){
	cout<<"Nhap Ma So: ";
	fflush(stdin);
    getline(cin,MaSo);
    cout<<"Nhap Ho Ten: ";
    fflush(stdin);
    getline(cin,HoTen);
    cout<<"Nhap Gioi Tinh: ";
    fflush(stdin);
    getline(cin,GioiTinh);
    do{
        cout<<"Nhap Tuoi: ";
        cin>>Tuoi;
        if(Tuoi<=14)
            cout<<"Tuoi Khong Hop Le.Xin Kiem Tra Lai!!"<<endl;
    }while(Tuoi<=14);
    cout<<"Nhap Que Quan: ";
	fflush(stdin);
	getline(cin,QueQuan);
}

void NhanVien::Xuat(){
	cout<<endl<<right<<setw(35)<<MaSo<<setw(20)<<HoTen<<setw(14)<<GioiTinh<<setw(20)<<QueQuan<<setw(20)<<Tuoi<<endl;
}

class NhanVienThamNien:public NhanVien{
    private:
        float HeSoLuong,ThamNien;
    public:
    	NhanVienThamNien(){
			HeSoLuong = 0;
			ThamNien = 0;
		}
		
		~NhanVienThamNien(){}
		
        void Nhap();
        
        void Xuat();
        
        float TinhLuong();
};

float NhanVienThamNien::TinhLuong(){
	return HeSoLuong*1600 + ThamNien*500;
}

void NhanVienThamNien::Nhap(){
	NhanVien::Nhap();
	do{
        cout<<"Nhap He So Luong: ";
        cin>>HeSoLuong;
        if(HeSoLuong<=0)
            cout<<"He So Luong Khong Hop Le.Xin Kiem Tra Lai!!"<<endl;
    }while(HeSoLuong<=0);
    
	do{
        cout<<"Nhap Tham Nien: ";
    	cin>>ThamNien;
        if(ThamNien<=0)
            cout<<"Tham Nien Khong Hop Le.Xin Kiem Tra Lai!!"<<endl;
    }while(ThamNien<=0);
}

void NhanVienThamNien::Xuat(){
	this->TinhLuong();
	cout<<endl<<right<<setw(35)<<MaSo<<setw(20)<<HoTen<<setw(14)<<GioiTinh<<setw(20)<<Tuoi<<setw(20)<<QueQuan<<setw(20)<<HeSoLuong<<setw(20)<<ThamNien<<setw(20)<<TinhLuong()<<endl;
}

class NhanVienThoiVu:public NhanVien{
    private:
        int SoGioLam;
        float DonGia;
    public:
    	NhanVienThoiVu(){
    		SoGioLam = 0;
    		DonGia = 0;
    	}
    	
    	~NhanVienThoiVu(){}
        void Nhap();
        
        void Xuat();
        
        float TinhLuong();
};

float NhanVienThoiVu::TinhLuong(){
	return this->SoGioLam*this->DonGia;
}

void NhanVienThoiVu::Nhap(){
	NhanVien::Nhap();
    do{
        cout<<"Nhap So Gio Lam: ";
        cin>>SoGioLam;
        if(SoGioLam<=0)
            cout<<"So Gio Lam Khong Hop Le.Xin Kiem Tra Lai!!"<<endl;
    }while(SoGioLam<=0);
    
	do{
        cout<<"Nhap Don Gia: ";
    	cin>>DonGia;
        if(DonGia<=0)
            cout<<"Don Gia Khong Hop Le.Xin Kiem Tra Lai!!"<<endl;
    }while(DonGia<=0);
}

void NhanVienThoiVu::Xuat(){
    this->TinhLuong();
	cout<<endl<<right<<setw(35)<<MaSo<<setw(20)<<HoTen<<setw(14)<<GioiTinh<<setw(20)<<Tuoi<<setw(20)<<QueQuan<<setw(20)<<SoGioLam<<setw(20)<<DonGia<<setw(20)<<TinhLuong()<<endl;
}

class QuanLyNhanVien{
    private:
        vector<NhanVien *> NV;
    public:
    	QuanLyNhanVien(){}
    	
    	~QuanLyNhanVien(){}
    	
        void NhapDS();
        
        void XuatDS();
        
        void XuatDSS();
        
      	void TinhLuong();
      	
		void SapXep();
		
		void TimKiem();
		
		void Xoa();
};

void QuanLyNhanVien::NhapDS(){
   	NhanVien *nv;
   	int n,m;
	int choose;
	do
	{
		system("cls");
		cout<<"\n\t\t\t\t\t\t\t\t\t\t|--------------NHAP NHAN VIEN---------------|";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t|	1.Nhap nhan vien tham nien.         |";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t|	2.Nhap nhan vien thoi vu.           |";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t|	3.Quay Lai.			    |";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t|-------------------------------------------|";
		cout<<"\n\t\t\t\t\t\t\t\t\t\tVui Long Nhap Lua Chon: ";
		cin>>choose;
		switch (choose)
		{
		case 1:
			{
				cout<<"\n\tNHAP NHAN VIEN THAM NIEN";
				cout<<"\n";
				textcolor(7);
				cout<<"\nNhap so luong nhan vien tham nien: ";
	            cin>>n;
	            for(int i=0;i<n;i++){
	            	cout<<"\nNhan Vien Thu "<<i+1<<endl;
	                nv=new NhanVienThamNien;
	                nv->Nhap();
	                nv->Set_KieuNV(true);
	                NV.push_back(nv);
	                cout<<endl;
	            }
			}
			break;
		case 2:
			{
				textcolor(11);
				cout<<"\n\tNHAP NHAN VIEN THOI VU";
				cout<<"\n";
				textcolor(7);
				cout<<"Nhap so luong nhan vien thoi vu: ";
	            cin>>m;
	            for(int i=0;i<m;i++){
	            	cout<<"\nNhan Vien Thu "<<i+1<<endl;
	                nv=new NhanVienThoiVu;
	                nv->Nhap();
	                nv->Set_KieuNV(false);
	                NV.push_back(nv);
	                cout<<endl;
			}
			break;
		default:
			break;
		}
		}
	} while (choose!=3);                 
}

void QuanLyNhanVien::XuatDS(){
	int choose;
	do
	{
		system("cls");
		textcolor(11);
		cout<<"\n\t\t\t\t\t\t\t\t\t\t|--------------XUAT NHAN VIEN---------------|";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t|	1.Xuat nhan vien tham nien.         |";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t|	2.Xuat nhan vien thoi vu.           |";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t|	3.Xuat tat ca nhan vien.	    |";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t|	4.Quay Lai.			    |";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t|-------------------------------------------|";
		cout<<"\n\t\t\t\t\t\t\t\t\t\tVui Long Nhap Lua Chon: ";
	
		cin>>choose;
    switch (choose)
		{
		case 1:
			{
				system("cls");
				cout<<"\n\t\t\t\t\t\t\t\t\t\t\tDANH SACH NHAN VIEN THAM NIEN.";
				cout<<"\n";
				textcolor(3);
				cout<<endl<<right<<setw(35)<<"MA SO"<<setw(20)<<"HO & TEN"<<setw(15)<<"GIOI TINH "<<setw(20)<<"TUOI "<<setw(20)<<"QUE QUAN "<<setw(20)<<"HE SO LUONG "<<setw(20)<<"THAM NIEN "<<setw(20)<<"LUONG";
				cout<<"\n";
				textcolor(7);
				for(int i=0;i<NV.size();i++)
				{
					if (NV[i]->Get_KieuNV() == true)
					NV[i]->Xuat();
				}
				system("pause");
			}
			break;
		case 2:
			{
				system("cls");
				textcolor(11);
				cout<<"\n\t\t\t\t\t\t\t\t\t\t\tDANH SACH NHAN VIEN THOI VU.";
				cout<<"\n";
				textcolor(3);
				cout<<endl<<right<<setw(35)<<"MA SO"<<setw(20)<<"HO & TEN"<<setw(15)<<"GIOI TINH "<<setw(20)<<"TUOI "<<setw(20)<<"QUE QUAN "<<setw(20)<<"SO GIO LAM "<<setw(20)<<"DON GIA "<<setw(20)<<"LUONG";
				cout<<"\n";
				textcolor(7);
				for(int i=0;i<NV.size();i++)
				{
					if (NV[i]->Get_KieuNV() == false)
						NV[i]->Xuat();
				}
				system("pause");
			}
			break;
		case 3:
			{
				system("cls");
				cout<<"\n";
				textcolor(11);
				cout<<"\n\t\t\t\t\t\t\t\t\t\t\tDANH SACH NHAN VIEN THAM NIEN.";
				cout<<"\n";
				textcolor(3);
				cout<<endl<<right<<setw(35)<<"MA SO"<<setw(20)<<"HO & TEN"<<setw(15)<<"GIOI TINH "<<setw(20)<<"TUOI "<<setw(20)<<"QUE QUAN "<<setw(20)<<"HE SO LUONG "<<setw(20)<<"THAM NIEN "<<setw(20)<<"LUONG";
				cout<<"\n";
				textcolor(7);
				for(int i=0;i<NV.size();i++)
				{
					if (NV[i]->Get_KieuNV() == true)
					NV[i]->Xuat();
				}
				cout<<"\n";
				textcolor(11);
				cout<<"\n\t\t\t\t\t\t\t\t\t\t\tDANH SACH NHAN VIEN THOI VU.";
				cout<<"\n";
				textcolor(3);
				cout<<endl<<right<<setw(35)<<"MA SO"<<setw(20)<<"HO & TEN"<<setw(15)<<"GIOI TINH "<<setw(20)<<"TUOI "<<setw(20)<<"QUE QUAN "<<setw(20)<<"HE SO LUONG "<<setw(20)<<"THAM NIEN "<<setw(20)<<"LUONG";
				cout<<"\n";
				textcolor(7);
				for(int i=0;i<NV.size();i++)
				{
					if (NV[i]->Get_KieuNV() == false)
					NV[i]->Xuat();
				}
            	
				system("pause");
			}
			break;
		default:
			break;
		}
	} while (choose!=4);
}

void QuanLyNhanVien::XuatDSS(){
    for(int i=0; i<this->NV.size();i++){
    	if (NV[i]->Get_KieuNV()){
    		textcolor(11);
			cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\tNHAN VIEN THAM NIEN.";
			cout<<"\n";
			textcolor(3);
			cout<<endl<<right<<setw(35)<<"MA SO"<<setw(20)<<"HO & TEN"<<setw(15)<<"GIOI TINH "<<setw(20)<<"TUOI "<<setw(20)<<"QUE QUAN "<<setw(20)<<"HE SO LUONG "<<setw(20)<<"THAM NIEN "<<setw(20)<<"LUONG";	
			cout<<"\n";
		}else{
			textcolor(11);
			cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\tNHAN VIEN THOI VU.";
			cout<<"\n";
			textcolor(3);
			cout<<endl<<right<<setw(35)<<"MA SO"<<setw(20)<<"HO & TEN"<<setw(15)<<"GIOI TINH "<<setw(20)<<"TUOI "<<setw(20)<<"QUE QUAN "<<setw(20)<<"SO GIO LAM "<<setw(20)<<"DON GIA "<<setw(20)<<"LUONG";
			cout<<"\n";
		}
		textcolor(7);
        this->NV.at(i)->Xuat();
        cout<<endl;
    }
}

void QuanLyNhanVien::TinhLuong()
{
	int choose;
	do
	{
		system("cls");
		textcolor(11);
		cout<<"\n\t\t\t\t\t\t\t\t\t|--------------TINH LUONG NHAN VIEN--------------|";
		cout<<"\n\t\t\t\t\t\t\t\t\t| 1.Tinh tong tien luong cua nhan vien tham nien.|";
		cout<<"\n\t\t\t\t\t\t\t\t\t| 2.Tinh tong tien luong cua nhan vien thoi vu.  |";
		cout<<"\n\t\t\t\t\t\t\t\t\t| 3.Tinh tong tien luong cua tat ca nhan vien.   |";
		cout<<"\n\t\t\t\t\t\t\t\t\t| 4.Quay Lai                                     |";
		cout<<"\n\t\t\t\t\t\t\t\t\t|------------------------------------------------|";
		cout<<"\n\t\t\t\t\t\t\t\t\tVui Long Nhap Lua Chon: ";
		cin>>choose;
		switch (choose)
		{
		case 1:
			{
				system("cls");
				float s1=0;
				for(int i=0;i<NV.size();i++)
				{
					if (NV[i]->Get_KieuNV() == true)
					s1+=NV[i]->TinhLuong();
				}
				textcolor(9);
				cout<<"\n\t\t\t\t\t\t\t\t|-------------------------------NHAN VIEN THAM NIEN-----------------------------|\n";
				cout<<"\t\t\t\t\t\t\t\t|		    Tong tien luong cua nhan vien tham nien la: "<<s1<<"\t\t|";
				cout<<"\n\t\t\t\t\t\t\t\t|-------------------------------------------------------------------------------|"<<endl;
				
				system("pause");
			}
			break;
		case 2:
			{
				system("cls");
				float s2=0;
				for(int i=0;i<NV.size();i++)
				{
					if (NV[i]->Get_KieuNV() == false)
					s2+=NV[i]->TinhLuong();
				}
				textcolor(9);
				cout<<"\n\t\t\t\t\t\t\t\t|-------------------------------NHAN VIEN THOI VU-------------------------------|\n";
				cout<<"\t\t\t\t\t\t\t\t|		    Tong tien luong cua nhan vien thoi vu la:  "<<s2<<"\t\t|";
				cout<<"\n\t\t\t\t\t\t\t\t|-------------------------------------------------------------------------------|"<<endl;
	
				system("pause");
			}
			break;
		case 3:
			{
				system("cls");
				float s=0;
			    for (int i = 0; i < NV.size(); i++){
			        s = s + NV[i]->TinhLuong();
			    }
			    textcolor(9);
				cout<<"\n\t\t\t\t\t\t\t\t|-------------------------------TAT CA NHAN VIEN -------------------------------|\n";
				cout<<"\t\t\t\t\t\t\t\t|		    Tong tien luong cua tat ca nhan vien la:  "<<s<<"\t\t|";
				cout<<"\n\t\t\t\t\t\t\t\t|-------------------------------------------------------------------------------|"<<endl;
				
				system("pause");
			}
		default:
			break;
		}
	} while (choose!=4);
}

void QuanLyNhanVien::SapXep() 
{
	int choose;
	do{
		system("cls");
		cout <<setw(80)<<"|"<<"------------------------------------------|"<<endl;
		cout <<setw(80)<<"|"<<setw(30)<<"SAP XEP TANG DAN"<<setw(13)<<"|"<<endl;
		cout <<setw(80)<<"|"<<"1.Sap xep nhan vien theo ma so"<<"\t\t  |"<<endl;
		cout <<setw(80)<<"|"<<"2.Sap xep nhan vien theo luong"<<"\t\t  |"<<endl;
		cout <<setw(80)<<"|"<<"3.Sap xep nhan vien theo tuoi"<<"\t\t  |"<<endl;
		cout <<setw(80)<<"|"<<"4.Quay lai"<<setw(33)<<"|"<<endl;
		cout <<setw(80)<<"|"<<"------------------------------------------|"<<endl;
		cout <<"\n";
		cout <<setw(105)<<"Vui long nhap lua chon: "; 
		cin >> choose;
		switch(choose) 
		{
			case 1: 
				{	
					for(int i=0; i<NV.size()-1; i++) {
						for(int j=i+1; j< NV.size(); j++) {
							if(NV[i]->GetMaSo() > NV[j]->GetMaSo()){
								swap(NV[i],NV[j]);
							}
						}	
					}
					XuatDSS();	
					system("pause");
				}
				break;
			case 2:
				{
					for(int i=0; i<NV.size()-1; i++) {
						for(int j=i+1; j<NV.size(); j++) {
							if(NV[i]->TinhLuong() > NV[j]->TinhLuong())
								swap(NV[i], NV[j]);
						}
					}
					XuatDSS();
					system("pause");
				}
				break;
			case 3:
				{
					for(int i=0; i<NV.size()-1; i++) {
						for(int j=i+1; j<NV.size(); j++) {
							if(NV[i]->GetTuoi() > NV[j]->GetTuoi())
								swap(NV[i], NV[j]);
						}
					}
					XuatDSS();	
					system("pause");
				}
				break;
			default:
				break;
		}
	}while(choose != 4);
}

void QuanLyNhanVien::TimKiem()
{
	int choose;
	do{
		system("cls");
		cout <<setw(80)<<"|"<<"------------------------------------------------|"<<endl;
		cout <<setw(80)<<"|"<<setw(30)<<"TIM KIEM NHAN VIEN"<<setw(19)<<"|"<<endl;
		cout <<setw(80)<<"|"<<"\t1.Tim kiem nhan vien theo ten"<<setw(12)<<"|"<<endl;
		cout <<setw(80)<<"|"<<"\t2.Tim kiem nhan vien theo tuoi"<<setw(11)<<"|"<<endl;
		cout <<setw(80)<<"|"<<"\t3.Tim kiem nhan vien theo luong"<<setw(10)<<"|"<<endl;
		cout <<setw(80)<<"|"<<"\t4.Tim kiem nhan vien theo que quan"<<setw(7)<<"|"<<endl;
		cout <<setw(80)<<"|"<<"\t5.Quay lai"<<setw(31)<<"|"<<endl;
		cout <<setw(80)<<"|"<<"------------------------------------------------|"<<endl;
		cout <<"\n";
		cout <<setw(105)<<"Vui long nhap lua chon: "; 
		cin >> choose;
		switch(choose) 
		{
			case 1:
				{
					string Ten;
					cout<<"\nNhap ho & ten can tim: ";
					fflush(stdin);
					getline(cin,Ten);
					for(int i=0; i<NV.size(); i++)
					{
						if(NV[i]->GetTen()== Ten){
			            	if (NV[i]->Get_KieuNV()){
			            		textcolor(11);
			               		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\tNHAN VIEN THAM NIEN";
			               		cout<<"\n";
			               		textcolor(3);
								cout<<endl<<right<<setw(35)<<"MA SO"<<setw(20)<<"HO & TEN"<<setw(15)<<"GIOI TINH "<<setw(20)<<"TUOI "<<setw(20)<<"QUE QUAN "<<setw(20)<<"HE SO LUONG "<<setw(20)<<"THAM NIEN "<<setw(20)<<"LUONG";	
			            		cout<<"\n";
							}else{
								textcolor(11);
			            		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\tNHAN VIEN THOI VU";
								cout<<"\n";
								textcolor(3);
								cout<<endl<<right<<setw(35)<<"MA SO"<<setw(20)<<"HO & TEN"<<setw(15)<<"GIOI TINH "<<setw(20)<<"TUOI "<<setw(20)<<"QUE QUAN "<<setw(20)<<"SO GIO LAM "<<setw(20)<<"DON GIA "<<setw(20)<<"LUONG";
			           			cout<<"\n";
							}
							textcolor(7);
							NV[i]->Xuat();
						}
					}
					system("pause");
				}
				break;
			case 2: 
				{	
					float Tuoi;
					cout<<"\nNhap so tuoi can tim: ";
					cin>>Tuoi;
					for(int i=0; i<NV.size(); i++)
					{					
						if(NV[i]->GetTuoi() == Tuoi){
			            	if (NV[i]->Get_KieuNV()){
			            		textcolor(11);
			               		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\tNHAN VIEN THAM NIEN";
			               		cout<<"\n";
			               		textcolor(3);
								cout<<endl<<right<<setw(35)<<"MA SO"<<setw(20)<<"HO & TEN"<<setw(15)<<"GIOI TINH "<<setw(20)<<"TUOI "<<setw(20)<<"QUE QUAN "<<setw(20)<<"HE SO LUONG "<<setw(20)<<"THAM NIEN "<<setw(20)<<"LUONG";	
			            		cout<<"\n";
							}else{
								textcolor(11);
			            		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\tNHAN VIEN THOI VU";
								cout<<"\n";
								textcolor(3);
								cout<<endl<<right<<setw(35)<<"MA SO"<<setw(20)<<"HO & TEN"<<setw(15)<<"GIOI TINH "<<setw(20)<<"TUOI "<<setw(20)<<"QUE QUAN "<<setw(20)<<"SO GIO LAM "<<setw(20)<<"DON GIA "<<setw(20)<<"LUONG";	
			           			cout<<"\n";
							}	
							textcolor(7);
							NV[i]->Xuat();
						}
					}
					system("pause");
				}
				break;
			case 3:
				{
					float Luong;
					cout<<"\nNhap so luong can tim: ";
					cin>>Luong;
					for(int i=0; i<NV.size(); i++)
					{
						if(NV[i]->TinhLuong()==Luong){
			            	if (NV[i]->Get_KieuNV()){
			            		textcolor(11);
			               		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\tNHAN VIEN THAM NIEN";
			               		cout<<"\n";
			               		textcolor(3);
								cout<<endl<<right<<setw(35)<<"MA SO"<<setw(20)<<"HO & TEN"<<setw(15)<<"GIOI TINH "<<setw(20)<<"TUOI "<<setw(20)<<"QUE QUAN "<<setw(20)<<"HE SO LUONG "<<setw(20)<<"THAM NIEN "<<setw(20)<<"LUONG";	
			            		cout<<"\n";
							}else{
								textcolor(11);
			            		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\tNHAN VIEN THOI VU";
								cout<<"\n";
								textcolor(3);
								cout<<endl<<right<<setw(35)<<"MA SO"<<setw(20)<<"HO & TEN"<<setw(15)<<"GIOI TINH "<<setw(20)<<"TUOI "<<setw(20)<<"QUE QUAN "<<setw(20)<<"SO GIO LAM "<<setw(20)<<"DON GIA "<<setw(20)<<"LUONG";
			           			cout<<"\n";
							}
							textcolor(7);
							NV[i]->Xuat();
						}
					}
					system("pause");
				}
				break;
			case 4:
				{
					string que;
					cout<<"\nNhap que quan can tim: ";
					fflush(stdin);
					getline(cin,que);
					for(int i=0; i<NV.size(); i++)
					{
						if(NV[i]->GetQue()== que){
			            	if (NV[i]->Get_KieuNV()){
			            		textcolor(11);
			               		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\tNHAN VIEN THAM NIEN";
			               		cout<<"\n";
			               		textcolor(3);
								cout<<endl<<right<<setw(35)<<"MA SO"<<setw(20)<<"HO & TEN"<<setw(15)<<"GIOI TINH "<<setw(20)<<"TUOI "<<setw(20)<<"QUE QUAN "<<setw(20)<<"HE SO LUONG "<<setw(20)<<"THAM NIEN "<<setw(20)<<"LUONG";	
			            		cout<<"\n";
							}else{
								textcolor(11);
			            		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\tNHAN VIEN THOI VU";
								cout<<"\n";
								textcolor(3);
								cout<<endl<<right<<setw(35)<<"MA SO"<<setw(20)<<"HO & TEN"<<setw(15)<<"GIOI TINH "<<setw(20)<<"TUOI "<<setw(20)<<"QUE QUAN "<<setw(20)<<"SO GIO LAM "<<setw(20)<<"DON GIA "<<setw(20)<<"LUONG";
			           			cout<<"\n";
							}
							textcolor(7);
							NV[i]->Xuat();
						}
					}
					system("pause");
				}
				break;
			default:
				break;
		}
	}while(choose != 5);
}

void QuanLyNhanVien::Xoa()
{
	int choose;
	do{
		system("cls");
		cout <<setw(80)<<"|"<<"------------------------------------------|"<<endl;
		cout <<setw(80)<<"|"<<setw(30)<<"XOA NHAN VIEN"<<setw(13)<<"|"<<endl;
		cout <<setw(80)<<"|"<<"1.Xoa nhan vien theo tuoi"<<"\t\t  |"<<endl;
		cout <<setw(80)<<"|"<<"2.Xoa nhan vien theo luong"<<"\t\t  |"<<endl;
		cout <<setw(80)<<"|"<<"3.Xoa nhan vien theo ten"<<"\t\t  |"<<endl;
		cout <<setw(80)<<"|"<<"4.Quay lai"<<setw(33)<<"|"<<endl;
		cout <<setw(80)<<"|"<<"------------------------------------------|"<<endl;
		cout <<"\n";
		cout <<setw(105)<<"Vui long nhap lua chon: ";  
		cin >> choose;
		switch(choose) 
		{
			case 1: 
				{	
					int kt=0;
					float Tuoi;
					cout<<"\nNhap so tuoi can xoa: ";
					cin>>Tuoi;
					for(int i=0; i<NV.size(); i++)
					{					
						if(NV.at(i)->GetTuoi() == Tuoi){
							NV.erase(NV.begin() + i);
							cout<<"Da xoa thanh cong !"<<endl;	
							kt=1;							
						}
					}
					if(kt==0)
						cout<<"Khong tim thay thong tin nhan vien de xoa "<<endl;
						system("pause");
				}
				break;
			case 2:
				{
					int kt=0;
					float Luong;
					cout<<"\nNhap so luong can xoa: ";
					cin>>Luong;
					for(int i=0; i<NV.size(); i++)
					{
						if(NV.at(i)->TinhLuong() == Luong){
							NV.erase(NV.begin() + i);
							cout<<"Da xoa thanh cong !"<<endl;
							kt=1;
						}
					}
					if(kt==0)
							cout<<"Khong tim thay thong tin nhan vien de xoa "<<endl;
					system("pause");
				}
				break;
			case 3:
				{
					int kt=0;
					string Ten;
					cout<<"\nNhap ten can xoa: ";
					fflush(stdin);
					getline(cin,Ten);
					for(int i=0; i<NV.size(); i++)
					{
						if(NV.at(i)->GetTen() == Ten){
							NV.erase(NV.begin() + i);
							cout<<"Da xoa thanh cong !"<<endl;	
							kt=1;						
						}			
					}
					if(kt==0)
							cout<<"Khong tim thay thong tin nhan vien de xoa "<<endl;
					system("pause");
				}
				break;
			default:
				break;
		}
	}while(choose != 4);
}

void Menu(QuanLyNhanVien qlnv)
{
	cout<<"\n";
	textcolor(9);
	cout<<right<<setw(123)<<"HE THONG QUAN LY NHAN VIEN"<<endl;
	string username,password;
	
	cout<<"\n";
	textcolor(7);
    cout<<right<<setw(120)<<"******DANG KY******"<<endl;
    cout<<"\n";
	cout<<right<<setw(110)<<"Tai Khoan: ";
	cin>>username;
	cout<<"\n";
	cout<<right<<setw(110)<<"Mat khau: ";
	cin>>password;
	cout<<right<<setw(129)<<"---------------------------------"<<endl;
	textcolor(9);
	cout<<setw(148)<<"Tai Khoan Cua Ban Dang Duoc Tao Xin Vui Long Doi Trong Giay Lat!!";
	for(int i=0;i<6;i++)
	{
		cout<<".";
		Sleep(700);
	}
	textcolor(4);
	cout<<"\n";
	cout<<right<<setw(140)<<"Xin Chuc Mung Ban Da Tao Tai Khoan Thanh Cong!!";
	Sleep(2800);
	
	start:
	system("cls");
	string usrn,pswd;
	textcolor(9);
	cout<<right<<setw(123)<<"HE THONG QUAN LY NHAN VIEN"<<endl;
	textcolor(7);
	cout<<"\n";
	cout<<right<<setw(120)<<"******DANG NHAP******"<<endl;
	cout<<"\n";
	cout<<right<<setw(110)<<"Tai Khoan: ";
	cin>>usrn;
	cout<<"\n";
	cout<<right<<setw(110)<<"Mat khau: ";
	cin>>pswd;

	if(usrn==username&&pswd==password){
		textcolor(4);
		cout<<"\n";
		cout<<right<<setw(131)<<"Chuc mung ban da dang nhap thanh cong!!";
  		Sleep(2500);
		system("cls");
		int choose;
		do
		{	
			system("cls");
			textcolor(11);
			cout << "\n\t\t\t\t\t\t\t\t\t|--------------------------------------------------------------|";
			cout << "\n\t\t\t\t\t\t\t\t\t| C-H-U-O-N-G---T-R-I-N-H---Q-U-A-N---L-Y---N-H-A-N---V-I-E-N  |";
			cout << "\n\t\t\t\t\t\t\t\t\t| <------------* Nhap so tuong ung trong menu   *------------> |";
			cout << "\n\t\t\t\t\t\t\t\t\t| 1.-----------*         Nhap nhan vien         *------------- |";
			cout << "\n\t\t\t\t\t\t\t\t\t| 2.-----------*         Xuat nhan vien         *------------- |";
			cout << "\n\t\t\t\t\t\t\t\t\t| 3.-----------*	 Sap xep nhan vien      *------------- |";
			cout << "\n\t\t\t\t\t\t\t\t\t| 4.-----------*	 Tim kiem nhan vien     *------------- |";
			cout << "\n\t\t\t\t\t\t\t\t\t| 5.-----------*	 Tong luong nhan vien   *------------- |";
			cout << "\n\t\t\t\t\t\t\t\t\t| 6.-----------*	 Xoa nhan vien	        *------------- |";     
			cout << "\n\t\t\t\t\t\t\t\t\t| 7.---------*T-H-O-A-T----C-H-U-O-N-G---T-R-I-N-H*------------|";
			cout << "\n\t\t\t\t\t\t\t\t\t|--------------------------------------------------------------|";
			cout<<"\n\t\t\t\t\t\t\t\t\tVui Long Nhap Lua Chon: ";
			cin>>choose;
			
			switch (choose)
			{
			case 1:
				qlnv.NhapDS();
				break;
			
			case 2:
				qlnv.XuatDS();
				break;
			
			case 3:
				qlnv.SapXep();
				break;
			
			case 4:
				qlnv.TimKiem();
				break;
				
			case 5:
				qlnv.TinhLuong();
				break;
				
			case 6:
				qlnv.Xoa();
				break;
				
			default:
				break;
			}
		} while (choose!=7);
	}
	
	else if(usrn!=username){
		cout<<"\n";
		textcolor(4);
		cout<<right<<setw(140)<<"Tai Khoan Khong Hop Le!!Xin Vui Long Kiem Tra Lai";
  		Sleep(2500);
  	goto start;
    }
    
   	else if(pswd!=password){
   		cout<<"\n";
   		textcolor(4);
  		cout<<right<<setw(140)<<"Mat Khau Khong Hop Le!!Xin Vui Long Kiem Tra Lai";
  		Sleep(2500);
  	goto start;
  	}
  	
  	else {
  		textcolor(4);
  		cout<<right<<setw(145)<<"Tai Khoan Mat Khau Khong Hop Le";
  		Sleep(2500);
  	goto start;
  	}
}

int main(){
    QuanLyNhanVien qlnv;
   	Menu(qlnv);
   	system("pause");
   	
}

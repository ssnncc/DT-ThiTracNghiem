#include<iostream>
using namespace std;
void NhapMang(int a[],int n)
  {
    for(int i=0;i<n;i++)
       {
	      cout<<"\nNhap phan tu thu "<<i<<":";
	      cin>>a[i];
	   }
  }
  void XuatMang(int a[],int n)
  {
    for(int i=0;i<n;i++)
       {
	      cout<<"\nPhan tu thu:"<<i<<" ";
	      cout<<a[i]<<endl;
	   }
  }
  //Tong tai vi tri tri chan
    int TongChan(int a[],int n,int S)
      {
	     S=0; 
	     for(int i=0;i<n;i++)
	       {
		     if(i%2==0)
		        {
				  S=S+a[i];
				}
		   }
		   return S;
	  }
	  //Tinh tong cac phan tu co gia tri le
  int TongLe(int a[],int n,int T)
    {
	   T=0;
	   for(int i=0;i<n;i++)
	     {
		   if(a[i]%2 !=0)
		      {
			    T=T+a[i];
			  } 
		 }
		 return T;
	}
	void SapXepTangDan(int a[],int n)
	   {
	   	for(int i=0;i<n;i++)
	   	  {
			 for(int j=i+1;j<n;j++)
			    {
				   if(a[i]>a[j])
				     {
					    int tam;
					    tam=a[i];
					    a[i]=a[j];
					    a[j]=tam;
					 }
				}
			 }
	   
	   }
	void SapXepGiamDan(int a[],int n)
	   {
	   	for(int i=0;i<n;i++)
	   	  {
			 for(int j=i+1;j<n;j++)
			    {
				   if(a[i]<a[j])
				     {
					    int tam;
					    tam=a[j];
					    a[j]=a[i];
					    a[i]=tam;
					 }
				}
			 }
	   
	   }
int Timso_max_trongmang(int a[],int n)
   {
   	int max=a[0];
   for(int i=0;i<=n;i++)
        {
		if(max<a[i])
		   {
		   max=a[i];
		  
		   
		   }
		}
      return max;
   }
    int Timso_min_trongmang(int a[],int n)
   {
   	int min=a[0];
   for(int i=0;i<=n;i++)
        {
		if(min>a[i])
		   {
		   min=a[i];
		  
		   
		   }
		}
      return min;
   }
/* void ViTriCucTieu(int a[],int n)
   {
   //	int tam=a[0];
   	for(int i=0;i<n-2;i++)
   	   {
		  for(int j=i+2;j<n;j++)
		    {
			  if(a[i+1]>a[i]&&a[i+1]<a[j])
			    {
				 cout<<a[i+1];
				}
			}
	  }
   
   }*/
void Menu(int a[],int n,int S,int T)
	     {
	int luachon;
	while (true)
	{
		system("cls");// xóa di h?t nh?ng trên màn hình tru?c do 
		// thi?t k? menu cho chuong trình
		cout << "\n\t\t============ MENU ============\n";
		cout << "\n1. Nhap mang";
		cout << "\n2. Xuat mang";
		cout << "\n3. Tong tai vi tri chan";
		cout << "\n4. Tong cac so le";
		cout << "\n5. Sap xep tang dan";
		cout << "\n6. Sap xep giam dan";
		cout << "\n7. Tim max";
		cout << "\n8. Tim mim";
		cout << "\n8. Cuc Tieu";
		cout << "\n0. Ket thuc";
		cout << "\n\t\t============ END ============\n";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if(luachon < 0 || luachon > 10)
		{
			cout << "\nLua chon khong hop le. Xin kiem tra lai";
			system("pause");
		}
		
		else if(luachon == 1)
		{
			cout << "\nNhap so luong phan tu mang: ";
			cin >> n;
			cout << "\n\n\t\t NHAP MANG\n";
			NhapMang(a, n);
		}
		else if (luachon == 2)
		{
			cout << "\n\n\t\t XUAT MANG\n";
			XuatMang(a, n);
			system("pause");
		}
		else if (luachon == 3)
		{
			cout<<"Tong tai vi tri chan:"<<TongChan(a,n,S)<<endl;
			system("pause");
		}
		else if (luachon == 4)
		{
			cout<<"Tong cac so le:"<<TongLe(a,n,T)<<endl;
			system("pause");
		}
		else if (luachon == 5)
		{
	             SapXepTangDan(a,n);
		}
		else if (luachon == 6)
		{
	            SapXepGiamDan(a,n);
		}
			else if (luachon == 7)
		{
			
			cout<<"Max:"<<Timso_max_trongmang(a,n);
		}
			else if (luachon == 8)
		{
			
			cout<<"Min:"<<Timso_min_trongmang(a,n);
		}
			else if (luachon == 9)
		{
			
		//	cout<<" Cuc tieu:";
	      //   ViTriCucTieu(a,n);
		}
		
		else
		{
			break; // thoát kh?i vòng l?p vô t?n
		}
	}

	delete[] a;
	system("pause");
		 }
	int main()
	{
	   int S,T,n;
	   int a[50];
	   Menu(a,n,S,T);
	   
	   return 0;
	}

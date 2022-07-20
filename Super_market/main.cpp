#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
using namespace std;


class products
{
    private:
    int PNo;
    string PName;
    float PPrice,PQty;
    public:
        void Creat_product()
        {
             cout<<"Enter the product number   : \n ";cin>>PNo;
             cout<<"Enter the product Name     : \n ";cin>>PName;
             cout<<"Enter the product Price    : \n ";cin>>PPrice;
             cout<<"Enter the product Quantity : \n ";cin>>PQty;
        }
        void Show_Info()
        {
            cout<<"\nThe product Number Is   :  \t"<<PNo;
            cout<<"\nThe product Name Is     :  \t"<<PName;
            cout<<"\nThe product Price Is    :  \t"<<PPrice;
            cout<<"\nThe product Quantity Is :  \t"<<PQty;

        }
        int Pnum()
        {return PNo;}

        string Pname()
        {return PName;}

        float Pprice()
        {return PPrice;}

} ;
products pro;
fstream fp;

void Write_priducts()
{
    fp.open("Shop.txt",ios::out|ios::app);
    pro.Creat_product();
    fp.write((char*)&pro ,sizeof(products));
    fp.close();
    cout<<"\n\n The Product Has Created ";
    getch();
}
void Display_Products()
{
    system("cls");
    cout<<"All The Products Information : \n\n ";
    fp.open("Shop.txt",ios::in);
    while(fp.read((char*)&pro,sizeof(products)))
    {
        pro.Show_Info();
        cout<<"\n\n #############################################\n ";
       getch();
    }
    fp.close();
getch();
}


void Search_Products(int num)
{
    int flag =0;
    fp.open("Shop.txt",ios::in);
   while(fp.read((char*)&pro,sizeof(products)))
   {
       if(pro.Pnum()==num)
        {
            pro.Show_Info();
            flag=1;
        }
   }
   fp.close();
  if (flag==0)
  {
      cout<<"\nThis Product is not exist \n ";
      getch();
  }
}
void Delete_Products()
{
    int num ;
    cout<<"\n\n Please enter the product want to Delete : ";
    cin>>num;
    fp.open("Shop.txt",ios::in|ios::out);
    fstream fp2;
    fp2.open("Replace.txt",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&pro,sizeof(products)))
   {
       if(pro.Pnum()!=num)
        {
        fp2.write((char*)&pro,sizeof(products));
        }
        fp2.close();
        fp.close();
        remove("Shop.txt");
        cout<<"\n\n The product Deleted " ;
        getch();
}
}

int main()
 {


 char ch;
 do {
    cout<<"\n\n\n  Main Menu";
    cout<<"\n\n\t1.CREATE PRODUCTS";
    cout<<"\n\n\t2.DISPLAY ALL PRODUCTS";
    cout<<"\n\n\t3.SEARCH ";
    cout<<"\n\n\t4.DELETE PRODUCT";
    cout<<"\n\n\t5.VIEW PRODUCT ";
    cout<<"\n\n\t6.EXIT";
    cout<<"\n\n\tPLEASE ENTER YOUR CHOICE (1-6)\n";
    ch=getch();
    switch(ch)
    {


case '1':
    Write_priducts();
    break;
case '2':
    Display_Products();
    break;
case '3':
    int Num;
    cout<<"Enter the Number to search: \t";
    cin>>Num;
    Search_Products(Num);
    break;
case '4':
    Delete_Products();
    break;
case '5':
    Display_Products();
    break;


case '6':
   cout<<"***************Thank you for using this";
default:
    cout<<"Error";

 }
 }while(ch!=6);

 }

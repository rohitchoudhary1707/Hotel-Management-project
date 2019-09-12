#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<iomanip.h>
class hotel
	 {
	 int roomno;
	 char name[20];
	 float amount;
	 char phoneno[12];
	 char address[40];
	 public:
	 void gethotel()
		   {
		   gotoxy(20,2);
		   cout<<"*--Software For Hotel Data Management--*";
		   gotoxy(20,3);
		   cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		   gotoxy(28,5);
		   cout<<"<--Add A Record*-->";
		   gotoxy(20,7);
		   cout<<"Enter room no of customer ->";
		   gotoxy(60,7);
		   cin>>roomno;
		   gotoxy(20,9);
		   cout<<"Enter name of customer ->";
		   gotoxy(60,9);
		   gets(name);
		   gotoxy(20,11);
		   cout<<"Enter amount to be paid by customer ->";
		   gotoxy(60,11);
		   cin>>amount;
		   gotoxy(20,13);
		   cout<<"Enter address of customer ->";
		   gotoxy(60,13);
		   gets(address);
		   gotoxy(20,15);
		   cout<<"Enter phone no of customer ->";
		   gotoxy(60,15);
		   gets(phoneno);
		   }
		   void showhotel()
		   {
		   cout<<endl<<roomno <<setw(20)<<name<<setw(15)<<amount<<setw(10)<<phoneno<<setw(25)<<address;
		   }
		   void displayhotel()
		   {
		   gotoxy(20,2);
		   cout<<"##Sofware For Electricity Bill Management##";
		   gotoxy(20,4);
		   cout<<"********************************************";
		   gotoxy(28,5);
		   cout<<"-*-Record of customer-*-";
		   gotoxy(28,7);
		   cout<<"Room no of customer :"<<roomno;
		   gotoxy(20,9);
		   cout<<"Name of customer :"<<name;
		   gotoxy(20,11);
		   cout<<"Amount to be paid by the customer :"<<amount;
		   gotoxy(20,13);
		   cout<<"Phone no of customer:"<<phoneno;
		   gotoxy(20,15);
		   cout<<"Address of customer  :"<<address;
		   }
		  int rroomno()
			  {
			  return roomno;
			  }
		  };
void main()
	  {
	  fstream f,f1;
	  int r,n;

	  int choice;
	  textcolor(YELLOW);
	  textbackground(MAGENTA);
	  clrscr();
	  gotoxy(20,3);
	  cout<<"*--Software For Hotel Management--*";
	  gotoxy(20,2);
	  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	  gotoxy(20,4);
	  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	  gotoxy(28,6);
	  cout<<"<---*Main menu*--->";
	  gotoxy(28,8);
	  cout<<"1> Add a Record";
	  gotoxy(28,10);
	  cout<<"2> Modify a record";
	  gotoxy(28,12);
	  cout<<"3> Delete a all Record";
	  gotoxy(28,14);
	  cout<<"4> Search a Record";
	  gotoxy(28,16);
	  cout<<"5> view a Record";
	  gotoxy(28,18);
	  cout<<"6> Quit";
	  gotoxy(20,20);
	  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	  gotoxy(20,22);
	  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	  gotoxy(54,24);
	  cout<<"Developed By:->";
	  gotoxy(54,25);
	  cout<<"*Rohit*";
	  gotoxy(26,21);
	  cout<<"Enter your choice please:-";
	  cin>>(choice);
	  switch(choice)
{
	   case 1:
	   clrscr();
	   f.open("hotel.dat",ios::app|ios::binary);
	   hotel obj;
	   obj.gethotel();
	   f.write((char*)&obj,sizeof (obj));
	   f.close();
	   break;
	   case 2:
	   clrscr();
	   char ch;
	   f.open ("hotel.dat",ios::in|ios::binary);
	   f1.open("temp.dat",ios::app|ios::binary);
	   gotoxy(10,12);
	   cout<<"Enter roomno of customer whose record you want to modify:-";
	   cin>>r;
	   f.read((char*)&obj,sizeof(obj));
	   do
	    {
	    n=obj.rroomno();
	    if(n==r)
	      {
	      clrscr();
	      obj.displayhotel();
	      gotoxy(20,20);
	      cout<<"Do you want to modify this record(y/n):";
	      fflush(stdin);
	      cin>>ch;
			  if(ch=='y'||ch=='y')
			      {
			      clrscr();
			      obj.gethotel();
			      f1.write((char*)&obj,sizeof(obj));
			      }
			 else
			      {
			      f1.write((char*)&obj,sizeof(obj));
			      }
		  }
		else
		      {
		      f1.write((char*)&obj,sizeof(obj));
		      }
		      f.read((char*)&obj,sizeof(obj));
		      }while(f);
		    f.close();
		    f1.close();
		    remove("hotel.data");
		    rename("temp.dat","hotel.dat");
		    gotoxy(20,24);
			     break;
		    case 3:
		    clrscr();
		    f.open("hotel.dat",ios::in|ios::binary);
		    f.open("temp.dat",ios::out|ios::binary);
		    gotoxy(10,12);
		    cout<<"enter roomno of customer whose record you want to delete:-";
		    cin>>r;
		    f.read((char*)&obj,sizeof(obj));
		    do
		      {
		      n=obj.rroomno();
		      if(n==r)
			{
			clrscr();
			obj.displayhotel();
			gotoxy(20,20);
			cout<<"\n Do you want to delete this record(y/n)";
			fflush(stdin);
			cin>>ch;
			       if(ch=='y' ||ch=='y')
				       {
				       }
				else
				       {
				       f1.write((char *)&obj,sizeof(obj));
				       }
			  }
			  else
			  {
			  f1.write((char *)&obj,sizeof(obj));
			  }
			 f.read((char*)&obj,sizeof(obj));
			 }while(f);
			f.close();
			f1.close();
			remove("hotel.dat");
			rename("temp.dat","hotel.dat");
			gotoxy(20,24);
			cout<<"press any key to continue...";
			getch();
			break;
		 case 4:
			  clrscr();
			  f.open("hotel.dat",ios::in|ios::binary);
			  gotoxy(10,12);
			  cout<<"Enter roomno of hotel whose record you want to search:-";
			  cin>>r;
			  f.read((char*)&obj,sizeof(obj));
			  do
			    {
			    n=obj.rroomno();
			    if(n==r)
			      {
			      clrscr();
			      obj.displayhotel();
			      gotoxy(20,20);
			      cout<<"press any key to continue...!";
			      getch();
			      }
			   f.read((char*)&obj,sizeof(obj));
			   }while(f);
			   getch();
			   break;
			   case 5:
			   clrscr();
			   gotoxy(20,2);
			   cout<<"<--*Record of student*-->";
			   cout<<endl<<"room no"<<setw(15)<<"Name"<<setw(15)<<"Amount"<<setw(15)<<"Phone no"<<setw(18)<<"address";
			   cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			   f.open( "hotel.dat",ios::in|ios::binary);
			   f.read((char*)&obj,sizeof(obj));
			   do
			    {
			    obj.showhotel();
			    f.read((char*)&obj,sizeof(obj));
			    }while(f);
			  f.close();
			  gotoxy(20,24);
			  cout<<"pressany key to conytinue....";
			  getch();
			  break;
			  case 6:exit(0);
			  default:
			  gotoxy(28,21);
			  cout<<"wrong choice..........!!";
			  getch();
			  break;
			  }
		 main();
		 }











//Computer Project
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
fstream f;
class movies
{
  int movieno;
  char movie[50];
  char type[2];
  char time[10];
  char date[10];
  int rate;
  int av;
  public:
  int amt;
  int seat;
  int stype;
  char s;
  void read()
  {
   cout<<"\n\tEnter movie code:";
   cin>>movieno;
   cout<<"\tEnter movie name:";
   gets(movie);
   cout<<"\tEnter timing:";
   gets(time);
   cout<<"\tEnter release date:";
   gets(date);
   cout<<"\tEnter rating(on 10):";
   cin>>rate;
   cout<<"\tEnter no:of seats available:";
   cin>>av;
  }
  void output1()
  {
   cout<<endl;
   cout<< "CODE\tNAME\tRELEASE DATE\tTIMING\tRATING(on 10)\tAVAILABLE SEATS\n";
  }
  void output2()
  {
   cout<<movieno<<"\t"<<movie<<"\t"<<date<<"\t"<<time<<"\t"<<rate<<"\t\t"<<av<<"\n";
  }
  int ret_movieno()
  {
   return movieno;
  }
  void calcul()
  {
   clrscr();
   cout<<"\n\t\tChoose class of seat";
   cout<<"\n\n\t1.GOLDEN-Rs.200";
   cout<<"\n\t2.SILVER-Rs.150";
   cout<<"\n\t3.BRONZE-Rs.100";
   cout<<"\n\n\tEnter your prefered type:";
   cin>>stype;
   cout<<"\n\n\tEnter confirmed no.of seats:";
   cin>>seat;
   if(stype==1)
   amt=seat*200;
   else if(stype==2)
   amt=seat*150;
   else if(stype==3)
   amt=seat*100;
   cout<<"\n\tYour amount for booking "<<seat<<" seats:"<<"Rs."<<amt;
   cout<<"\n\tDo u wish to continue to the transaction page?";
   cin>>s;
  }
  int check()
  {
   int n,n1,h=0;
   f.open("movies.dat",ios::in|ios::binary);
   cout<<"\n\nEnter movie code for booking:";
   cin>>n;
   cout<<"Enter no:of seats required:";
   cin>>n1;
   while(f.read((char*)&m,sizeof(m)))
   {
    if(ret_movieno()==n)
    if((av-n1)>=0)
    h=1;
   }
   return h;
  }
}m;
void display()
{
 clrscr();
 int c=0;
 f.open("movies.dat",ios::in|ios::binary);
 cout<<"Displaying list of movies:";
 while(f.read((char*)&m,sizeof(m)))
 {
  cout<<"\n\n";
  c++;
  cout<<"Movie No:"<<c;
  m.output1();
  m.output2();
 }
 f.close();
}
void del()
{
  int n;
  fstream f1,f2;
  f1.open("movies.dat",ios::in|ios::binary);
  f2.open("temp.dat",ios::out|ios::binary);
  cout<<"\nEnter movie code to be deleted:";
  cin>>n;
  while(f1.read((char*)&m,sizeof(m)))
  {
   if(m.ret_movieno()!=n)
   f2.write((char*)&m,sizeof(m));
  }
  f1.close();
  f2.close();
  remove("movies.dat");
  rename("temp.dat","movies.dat");
}
void app()
{
  clrscr();
  cout<<"Enter details of movie to be appended:\n";
  f.open("movies.dat",ios::app|ios::binary);
  m.read();
  f.write((char*)&m,sizeof(m));
  f.close();
}
void edit()
{
  clrscr();
  cout<<"Enter movie code to be edited:";
  int pos,n;
  cin>>n;
  f.open("movies.dat",ios::in|ios::out|ios::binary);
  while(f.read((char*)&m,sizeof(m)))
  {
   if(m.ret_movieno()==n)
    {
     pos=f.tellg();
     m.read();
     f.seekp(pos-sizeof(m));
     f.write((char*)&m,sizeof(m));
    }
  }
  f.close();
}
void atm()
{
  clrscr();
  int a,b,c;
  cout<<"\n\t\tTransaction Page";
  cout<<"\n\n\tEnter your bank card no:";
  cin>>a;
  cout<<"\n\tEnter CVV:";
  cin>>b;
  cout<<"\n\tEnter OTP sent to your mobile no:";
  cin>>c;
  cout<<"\n\tYour transation has been successful.";
  cout<<"\n\tPlease collect your tickets at the theatre kiosk.";
  cout<<"\n\nThank u for booking with us.PLEASE VISIT AGAIN!!";
}
void main()
{
 int x,p,z,c1,r;
 char a,b,c,d;
 clrscr();
 cout<<"\n\n\t\t\t\t *WELCOME*";
 cout<<"\n\n\t\t\t  MOVIE TICKET BOOKING";
 cout<<"\n\n\n\t\t\tMENU";
 cout<<"\n\n\t\t1.Enter booking";
 cout<<"\n\t\t2.Exit program";
 cout<<"\n\n\t\tEnter your choice:";
 cin>>c1;
 if(c1==1)
 {
  do
  {
   clrscr();
   cout<<"\n\n\t\t\t\tMAIN MENU";
   cout<<"\n\n\t\t1.Administrator \n\t\t2.User\n";
   cout<<"\n\n\t\tEnter mode:";
   cin>>x;
   if(x==1)
   {
    do
    {
    clrscr();
    cout<<"\tYou have logged in as administrator\n";
    cout<<"\n\t\t\tMENU\n\n";
    cout<<"\t\t1)Input movies\n";
    cout<<"\t\t2)Delete a movie\n";
    cout<<"\t\t3)Append a movie\n";
    cout<<"\t\t4)Edit a movie\n";
    cout<<"\t\t5)Display all movies";
    cout<<"\n\n\t\tEnter your choice:";
    cin>>z;
    if(z==1)
    {
     clrscr();
     cout<<"\nEnter number of movies to input:";
     cin>>p;
     f.open("movies.dat",ios::out|ios::binary);
     for(int i=0;i<p;++i)
     {
      m.read();
      f.write((char*)&m,sizeof(m));
     }
     f.close();
     display();
    }
   else if(z==2)
   {
    display();
    del();
   }
   else if(z==3)
   app();
   else if(z==4)
   edit();
   else if(z==5)
   display();
   cout<<"\nDo you want to return to main menu?";
   cin>>a;
   }while(a=='y');
  }
  else if(x==2)
  {
   display();
   r=m.check();
   if(r==1)
   {
   clrscr();
   cout<<"\n\tYour selected movie is available.";
   cout<<"\n\tDo u want to proceed to booking?";
   cin>>d;
   if(d=='y')
   {
   m.calcul();
   atm();
   }
   }
   else cout<<"Sorry.Your selected movie is unavailable due to lack of seats.";
  }
  else cout<<"\n\t\tEnter a valid choice!!";
  cout<<"\nDo you want to change user?";
  cin>>b;
 }while(b=='y');
}
else if(c1!=2)
cout<<"\n\t\tEnter a valid choice!!";
getch();
}

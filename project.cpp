#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
string usernames[100];
string passwords[100];
void adminMenu();
void adminOption(int option);
void lib_Member();
int usercount=0;
int bookcount=0;
string book[30];
string bookAuthor[30];
void addbooktofile(string bookname, string author);
void signUp(string username,string password, string role);
bool signIn(string username,string password, string role);
void viewusers();
void storefile();
void addbookstoarray(string bookname, string author);
bool isvalidusername(string username);
void loaddatafromfile();
bool isPresent(string book_name);
bool isDelete(string member_name);
int option =0;
void addbook();
void updateBooks();
void returnbook();
string member[100];
void deletebook();
void searchbook();
void viewbook();
void addmember();
bool check(string bookname);
void deletemember();
void viewmember();
void searchmember();
int menu();
int authorcounter=4;
void issuebook();
void libraryoption(int option);     
void payfine(); 
string getfield(string record, int field);
string rolle[100];
void maze();
void loaddataofbooksfromfile();
void storedataofbooks();
string role;
void storedataofmembers();
void loaddataofmemberfromfile();
main()
{ 
    loaddatafromfile(); 
   loaddataofbooksfromfile();
   loaddataofmemberfromfile(); 
    string username;
    string password;  
    int choice=3;
    bool decision;
 maze();
    while(choice!=0)
    { 
        choice =menu();
        if (choice ==1)
        { 
            cout << "enter username"<< endl;
            cin >> username;
            cout << "enter password "<< endl;
            cin >> password;
            cout <<"enter role" << endl;
            cin >> role;
            decision=isvalidusername( username);
            if(decision == true)
            {
                signUp( username, password,role);
                cout << "user created successfully"<< endl;
            }
            else
            {
                cout << "username already exit"<< endl;
            }
            }
            else if (choice==2)
            {  
                
                cout << "enter username"<< endl;
            cin >> username;
            cout << "enter password "<< endl;
            cin >> password;
                decision=signIn( username, password, role);
                if (decision =true)
                {
                     if(rolle[usercount]== "admin")
                   {
                    adminMenu();
                   }
                   else if(rolle[usercount]=="librarian")
                   {
                   lib_Member();
                   }
                   cout << "login successfully"<< endl;
                }
                else 
                {
                    cout << "invalid credentials ";
                }
            }
            else if(choice ==3)
            {
                viewusers();
            }
            else
        {
            cout << "invalid choice";

        }
    } 
}
void signUp(string username,string password,string role)
{ 
    usernames[usercount] = username;
    passwords[usercount]= password;
    rolle[usercount] = role;
    usercount ++;
     storefile();
}
void storefile()
{
    fstream file;
    file.open("users.txt",ios::out);
    for(int i=0; i<usercount; i++)
    {
        file<< usernames[i] << "," << passwords[i]<< endl;
    }
    file.close();
}

void viewusers()
{  
    cout << "usernames"<< "\t\t" << "passwords" <<endl;
      for(int index=0; index<usercount; index++)
      {
        cout << usernames[index] << "\t\t" << passwords[index]<< endl;
      }
}
bool signIn(string username,string password, string role)
{ 
    bool isfound =false;
    for (int index;index < usercount ;index++)
    {
        if (usernames[index]== username && passwords[index]==password && rolle[index]== role)
        {
            isfound =true;
            break;
        }
    }
    return isfound;
}
bool isvalidusername(string username)
{     
    bool isfound =true;
    for (int index=0;index <usercount ;index++)
    {
        if (usernames[index]==username)
        {
            isfound=false;
            break;
        }
    }
    return isfound;
}
int menu()
{
       int option;
      cout << "1.signUp"<< endl;
      cout << "2.signIn"<< endl;
      cout <<"3.view all users" << endl;
      cout << "0.exit"<< endl;
      cout << "enter your option";
      cin >> option;
      return option;
}
void loaddatafromfile()
{
    fstream file;
   string record;
    file.open("users.txt",ios::in);
    while(!file.eof())
    {
    getline(file,record);
    {
     usernames[usercount]=getfield(record,1);
     passwords[usercount]=getfield(record,2);
     rolle[usercount]=getfield(record,3);
    usercount++;
    }
}
    file.close();
}
string getfield(string record, int field)
{
    int commacount =1;
    string item;
    for(int x=0; x< record.length(); x++)
    {
        if(record[x]== ',')
        {
            commacount = commacount+1;
        }
        else if(commacount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}
void adminMenu()
{
    int option;
system("CLS");
cout << "*******************"<< endl;
cout << "1.ADD BOOK" << endl;
cout << "2.UPDATE BOOK" << endl;
cout << "3.DELETE BOOK" << endl;
cout << "4.SEARCH BOOK" << endl;
cout << "5.VIEW BOOK" << endl;
cout << "6.ADD MEMBER" << endl;
cout << "7.DELETE MEMBER" << endl;
cout << "8.VIEW MEMBER" << endl;
cout << "9.SEARCH MEMBER" << endl;
cout << "10.Exit" << endl;
cout << "*******************"<< endl;
cout << "ENTER YOUR DESIRED CHOICE:";
cin >> option;

adminOption(option);
}
void adminOption(int option)
{
while(option!=10)
{
if(option == 1)
{
addbook();
}
 if(option ==2)
{
updateBooks();
}
 if(option ==3)
{
deletebook();
}  
 if(option ==4)
{
searchbook();
}
 if(option ==5)
{
viewbook();
}
 if(option ==6)
{
addmember();
}
 if(option == 7)
{
deletemember();
}
 if(option ==8)
{
viewmember();
}
 if(option ==9)
{
searchmember();
}
adminMenu();
}
}
void addbook()    
{ 
cout <<"enter name of books:";
cin>>book[bookcount];
cout << "enter author of the books" ;
cin.ignore();
 getline(cin,bookAuthor[bookcount]);
bookcount++;
storedataofbooks();
getch();
 }
void viewbook()
{
    cout << "BOOK NAME"<< "\t\t" << "BOOK AUTHOR" << "\t\t" << endl;
    for(int index=0; index<bookcount; index++)
    {
        cout << book[index] <<"\t\t" << bookAuthor[index];
    }
    getch();
}
void updateBooks()
{
    string author;
    string bookName;
 cout << "Enter book name to update:";
 cin.ignore();
 getline(cin,bookName);
//  cout << "Enter author name:";
//  cin >> author;

 for(int i=0; i<bookcount; i++)
 {
 if(bookName == book[i])
 {
 string bookie;
 cout << "enter new name";
 getline(cin,bookie);
 book[i]= bookie; 
 storedataofbooks();
 }
 }
} 
void searchbook()
{
string bookname;
        
cout << "enter book name to search:";
  cin.ignore();     
getline(cin,bookname);
    
for(int i=0; i<bookcount; i++)
{
        if(book[i] == bookname)
        
{
            cout << bookname;
    }
}
getch();
}
void addmember()
{
   
    cout <<"Enter name";
    getline(cin,member[usercount]);
    usercount++;
    cout <<"ADD MEMBER SUCCESSFULLY";
    getch();
}
bool isPresent(string book_name)
 {
    bool flag=false; 
    for(int index=0 ; index<bookcount ; index++)
    {
        if(book[index]==book_name)
        {
            flag=true;
        }
    }
    return flag;
    storedataofmembers();
 }
void deletebook()
{
        string bookname;
       bool check;
        cout << "enter book name to delete:";
        getline(cin,bookname);
        check=isPresent(bookname);
        if(check==true)
        {
for(int index=0;index<bookcount;index++)
{
  if(book[index]==bookname)
  {
    book[index]=book[index+1];
    book[index+1]=" ";
    storedataofbooks();
    cout << "Succesfully deleted" << endl;
  }
}
        }
        getch();
}
bool isDelete(string member_name)
 {
    bool flag=false; 
    for(int index=0 ; index<usercount ; index++)
    {
        if(member[index]==member_name)
        {
            flag=true;
        }
    }
    return flag;
 }
void deletemember()
{
        string membername;
        bool check;
        cout << "enter member name to delete:";
        getline(cin,membername);
        check=isDelete(membername);
        if(check==true)
        {
for(int index=0 ;  index<usercount ;index++)
{
  if(member[index]==membername)
  {
    member[index]=member[index+1];
    member[index+1]=" ";
    cout << "Succesfully deleted" << endl;
  }
}
storedataofmembers();
        }
        getch();
}
void searchmember()
{
string membername;
        
cout << "enter member name to search:";
       
getline(cin,membername);
    
for(int i=0; i<usercount; i++)
{
        if(member[i] == membername)
        
{
            cout << membername;
    }
}
getch();
}
void viewmember()
{
    cout << "MEMBER NAME"<< "\t\t" << endl;
    for(int index=0; index<usercount; index++)
    {
        cout << member[index];
    }
    getch();
}
void lib_Member()
{
    int option;
    system("cls");
cout << "*******************"<< endl;
cout << "1.SEARCH BOOK" << endl;
cout << "2.VIEW BOOK" << endl;
cout << "3.issue book" << endl;
cout << "4.Return book" << endl;
cout << "5.Pay fine" << endl;
cout << "6.Exit" << endl;
cout << "*******************"<< endl;
cout << "ENTER YOUR DESIRED CHOICE:";
cin >> option;
libraryoption(option);
}
void libraryoption(int option)
{
while(option!=6)
{
if(option==1)
{
    searchbook();
}
if(option==2)
{
    viewbook();
}
if(option==3)
{
    issuebook();
}
if(option==4)
{
    returnbook();
}
if(option==5)
{
    payfine();
}
lib_Member();
}

getch();
}
  

void issuebook()
{
        string bookname;
        bool check;
        cout << "enter book name to issue:";
        getline(cin,bookname);
        check=isPresent(bookname);
        if(check==true)
        {
for(int index=0;index<bookcount;index++)
{
  if(book[index]==bookname)
  {
    book[index]=book[index-1];
    bookAuthor[index]=bookAuthor[index-1];
    cout << "Succesfully ISSUED PLEASE return it on time!!" << endl;
  }
}
        }
        getch();
}
bool check(string bookname)
{
    bool check = true;
    for(int i=0; i<bookcount; i++)
    {
if(book[i]== bookname)
{
    check = false;
}
    }
    return check;
}
void returnbook()
{
        string bookname;
        bool result;
        int index=0;
        string author;
        cout << "enter book name to return:";
        getline(cin,bookname);
        cout <<"Enter author name:";
        getline(cin,author);
        result=check(bookname);
        if(result==true)
        {
     book[bookcount]= bookname;
     bookcount++;
     bookAuthor[authorcounter]= author;
     authorcounter++;
     cout << "Succesfully return on time!!" << endl;        
  }
  else if(result==false)
  {
    cout << "NO RETURN";
  }
  getch();
}
void payfine()
{
    int numberofbooks;
    int fine;
    int day;
     cout<<"Book deposited in no. of days:";
     cin >>day;
     cout << "Enter number of books:";
     cin >>numberofbooks;
                if(day>15)
                {
                   fine=(day-15)*numberofbooks;
                   cout<<"Fine has to deposited Rs. "<<fine;
                }
                if(day>30)
                {
                    cout << "Sorry to Inform that membership is lost!";
                }
                getch();
}
void maze()
{
    cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
    cout <<" &                                                                 &" << endl;
    cout <<" &                                                                 &" << endl;
    cout <<" &              LIBRARY MANAGEMENT SYSTEM                          &" << endl;
    cout <<" &                                                                 &" << endl;
    cout <<" &    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^    &" << endl;
    cout <<" &                                                                 &" << endl;
    cout <<" &    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^    &" << endl;
    cout <<" &                                                                 &" << endl;
    cout <<" &                                                                 &" << endl;
    cout <<" &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
}
void storedataofbooks()
{
    fstream file;
    file.open("book.txt",ios::out);
    for(int i=0; i<bookcount; i++)
    {
        file<< book[i] << "," << bookAuthor[i]<< endl;
    }
    file.close();
}
void loaddataofbooksfromfile()
{
    string record;
    fstream file;
   
    file.open("book.txt",ios::in);
    while(!file.eof())
    {
    getline(file,record);

     book[bookcount]=getfield(record,1);
     bookAuthor[bookcount]=getfield(record,2);
      bookcount++;
    }
    file.close();

}

void loaddataofmemberfromfile()
{
    string record;
    fstream file;
   
    file.open("member.txt",ios::in);
    while(!file.eof())
    {
    getline(file,record);
     member[usercount]=getfield(record,1);
      usercount++;
}
file.close();
}
void storedataofmembers()
{
    fstream file;
    file.open("member.txt",ios::out);
    for(int i=0; i<usercount; i++)
    {
        file<< member[i]<< endl;
    }
    file.close();
}
#include<iostream>
#include<fstream>
using namespace std;

class temp{
 string id,name,author,search;
 fstream file;
 public:
    void addBook();
    void displayBooks();
    void searchBook();
    
}obj;



int main(){


char choice;
    cout<<"------------------------------------------"<<endl;
    cout<<"|     Welcome to the Library Management    |"<<endl;
    cout<<"|              System                    |"<<endl;       
    cout<<"------------------------------------------"<<endl;

cout<<"--------------------------------------------"<<endl;
cout<<"|     Please select an option:             |"<<endl;
cout<<"|     1. Add a book                        |"<<endl;
cout<<"|     2. Display all books                 |"<<endl;
cout<<"|     3. Search for a book                 |"<<endl;
cout<<"|     4. Exit                             |"<<endl;
cout<<"--------------------------------------------"<<endl;

cout<<"Enter your choice :"<<endl;
cin>>choice;


switch(choice){
    case '1':
cin.ignore();
obj.addBook();
    break;

        case '2':
cin.ignore();
obj.displayBooks();
    break;

        case '3':
    cin.ignore();
    obj.searchBook();
    break;

        case '4':
return 0;

    break;
    default:
    cout<<"Invalid choice.please try again."<<endl;
}

    return 0;
}

void temp :: addBook(){
 cout<<"Enter book id :"<<endl;
 getline(cin,id);
 cout<<"Enter boook name :"<<endl;
 getline(cin,name);
 cout<<"Enter book's author :"<<endl;
 getline(cin,author);

 file.open("bookData.txt",ios::out | ios::app);
 file<<id<<"*"<<name<<"*"<<author<<endl;
 file.close();
}


void temp :: displayBooks(){
    file.open ("bookData.txt",ios :: in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');

        cout<<"\n\n";
        cout<<"\t\t Book Id \t\t\t Book Name \t\t\t Author's  Name"<<endl;
while(!file.eof()){
    cout<<"\t\t "<<id<<"\t\t\t "<<name<<"\t\t\t "<<author<<endl;

    getline(file,id,'*');
    getline(file,name,'*');     
    getline(file,author,'\n');
}
file.close();  
}

void temp :: searchBook(){

    displayBooks();
    cout<<"Enter book Id :: ";
    getline(cin,search);

    file.open("bookData.txt",ios::in);
    getline(file,id,'*');
    getline(file,name,'*');     
    getline(file,author,'\n');

     cout<<"\n\n";
        cout<<"\t\t Book Id \t\t\t Book Name \t\t\t Author's  Name"<<endl;
while(!file.eof()){
    if(search == id){
         cout<<"\t\t Book Id \t\t\t Book Name \t\t\t Author's  Name"<<endl;
         cout<<"Book Searched Successfully...!";
    }

  getline(file,id,'*');
    getline(file,name,'*');     
    getline(file,author,'\n');
}
file.close();
}





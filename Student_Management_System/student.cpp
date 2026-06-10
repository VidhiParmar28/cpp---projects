#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string rollNum,name,address,search;
    fstream file;

    public:
    void addStu();
    void viewStu();
    void searchStu();

}obj;



int main(){

char choice;

    cout<<"--------------------"<<endl;
    cout<<"1.Add Student Record."<<endl;
    cout<<"2.View All Student Records."<<endl;
    cout<<"3.Search Student Record."<<endl;
    cout<<"4.Exit."<<endl;

    cout<<"Enter a choice."<<endl;
    cin>>choice;

    switch(choice){
        case '1':
cin.ignore();
obj.addStu();
        break;

        case '2':
        cin.ignore();
        obj.viewStu();
        break;

        case '3':
        cin.ignore();
obj.searchStu();
        break;

        case '4':
        cin.ignore();
return 0;
        break;

        default:
        cout<<"Invalid choice ...!";
    }

    return 0;
}


void temp :: addStu(){
    cout<<"Enter Student Roll Number  :";
    getline(cin,rollNum);
    cout<<"Enter Student Name :";
    getline(cin,name);
    cout<<"Enter Student Address :";
    getline(cin,address);

    file.open("stuData.txt",ios :: out | ios :: app);
   file<<rollNum<<"*";
   file<<name<<"*";
   file<<address<<endl; 
   file.close();
    
}

void temp :: viewStu(){
    file.open("stuData.txt",ios :: in);
    getline(file,rollNum,'*');
    getline(file,name,'*');
    getline(file,address,'*');

    while(!file.eof()){
        cout<<"\n";
        cout<<"Student Roll Num :"<<rollNum;
        cout<<"Student Name :"<<name;
        cout<<"Student Address :"<<address<<endl;

        getline(file,rollNum,'*');
        getline(file,name,'*');
        getline(file,address,'\n');
    }

    file.close();
}

void temp :: searchStu(){
    cout<<"Enter Student Roll Number :";
    getline(cin,search);

    file.open("stuData.txt",ios :: in);
    getline(file,rollNum,'*');
    getline(file,name,'*');
    getline(file,address,'\n');

    while(!file.eof()){
        if(rollNum == search){
            cout<<endl;
cout<<"Student Roll Number :"<<rollNum;
cout<<"Student Name :"<<name;
cout<<"Student Address :"<<address<<endl;

        }
            getline(file,rollNum,'*');
    getline(file,name,'*');
    getline(file,address,'\n');
    }
    file.close();
}
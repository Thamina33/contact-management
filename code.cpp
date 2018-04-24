#include<iostream>
#include<fstream>
#include<cstring>
#include<stdlib.h>
using namespace std;

int  checking_existing(const string &c_name , const string &c_ph){
ifstream read ;
int b ;
string name , mail , phone ;
read.open("contact.txt",ios::out| ios::app );

while(read>>name>>phone>>mail){
  if(name == c_name || phone == c_ph){
b=1 ;
break ;
}
else
{
  b=0 ;
}
}
return b ;
}

class user{
         public:
         char name [25];
         char mail_add[25];
        char phone [25];
        char h_address [25];
        char dob [25];


};
class contact : public user{
        public:
        void insert_contact();
        void show_all();
        void search_contact();
        void delete_contact();
        void update_contact();

};

void contact :: insert_contact(){
            system("cls");
            system("color 57");
             cout<<"\n\t\t\t\t**************************************************"<<endl;
             cout<<"\n\t\t\t\t   ********* Contact Management System  *********"<<endl;
             cout<<"\n\t\t\t\t**************************************************"<<endl;
             cout<<"\n\n\t\t\t\t\t\tEnter Contact details \n\t\t\t\t\t____________________________________"<<endl;
    fstream stud;
    label:
        stud.open("contact.txt", ios::app);
        cin.ignore();
        cout<<" \n\n\n\t\t Enter name : ";
        cin.getline(name,25);
        cout<<" \n\n\t\tEnter phone : ";
        cin.getline(phone,25);
        cout<<" \n\n\t\t Enter E-mail : ";
        cin.getline(mail_add,25);
        cout<<" \n\n\t\t Enter Home Address : ";
        cin.getline(h_address,25);
        cout<<" \n\n\t\t Enter Date of Birth : ";
        cin.getline(dob,25);
       string c_name , c_ph ;
      c_ph=phone;
      c_name= name ;
      int a ;
      a =checking_existing( c_name ,c_ph);
      if(a==1){
       cout<<"This Name or Phone Number  is already Taken  "<<endl; ;
       cout<<"please Press 'Any Key to try Again' "<<endl ;

       goto label ;
     }
           else {
    stud<< name<<' '<<phone<<' '<<mail_add<<' '<<h_address<<' '<<dob<<'\n';
    cout<< "\n\n\t\t\tdone !";
    cout<<"\n\t\tContact has been saved successfully !!!"<<endl;
    stud.close();
     }

}

void contact :: show_all(){
            system("cls");
            system("color 6f");
             cout<<"\n\t\t\t\t#########################################################"<<endl;
             cout<<"\n\t\t\t\t#\t\tContact Management System\t\t#"<<endl;
             cout<<"\n\t\t\t\t#########################################################"<<endl;
         fstream stud;
         stud.open("contact.txt",ios::in);

          int counter =1;
         while(!stud.eof())
    {

        stud.getline(name,25,' ');
        stud.getline(phone,25,' ');
        stud.getline(mail_add,25,' ');
        stud.getline(h_address,25,' ');
        stud.getline(dob,25);
        if(stud.eof()){
        break;
        }
        cout<<"\tContact ["<<counter++<<"]"<<endl;
        cout<< "\n \t\tName\t\t: "<< name << "\n\t\tPhone\t\t: "<<phone<<"\n\t\tE-mail\t\t: "<<mail_add<<"\n\t\tHome Address\t: "<<h_address<<"\n\t\tDate of Birth\t: "<<dob<<"\n"<<endl;


    }

}

void contact :: search_contact(){
                system("cls");
            system("color f4");
             cout<<"\n\t\t\t\t#########################################################"<<endl;
             cout<<"\n\t\t\t\t#\t\tContact Management System\t\t#"<<endl;
             cout<<"\n\t\t\t\t#########################################################"<<endl;
         fstream stud;
    stud.open("contact.txt",ios::in);

    char a[25];
    cout<<" \n\t enter the Name  of Contact to search about it : ";
    cin.ignore();
    cin.getline(a,25);

    int x=0;

    while(!stud.eof())
    {
        stud.getline(name,25,' ');
        stud.getline(phone,25,' ');
        stud.getline(mail_add,25,' ');
        stud.getline(h_address,25,' ');
        stud.getline(dob,25);
        if(strcmp(name, a)==0)
        {
            cout<< "\n \t\tName\t\t: "<< name << "\n\t\tPhone\t\t: "<<phone<<"\n\t\tE-mail\t\t: "<<mail_add<<"\n\t\tHome Address\t: "<<h_address<<"\n\t\tDate of Birth\t: "<<dob<<"\n"<<endl;

            x=1;
            break;
        }

    }
    if(x==0)
    {
        cout<<" \n\n\n\t\t not found !!!!\n";
    }
    stud.close();

}
void contact ::update_contact(){
            system("cls");
            system("color 21");
            cout<<"\n\t\t\t\t#########################################################"<<endl;
             cout<<"\n\t\t\t\t#\t\tContact Management System\t\t#"<<endl;
             cout<<"\n\t\t\t\t#########################################################"<<endl;

     fstream stud;
    fstream temp;

    stud.open("contact.txt",ios::in);
    temp.open("temp.txt",ios::out);
    char a[25];
    cin.ignore();
    cout<<" \n\t\t enter the Name  of Contact to update record : ";
    cin.getline(a,25);
    while(!stud.eof())
    {
        stud.getline(name,25,' ');
        stud.getline(phone,25,' ');
       stud.getline(mail_add,25,' ');
        stud.getline(h_address,25,' ');
        stud.getline(dob,25);
        if(strcmp(name,a)==0)
        {
             fstream file_read;
             label :
            file_read.open("contact.txt", ios::app);
            cin.ignore();
            cout<<" \n\t\tEnter new value of record  \n ";
            cout<<" \n\n\t\tName : ";

            cin.getline(name,25);
            cout<<" \n\n\tPhone : ";
            cin.getline(phone,25);
            cout<<" \n\n\tMail Address : ";
            cin.getline(mail_add,25);
            cout<<" \n\n\t\t Home Address : ";
            cin.getline(h_address,25);
            cout<<" \n\n\t\t Date of Birth : ";
            cin.getline(dob,25);

            string c_name , c_ph ;
          c_ph=phone;
          c_name= name ;
          int a ;
           a =checking_existing( c_name ,c_ph);
           if(a==1){
           cout<<"\n\t\tThis Name or Phone Number  is already Taken  "<<endl; ;
           cout<<"\n\t\tplease Press 'Any Key to try Again' "<<endl ;

         goto label ;
           }
            else{
            temp<<name<<' '<<phone<<' '<<mail_add<<' '<<h_address<<' '<<dob<<'\n';
            }
        }
        else
        {
            temp<<name<<' '<<phone<<' '<<mail_add<<' '<<h_address<<' '<<dob<<'\n';
        }


    }
    temp.close();
    stud.close();

    stud.open("contact.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof())
    {
        temp.getline(name,25,' ');
        temp.getline(phone,25,' ');
        temp.getline(mail_add,25,' ');
        temp.getline(h_address,25,' ');
        temp.getline(dob,25);
        stud<<name<<' '<<phone<<' '<<mail_add<<' '<<h_address<<' '<<dob<<'\n';
    }
    temp.close();
    stud.close();
    remove("temp.txt");
    cout<<"\n done !!! \n";
}

   void contact :: delete_contact(){
           system("cls");
            system("color ec");
              cout<<"\n\t\t\t\t#########################################################"<<endl;
             cout<<"\n\t\t\t\t#\t\tContact Management System\t\t#"<<endl;
             cout<<"\n\t\t\t\t#########################################################"<<endl;
          fstream stud;
         fstream temp;

    stud.open("contact.txt",ios::in);
    temp.open("temp.txt",ios::out);
    char a[25];
    cin.ignore();
    cout<<" \n\n\n\t\t enter the Name  of Contact to delete record : ";
    cin.getline(a,25);
    while(!stud.eof())
    {
        stud.getline(name,25,' ');
        stud.getline(phone,25,' ');
        stud.getline(mail_add,25,' ');
        stud.getline(h_address,25,' ');
        stud.getline(dob,25);
        if(strcmp(name,a)==0)
        {
            continue;
        }
        else
        {
            temp<<name<<' '<<phone<<' '<<mail_add<<' '<<h_address<<' '<<dob<<'\n';
        }


    }
    temp.close();
    stud.close();

    stud.open("contact.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof())
    {
        temp.getline(name,25,' ');
        temp.getline(phone,25,' ');
        temp.getline(mail_add,25,' ');
        temp.getline(h_address,25,' ');
        temp.getline(dob,25);
        stud<<name<<' '<<phone<<' '<<mail_add<<' '<<h_address<<' '<<dob<<'\n';
    }
    temp.close();
    stud.close();
    remove("temp.txt");
    cout<<"\n done !!! \n";
   }
int main()
{   contact ob;
    string User = "admin";
    string pass= "1234";
    bool flag=true;
    string User_name;
    string Passcode;
    label :
        system("cls");
        system("color b9");
        cout<<"\n\n\t\t\t\t\t\t***** WellCOME *****\n\t\t\t\t\t To our Contact Management System"<<endl;
        cout<<"\t\t====================================================================================="<<endl;
        cout<<"\n\n\t\tPlease, sign up with your User Name and password :"<< endl;
        cout<<"\n\n\t\t Enter Your User Name : ";
        cin>>User_name;
        cout<<"\n\t\t Enter Your User Passcode : ";
        cin>>Passcode;
        cout<<"\n\n\tThank You, Sir, \n\t\t  for using our Contact Management System "<<endl;
        if(User_name == User && Passcode == pass){

    while (flag)
    {
        system("cls");
        system("color 3f");
        cout<<"\a"<<endl;
        cout<<"\n\t\t\toooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"<<endl;
        cout<<"\n\t\t\tooooo\t\t\tCONTACT MANAGEMENT SYSTEM\t\toooooo"<<endl;
        cout<<"\n\t\t\toooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"<<endl;
        cout<<"\n\n\tThank You, Sir, \n\t\t  for using our Contact Management System "<<endl;
        cout << "\n\n\t\t\t Create a Contact\t: [1]\n\t\t\t Search Contact\t\t: [2] \n\t\t\t Display all Contact\t: [3] \n\t\t\t Update a Contact\t: [4] \n\t\t\t Delete a Contact\t: [5] \n\n\n\t\t\t write your choose\t: ";
        int c;
        cin>>c;
        switch (c)
        {
        case 1 :

            ob.insert_contact();
            break;
        case 2:

            ob.search_contact();
            break;
        case 3:

            ob.show_all();
            break;
        case 4 :

           ob.update_contact();

            break;
        case 5 :

           ob.delete_contact();
            break;
            case 6 :


        default :
            cout << " \n choose right number \n";
        }
        cout << "\n if you continue to use program press ' y ' \n ";
        char f;
        cin>>f;
        if(f!='y')
        {
            flag=false;
        }
    }
        }
    else{
        goto label;
    }
    return 0;
}



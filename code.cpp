#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void delete_contact()
{

    fstream stud;
    fstream temp;

    stud.open("contact.txt",ios::in);
    temp.open("temp.txt",ios::out);
    char name [25];
    char mail_add[25];
    char phone [25];
    char a[25];
    cin.ignore();
    cout<<" \n\t enter the name  number to delete record : ";
    cin.getline(a,25);
    while(!stud.eof())
    {
        stud.getline(name,25,'|');
        stud.getline(phone,25,'|');
        stud.getline(mail_add,25);
        if(strcmp(name,a)==0)
        {
            continue;
        }
        else
        {
            temp<< name<<'|'<<phone<<'|'<<mail_add<<'\n';
        }


    }
    temp.close();
    stud.close();

    stud.open("contact.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof())
    {
        temp.getline(name,25,'|');
        temp.getline(phone,25,'|');
        temp.getline(mail_add,25);
        stud<< name<<'|'<<phone<<'|'<<mail_add<<'\n';
    }
    temp.close();
    stud.close();
    remove("temp.txt");
    cout<<"\n done !!! \n";
}
void update_contact()
{
    fstream stud;
    fstream temp;

    stud.open("contact.txt",ios::in);
    temp.open("temp.txt",ios::out);
    char name [25];
    char mail_add[25];
    char phone [25];
    char a[25];
    cin.ignore();
    cout<<" \n\t enter the name  number to update record : ";
    cin.getline(a,25);
    while(!stud.eof())
    {
        stud.getline(name,25,'|');
        stud.getline(phone,25,'|');
        stud.getline(mail_add,25);
        if(strcmp(name,a)==0)
        {

            cout<<" \n\tenter new value of record  \n ";
            cout<<" \n name : ";
            cin.getline(name,25);
            cout<<" \n phone : ";
            cin.getline(phone,25);
            cout<<" \n age : ";
            cin.getline(mail_add,25);
            temp<< name<<'|'<<phone<<'|'<<mail_add<<'\n';
        }
        else
        {
            temp<< name<<'|'<<phone<<'|'<<mail_add<<'\n';
        }


    }
    temp.close();
    stud.close();

    stud.open("contact.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof())
    {
        temp.getline(name,25,'|');
        temp.getline(phone,25,'|');
        temp.getline(mail_add,25);
        stud<< name<<'|'<<phone<<'|'<<mail_add<<'\n';
    }
    temp.close();
    stud.close();
    remove("temp.txt");
    cout<<"\n done !!! \n";
}
void display_all()
{
    char name [25];
    char mail_add[25];
    char phone [25];

    fstream stud;
    stud.open("contact.txt",ios::in);

    cout<< " \n\t name \t phone \t Mail Address \n";
    while(!stud.eof())
    {
        stud.getline(name,25,'|');
        stud.getline(phone,25,'|');
        stud.getline(mail_add,25);
        cout<< "\n \t "<< name << "\t"<<phone<<"\t"<<mail_add<<endl;

    }
}
void search_contact(   )
{

    fstream stud;
    stud.open("contact.txt",ios::in);
    char name [25];
    char mail_add[25];
    char phone [25];
    char a[25];
    cout<<" \n enter the name to search about it : ";
    cin.ignore();
    cin.getline(a,25);
    int x=0;
    cout<< " \n\t name \t phone \t mail address \n";
    while(!stud.eof())
    {
        stud.getline(name,25,'|');
        stud.getline(phone,25,'|');
        stud.getline(mail_add,25);
        if(strcmp(name, a)==0)
        {
            cout<< "\n \t "<< name << "\t"<<phone<<"\t"<<mail_add<<endl;
            x=1;
            break;
        }

    }
    if(x==0)
    {
        cout<<" \n not found !!!!\n";
    }
    stud.close();
}
void  insert_contact()
{

    char name [25];
    char mail_add[25];
    char phone [25];
    fstream stud;
    stud.open("contact.txt", ios::app);
    cin.ignore();
    cout<<" \n name : ";
    cin.getline(name,25);
    cout<<" \n phone : ";
    cin.getline(phone,25);
    cout<<" \n Mail Address : ";
    cin.getline(mail_add,25);
    stud<< name<<'|'<<phone<<'|'<<mail_add<<'\n';
    cout<< "done !";
    stud.close();
}

int main()
{
    bool flag=true;
    while (flag)
    {
        cout << " insert : 1 \n search : 2 \n display all : 3 \n update : 4 \n delete :  5 \n write your choose : ";
        int c;
        cin>>c;
        switch (c)
        {
        case 1 :
            insert_contact();
            break;
        case 2:
            search_contact();
            break;
        case 3:
            display_all();
            break;
        case 4 :
            update_contact();

            break;
        case 5 :
            delete_contact();
            break;
        default :
            cout << " \n choose right number \n";
        }
        cout << " if you continue to use program press ' y ' \n ";
        char f;
        cin>>f;
        if(f!='y')
        {
            flag=false;
        }
    }
    return 0;
}

#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
void user_menu(string);
class user
{
	public:
     string name;
	string phone;
	string dob;


};
class contact : public user
{
public:
    void createAccount();
    void show_all();
     void search_contact( string );
};
void contact :: createAccount()
{

	cout << "\n\tEnter  name :";
	cin>>name;
	cin.clear();


	cout << "\n\tEnter phone number :";
	cin >>phone;
	cin.clear();
	cout << "\n\tEnter Date f Birth :";
	cin >>dob;
	cin.clear();

                ofstream file;
                file.open("contact.txt",ios::out | ios :: app);
                file <<name<<" "<<phone<<" "<<dob<<endl;
                file.close();
}
void contact :: show_all(){

   	      ifstream file_read;
         file_read.open("contact.txt",ios::out| ios :: app);
				 while (file_read>>name>>phone>>dob) {

        cout<<endl<<"Name   :  "<<name;
        cout<<endl<<"Phone  :  "<<phone;
        cout<<endl<<"Dob    :  "<<dob<<endl<<endl;


}
  file_read.close();
}
void contact :: search_contact(string c_name){
int flag = 0;

        ifstream file_read;
        file_read.open("contact.txt",ios::out| ios :: app);
        while (file_read>>name>>phone>>dob) {
        if(c_name == name){
        cout<<endl<<"Name   :  "<<name;
        cout<<endl<<"Phone  :  "<<phone;
        cout<<endl<<"Dob    :  "<<dob<<endl<<endl;
         flag = 1;
        }
        if(file_read.eof()){
            break;
        }
}

	if(flag !=1 )
	{
		cout<<"\n Contact not saved!"<<endl;

	}

 file_read.close();

}

int main()
{
	int ch;
	contact a;
	string c_name;

	do{
	    cout<<"\n\t\t|\tcontact management System\t|\t\t"<<endl;
        cout <<"\n\t 1. Create a Contact";
		cout <<"\n\t 2. Show all  contact.";
		cout <<"\n\t 3. Search a Contact.";
		cout <<"\n\t 0.Exit";

		cout<<"\n\n\tEnter your choice ::";
		if(cin >> ch )
		{
			switch (ch)
			{
				case 1:
					a.createAccount();
				      break;
				case 2:
					a.show_all();
					break;
                case 3:
                    cout<<"\nEnter Contact Name : ";
                    cin>>c_name;
                    a.search_contact(c_name);
                    break;
			}
		}
		else
		{
			cout<<"\n\t Input only Digits please ! Press Enter To continue";

			cin.clear();
		}



	}
	while(ch !=0);

	return 0;
}


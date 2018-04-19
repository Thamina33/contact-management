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
     void edit_contact();
     void delete_contact();
};
void contact :: createAccount()
{
    int flag = 0;
    ifstream file_read;
    string c_name;
    string c_ph;
	cout << "\n\tEnter  name :";
	cin>>c_name;
     file_read.open("contact.txt",ios::out| ios :: app);
        while (file_read>>name>>phone>>dob) {
        if(c_name == name){

        cout<<endl<<"contact name is exit !!!" <<endl;
        cout<<"please enter another name : ";
         flag = 1;
          cin>>c_name;
          cin.clear();

    }
    if(file_read.eof()){
            break;
        }
}
    name = c_name;
    file_read.close();

    cout << "\n\tEnter phone number :";
	cin >>c_ph;
     file_read.open("contact.txt",ios::out| ios :: app);
        while (file_read>>name>>phone>>dob) {
        if(c_ph == phone){

        cout<<endl<<"this number already saved  !!!" <<endl;
         cout<<endl<<"Name   :  "<<name;
        cout<<endl<<"Phone  :  "<<phone;
        cout<<endl<<"Dob    :  "<<dob<<endl<<endl;
        break;
        //problem;;;;
    }
    if(file_read.eof()){
            break;
        }
}

    file_read.close();
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
    int ch;
int flag = 0;
contact a;
        ifstream file_read;
        file_read.open("contact.txt",ios::out| ios :: app);
        while (file_read>>name>>phone>>dob) {
        if(c_name == name){

        cout<<endl<<"Name   :  "<<name;
        cout<<endl<<"Phone  :  "<<phone;
        cout<<endl<<"Dob    :  "<<dob<<endl<<endl;
         flag = 1;

	cin.clear();

		cout<<"\n\t 1.Update contact Details.";
		cout<<"\n\t 2. Delete contact";
		cout<<"\n\t 0.Exit";

		cout<<"\n\t Enter your Choice (1-2)::";
	if(cin >> ch)
	{


		switch (ch)
		{
			case 1:

				a.edit_contact();
				//problem;;;
				break;

			case 2:
				//a.delete_contact();
                break;
             default :
                 if(ch==0){
                   break;
                 }
                 else{
				cout<<"\n\t Worng choise \n";
                 }
				break;
		}
	}
		else
		{
			cout<<"\n\t Input only Digits please !";
			cin.clear();
		 	cin.ignore();
		 	ch=1;
		}
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
void contact :: edit_contact(){
      string new_name;
      string  new_ph;
      string   new_dob;
      cout<<"Enter New Name : ";
      cin>>new_name;
      cin.clear();
      cout<<"Enter New Phone Number : ";
      cin>>new_ph;
       cin.clear();
       cout<<"Enter New DoB : ";
      cin>>new_dob;
       cin.clear();
      name = new_name;
      phone = new_ph;
      dob = new_dob;
      ofstream file("contact.txt",ios::out | ios :: app);
                file <<name<<" "<<phone<<" "<<dob<<endl;
                file.close();
    cout<<"\n\tcontact successfully updated !!!\n";
        cout<<endl<<"Name   :  "<<name;
        cout<<endl<<"Phone  :  "<<phone;
        cout<<endl<<"Dob    :  "<<dob<<endl<<endl;
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


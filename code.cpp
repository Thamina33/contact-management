#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

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
                file.open("contact.txt",ios::in | ios::out | ios :: trunc);
                file <<name<<" "<<phone<<" "<<dob<<endl;
                file.close();
}
void contact :: show_all(){

   	      ifstream file_read;
         file_read.open("contact.txt",ios::out| ios :: app);
        file_read>>name>>phone>>dob;

        cout<<endl<<"Name    :  "<<name;
        cout<<endl<<"Phone    :  "<<phone;
        cout<<endl<<"Dob       :  "<<dob<<endl<<endl;
        file_read.close();


}

int main()
{
	int ch;
	contact a;

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

			}
		}
		else
		{
			cout<<"\n\t Input only Digits please ! Press Enter To continue";

			cin.clear();
		}



	}while(ch !=0);

	return 0;
}


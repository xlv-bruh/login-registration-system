#include <iostream>
#include <fstream>
#include <string>
using namespace std;





int main()
{
	
	bool registrtion = true;
	bool login = false;
	string username;
	string password, password1;
	string email;
	string File;
	fstream out;

	if (registrtion)
	{
		char temp;
		bool email_temp = false;
		cout << "Enter '+' if u want to sing in, or enter '-', if u already have an acc: ";		cin >> temp;
		if (temp == '+')
		{
			cout << endl << "Registrtion:" << endl << endl;

			cout << "Enter email: ";		cin >> email;

			for(int i = 0; i < email.size(); i++)
			{
				if(email[i] == '@')
				{
					email_temp = true;
				}
			}

			cout << "Enter username: ";		cin >> username;

			cout << "Enter password: ";		cin >> password;

			cout << "Enter password again: ";		cin >> password1;
			if (password == password1)
			{
				cout << "Succes" << endl;
				registrtion = false;
				out.open("login.txt");

				out << email << endl;
				out << username << endl;
				out << password;

				out.close();
			}
			else if (email_temp)
				cout << "incorect email" << endl;
			else
				cout << "passwords dont match"<<endl;
		}
		else if (temp == '-')
		{
			cout << "Login" << endl << endl;
			cout << "Enter email: ";		cin >> email;

			cout << "Enter password: ";		cin >> password;

			bool login_email = false;
			bool login_password = false;
			out.open("login.txt");

			for(int i = 0; !out.eof(); i++){
				out >> File;
				if(File == email)
				{
					login_email = true;
				}

				if(i == 1)
				{
					username = File;
				}

				if(File == password)
				{
					login_password = true;
				}

			}
			if (login_email && login_password)
			{
				cout << "Welcome " << username << "!" << endl;
				login = true;
			}
			else
			{
				cout << "Email or Password false, try again" << endl;
			}

			out.close();

		}
	}
	




	return 0;
}

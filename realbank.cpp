

// CHANDU BANK OF INDIA(CBI)

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <mysql.h>
#include <mysqld_error.h>
#include <conio.h>
#include <string>
#include <thread> // For std::this_thread::sleep_for
#include <chrono> ///time
using namespace std;
const char *host = "localhost";
const char *user = "root";
const char *pass = "Chandu123!@#";
class bank
{
private:
	MYSQL *obj;
	string name, father_name, mother_name, phone, aadhar, address, pin;
	double balance = 0;
	int account_number;
	void deposite_Zero_account();
	void deposite_account();
	void withdraw_zero_account();
	void withdraw_account();
	void check_zero_balance();
	void remaining_balance();
	void transfer_from_zero();
	void transfer_account();
	void close_acc1();
	void close_acc2();

public:
	void open_zero_account();
	void open_account();
	void deposite();
	void withdraw();
	void transfer();
	void check_balance();
	void change_upi_pin();
	void history();
	void close_account();
};

void bank::close_acc1()
{
	string phone, acc_num, acc_pin, from_acc, from_pin, from_bal;
	double money;
	bool found = false;
	bool found_account = false;
	bool found_pin = false;
	int h = 3;
	obj = mysql_init(nullptr);
	system("cls");
	if (!mysql_real_connect(obj, host, user, pass, "bank", 3306, NULL, 0))
	{
		cout << "Error :" << mysql_error(obj) << endl;
	}
	else
	{
		do
		{
			cout << "Enter phone number :";
			cin >> phone;
			if (phone.length() != 10)
			{
				cout << "Inavlid phone number!" << endl;
				found = false;
				continue;
			}
			for (size_t i = 0; i < phone.length(); i++)
			{
				if (!isdigit(phone[i]))
				{
					cout << "Inavalid phone number!" << endl;
					found = false;
				}
				else
				{
					found = true;
				}
			}
		} while (!found);
		cout << "Enter account number :";
		cin >> acc_num;
		string line = "select account_number,pin,balance from account where phone='" + phone + "' and account_number='" + acc_num + "'";
		if (mysql_query(obj, line.c_str()))
		{
			cout << "Error :" << mysql_error(obj) << endl;
		}
		else
		{
			MYSQL_RES *res = mysql_store_result(obj);
			MYSQL_ROW row;
			if (res)
			{
				while (row = mysql_fetch_row(res))
				{
					from_acc = row[0];
					from_pin = row[1];
					from_bal = row[2];
					found_account = true;
				}
			}
			else
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
			if (found_account == true)
			{
				if (stod(from_bal) > 0)
				{
					cout << "Withdraw balanace amount!" << endl;
					this_thread::sleep_for(chrono::milliseconds(4000));
					withdraw();
				}
				else
				{
					char ch;
					do
					{
						acc_pin.clear();
						cout << "Enter pin :";
						while (true)
						{
							ch = _getch();
							if (ch == '\r')
							{
								break;
							}
							else if (ch == '\b')
							{
								if (!acc_pin.empty())
								{
									acc_pin.pop_back();
									cout << "\b \b";
								}
							}
							else
							{
								acc_pin += ch;
								cout << "*";
							}
						}
						cout << endl;
						if (from_pin == acc_pin)
						{
							found_pin = true;
						}
						else
						{
							found_pin = false;
							h--;
							if (h == 0)
							{
								break;
								cout << "Invalid pin intered" << endl;
								close_account();
							}
							else
							{
								cout << h << " attempts remaining" << endl;
							}
						}
					} while (from_pin != acc_pin);
					string del_acc = "delete from account where account_number='" + acc_num + "' and phone='" + phone + "'";
					if (mysql_query(obj, del_acc.c_str()))
					{
						cout << "Error :" << mysql_error(obj) << endl;
					}
					else
					{
						if (mysql_affected_rows(obj) > 0)
						{
							cout << "Account closed successfull" << endl;
						}
					}
				}
			}
			else
			{
				cout << "Account not found!" << endl;
				this_thread::sleep_for(chrono::milliseconds(4000));
			}
		}
	}
	mysql_close(obj);
}

void bank::close_acc2()
{
	string phone, acc_num, acc_pin, from_acc, from_pin, from_bal;
	double money;
	bool found = false;
	bool found_account = false;
	bool found_pin = false;
	int h = 3;
	obj = mysql_init(nullptr);
	system("cls");
	if (!mysql_real_connect(obj, host, user, pass, "bank", 3306, NULL, 0))
	{
		cout << "Error :" << mysql_error(obj) << endl;
	}
	else
	{
		do
		{
			cout << "Enter phone number :";
			cin >> phone;
			if (phone.length() != 10)
			{
				cout << "Inavlid phone number!" << endl;
				found = false;
				continue;
			}
			for (size_t i = 0; i < phone.length(); i++)
			{
				if (!isdigit(phone[i]))
				{
					cout << "Inavalid phone number!" << endl;
					found = false;
				}
				else
				{
					found = true;
				}
			}
		} while (!found);
		cout << "Enter account number :";
		cin >> acc_num;
		string line = "select account_number,pin from nmlaccount where phone='" + phone + "' and account_number='" + acc_num + "'";
		if (mysql_query(obj, line.c_str()))
		{
			cout << "Error :" << mysql_error(obj) << endl;
		}
		else
		{
			MYSQL_RES *res = mysql_store_result(obj);
			MYSQL_ROW row;
			if (res)
			{
				while (row = mysql_fetch_row(res))
				{
					from_acc = row[0];
					from_pin = row[1];
					from_bal = row[2];
					found_account = true;
				}
			}
			else
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
			if (found_account == true)
			{
				if (stod(from_bal) >= 1000)
				{
					cout << "Withdraw balanace amount!" << endl;
					this_thread::sleep_for(chrono::milliseconds(4000));
					withdraw();
				}
				else
				{
					char ch;
					do
					{
						acc_pin.clear();
						cout << "Enter pin :";
						while (true)
						{
							ch = _getch();
							if (ch == '\r')
							{
								break;
							}
							else if (ch == '\b')
							{
								if (!acc_pin.empty())
								{
									acc_pin.pop_back();
									cout << "\b \b";
								}
							}
							else
							{
								acc_pin += ch;
								cout << "*";
							}
						}
						cout << endl;
						if (from_pin == acc_pin)
						{
							found_pin = true;
						}
						else
						{
							found_pin = false;
							h--;
							if (h == 0)
							{
								break;
								cout << "Invalid pin intered" << endl;
								close_account();
							}
							else
							{
								cout << h << " attempts remaining" << endl;
							}
						}
					} while (from_pin != acc_pin);
					string del_acc = "delete from nmlaccount where account_number='" + acc_num + "' and phone='" + phone + "'";
					if (mysql_query(obj, del_acc.c_str()))
					{
						cout << "Error :" << mysql_error(obj) << endl;
					}
					else
					{
						if (mysql_affected_rows(obj) > 0)
						{
							cout << "Account closed successfull" << endl;
						}
					}
				}
			}
			else
			{
				cout << "Account not found!" << endl;
				this_thread::sleep_for(chrono::milliseconds(4000));
			}
		}
	}
	mysql_close(obj);
}

// closing account
void bank::close_account()
{
	int choice;
	system("cls");
	do
	{
		cout << "choose account type" << endl;
		cout << "1)Zero account" << endl;
		cout << "2)Savings account" << endl;
		cout << "3)EXIT" << endl;
		cout << "choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			close_acc1();
			break;
		case 2:
			close_acc2();
			break;
		case 3:
			break;
		default:
			cout << "Invalid choice!" << endl;
		}
	} while (choice != 3);
}

// check pin
void bank::change_upi_pin()
{
	int acc_num;
	string phone_num, acc_pin, acc_pinn;
	bool found_num = false;
	bool reciver1 = false;
	bool reciver2 = false;
	obj = mysql_init(nullptr);
	if (!mysql_real_connect(obj, host, user, pass, "bank", 3306, NULL, 0))
	{
		cout << "Error :" << mysql_error(obj) << endl;
	}
	else
	{
		cout << "Enter account number to to change pin :";
		cin >> acc_num;
		do
		{
			cout << "Enter phone number :";
			cin >> phone_num;
			if (phone_num.length() != 10)
			{
				cout << "Invalid phone number!" << endl;
				found_num = false;
				continue;
			}
			for (size_t i = 0; i < phone_num.length(); i++)
			{
				if (!isdigit(phone_num[i]))
				{
					cout << "Invalid phone number!" << endl;
					found_num = false;
				}
				else
				{
					found_num = true;
				}
			}
		} while (!found_num);
		string found_account = "select account_number from account where phone='" + phone_num + "' and account_number='" + to_string(acc_num) + "'";
		if (mysql_query(obj, found_account.c_str()))
		{
			cout << "Error :" << mysql_error(obj) << endl;
		}
		else
		{
			MYSQL_RES *res = mysql_store_result(obj);
			MYSQL_ROW row;
			if (res)
			{
				while (row = mysql_fetch_row(res))
				{
					reciver1 = true;
				}
			}
			else
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
		}
		string found_account2 = "select account_number from nmlaccount where phone='" + phone_num + "' and account_number='" + to_string(acc_num) + "'";
		if (mysql_query(obj, found_account2.c_str()))
		{
			cout << "Error :" << mysql_error(obj) << endl;
		}
		else
		{
			MYSQL_RES *res = mysql_store_result(obj);
			MYSQL_ROW row;
			if (res)
			{
				while (row = mysql_fetch_row(res))
				{
					reciver2 = true;
				}
			}
			else
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
		}
		if (reciver1 != true && reciver2 != true)
		{
			cout << "Account not found!" << endl;
			this_thread::sleep_for(chrono::milliseconds(4000));
		}
		else
		{
			if (reciver1 == true)
			{
				do
				{
					char ch;
					acc_pin.clear();
					cout << "Enter new pin :";
					while (true)
					{
						ch = _getch();
						if (ch == '\r')
						{
							break;
						}
						else if (ch == '\b')
						{
							if (!acc_pin.empty())
							{
								acc_pin.pop_back();
								cout << "\b \b";
							}
						}
						else
						{
							acc_pin += ch;
							cout << "*";
						}
					}
					cout << endl;
					char ch1;
					acc_pinn.clear();
					cout << "Enter pin again :";
					while (true)
					{
						ch1 = _getch();
						if (ch1 == '\r')
						{
							break;
						}
						else if (ch1 == '\b')
						{
							if (!acc_pinn.empty())
							{
								acc_pinn.pop_back();
								cout << "\b \b";
							}
						}
						else
						{
							acc_pinn += ch1;
							cout << "*";
						}
					}
					cout << endl;
				} while (acc_pin != acc_pinn);
				string update_pin = "update account set pin='" + acc_pinn + "' where account_number='" + to_string(acc_num) + "' and phone='" + phone_num + "'";
				if (mysql_query(obj, update_pin.c_str()))
				{
					cout << "Error :" << mysql_error(obj) << endl;
				}
				else
				{
					if (mysql_affected_rows(obj) > 0)
					{
						cout << "Pin updated sucessfull" << endl;
						this_thread::sleep_for(chrono::milliseconds(3000));
					}
				}
			}
			if (reciver2 == true)
			{
				do
				{
					char ch;
					acc_pin.clear();
					cout << "Enter new pin :";
					while (true)
					{
						ch = _getch();
						if (ch == '\r')
						{
							break;
						}
						else if (ch == '\b')
						{
							if (!acc_pin.empty())
							{
								acc_pin.pop_back();
								cout << "\b \b";
							}
						}
						else
						{
							acc_pin += ch;
							cout << "*";
						}
					}
					cout << endl;
					char ch1;
					acc_pinn.clear();
					cout << "Enter pin again :";
					while (true)
					{
						ch1 = _getch();
						if (ch1 == '\r')
						{
							break;
						}
						else if (ch1 == '\b')
						{
							if (!acc_pinn.empty())
							{
								acc_pinn.pop_back();
								cout << "\b \b";
							}
						}
						else
						{
							acc_pinn += ch1;
							cout << "*";
						}
					}
					cout << endl;
				} while (acc_pin != acc_pinn);
				string update_pin = "update nmlaccount set pin='" + acc_pinn + "' where account_number='" + to_string(acc_num) + "' and phone='" + phone_num + "'";
				if (mysql_query(obj, update_pin.c_str()))
				{
					cout << "Error :" << mysql_error(obj) << endl;
				}
				else
				{
					if (mysql_affected_rows(obj) > 0)
					{
						cout << "Pin updated sucessfull" << endl;
						this_thread::sleep_for(chrono::milliseconds(3000));
					}
				}
			}
		}
	}
	mysql_close(obj);
}
// history
void bank::history()
{
	string phone_num;
	int acc_num;
	bool found_num = false;
	bool reciver1 = false;
	bool reciver2 = false;
	system("cls");
	cout << "                                                                  HISTORY" << endl;
	obj = mysql_init(nullptr);
	if (!mysql_real_connect(obj, host, user, pass, "bank", 3306, NULL, 0))
	{
		cout << "Error :" << mysql_error(obj) << endl;
	}
	else
	{
		cout << "Enter account number to see transition history :";
		cin >> acc_num;
		do
		{
			cout << "Enter phone number :";
			cin >> phone_num;
			if (phone_num.length() != 10)
			{
				cout << "Invalid phone number!" << endl;
				found_num = false;
				continue;
			}
			for (size_t i = 0; i < phone_num.length(); i++)
			{
				if (!isdigit(phone_num[i]))
				{
					cout << "Invalid phone number!" << endl;
					found_num = false;
				}
				else
				{
					found_num = true;
				}
			}
		} while (!found_num);
		string found_account = "select account_number from account where phone='" + phone_num + "' and account_number='" + to_string(acc_num) + "'";
		if (mysql_query(obj, found_account.c_str()))
		{
			cout << "Error :" << mysql_error(obj) << endl;
		}
		else
		{
			MYSQL_RES *res = mysql_store_result(obj);
			MYSQL_ROW row;
			if (res)
			{
				while (row = mysql_fetch_row(res))
				{
					reciver1 = true;
				}
			}
			else
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
		}
		string found_account2 = "select account_number from nmlaccount where phone='" + phone_num + "' and account_number='" + to_string(acc_num) + "'";
		if (mysql_query(obj, found_account2.c_str()))
		{
			cout << "Error :" << mysql_error(obj) << endl;
		}
		else
		{
			MYSQL_RES *res = mysql_store_result(obj);
			MYSQL_ROW row;
			if (res)
			{
				while (row = mysql_fetch_row(res))
				{
					reciver2 = true;
				}
			}
			else
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
		}
		if (reciver1 == true || reciver2 == true)
		{
			string show_history = "select transition_history from history where account_number='" + to_string(acc_num) + "' and phone='" + phone_num + "'";
			if (mysql_query(obj, show_history.c_str()))
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
			else
			{
				MYSQL_RES *res = mysql_store_result(obj);
				MYSQL_ROW row;
				if (res)
				{
					while (row = mysql_fetch_row(res))
					{
						for (unsigned int i = 0; i < mysql_num_fields(res); i++)
						{
							cout << row[i];
						}
						cout << endl;
					}
				}
				else
				{
					cout << "Error :" << mysql_error(obj) << endl;
				}
				mysql_free_result(res);
			}
		}
		else
		{
			cout << "Account not found!" << endl;
			this_thread::sleep_for(chrono::milliseconds(4000));
		}
	}
	mysql_close(obj);
}

// deposite money
void bank::open_zero_account()
{
	bool found = false;
	bool account_found = false;
	system("cls");
	cout << "                     Creating zero account" << endl;
	// details
	cin.ignore();
	cout << "Enter name :";
	getline(cin, name);
	cout << "Enter father name :";
	getline(cin, father_name);
	cout << "Enter mother name :";
	getline(cin, mother_name);
	do
	{
		cout << "Enter phone number :";
		cin >> phone;
		if (phone.length() != 10)
		{
			found = false;
			cout << "Invalid mobile number!" << endl;
			continue;
		}
		for (size_t i = 0; i < phone.length(); i++)
		{
			if (!isdigit(phone[i]))
			{
				cout << "Invalid mobile number!" << endl;
				found = false;
			}
			else
			{
				found = true;
			}
		}
	} while (found == false);
	bool aadhar_found = false;
	do
	{
		cout << "Enter aadhar number :";
		cin >> aadhar;
		if (aadhar.length() != 12)
		{
			cout << "Invalid aadhar number!" << endl;
			aadhar_found = false;
			continue;
		}
		for (size_t i = 0; i < aadhar.length(); i++)
		{
			if (!isdigit(aadhar[i]))
			{
				cout << "Invalid aadhar number!" << endl;
				aadhar_found = false;
			}
			else
			{
				aadhar_found = true;
			}
		}
	} while (!aadhar_found);
	cout << "Enter address :";
	cin.ignore();
	getline(cin, address);
	srand(time(0));
	account_number = rand() % 10000000000000000;
	// opening bank server
	obj = mysql_init(nullptr);
	if (!mysql_real_connect(obj, host, user, pass, "bank", 3306, NULL, 0))
	{
		cout << "Error :" << mysql_error(obj) << endl;
	}
	else
	{
		// data base connected
		string line = "select phone,aadhar from account where phone='" + phone + "' or aadhar='" + aadhar + "'";
		if (mysql_query(obj, line.c_str()))
		{
			cout << "Error :" << mysql_error(obj) << endl;
		}
		else
		{
			// query passed
			MYSQL_RES *res = mysql_store_result(obj);
			MYSQL_ROW row;
			if (res)
			{
				while (row = mysql_fetch_row(res))
				{
					cout << "Account is already exsists" << endl;
					account_found = true;
				}
				mysql_free_result(res);
			}
			else
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
		}
	}
	/*
	 name varchar(225
 father_name varchar(225),
 mother_name varchar(225),
 phone varchar(225),
 aadhar varchar(225),
 address varchar(250),
 account_number varchar(220),
 pin int,
 balance double);
	*/
	if (account_found == false)
	{
		cout << "Account created" << endl;
		cout << "ACCOUNT NUMBER IS :" << account_number << endl;
		bool found_pin = false;
		do
		{
			cout << "Set a four digit pin :";
			cin >> pin;
			if (pin.length() < 4 || pin.length() > 4)
			{
				cout << "Set only four digit pin!" << endl;
				found_pin = false;
				continue;
			}
			for (size_t i = 0; i < pin.length(); i++)
			{
				if (!isdigit(pin[i]))
				{
					cout << "Set only four digit pin!" << endl;
					found_pin = false;
				}
				else
				{
					found_pin = true;
				}
			}
		} while (!found_pin);
		stringstream s;
		s << pin;
		string changed_pin = s.str();
		stringstream ss;
		ss << account_number;
		string changed_acc_num = ss.str();
		int x = 0;
		string insert_into_database = "insert into account (name,father_name,mother_name,phone,aadhar,address,account_number,pin,balance) values('" + name + "','" + father_name + "','" + mother_name + "','" + phone + "','" + aadhar + "','" + address + "','" + changed_acc_num + "','" + changed_pin + "','" + to_string(x) + "')";
		if (mysql_query(obj, insert_into_database.c_str()))
		{
			cout << "Error :" << mysql_error(obj) << endl;
		}
		else
		{
			cout << "Pin successfully updated" << endl;
		}
	}
	mysql_close(obj);
}

// open account
void bank::open_account()
{
	bool found = false;
	bool account_found = false;
	system("cls");
	cout << "                     Creating account" << endl;
	// details
	cin.ignore();
	cout << "Enter name :";
	getline(cin, name);
	cout << "Enter father name :";
	getline(cin, father_name);
	cout << "Enter mother name :";
	getline(cin, mother_name);
	do
	{
		cout << "Enter phone number :";
		cin >> phone;
		if (phone.length() != 10)
		{
			found = false;
			cout << "Invalid mobile number!" << endl;
			continue;
		}
		for (size_t i = 0; i < phone.length(); i++)
		{
			if (!isdigit(phone[i]))
			{
				cout << "Invalid mobile number!" << endl;
				found = false;
			}
			else
			{
				found = true;
			}
		}
	} while (!found);
	bool aadhar_found = false;
	do
	{
		cout << "Enter aadhar number :";
		cin >> aadhar;
		if (aadhar.length() != 12)
		{
			cout << "Invalid aadhar number!" << endl;
			aadhar_found = false;
			continue;
		}
		for (size_t i = 0; i < aadhar.length(); i++)
		{
			if (!isdigit(aadhar[i]))
			{
				cout << "Invalid aadhar number!" << endl;
				aadhar_found = false;
			}
			else
			{
				aadhar_found = true;
			}
		}
	} while (!aadhar_found);
	cout << "Enter address :";
	cin.ignore();
	getline(cin, address);
	srand(time(0));
	account_number = rand() % 1000000000000;
	// opening bank server
	obj = mysql_init(nullptr);
	if (!mysql_real_connect(obj, host, user, pass, "bank", 3306, NULL, 0))
	{
		cout << "Error :" << mysql_error(obj) << endl;
	}
	else
	{
		// data base connected
		string line = "select phone,aadhar from nmlaccount where phone='" + phone + "' or aadhar='" + aadhar + "'";
		if (mysql_query(obj, line.c_str()))
		{
			cout << "Error :" << mysql_error(obj) << endl;
		}
		else
		{
			// query passed
			MYSQL_RES *res = mysql_store_result(obj);
			MYSQL_ROW row;
			if (res)
			{
				while (row = mysql_fetch_row(res))
				{
					cout << "Account is already exsists" << endl;
					account_found = true;
				}
				mysql_free_result(res);
			}
			else
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
		}
	}
	/*
	 name varchar(225
 father_name varchar(225),
 mother_name varchar(225),
 phone varchar(225),
 aadhar varchar(225),
 address varchar(250),
 account_number varchar(220),
 pin int,
 balance double);
	*/
p:
	cout << "Deposite 1000 rupeess" << endl;
	cin >> balance;
	stringstream l;
	l << balance;
	string balance_amount = l.str();
	if (balance >= 1000)
	{
		if (account_found == false)
		{
			cout << "Account created" << endl;
			cout << "ACCOUNT NUMBER IS :" << account_number << endl;
			bool found_pin = false;
			do
			{

				cout << "Set a four digit pin :";
				cin >> pin;
				if (pin.length() < 4 || pin.length() > 4)
				{
					cout << "Set only four digit pin!" << endl;
					found_pin = false;
					continue;
				}
				for (size_t i = 0; i < pin.length(); i++)
				{
					if (!isdigit(pin[i]))
					{
						cout << "Set only four digit pin!" << endl;
						found_pin = false;
					}
					else
					{
						found_pin = true;
					}
				}
			} while (!found_pin);
			stringstream s;
			s << pin;
			string changed_pin = s.str();
			stringstream ss;
			ss << account_number;
			string changed_acc_num = ss.str();
			string insert_into_database = "insert into nmlaccount (name,father_name,mother_name,phone,aadhar,address,account_number,pin,balance) values('" + name + "','" + father_name + "','" + mother_name + "','" + phone + "','" + aadhar + "','" + address + "','" + changed_acc_num + "','" + changed_pin + "','" + balance_amount + "')";
			if (mysql_query(obj, insert_into_database.c_str()))
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
			else
			{
				cout << "Pin successfully updated" << endl;
			}
		}
	}
	else
	{
		cout << "Deposie minimum 1000 rupeess" << endl;
		goto p;
	}
	mysql_close(obj);
}

// depositing
void bank::deposite_Zero_account()
{
	int temp_account_number;
	double cash;
	bool add_amount = false;
	bool found_phone = false;
	string phone_num;
	system("cls");
	cout << "                                 Depositing into zero account" << endl;
	cout << "Enter account number to deposite :";
	cin >> temp_account_number;
	do
	{
		cout << "Enter phone number :";
		cin >> phone_num;
		if (phone_num.length() != 10)
		{
			cout << "Invalid phone number!" << endl;
			found_phone = false;
			continue;
		}
		for (size_t i = 0; i < phone_num.length(); i++)
		{
			if (!isdigit(phone_num[i]))
			{
				cout << "Invalid phone number!" << endl;
				found_phone = false;
			}
			else
			{
				found_phone = true;
			}
		}
	} while (!found_phone);
	do
	{
		cout << "Enter amount to deposite :";
		cin >> cash;
		if (cash <= 0)
		{
			cout << "Invalid amount!" << endl;
		}
		else
		{
			break;
		}
	} while (true);
	obj = mysql_init(nullptr);
	if (!mysql_real_connect(obj, host, user, pass, "bank", 3306, NULL, 0))
	{
		cout << "Error :" << mysql_error(obj) << endl;
	}
	else
	{
		// connected
		string line = "select account_number from account where account_number='" + to_string(temp_account_number) + "' and phone='" + phone_num + "'";
		if (mysql_query(obj, line.c_str()))
		{
			cout << "Error :" << mysql_error(obj) << endl;
		}
		else
		{
			MYSQL_RES *res = mysql_store_result(obj);
			MYSQL_ROW row;
			if (res)
			{
				while (row = mysql_fetch_row(res))
				{
					add_amount = true;
				}
				mysql_free_result(res);
			}
			else
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
		}
		if (add_amount == true)
		{
			string add_money = "update account set balance= balance+'" + to_string(cash) + "'  where account_number = '" + to_string(temp_account_number) + "'";
			if (mysql_query(obj, add_money.c_str()))
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
			else
			{
				if (mysql_affected_rows(obj) > 0)
				{
					cout << cash << " Balance deposited successfully" << endl;
				}
				time_t now = time(nullptr);
				tm localtm;
				localtime_s(&localtm, &now);
				char buffer[80];
				strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localtm);
				string hist = to_string(cash) + " deposited into " + to_string(temp_account_number) + " on " + buffer;
				string deposite_cash = "insert into history(transition_history,account_number,phone,timedate) values('" + hist + "','" + to_string(temp_account_number) + "','" + phone_num + "','" + buffer + "')";
				if (mysql_query(obj, deposite_cash.c_str()))
				{
					cout << "Error :" << mysql_error(obj) << endl;
				}
				else
				{
					MYSQL_RES *res = mysql_store_result(obj);
					MYSQL_ROW row;
					if (res)
					{
						while (row = mysql_fetch_row(res))
						{
							cout << "Transition saved" << endl;
						}
					}
				}
			}
		}
		else
		{
			cout << "Account not found!" << endl;
		}
	}
	mysql_close(obj);
}
void bank::deposite_account()
{
	int temp_account_number;
	double cash;
	bool add_amount = false;
	string phone_num;
	bool found_phone = false;
	system("cls");
	cout << "                                   Depositing into Savings account" << endl;
	cout << "Enter account number to deposite :";
	cin >> temp_account_number;
	do
	{
		cout << "Enter phone number :";
		cin >> phone_num;
		if (phone_num.length() != 10)
		{
			cout << "Invalid phone number!" << endl;
			found_phone = false;
			continue;
		}
		for (size_t i = 0; i < phone_num.length(); i++)
		{
			if (!isdigit(phone_num[i]))
			{
				cout << "Invalid phone number!" << endl;
				found_phone = false;
			}
			else
			{
				found_phone = true;
			}
		}
	} while (!found_phone);
	do
	{
		cout << "Enter amount to deposite :";
		cin >> cash;
		if (cash <= 0)
		{
			cout << "Invalid amount!" << endl;
		}
		else
		{
			break;
		}
	} while (true);
	obj = mysql_init(nullptr);
	if (!mysql_real_connect(obj, host, user, pass, "bank", 3306, NULL, 0))
	{
		cout << "Error :" << mysql_error(obj) << endl;
	}
	else
	{
		// connected
		string line = "select account_number from nmlaccount where account_number='" + to_string(temp_account_number) + "'";
		if (mysql_query(obj, line.c_str()))
		{
			cout << "Error :" << mysql_error(obj) << endl;
		}
		else
		{
			MYSQL_RES *res = mysql_store_result(obj);
			MYSQL_ROW row;
			if (res)
			{
				while (row = mysql_fetch_row(res))
				{
					add_amount = true;
				}
				mysql_free_result(res);
			}
			else
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
		}
		if (add_amount == true)
		{
			string add_money = "update nmlaccount set balance= balance+'" + to_string(cash) + "'  where account_number = '" + to_string(temp_account_number) + "'";
			if (mysql_query(obj, add_money.c_str()))
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
			else
			{
				if (mysql_affected_rows(obj) > 0)
				{
					cout << cash << " Balance deposited successfully" << endl;
				}
				time_t now = time(nullptr);
				tm localtm;
				localtime_s(&localtm, &now);
				char buffer[80];
				strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localtm);
				string hist = to_string(cash) + " deposited into " + to_string(temp_account_number) + " on " + buffer;
				string deposite_cash = "insert into history(transition_history,account_number,phone,timedate) values('" + hist + "','" + to_string(temp_account_number) + "','" + phone_num + "','" + buffer + "')";
				if (mysql_query(obj, deposite_cash.c_str()))
				{
					cout << "Error :" << mysql_error(obj) << endl;
				}
				else
				{
					MYSQL_RES *res = mysql_store_result(obj);
					MYSQL_ROW row;
					if (res)
					{
						while (row = mysql_fetch_row(res))
						{
							cout << "Transition saved" << endl;
						}
					}
				}
			}
		}
		else
		{
			cout << "Account not found!" << endl;
		}
	}
	mysql_close(obj);
}
void bank::deposite()
{
	system("cls");
	int choice;
	do
	{
		cout << "Select account type" << endl;
		cout << "1)Zero account" << endl;
		cout << "2)Savings" << endl;
		cout << "3)EXIT" << endl;
		cout << "choice :";
		cin >> choice;
		switch (choice)
		{
		case 1:
			deposite_Zero_account();
			break;
		case 2:
			deposite_account();
			break;
		case 3:
			break;
		default:
			cout << "Invalid choice!" << endl;
		}
	} while (choice != 3);
}

// withdraw
void bank::withdraw_zero_account()
{
	string pin_dd;
	int temp_account_number;
	int pin_d, h = 3;
	double cash;
	bool add_amount = false;
	double from_balance;
	bool found_num = false;
	string debit_num;
	system("cls");
	cout << "                                   Withdrawing from savings account" << endl;
	cout << "Enter account number to withdraw :";
	cin >> temp_account_number;
	do
	{
		cout << "Enter phone number :";
		cin >> debit_num;
		if (debit_num.length() != 10)
		{
			cout << "Invalid phone number!" << endl;
			found_num = false;
			continue;
		}
		for (size_t i = 0; i < debit_num.length(); i++)
		{
			if (!isdigit(debit_num[i]))
			{
				cout << "Invalid number!" << endl;
				found_num = false;
			}
			else
			{
				found_num = true;
			}
		}
	} while (!found_num);
	do
	{
		cout << "Enter amount to withdraw :";
		cin >> cash;
		if (cash <= 0)
		{
			cout << "Invalid amount!" << endl;
		}
		else
		{
			break;
		}
	} while (true);
	obj = mysql_init(nullptr);
	if (!mysql_real_connect(obj, host, user, pass, "bank", 3306, NULL, 0))
	{
		cout << "Error :" << mysql_error(obj) << endl;
	}
	else
	{
		// connected
		string line = "select account_number,balance,pin from account where account_number='" + to_string(temp_account_number) + "' and phone='" + debit_num + "'";
		if (mysql_query(obj, line.c_str()))
		{
			cout << "Error :" << mysql_error(obj) << endl;
		}
		else
		{
			MYSQL_RES *res = mysql_store_result(obj);
			MYSQL_ROW row;
			if (res)
			{
				while (row = mysql_fetch_row(res))
				{
					add_amount = true;
					from_balance = stod(row[1]);
					pin_d = stoi(row[2]);
				}
				mysql_free_result(res);
			}
			else
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
		}
		char ch;
		if (add_amount == true)
		{
			do
			{
				pin_dd.clear();
				cout << "Enter account pin :";
				while (true)
				{
					ch = _getch();
					if (ch == '\r')
					{
						break;
					}
					else if (ch == '\b')
					{
						if (!pin_dd.empty())
						{
							pin_dd.pop_back();
							cout << "\b \b";
						}
					}
					else
					{
						pin_dd = pin_dd + ch;
						cout << "*";
					}
				}
				cout << endl;
				if (pin_dd != to_string(pin_d))
				{
					cout << "Invalid pin!" << endl;
					h--;
					if (h == 0)
					{
						cout << "Too many attempts" << endl;
						this_thread::sleep_for(chrono::milliseconds(4000));
						withdraw();
					}
					else
					{
						cout << h << " attempts remaining" << endl;
					}
				}
				else
				{
					break;
				}
			} while (true);
			string withdraw_money = "update account set balance= balance-'" + to_string(cash) + "'  where account_number = '" + to_string(temp_account_number) + "' and phone='" + debit_num + "'";
			if (mysql_query(obj, withdraw_money.c_str()))
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
			else
			{
				if (from_balance > 0 && from_balance >= cash)
				{
					if (mysql_affected_rows(obj) > 0)
					{
						cout << cash << " withdrawed successfully" << endl;
						time_t now = time(nullptr);
						tm localtm;
						localtime_s(&localtm, &now);
						char buffer[80];
						strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localtm);
						string hist = to_string(cash) + " withdrawed from " + to_string(temp_account_number) + " on " + buffer;
						string deposite_cash = "insert into history(transition_history,account_number,phone,timedate) values('" + hist + "','" + to_string(temp_account_number) + "','" + debit_num + "','" + buffer + "')";
						if (mysql_query(obj, deposite_cash.c_str()))
						{
							cout << "Error :" << mysql_error(obj) << endl;
						}
						else
						{
							MYSQL_RES *res = mysql_store_result(obj);
							MYSQL_ROW row;
							if (res)
							{
								while (row = mysql_fetch_row(res))
								{
									cout << "Transition saved" << endl;
								}
							}
						}
					}
				}
				else
				{
					cout << "Insufficent funds!" << endl;
				}
			}
		}
		else
		{
			cout << "Account not found!" << endl;
		}
	}
	mysql_close(obj);
}
void bank::withdraw_account()
{
	string nml_pin;
	int temp_account_number, nml_pinn, h = 3;
	double cash;
	bool add_amount = false;
	double nml_bal;
	string nml_phone;
	bool found_num = false;
	system("cls");
	cout << "                                   Withdrawing from savings account" << endl;
	cout << "Enter account number to withdraw :";
	cin >> temp_account_number;
	do
	{
		cout << "Enter phone number :";
		cin >> nml_phone;
		if (nml_phone.length() != 10)
		{
			cout << "Invalid phone number!" << endl;
			found_num = false;
			continue;
		}
		for (size_t i = 0; i < nml_phone.length(); i++)
		{
			if (!isdigit(nml_phone[i]))
			{
				cout << "Invalid number!" << endl;
				found_num = false;
			}
			else
			{
				found_num = true;
			}
		}
	} while (!found_num);
	do
	{
		cout << "Enter amount to withdraw :";
		cin >> cash;
		if (cash <= 0)
		{
			cout << "Invalid amount!" << endl;
		}
		else
		{
			break;
		}
	} while (true);
	obj = mysql_init(nullptr);
	if (!mysql_real_connect(obj, host, user, pass, "bank", 3306, NULL, 0))
	{
		cout << "Error :" << mysql_error(obj) << endl;
	}
	else
	{
		// connected
		string line = "select account_number,balance,pin from nmlaccount where account_number='" + to_string(temp_account_number) + "' and phone='" + nml_phone + "'";
		if (mysql_query(obj, line.c_str()))
		{
			cout << "Error :" << mysql_error(obj) << endl;
		}
		else
		{
			MYSQL_RES *res = mysql_store_result(obj);
			MYSQL_ROW row;
			if (res)
			{
				while (row = mysql_fetch_row(res))
				{
					add_amount = true;
					nml_bal = stod(row[1]);
					nml_pinn = stoi(row[2]);
				}
				mysql_free_result(res);
			}
			else
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
		}
		char ch;
		if (add_amount == true)
		{
			do
			{
				nml_pin.clear();
				cout << "Enter account pin :";
				while (true)
				{
					ch = _getch();
					if (ch == '\r')
					{
						break;
					}
					else if (ch == '\r')
					{
						if (!nml_pin.empty())
						{
							nml_pin.pop_back();
						}
					}
					else
					{
						nml_pin += ch;
						cout << "*";
					}
				}
				cout << endl;
				if (nml_pin != to_string(nml_pinn))
				{
					cout << "Invalid pin!" << endl;
					h--;
					if (h == 0)
					{
						cout << "Too many attempts!" << endl;
						this_thread::sleep_for(chrono::milliseconds(6000));
						withdraw();
					}
					else
					{
						cout << h << " attempts remaining" << endl;
					}
				}
				else
				{
					break;
				}
			} while (true);
			string withdraw_money = "update nmlaccount set balance= balance-'" + to_string(cash) + "'  where account_number = '" + to_string(temp_account_number) + "' and phone='" + nml_phone + "'";
			if (mysql_query(obj, withdraw_money.c_str()))
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
			else
			{
				if (nml_bal > 0 && nml_bal >= cash)
				{
					if (mysql_affected_rows(obj) > 0)
					{
						cout << cash << " withdrawed successfully" << endl;
						time_t now = time(nullptr);
						tm localtm;
						localtime_s(&localtm, &now);
						char buffer[80];
						strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localtm);
						string hist = to_string(cash) + " withdrawed from " + to_string(temp_account_number) + " on " + buffer;
						string deposite_cash = "insert into history(transition_history,account_number,phone,timedate) values('" + hist + "','" + to_string(temp_account_number) + "','" + nml_phone + "','" + buffer + "')";
						if (mysql_query(obj, deposite_cash.c_str()))
						{
							cout << "Error :" << mysql_error(obj) << endl;
						}
						else
						{
							MYSQL_RES *res = mysql_store_result(obj);
							MYSQL_ROW row;
							if (res)
							{
								while (row = mysql_fetch_row(res))
								{
									cout << "Transition saved" << endl;
								}
							}
						}
					}
				}
				else
				{
					cout << "Insufficent funds!" << endl;
				}
			}
		}
		else
		{
			cout << "Account not found!" << endl;
		}
	}
	mysql_close(obj);
}
void bank::withdraw()
{
	int choice;
	system("cls");
	do
	{
		cout << "Select account type" << endl;
		cout << "1)Zero account" << endl;
		cout << "2)Savings" << endl;
		cout << "3)EXIT" << endl;
		cout << "choice :";
		cin >> choice;
		switch (choice)
		{
		case 1:
			withdraw_zero_account();
			break;
		case 2:
			withdraw_account();
			break;
		case 3:
			break;
		default:
			cout << "Invalid choice" << endl;
		}
	} while (choice != 3);
}
// balance enquiry
void bank::check_zero_balance()
{
	string temp_phone, check_pinn, temp_account;
	int h = 3, check_pin;
	double zero_bal;
	bool found_phone = false;
	bool found_a = false;
	system("cls");
	cout << "                                                        Checking balance" << endl;
	do
	{
		cout << "Enter phone number :";
		cin >> temp_phone;
		if (temp_phone.length() != 10)
		{
			cout << "Invalid phone number!" << endl;
			found_phone = false;
			continue;
		}
		for (size_t i = 0; i < temp_phone.length(); i++)
		{
			if (!isdigit(temp_phone[i]))
			{
				cout << "Invalid phone number!" << endl;
				found_phone = false;
			}
			else
			{
				found_phone = true;
			}
		}
	} while (!found_phone);
	cout << "Enter account number :";
	cin >> temp_account;
	MYSQL *conn;
	conn = mysql_init(0);
	if (!mysql_real_connect(conn, host, user, pass, "bank", 3306, NULL, 0))
	{
		cout << "Error :" << mysql_error(conn) << endl;
	}
	else
	{
		string found_ac = "select balance,pin from account where account_number='" + temp_account + "' and phone='" + temp_phone + "'";
		if (mysql_query(conn, found_ac.c_str()))
		{
			cout << "Error :" << mysql_error(conn) << endl;
		}
		else
		{
			MYSQL_RES *res = mysql_store_result(conn);
			MYSQL_ROW row;
			if (res)
			{
				while (row = mysql_fetch_row(res))
				{
					zero_bal = stod(row[0]);
					check_pin = stoi(row[1]);
					found_a = true;
				}
				mysql_free_result(res);
			}
			else
			{
				cout << "Error :" << mysql_error(conn) << endl;
			}
		}
		if (found_a == true)
		{
			char ch;
			do
			{
				check_pinn.clear();
				cout << "Enter account pin :";
				while (true)
				{
					ch = _getch();
					if (ch == '\r')
					{
						break;
					}
					else if (ch == '\b')
					{
						if (!check_pinn.empty())
						{
							check_pinn.pop_back();
							cout << "\b \b";
						}
					}
					else
					{
						check_pinn += ch;
						cout << "*";
					}
				}
				cout << endl;
				if (check_pinn != to_string(check_pin))
				{
					cout << "Invalid pin!" << endl;
					h--;
					if (h == 0)
					{
						cout << "Too many attempts!" << endl;
						this_thread::sleep_for(chrono::milliseconds(6000));
						check_balance();
					}
					else
					{
						cout << h << " attempts remaining" << endl;
					}
				}
				else
				{
					break;
				}
			} while (true);
			cout << "Balance in " << temp_account << " is :" << zero_bal << endl;
		}
		else
		{
			cout << "Account not found!" << endl;
		}
	}
	mysql_close(conn);
}
void bank::remaining_balance()
{
	string temp_phone, check_pinn, temp_account;
	int h = 3, check_pin;
	double zero_bal;
	bool found_phone = false;
	bool found_a = false;
	system("cls");
	cout << "                                                        Checking balance" << endl;
	do
	{
		cout << "Enter phone number :";
		cin >> temp_phone;
		if (temp_phone.length() != 10)
		{
			cout << "Invalid phone number!" << endl;
			found_phone = false;
			continue;
		}
		for (size_t i = 0; i < temp_phone.length(); i++)
		{
			if (!isdigit(temp_phone[i]))
			{
				cout << "Invalid phone number!" << endl;
				found_phone = false;
			}
			else
			{
				found_phone = true;
			}
		}
	} while (!found_phone);
	cout << "Enter account number :";
	cin >> temp_account;
	MYSQL *conn;
	conn = mysql_init(0);
	if (!mysql_real_connect(conn, host, user, pass, "bank", 3306, NULL, 0))
	{
		cout << "Error :" << mysql_error(conn) << endl;
	}
	else
	{
		string found_ac = "select balance,pin from nmlaccount where account_number='" + temp_account + "' and phone='" + temp_phone + "'";
		if (mysql_query(conn, found_ac.c_str()))
		{
			cout << "Error :" << mysql_error(conn) << endl;
		}
		else
		{
			MYSQL_RES *res = mysql_store_result(conn);
			MYSQL_ROW row;
			if (res)
			{
				while (row = mysql_fetch_row(res))
				{
					zero_bal = stod(row[0]);
					check_pin = stoi(row[1]);
					found_a = true;
				}
				mysql_free_result(res);
			}
			else
			{
				cout << "Error :" << mysql_error(conn) << endl;
			}
		}
		if (found_a == true)
		{
			char ch;
			do
			{
				check_pinn.clear();
				cout << "Enter account pin :";
				while (true)
				{
					ch = _getch();
					if (ch == '\r')
					{
						break;
					}
					else if (ch == '\b')
					{
						if (!check_pinn.empty())
						{
							check_pinn.pop_back();
							cout << "\b \b";
						}
					}
					else
					{
						check_pinn += ch;
						cout << "*";
					}
				}
				cout << endl;
				if (check_pinn != to_string(check_pin))
				{
					cout << "Invalid pin!" << endl;
					h--;
					if (h == 0)
					{
						cout << "Too many attempts!" << endl;
						this_thread::sleep_for(chrono::milliseconds(6000));
						check_balance();
					}
					else
					{
						cout << h << " attempts remaining" << endl;
					}
				}
				else
				{
					break;
				}
			} while (true);
			cout << "Balance in " << temp_account << " is :" << zero_bal << endl;
		}
		else
		{
			cout << "Account not found!" << endl;
		}
	}
	mysql_close(conn);
}
void bank::check_balance()
{
	int choice;
	system("cls");
	do
	{
		cout << "Select account type " << endl;
		cout << "1)Zero account " << endl;
		cout << "2)Savings" << endl;
		cout << "3)EXIT" << endl;
		cout << "Choice :";
		cin >> choice;
		switch (choice)
		{
		case 1:
			check_zero_balance();
			break;
		case 2:
			remaining_balance();
			break;
		case 3:
			break;
		default:
			cout << "Invalid choice" << endl;
		}
	} while (choice != 3);
}
// transfer money
void bank::transfer_from_zero()
{
	// from zero account
	string sender_phone, reciver_phone, acc_pin;
	int sender_acc, reciver_acc, h = 3;
	double money, check_bal;
	;
	char ch;
	bool found_acc_pinn = false;
	bool found_sender_phone = false;
	bool found_reciver_phone = false;
	bool found_sender_ = false;
	bool found_reciver_1 = false;
	bool found_reciver_2 = false;
	bool reciver1 = false;
	bool reciver2 = false;
	system("cls");
	cout << "                                                          Transfering from zero account" << endl;
	obj = mysql_init(nullptr);
	if (!mysql_real_connect(obj, host, user, pass, "bank", 3306, NULL, 0))
	{
		cout << "Error :" << mysql_error(obj) << endl;
	}
	else
	{
		// here the sender accont details
		do
		{
			cout << "Enter sender account number :";
			cin >> sender_acc;
			do
			{
				cout << "Enter sender phone number :";
				cin >> sender_phone;
				if (sender_phone.length() != 10)
				{
					cout << "Invalid phone number!" << endl;
					found_sender_phone = false;
					continue;
				}
				for (size_t i = 0; i < sender_phone.length(); i++)
				{
					if (!isdigit(sender_phone[i]))
					{
						cout << "Invalid phone number!" << endl;
						found_sender_phone = false;
					}
					else
					{
						found_sender_phone = true;
					}
				}
			} while (!found_sender_phone);
			string found_sender_account = "select phone,account_number from account where account_number='" + to_string(sender_acc) + "' and phone='" + sender_phone + "'";
			if (mysql_query(obj, found_sender_account.c_str()))
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
			else
			{
				MYSQL_RES *res = mysql_store_result(obj);
				MYSQL_ROW row;
				if (res)
				{
					while (row = mysql_fetch_row(res))
					{
						found_sender_ = true;
					}
				}
				else
				{
					cout << "Error :" << mysql_error(obj) << endl;
				}
				mysql_free_result(res);
			}
			if (found_sender_ != true)
			{
				cout << "Sender account not founded" << endl;
			}
		} while (!found_sender_);

		// here the reciver account details
		do
		{
			cout << "Enter reciver account number :";
			cin >> reciver_acc;
			do
			{
				cout << "Enter reciver phone number :";
				cin >> reciver_phone;
				if (reciver_phone.length() != 10)
				{
					cout << "Invalid phone number!" << endl;
					found_reciver_phone = false;
					continue;
				}
				for (size_t i = 0; i < reciver_phone.length(); i++)
				{
					if (!isdigit(reciver_phone[i]))
					{
						cout << "Invalid phone number!" << endl;
						found_reciver_phone = false;
					}
					else
					{
						found_reciver_phone = true;
					}
				}
			} while (!found_reciver_phone);
			// from zero account
			string found_reciver_account1 = "select account_number,phone from account where account_number='" + to_string(reciver_acc) + "' and phone='" + reciver_phone + "'";
			if (mysql_query(obj, found_reciver_account1.c_str()))
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
			else
			{
				MYSQL_RES *res = mysql_store_result(obj);
				MYSQL_ROW row;
				if (res)
				{
					while (row = mysql_fetch_row(res))
					{
						found_reciver_1 = true;
						reciver1 = true;
					}
				}
				else
				{
					cout << "Error :" << mysql_error(obj) << endl;
				}
				mysql_free_result(res);
			}
			// from nmlaccunt
			string found_reciver_account2 = "select account_number,phone from nmlaccount where account_number='" + to_string(reciver_acc) + "' and phone='" + reciver_phone + "'";
			if (mysql_query(obj, found_reciver_account2.c_str()))
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
			else
			{
				MYSQL_RES *res = mysql_store_result(obj);
				MYSQL_ROW row;
				if (res)
				{
					while (row = mysql_fetch_row(res))
					{
						found_reciver_2 = true;
						reciver2 = true;
					}
				}
				else
				{
					cout << "Error :" << mysql_error(obj) << endl;
				}
				mysql_free_result(res);
			}
			if (found_reciver_1 != true && found_reciver_2 != true)
			{
				cout << "Reciver account not found" << endl;
			}
		} while (!found_reciver_1 && !found_reciver_2);
		do
		{
			cout << "Enter amount to transfer :";
			cin >> money;
			if (money > 0)
			{
				break;
			}
			else
			{
				cout << "Enter valid amount!" << endl;
			}
		} while (true);
		do
		{
			acc_pin.clear();
			cout << "Enter account pin :";
			while (true)
			{
				ch = _getch();
				if (ch == '\r')
				{
					break;
				}
				else if (ch == '\b')
				{
					if (!acc_pin.empty())
					{
						acc_pin.pop_back();
						cout << "\b \b";
					}
				}
				else
				{
					acc_pin = acc_pin + ch;
					cout << "*";
				}
			}
			cout << endl;
			string found_acc_pin = "select pin from account where account_number='" + to_string(sender_acc) + "' and phone='" + sender_phone + "' and pin='" + (acc_pin) + "'";
			if (mysql_query(obj, found_acc_pin.c_str()))
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
			else
			{
				MYSQL_RES *res = mysql_store_result(obj);
				MYSQL_ROW row;
				if (res)
				{
					while (row = mysql_fetch_row(res))
					{
						found_acc_pinn = true;
					}
				}
				else
				{
					cout << "Error :" << mysql_error(obj) << endl;
				}
				mysql_free_result(res);
			}
			if (found_acc_pinn != true)
			{
				cout << "Incorrect pin!" << endl;
				found_acc_pinn = false;
				h--;
				if (h == 0)
				{
					this_thread::sleep_for(chrono::milliseconds(5000));
					transfer();
				}
				else
				{
					cout << h << " remaining attempts" << endl;
				}
			}
			else
			{
				found_acc_pinn = true;
			}
		} while (!found_acc_pinn);
		string check_balance_ = "select balance from account where  account_number='" + to_string(sender_acc) + "' and phone='" + sender_phone + "'";
		if (mysql_query(obj, check_balance_.c_str()))
		{
			cout << "Error :" << mysql_error(obj) << endl;
		}
		else
		{
			MYSQL_RES *res = mysql_store_result(obj);
			MYSQL_ROW row;
			if (res)
			{
				while (row = mysql_fetch_row(res))
				{
					check_bal = stod(row[0]);
				}
			}
			else
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
			mysql_free_result(res);
			if (check_bal > 0 && check_bal >= money)
			{
				if (reciver1 == true)
				{
					string debit = "update account set balance=balance-'" + to_string(money) + "' where account_number='" + to_string(sender_acc) + "' and phone='" + sender_phone + "'";
					if (mysql_query(obj, debit.c_str()))
					{
						cout << "Error :" << mysql_error(obj) << endl;
					}
					else
					{
						if (mysql_affected_rows(obj) > 0)
						{
							cout << money << " debited from your account " << sender_acc << endl;
							time_t now = time(nullptr);
							tm localtm;
							localtime_s(&localtm, &now);
							char buffer[80];
							strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localtm);
							string hist = to_string(money) + " withdrawed from " + to_string(sender_acc) + " to send to account number" + to_string(reciver_acc) + " on " + buffer;
							string deposite_cash = "insert into history(transition_history,account_number,phone,timedate) values('" + hist + "','" + to_string(sender_acc) + "','" + sender_phone + "','" + buffer + "')";
							if (mysql_query(obj, deposite_cash.c_str()))
							{
								cout << "Error :" << mysql_error(obj) << endl;
							}
							else
							{
								MYSQL_RES *res = mysql_store_result(obj);
								MYSQL_ROW row;
								if (res)
								{
									while (row = mysql_fetch_row(res))
									{
										cout << "Transition saved" << endl;
									}
								}
							}
						}
					}
					string credit = "update account set balance=balance+'" + to_string(money) + "' where account_number='" + to_string(reciver_acc) + "' and phone='" + reciver_phone + "'";
					if (mysql_query(obj, credit.c_str()))
					{
						cout << "Error :" << mysql_error(obj) << endl;
					}
					else
					{
						if (mysql_affected_rows(obj) > 0)
						{
							cout << money << " credited in your account " << reciver_acc << endl;
							time_t now = time(nullptr);
							tm localtm;
							localtime_s(&localtm, &now);
							char buffer[80];
							strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localtm);
							string hist = to_string(money) + " recived from " + to_string(sender_acc) + " on " + buffer;
							string deposite_cash = "insert into history(transition_history,account_number,phone,timedate) values('" + hist + "','" + to_string(reciver_acc) + "','" + reciver_phone + "','" + buffer + "')";
							if (mysql_query(obj, deposite_cash.c_str()))
							{
								cout << "Error :" << mysql_error(obj) << endl;
							}
							else
							{
								MYSQL_RES *res = mysql_store_result(obj);
								MYSQL_ROW row;
								if (res)
								{
									while (row = mysql_fetch_row(res))
									{
										cout << "Transition saved" << endl;
									}
								}
							}
						}
					}
				}
				if (reciver2 == true)
				{
					string debit = "update account set balance=balance-'" + to_string(money) + "' where account_number='" + to_string(sender_acc) + "' and phone='" + sender_phone + "'";
					if (mysql_query(obj, debit.c_str()))
					{
						cout << "Error :" << mysql_error(obj) << endl;
					}
					else
					{
						if (mysql_affected_rows(obj) > 0)
						{
							cout << money << " debited from your account " << sender_acc << endl;
							time_t now = time(nullptr);
							tm localtm;
							localtime_s(&localtm, &now);
							char buffer[80];
							strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localtm);
							string hist = to_string(money) + " withdrawed from " + to_string(sender_acc) + " to send to account number" + to_string(reciver_acc) + " on " + buffer;
							string deposite_cash = "insert into history(transition_history,account_number,phone,timedate) values('" + hist + "','" + to_string(sender_acc) + "','" + sender_phone + "','" + buffer + "')";
							if (mysql_query(obj, deposite_cash.c_str()))
							{
								cout << "Error :" << mysql_error(obj) << endl;
							}
							else
							{
								MYSQL_RES *res = mysql_store_result(obj);
								MYSQL_ROW row;
								if (res)
								{
									while (row = mysql_fetch_row(res))
									{
										cout << "Transition saved" << endl;
									}
								}
							}
						}
					}
					string credit = "update nmlaccount set balance=balance+'" + to_string(money) + "' where account_number='" + to_string(reciver_acc) + "' and phone='" + reciver_phone + "'";
					if (mysql_query(obj, credit.c_str()))
					{
						cout << "Error :" << mysql_error(obj) << endl;
					}
					else
					{
						if (mysql_affected_rows(obj) > 0)
						{
							cout << money << " credited in your account " << reciver_acc << endl;
							time_t now = time(nullptr);
							tm localtm;
							localtime_s(&localtm, &now);
							char buffer[80];
							strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localtm);
							string hist = to_string(money) + " recived from " + to_string(sender_acc) + " on " + buffer;
							string deposite_cash = "insert into history(transition_history,account_number,phone,timedate) values('" + hist + "','" + to_string(reciver_acc) + "','" + reciver_phone + "','" + buffer + "')";
							if (mysql_query(obj, deposite_cash.c_str()))
							{
								cout << "Error :" << mysql_error(obj) << endl;
							}
							else
							{
								MYSQL_RES *res = mysql_store_result(obj);
								MYSQL_ROW row;
								if (res)
								{
									while (row = mysql_fetch_row(res))
									{
										cout << "Transition saved" << endl;
									}
								}
							}
						}
					}
				}
			}
			else
			{
				cout << "Insufficent balance!" << endl;
				this_thread::sleep_for(chrono::milliseconds(4000));
				transfer();
			}
		}
	} // connection database
	mysql_close(obj);
}
void bank::transfer_account()
{
	// from nml account
	string sender_phone, reciver_phone, acc_pin;
	int sender_acc, reciver_acc, h = 3;
	double money, check_bal;
	;
	char ch;
	bool found_acc_pinn = false;
	bool found_sender_phone = false;
	bool found_reciver_phone = false;
	bool found_sender_ = false;
	bool found_reciver_1 = false;
	bool found_reciver_2 = false;
	bool reciver1 = false;
	bool reciver2 = false;
	system("cls");
	cout << "                                                  Transfering from normal account" << endl;
	obj = mysql_init(nullptr);
	if (!mysql_real_connect(obj, host, user, pass, "bank", 3306, NULL, 0))
	{
		cout << "Error :" << mysql_error(obj) << endl;
	}
	else
	{
		// here the sender accont details
		do
		{
			cout << "Enter sender account number :";
			cin >> sender_acc;
			do
			{
				cout << "Enter sender phone number :";
				cin >> sender_phone;
				if (sender_phone.length() != 10)
				{
					cout << "Invalid phone number!" << endl;
					found_sender_phone = false;
					continue;
				}
				for (size_t i = 0; i < sender_phone.length(); i++)
				{
					if (!isdigit(sender_phone[i]))
					{
						cout << "Invalid phone number!" << endl;
						found_sender_phone = false;
					}
					else
					{
						found_sender_phone = true;
					}
				}
			} while (!found_sender_phone);
			string found_sender_account = "select phone,account_number from nmlaccount where account_number='" + to_string(sender_acc) + "' and phone='" + sender_phone + "'";
			if (mysql_query(obj, found_sender_account.c_str()))
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
			else
			{
				MYSQL_RES *res = mysql_store_result(obj);
				MYSQL_ROW row;
				if (res)
				{
					while (row = mysql_fetch_row(res))
					{
						found_sender_ = true;
					}
				}
				else
				{
					cout << "Error :" << mysql_error(obj) << endl;
				}
				mysql_free_result(res);
			}
			if (found_sender_ != true)
			{
				cout << "Sender account not founded" << endl;
			}
		} while (!found_sender_);

		// here the reciver account details
		do
		{
			cout << "Enter reciver account number :";
			cin >> reciver_acc;
			do
			{
				cout << "Enter reciver phone number :";
				cin >> reciver_phone;
				if (reciver_phone.length() != 10)
				{
					cout << "Invalid phone number!" << endl;
					found_reciver_phone = false;
					continue;
				}
				for (size_t i = 0; i < reciver_phone.length(); i++)
				{
					if (!isdigit(reciver_phone[i]))
					{
						cout << "Invalid phone number!" << endl;
						found_reciver_phone = false;
					}
					else
					{
						found_reciver_phone = true;
					}
				}
			} while (!found_reciver_phone);
			// from zero account
			string found_reciver_account1 = "select account_number,phone from nmlaccount where account_number='" + to_string(reciver_acc) + "' and phone='" + reciver_phone + "'";
			if (mysql_query(obj, found_reciver_account1.c_str()))
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
			else
			{
				MYSQL_RES *res = mysql_store_result(obj);
				MYSQL_ROW row;
				if (res)
				{
					while (row = mysql_fetch_row(res))
					{
						found_reciver_1 = true;
						reciver1 = true;
					}
				}
				else
				{
					cout << "Error :" << mysql_error(obj) << endl;
				}
				mysql_free_result(res);
			}
			// from nmlaccunt
			string found_reciver_account2 = "select account_number,phone from account where account_number='" + to_string(reciver_acc) + "' and phone='" + reciver_phone + "'";
			if (mysql_query(obj, found_reciver_account2.c_str()))
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
			else
			{
				MYSQL_RES *res = mysql_store_result(obj);
				MYSQL_ROW row;
				if (res)
				{
					while (row = mysql_fetch_row(res))
					{
						found_reciver_2 = true;
						reciver2 = true;
					}
				}
				else
				{
					cout << "Error :" << mysql_error(obj) << endl;
				}
				mysql_free_result(res);
			}
			if (found_reciver_1 != true && found_reciver_2 != true)
			{
				cout << "Reciver account not found" << endl;
			}
		} while (!found_reciver_1 && !found_reciver_2);
		do
		{
			cout << "Enter amount to transfer :";
			cin >> money;
			if (money > 0)
			{
				break;
			}
			else
			{
				cout << "Enter valid amount!" << endl;
			}
		} while (true);
		do
		{
			acc_pin.clear();
			cout << "Enter account pin :";
			while (true)
			{
				ch = _getch();
				if (ch == '\r')
				{
					break;
				}
				else if (ch == '\b')
				{
					if (!acc_pin.empty())
					{
						acc_pin.pop_back();
						cout << "\b \b";
					}
				}
				else
				{
					acc_pin = acc_pin + ch;
					cout << "*";
				}
			}
			cout << endl;
			string found_acc_pin = "select pin from nmlaccount where account_number='" + to_string(sender_acc) + "' and phone='" + sender_phone + "' and pin='" + (acc_pin) + "'";
			if (mysql_query(obj, found_acc_pin.c_str()))
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
			else
			{
				MYSQL_RES *res = mysql_store_result(obj);
				MYSQL_ROW row;
				if (res)
				{
					while (row = mysql_fetch_row(res))
					{
						found_acc_pinn = true;
					}
				}
				else
				{
					cout << "Error :" << mysql_error(obj) << endl;
				}
				mysql_free_result(res);
			}
			if (found_acc_pinn != true)
			{
				cout << "Incorrect pin!" << endl;
				found_acc_pinn = false;
				h--;
				if (h == 0)
				{
					this_thread::sleep_for(chrono::milliseconds(5000));
					transfer();
				}
				else
				{
					cout << h << " remaining attempts" << endl;
				}
			}
			else
			{
				found_acc_pinn = true;
			}
		} while (!found_acc_pinn);
		string check_balance_ = "select balance from nmlaccount where  account_number='" + to_string(sender_acc) + "' and phone='" + sender_phone + "'";
		if (mysql_query(obj, check_balance_.c_str()))
		{
			cout << "Error :" << mysql_error(obj) << endl;
		}
		else
		{
			MYSQL_RES *res = mysql_store_result(obj);
			MYSQL_ROW row;
			if (res)
			{
				while (row = mysql_fetch_row(res))
				{
					check_bal = stod(row[0]);
				}
			}
			else
			{
				cout << "Error :" << mysql_error(obj) << endl;
			}
			mysql_free_result(res);
			if (check_bal > 1000)
			{
				if (reciver1 == true)
				{
					string debit = "update nmlaccount set balance=balance-'" + to_string(money) + "' where account_number='" + to_string(sender_acc) + "' and phone='" + sender_phone + "'";
					if (mysql_query(obj, debit.c_str()))
					{
						cout << "Error :" << mysql_error(obj) << endl;
					}
					else
					{
						if (mysql_affected_rows(obj) > 0)
						{
							cout << money << " debited from your account " << sender_acc << endl;
							time_t now = time(nullptr);
							tm localtm;
							localtime_s(&localtm, &now);
							char buffer[80];
							strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localtm);
							string hist = to_string(money) + " withdrawed from " + to_string(sender_acc) + " to send to account number" + to_string(reciver_acc) + " on " + buffer;
							string deposite_cash = "insert into history(transition_history,account_number,phone,timedate) values('" + hist + "','" + to_string(sender_acc) + "','" + sender_phone + "','" + buffer + "')";
							if (mysql_query(obj, deposite_cash.c_str()))
							{
								cout << "Error :" << mysql_error(obj) << endl;
							}
							else
							{
								MYSQL_RES *res = mysql_store_result(obj);
								MYSQL_ROW row;
								if (res)
								{
									while (row = mysql_fetch_row(res))
									{
										cout << "Transition saved" << endl;
									}
								}
							}
						}
					}
					string credit = "update nmlaccount set balance=balance+'" + to_string(money) + "' where account_number='" + to_string(reciver_acc) + "' and phone='" + reciver_phone + "'";
					if (mysql_query(obj, credit.c_str()))
					{
						cout << "Error :" << mysql_error(obj) << endl;
					}
					else
					{
						if (mysql_affected_rows(obj) > 0)
						{
							cout << money << " credited in your account " << reciver_acc << endl;
							time_t now = time(nullptr);
							tm localtm;
							localtime_s(&localtm, &now);
							char buffer[80];
							strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localtm);
							string hist = to_string(money) + " recived from " + to_string(sender_acc) + " on " + buffer;
							string deposite_cash = "insert into history(transition_history,account_number,phone,timedate) values('" + hist + "','" + to_string(reciver_acc) + "','" + reciver_phone + "','" + buffer + "')";
							if (mysql_query(obj, deposite_cash.c_str()))
							{
								cout << "Error :" << mysql_error(obj) << endl;
							}
							else
							{
								MYSQL_RES *res = mysql_store_result(obj);
								MYSQL_ROW row;
								if (res)
								{
									while (row = mysql_fetch_row(res))
									{
										cout << "Transition saved" << endl;
									}
								}
							}
						}
					}
				}
				if (reciver2 == true)
				{
					string debit = "update nmlaccount set balance=balance-'" + to_string(money) + "' where account_number='" + to_string(sender_acc) + "' and phone='" + sender_phone + "'";
					if (mysql_query(obj, debit.c_str()))
					{
						cout << "Error :" << mysql_error(obj) << endl;
					}
					else
					{
						if (mysql_affected_rows(obj) > 0)
						{
							cout << money << " debited from your account " << sender_acc << endl;
							time_t now = time(nullptr);
							tm localtm;
							localtime_s(&localtm, &now);
							char buffer[80];
							strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localtm);
							string hist = to_string(money) + " withdrawed from " + to_string(sender_acc) + " to send to account number" + to_string(reciver_acc) + " on " + buffer;
							string deposite_cash = "insert into history(transition_history,account_number,phone,timedate) values('" + hist + "','" + to_string(sender_acc) + "','" + sender_phone + "','" + buffer + "')";
							if (mysql_query(obj, deposite_cash.c_str()))
							{
								cout << "Error :" << mysql_error(obj) << endl;
							}
							else
							{
								MYSQL_RES *res = mysql_store_result(obj);
								MYSQL_ROW row;
								if (res)
								{
									while (row = mysql_fetch_row(res))
									{
										cout << "Transition saved" << endl;
									}
								}
							}
						}
					}
					string credit = "update account set balance=balance+'" + to_string(money) + "' where account_number='" + to_string(reciver_acc) + "' and phone='" + reciver_phone + "'";
					if (mysql_query(obj, credit.c_str()))
					{
						cout << "Error :" << mysql_error(obj) << endl;
					}
					else
					{
						if (mysql_affected_rows(obj) > 0)
						{
							cout << money << " credited in your account " << reciver_acc << endl;
							time_t now = time(nullptr);
							tm localtm;
							localtime_s(&localtm, &now);
							char buffer[80];
							strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localtm);
							string hist = to_string(money) + " recived from " + to_string(sender_acc) + " on " + buffer;
							string deposite_cash = "insert into history(transition_history,account_number,phone,timedate) values('" + hist + "','" + to_string(reciver_acc) + "','" + reciver_phone + "','" + buffer + "')";
							if (mysql_query(obj, deposite_cash.c_str()))
							{
								cout << "Error :" << mysql_error(obj) << endl;
							}
							else
							{
								MYSQL_RES *res = mysql_store_result(obj);
								MYSQL_ROW row;
								if (res)
								{
									while (row = mysql_fetch_row(res))
									{
										cout << "Transition saved" << endl;
									}
								}
							}
						}
					}
				}
			}
			else
			{
				cout << "Insufficent balance!" << endl;
				this_thread::sleep_for(chrono::milliseconds(4000));
				transfer();
			}
		}
	} // connection database
	mysql_close(obj);
}
void bank::transfer()
{
	int choice;
	system("cls");
	do
	{
		cout << "Select account type to send money" << endl;
		cout << "1)Zero account" << endl;
		cout << "2)Non-zero" << endl;
		cout << "3)EXIT" << endl;
		cout << "Choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			transfer_from_zero();
			break;
		case 2:
			transfer_account();
			break;
		case 3:
			break;
		default:
			cout << "Invalid choice" << endl;
		}
	} while (choice != 3);
}
int main()
{
	bank b;
	int choice;
	system("cls");
	do
	{
		cout << "           " << endl;
		cout << "                  " << endl;
		cout << "1)Open zero account" << endl;
		cout << "2)Savings account" << endl;
		cout << "3)Deposite" << endl;
		cout << "4)Withdraw" << endl;
		cout << "5)Check_balance" << endl;
		cout << "6)Transfer money" << endl;
		cout << "7)History" << endl;
		cout << "8)Change upi pin" << endl;
		cout << "9)Close account" << endl;
		cout << "10)EXIT" << endl;
		cout << "Enter choice :";
		cin >> choice;
		switch (choice)
		{
		case 1:
			b.open_zero_account();
			break;
		case 2:
			b.open_account();
			break;
		case 3:
			b.deposite();
			break;
		case 4:
			b.withdraw();
			break;
		case 5:
			b.check_balance();
			break;
		case 6:
			b.transfer();
			break;
		case 7:
			b.history();
			break;
		case 8:
			b.change_upi_pin();
			break;
		case 9:
			b.close_account();
			break;
		case 10:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Invalid choice" << endl;
		}
	} while (choice != 9);
	return 0;
}
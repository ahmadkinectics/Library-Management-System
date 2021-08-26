
//These are the header file
#include <iostream>
#include <csignal>
#include <cctype>
#include <conio.h>
#include <cstdlib>
#include <cmath>
#include <windows.h>
#include <string>
#include<cctype>
#include<functional>
#include<stdio.h>
#include<cstring>
#include<climits>
#pragma warning (disable : 4996)
using namespace std;
int adminMain(void);
int adminMain_book(void);
int adminMain_user(void);
int userMain(void);
int gotoxy(int x, int y);
int developer();
int window();
int change_A_pass();
int finish();
int pass();
int u_pass();
int adminsignup();
int adminsignin();
int get_password(char* pass);
int add_books(void);
int add_window();
int getdata(int choice);
int checkid(int t);
int edit_books();
int search_books();
int searchByID();
int searchByName();
int delete_books();
int view_books();
int add_user(void);
int getdata_user(int choice);
int checkid_user(int t);
int edit_user();
int search_user();
int searchBy_user_ID();
int searchBy_user_Name();
int delete_user();
int view_user();
int user_pass();



//These are global variables
char choice;

char another1;
char another;
int choice27;
char choice1; char choice2; char choice3; char choice4; char choice5; char choice6; char choice7; char choice8; 
char choice9; char choice10; char choice11; char choice12; char choice13; char choice14; char choice15; char choice16; 
char choice17; char choice18; char choice19; char choice20; char choice21; char choice22; char choice23; char choice24; 
char findBook;
char password[10];
int x = 15;
FILE* login;
int temp_passP[25];

//-----------------------------Main Function-----------------------------------------------------
int main()
{
	system("cls");//Clearing the Screen
	window();//Function Call(For title message)

	cout << "\n\t\t\t\t     Login Area";
	cout << "\n\n\t1. Librarian";
	cout << "\n\t2. Student";
	cout << "\n\t3. Developer Info";
	cout << "\n\t4. Exit";

	cout << "\n\n\tEnter your choice: ";

	cin >> choice; //Takes input from keyboard

	system("cls");      //Use to clear Screen
	window();           // for title message

	switch (choice)
	{
	case '1':
	 //Function Call(function for Admin Password)
	     pass();
		adminMain();
		break;

	case '2':
		u_pass();
		break;

	case '3':
		developer();
		break;

	case '4':
		finish();
		break;

	default:
		cout << "\n\tWrong Input! --- Press Again.";
		main();
	}
	return 0;
}

int adminMain(void)//Function for Admin to manage things
{
	system("cls");
	window();

	cout << "\n\t\t\t\tLibrarian Workspace";
	cout << "\n\n\t1. Books Info";
	cout << "\n\t2. Students Info";
	cout << "\n\t3. Change Password";
	cout << "\n\t4. Back";
	cout << "\n\t5. Exit";

	cout << "\n\n\tEnter your choice: ";

	cin >> choice1;

	switch (choice1)
	{
	case '1':
		adminMain_book();
		return 1;
		break;

	case '2':
		adminMain_user();
		break;

	case '3':
		change_A_pass();
		break;

	case '4':
		main();
		break;

	case '5':
		finish();
		break;

	default:
		cout << "\n\tWrong Input!--- Press Again.";
		 adminMain();
	}
}

int adminMain_book(void)
{
	while (1)
	{
		system("cls");
		window();

		cout << "\n\t\t\t\tLibrarian Workspace";
		cout << "\n\n\t1. Add Book";
		cout << "\n\t2. Search Book";
		cout << "\n\t3. Modify Book Record";
		cout << "\n\t4. Delete Book Record";
		cout << "\n\t5. View book list";
		cout << "\n\t6. Back";
		cout << "\n\t7. Exit";

		cout << "\n\n\tEnter your choice: ";

		cin >> choice2;

		switch (choice2)
		{
		case '1':
			add_books();
			break;

		case '2':
			search_books();
			break;

		case '3':
			edit_books();
			break;

		case '4':
			delete_books();
			break;

		case '5':
			view_books();
			break;

		case '6':
			system("cls");
			adminMain();
			break;

		case '7':
			finish();
			break;

		default:
			cout << "\n\tWrong Input!--- Press Again.";
			break;
			adminMain_book();
		}
	}

}

int adminMain_user(void)
{
	while (1)
	{
		system("cls");
		window();

		cout << "\n\t\t\t\tLibrarian Workspace";
		cout << "\n\n\t1. Add Student";
		cout << "\n\t2. Search Student";
		cout << "\n\t3. Modify Student Record";
		cout << "\n\t4. Delete Student Record";
		cout << "\n\t5. View All Students Enrolled";
		cout << "\n\t6. Back";
		cout << "\n\t7. Exit";

		cout << "\n\n\tEnter your choice: ";

		cin >> choice3;

		switch (choice3)
		{
		case '1':
			add_user();
			break;

		case '2':
			search_user();
			break;

		case '3':
			edit_user();
			break;

		case '4':
			delete_user();
			break;

		case '5':
			view_user();
			break;

		case '6':
			adminMain();
			break;

		case '7':
			finish();
			break;

		default:
			cout << "\n\tWrong Input!--- Press Again.";
			break;
			adminMain_user();
		}
	}
}


int userMain(void)
{
	while (1)
	{
		system("cls");
		window();

		cout << "\n\t\t\t\t    Student Area";
		cout << "\n\n\t1. View Book List";
		cout << "\n\t2. Search Book";
		cout << "\n\t3. Back";
		cout << "\n\t4. Exit";

		cout << "\n\n\tEnter your choice: ";

		cin >> choice4;

		switch (choice4)
		{
		case '1':
			view_books();
			break;
		case '2':
			search_books();
			break;

		case '3':
			main();
			break;

		case '4':
			finish();
			break;

		default:
			cout << "\n\tWrong Input!--- Press Again.";
			break;
			userMain();
		}
	}
}


//-----------------------------General Function-----------------------------------------------------
COORD coord = { 0, 0 }; ///set the cordinate to 0, 0 (top-left corner of window);
int gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y; /// X and Y coordinates

	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int developer()// function for show Developer Info
{
	system("cls");
	window();

	cout << "\n\n\t\tDesign and Developed by....";
	cout << "\n\n\t\t* Ahmad Raza(SCME, NUST)";
	cout << "\n\n\t\t* M. Saqib Farooq(SCME, NUST)";

	cout << "\n\n\n\n\t\tSupervised by....";
	cout << "\n\n\t\t* Sir Abid Rauf(SCEECS, NUST)"<<endl;
	cout << "\n\t\t* Mam Sara Mehmood(SCEECS, NUST)"<<endl;
    cout<<"\n\t\tPlease Enter any key to back to Main Menu: ";
	cin >> choice5;
	 return main();
}

int window() // function for showing software info All time on top of screen
{
	cout << "\n**************************** LIBRARY MANAGEMENT SYSTEM ****************************";
	cout << "\t\t\t\t\t\t\t\t\t     SCME, NUST";
	cout << "\n\t______________________________________________________________________";
	return 0;
}

int change_A_pass() // function for Admin Password change
{
	system("cls");
	window();

	FILE* login; //file pointer
	char old_pass[10], new_pass[10];

	cout << "\n\t\t\t\t   Change Password";

	cout << "\n\n\tEnter Old password: ";
	get_password(old_pass);

	cout << "\n\tEnter New password: ";
	get_password(new_pass);

	login = fopen("password.dat", "rb+");

	while (fread(&password, sizeof(password), 1, login) == 1)
	{
		if (strcmp(old_pass, password) == 0)
		{
			strcpy(password, new_pass);

			fseek(login, sizeof(password), SEEK_CUR);
			fwrite(&password, sizeof(password), 1, login);
			fclose(login);

			cout << "\n\n\n\tPassword successfully changed!";
		}
		else
		{
			cout << "\n\n\n\tPassword changing process failed!";
		}
	}
	cout << "\n\n\n\tPress any key to go back...";
	cin >> choice6;
	system("cls");
	window();
	 return adminMain();
}

int finish()// function to Exit Message
{
	system("cls");
	window();

	cout << "\n\n\n\tSure you wanna Exit (Y/N): ";

	cin >> choice7;

	if (choice7 == 'n' || choice7 == 'N')
	{
		system("cls");
		window();
		main();
	}
	else
	{
		system("cls");
		window();

		cout << "\n\n\n\n\t*********************************************************************";
		cout << "\n\t\t\t\t     Thank You";
		cout << "\n\t\t   School of Chemical And Materials Engineering";
		cout << "\n\t*********************************************************************\n\n\n\n\t";
		exit(0);
	}
}

int pass() // function for Admin Password
{    
    
	login = fopen("password.dat", "rb");//fopen() function is used to open a file to perform operations such as reading, writing etc
	
	if (login == NULL)
	{
	 adminsignup();
	}
	else
	{
	 adminsignin();
	}
}

int u_pass() // function for User Password
{
	system("cls");
	window();

	cout << "\n\t\t\t\t     Login Area";
	cout << "\n\n\n\tTo Enter Student Area need your Library ID.";
	cout << "\n\tDo you have Library ID(Y/N): ";

	cin>>choice8;


	if (choice8 == 'N' || choice8 == 'n')
	{
		cout << "\n\tPlease contact with Library Administrator for your Library ID.";
		cout << "\n\n\n\n\n\tPress any key to go back...";
		cin >> choice9;
		system("cls");
		window();
		return main();
	}
	else
	{
		return user_pass();
	}
}

int adminsignup() // Function for save Admin Pass
{
	
    char temp[10];
	login = fopen("password.dat", "wb");

	cout << "\n\t\t\t\t     Login Area";

	cout << "\n\n\n\tDatabase Do not exits. Be an Administrator. Please Sign Up!";
	cout << "\n\n\tEnter password: ";
	
	get_password(password);
    
	cout << "\n\tRe Enter Password: ";
	
	
	
	get_password(temp);
    

	while (strcmp(password, temp) != 0)
	{
		cout << "\n\n\tPassword did not matched! Enter again...";

		cout << "\n\n\tEnter password: ";
		get_password(password);

		cout << "\n\tRe Enter Password: ";
	get_password(temp);

		system("cls");
	}
    
	fwrite(&password, sizeof(password), 1, login);
	fclose(login);

	system("cls");
	 return window();
}


int adminsignin() // function for Admin Login part
{
	char temp[10];

	login = fopen("password.dat", "rb");

	cout << "\n\t\t\t\t     Login Area";


	cout << "\n\n\tEnter password: ";
	get_password(temp);


	while (fread(&password, sizeof(password), 1, login) == 1)
	{
		while (strcmp(temp, password) != 0)
		{
			cout << "\n\n\tPassword did not match!---Enter Again: ";
			get_password(temp);
		}

		cout << "\n\tPassword Match!";
		break;
	}
	fclose(login);

	system("cls");
	return window();
}

int get_password(char* pass) // function for Password

	{
	
	cout<<"please enter  digit"<<endl;
	int i = 0;
	while (1)
	{
		
      temp_passP[i] = getch();
      if (temp_passP[i] == 13)
       {
        break;
       }
		else if (temp_passP[i] == 8)
		{
			if (i != 0)
		{
				cout << "\b \b";
				return 0;
				--i;
			}
			else			
			{
				cout << "\a";
				return 0;
			}
		}
		else
		{
			cout << "*";
			*(pass + i) = temp_passP[i];
			i++;
		}
		*(pass + i) = '\0';
		
		}
	return 0;
}

struct BOOK             //Structure variable for BOOK
{
	int id;
	char name[20];
	char Author[20];
	int quantity;
	float Price;
	int rackno;
	char* cat;
};

struct BOOK book;

char catagories[][15] = { "Mathematics", "Programming", "Physics", "English", "Thermodynamics", "Pak. Studies" };

int add_books(void) //funtion for adding books
{
	system("cls");
	window();

	FILE* fp;
	int i, choice28;

	system("cls");
	window();

	add_window();
	cout << "\n\n\n\tEnter your choice:";
	cin >> choice28;

	if (choice28 == 7)
	{
		adminMain_book();
		return 0;
	}
	system("cls");
	window();

	fp = fopen("Record.dat", "ab+");

	if (getdata(choice27) == 1)
	{
		book.cat = catagories[choice27 - 1];

		fseek(fp, 0, SEEK_END);
		fwrite(&book, sizeof(book), 1, fp);
		fclose(fp);

		cout << "\tThe record is sucessfully saved.";
		cout << "\n\n\tSave any more?(Y/N):";
		cin >> choice11;

		if (choice11 == 'n' || choice11 == 'N')
		{
			system("cls");
			adminMain_book();
			return 0;
		}
		else
		{
			add_books;
			return 0;
		}
	}
	fclose(fp);
}

int add_window() //Function for Books Catagory Interface
{
	system("cls");
	window();
	cout << "\n\t\t\t\t  Books Categories";
	cout << "\n\n\t1. Mathematics";
	cout << "\n\t2. Programming";
	cout << "\n\t3. Physics";
	cout << "\n\t4. English";
	cout << "\n\t5. Thermodynamics";
	cout << "\n\t6. Pak. Studies";
	cout << "\n\t7. Back";
	return 0;
}

int getdata(int choice)
{
	int bookID;


	cout << "\n\t\t\t\t      Details";

	cout << "\n\n\tCategory: ";
	cout << catagories[choice - 1];

	cout << "\n\tBook ID: ";
	cin >> bookID;

	if (book.id == bookID)
	{
		cout << "\n\tId is already Exits.";
		
		add_books();
	}
	else
	{

		book.id = bookID;
		cout << "\tBook Name: ";
		cin >> book.name;

		cout << "\tAuthor: ";
		cin >> book.Author;

		cout << "\tQuantity: ";
		cin >> book.quantity;

		cout << "\tPrice: Rs. ";
		cin >> book.Price;

	}
	return 1;
}

int checkid(int d)      //Function to check ID is exist or not
{
	FILE* temp;

	temp = fopen("Record.dat","rb+");

	while (fread(&book, sizeof(book), 1, temp) == 1)
		if (book.id == d)
		{
			fclose(temp);
			return 0;
		}
	fclose(temp);
	return 1;

}

int edit_books()       //Function to Edit Books info
{
	system("cls");
	window();

	FILE* fp;
	int c = 0, d;

	cout << "\n\t\t\t\tModify Book Record";
	while (1)
	{
		cout << "\n\n\tEnter Book Id to edit: ";
		cin >> d;

		fp = fopen("Record.dat", "rb+");
		while (fread(&book, sizeof(book), 1, fp) == 1)
		{
			if (checkid(d) == 0)
			{
				cout << "\n\n\tThe book is availble.";
				cout << "\n\tThe Book ID: %d", book.id;
				cout << "\n\tNew name: ";
				cin >> book.name;
				cout << "\n\tNew Author: ";
				cin >> book.Author;
				cout << "\n\tNew quantity: ";
				cin >> book.quantity;
				cout << "\n\tNew price: ";
				cin >> book.Price;
				cout << "\n\n\tThe record is modified.";

				fseek(fp, ftell(fp) - sizeof(book), 0);
				fwrite(&book, sizeof(book), 1, fp);
				fclose(fp);

				c = 1;
			}
			if (c == 0)
			{
				cout << "\n\tNo record found";
			}
		}

		cout << "\n\n\tModify another Record?(Y/N)";
		cin >> choice12;
		if (choice12 == 'y' || choice12 == 'Y')
		{
			edit_books();
		}
		else
			adminMain_book();
	}
}

int search_books()  //Function to search books
{
	system("cls");
	window();

	cout << "\n\t\t\t\t    Search Books";
	cout << "\n\n\t1. Search By ID";
	cout << "\n\t2. Search By Name";
	cout << "\n\n\tEnter Your Choice: ";

	cin >> choice13;

	switch (choice13)
	{
	case '1':
		searchByID();
		break;

	case '2':
		searchByName();
		break;

	default:

		search_books();
		break;
	}
	return 0;
}

int searchByID()//Function to search books by given ID
{
	system("cls");
	window();

	int id;
	FILE* fp; //file pointer

	cout << "\n\t\t\t\t Search Books By Id";
	cout << "\n\n\tEnter the book Id: ";
	cin >> id;

	int findBook = 0;

	fp = fopen("Record.dat", "rb");

	while (fread(&book, sizeof(book), 1, fp) == 1)
	{
		if (book.id == id)
		{
			cout << "\n\tThe Book is available.";

			cout << "\n\tBook ID: " << book.id;
			cout << "\n\tBook Name: " << book.name;
			cout << "\n\tAuthor: " << book.Author;
			cout << "\n\tQantity: " << book.quantity;
			cout << "\n\tPrice: Rs." << book.Price;

			findBook = 1;
		}
	}
	if (findBook == 0)//checks whether conditiion enters inside loop or not
	{
		cout << "\n\n\tNo Record Found.";
	}
	fclose(fp);

	cout << "\n\n\tTry another search?(Y/N)";
	cin >> choice14;

	if (choice14 == 'y' || choice14 == 'Y')
	{
		searchByID();
	}
	else
	{
		system("cls");
		window();
	}
	return 0;
}

int searchByName()//Function to search books by using Books name
{
	system("cls");
	window();

	char s[15];
	int d = 0;
	FILE* fp;

	cout << "\n\t\t\t\tSearch Books By Name";
	cout << "\n\n\tEnter Book Name: ";
	cin >> s;

	fp = fopen("Record.dat", "rb");

	while (fread(&book, sizeof(book), 1, fp) == 1)
	{
		if (strcmp(book.name, (s)) == 0)//checks whether book.name is equal to s or not
		{
			cout << "\n\tThe Book is available.";
			cout << "\n\n\tBook ID: " << book.id;
			cout << "\n\tBook Name: " << book.name;
			cout << "\n\Author: " << book.Author;
			cout << "\n\tQantity: " << book.quantity;
			cout << "\n\tPrice: Rs." << book.Price;
			d++;
		}
	}

	if (d == 0)
	{
		cout << "\n\tNo Record Found.";
	}
	fclose(fp);

	cout << "\n\n\tTry another search?(Y/N)";
	cin >> choice15;
	if (choice15 == 'y' || choice15 == 'Y')
	{
		searchByName();
	}
	else
	{
		system("cls");
		window();
	}
	return 0;
}

int delete_books()//function that delete  record form Database
{
	
	system("cls");
	window();

	FILE* ft;
	FILE* fp;

	int d, findBook = 0;
	
		{
				cout << "\n\t\t\t\t    Delete Book";

		cout << "\n\n\tEnter the Book ID to  delete: ";
		cin >> d;

		fp = fopen("Record.dat", "rb+");

		while (fread(&book, sizeof(book), 1, fp) == 1)
		{
			if (book.id == d)
			{
				cout << "\n\n\tThe book record is available.";

				cout << "\n\n\tBook name: " << book.name;
				cout << "\n\tAuthor: " << book.Author;

				findBook = 1;

				cout << "\n\n\tDo you want to delete it?(Y/N):";
				cin >> choice16;

				if (choice16 == 'y' || choice16 == 'Y')
				{
					ft = fopen("test.dat", "wb");  //temporary file for delete

					rewind(fp);

					while (fread(&book, sizeof(book), 1, fp) == 1)
					{
						if (book.id != d)
						{
							fwrite(&book, sizeof(book), 1, ft); //write all in tempory file except that we want to delete
						}
					}
					fclose(fp);
					fclose(ft);

					remove("Record.dat");
					rename("test.dat", "Record.dat"); //copy all item from temporary file to fp except that we want to delete

					cout << "\n\tThe record is sucessfully deleted.";
				}
			}
	}
		if (findBook == 0)
		{
			cout << "\n\tNo record is found.";
		}

		cout << "\n\n\tDelete another record?(Y/N)";
		cin >> choice17;
		
		if (choice17 == 'y' || choice17 == 'Y' )
		{ 
		 cout<<" back to delete books"<<endl;
			delete_books();
		}
		else
		{
			adminMain_book();
		}
		
	}
	
}

int view_books()   //I use this function to view all books info
{
	system("cls");
	window();

	int j = 7;
	FILE* fp;

	cout << "\n\t\t\t\t     Book List";
	cout << "\n\n\tCATEGORY      ID     BOOK NAME            AUTHOR          QTY     PRICE";

	fp = fopen("Record.dat", "rb");

	while (fread(&book, sizeof(book), 1, fp) == 1)
	{
		gotoxy(8, j);
		cout << book.cat;
		gotoxy(22, j);
		cout << book.id;
		gotoxy(29, j);
		cout << book.name;
		gotoxy(50, j);
		cout << book.Author;
		gotoxy(66, j);
		cout << book.quantity;
		gotoxy(74, j);
		cout << book.Price;
		j++;
	}
	
	cout << "\n\n\tPress any key to go back\n";
	int abc; cin>>abc;
	fclose(fp);
    return 0;
	
}
//------------------------------------------------------------------------------------------------------------------

//------------------------------User Releted Function for Admin-----------------------------------------------------
struct USER             //Structure variable for User
{
	int id;
	char name[20];
	char pass[20];
	char tech[10];
	int batch;
};

struct USER user;

int add_user(void)//funtion for adding User
{
	system("cls");
	window();

	FILE* fp;
	int i,

		choice27=0;
	fp = fopen("uRecord.dat", "ab+");
	if (getdata_user(choice27) == 1)
	{
		fseek(fp, 0, SEEK_END);
		fwrite(&user, sizeof(user), 1, fp);
		fclose(fp);

		cout << "\n\n\tThe record is sucessfully saved.";

		cout << "\n\n\n\tSave any more?(Y/N)";
		cin >> choice18;

		if (choice18 == 'n' || choice18 == 'N')
		{
			system("cls");
			window();
			adminMain_user();
		}
		else
		{
			add_user();
		}
		return 0;
	}
	fclose(fp);
}

int getdata_user(int choice)
{
	int userID;
	cout << "\n\t\t\t\tStudent Information";

	cout << "\n\n\tUser ID: ";
	cin >> userID;

	if (user.id == userID)
	{
		cout << "\n\n\tId already Exist.";
	
		add_user();
	}
	else
	{
		user.id = userID;
		cout << "\tUser Name: ";
		cin >> user.name;
		cout << "\tPassword: ";
		cin >> user.pass;
		cout << "\tClass: ";
		cin >> user.tech;
		cout << "\tBatch: ";
		cin >> user.batch;
	}
	return 1;
}

int checkid_user(int t)      //Function to check ID is exist or not
{
	FILE* temp;

	temp = fopen("uRecord.dat", "rb+");

	while (fread(&user, sizeof(user), 1, temp) == 1)
		if (user.id == t)
		{
			fclose(temp);
			return 0;
		}
	fclose(temp);

	return 1;
}

int edit_user()       //Function to Edit User info
{
	system("cls");
	window();

	FILE* fp;
	int c = 0, d;

	cout << "\n\t\t\t     Edit Student Information";

	while (1)
	{
		cout << "\n\n\tEnter Student Id to edit: ";
		cin >> d;

		fp = fopen("uRecord.dat", "rb+");

		while (fread(&user, sizeof(user), 1, fp) == 1)
		{
			if (checkid_user(d) == 0)
			{
				cout << "\n\n\tThe User is availble.";
				cout << "\n\n\tThe User ID: " << user.id;
				cout << "\n\tNew Name: ";
				cin >> user.name;
				cout << "\tPassword: ";
				cin >> user.pass;
				cout << "\tClass: ";
				cin >> user.tech;
				cout << "\tBatch: ";
				cin >> user.batch;

				cout << "\tThe record is modified.";

				fseek(fp, ftell(fp) - sizeof(user), 0);
				fwrite(&user, sizeof(user), 1, fp);
				fclose(fp);

				c = 1;
			}

			if (c == 0)
			{
				cout << "\n\n\tNo record found.";
			}
		}

		cout << "\n\n\tModify another Record?(Y/N)";
		cin >> choice19;
		if (choice19 == 'y' || choice19 == 'Y')
		{
			edit_user();
		}
		else
		{
			adminMain_user();
		}
	}
}

int search_user()//Function to search user
{
	system("cls");
	window();

	cout << "\n\t\t\t\t   Search Student";
	cout << "\n\n\t1. Search By ID";
	cout << "\n\t2. Search By Name";

	cout << "\n\n\tEnter Your Choice: ";
	cin >> choice20;

	switch (choice20)
	{
	case '1':
		searchBy_user_ID();
		break;
	case '2':
		searchBy_user_Name();
		break;
	default:
		 search_user();
	}
	return 0;
}

int searchBy_user_ID()//Function to search user by given ID
{
	system("cls");
	window();

	int id;
	FILE* fp;

	cout << "\n\t\t\t\t    Search By Id";

	cout << "\n\n\tEnter the Student Id: ";
	cin >> id;

	int findUser = 0;

	fp = fopen("uRecord.dat", "rb");

	while (fread(&user, sizeof(user), 1, fp) == 1)
	{
		if (user.id == id)
		{
			cout << "\n\n\tThe user is available.";
			cout << "\n\n\tStudent ID: " << user.id;
			cout << "\n\tName: " << user.name;
			cout << "\n\tPassword:  " << user.pass;
			cout << "\n\tClass: " << user.tech;
			cout << "\n\tBatch: " << user.batch;

			findUser = 1;
		}
	}
	if (findUser == 0)//checks whether conditiion enters inside loop or not
	{
		cout << "\n\n\tNo Record Found";
	}
	fclose(fp);

	cout << "\n\n\tTry another search?(Y/N)";
	cin >> choice21;

	if (choice21 == 'y' || choice21 == 'Y')
	{
		searchBy_user_ID();
	}
	else
	{
		adminMain_user();
	}
	return 0;
}


int searchBy_user_Name() //Function to search user by name
{
	system("cls");
	window();

	char s[15];
	int d = 0;

	FILE* fp;

	cout << "\n\t\t\t\t   Search By Name";
	cout << "\n\n\tEnter Student Name: ";
	cin >> s;

	fp = fopen("uRecord.dat", "rb");

	while (fread(&user, sizeof(user), 1, fp) == 1)
	{
		if (strcmp(user.name, (s)) == 0)//checks whether user.name is equal to s or not
		{
			cout << "\n\n\tThe User is available.";
			cout << "\n\n\tStudent ID: " << user.id;
			cout << "\n\tName: " << user.name;
			cout << "\n\tPassword: " << user.pass;
			cout << "\n\tClass: " << user.tech;
			cout << "\n\tBatch: " << user.batch;

			d++;
		}
	}
	if (d == 0)
	{
		cout << "\n\tNo Record Found.";
	}
	fclose(fp);

	cout << "\n\n\tTry another search?(Y/N)";
	cin >> choice22;

	if (choice22 == 'y' || choice22 == 'Y')
	{
		searchBy_user_Name();
	}
	else
	{
		adminMain_user();
	}
	return 0;
}


int delete_user()//function that delete record form Database
{
	system("cls");
	window();

	FILE* ft, * fp;

	
	int d, findUser = 0;


	{
		cout << "\n\t\t\t\t   Delete Student";
		cout << "\n\n\tEnter the Student ID to delete: ";
		cin >> d;

		fp = fopen("uRecord.dat", "rb+");

		while (fread(&user, sizeof(user), 1, fp) == 1)
		{
			if (user.id == d)
			{
				cout << "\n\n\tThe user record is available.";
				cout << "\n\n\tName: " << user.name;
				cout << "\n\tClass: " << user.tech;
				cout << "\n\tBatch: " << user.batch;

				findUser = 1;

				cout << "\n\n\tDo you want to delete it?(Y/N) ";
				cin >> choice23;
				if (choice23 == 'y' || choice23 == 'Y')
				{
					ft = fopen("utest.dat", "wb");  //temporary file for delete

					rewind(fp);

					while (fread(&user, sizeof(user), 1, fp) == 1)
					{
						if (user.id != d)
						{
							fwrite(&user, sizeof(user), 1, ft); //write all in tempory file except that we want to delete
						}
					}
					fclose(fp);
					fclose(ft);

					remove("uRecord.dat");
					rename("utest.dat", "uRecord.dat"); //copy all item from temporary file to fp except that we want to delete

					cout << "\n\n\tThe record is sucessfully deleted.";
				}
			}
		}
		if (findUser == 0)
		{
			cout << "\n\n\tNo record is found.";
		}

		cout << "\n\n\tDelete another record?(Y/N)";
		cin >> choice24;

		if (choice24 == 'y' || choice24 == 'Y')
		{
			delete_user();
		}
		else
		{
			adminMain_user();
		}
	}
	return 0;
}

int view_user()   //I use this function to view all user info
{
	system("cls");
	window();

	int j = 7;
	FILE* fp;

	cout << "\n\t\t\t\t   Students List";

	cout << "\n\n\tID   Student Name     Password   Class    Batch";

	fp = fopen("uRecord.dat", "rb");

	while (fread(&user, sizeof(user), 1, fp) == 1)
	{
		gotoxy(8, j);
		cout << user.id;
		gotoxy(13, j);
		cout << user.name;
		gotoxy(30, j);
		cout << user.pass;
		gotoxy(40, j);
		cout << user.tech;
		gotoxy(50, j);
		cout << user.batch;
		cout << "\n";
		j++;
	}
	cout<"please enter any key to go back: ";
	int def;
	cin>>def;
	fclose(fp);
	return 0;
	
}

int user_pass()//function that delete  record form Database
{
	system("cls");
	window();
    	
    
	FILE* ft, * fp;
	int d, findUser = 0;

	while (1)//infinite loop
	{
		cout << "\n\t\t\t\tStudent Login";
		cout << "\n\n\tEnter the User ID:";
		cin >> d;

		fp = fopen("uRecord.dat", "rb+");

		while (fread(&user, sizeof(user), 1, fp) == 1)
		{
			if (user.id == d)
			{
				cout << "\n\tThe student record is available.";
				cout << "\n\tName: " << user.name;

				char p[20];
				cout << "\n\tEnter Your Password:";
				cin >> p;

				if (strcmp(user.pass, (p)) == 0)
				{
					cout << "\n\tThank You!";
					
					userMain();
				}
				else
				{
					cout << "\n\tWrong Password!";
	
					main();
				}
			}
		}
		if (findUser == 0)
		{
			cout << "\n\n\tNo Record is found!";
			
			system("cls");
			window();
			main();
		}
	}
}



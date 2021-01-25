#include<fstream>
#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
char d;
char e;
char t;
class qw {
private:
	int n;
	string name;
	double mark_physic;
	double mark_chemcrity;
	double mark_maths;
	double mark_english;
	double mark_computerscience;
public:
	void createstudentname() {
		cout << "enter the roll number of steudent :";
		cin >> n;
		cout << "enter the name of the student :";
		cin >> name;
		cout << "enter the grade number of physic :";
		cin >> mark_physic;
		cout << "enter the grade number of chemcrity:";
		cin >> mark_chemcrity;
		cout << "enter the grade number of maths :";
		cin >> mark_maths;
		cout << "enter the grade number of english :";
		cin >> mark_english;
		cout << "enter the grade number of computerscience :";
		cin >> mark_computerscience;
	}
	void display() {

		cout << "enter the roll number of steudent :" << n << endl;
		                                             
		cout << "enter the name of the student " << name << endl;

		cout << "enter the grade number of physic :" << mark_physic << endl;

		cout << "enter the grade number of chemcrity:" << mark_chemcrity << endl;

		cout << "enter the grade number of maths :" << mark_maths << endl;

		cout << "enter the grade number of english :" << mark_english << endl;

		cout << "enter the grade number of computerscience :" << mark_computerscience << endl;

	}
	void main_menu() {
		cout << "welcome to system of acount student " << endl;
		cout << "\n" << endl;
		cout << "this system made by c++ language " << endl;
		cout << "\n" << endl;
		cout << "the team is AAKM  " << endl;
		cout << "the team leader is  Abdo Fawzy" << endl;
		cout << "team members are Mina nashta \t Abdo Fawzy \t Kerolos Adel \t Mohamed Alhoseny  " << endl;
	    
		if (cin.get() == '\n') {
			system("cls");
		}
	}
	void min1() {
		cout << "A. Result manu " << endl;
		cout << "B.entry / edit menue " << endl;
		cout << "c. Exit " << endl;
		cout << "choose form thw menu (a/b/c):";
		cin >> d;
		if (cin.get() == '\n') {
			system("cls");
		}
	}
	void min2() {
		cout << "A. class result " << endl;
		cout << "B. student report card " << endl;
		cout << "c. Back to the main menu " << endl;
	}
	void min3() {
		cout << "1.create student records" << endl;
		cout << "2.display all student record" << endl;
		cout << "3.search student record" << endl;
		cout << "4.delete the strudent record" << endl;
		cout << "5.modify the strudent record" << endl;
		cout << "6.Back to the main menu " << endl;
	}
	int num() { return n; }
	string names() { return name; }
	double physic() { return mark_physic; }
	double chemcrity() { return mark_chemcrity; }
	double maths() { return mark_maths; }
	double english() { return mark_english; }
	double computerscience() { return mark_computerscience; }
};
qw pro;
fstream ff;
void write() {
	ff.open("asd.txt", ios::out | ios::app);
	pro.createstudentname();
	ff.write((char*)&pro, sizeof(qw));
	ff.close();
	cout << "the acount was created" << endl;
	if (cin.get() == '\n') {
	
	}
}
void displaya() {
	ff.open("asd.txt", ios::in);
	while (ff.read((char*)&pro, sizeof(qw))) {
		pro.display();
		if (cin.get() == '\n') {
		}
	}
	ff.close();
	if (cin.get() == '\n') {
		system("cls");
	}
}
void search() {
	int er;
	cout << "enter the number of roll ";
	cin >> er;
	int falg = 0;
	ff.open("asd.txt", ios::in);
	while (ff.read((char*)&pro, sizeof(qw))) {
		if (pro.num() == er)
		{
			pro.display();
			falg = 1;
		}
	}
	ff.close();
	if (falg == 0) {
		cout << "\n not found \n" << endl;
		

	}
	if (cin.get() == '\n') {
	
	}
}
void deleted() {
	int we;
	cout << "enter the roll you want to delete" << endl; cin >> we;
	ff.open("asd.txt", ios::out | ios::in);
	fstream df;
	df.open("asd2.txt", ios::out);
	ff.seekg(0, ios::beg);
	while (ff.read((char*)&pro, sizeof(qw))) {
		if (pro.num() != we) {
			df.write((char*)&pro, sizeof(qw));
		}
	}
	ff.close();
	df.close();
	remove("asd.txt");
	rename("asd2.txt", "asd.txt");
	cout << "product is deleted" << endl;
	cout << "\n            ====            \n" << endl;
	if (cin.get() == '\n') {
		
	}
}
void mofify() {
	int we;
	cout << "enter the roll you want to modify" << endl; cin >> we;
	ff.open("asd.txt", ios::out | ios::in);
	fstream df;
	df.open("asd2.txt", ios::out);
	ff.seekg(0, ios::beg);
	while (ff.read((char*)&pro, sizeof(qw))) {
		if (pro.num() != we) {
			df.write((char*)&pro, sizeof(qw));
		}
	}
	ff.close();
	df.close();
	remove("asd.txt");
	rename("asd2.txt", "asd.txt");
	write();
}
void classq() {
	displaya();
}
void studentrecordcard() {
	search();
	if (cin.get() == '\n') {
		system("cls");
	}
}
void qe() {
	pro.min1();
	switch (d) {
	case'a':
		pro.min2();
		cout << "shoose from the  menu (a/b/c)";
		cin >> t;
		switch (t) {
		case 'a':
			system("cls");
			classq();
			break;
		case'b':
			system("cls");
			studentrecordcard();
		  system("cls");
			
			break;
		case 'c':
			qe();
			break;
		default:cout << "error" << endl;
		}
		break;
	case'b':
		pro.min3();
		cout << "choose form the meue (1/2/3/4/5/6) ";
		cin >> e;
		if (cin.get() == '\n') {
			system("cls");
		}
		switch (e) {
		case '1':
			system("cls");
			write();
			system("cls");
			break;
		case '2':
			system("cls");
			displaya();
			break;

		case'3':
			system("cls");
			search();

		case '4':
			system("cls");
			deleted();
			break;
		case '5':
			system("cls");
			mofify();
			break;
		case '6':
			qe();
			break;
		default:cout << "error" << endl;
		}
	case'c':
		exit(0);
		break;
	default:cout << "Error" << endl;
	}
}
int main() {
	cout << "========================================= main menu ====================================" << endl;
	pro.main_menu();
	do {
		pro.min1();
		switch (d) {
		case'a':
			pro.min2();
			cout << "shoose from the  menu (a/b/c)";
			cin >> t;
			if (cin.get() == '\n') {
				system("cls");
			}
			switch (t) {
			case 'a':
				classq();

				break;
			case'b':
				studentrecordcard();
				break;
			case 'c':
				qe();
				break;
			default:cout << "error" << endl;
			}
			break;
		case'b':
			pro.min3();
			cout << "choose form the meue (1/2/3/4/5/6) ";
			cin >> e;
			if (cin.get() == '\n') {
				system("cls");
			}
			switch (e) {
			case '1':
				system("cls");
				write();
				if (cin.get() == '\n') {
					system("cls");
				}
				break;
			case '2':
				system("cls");
				displaya();
				break;

			case'3':
				system("cls");
				search();
				if (cin.get() == '\n') {
					system("cls");
				}
				break;
			case '4':
				system("cls");
				deleted();
				if (cin.get() == '\n') {
					system("cls");
				}
				break;
			case '5':
				system("cls");
				mofify();
				if (cin.get() == '\n') {
					system("cls");
				}
				break;
			case '6':
				qe();
				break;
			default:cout << "error" << endl;
			}
			break;
		case'c':
			exit(0);
			break;

		default:cout << "Error" << endl;
		}
	} while (d != '7');
	return 0;
}



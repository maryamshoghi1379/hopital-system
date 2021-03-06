// جلسه 7 و 8 پروژه بیمارستان.cpp : Defines the entry point for the console application.
//
//+++++++++++++++++++++++++++        *              ++++++++++++++++++++++++
//+++++++++++++++++++++++++++  HOSPITAL  PROJECT   +++++++++++++++++++++++++
//+++++++++++++++++++++++++++        *              ++++++++++++++++++++++++
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include < map >
#include <iomanip>
#include <fstream>
using namespace std;
//+++++++++++++++++++++++++++      *          ++++++++++++++++++++++++
//+++++++++++++++++++++++++++ CLASS PERSON   +++++++++++++++++++++++++
//+++++++++++++++++++++++++++      *          ++++++++++++++++++++++++
multimap<string , string> p_list_unik;
class Person
{
protected:

	string person_firstname, person_lastname, national_code, phone;
	int person_age;
public:
	Person() {}
	Person(string person_firstname, string person_lastname, string national_code, string phone, int person_age)
	{
		(*this).person_firstname = person_firstname;
		(*this).person_lastname = person_lastname;
		(*this).phone = phone;
		(*this).person_age = person_age;
		(*this).national_code = national_code;

	}
	void set_person_firstname(string person_firstname)
	{
		(*this).person_firstname = person_firstname;
	}
	void set_person_lastname(string  person_lastname)
	{
		(*this).person_lastname = person_lastname;
	}
	void set_national_code(string national_code)
	{
		(*this).national_code = national_code;
	}
	void set_phone(string phone)
	{
		(*this).phone = phone;
	}
	void set_person_age(int person_age)
	{
		(*this).person_age = person_age;
	}
	string get_person_firstname() const
	{
		return person_firstname;
	}
	string get_person_lastname() const
	{
		return person_lastname;
	}
	string get_national_code() const
	{
		return national_code;
	}
	string get_phone() const
	{
		return phone;
	}
	int get_person_age() const
	{
		return person_age;
	}
	virtual void printt_person() const
	{
		cout << person_firstname << setw(8) << " " << person_lastname << setw(8) << " " << national_code << setw(8) << " " << phone << setw(8) << " " << person_age << endl;
	}
};
//+++++++++++++++++++++++++++        *          ++++++++++++++++++++++++
//+++++++++++++++++++++++++++  CLASS PATIENT   +++++++++++++++++++++++++
//+++++++++++++++++++++++++++        *         +++++++++++++++++++++++++
class Patient : public Person
{

private:
	string patient_problem, name_of_doctor;
	int patient_room, patient_id;


public:
	Patient() {}
	Patient(string person_firstname, string person_lastname, string national_code, string phone, int person_age, int patient_id, string patient_problem, int patient_room, string name_of_doctor) :Person(person_firstname, person_lastname, national_code, phone, person_age)
	{
		this->patient_id = patient_id;
		this->patient_problem = patient_problem;
		this->patient_room = patient_room;
		this->name_of_doctor = name_of_doctor;
	}

	void setpatient_problem(string patient_problem)
	{
		this->patient_problem = patient_problem;
	}
	void setpatient_room(int patient_room)
	{
		this->patient_room = patient_room;
	}
	void setpatient_id(int patient_id)
	{
		this->patient_id = patient_id;
	}
	void setname_of_doctor(string  name_of_doctor)
	{
		this->name_of_doctor = name_of_doctor;
	}
	string getpatient_problem()const
	{
		return patient_problem;
	}
	int getpatient_room()const
	{
		return patient_room;
	}
	int getpatient_id()const
	{
		return patient_id;
	}
	string getname_of_doctor() const
	{
		return name_of_doctor;
	}
	void printt_person() const override
	{
		cout << person_firstname << setw(8) << " " << person_lastname << setw(8) << " " << national_code << setw(8) << " " << phone << setw(8) << " " << person_age << setw(8) << " " << patient_id << setw(8) << " " << patient_room << setw(8) << " " << patient_problem << setw(8) << " " << name_of_doctor << endl;
	}

};
//+++++++++++++++++++++++++++      *          +++++++++++++++++++++++
//+++++++++++++++++++++++++++  CLASS DOCTOR  ++++++++++++++++++++++++
//+++++++++++++++++++++++++++      *          +++++++++++++++++++++++
class Doctor : public Person
{
private:
	string doctor_specialty;
	int doctor_room, doctor_id;
public:
	Doctor() {}
	Doctor(string person_firstname, string person_lastname, string national_code, string phone, int person_age, string doctor_specialty, int doctor_room, int doctor_id) :Person(person_firstname, person_lastname, national_code, phone, person_age)
	{
		this->doctor_specialty = doctor_specialty;
		this->doctor_room = doctor_room;
		this->doctor_id = doctor_id;

	}
	void setdoctor_specialty(string doctor_specialty)
	{
		this->doctor_specialty = doctor_specialty;
	}
	void setdoctor_room(int doctor_room)
	{
		this->doctor_room = doctor_room;
	}
	void setdoctor_id(int  doctor_id)
	{
		this->doctor_id = doctor_id;
	}
	string getdoctor_specialty()const
	{
		return doctor_specialty;
	}
	int getdoctor_room()const
	{
		return doctor_room;
	}
	int getdoctor_id()const
	{
		return  doctor_id;
	}
	void printt_person() const override
	{
		cout << person_firstname << setw(4) << " " << person_lastname << setw(8) << " " << national_code << setw(2) << " " << phone << setw(2) << " " << person_age << setw(2) << " " << doctor_id << setw(2) << " " << doctor_specialty << setw(2) << " " << doctor_room << endl;
	}
};
//+++++++++++++++++++++++++++        *          ++++++++++++++++++++++++
//+++++++++++++++++++++++++++  CLASS PATIENT   +++++++++++++++++++++++++
//+++++++++++++++++++++++++++        *         +++++++++++++++++++++++++
vector<Patient>list_patient, list2_patient;
fstream outputpatient_list;
void write_patient()
{
	int person_age, patient_room, patient_id, tr = 0;
	string patient_problem, person_firstname, person_lastname, national_code, phone, name_of_doctor;
	do {
		cout << "Please enter person_firstname :)" << endl;
		cin >> person_firstname;
		cout << "Please enter person_lastname :)" << endl;
		cin >> person_lastname;
		cout << "Please enter person_age :)" << endl;
		cin >> person_age;
		cout << "Please enter national_code  :)" << endl;
		cin >> national_code;
		cout << "Please enter patient_id :)" << endl;
		cin >> patient_id;
		cout << "Please enter  phone :)" << endl;
		cin >> phone;
		cout << "Please enter patient_room :)" << endl;
		cin >> patient_room;
		cout << "Please enter patient_problem :)" << endl;
		cin >> patient_problem;
		cout << "Please enter  name_of_doctor   :)" << endl;
		cin >> name_of_doctor;
		cout << "Please enter  1 to  exit   :)" << endl;
		cin >> tr;
		list_patient.push_back(Patient(person_firstname, person_lastname, national_code, phone, person_age, patient_id, patient_problem, patient_room, name_of_doctor));
		outputpatient_list.open("patient.CSV", ios::app);
		outputpatient_list << person_firstname + "," + person_lastname + "," + to_string(person_age) + "," + national_code + "," + patient_problem + "," + to_string(patient_room) + "," + to_string(patient_id) + "," + name_of_doctor << endl;
	} while (tr != 1);
}
void displayall_patient()
{
	system("cls");
	cout << "+++++++++++++++++++++LIST_OF_ALL_PATIENTS++++++++++++++++++++++"<<endl;
	int a = list_patient.size();
	for (int i = 0; i < a; i++)
	{
		list_patient[i].printt_person();
	}

}
void displayOne_patient(int patient_id)
{
	system("cls");
	cout << "+++++++++++++++++++++LIST_OF_ONE_PATIENT++++++++++++++++++++++"<<endl;
	int a = list_patient.size();
	for (int i = 0; i < a; i++)
	{
		if (list_patient[i].getpatient_id() == patient_id)
		{
			list_patient[i].printt_person();
		}
	}

}
void modify_patient(int patient_id)
{
	int person_age, patient_room, choice;
	string patient_problem, person_firstname, person_lastname, national_code, phone, name_of_doctor;
	int a = list_patient.size();
	for (int i = 0; i < a; i++)
	{
		if (list_patient[i].getpatient_id() == patient_id)
		{
			do {
				cout << "+++++++++++++++++++++MODIFY_PATIENT_MENU++++++++++++++++++++++" << endl;
				cout << " 1)PATIENT PROBLEM " << endl;
				cout << " 2)PATIENT_ROOM " << endl;
				cout << " 3)person_firstname " << endl;
				cout << " 4)person_lastname " << endl;
				cout << " 5)person_age " << endl;
				cout << " 6)national_code " << endl;
				cout << " 7)phone  " << endl;
				cout << " 8)name_of_doctor" << endl;
				cout << " 9)Please enter 10 to exit !" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:cout << "Enter new patient_problem :)"; cin >> patient_problem; list_patient[i].setpatient_problem(patient_problem); break;
				case 2:cout << "Enter new patient_room :)"; cin >> patient_room; list_patient[i].setpatient_room(patient_room); break;
				case 3:cout << "Enter new person_firstname :) "; cin >> person_firstname; list_patient[i].set_person_firstname(person_firstname); break;
				case 4:cout << "Enter new person_lastname :)"; cin >> person_lastname; list_patient[i].set_person_lastname(person_lastname); break;
				case 5:cout << "Enter new person_age :)"; cin >> person_age; list_patient[i].set_person_age(person_age); break;
				case 6:cout << "Enter new national_code :)"; cin >> national_code; list_patient[i].set_national_code(national_code); break;
				case 7:cout << "Enter new phone :)"; cin >> phone; list_patient[i].set_phone(phone); break;
				case 8:cout << "Enter new name_of_doctor :)"; cin >> name_of_doctor; list_patient[i].setname_of_doctor(name_of_doctor); break;
				case 9:break;
				}

			} while (choice == 10);
		}
	}
}
void deleteall_patient() { list_patient.clear(); }

void deleteone(int patient_id)
{
	int a = list_patient.size();
	for (int i = 0; i < a; i++)
	{
		if (list_patient[i].getpatient_id() != patient_id)
		{
			list2_patient.push_back(list_patient[i]);
		}
	}
	list_patient = list2_patient;
	vector<Patient>().swap(list2_patient);
}
void pdlist(string name_of_doctor)
{
	for (multimap<string, string>::iterator it = p_list_unik.begin(); it != p_list_unik.end(); it++) {
		if (name_of_doctor == it->first)
		{
			cout << it->second << endl;
		}
	}
}
void list_of_doctor_of_patient()
{
	string name_of_doctor;
	cout << "Enter Doctor_name (without any space):";
	cin >> name_of_doctor;
	int a = list_patient.size();
	for (int i = 0; i < a; i++)
	{
		p_list_unik.insert(pair<string, string>(list_patient[i].getname_of_doctor(), list_patient[i].get_person_firstname() + " " + list_patient[i].get_person_lastname()));
	}
	pdlist(name_of_doctor);
}
//+++++++++++++++++++++++++++        *          +++++++++++++++++++++++
//+++++++++++++++++++++++++++  CLASS DOCTOR   +++++++++++++++++++++++++
//+++++++++++++++++++++++++++        *         ++++++++++++++++++++++++
vector<Doctor>list1;
vector<Doctor>list2;
void write_Doctor() {
	string  person_firstname, person_lastname, phone, national_code, doctor_specialty;
	int person_age, doctor_id, m, doctor_room;
	do {
		cout << "Please enter person_firstname :)" << endl;
		cin >> person_firstname;
		cout << "Please enter person_lastname :)" << endl;
		cin >> person_lastname;
		cout << "Please enter national_code :)" << endl;
		cin >> national_code;
		cout << "Please enter person_age :)" << endl;
		cin >> person_age;
		cout << "Please enter doctor_id :)" << endl;
		cin >> doctor_id;
		cout << "Please enter doctor_specialty :)" << endl;
		cin >> doctor_specialty;
		cout << "Please enter phone :)" << endl;
		cin >> phone;
		cout << "Please enter doctor_room :)" << endl;
		cin >> doctor_room;
		cout << "Please enter 3 to end !"<< endl;
		cin >> m;
		list1.push_back(Doctor(person_firstname, person_lastname, national_code, phone, person_age, doctor_specialty, doctor_room, doctor_id));
		outputpatient_list.open("doctor.CSV", ios::app);
		outputpatient_list << to_string(doctor_id)+","+person_firstname + "," + person_lastname + "," + phone + "," + national_code + "," + to_string(person_age) + "," + doctor_specialty + "," + to_string(person_age);
		cout << endl;
	} while (m != 3);
}
void displayalldo() {
	system("cls");
	cout << "+++++++++++++++++++++LIST_OF_DOCTORS++++++++++++++++++++++" << endl;
	int x = list1.size();
	for (int i = 0; i < x; i++)
	{
		list1[i].printt_person();
	}
}
void displaydo(int doctor_id)
{
	system("cls");
	cout << "+++++++++++++++++++++LIST_OF_DOCTOR++++++++++++++++++++++"<<endl;
	int x = list1.size();
	for (int i = 0; i < x; i++)
	{
		if (list1[i].getdoctor_id() == doctor_id) 
		{
			list1[i].printt_person();
		}
	}

}
void modifyda(int doctor_id)
{
	string  person_firstname, person_lastname, phone, doctor_specialty, national_code;
	int person_age, m;
	for (int i = 0; i < list1.size(); i++)
	{
		if (list1[i].getdoctor_id() == doctor_id)
		{
			do {
				cout << "+++++++++++++++++++++MODIFY_DOCTOR_MENU++++++++++++++++++++++"<<endl;
				cout << "1.Doctor_id :)" << endl;
				cout << "2.Name of doctor :)" << endl;
				cout << "3.Family of doctor :)" << endl;
				cout << "4.Phone of doctor :)" << endl;
				cout << "5.National code of doctor :)" << endl;
				cout << "6.Age of doctor :)" << endl;
				cout << "7.Doctor speciality :)" << endl;
				cout << "8.Please enter 10 to break !" << endl;
				cin >> m;
				switch (m) {
				case 1:cout << "Please enter new code :)"; cin >> doctor_id; list1[i].setdoctor_id(doctor_id); break;
				case 2:cout << "Please enter new name :)"; cin >> person_firstname; list1[i].set_person_firstname(person_firstname); break;
				case 3:cout << "Please enter new family :)"; cin >> person_lastname; list1[i].set_person_lastname(person_lastname); break;
				case 4:cout << "Please enter new phone :)"; cin >> phone; list1[i].set_phone(phone); break;
				case 5:cout << "Please enter new national code :)"; cin >> national_code; list1[i].set_national_code(national_code); break;
				case 6:cout << "Please enter new age of doctor :)"; cin >> person_age; list1[i].set_person_age(person_age); break;
				case 7:cout << "Please enter new doctor_speciality :)"; cin >> doctor_specialty; list1[i].setdoctor_specialty(doctor_specialty); break;
				case 8:break;
				}

			} while (m ==10 );
		}
	}
}
void deleteallda() {
	list1.clear();
}
void deleteoneda(int dc) {
	for (int i = 0; i < list1.size(); i++) {
		if (list1[i].getdoctor_id() != dc) {
			list2.push_back(list1[i]);
		}
	}
	list1 = list2;
	vector<Doctor>().swap(list2);
}
int main()
{
	int dc, cp;
	system("cls");
	int y;
	string nd;
	do {
		cout << "+++++++++++++++++++++MAIN_MENU++++++++++++++++++++++"<<endl;
		cout << "+++++++++++++++++++++DOCTOR_MENU++++++++++++++++++++++"<<endl;
		cout << "1.Enter new doctor" << endl;
		cout << "2.Show information of doctors" << endl;
		cout << "3.Show information of one doctor" << endl;
		cout << "4.Modify of doctor" << endl;
		cout << "5.Delete all doctors" << endl;
		cout << "6.Delete one doctor" << endl;
		cout << "7.Show list of patients of each doctor:" << endl;
		cout << "+++++++++++++++++++++Patient_MENU ++++++++++++++++++++++"<<endl;
		cout << "8.Enter new patient" << endl;
		cout << "9.Show information of patients" << endl;
		cout << "10.Show information of one patient" << endl;
		cout << "11.Modify of patient" << endl;
		cout << "12.Delete all patients" << endl;
		cout << "13.Delete one patient" << endl;
		cout << "14.Exit" << endl;
		cin >> y;
		switch (y) {
		case 1:write_Doctor(); break;
		case 2:displayalldo(); break;
		case 3:cout << "Enter doctor_id :)"; cin >> dc; displaydo(dc); break;
		case 4:cout << "Enter doctor_id to change :)"; cin >> dc; modifyda(dc); break;
		case 5:deleteallda(); break;
		case 6:cout << "Enter doctor_id to change :)"; cin >> dc; deleteoneda(dc); break;
		case 7:list_of_doctor_of_patient(); break;
		case 8:write_patient(); break;
		case 9:displayall_patient(); break;
		case 10:cout << "Enter patient_id :)"; cin >> cp; displayOne_patient(cp); break;
		case 11:cout << "Enter patient_id to change :)"; cin >> cp; modify_patient(cp); break;
		case 12:deleteall_patient(); break;
		case 13:cout << "Enter  patient_id to delete :)"; cin >> cp; deleteone(cp); break;
		case 14:break;
		}
	} while (y != 14);
	_getch();
	return 0;
}



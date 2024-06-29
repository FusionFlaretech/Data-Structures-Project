#include<iostream>
#include"AvlTree.h"
#include"RB Tree.h"
#include"Btree.h"
#include<fstream>
#include<string>
using namespace std;

void menu()
{
	int option;
	int datatype;
	AVLtree<string> obj;
	AVLtree<int> obj2;
	AVLtree<double> obj3;

	redblacktree<string> r1;
	redblacktree<int> r2;
	redblacktree<double> r3 ;


	BTree<string> b1;
	BTree<int> b2;
	BTree<double> b3;


	ifstream* input = new ifstream[10];
	ifstream input2, input3, input4, input5, input6, input7, input8, input9, input10;

	string s;
	int line_no = 1;
	int size = 10;
	string* filename = new string[10];
	filename[0] = "data1.csv";
	filename[1] = "data2.csv";
	filename[2] = "data3.csv";
	filename[3] = "data4.csv";
	filename[4] = "data5.csv";
	filename[5] = "data6.csv";
	filename[6] = "data7.csv";
	filename[7] = "data8.csv";
	filename[8] = "data9.csv";
	filename[9] = "data10.csv";

	input[0].open("data1.csv");
	input[1].open("data2.csv");
	input[2].open("data3.csv");
	input[3].open("data4.csv");
	input[4].open("data5.csv");
	input[5].open("data6.csv");
	input[6].open("data7.csv");
	input[7].open("data8.csv");
	input[8].open("data9.csv");
	input[9].open("data10.csv");

	string low, high;

	int field;
	int choice;
	int iD;
	int Y;
	int death_no;
	double ID;
	double years;
	double Rate;
	double dea_ths;

	string str;
	string id, year, cause1, cause_name, state, deaths, rate;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "                                         WELCOME TO DATABASE SYSTEM!\n";
	cout << "Select options from the following menu: " << endl;
	cout << "Press 1 to create a B Tree index\n";
	cout << "Press 2 to create an AVL Tree index\n";
	cout << "Press 3 to create a RED-BLACK Tree index\n";
	cin >> choice;
	cout << "*************************************************************************************************************************************************\n";
	cout << endl;

	getline(input[1], str);
	getline(input[2], str);
	getline(input[3], str);
	getline(input[4], str);
	getline(input[5], str);
	getline(input[6], str);
	getline(input[7], str);
	getline(input[8], str);
	getline(input[9], str);


	switch (choice)
	{
	case 1:
		int order;
		cout << "----------------------------------------------------Welcome to B Tree indexing-------------------------------------------------------------------\n";
		cout << endl;
		cout << "Please enter the order of B Tree (i.e. the value of m)\n ";
		cin >> order;
		cout << endl;
		cout << "You can perform indexing on the following data fields\n" << endl;
		getline(input[0], str, ',');
		cout << "1) " << str << endl;
		getline(input[0], str, ',');
		cout << "2) " << str << endl;
		getline(input[0], str, ',');
		cout << "3) " << str << endl;
		getline(input[0], str, ',');
		cout << "4) " << str << endl;
		getline(input[0], str, ',');
		cout << "5) " << str << endl;
		getline(input[0], str, ',');
		cout << "6) " << str << endl;
		getline(input[0], str, '\n');
		cout << "7) " << str << endl;
		cout << endl;
		cout << "Now please specify the data field to perform indexing\n";
		cin >> field;
		cout << "Please specify the data type of the field\n";
		cout << "1) Integer " << endl << "2) Double" << endl << "3) String" << endl;
		cin >> datatype;
		if (field == 1 && datatype == 1) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {

					getline(input[i], str, ',');
					if (str == "") {
						break;
					}
					line_no++;
					id = str;
					iD = stoi(str);
					b2.insert(iD, filename[i], line_no);

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, '\n');

				}
				line_no = 0;
			}

			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the ID you want to search\n";
				int val;
				cin >> val;
				//b2.pointSearch(b2.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				int l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				int h = stoi(high);
				//b2.rangeSearch(b2.root, l, h);
			}
			b2.root->Traverse(b2.root);

		}


		else if (field == 1 && datatype == 2) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {

					getline(input[i], str, ',');
					if (str == "") {
						break;
					}
					line_no++;
					id = str;
					ID = stod(str);
					b3.insert(ID, filename[i], line_no);

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, '\n');

				}
				line_no = 0;
			}

			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the ID you want to search\n";
				double val;
				cin >> val;
				//b3.pointSearch(b3.root, val);
			}

			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				double l = stod(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				double h = stod(high);
				//b3.rangeSearch(b3.root, l, h);
			}

			b3.root->Traverse(b3.root);
		}


		else if (field == 1 && datatype == 3) {
			cout << "Please enter a valid datatype\n";
		}


		else if (field == 2 && datatype == 1) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');


					getline(input[i], str, ',');
					if (str == "") {
						break;
					}
					year = str;
					Y = stoi(str);
					line_no++;
					 b2.insert(Y, filename[i], line_no);


					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, '\n');

				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Year you want to search\n";
				int val;
				cin >> val;
				//b2.pointSearch(b2.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				int l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				int h = stoi(high);
				//b2.rangeSearch(b2.root, l, h);
			}

			b2.root->Traverse(b2.root);
		}


		else if (field == 2 && datatype == 2) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');

					getline(input[i], str, ',');
					if (str == "") {
						break;
					}
					year = str;
					years = stod(str);
					line_no++;
				     b3.insert(years, filename[i], line_no);


					getline(input[i], str, ',');


					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, '\n');

				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Year you want to search\n";
				double val;
				cin >> val;
				//b3.pointSearch(b3.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				double l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				double h = stoi(high);
				//b3.rangeSearch(b3.root, l, h);
			}

			b3.root->Traverse(b3.root);
		}


		else if (field == 2 && datatype == 3) {
			cout << "Please enter a valid data type\n";
		}

		else if (field == 3 && datatype == 1) {
			cout << "Please enter a valid data type\n";
		}
		else if (field == 3 && datatype == 2) {
			cout << "Please enter a valid data type\n";
		}

		else if (field == 3 && datatype == 3) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');

					getline(input[i], str, ',');


					getline(input[i], str, ',');
					line_no++;
					cause1 = str;
				    b1.insert(cause1, filename[i], line_no);

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, '\n');

				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Cause you want to search\n";
				string val;
				cin >> val;
				//b1.pointSearch(b1.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				//int l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				//int h = stoi(high);
				//b1.rangeSearch(b1.root, low, high);
			}
			b1.root->Traverse(b1.root);
		}

		else if (field == 4 && datatype == 1) {
			cout << "Please enter a valid data type\n";
		}

		else if (field == 4 && datatype == 2) {
			cout << "Please enter a valid data type\n";
		}

		else if (field == 4 && datatype == 3) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');
					line_no++;
					cause_name = str;
					b1.insert(cause_name, filename[i], line_no);

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, '\n');

				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Cause Name you want to search\n";
				string val;
				cin >> val;
				//b1.pointSearch(b1.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				//int l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				//int h = stoi(high);
				//b1.rangeSearch(b1.root, low, high);
			}
			b1.root->Traverse(b1.root);
		}


		else if (field == 5 && datatype == 1) {
			cout << "Please enter a valid data type\n";
		}

		else if (field == 5 && datatype == 2) {
			cout << "Please enter a valid data type\n";
		}

		else if (field == 5 && datatype == 3) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');
					line_no++;
					state = str;
					b1.insert(state, filename[i], line_no);

					getline(input[i], str, ',');

					getline(input[i], str, '\n');

				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the State you want to search\n";
				string val;
				cin >> val;
				//b1.pointSearch(b1.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				//int l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				//int h = stoi(high);
				//b1.rangeSearch(b1.root, low, high);
			}
			b1.root->Traverse(b1.root);
		}


		else if (field == 6 && datatype == 1) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');
					if (str == "") {
						break;
					}
					line_no++;
					deaths = str;
					death_no = stoi(str);
					b2.insert(death_no, filename[i], line_no);


					getline(input[i], str, '\n');

				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Deaths you want to search\n";
				int val;
				cin >> val;
				//b2.pointSearch(b2.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				int l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				int h = stoi(high);
				//b2.rangeSearch(b2.root, l, h);
			}
			b1.root->Traverse(b1.root);
		}

		else if (field == 6 && datatype == 2) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');
					if (str == "") {
						break;
					}
					line_no++;
					deaths = str;
					dea_ths = stod(deaths);

					 b3.insert(dea_ths, filename[i], line_no);


					getline(input[i], str, '\n');
				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Death you want to search\n";
				double val;
				cin >> val;
				//b3.pointSearch(b3.root, val);
			}

			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				double l = stod(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				double h = stod(high);
				//b3.rangeSearch(b3.root, l, h);
			}
			b3.root->Traverse(b3.root);
		}

		else if (field == 6 && datatype == 3) {
			cout << "Please enter a valid data type\n";
		}


		else if (field == 7 && datatype == 1) {
			cout << "Please enter a valid data type\n";
		}

		else if (field == 7 && datatype == 2) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');

					getline(input[i], str, ',');


					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, '\n');
					if (str == "") {
						break;
					}
					line_no++;
					rate = str;
					Rate = stod(rate);
					r3.root = r3.Insert(r3.root, Rate, filename[i], line_no);


				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Death Rate you want to search\n";
				double val;
				cin >> val;
				//b3.pointSearch(b3.root, val);
			}

			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				double l = stod(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				double h = stod(high);
				//b3.rangeSearch(b3.root, l, h);
			}
			b3.root->Traverse(b3.root);
		}

		else if (field == 7 && datatype == 3) {
			cout << "Please enter a valid data type\n";
		}
		break;

	case 3:
		cout << "----------------------------------------------------Welcome to RED-BLACK Tree indexing-----------------------------------------------------------\n";
		cout << endl;
		cout << "You can perform indexing on the following data fields\n";
		cout << endl;
		getline(input[0], str,',');
		cout << "1) " << str << endl;
		getline(input[0], str, ',');
		cout << "2) " << str << endl;
		getline(input[0], str, ',');
		cout << "3) " << str << endl;
		getline(input[0], str, ',');
		cout << "4) " << str << endl;
		getline(input[0], str, ',');
		cout << "5) " << str << endl;
		getline(input[0], str, ',');
		cout << "6) " << str << endl;
		getline(input[0], str, '\n');
		cout << "7) " << str << endl;
		cout << endl;
		cout << endl;
		cout << "Now please specify the data field to perform indexing\n";
		cin >> field;
		cout << "Please specify the data type of the field\n";
		cout << "1) Integer " << endl << "2) Double" << endl << "3) String" << endl;
		cin >> datatype;

		if (field == 1 &&  datatype == 1) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {

					getline(input[i], str, ',');
					if (str == "") {
						break;
					}
					line_no++;
					id = str;
					iD = stoi(str);
					r2.root = r2.Insert(r2.root, iD, filename[i], line_no);

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, '\n');

				}
				line_no = 0;
			}

			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the ID you want to search\n";
				int val;
				cin >> val;
				r2.pointSearch(r2.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				int l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				int h = stoi(high);
				r2.rangeSearch(r2.root, l, h);
			}
			r2.colourlevel(r2.root, "ID");

		}


		else if (field == 1 && datatype == 2) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {

					getline(input[i], str, ',');
					if (str == "") {
						break;
					}
					line_no++;
					id = str;
					ID = stod(str);
					r3.root = r3.Insert(r3.root, ID, filename[i], line_no);

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, '\n');

				}
				line_no = 0;
			}

			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the ID you want to search\n";
				double val;
				cin >> val;
				r3.pointSearch(r3.root, val);
			}

			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				double l = stod(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				double h = stod(high);
				r3.rangeSearch(r3.root, l, h);
			}
			r3.colourlevel(r3.root , "ID");
		}


		else if (field == 1 && datatype == 3) {
			cout << "Please enter a valid datatype\n";
		}


		else if (field == 2 && datatype == 1) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');


					getline(input[i], str, ',');
					if (str == "") {
						break;
					}
					year = str;
					Y = stoi(str);
					line_no++;
					r2.root = r2.Insert(r2.root, Y, filename[i], line_no);


					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, '\n');

				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Year you want to search\n";
				int val;
				cin >> val;
				r2.pointSearch(r2.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				int l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				int h = stoi(high);
				r2.rangeSearch(r2.root, l, h);
			}

			r2.colourlevel(r2.root, "Year");
		}


		else if (field == 2 && datatype == 2) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');

					getline(input[i], str, ',');
					if (str == "") {
						break;
					}
					year = str;
					years = stod(str);
					line_no++;
					r3.root = r3.Insert(r3.root, years, filename[i], line_no);


					getline(input[i], str, ',');


					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, '\n');

				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Year you want to search\n";
				double val;
				cin >> val;
				r3.pointSearch(r3.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				double l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				double h = stoi(high);
				r3.rangeSearch(r3.root, l, h);
			}

			r3.colourlevel(r3.root, "Year");
		}


		else if (field == 2 && datatype == 3) {
			cout << "Please enter a valid data type\n";
		}

		else if (field == 3 && datatype == 1) {
			cout << "Please enter a valid data type\n";
		}
		else if (field == 3 && datatype == 2) {
			cout << "Please enter a valid data type\n";
		}

		else if (field == 3 && datatype == 3) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');

					getline(input[i], str, ',');


					getline(input[i], str, ',');
					line_no++;
					cause1 = str;
					r1.root = r1.Insert(r1.root, cause1, filename[i], line_no);

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, '\n');

				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Cause you want to search\n";
				string val;
				cin >> val;
				r1.pointSearch(r1.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				//int l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				//int h = stoi(high);
				r1.rangeSearch(r1.root, low, high);
			}
			r1.colourlevel(r1.root, "Cause");
		}

		else if (field == 4 && datatype == 1) {
			cout << "Please enter a valid data type\n";
		}

		else if (field == 4 && datatype == 2) {
			cout << "Please enter a valid data type\n";
		}

		else if (field == 4 && datatype == 3) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');
					line_no++;
					cause_name = str;
					r1.root = r1.Insert(r1.root, cause_name, filename[i], line_no);

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, '\n');

				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Cause Name you want to search\n";
				string val;
				cin >> val;
				r1.pointSearch(r1.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				//int l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				//int h = stoi(high);
				r1.rangeSearch(r1.root, low, high);
			}
			r1.colourlevel(r1.root, "Cause_N");
		}


		else if (field == 5 && datatype == 1) {
			cout << "Please enter a valid data type\n";
		}

		else if (field == 5 && datatype == 2) {
			cout << "Please enter a valid data type\n";
		}

		else if (field == 5 && datatype == 3) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');
					line_no++;
					state = str;
					r1.root = r1.Insert(r1.root, state, filename[i], line_no);

					getline(input[i], str, ',');

					getline(input[i], str, '\n');

				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the State you want to search\n";
				string val;
				cin >> val;
				r1.pointSearch(r1.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				//int l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				//int h = stoi(high);
				r1.rangeSearch(r1.root, low, high);
			}
			r1.colourlevel(r1.root, "State");
		}


		else if (field == 6 && datatype == 1) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');
					if (str == "") {
						break;
					}
					line_no++;
					deaths = str;
					death_no = stoi(str);
					r2.root = r2.Insert(r2.root, death_no, filename[i], line_no);


					getline(input[i], str, '\n');

				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Deaths you want to search\n";
				int val;
				cin >> val;
				r2.pointSearch(r2.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				int l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				int h = stoi(high);
				r2.rangeSearch(r2.root, l, h);
			}
			r2.colourlevel(r2.root, "Deaths");
		}

		else if (field == 6 && datatype == 2) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');
					if (str == "") {
						break;
					}
					line_no++;
					deaths = str;
					dea_ths = stod(deaths);

					r3.root = r3.Insert(r3.root, dea_ths, filename[i], line_no);


					getline(input[i], str, '\n');
				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Death you want to search\n";
				double val;
				cin >> val;
				r3.pointSearch(r3.root, val);
			}

			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				double l = stod(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				double h = stod(high);
				r3.rangeSearch(r3.root, l, h);
			}
			r3.colourlevel(r3.root, "Deaths");
		}

		else if (field == 6 && datatype == 3) {
			cout << "Please enter a valid data type\n";
		}


		else if (field == 7 && datatype == 1) {
			cout << "Please enter a valid data type\n";
		}

		else if (field == 7 && datatype == 2) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');

					getline(input[i], str, ',');


					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, '\n');
					if (str == "") {
						break;
					}
					line_no++;
					rate = str;
					Rate = stod(rate);
					r3.root = r3.Insert(r3.root, Rate, filename[i], line_no);


				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Death Rate you want to search\n";
				double val;
				cin >> val;
				r3.pointSearch(r3.root, val);
			}

			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				double l = stod(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				double h = stod(high);
				r3.rangeSearch(r3.root, l, h);
			}
			r3.colourlevel(r3.root, "Rate");
		}

		else if (field == 7 && datatype == 3) {
			cout << "Please enter a valid data type\n";
		}
		
		break;

	case 2:
		cout << "----------------------------------------------------Welcome to AVL Tree indexing-----------------------------------------------------------------\n";
		cout << endl;
		cout << "You can perform indexing on the following data fields\n" << endl;
		getline(input[0], str, ',');
		cout << "1) " << str << endl;
		getline(input[0], str, ',');
		cout << "2) " << str << endl;
		getline(input[0], str, ',');
		cout << "3) " << str << endl;
		getline(input[0], str, ',');
		cout << "4) " << str << endl;
		getline(input[0], str, ',');
		cout << "5) " << str << endl;
		getline(input[0], str, ',');
		cout << "6) " << str << endl;
		getline(input[0], str, '\n');
		cout << "7) " << str << endl;
		cout << endl;
		cout << "Now please specify the data field to perform indexing\n";
		cin >> field;
		cout << "Please specify the data type of the field\n";
		cout << "1) Integer " << endl << "2) Double" << endl << "3) String" << endl;
		cin >> datatype;
		cout << endl;
		if (field == 1 && datatype == 1) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {

					getline(input[i], str, ',');
					if (str == "") {
						break;
					}
					line_no++;
					id = str;
					iD = stoi(str);
					obj2.root = obj2.Insert(obj2.root, iD, filename[i], line_no);

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, '\n');

				}
				line_no = 0;
			}

			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the ID you want to search\n";
				int val;
				cin >> val;
				obj2.pointSearch(obj2.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				int l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				int h = stoi(high);
				obj2.rangeSearch(obj2.root, l, h);
			}
			if (option == 3) {
				cout << "Please enter the ID you want to update\n";
				int prev_id;
				cin >> prev_id;
				cout << "Please enter the ID you need to replace the old ID with\n";
				int new_id;
				cin >> new_id;
				obj2.updateNode(prev_id,new_id);
				cout << "Update successful\n";
			}
			if (option == 4) {
				cout << "Please enter the ID you want to delete\n";
				int del_id;
				cin >> del_id;
				//obj2.deleteNodeFromFile(del_id);
				
			}
			obj2.LevelOrder("ID");
			
		}

		
		else if (field == 1 && datatype == 2) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {

					getline(input[i], str, ',');
					if (str == "") {
						break;
					}
					line_no++;
					id = str;
					ID = stod(str);
					obj3.root = obj3.Insert(obj3.root, ID, filename[i], line_no);

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, '\n');

				}
				line_no = 0;
			}

			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the ID you want to search\n";
				double val;
				cin >> val;
				obj3.pointSearch(obj3.root, val);
			}

			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				double l = stod(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				double h = stod(high);
				obj3.rangeSearch(obj3.root, l, h);
			}
			if (option == 3) {
				cout << "Please enter the ID you want to update\n";
				int prev_id;
				cin >> prev_id;
				cout << "Please enter the ID you need to replace the old ID with\n";
				int new_id;
				cin >> new_id;
				obj3.updateNode(prev_id, new_id);
				cout << "Update successful\n";
			}
			if (option == 4) {
				cout << "Please enter the ID you want to delete\n";
				int del_id;
				cin >> del_id;
				//obj3.deleteNodeFromFile(del_id);
			}
			obj3.LevelOrder("ID");
		}


		else if (field == 1 && datatype == 3) {
		cout << "Please enter a valid datatype\n";
		}


		else if (field == 2 && datatype == 1) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');


					getline(input[i], str, ',');
					if (str == "") {
						break;
					}
					year = str;
					Y = stoi(str);
					line_no++;
					obj2.root = obj2.Insert(obj2.root, Y, filename[i], line_no);


					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, '\n');

				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Year you want to search\n";
				int val;
				cin >> val;
				obj2.pointSearch(obj2.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				int l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				int h = stoi(high);
				obj2.rangeSearch(obj2.root, l, h);
			}
			if (option == 3) {
				cout << "Please enter the Year you want to update\n";
				int prev_id;
				cin >> prev_id;
				cout << "Please enter the Year you need to replace the old Year with\n";
				int new_id;
				cin >> new_id;
				obj2.updateNode(prev_id, new_id);
				cout << "Update successful\n";
			}
			if (option == 4) {
				cout << "Please enter the Year you want to delete\n";
				int del_id;
				cin >> del_id;
				//obj2.deleteNodeFromFile(del_id);
			}

			obj2.LevelOrder("Year");
		}


		else if (field == 2 && datatype == 2) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');

					getline(input[i], str, ',');
					if (str == "") {
						break;
					}
					year = str;
					years = stod(str);
					line_no++;
					obj3.root = obj3.Insert(obj3.root, years, filename[i], line_no);


					getline(input[i], str, ',');


					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, '\n');

				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Year you want to search\n";
				double val;
				cin >> val;
				obj3.pointSearch(obj3.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				double l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				double h = stoi(high);
				obj3.rangeSearch(obj3.root, l, h);
			}
			if (option == 3) {
				cout << "Please enter the Year you want to update\n";
				int prev_id;
				cin >> prev_id;
				cout << "Please enter the Year you need to replace the old Year with\n";
				int new_id;
				cin >> new_id;
				obj3.updateNode(prev_id, new_id);
				cout << "Update successful\n";
			}
			if (option == 4) {
				cout << "Please enter the Year you want to delete\n";
				int del_y;
				cin >> del_y;
				//obj3.deleteNodeFromFile(del_y);
			}

			obj3.LevelOrder("Year");
		}


		else if (field == 2 && datatype == 3) {
		cout << "Please enter a valid data type\n";
		}

		else if (field == 3 && datatype == 1) {
			cout << "Please enter a valid data type\n";
		}
		else if (field == 3 && datatype == 2) {
			cout << "Please enter a valid data type\n";
		}

		else if (field == 3 && datatype == 3) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');

					getline(input[i], str, ',');


					getline(input[i], str, ',');
					line_no++;
					cause1 = str;
					obj.root = obj.Insert(obj.root, cause1, filename[i], line_no);

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, '\n');

				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Cause you want to search\n";
				string val;
				cin >> val;
				obj.pointSearch(obj.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				//int l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				//int h = stoi(high);
				obj.rangeSearch(obj.root, low, high);
			}
			if (option == 3) {
				cout << "Please enter the Cause you want to update\n";
				string prev_id;
				cin >> prev_id;
				cout << "Please enter the Cause you need to replace the old ID with\n";
				string new_id;
				cin >> new_id;
				obj.updateNode(prev_id, new_id);
				cout << "Update successful\n";
			}
			if (option == 4) {
				cout << "Please enter the Cause you want to delete\n";
				string del_id;
				cin >> del_id;
				//obj.deleteNodeFromFile(del_id);
			}
			obj.LevelOrder("Cause");
		}

		else if (field == 4 && datatype == 1) {
			cout << "Please enter a valid data type\n";
		}

		else if (field == 4 && datatype == 2) {
			cout << "Please enter a valid data type\n";
		}

		else if (field == 4 && datatype == 3) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');
					line_no++;
					cause_name = str;
					obj.root = obj.Insert(obj.root, cause_name, filename[i], line_no);

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, '\n');

				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Cause Name you want to search\n";
				string val;
				cin >> val;
				obj.pointSearch(obj.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				//int l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				//int h = stoi(high);
				obj.rangeSearch(obj.root, low, high);
			}
			if (option == 3) {
				cout << "Please enter the Cause Name you want to update\n";
				string prev_id;
				cin >> prev_id;
				cout << "Please enter the Cause Name you need to replace the old Cause Name with\n";
				string new_id;
				cin >> new_id;
				obj.updateNode(prev_id, new_id);
				cout << "Update successful\n";
			}
			if (option == 4) {
				cout << "Please enter the Cause Name you want to delete\n";
				string del_id;
				cin >> del_id;
				//obj.deleteNodeFromFile(del_id);
			}
			obj.LevelOrder("CN");
		}


		else if (field == 5 && datatype == 1) {
			cout << "Please enter a valid data type\n";
		}

		else if (field == 5 && datatype == 2) {
			cout << "Please enter a valid data type\n";
		}

		else if (field == 5 && datatype == 3) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');
					line_no++;
					state = str;
					obj.root = obj.Insert(obj.root, state, filename[i], line_no);

					getline(input[i], str, ',');
				
					getline(input[i], str, '\n');

				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the State you want to search\n";
				string val;
				cin >> val;
				obj.pointSearch(obj.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				//int l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				//int h = stoi(high);
				obj.rangeSearch(obj.root, low, high);
			}
			if (option == 3) {
				cout << "Please enter the State you want to update\n";
				string prev_id;
				cin >> prev_id;
				cout << "Please enter the State you need to replace the old State with\n";
				string new_id;
				cin >> new_id;
				obj.updateNode(prev_id, new_id);
				cout << "Update successful\n";
			}
			if (option == 4) {
				cout << "Please enter the State you want to delete\n";
				string del_id;
				cin >> del_id;
				//obj.deleteNodeFromFile(del_id);
			}
			obj.LevelOrder("State");
		}


		else if (field == 6 && datatype == 1) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');
					if (str == "") {
						break;
					}
					line_no++;
					deaths = str;
					death_no = stoi(str);
					obj2.root = obj2.Insert(obj2.root, death_no, filename[i], line_no);


					getline(input[i], str, '\n');

				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Deaths you want to search\n";
				int val;
				cin >> val;
				obj2.pointSearch(obj2.root, val);
			}
			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				int l = stoi(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				int h = stoi(high);
				obj2.rangeSearch(obj2.root, l, h);
			}
			if (option == 3) {
				cout << "Please enter the Deaths you want to update\n";
				int prev_id;
				cin >> prev_id;
				cout << "Please enter the Deaths you need to replace the old Deaths with\n";
				int new_id;
				cin >> new_id;
				obj2.updateNode(prev_id, new_id);
				cout << "Update successful\n";
			}
			if (option == 4) {
				cout << "Please enter the deaths you want to delete\n";
				int del_id;
				cin >> del_id;
				//obj2.deleteNodeFromFile(del_id);
			}
			obj2.LevelOrder("D");
		}

		else if (field == 6 && datatype == 2) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');

					getline(input[i], str, ',');
					if (str == "") {
						break;
					}
					line_no++;
					deaths = str;
					dea_ths = stod(deaths);

					obj3.root = obj3.Insert(obj3.root, dea_ths, filename[i], line_no);


					getline(input[i], str, '\n');
				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Death you want to search\n";
				double val;
				cin >> val;
				obj3.pointSearch(obj3.root, val);
			}

			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				double l = stod(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				double h = stod(high);
				obj3.rangeSearch(obj3.root, l, h);
			}
			if (option == 3) {
				cout << "Please enter the deaths you want to update\n";
				double prev_id;
				cin >> prev_id;
				cout << "Please enter the deaths you need to replace the old deaths with\n";
				double new_id;
				cin >> new_id;
				obj3.updateNode(prev_id, new_id);
				cout << "Update successful\n";
			}
			if (option == 4) {
				cout << "Please enter the deaths you want to delete\n";
				double del_id;
				cin >> del_id;
				//obj3.deleteNodeFromFile(del_id);
			}
			obj3.LevelOrder("D");
		}

		else if (field == 6 && datatype == 3) {
		cout << "Please enter a valid data type\n";
		}


		else if (field == 7 && datatype == 1) {
			cout << "Please enter a valid data type\n";
		}

		else if (field == 7 && datatype == 2) {
			for (int i = 0; i < size; i++) {
				while (!input[i].eof()) {
					getline(input[i], str, ',');
					
					getline(input[i], str, ',');
					

					getline(input[i], str, ',');
					
					getline(input[i], str, ',');
					
					getline(input[i], str, ',');
					
					getline(input[i], str, ',');
					
					getline(input[i], str, '\n');
					if (str == "") {
						break;
					}
					line_no++;
					rate = str;
					Rate = stod(rate);
					obj3.root = obj3.Insert(obj3.root, Rate, filename[i], line_no);


				}
				line_no = 0;
			}
			cout << "What else function do you need to perform\n";
			cout << "These are the following functions which you can perform on the following set of data\n";
			cout << "1) Point Search\n";
			cout << "2) Range Search\n";
			cout << "3) Update key, field, old value, new value\n";
			cout << "4) Delete key\n";
			cin >> option;
			if (option == 1) {
				cout << "Please enter the Death Rate you want to search\n";
				double val;
				cin >> val;
				obj3.pointSearch(obj3.root, val);
			}

			if (option == 2) {

				cout << "Enter the lower bound of the range: ";
				cin >> low;
				double l = stod(low);
				cout << "Enter the upper bound of the range: ";
				cin >> high;
				double h = stod(high);
				obj3.rangeSearch(obj3.root, l, h);
			}
			if (option == 3) {
				cout << "Please enter the rate you want to update\n";
				double prev_id;
				cin >> prev_id;
				cout << "Please enter the rate you need to replace the old rate with\n";
				double new_id;
				cin >> new_id;
				obj3.updateNode(prev_id, new_id);
				cout << "Update successful\n";
			}
			if (option == 4) {
				cout << "Please enter the ID you want to delete\n";
				double del_id;
				cin >> del_id;
				//obj3.deleteNodeFromFile(del_id);
			}
			obj3.LevelOrder("R");
		}

		else if (field == 7 && datatype == 3) {
		cout << "Please enter a valid data type\n";
		}
		break;
	}
}



int main() {
	menu();
}


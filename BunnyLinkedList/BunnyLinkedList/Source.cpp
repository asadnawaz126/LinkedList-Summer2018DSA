#include <iostream>
#include<stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include<time.h>

using namespace std;

struct bunny {
	char sex;
	string color;
	int age;
	string name;
	bunny *next;
}*start;


bunny* create(vector<string> bunnyData);
void insertAtBeginning(bunny* b);
void insert(bunny* b);
void display();
void babyBunnies();
void displayBabyNames();

vector<string> randomNames = {"Ka", "Lorine", "Edith","Cedrick","Dewitt","Rosina","Loma",
							"Kiyoko","Elissa","Opal","Darline","Cristopher","Aurelio","Rebeca","Katheryn","Marya","Mauricio"};
vector<string> randomSex = {"M","M","M","M","F"};
vector<string> randomColors = {"White","Brown","Black","Spotted"};

int bunnyCount = 0; //number of Bunnies

int main() {

	start = NULL;
	//bunny *newBunny = NULL;

	string fileName = "Task 1 Input.txt";

	ifstream inFile(fileName);

	vector<string> bunnyData(4);

	int loopCount = 1;
	
	while (inFile) {

		string Bunny;
		getline(inFile, Bunny);

		//cout << endl << Bunny << endl;
		/*if (loopCount>6) {
			break;
		}*/

	

		if (Bunny.length() > 1) {

			int spacePosition = 0; //position of whitespace

			int index = 0; //bunny data index

			for (int i = 0; i < Bunny.length(); i++) {

				//if Bunny encounters a whitespace then the data from the start of the previous non whitespace index will be a substring
				//and added to Bunny array;

				if (Bunny[i] == ' ') {

					bunnyData[index] = Bunny.substr(spacePosition, i - spacePosition);

					spacePosition = i + 1;
					index++;
				}

				if (i == Bunny.length() - 1) {
					bunnyData[index] = Bunny[i];
				}

			}

			if (loopCount == 1) {
				bunny *newBunny = create(bunnyData);
				//cout << newBunny->color << endl;
				insertAtBeginning(newBunny);
			}

			else {
				bunny *newBunny = create(bunnyData);
				//cout << "after bunny created";
				insert(newBunny);
			}

			//cout << endl << "LoopCount is: "<<loopCount<< endl;
			loopCount++;
		}

		else {
			loopCount++;
			continue;
		}
	}
	babyBunnies();
	display();
	displayBabyNames();
	
	getchar();
	return 0;
}


bunny* create(vector<string> bunnyData) {

	bunny* newBunny = new bunny;


	if (newBunny == NULL) {
		cout << "OVERFLOW";
		getchar();
		exit(1);
	}

	else{
	
		newBunny->name = bunnyData[0];
		newBunny->sex = bunnyData[1][0];
		newBunny->color = bunnyData[2];
		newBunny->age = stoi(bunnyData[3]);

		//newBunny->next = NULL;
		return newBunny;

	}
	
}


void insertAtBeginning(bunny* b) {


	//cout << b->color<<endl;
	bunny* temp;

	if (start == NULL) {
		start = b;
		start->next = NULL;
	}
}

void insert(bunny* b) {


	bunny* temp = start;
	
	if (start == NULL) {
		start = b;
		start->next = NULL;
	}

	else {
		while (temp->next!= NULL)
		{			
			temp = temp->next;

		}
		
		b->next = temp->next;
		temp->next = b;
		b->next = NULL;
		
	}

	bunnyCount++;  //increase number of Bunnies by 1

}

void display() {
	bunny* temp = start;

	while (temp->next != NULL) {
		cout << temp->name << " " << temp->sex << " " << temp->color << " " << temp->age << endl;
		temp = temp->next;
	}
	cout << temp->name << " " << temp->sex << " " << temp->color << " " << temp->age << endl;
	
}

void babyBunnies() {

	bunny* temp = start;

	
	int maleCount = 0;
	int femaleCount = 0;

	while (temp->next != NULL) {
		if (temp->sex == 'M') {
			maleCount++;
		}
		else if (temp->sex == 'F') {
			femaleCount++;
		}

		temp = temp->next;
	}

	if (temp->sex == 'M')
		maleCount++;
	else if (temp->sex == 'F')
		femaleCount++;

	srand(time(NULL));

	if (maleCount >= 1) {
		for (int i = 0;i < femaleCount;i++) {
			vector<string> bunnyData;

			bunnyData.push_back(randomNames[rand() % randomNames.size()]);
			bunnyData.push_back(randomSex[rand() % randomSex.size()]);
			bunnyData.push_back(randomColors[rand() % randomColors.size()]);
			bunnyData.push_back(to_string(rand() % 6));

			bunny* newBunny = create(bunnyData);
			insert(newBunny);

		}
	}

}

void displayBabyNames() {

	bunny* temp = start;


	for (int i = 1;i <= bunnyCount;i++) {

		if (i > 5)
			cout << endl << "Bunny " << temp->name << " was born!";

		temp = temp->next;
	}
	
}


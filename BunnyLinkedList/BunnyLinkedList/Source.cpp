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
bool isAdult(bunny *Bunny);

vector<string> randomNames = {"Ka", "Lorine", "Edith","Cedrick","Dewitt","Rosina","Loma",
							"Kiyoko","Elissa","Opal","Darline","Cristopher","Aurelio","Rebeca","Katheryn","Marya","Mauricio"};
vector<string> randomSex = {"M","M","M","M","F"};
vector<string> randomColors = {"White","Brown","Black","Spotted"};

int bunnyCount = 0; //number of Bunnies

int main() {

	start = NULL;

	string fileName = "Input1.txt";

	ifstream inFile;

	inFile.open(fileName);

	vector<string> bunnyData(4);

	int loopCount = 0;
	
	while (!inFile.eof()) {

		string Bunny;
		getline(inFile, Bunny);

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


			bunny *newBunny = create(bunnyData);
			insert(newBunny);


			loopCount++;
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

	bunny* temp;

	if (start == NULL) {
		start = b;
		start->next = NULL;
	}

}

void insert(bunny* b) {

	bunnyCount++;

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

	  //increase number of Bunnies by 1

}

void display() {
	bunny* temp = start;

	cout << "Total number of bunnies: " << bunnyCount << endl << endl;

	while (temp->next != NULL) {
		cout << temp->name << " " << temp->sex << " " << temp->color << " " << temp->age << endl;
		temp = temp->next;
	}
	cout << temp->name << " " << temp->sex << " " << temp->color << " " << temp->age << endl;
	
}

void babyBunnies() {

	bunny* temp = start;


	int adultMaleCount = 0;
	int adultFemaleCount = 0;

	while (temp->next != NULL) {
		if (temp->sex == 'M' && isAdult(temp)) {
			adultMaleCount++;
		}
		else if (temp->sex == 'F' && isAdult(temp)) {
			adultFemaleCount++;
		}

		temp = temp->next;
	}

	if (temp->sex == 'M' && isAdult(temp))
		adultMaleCount++;
	else if (temp->sex == 'F' && isAdult(temp))
		adultFemaleCount++;

	srand(time(NULL));

	if (adultMaleCount >= 1) {
		for (int i = 0;i < adultFemaleCount;i++) {
			vector<string> bunnyData;

			bunnyData.push_back(randomNames[rand() % randomNames.size()]);
			bunnyData.push_back(randomSex[rand() % randomSex.size()]);
			bunnyData.push_back(randomColors[rand() % randomColors.size()]);
			bunnyData.push_back("0");

			bunny* newBunny = create(bunnyData);
			//cout << "Bunny: " << newBunny->name << " created" << endl << endl;
			insert(newBunny);
			

		}
	}

}
bool isAdult(bunny *Bunny) {

	if (Bunny->age >= 2)
		return true;

	else
		return false;
}

void displayBabyNames() {

	bunny* temp = start;


	for (int i = 1;i <= bunnyCount;i++) {

		if (i > 5)
			cout << endl << "Bunny " << temp->name << " was born!";

		temp = temp->next;
	}
	
}


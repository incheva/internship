#include <iostream>
#include <string>
#include <conio.h>
#define max_size 5
using namespace std;

struct Student{
	int id;
	char name[100];
	char gender[30];
};

struct friendship {
	char *studentName;
	int myFriends[20];
	int numFriends;
};

class Friends {
	Student studArr[max_size];
	friendship friendList[max_size];
public:
	void studInfo();
	void assignFriends();
	int frAdd(int frCount, int currFr, int currStud);
	void printMyFriends(int index);
	void allFrOfMyFr(int index);
	int notMyFriends(int myIndex, int crrentFrined, int myFriendIndex);
};
	
void Friends::studInfo(){
	for (int i = 0; i < max_size; i++){
		cout << "Enter Student id: ";
		cin >> studArr[i].id;
		cout << "Enter Student name: ";
		cin >> studArr[i].name;
		cout << "Enter Student gender: ";
		cin >> studArr[i].gender;
	}		
		}
void Friends::assignFriends(){
	for (int index = 0; index < max_size; index++){
		friendList[index].studentName = studArr[index].name;
		cout << " " << index;
		cout << ".  " << friendList[index].studentName << "\n";
	}
}

int Friends::frAdd(int frCount, int currFr, int currStud){
	friendList[currStud].numFriends = frCount;
	int ch;
	if (currFr >= frCount)
		return 0;
	cout << "Enter the number corresponding to the friend you want to add: " << "\n";
	cin >> ch;
	friendList[currStud].myFriends[currFr] = ch;
	currFr = currFr + 1;
	frAdd(frCount, currFr, currStud);
}

void Friends::printMyFriends(int index){
	cout << " " << friendList[index].studentName;
	cout << " friends are: ";
	for (int j = 0; j < friendList[index].numFriends; j++){
		cout << " " << friendList[friendList[index].myFriends[j]].studentName;
	}
}

void Friends::allFrOfMyFr(int index){
	for (int i = 0; i < friendList[index].myFriends[i]; i++){
		printMyFriends(friendList[index].myFriends[i]);
			}
}

int Friends::notMyFriends(int myIndex, int currFr, int myFriendIndex){
	if (myFriendIndex <= friendList[myIndex].numFriends || myIndex == currFr){
		for (int j = 0; j < friendList[currFr].numFriends; j++){
			if (friendList[currFr].myFriends[j] == myFriendIndex) {
				myFriendIndex = myFriendIndex + 1;
				notMyFriends(myIndex, currFr, myFriendIndex);
			}
			else{
				cout << " " << friendList[friendList[currFr].myFriends[j]].studentName;
			}
		}
	}
	if (currFr < friendList[myIndex].numFriends){
		currFr = currFr + 1;
		notMyFriends(myIndex, currFr, 1);
	}
	else {
		return 0;
	}
}

void main(){
	int pos = 0;
	int frCount = 0;
	Friends *Student1 = new Friends;
	Student1->studInfo();
	Student1->assignFriends();
	for (int i = 0; i < max_size; i++){
		cout << "How many friends do you want to add?" << "\n";
		cin >> frCount;
		Student1->frAdd(frCount, 0, i);
	}
	cout << "Print out all friends of the student with position: ";
	cin >> pos;
	Student1->printMyFriends(pos); //function to see all friends of the student

	//cout << "Print out all friends of the friends of student with position: ";
	//Student1->allFrOfMyFr(pos); //function to see all friends of the friends of the student

	//cout << "Print out the friends which are not friends of the student with position:";
	//Student1->notMyFriends(pos, 0, 0);
	_getch();
}

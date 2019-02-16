/*
HAFIZ MUNEEB UR REHMAN
BCSF15M030
ASSIGNMENT 01
QUESTION 1
*/


#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

class Node
{
public:
	string name;
	long double responseSize;
	int totalReq;
	Node* next;
};

class LinkedList
{
	Node* head;
	Node* tail;
	int size;
public:
	LinkedList() { head = tail = NULL; size = 0; }
	void insertNode(string name, int responseSize);
	bool searchNode(string name, int responseSize);
	void displayResults();
};

void LinkedList::insertNode(string name, int responseSize)
{
	Node* n=new Node;
	n->name = name;
	n->responseSize = responseSize;
	++(n->totalReq);
	n->next = NULL;
	if (head == NULL)
		head = tail = n;
	else
	{
		tail->next = n;
		tail = n;
	}
}

bool LinkedList::searchNode(string name, int responseSize)
{
	Node* temp = head;
	while (temp != NULL)
	{
		if (temp->name == name)
		{
			temp->responseSize += responseSize;
			++(temp->totalReq);
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void LinkedList::displayResults()
{
	Node* temp = head;
	cout << "Page Name\t\t\t\t\t" << "Total Request\t\t" << "Average Response Size\n\n\n";
	while (temp != NULL)
	{
		cout <<left<< setw(60) << temp->name  << setw(10) << temp->totalReq << "\t\t" << setw(10) << (temp->responseSize / temp->totalReq) << endl;
		temp = temp->next;
	}
}

void readingFromFile(LinkedList list);

int main()
{
	LinkedList list;
	readingFromFile(list);
	return 0;
}


void readingFromFile(LinkedList list)
{
	ifstream inFile("Input 2.txt");
	if (!inFile)
	{
		cout << "Error opening File...\n";
		exit(1);
	}
	string str;
	while (!inFile.eof())
	{
		getline(inFile, str);
		int length = str.length();
		char *nstr = new char[length];
		char *rstr = new char[10];
		int spCounter = 5;
		int j = 0, k = 0;
		bool flag = true;
		bool isIgnore = false;
		for (int i = 48; i < length; i++)
		{
			if (str[i] == ' ')
				spCounter++;
			else if (str[i] == '?')
				flag = false;
			else if (spCounter == 6 && flag)
			{
				nstr[j] = str[i];
				j++;
			}
			else if (spCounter == 9 && str[i] != ' ')
			{
				if (str[i] != '-')
				{
					rstr[k] = str[i];
					k++;
				}
				else
					isIgnore = true;
			}
		}
		if (!isIgnore)
		{
			nstr[j] = rstr[k] = NULL;
			int i = 0;
			string name;
			while (nstr[i] != NULL)
			{
				name = name + nstr[i];
				i++;
			}
			i = 0;
			int responseSize = 0;
			while (rstr[i] != NULL)
			{
				responseSize = (responseSize * 10) + (rstr[i] - 48);
				i++;
			}
			bool isOld = list.searchNode(name, responseSize);
			if (!isOld)
				list.insertNode(name, responseSize);
		}
	}
	list.displayResults();
	inFile.close();
}

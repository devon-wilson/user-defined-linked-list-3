#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
const int MAX_STR = 200;
struct nodeType
{
        char data[MAX_STR];
        nodeType *link;
};
void addToList(nodeType* &first, nodeType* &last, char start[]);
void printList(nodeType* first);
void findWord(nodeType* first, char search[]);
int main()
{
	char search[MAX_STR] = {'\0'};
        nodeType *first = NULL;
        nodeType *last = NULL;
        char quit[MAX_STR] = "quit";
        char start[MAX_STR] = {'\0'};
        do
        {
                cout << "Enter data " << endl;
                cin.getline(start, MAX_STR);
		if(strcmp(start, quit) != 0)
		{
                	addToList(first, last, start);
		}
        }while(strcmp(start , quit) != 0);
	cout << "What word to search for? " << endl;
	cin.getline(search, MAX_STR);
	findWord(first, search);
        printList(first);
        return 0;
}

void findWord(nodeType* current, char search[])
{
	if(current == NULL)
	{
		cout << "Word not found " << endl;
		return;
	}
	else if(strcmp(current->data, search) == 0)
	{
		cout << "Word found " << endl;
		return;
	}
	findWord(current->link, search);
}

void addToList(nodeType* &first, nodeType* &last, char start[])
{
                nodeType *newNode = new nodeType;
                strcpy(newNode -> data, start);
                newNode -> link = NULL;
                if(first == NULL)
                {
                        first = newNode;
                        last = newNode;
                }
                else
                {
                        last -> link = newNode;
                        last = newNode;
                }
}

void printList(nodeType *current)
{
	if(current == NULL)
	{
		return;	
	}
        else
        {
                cout << " " << endl;
                cout << current -> data << endl;
        }
	printList(current->link);
}


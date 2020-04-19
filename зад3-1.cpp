//3-1 spisyk L s neobhodimi funkcii i menu
//spisyk s nachalen ukazatel pstart systawq spisyk samo s elementite, koito ne se powtarqt
//da se izwedat na ekrana po podhodqsh nachin
#include <iostream>
using namespace std;
struct list {
	int key;
	list* next;
}
*start = NULL;

void add_å(int n) {
	list* p = start, * q = p;
	q = new list;
	q->key = n;
	q->next = NULL;
	if (start)
	{
		while (p->next)
			p = p->next;
		p->next = q;
	}
	else
		start = q;
}

void print()
{
	if (start) {
		list* p = start;
		while (p) {
			cout << p->key << " ";
			p = p->next;
		}
	}
	else
		cout << "\n Empty list";
}


void help()
{
	list* p = start;
	list* q;
	list* r;
	list* t;
	list* i = NULL;
	bool isFirstElement = true;
	if (start) {

		while (p->next)
		{
			if (i != NULL) {
				i = i->next;
			}
			if (i == NULL && !isFirstElement) {
				i = start;
			}
			q = p;
			bool  shouldDeleteParent = false;

			while (q->next) {
				bool shouldRestart = false;
				if (q->next->key == p->key) {
					r = q->next;
					q->next = r->next;
					delete r;
					shouldDeleteParent = true;
					shouldRestart = true;
				}
				q = q->next;
				if (shouldRestart) {
					q = p;
				}
			}
			isFirstElement = false;
			if (shouldDeleteParent) {
				t = p;
				if (start == p) {
					start = start->next;
				}

				if (i) {
					i->next = t->next;
				}

				delete t;
				p = start;
				i = NULL;
				isFirstElement = true;
			}
			else {
				p = p->next;
			}

		}
	}
}


int main()
{
	int ch, num, br, i;
	do
	{
		cout << "\n\t Menu";
		cout << "\n 1.Add elements";
		cout << "\n 2.Print full list L";
		cout << "\n 3.Print list P, no repeating numbers";
		cout << "\n 4.Exit";
		do
		{
			cout << "\n Your choice is: ";
			cin >> ch;
		} while (ch < 1 || ch>4);
		switch (ch) {
		case 1:
			cout << "\n How many elements do you want to add? ";
			cin >> br;
			cout << "\n Input L-stack elements: " << endl;
			for (i = 0; i < br; i++)
			{
				cout << " ";
				cin >> num;
				add_å(num);
			}
			break;

		case 2:
			cout << "\n List is: " << endl;
			print(); break;
		case 3:
			help();
			help();
			cout << "List P: " << endl;
			print();
			break;
		}

	} while (ch != 4);
}

//Создаём библиоте
#include <iostream>
#include <cstring>
#include <list>

using std::cout;
using std::cin;
using std::endl;

using namespace std;

typedef struct {

	char title[100];
	char author[50];
	short year;

} BOOK;


int main() {

	list<BOOK> myList;

	BOOK book = {"Онегин", "Пушкин", 2000};
	myList.push_back(book);

	strcpy(book.title, "Муму");
	strcpy(book.author, "Тургенев");
	book.year = 1995;

	myList.push_front(book);

	strcpy(book.title, "Левша");
	strcpy(book.author, "Лесков");
	book.year = 2011;	


	list<BOOK>::iterator it;
	it = myList.begin();
	myList.insert(++it, book);

	for (it = myList.begin(); it !=  myList.end(); ++it) {
		book = *it;
		cout << book.title << " " << book.author << " " << book.year << endl;
	}

	myList.clear();

	return 0;

}

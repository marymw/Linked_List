//Создаём библиотеку

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


typedef struct tag_obj {

	BOOK b;
	struct tag_obj *prev, *next;

}OBJ;


OBJ *head = NULL, *tail = NULL;

void add_obj(OBJ* obj, BOOK book);
void del_obj(OBJ* obj);
void show();



int main() {

	BOOK book = {"Онегин", "Пушкин", 2000};
	add_obj(tail, book);

	strcpy(book.title, "Муму");
	strcpy(book.author, "Тургенев");
	book.year = 1995;

	add_obj(tail, book);

	strcpy(book.title, "Левша");
	strcpy(book.author, "Лесков");
	book.year = 2011;	

	add_obj(head, book);

	show();

	while (head != NULL) del_obj(head);

	return 0;

}


void add_obj(OBJ* obj, BOOK book){// вставка объекта с данными book после объекта  obj

	OBJ *ptr = new OBJ;

	ptr->b = book;
	ptr->prev = obj;
	ptr->next = (obj ==  NULL) ? NULL : obj->next;

	if (obj != NULL) {

		obj->next  = ptr;
		if(obj->next != NULL) obj->next->prev = ptr;

	}

	if (ptr->prev == NULL) head = ptr;
	if (ptr->next == NULL) tail = ptr;

}


void del_obj(OBJ* obj) {

	if (obj == NULL) return;

	OBJ* prev_obj = obj->prev;
	OBJ* next_obj = obj->next;

	cout << "Удален объект: " << obj->b.title << endl;
	delete obj;

	if (prev_obj != NULL) prev_obj->next = next_obj;
	else head = next_obj;

	if (next_obj != NULL) next_obj->prev = prev_obj;
	else tail = prev_obj;

}


void show() {

	OBJ* c = head;

	while (c != NULL) {
		cout << c->b.title << " " << c->b.author << " " << c->b.year << endl;
		c = c->next;
	}
}

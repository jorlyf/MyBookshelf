#pragma once
#include "Bookshelf.h"
#include "Book.h"
#include "Indents.h"
#include <iostream>
#include <conio.h>

using namespace std;

class Console
{
private:
	Bookshelf bookshelf; // основная модель данных
	char key;            // текущий выбор

	void print_menu();                                               // вывод меню
	void print_hello();                                              // вывод приветствия
	void print_books(vector<Book*> &books);                          // вывод всех книг
	void print_book(Book &book, Indents &indents, bool print_note);  // вывод книги
	void print_only_one_book(Book &book, Indents &indents);          // вывод книги с заголовками
	void print_header(Indents &indents);                             // вывод заголовков таблицы книг

	bool is_have_books(vector<Book*> &books);                        // проверить наличие книг

public:
	void run();           // запуск приложения
	static void set_ru(); // установка русского вывода/ввода в консоли
};

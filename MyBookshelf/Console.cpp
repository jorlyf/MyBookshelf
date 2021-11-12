#include "Console.h"
#include "Bookshelf.h"
#include "Utils.h"

void Console::run()
{
	print_hello();

	while (true)
	{
		print_menu();
		key = _getch();

		if (key != 27) // 27 = "ESC", его неправильно выводит
			cout << key << endl;

		switch (key)
		{
		case '1':
			print_books(bookshelf.get_books());
			break;
		case '2':
			break;
		case '3':
		{
			cout << "Введите название книги, либо нажмите Enter для выхода: ";
			string name = Utils::get_string(40);
			if (name.empty()) break; // нажатие Enter

			Book book = bookshelf.create_book(name);

			cout << "Введите автора книги, либо нажмите Enter для пропуска: ";
			string author = Utils::get_string(40);
			book.set_author(author);

			cout << "Введите жанр книги, либо нажмите Enter для пропуска: ";
			string genre = Utils::get_string(40);
			book.set_genre(genre);

			cout << "Введите рейтинг книги(1-10), либо введите 0 для пропуска: ";
			short rating = Utils::get_int(1, 10);
			book.set_rating(rating);

			cout << "Напишите свои мысли о книге, либо нажмите Enter для пропуска: ";
			string note = Utils::get_string(1024);
			book.set_note(note);

			Indents indents = Utils::get_print_indents(book);
			print_only_one_book(book, indents);
		inp:
			cout << "Вы действительно хотите сохранить данную книгу в своей библиотеке?(да/нет)" << endl;
			string answer = Utils::get_string(10);
			if (answer == "да") bookshelf.add_book(book);
			else if (answer == "нет") break;
			else goto inp;

			break;
		}
		case '4':
			break;
		case '5':
			break;
		case '6':
			break;
		case '0':
			break;
		case 27:
			cout << "ESC" << endl; // вывод выбора
			cout << "До встречи!" << endl;
			return;
		default:
			cout << "Нет такой команды!" << endl;
			break;
		}
	}

}
void Console::set_ru()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
}

void Console::print_menu()
{
	cout << "\n";
	cout << "    МЕНЮ:" << endl;
	cout << "1 - показать список книг" << endl;
	cout << "2 - посмотреть все подробности по книге" << endl;
	cout << "3 - добавить книгу" << endl;
	cout << "4 - отредактировать книгу" << endl;
	cout << "5 - удалить книгу" << endl;
	cout << "6 - найти книги по критериям" << endl;
	cout << "0 - справка" << endl;
	cout << "ESC - закрыть приложение" << endl;
	cout << "\n";
	cout << "Ваш выбор: ";
}
void Console::print_hello()
{
	cout << "Добро пожаловать в Вашу книжкую полку!" << endl;
}
void Console::print_books(vector<Book*>& books)
{
	if (!is_have_books(books)) { cout << "У вас нет ни одной книги!" << endl; return; }

	Indents indents = Utils::get_print_indents(books);
	print_header(indents);

	for (int i = 0; i < books.size(); i++)
	{
		Book& book = bookshelf.get_book_at(i);
		if (&book == nullptr) continue;

		print_book(book, indents, false);
	}
}
void Console::print_book(Book& book, Indents& indents, bool print_note)
{
	printf("%-*i", indents.id, book.get_id());
	printf("%-*s", indents.name, book.get_name().c_str());
	printf("%-*s", indents.author, book.get_author().c_str());
	printf("%-*s", indents.genre, book.get_genre().c_str());
	printf("%-*i", indents.rating, book.get_rating());
	printf("%-*s\n", indents.created_date, book.get_created_date().c_str());
	if (print_note) printf("%s\n", book.get_note().c_str());
}
void Console::print_only_one_book(Book& book, Indents& indents)
{
	print_header(indents);
	printf("%-*i", indents.id, book.get_id());
	printf("%-*s", indents.name, book.get_name().c_str());
	printf("%-*s", indents.author, book.get_author().c_str());
	printf("%-*s", indents.genre, book.get_genre().c_str());
	printf("%-*i", indents.rating, book.get_rating());
	printf("%-*s\n", indents.created_date, book.get_created_date().c_str());
	printf("%s\n", book.get_note().c_str());
}
void Console::print_header(Indents& indents)
{
	printf("%-*s", indents.id, "id");
	printf("%-*s", indents.name, "Название");
	printf("%-*s", indents.author, "Автор");
	printf("%-*s", indents.genre, "Жанр");
	printf("%-*s", indents.rating, "Рейтинг");
	printf("%-*s\n", indents.created_date, "Дата добавления");
}
bool Console::is_have_books(vector<Book*>& books)
{
	if (books.size() < 1) return false;
	return true;
}
#include "Console.h"
#include "Bookshelf.h"
#include "Utils.h"

void Console::run()
{
	print_hello(); // приветствие

	while (true)
	{
		print_menu();
		key = _getch();

		if (key != 27) // 27 - это "ESC", его неправильно выводит
			cout << key << endl;

		switch (key)
		{
		case '1':        // список книг
		{
			print_books(bookshelf.get_books());
			break;
		}
		case '2':        // получить информацию о книге
		{
			cout << "Введите id книги, про которую хотите найти больше информации, либо нажмите Enter для выхода: ";
			unsigned int id = Utils::get_int();
			if (id == 0) break; // нажатие Enter

			Book& book = bookshelf.get_book_by_id(id);
			if (&book == nullptr) { cout << "Такой книги не существует!" << endl; break; }

			print_only_one_book(book);
			break;
		}
		case '3':        // добавить книгу
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

			cout << "Введите рейтинг книги(1-10), либо нажмите Enter для пропуска: ";
			short rating = Utils::get_int(1, 10);
			book.set_rating(rating);

			cout << "Напишите свои мысли о книге, либо нажмите Enter для пропуска: ";
			string note = Utils::get_string(1024);
			book.set_note(note);

			print_only_one_book(book);

			string answer;
			do {
				cout << "Вы действительно хотите сохранить данную книгу в своей библиотеке?(да/нет)" << endl;
				string answer = Utils::get_lower_case_string(Utils::get_string(10));
				if (answer == "да") { bookshelf.add_book(book); break; }
				else if (answer == "нет") break;
			} while (answer != "нет" || answer != "да");

			break;
		}
		case '4':        // редактировать книг
		{
			cout << "Введите id книги, которую хотите отредактировать, либо нажмите Enter для выхода: ";
			unsigned int id = Utils::get_int();
			if (id == 0) break; // нажатие Enter

			Book& book = bookshelf.get_book_by_id(id);
			if (&book == nullptr) { cout << "Такой книги не существует!" << endl; break; }

			print_only_one_book(book);

			short prop;
			do {
				cout << "\n1 - Название, 2 - Автор, 3 - жанр, 4 - рейтинг, 5 - запись о книге" << endl;
				cout << "Выберите, что хотите изменить, либо нажмите Enter для выхода: ";
				prop = Utils::get_int(0, 5);
				if (prop == 0) break;

				cout << "Введите новое значение: ";
				switch (prop)
				{
				case 1:
				{
					string name = Utils::get_string(40);
					book.set_name(name);
					break;
				}
				case 2:
				{
					string author = Utils::get_string(40);
					book.set_author(author);
					break;
				}
				case 3:
				{
					string genre = Utils::get_string(25);
					book.set_genre(genre);
					break;
				}
				case 4:
				{
					short rating = Utils::get_int(1, 10);
					book.set_rating(rating);
					break;
				}
				case 5:
				{
					string note = Utils::get_string(1024);
					book.set_note(note);
					break;
				}

				}
			} while (prop != 0);
			bookshelf.save(); // сохранение изменений
			break;
		}
		case '5':        // удалить книги
		{
			cout << "Введите id книги, которую желаете удалить, либо нажмите Enter для выхода: ";
			unsigned int id = Utils::get_int();
			if (id == 0) break; // нажатие Enter

			Book& book = bookshelf.get_book_by_id(id);
			if (&book == nullptr) { cout << "Такой книги не существует!" << endl; break; }

			print_only_one_book(book);

			string answer;
			do {
				cout << "Вы действительно хотите удалить данную книгу из своей библиотеке?(да/нет)" << endl;
				string answer = Utils::get_lower_case_string(Utils::get_string(10));
				if (answer == "да") { bookshelf.delete_book(book); break; }
				else if (answer == "нет") break;
			} while (answer != "нет" || answer != "да");

			break;
		}
		case '6':        // сортировать список книг
			break;
		case '0':        // справка
			break;
		case 27:         // выход
		{
			cout << "ESC" << endl; // вывод выбора
			cout << "До встречи!" << endl;
			return;
		}
		default:         // не найдена команда
		{
			cout << "Нет такой команды!" << endl;
			break;
		}
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
	cout << "4 - отредактировать книги" << endl;
	cout << "5 - удалить книгу" << endl;
	cout << "6 - сортировать книги по критериям" << endl;
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
	if (book.get_rating() != 0) { printf("%-*i", indents.rating, book.get_rating()); }
	else // заполняю пробелами пространство
	{
		string spaces;
		for (int i = 0; i < indents.rating; i++)
			spaces += " ";
		printf(spaces.c_str());
	}

	printf("%-*s\n", indents.created_date, book.get_created_date().c_str());
	if (print_note) printf("%s\n", book.get_note().c_str());
}
void Console::print_only_one_book(Book& book)
{
	Indents indents = Utils::get_print_indents(book);
	print_header(indents);
	print_book(book, indents, true);
}
void Console::print_header(Indents& indents)
{
	printf("%-*s", indents.id, "id");
	printf("%-*s", indents.name, "Название");
	printf("%-*s", indents.author, "Автор");
	printf("%-*s", indents.genre, "Жанр");
	printf("%-*s", indents.rating, "Рейтинг");
	printf("%-*s\n", indents.created_date, "Дата занесения");
}
bool Console::is_have_books(vector<Book*>& books)
{
	if (books.size() < 1) return false;
	return true;
}
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

		if (key != 27) // 27 = "ESC", ��� ����������� �������
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
			cout << "������� �������� �����, ���� ������� Enter ��� ������: ";
			string name = Utils::get_string(40);
			if (name.empty()) break; // ������� Enter

			Book book = bookshelf.create_book(name);

			cout << "������� ������ �����, ���� ������� Enter ��� ��������: ";
			string author = Utils::get_string(40);
			book.set_author(author);

			cout << "������� ���� �����, ���� ������� Enter ��� ��������: ";
			string genre = Utils::get_string(40);
			book.set_genre(genre);

			cout << "������� ������� �����(1-10), ���� ������� 0 ��� ��������: ";
			short rating = Utils::get_int(1, 10);
			book.set_rating(rating);

			cout << "�������� ���� ����� � �����, ���� ������� Enter ��� ��������: ";
			string note = Utils::get_string(1024);
			book.set_note(note);

			Indents indents = Utils::get_print_indents(book);
			print_only_one_book(book, indents);
		inp:
			cout << "�� ������������� ������ ��������� ������ ����� � ����� ����������?(��/���)" << endl;
			string answer = Utils::get_string(10);
			if (answer == "��") bookshelf.add_book(book);
			else if (answer == "���") break;
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
			cout << "ESC" << endl; // ����� ������
			cout << "�� �������!" << endl;
			return;
		default:
			cout << "��� ����� �������!" << endl;
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
	cout << "    ����:" << endl;
	cout << "1 - �������� ������ ����" << endl;
	cout << "2 - ���������� ��� ����������� �� �����" << endl;
	cout << "3 - �������� �����" << endl;
	cout << "4 - ��������������� �����" << endl;
	cout << "5 - ������� �����" << endl;
	cout << "6 - ����� ����� �� ���������" << endl;
	cout << "0 - �������" << endl;
	cout << "ESC - ������� ����������" << endl;
	cout << "\n";
	cout << "��� �����: ";
}
void Console::print_hello()
{
	cout << "����� ���������� � ���� ������� �����!" << endl;
}
void Console::print_books(vector<Book*>& books)
{
	if (!is_have_books(books)) { cout << "� ��� ��� �� ����� �����!" << endl; return; }

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
	printf("%-*s", indents.name, "��������");
	printf("%-*s", indents.author, "�����");
	printf("%-*s", indents.genre, "����");
	printf("%-*s", indents.rating, "�������");
	printf("%-*s\n", indents.created_date, "���� ����������");
}
bool Console::is_have_books(vector<Book*>& books)
{
	if (books.size() < 1) return false;
	return true;
}
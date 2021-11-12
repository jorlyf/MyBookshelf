#pragma once
#pragma warning( disable: 4996 ) 
#include <string>
#include <time.h>


using namespace std;

class Book
{
private:
	unsigned int id;
	char name[40];
	char author[40];
	char genre[25];
	char created_date[50];
	char note[1024];
	short rating; // 1 - 10

	void set_created_date();

public:
	Book(unsigned int id, string name);

	unsigned int get_id();
	string get_name();
	string get_author();
	string get_genre();
	string get_created_date();
	string get_note();
	short get_rating();

	bool set_name(string value);
	bool set_author(string value);
	bool set_genre(string value);
	bool set_note(string value);
	bool set_rating(short value);
};

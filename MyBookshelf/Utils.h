#pragma once
#include "Indents.h"
#include "Book.h"
#include <vector>
#include <windows.h>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

static class Utils
{
public:
	static void clear_cin();
	static Indents get_print_indents(vector<Book*> &books);
	static Indents get_print_indents(Book& book);
	static string get_string(unsigned int max_length);
	static int get_int(unsigned int beginvalue, unsigned int endvalue);
	static int get_int();
	static string get_lower_case_string(string value);
};


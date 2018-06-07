 ///
 /// @file    String.cc
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-06-06 22:50:45
 ///
#include"String.h"
#include<string.h>
#include<stdio.h>
#include <iostream>
using std::cout;
using std::endl;
 
String::String()
: _pstr(NULL)
{
	//_pstr = new char [10]();
	//_pstr = NULL;
	cout << "String()" << endl;
}

String::String(const char * pstr)
: _pstr(new char [strlen(pstr) + 1]())
{
	strcpy(_pstr, pstr);
	cout << "String(const char *)" << endl;
}

String::String(const String & rhs)
: _pstr(new char [strlen(rhs._pstr) + 1]())
{
	strcpy(_pstr, rhs._pstr);
	cout << "String(const String &)" << endl;
}

String::~String()
{
	delete [] _pstr;
	_pstr = NULL;
	cout << "~String" << endl;
}

String & String::operator = (const String & rhs)
{
	if(this == &rhs)
		return (*this);
	delete [] _pstr;
	_pstr = new char [strlen(rhs._pstr) + 1]();
	if(_pstr != NULL)
	{
		strcpy(_pstr, rhs._pstr);
	}
	cout << "String & operator = (const String &)" << endl;
	return (*this);
}

void String::print()
{
	cout << "pstr =" << _pstr <<endl;
}

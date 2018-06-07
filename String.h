 ///
 /// @file    String.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-06-06 22:46:09
 ///

#ifndef __STRING_H__
#define __STRING_H__
#include<string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
	String();
	String(const char * pstr);
	String(const String & rhs);
	String & operator=(const String & rhs);
	~String();
	
	void print();

private:
	char * _pstr;
};

#endif

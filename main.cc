 ///
 /// @file    main.cc
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-06-06 23:02:33
 ///

#include"String.h"
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	String str1;
	str1.print();

	String str2 = "Hello world";
	String str3("wangdao");

	str2.print();
	str3.print();

	String str4 = str3;
	str4.print();

	str4 = str2;
	str4.print();

	return 0;
}

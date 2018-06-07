 ///
 /// @file    Computer.cc
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-06-07 16:16:12
 ///
 
#include<stdio.h>
#include<string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	Computer(const char * brand, double price)
	: _brand(new char [strlen(brand) + 1]())
	, _price(price)
	{
		cout << "Computer(const char *, double)" << endl;
		strcpy(_brand, brand);
		_totalPrice += _price;
	}

	Computer(const Computer & rhs)
	: _brand(new char [strlen(rhs._brand) + 1]())
	, _price(rhs._price)
	{
		strcpy(_brand, rhs._brand);
		cout << "Computer(const Computer & rhs)" << endl;
	}

#if 1
	Computer & operator=(const Computer & rhs)
	{
		cout << "Computer & operator=(const Computer & rhs)" << endl;
		_brand = rhs._brand;
		_price = rhs._price;
	}
#endif

#if 0
	Computer & operator=(const Computer & rhs)
	{
		cout << "Computer & operator=(const Computer & rhs)" << endl;
		if(this == &rhs)
			return *this;
		delete [] this->_brand;
		_brand = new char [strlen(rhs._brand) + 1];
		if(NULL != _brand)
			strcpy(_brand,rhs._brand);
		_price = rhs._price;
		return *this;
	}
#endif

	void print()
	{
		cout << "brand:" << _brand << endl;
		cout << "price:" << _price << endl;
	}

	void printtotal()
	{
		cout << "total:" << _totalPrice << endl;
	}

	~Computer()
	{
		delete [] _brand;
		//_brand = NULL;
		cout << "~Computer()" << endl;
	}

private:
	char * _brand;
	double _price;
	static double _totalPrice;
};

double Computer::_totalPrice = 0;

int test(void)
{
	Computer com1("DELL",6000);
	cout << "com1:" << endl;
	com1.print();
	cout << endl;

	Computer com2 = com1;
	cout << "com2:" << endl;
	com2.print();
	cout << endl;

	Computer com3("ASUS",7000);
	cout << "com3:" <<endl;
	com3.print();
	cout << endl;

	com3 = com1;
	cout << "after operator" << endl;
	com3.print();
	cout << endl;

	com3 = com3;

	return 0;
}

int test0(void)
{
	Computer com("ASUS",10000);
	cout << "com:" << endl;
	com.print();
	com.~Computer();

	return 0;
}
int test1(void)
{
	cout << "sizeof(Computer) = " << sizeof(Computer) << endl;
	Computer com1("DELL",6000);
	cout << "com1:" << endl;
	com1.print();
	com1.printtotal();
	cout << endl;

	Computer com2("ASUS",7000);
	cout << "com2:" << endl;
	com2.print();
	com2.printtotal();
	cout << endl;

	Computer com3("MAC",8000);
	cout << "com3:" << endl;
	com3.print();
	com3.printtotal();
	cout << endl;

	return 0;
}

int main(void)
{
	test();
	//test0();
	//test1();

	return 0;
}

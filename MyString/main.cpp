#include <iostream>

class myString {
	char* str;
	int size = 0;
public:

	myString()
	{
		str = nullptr;
	}

	myString& operator = (const char* c)
	{
		while (c[size] != '\0')
		{
			size++;
		}
		str = new char[size+1];
		for (int i = 0; i < size; i++)
		{
			str[i] = c[i];
		}
		str[size] = 0;
		std::cout << this << std::endl;
		return *this;
	}

	void ShowStr()
	{
		std::cout << str << std::endl;
	}

	~myString()
	{
		delete[] str;
	}
};

int main()
{

	myString st;
	st = "Hello World";
	st.ShowStr();

	return 0;
}
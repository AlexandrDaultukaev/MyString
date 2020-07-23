#include <iostream>

class myString {
	char* str;
	int size;
public:

	myString()
	{
		str = nullptr;
		size = 0;
	}

	myString& operator = (const char* c)
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}
		while (c[size] != '\0')
		{
			size++;
		}
		//strlen(c);
		str = new char[size+1];
		for (int i = 0; i < size; i++)
		{
			str[i] = c[i];
		}
		str[size] = '\0';
		//std::cout << this << std::endl;
		return *this;
	}


	myString& operator = (const myString& c)
	{
		if (this->str != nullptr)
		{
			delete[] this->str;
		}
		this->size = strlen(c.str);
		this->str = new char[this->size+1];
		for (int i = 0; i < this->size; i++)
		{
			str[i] = c.str[i];
		}
		str[size] = '\0';
		//std::cout << this << std::endl;
		return *this;
	}

	myString operator + (const myString& c)
	{
		int llenstr = strlen(this->str);
		int llenc = strlen(c.str);
		myString sum;
		sum.size = llenstr + llenc;
		sum.str = new char[sum.size + 1];
		int i = 0;
		for (; i < strlen(this->str); i++)
		{
			sum.str[i] = this->str[i];
		}
		for (int j = 0; j < strlen(c.str); j++, i++)
		{
			sum.str[i] = c.str[j];
		}
		sum.str[sum.size] = '\0';
		return sum;
	}

	myString(const char other[])
	{
		this->size = strlen(other);
		this->str = new char[this->size + 1];

		for (int i = 0; i < this->size; i++)
		{
			this->str[i] = other[i];
		}

		this->str[size] = '\0';
	}

	myString(const myString& other)
	{
		this->size = strlen(other.str);
		this->str = new char[this->size + 1];

		for (int i = 0; i < this->size; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[size] = '\0';
	}

	myString(char* c)
	{
		this->size = strlen(c);
		this->str = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			this->str[i] = c[i];
		}
		this->str[this->size] = '\0';
	}


	void ShowStr()
	{
		std::cout << this->str << std::endl;
	}

	~myString()
	{
		delete[] this->str;
	}
};

int main()
{

	//myString st;
	//st = "Hello World";
	//st.ShowStr();

	return 0;
}

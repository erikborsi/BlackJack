#include <string>

using namespace std;

class Value
{
	int _value;
protected:
	void setValue(int valuein);
	int getValue();

};

void Value::setValue(int valuein)
{
	_value = valuein;
}

int Value::getValue()
{
	return _value;
}
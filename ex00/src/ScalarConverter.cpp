#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _c( 0 ), _i( 0 ), _f ( 0 ), _d( 0 ), _s( 0 ), _l( 0 ) {}

ScalarConverter::ScalarConverter( std::string str ) : _s(str), _l(_s.length())
{
	std::cout << "str: " << _s << std::endl << "length: " << _l << std::endl;
	setType();
}

ScalarConverter::ScalarConverter( const ScalarConverter &object )
{
	*this = object;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=( const ScalarConverter &object )
{
	_c = object.getChar();
	_i = object.getInt();
	_f = object.getFloat();
	_d = object.getDouble();
	_type = object.getType();
	_s = object._s;

	return *this;
}

bool	ScalarConverter::checkChar()
{
	if (_l == 1 && isalpha(_s[0]))
		return true;
	return false;
}

bool	ScalarConverter::checkInt()
{
	int i = (_s[0] == '-') ? 1 : 0;

	for(int i = 0; i < _l; i++)
	{
		if (!isdigit(_s[i]))
			break ;
		if (i == (_l - 1))
			return true;
	}
	return false;
}

bool	ScalarConverter::checkFloat()
{
	int i = (_s[0] == '-') ? 1 : 0;
	int	p = 0;

	if (_s[_l - 1] != 'f')
		return false;
	for (; i < (_l - 1); i++)
	{
		if (_s[i] == '.')
		{
			p++;
			if (p > 1)
				return false;
			continue ;
		}
		if (!isdigit(_s[i]))
			return false;
	}
	return true;
}

bool	ScalarConverter::checkDouble()
{
	int i = (_s[0] == '-') ? 1 : 0;
	int	p = 0;

	for (; i < _l; i++)
	{
		if (_s[i] == '.')
		{
			p++;
			if (p > 1)
				return false;
			continue ;
		}
		if (!isdigit(_s[i]))
			return false;
	}
	return true;
}


void	ScalarConverter::convert( ScalarConverter &object )
{
	switch (object.getType())
	{
		case 0:
			object.printChar();
			break ;
		case 1:
			object.printInt();
			break ;
		case 2:
			object.printFloat();
			break ;
		case 3:
			object.printDouble();
			break ;
		default:
			std::cout << "not a type" << std::endl;
	}
}

void	ScalarConverter::setType()
{
	if (checkChar())
		_type = c;
	else if (checkInt())
		_type = i;
	else if (checkFloat())
		_type = f;
	else if (checkDouble())
		_type = d;
	else
		_type = n;
	return ;
}

ScalarConverter::Types	ScalarConverter::getType()
{
	return _type;
}

char	ScalarConverter::getChar() const
{
	return _c;
}

char	ScalarConverter::getInt() const
{
	return _i;
}

char	ScalarConverter::getFloat() const
{
	return _f;
}

char	ScalarConverter::getDouble() const
{
	return _d;
}

void	ScalarConverter::printChar()
{
	if (isprint(getChar()))
		std::cout << "char: " << _s[0] << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	_i = static_cast<int>(_s[0]);
	_f = static_cast<float>(_s[0]);
	_d = static_cast<double>(_s[0]);
	std::cout << "int: " << getInt() << std::endl;
	std::cout << "float: " << getFloat() << std::endl;
	std::cout << "double: " << getDouble() << std::endl;
}

void	ScalarConverter::printInt()
{
	if (isprint(getInt()))
		_c = static_cast<char>(getInt());
	std::cout << "char: " << getChar() << std::endl;
	if (getInt() > std::numeric_limits<int>::max() || getInt() < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << getInt() << std::endl;
	_f = static_cast<float>(getInt());
	_d = static_cast<double>(getInt());
	std::cout << "float: " << getFloat() << std::endl;
	std::cout << "double: " << getDouble() << std::endl;
}
void	ScalarConverter::printFloat()
{
	
}
void	ScalarConverter::printDouble()
{
	
}

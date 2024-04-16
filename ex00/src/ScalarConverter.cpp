#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter( const ScalarConverter &object )
{
	*this = object;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=( const ScalarConverter &object )
{
	(void)object;
	return *this;
}

void	ScalarConverter::convert( std::string str )
{
	int type;
	
	try
	{
		type = setType(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	switch (type)
	{
		case 1:
			convertChar(str);
			break;
		case 2:
			convertInt(str);
			break;
		case 3:
			convertFloat(str);
			break;
		case 4:
			convertDouble(str);
			break;
		case 5:
			convertPseudoLit(str);
			break;
		default:
			std::cout << "Error: invalid input" << std::endl;
			break;
	}
}

void	ScalarConverter::convertInt( std::string str )
{
	char c;
	double i;
	float f;
	double d;

	i = std::atoi(str.c_str());
	c = static_cast<char>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);
	if (!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	if (f > FLT_MAX || f < -FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << ".0f" << std::endl;
	if (d > DBL_MAX || d < -DBL_MAX)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;
}

void	ScalarConverter::convertChar( std::string str )
{
	char c;
	int i;
	float f;
	double d;

	c = static_cast<char>(str[0]);
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
	if (!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	if (f > FLT_MAX || f < -FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << ".0f" << std::endl;
	if (d > DBL_MAX || d < -DBL_MAX)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;
}

void	ScalarConverter::convertFloat( std::string str )
{
	char c;
	double i;
	float f;
	double d;
	std::istringstream iss(str);

	iss >> f;
	c = static_cast<char>(f);
	i = static_cast<int>(f);
	d = static_cast<double>(f);
	if (!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	if (f > FLT_MAX || f < -FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << ".0f" << std::endl;
	if (d > DBL_MAX || d < -DBL_MAX)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;
}

void	ScalarConverter::convertDouble( std::string str )
{
	char c;
	double i;
	float f;
	double d;
	std::istringstream iss(str);

	iss >> d;
	c = static_cast<char>(d);
	i = static_cast<int>(d);
	f = static_cast<float>(d);
	if (!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	if (f > FLT_MAX || f < -FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << ".0f" << std::endl;
	if (d > DBL_MAX || d < -DBL_MAX)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;
}

void	ScalarConverter::convertPseudoLit( std::string str )
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (str == "+inff" || str == "-inff" || str == "nanf")
		std::cout << "float: " << str << std::endl;
	else
		std::cout << "float: " << str << "f" << std::endl;
	if (str == "+inff" || str == "-inff" || str == "nanf")
	{
		std::string s = str.substr(0, str.length() - 1);
		std::cout << "double: " << s << std::endl;
	}
	else
		std::cout << "double: " << str << std::endl;
}


bool	ScalarConverter::checkChar ( std::string str )
{
	if (str.length() == 1 && isalpha(str[0]))
		return true;
	return false;
}

bool	ScalarConverter::checkInt ( std::string str )
{
	int i = (str[0] == '-') ? 1 : 0;

	for(int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			break ;
		if (i == (str.length() - 1))
			return true;
	}
	return false;
}

bool	ScalarConverter::checkFloat ( std::string str )
{
	int i = (str[0] == '-') ? 1 : 0;
	int	p = 0;
	int len = str.length();

	if (str[len - 1] != 'f')
		return false;
	for (; i < (len - 1); i++)
	{
		if (str[i] == '.')
		{
			p++;
			if (p > 1)
				return false;
			continue ;
		}
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

bool	ScalarConverter::checkDouble ( std::string str )
{
	int i = (str[0] == '-') ? 1 : 0;
	int	p = 0;
	int len = str.length();

	for (; i < len; i++)
	{
		if (str[i] == '.')
		{
			p++;
			if (p > 1)
				return false;
			continue ;
		}
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::checkPseudoLit( std::string str )
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return true;
	return false;
}

int	ScalarConverter::setType( std::string str )
{
	if (checkChar(str))
		return 1;
	else if(checkInt(str))
		return 2;
	else if(checkFloat(str))
		return 3;
	else if(checkDouble(str))
		return 4;
	else if (checkPseudoLit(str))
		return 5;
	else
		throw InvalidInputException();

}

const char* ScalarConverter::InvalidInputException::what() const throw()
{
	return "Error: invalid input.";
}

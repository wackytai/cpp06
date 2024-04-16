#include "../inc/ScalarConverter.hpp"

int	main ( int argc, char** argv )
{
	if (argc != 2)
	{
		std::cout << "Usage: ./converter <data>" << std::endl;
		return 1;
	}

	std::string str(argv[1]);
	ScalarConverter::convert(str);
	
	return 0;
}
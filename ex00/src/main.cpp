#include "../inc/ScalarConverter.hpp"

int	main ( int argc, char** argv )
{
	if (argc != 2)
	{
		std::cout << "Usage: ./converter <data>" << std::endl;
		return 1;
	}

	ScalarConverter	obj(argv[1]);

	obj.convert(obj);
	
	return 0;
}
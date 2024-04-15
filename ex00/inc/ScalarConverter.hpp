#ifndef	SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <iomanip>
# include <sstream>
# include <cfloat>
# include <cstring>
# include <string>
# include <limits>
# include <climits>
# include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter( const ScalarConverter &object );

	public:
		~ScalarConverter();
		ScalarConverter &operator=( const ScalarConverter &object );
		static void		convert( std::string str );
		static void		convertInt( std::string str );
		static void		convertChar( std::string str );
		static void		convertFloat( std::string str );
		static void		convertDouble( std::string str );
		static void		convertPseudoLit( std::string str );
		static bool		checkInt ( std::string str );
		static bool		checkChar ( std::string str );
		static bool		checkFloat ( std::string str );
		static bool		checkDouble ( std::string str );
		static bool 	checkPseudoLit( std::string str );
		static int		setType( std::string str );
};

#endif
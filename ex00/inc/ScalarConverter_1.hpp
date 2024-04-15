#ifndef	SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <cstring>
# include <string>
# include <limits>
# include <climits>
# include <cmath>

class ScalarConverter
{
	private:
		enum	Types
		{
			c, i, f, d, n
		}	_type;
		ScalarConverter();
		ScalarConverter( std::string str );

	public:
		ScalarConverter( const ScalarConverter &object );
		~ScalarConverter();
		ScalarConverter &operator=( const ScalarConverter &object );
		static void	convert( std::string str );
		bool		checkChar ();
		bool		checkInt ();
		bool		checkFloat ();
		bool		checkDouble ();
		void		setType();
};

#endif
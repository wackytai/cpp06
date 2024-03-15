#ifndef	SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <cstring>
# include <string>
# include <limits>
# include <cmath>

class ScalarConverter
{
	private:
		char		_c;
		int			_i;
		float		_f;
		double		_d;
		std::string	_s;
		int			_l;
		enum	Types
		{
			c, i, f, d, n
		}	_type;
		ScalarConverter( std::string str );

	public:
		ScalarConverter();
		ScalarConverter( const ScalarConverter &object );
		~ScalarConverter();
		ScalarConverter &operator=( const ScalarConverter &object );
		static void	convert( ScalarConverter &object );
		bool		checkChar ();
		bool		checkInt ();
		bool		checkFloat ();
		bool		checkDouble ();
		void		setType();
		Types		getType();
		char		getChar() const;
		char		getInt() const;
		char		getFloat() const;
		char		getDouble() const;
		void		printChar();
		void		printInt();
		void		printFloat();
		void		printDouble();
};

#endif
#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base	*generate( void );
void	identify( Base *p );
void	identify( Base &p );

int	main()
{
	Base	*obj_1;

	obj_1 = generate();
	identify( obj_1 );
	if ( obj_1 )
		delete obj_1;
	return 0;
}

Base	*generate( void )
{
	enum	Types { a, b, c, n };
	Types	_type;
	
	//choose how to randomly assign a value between 0-2 to _type
	switch( _type )
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
		case 3:
			return NULL;
	}
}

void	identify( Base *p )
{
	A	*a = dynamic_cast<A*>(p);
	B	*b = dynamic_cast<B*>(p);
	C	*c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "p points to an object of type A" << std::endl;
	else if (b)
		std::cout << "p points to an object of type B" << std::endl;
	else if (c)
		std::cout << "p points to an object of type C" << std::endl;
	else
		std::cout << "p points to an object not of type A, B or C" << std::endl;
}

void	identify( Base &p )
{
	//since a reference can be NULL, use try & catch blocks to throw exceptions!
}

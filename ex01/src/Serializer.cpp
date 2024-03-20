#include "../inc/Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer( const Serializer &obj )
{
	*this = obj;
}

Serializer::~Serializer() {}

Serializer& Serializer::operator=( const Serializer &obj )
{
	(void) obj;
	return *this;
}

uintptr_t	Serializer::serialize( Data* ptr )
{
	return reinterpret_cast<unintptr_t>( ptr );
}

Data*		Serializer::deserialize( uintptr_t raw )
{
	return reinterpret_cast<Data*>( raw );
}

#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::Fixed(const Fixed& other): number(other.number){std::cout << "Copy constructor called" << std::endl;}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj){

	std::cout << "Copy assignment operator called" << std::endl;
	this->number = obj.number;
	return (*this);
}
int Fixed::getRawBits(void) const
{
	std::cout << "GetRawBits member function called" << std::endl;
	return (this->number);
}
void Fixed::setRawBits (int const raw)
{
	std::cout << "SetRawBits member function called" << std::endl;
	this->number = raw;
}

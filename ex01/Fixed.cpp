#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}
Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	this->number = other.getRawBits();
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value){
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(value << this->fractional);
}
Fixed::Fixed(const float value){
	std::cout << "Float constructor called" << std::endl;
	int fpoint_one = (1 << this->fractional);
	this->setRawBits(roundf(fpoint_one * value));
}
Fixed& Fixed::operator=(const Fixed& obj){

	std::cout << "Copy assignment operator called" << std::endl;
	this->number = obj.getRawBits();
	return (*this);
}
int Fixed::getRawBits(void) const
{
	std::cout << "GetRawBits member function called" << std::endl;
	return (this->number);
}
void Fixed::setRawBits (int const raw)
{
	this->number = raw;
}
float Fixed::toFloat( void ) const
{
	return (roundf(this->number) / (1 << this->fractional));
}
int Fixed::toInt( void ) const
{
	return (this->number >> this->fractional);
}
std::ostream& operator<<(std::ostream& ostream, const Fixed &obj)
{
	ostream << obj.toFloat();
	return (ostream);

}

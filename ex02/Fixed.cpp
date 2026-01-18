#include "Fixed.hpp"

Fixed::Fixed(){
	// std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}
Fixed::Fixed(const Fixed& other){
	// std::cout << "Copy constructor called" << std::endl;
	this->number = other.getRawBits();
}

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value){
	// std::cout << "Int constructor called" << std::endl;
	this->setRawBits(value << this->fractional);
}
Fixed::Fixed(const float value){
	// std::cout << "Float constructor called" << std::endl;
	int fpoint_one = (1 << this->fractional);
	this->setRawBits(roundf(fpoint_one * value));
}
Fixed& Fixed::operator=(const Fixed& obj){

	// std::cout << "Copy assignment operator called" << std::endl;
	this->number = obj.getRawBits();
	return (*this);
}
int Fixed::getRawBits(void) const
{
	// std::cout << "GetRawBits member function called" << std::endl;
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

	bool Fixed::operator>(const Fixed& obj) const{return (this->number > obj.number);}
	bool Fixed::operator<(const Fixed& obj) const{return (this->number < obj.number);}
	bool Fixed::operator>=(const Fixed& obj) const{return (this->number >= obj.number);}
	bool Fixed::operator<=(const Fixed& obj) const{return (this->number <= obj.number);}
	bool Fixed::operator==(const Fixed& obj) const{return (this->number == obj.number);}
	bool Fixed::operator!=(const Fixed& obj) const{return (this->number != obj.number);}
	Fixed Fixed::operator*(const Fixed& obj) const
{
	Fixed instance = *this;
	long long numb = instance.number * obj.number;
	instance.number = (int)(numb >> instance.fractional);
	return (instance);
}
	Fixed Fixed::operator-(const Fixed& obj) const
{
	Fixed instance = *this;
	instance.number -=obj.number;
	return(instance);
}
	Fixed Fixed::operator+(const Fixed& obj) const
{
	Fixed instance = *this;
	instance.number += obj.number;
	return (instance);
}
	Fixed Fixed::operator/(const Fixed& obj) const
{
	Fixed instance = *this;
	long long numb = instance.number << instance.fractional;
	instance.number = numb / obj.number;
	return(instance);
 }
	Fixed& Fixed::operator++()
{
	this->number += 1;
	return (*this);
}
	Fixed& Fixed::operator--()
{
	this->number -= 1;
	return (*this);
}
	Fixed Fixed::operator++(int)
{
	Fixed instance(*this);
	this->number += 1;
	return (instance);

}
	Fixed Fixed::operator--(int)
{
	Fixed instance(*this);
	this->number -= 1;
	return (instance);

}
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	else
		return(b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return(a);
	else
		return (b);

}
std::ostream& operator<<(std::ostream& ostream, const Fixed &obj)
{
	ostream << obj.toFloat();
	return (ostream);

}

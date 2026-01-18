#pragma once

#include <iostream>
#include <cmath>
class Fixed {
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& obj);
	~Fixed();
	float toFloat( void ) const;
	int toInt( void ) const;
	Fixed& operator=(const Fixed& obj);
	bool operator>(const Fixed& obj) const;
	bool operator<(const Fixed& obj) const;
	bool operator>=(const Fixed& obj) const;
	bool operator<=(const Fixed& obj) const;
	bool operator==(const Fixed& obj) const;
	bool operator!=(const Fixed& obj) const;
	Fixed operator*(const Fixed& obj) const;
	Fixed operator-(const Fixed& obj) const;
	Fixed operator+(const Fixed& obj) const;
	Fixed operator/(const Fixed& obj) const;
	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	int getRawBits(void) const;
	void setRawBits (int const raw);
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
private:
  int number;
  static const int fractional = 8;
};
std::ostream& operator<<(std::ostream& Ostream, const Fixed &obj);


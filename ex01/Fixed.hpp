#pragma once

#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& obj);
	~Fixed();
	Fixed& operator=(const Fixed& obj);
	int getRawBits(void) const;
	void setRawBits (int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
private:
  int number;
  static const int fractional = 8;
};


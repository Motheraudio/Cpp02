#pragma once

#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(const Fixed& obj);
	~Fixed();
	Fixed& operator=(const Fixed& obj);
	int getRawBits(void) const;
	void setRawBits (int const raw);
private:
  int number;
  static const int fractional = 8;
};


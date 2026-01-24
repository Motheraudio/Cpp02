#include <iostream>
#include "Fixed.hpp"
int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
std::cout << "-------------------------------" << std::endl;
std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
std::cout << "b / a: " << b / a << std::endl;
std::cout << "a - b: " << a - b << std::endl;
std::cout << "a + b: " << a + b << std::endl;
std::cout << "a + b: " << a + b << std::endl;
std::cout << "a--: " << a-- << std::endl;
std::cout << "--a: " << --a << std::endl;
std::cout << "==: " << (a == b) << std::endl;
std::cout << ">: " << (a > b) << std::endl;
std::cout << ">=: " << (a >= b) << std::endl;
std::cout << "<: " << (a < b) << std::endl;
std::cout << "<=: " << (a <= b) << std::endl;
std::cout << "!=: " << (a != b) << std::endl;
Fixed const x(10.1f);
Fixed const y(10.2f);
Fixed l (0);
Fixed k (-1);
std::cout << "min(l, k)" << Fixed::min(l, k) << std::endl;
std::cout << "max(l, k)" << Fixed::max(l, k) << std::endl;
std::cout << "min(x, y)" << Fixed::min(x, y) << std::endl;
std::cout << "max(x, y)" << Fixed::max(x, y) << std::endl;
return 0;
}

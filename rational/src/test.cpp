#include "rational.h"

#include <iostream>
#include <iomanip>

int main() {
  auto a = Rational{ 1, 3 }; // the number 1/3
  auto b = Rational{ -6, 7 }; // the number -6/7
  std::cout << a << " * " << b << " = " << a * b << "\n";
  std::cout << "a / ( a + b / a ) = " << a / ( a + b / a ) << "\n";
  std::cout << "a - b = " << a - b << "\n";
  std::cout << "1 / a = " << a.inverse() << "\n";
  std::cout << "a < b is " << (a < b) << "\n";
  std::cout << "b < a is " << (b < a) << "\n";
  std::cout << "a == b is " << (a == b) << "\n";
  std::cout << "a == 1/3 is " << (a == Rational { 1, 3 }) << "\n";
  std::cout << "Sign of a and b are " << a.sign() << " & " << b.sign() << "\n";
  std::cout << "1/0 is " << Rational{ 1, 0 } << "\n";
;
  auto phi = Rational{ 1 };

  for( int i = 0; i < 40; ++i ) {
    phi = 1 / ( 1 + phi );
  }
  std::cout << std::setprecision( 15 );
  std::cout << "phi (float) = " << ( 1 + phi ).to_float() << "\n";
  std::cout << "phi (double) = " << ( 1 + phi ).to_double() << "\n";

  return 0;
}

#include <cmath>
#include <iostream>

const double PI = 3.14159265359;

int main(int argc, char const *argv[]) {
  if (argc > 1) {
    double radius = atof(argv[1]);
    double area = PI * pow(radius, 2.0);
    std::cout << "Circle area = " << area << " m^2.\n";
  } else {
    std::cerr << "Error! You haven't inputted a radius!\n";
    return 1;
  }
  return 0;
}
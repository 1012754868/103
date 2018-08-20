#include <cmath>
#include <iostream>

const double PI = 3.14159265359;

void parse_flags(int argc, char const *argv[]);
void print_usage(char const *argv[]);
void print_version();

int main(int argc, char const *argv[]) {
  if (argc == 1) {
    std::cerr << "\nERROR! No flags supplied! \n";
    print_usage(argv);
    return 1;
  }
  parse_flags(argc, argv);
  return 0;
}

void parse_flags(int argc, char const *argv[]) {
  // this flag is used to check for valid input
  bool valid = false;
  // start at 1 so not to include the program name
  for (int i = 1; i < argc; i++) {
    // check for valid flags, use if,if,if rather than if,else if so we can
    // supply multiple (valid) flags
    if (std::string(argv[i]) == "-u" || std::string(argv[i]) == "--usage") {
      print_usage(argv);
      valid = true;
    }
    if (std::string(argv[i]) == "-v" || std::string(argv[i]) == "--version") {
      print_version();
      valid = true;
    }
    if (std::string(argv[i]) == "-r" || std::string(argv[i]) == "--radius") {
      valid = true;
      // need to make sure a value has been entered as well as -r
      if (i + 1 < argc) {
        double radius = atof(argv[i + 1]);
        double area = PI * pow(radius, 2.0);
        std::cout << "\nCircle area = " << area << " m^2.\n\n";
      } else {
        std::cerr << "\nERROR! -r option requires radius value!\n\n";
        print_usage(argv);
        exit(1);
      }
    }
  }
  // if not come across valid flag, then print usage instructions and exit
  if (valid == false) {
    std::cerr << "\nERROR! Invalid flags supplied!\n\n";
    print_usage(argv);
    exit(1);
  }
}

void print_usage(char const *argv[]) {
  std::cout << "\nUsage: " << argv[0] << " FLAGS\n\n";
  std::cout << "Flags:\n\n-r,--radius RADIUS\tinput circle radius.\n";
  std::cout << "-u,--usage\t\tprint usage instructions.\n";
  std::cout << "-v,--version\t\tprint version number.\n\n";
}

void print_version() { std::cout << "\nVersion 1.0.1\n"; }
#include <chrono>
#include <iostream>
#include <random>
#include <regex>

int get_random_number(int low, int high);
void print_line(int n);
void print_word(std::string word);
void welcome();
bool is_integer(std::string num);
int get_input(int low, int high);

int main(int argc, char const *argv[]) {
  welcome();
  int low = 1;
  int high = 10;

  // beginning of game loop
  int n = get_random_number(low, high);
  std::cout << n
            << std::endl;  // for de-bugging only! Comment out to play properly
  std::cout << "You need to guess the number in the range " << low << " to "
            << high << std::endl;
  int guess = get_input(low, high);

  if (guess == n) {
    std::cout << "You've guess correctly! Winner!\n\n";
  } else {
    std::cout << "Incorrect! Loser!\n\n";
  }
  // end of game loop

  print_line(80);
}

int get_random_number(int low, int high) {
  int seed =
      std::chrono::high_resolution_clock::now().time_since_epoch().count();
  std::mt19937 generator(seed);
  std::uniform_int_distribution<int> distribution(low, high);
  return distribution(generator);
}

void print_line(int n) {
  for (int i = 0; i < n; i++) {
    std::cout << "#";
  }
}

void print_word(std::string word) {
  int length = word.length();
  for (int i = 0; i < (80 - length) / 2 - 1; i++) {
    std::cout << " ";
  }
  std::cout << word << std::endl;
}

void welcome() {
  print_line(80);
  std::cout << "\n\n";
  print_word("Welcome to the Guessing Game!");
}

// https://codereview.stackexchange.com/questions/162569/checking-if-each-char-in-a-string-is-a-decimal-digit
bool is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

int get_input(int low, int high) {
  std::string guess_string;
  bool valid_input = false;
  int guess = 0;

  do {
    std::cout << "\nHave a guess: ";
    std::cin >> guess_string;
    valid_input = is_integer(guess_string);
    // if input is not an integer, print an error message
    if (valid_input == false) {
      std::cout << "You didn't enter an integer!\n";
    } else {  // if it is an int, check whether in range
      guess = std::stoi(guess_string);  // convert to int
      if (guess > low && guess < high) {
        valid_input = true;
      } else {
        std::cout << "Input out of range!\n";
        valid_input = false;
      }
    }
  } while (valid_input == false);

  return guess;
}
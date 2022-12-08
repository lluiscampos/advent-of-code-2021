#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {

  unsigned int max = 0;

  std::ifstream infile("day1.input");

  unsigned int current = 0;

  std::string line;
  while (std::getline(infile, line)) {
    std::istringstream iss(line);
    int a;
    if (!(iss >> a)) {

      std::cout << current << " " << max << std::endl;
      if (current > max) {
        max = current;
      }
      current = 0;

    } else {

      current += a;
      std::cout << "processed: " << a << std::endl;
    }
  }

  std::cout << current << " " << max << std::endl;
  if (current > max) {
    max = current;
  }
  current = 0;

  std::cout << "solution: " << max << std::endl;

  return 0;
}
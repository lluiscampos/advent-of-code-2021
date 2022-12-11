#include <fstream>
#include <iostream>
#include <list>
#include <numeric>
#include <sstream>
#include <string>

#include "days.hpp"

void day1() {
  std::ifstream infile("day1.input");

  std::list<unsigned int> calories;
  unsigned int current = 0;

  std::string line;
  while (std::getline(infile, line)) {
    std::istringstream iss(line);
    int a;
    if (!(iss >> a)) {
      calories.push_back(current);
      current = 0;
    } else {
      current += a;
    }
  }
  calories.push_back(current);

  calories.sort();
  std::cout << "day 1 part 1 solution: " << calories.back() << std::endl;

  std::list<unsigned int> calories_top3;
  auto it = calories.begin();
  std::advance(it, calories.size() - 3);
  calories_top3.splice(calories_top3.begin(), calories, it, calories.end());
  std::cout << "day 1 part 2 solution: "
            << std::accumulate(calories_top3.begin(), calories_top3.end(), 0)
            << std::endl;
}

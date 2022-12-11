#include <fstream>
#include <iostream>
#include <list>
#include <numeric>
#include <sstream>
#include <string>

#include "days.hpp"

typedef enum Hand {
  rock,
  paper,
  scissors,
} Hand;

Hand char_to_hand(char c) {
  if (c == 'A' or c == 'X') {
    return rock;
  }
  if (c == 'B' or c == 'Y') {
    return paper;
  }
  if (c == 'C' or c == 'Z') {
    return scissors;
  }
  std::cout << "ERROR ERROR ERROR " << c << std::endl;
  return rock;
}

int shape_score(Hand hand) {
  if (hand == rock) {
    return 1;
  }
  if (hand == paper) {
    return 2;
  }
  if (hand == scissors) {
    return 3;
  }
  std::cout << "ERROR ERROR ERROR" << std::endl;
  return 0;
}

int match_score(Hand mine, Hand opponent) {
  if (mine == rock) {
    if (opponent == scissors) {
      return 6;
    }
    if (opponent == paper) {
      return 0;
    }
    return 3;
  }
  if (mine == paper) {
    if (opponent == scissors) {
      return 0;
    }
    if (opponent == rock) {
      return 6;
    }
    return 3;
  }
  if (mine == scissors) {
    if (opponent == rock) {
      return 0;
    }
    if (opponent == paper) {
      return 6;
    }
    return 3;
  }

  std::cout << "ERROR ERROR ERROR" << std::endl;
  return 0;
}

void day2() {
  std::cout << "hello day 2" << std::endl;

  std::ifstream infile("day2.input");

  unsigned int total_score = 0;

  std::string line;
  while (std::getline(infile, line)) {
    std::istringstream iss(line);
    char a, b;
    if (!(iss >> a >> b)) {
      std::cout << "done" << std::endl;
    } else {
      Hand his_hand = char_to_hand(a);
      Hand my_hand = char_to_hand(b);
      int round_score = shape_score(my_hand) + match_score(my_hand, his_hand);
      std::cout << a << " vs " << b << " = " << round_score << std::endl;
      total_score += round_score;
    }
  }

  std::cout << "day 2 part 1 solution: " << total_score << std::endl;
}

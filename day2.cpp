#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#include "days.hpp"

class Hand {
public:
  int shape_score() { return shape_scores[mine]; }
  int match_score(Hand &opponent) {
    if (opponent.get_shape() == wins) {
      return 6;
    }
    if (opponent.get_shape() == loses) {
      return 0;
    }
    return 3;
  }
  Hand ideal_win() { return Hand(loses, mine, wins); }
  Hand ideal_loss() { return Hand(wins, loses, mine); }

protected:
  typedef enum HandShape {
    rock,
    paper,
    scissors,
  } HandShape;

  Hand(HandShape m, HandShape w, HandShape l) : mine(m), wins(w), loses(l){};
  HandShape get_shape() const { return mine; }

private:
  HandShape mine, wins, loses;
  std::map<HandShape, int> shape_scores = {
      {rock, 1}, {paper, 2}, {scissors, 3}};
};

class RockHand : public Hand {
public:
  RockHand() : Hand(rock, scissors, paper){};
};

class PaperHand : public Hand {
public:
  PaperHand() : Hand(paper, rock, scissors){};
};

class ScissorsHand : public Hand {
public:
  ScissorsHand() : Hand(scissors, paper, rock){};
};

Hand hand_factory(char c) {
  if (c == 'A' or c == 'X') {
    return RockHand();
  }
  if (c == 'B' or c == 'Y') {
    return PaperHand();
  }
  if (c == 'C' or c == 'Z') {
    return ScissorsHand();
  }
  std::cout << "ERROR ERROR ERROR " << c << std::endl;
  return RockHand();
}

Hand ideal_hand_factory(Hand opponent, char c) {
  if (c == 'X') {
    return opponent.ideal_loss();
  }
  if (c == 'Y') {
    return opponent;
  }
  if (c == 'Z') {
    return opponent.ideal_win();
  }
  std::cout << "ERROR ERROR ERROR " << c << std::endl;
  return opponent;
}

void day2() {
  std::ifstream infile("day2.input");

  unsigned int total_score_p1 = 0;
  unsigned int total_score_p2 = 0;
  std::string line;
  while (std::getline(infile, line)) {
    std::istringstream iss(line);
    char a, b;
    if (!(iss >> a >> b)) {
      std::cout << "done" << std::endl;
    } else {
      Hand his_hand = hand_factory(a);
      Hand my_hand = hand_factory(b);
      int round_score_p1 =
          my_hand.shape_score() + my_hand.match_score(his_hand);
      total_score_p1 += round_score_p1;
      Hand my_ideal_hand = ideal_hand_factory(his_hand, b);
      int round_score_p2 =
          my_ideal_hand.shape_score() + my_ideal_hand.match_score(his_hand);
      total_score_p2 += round_score_p2;
    }
  }

  std::cout << "day 2 part 1 solution: " << total_score_p1 << std::endl;
  std::cout << "day 2 part 2 solution: " << total_score_p2 << std::endl;
}

#include <cassert>
#include <iostream>
#include <set>
#include <map>


std::map<int, std::set<std::string>> memo{{0, std::set<std::string>({})}};


void printSet(std::set<std::string> &set, int nStairs) {
  std::cout << "STAIRS(" << nStairs << "):" << std::endl;
  for ( auto s : set ) {
    std::cout << s << std::endl;
  }
}


std::set<std::string> ways2(int nStairs) {
  if ( memo.count(nStairs) > 0 ) {
    return memo[nStairs];
  }

  std::set<std::string> set = {};
  for ( int i = 1; i < nStairs; i++ ) {
    std::set<std::string> sub = ways2(i);
    for ( auto &s : sub ) {
      set.insert(std::to_string(nStairs - i) + "+" + s);
      set.insert(s + "+" + std::to_string(nStairs - i));
    }
  }

  set.insert(std::to_string(nStairs));

  printSet(set, nStairs);

  memo[nStairs] = set;

  return set;
}


int main(int argc, char *argv[]) {

  {
    std::set<std::string> expected = {};
    assert(ways2(0) == expected);
  }
  {
    std::set<std::string> expected = {"1"};
    assert(ways2(1) == expected);
  }
  {
    std::set<std::string> expected = {"1+1", "2"};
    assert(ways2(2) == expected);
  }
  {
    std::set<std::string> expected = {"1+1+1", "2+1", "1+2", "3"};
    assert(ways2(3) == expected);
  }
  {
    std::set<std::string> expected = {"1+1+1+1", "1+1+2", "1+2+1", "2+1+1", "1+3", "3+1", "2+2", "4" };
    assert(ways2(4) == expected);
  }

  int n = 10;
  std::set<std::string> set = ways2(n);
  printSet(set, n);
}

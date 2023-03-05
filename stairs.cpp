#include <cassert>
#include <iostream>
#include <map>

std::map<int, int> memo;


int ways2(int nStairs) {
  if ( nStairs < 2 ) {
    return nStairs;
  }

  return ways2(nStairs - 1) * 2;
}

unsigned int ways(int nStairs) {
  if ( nStairs == 0 ) {
    return 0;
  }

  if ( memo.count(nStairs) > 0 ) {
    return memo[nStairs];
  }

  unsigned int total = 0;
  for ( int i = 1; i < nStairs; i++ ) {
    total += ways(i);
  }

  memo[nStairs] = total + 1;

  std::cout << nStairs << ": " << total + 1 << std::endl;

  return total + 1;
}


int main(int argc, char *argv[]) {

  assert(ways(0) == 0);   //
  assert(ways(1) == 1);   // 1
  assert(ways(2) == 2);   // 1+1; 2
  assert(ways(3) == 4);   // 1+1+1; 1+2, 2+1; 3
  assert(ways(4) == 8);   // 1+1+1+1; 1+1+2, 1+2+1, 2+1+1; 1+3, 2+2, 3+1; 4
  assert(ways(5) == 16);

  for ( int i = 2; i < 31; i *= 2 ) {
    assert(ways(i) == ways2(i));
  }

  int n = 32;
  unsigned int w = ways(n);
  std::cout << n << ": " << w << std::endl;

}

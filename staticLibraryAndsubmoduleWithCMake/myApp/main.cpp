#include <iostream>
#include "addition.h"

using namespace std;

int main() {
  cout << "2 + 2 = " << myLibrary::add(2, 2) << endl;
  return EXIT_SUCCESS;
}
#include <stdlib.h>
#include <stdio.h>
#include <optionalLibraryConfig.h>

#ifdef USE_SIMPLE_MATH_LIBRARY
#include <simpleMath.h>
#endif

int main(int argc, char *argv[]) {

  printf("%s version %i.%i.%i\n", argv[0], OPTIONALLIBRARY_VERSION_MAJOR, OPTIONALLIBRARY_VERSION_MINOR, OPTIONALLIBRARY_VERSION_PATCH);

#ifdef USE_SIMPLE_MATH_LIBRARY
  printf("2 + 2 = %i\n", addInts(2, 2));
#else
  printf("Simple math not available\n");
#endif

  return EXIT_SUCCESS;
}
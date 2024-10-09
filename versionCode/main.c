#include <stdlib.h>
#include <stdio.h>
#include <simpleMath.h>
#include <versionCodeConfig.h>

int main(int argc, char *argv[]) {

  printf("%s version %i.%i.%i\n", argv[0], VERSIONCODE_VERSION_MAJOR, VERSIONCODE_VERSION_MINOR, VERSIONCODE_VERSION_PATCH);

  printf("2 + 2 = %i\n", addInts(2, 2));

  return EXIT_SUCCESS;
}
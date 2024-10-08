#include <iostream>
#include "addition.h"
#include <GLFW/glfw3.h>

using namespace std;

int main() {
  cout << "2 + 2 = " << myLibrary::add(2, 2) << endl;

  GLFWwindow* window;

  /* Initialize the library */
  if (!glfwInit()) {
    return EXIT_FAILURE;
  }

  // Create a windowed mode window and its OpenGL context
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  
  if (!window)
  {
      glfwTerminate();
      return EXIT_FAILURE;
  }

  // Main loop

  while (!glfwWindowShouldClose(window))
  {
      /* Swap front and back buffers */
      glfwSwapBuffers(window);

      /* Poll for and process events */
      glfwPollEvents();
  }

  glfwTerminate();

  return EXIT_SUCCESS;
}
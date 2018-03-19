/**
   utilities - extra functions that didn't really belong
   inside of a class or the main file.
 */

#include "utilities.h"

using namespace std;

void printGlmMat4(glm::mat4 m) {
  for (unsigned int i = 0; i < 4; i++) {
    for (unsigned int j = 0; j < 4; j++) {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void printGlmVec3(glm::vec3 v) {
  for (unsigned int i = 0; i < 3; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

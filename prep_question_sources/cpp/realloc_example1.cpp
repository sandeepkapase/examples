// [[file:~/github/prep/cpp/Questions.org::c++ realloc_example1 example.][c++ realloc_example1 example.]]
#include <assert.h>
#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>
#include <forward_list>
#include <vector>






using namespace std;
int main(int argc, char*argv[]) {
  void * ptr = malloc(sizeof(int)*100); // allocated memory for 100 integer
  if (ptr == NULL) { cout << "\nMemory allocation failed. Exitting...."; exit(EXIT_FAILURE);}
  // required more memory now. Resize it to 200

  ptr = realloc(ptr, sizeof(int)*200); // Don't assing it to ptr, as in case of failure we will lose reference to old memory.
  if (ptr == NULL) { cout << "\nMemory reallocation failed. Exitting...."; exit(EXIT_FAILURE);}
  free(ptr);
  cout << "\nMemory release done.";
  return 0;
}
// c++ realloc_example1 example. ends here

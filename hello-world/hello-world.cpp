#include <iostream>
#include <vector>
#include <string>

//using namespace std;

int main() {
  std::vector<std::string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

  for (const std::string& word : msg) {
    std::cout << word << " ";
  }
  std::cout << std::endl;

  return 0;
}
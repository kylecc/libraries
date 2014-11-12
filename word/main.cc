#include "word.h"
using namespace std;

int main() {
  Word w("2.0.");
  cout << w.asDouble() << endl;
  
  return 0;
}

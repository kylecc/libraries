#include "word.h"

Word::Word() {
  array = NULL;
  delimiters = NULL;
  init("\0");
}

Word::Word(char c) {
  array = NULL;
  delimiters = NULL;
  char* temp = new char[2];
  check(temp != NULL, "Word::Word(char) : Out of memory");
  temp[0] = c;
  temp[1] = '\0';
  init(temp);
}

Word::Word(int n) {
  array = NULL;
  delimiters = NULL;
  int s = 0, t;
  char* temp;
  bool negative = false;
  if(n < 0) {
    negative = true;
    n *= -1;
  }
  t = n;
  if(t == 0) {
    s = 1;
  }
  while(t > 0) {
    t /= 10;
    ++s;
  }
  if(negative) {
    ++s;
  }
  temp = new char[s + 1];
  check(temp != NULL, "Word::Word(int) : Out of memory");
  if(negative) {
    temp[0] = '-';
  }
  temp[s] = '\0';
  while(s > negative) {
    temp[--s] = n % 10 + '0';
    n /= 10;
  }
  init(temp);
}

Word::Word(const char* c) {
  array = NULL;
  delimiters = NULL;
  init(c);
}

Word::Word(const char* c, const char* d) {
  array = NULL;
  delimiters = NULL;
  init(c, d);
}

Word::Word(Word& w) {
  array = NULL;
  delimiters = NULL;
  *this = w;
}

Word::~Word() {
  delete []array;
  delete []delimiters;
}

void Word::init(const char* arr) {
  init(arr, " \t\n");
}

void Word::init(const char* arr, const char* del) {
  check(arr != NULL, "Word::init(char*) : Null pointer");
  check(del != NULL, "Word::init(char*) : Null pointer");
  size = (int)strlen(arr) + 1;
  if(array != NULL) {
    delete []array;
  }
  array = new char[size];
  check(array != NULL, "Word::init(char*, char*) : Out of memory");
  strcpy(array, arr);
  count = (int)strlen(array);
  if(delimiters != NULL) {
    delete []delimiters;
  }
  delimiters = new char[(int)strlen(del)];
  check(delimiters != NULL, "Word::init(char*, char* : Out of memory");
  strcpy(delimiters, del);
}

char* Word::toLowerCase() {
  char* temp = new char[size + 1];
  check(temp != NULL, "Word::toLowerCase() : Out of memory");
  strcpy(temp, array);
  for(int i = 0; i < count; ++i) {
    if(temp[i] >= 'A' && temp[i] <= 'Z') {
      temp[i] += 32;
    }
  }
  return temp;
}

char* Word::toUpperCase() {
  char* temp = new char[size + 1];
  check(temp != NULL, "Word::toUpperCase() : Out of memory");
  strcpy(temp, array);
  for(int i = 0; i < count; ++i) {
    if(temp[i] >= 'a' && temp[i] <= 'z') {
      temp[i] -= 32;
    }
  }
  return temp;
}

Word& Word::operator+ (const char* c) {
  size += (int)strlen(c);
  char* temp = new char[size + 1];
  check(temp != NULL, "Word::operator+ (char*) : Out of memory");
  strcpy(temp, array);
  strcat(temp, c);
  return *this;
}

Word& Word::operator+ (const Word& w) {
  size += w.size;
  char* temp = new char[size + 1];
  check(temp != NULL, "Word::operator+ (Word) : Out of memory");
  strcpy(temp, array);
  strcat(temp, w.array);
  return *this;
}

Word& Word::operator= (const char* c) {
  init(c);
  return *this;
}

Word& Word::operator= (const Word& w) {
  init(w.array, w.delimiters);
  return *this;
}

std::ostream& operator<< (std::ostream& out, const Word& w) {
  out << w.array;
  return out;
}

char* Word::cString() const {
  char* temp = new char[size + 1];
  check(temp != NULL, "Word::cString() : Out of memory");
  strcpy(temp, array);
  return temp;
}

int Word::length() const {
  return count;
}

int Word::asInt() const {
  for(int i = 0; i < count; ++i) {
    check(array[i] >= '0' && array[i] <= '9', "Word::asInt() : Non-integer string");
  }
  return atoi(array);
}

double Word::asDouble() const {
  bool dot = false;
  for(int i = 0; i < count; ++i) {
    check((array[i] >= '0' && array[i] <= '9') || !dot++, "Word::asDouble() : Non-double string");
  }
  return atof(array);
}

void Word::setDelimiters(const char* del) {
  check(del != NULL, "Word::setDelimiters(char*) : Null pointer");
  char* temp = new char[(int)strlen(del)];
  check(temp != NULL, "Word::setDelimiters(char*) : Out of memory");
  strcpy(temp, del);
  delete []delimiters;
  delimiters = temp;
}

bool Word::operator< (const char* c) const {
  return strcmp(array, c) < 0;
}

bool Word::operator< (const Word& w) const {
  return strcmp(array, w.array) < 0;
}

bool Word::operator<= (const char* c) const {
  return strcmp(array, c) <= 0;
}

bool Word::operator<= (const Word& w) const {
  return strcmp(array, w.array) <= 0;
}

bool Word::operator> (const char* c) const {
  return strcmp(array, c) > 0;
}

bool Word::operator> (const Word& w) const {
  return strcmp(array, w.array) > 0;
}

bool Word::operator>= (const char* c) const {
  return strcmp(array, c) >= 0;
}

bool Word::operator>= (const Word& w) const {
  return strcmp(array, w.array) >= 0;
}

bool Word::operator== (const char* c) const {
  return strcmp(array, c) == 0;
}

bool Word::operator== (const Word& w) const {
  return strcmp(array, w.array) == 0;
}

bool Word::operator!= (const char* c) const {
  return !(*this == c);
}

bool Word::operator!= (const Word& w) const {
  return !(*this == w);
}

char Word::operator[] (const int index) const {
  check(index >= 0 && index < count, "Word::operator[] const : Invalid index");
  return array[index];
}

char& Word::operator[] (const int index) {
  check(index >= 0 && index < count, "Word::operator[] : Invalid index");
  return array[index];
}

#include "check.h"
#include <cstring>

class Word {
private:
  char* array, *delimiters;
  int size, count;
  static const int DEFSIZE = 10;

  void init(const char* arr);
  void init(const char* arr, const char* del);
public:
  Word();
  Word(char c);
  Word(int n);
  Word(const char* c);
  Word(const char* c, const char* d);
  Word(Word& w);
  ~Word();
  void setDelimiters(const char* del);
  char* cString() const;
  int length() const;
  int asInt() const;
  double asDouble() const;
  char* toLowerCase();
  char* toUpperCase();
  Word& substring(const int startIndex);
  Word& substring(const int startIndex, const int endIndex);
  Word& operator+ (const char* c);
  Word& operator+ (const Word& w);
  Word& operator= (const char* c);
  Word& operator= (const Word& w);
  bool operator< (const char* c) const;
  bool operator< (const Word& w) const;
  bool operator<= (const char* c) const;
  bool operator<= (const Word& w) const;
  bool operator> (const char* c) const;
  bool operator> (const Word& w) const;
  bool operator>= (const char* c) const;
  bool operator>= (const Word& w) const;
  bool operator== (const char* c) const;
  bool operator== (const Word& w) const;
  bool operator!= (const char* c) const;
  bool operator!= (const Word& w) const;
  char operator[] (const int index) const;
  char& operator[] (const int index);
  friend std::ostream& operator<< (std::ostream& out, const Word& w);
};

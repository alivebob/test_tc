// Copyright 2018 <Author>

#ifndef TYPING_MACHINE_H_
#define TYPING_MACHINE_H_

#include <string>

#include "node.h"

class TypingMachine {
 public:
  TypingMachine();
  void HomeKey();
  void EndKey();
  void LeftKey();
  void RightKey();
  bool TypeKey(char key);
  bool EraseKey();
  std::string Print(char separator);
private:
	Node *m_home;
	Node *m_end;
	Node *m_cur;
	int m_len;
	std::string m_str;
};

#endif  // TYPING_MACHINE_H_

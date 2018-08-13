// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
	m_home = m_end = m_cur = new Node('\0');
	m_len = 0;
}

void TypingMachine::HomeKey() {
	m_cur = m_home;
}

void TypingMachine::EndKey() {
	m_cur = m_end;
}

void TypingMachine::LeftKey() {
	if (m_cur->GetPreviousNode())
		m_cur = m_cur->GetPreviousNode();
}

void TypingMachine::RightKey() {
	if (m_cur->GetNextNode())
		m_cur = m_cur->GetNextNode();
}

bool TypingMachine::TypeKey(char key) {
	Node *p;

	if (key < 0x20 || key > 0x7E)
		return false;

	if (!m_cur)
		return false; // ASSERT

	if (m_len >= 100)
		return false;

	p = m_cur->InsertPreviousNode(key);
	m_len++;

	if (m_home == m_cur)
		m_home = p;

	return true;
}

bool TypingMachine::EraseKey() {
	int ret;
	if (!m_cur)
		return false; // ASSERT

	if (m_cur->GetPreviousNode() == m_home)
		m_home = m_cur;

	ret = m_cur->ErasePreviousNode();

	if (ret) m_len--;

	return ret;
}

std::string TypingMachine::Print(char separator) {
	Node *p = m_home;

	m_str.clear();
	while (p) {
		char c;
		if (p == m_cur && separator != 0)
			m_str.push_back(separator);
		c = p->GetData();
		if (c == '\0') break;
		m_str.push_back(c);
		p = p->GetNextNode();
	}

	return m_str;
}

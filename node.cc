// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
	m_prev = m_next = nullptr;
	m_data = data;
  return;
}

char Node::GetData() {
  return m_data;
}

Node* Node::GetPreviousNode() {
  return m_prev;
}

Node* Node::GetNextNode() {
  return m_next;
}

Node* Node::InsertPreviousNode(char data) {
	Node *a = new Node(data);

	if (m_prev)
		m_prev->m_next = a;

	a->m_prev = m_prev;
	a->m_next = this;
	m_prev = a;

	return a;
}

Node* Node::InsertNextNode(char data) {
	Node *a = new Node(data);

	if (m_next)
		m_next->m_prev = a;

	a->m_next = m_next;
	a->m_prev = this;
	m_next = a;

	return a;
}

bool Node::ErasePreviousNode() {
	Node *a = m_prev;

	if (!a)
		return false;

	if (a->m_prev)
		a->m_prev->m_next = this;
	m_prev = a->m_prev;

	delete a;

	return true;
}

bool Node::EraseNextNode() {
	Node *a = m_next;

	if (!a)
		return false;

	if (a->m_next)
		a->m_next->m_prev = this;
	m_next = a->m_next;

	delete a;

	return true;
}

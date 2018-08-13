// Copyright 2018 Minkyu Jo

#include "node.h"
#include "node_test.h"
#include "test.h"

class NodeConstructorTestSuite
{
private:
  static void SingleNodeTest() {
    Node *node = new Node('A');
    ASSERT_EQ(node->GetData(), 'A');
    delete node;
  }

public:
  static void RunTest() {
    SingleNodeTest();
    // add more..
  }
};

class InsertNodeTestSuite
{
private:
	static void InsertPrivousNodeTest() {
		Node *node = new Node('A');
		char b = 'B';
		Node *inserted_node = node->InsertPreviousNode(b);
		ASSERT_EQ(inserted_node, node->GetPreviousNode());
		ASSERT_EQ(inserted_node->GetData(), b);
		delete node->GetPreviousNode();
		delete node;
	}
	static void InsertNextNodeTest() {
		Node *node = new Node('A');
		char b = 'B';
		Node *inserted_node = node->InsertNextNode(b);
		ASSERT_EQ(inserted_node, node->GetNextNode());
		ASSERT_EQ(inserted_node->GetData(), b);
		delete node->GetNextNode();
		delete node;
	}
public:
	static void RunTest() {
		InsertPrivousNodeTest();
		InsertNextNodeTest();
		// add more..
	}
};

class DeleteNodeTestSuite
{
private:
	static void DeletePreviousNodeTest() {
		Node *node = new Node('A');
		char b = 'B';
		char c = 'C';
		ASSERT_TRUE(node);
		node->InsertPreviousNode(b);
		node->InsertPreviousNode(c);
		bool is_del = node->ErasePreviousNode();

		ASSERT_TRUE(is_del);
		ASSERT_EQ(node->GetPreviousNode()->GetData(), b);

		is_del = node->ErasePreviousNode();
		ASSERT_TRUE(is_del);
		ASSERT_TRUE(node->GetPreviousNode() == nullptr);

		is_del = node->ErasePreviousNode();
		ASSERT_FALSE(is_del);

		delete node;
	}

	static void DeleteNextNodeTest() {
		Node *node = new Node('A');
		char b = 'B';
		char c = 'C';
		ASSERT_TRUE(node);
		node->InsertNextNode(b);
		node->InsertNextNode(c);
		bool is_del = node->EraseNextNode();

		ASSERT_TRUE(is_del);
		ASSERT_EQ(node->GetNextNode()->GetData(), b);

		is_del = node->EraseNextNode();
		ASSERT_TRUE(is_del);
		ASSERT_TRUE(node->GetNextNode() == nullptr);

		is_del = node->EraseNextNode();
		ASSERT_FALSE(is_del);

		delete node;
	}

public:
	static void RunTest() {
		DeletePreviousNodeTest();
		DeleteNextNodeTest();
		// add more..
	}
};

class SomeOtherTestSuite
{
private:

public:
  static void RunTest() {
    // add more..
  }
};

void NodeTest() {
  NodeConstructorTestSuite::RunTest();
  InsertNodeTestSuite::RunTest();
  DeleteNodeTestSuite::RunTest();
  // add more..
}
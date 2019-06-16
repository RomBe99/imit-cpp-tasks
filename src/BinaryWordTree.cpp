#include "../headers/BinaryWordTree.h"

BinaryWordTree::Node::Node(const std::string& word, Node* leftLeaf, Node* rightLeaf)
{
    if (word . length() == 0) {
        throw std::exception();
    }

    this -> word = word;
    this -> leftLeaf = leftLeaf;
    this -> rightLeaf = rightLeaf;
}

void BinaryWordTree::Node::add()
{
    count++;
}

void BinaryWordTree::Node::reduce()
{
    count--;
}

int BinaryWordTree::Node::compare(const std::string& otherString) const
{
    if (otherString . length() == 0) {
        throw std::exception();
    }

    return word . compare(otherString);
}

void BinaryWordTree::Node::print(BinaryWordTree::Node*& node)
{
    if (node == nullptr) return;

    print(node -> leftLeaf);
    std::cout << node -> word << ' ' << node -> count << std::endl;
    print(node -> rightLeaf);
}

void BinaryWordTree::Node::findNode(BinaryWordTree::Node*& node, bool& isFind, const std::string& word, int& count)
{
    if (isFind) {
        return;
    }
    else if (node == nullptr) {
        return;
    }

    const int COMPARE_RESULT = node -> compare(word);

    if (COMPARE_RESULT == 0) {
        isFind = true;
        count = node -> count;

        return;
    }
    else if (COMPARE_RESULT > 0) {
        findNode(node -> leftLeaf, isFind, word, count);
    }
    else if (COMPARE_RESULT < 0) {
        findNode(node -> rightLeaf, isFind, word, count);
    }
}

void BinaryWordTree::Node::addWord(Node*& node, const std::string& word)
{
    if (node == nullptr) {
        return;
    }

    const int COMPARE_RESULT = node -> compare(word);

    if (COMPARE_RESULT == 0) {
        node -> add();
        return;
    }
    else if (COMPARE_RESULT > 0) {
        if (node -> leftLeaf == nullptr) {
            node -> leftLeaf = new Node(word);
            return;
        }
        else {
            addWord(node -> leftLeaf, word);
        }
    }
    else if (COMPARE_RESULT < 0) {
        if (node -> rightLeaf == nullptr) {
            node -> rightLeaf = new Node(word);
            return;
        }
        else {
            addWord(node -> rightLeaf, word);
        }
    }
}

BinaryWordTree::Node*& BinaryWordTree::Node::findLeftLeaf(BinaryWordTree::Node*& node)
{
    if (node -> leftLeaf != nullptr) {
        findLeftLeaf(node -> leftLeaf);
    }

    return node;
}

void BinaryWordTree::Node::deleteWord(BinaryWordTree::Node*& node, const std::string& word)
{
    if (node == nullptr) {
        return;
    }

    const int COMPARE_RESULT = node -> compare(word);

    if (COMPARE_RESULT == 0) {
        node -> reduce();
        if (node -> count == 0) {
            // TODO Придумать что делать в этом случае
        }
        return;
    }
    else if (COMPARE_RESULT == -1) {
        addWord(node -> leftLeaf, word);
    }
    else if (COMPARE_RESULT == 1) {
        addWord(node -> rightLeaf, word);
    }
}

void BinaryWordTree::Node::deleteNode(BinaryWordTree::Node*& node)
{
    if (node == nullptr) return;

    deleteNode(node -> leftLeaf);
    deleteNode(node -> rightLeaf);
    delete node;
    node = nullptr;
}

BinaryWordTree::Node::~Node()
{
    delete &word;
    leftLeaf = nullptr;
    rightLeaf = nullptr;
}

BinaryWordTree::BinaryWordTree(const std::string& rootWord)
{
    root = new Node(rootWord);
    treeSize = 1;
}

void BinaryWordTree::print()
{
    if (isEmpty()) {
        std::cout << "Binary tree is empty" << std::endl;
    }
    else {
        BinaryWordTree::Node::print(root);
    }
}

int BinaryWordTree::findWordEntries(const std::string& word)
{
    int count = 0;
    bool isFind = false;

    BinaryWordTree::Node::findNode(root, isFind, word, count);

    return count;
}

void BinaryWordTree::addWord(const std::string& word)
{
    treeSize++;
    BinaryWordTree::Node::addWord(root, word);
}

void BinaryWordTree::deleteWord(const std::string& word)
{
    BinaryWordTree::Node::deleteWord(root, word);
}

bool BinaryWordTree::isEmpty() const
{
    return root == nullptr;
}

size_t BinaryWordTree::getTreeSize() const
{
    return treeSize;
}

BinaryWordTree::~BinaryWordTree()
{
    BinaryWordTree::Node::deleteNode(root);
}
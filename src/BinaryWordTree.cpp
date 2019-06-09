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
    else if (node -> compare(word) == -1) {
        findNode(node -> leftLeaf, isFind, word, count);
    }
    else if (node -> compare(word) == 0) {
        isFind = true;
        count = node -> count;

        return;
    }
    else if (node -> compare(word) == 1) {
        findNode(node -> rightLeaf, isFind, word, count);
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

int BinaryWordTree::Node::compare(const std::string& otherString) const
{
    if (otherString . length() == 0) {
        throw std::exception();
    }

    return word . compare(otherString);
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
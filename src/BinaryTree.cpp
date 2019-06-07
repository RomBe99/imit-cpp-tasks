#include "../headers/BinaryTree.h"

BinaryTree::Node::Node(int value, BinaryTree::Node* rightLeaf, BinaryTree::Node* leftLeaf)
        :value(value), rightLeaf(rightLeaf), leftLeaf(leftLeaf) {}

void BinaryTree::Node::print(const BinaryTree::Node* node, const long n)
{
    if (node == nullptr) return;

    print(node -> rightLeaf, n + 5);

    for (long i = 0; i < n; i++) {
        std::cout << ' ';
    }

    std::cout << node -> value << std::endl;

    print(node -> leftLeaf, n + 5);
}

bool BinaryTree::Node::isPositive(const BinaryTree::Node* node)
{
    if (node == nullptr) {
        return true;
    }
    else if (node -> value >= 0 && isPositive(node -> leftLeaf) && isPositive(node -> rightLeaf)) {
        return true;
    }

    return false;
}

void BinaryTree::Node::average(const BinaryTree::Node* node, int& sum, int& count)
{
    if (node == nullptr) {
        return;
    }

    sum += node -> value;
    count++;

    average(node -> leftLeaf, sum, count);
    average(node -> rightLeaf, sum, count);
}

bool BinaryTree::Node::check(const BinaryTree::Node* node, int min, int max)
{
    if (node == nullptr) {
        return true;
    }
    else if (node -> value <= min || max <= node -> value) {
        return false;
    }

    return check(node -> leftLeaf, min, node -> value) && check(node -> rightLeaf, node -> value, max);
}

void BinaryTree::Node::deleteNode(BinaryTree::Node*& node)
{
    if (node != nullptr) {
        deleteNode(node -> leftLeaf);
        deleteNode(node -> rightLeaf);
        delete node;
        node = nullptr;
    }
}

BinaryTree::BinaryTree(const int rootValue)
{
    root = new Node(rootValue);
}

void BinaryTree::insert(const int x, const int sequenceSize, const int sequence[])
{
    Node* temp = root;

    for (int i = 0; i < sequenceSize; i++) {
        if (sequence[i] == 0) {
            if (temp -> leftLeaf == nullptr) {
                temp -> leftLeaf = new Node(x);

                return;
            }

            temp = temp -> leftLeaf;
        }
        else if (sequence[i] == 1) {
            if (temp -> rightLeaf == nullptr) {
                temp -> rightLeaf = new Node(x);

                return;
            }

            temp = temp -> rightLeaf;

        }
    }

    temp -> value = x;
}

void BinaryTree::print() const
{
    if (isEmpty()) {
        std::cout << "Binary tree is empty" << std::endl;
    }
    else {
        BinaryTree::Node::print(root, 0);
    }
}

bool BinaryTree::isPositive() const
{
    return isEmpty() ? true : BinaryTree::Node::isPositive(root);
}

double BinaryTree::average() const
{
    if (isEmpty()) {
        return 0;
    }

    int sum = 0;
    int count = 0;

    BinaryTree::Node::average(root, sum, count);

    return (double) sum / count;
}

bool BinaryTree::isBinarySearchTree() const
{
    if (isEmpty()) {
        return false;
    }

    return BinaryTree::Node::check(root, INT32_MIN, INT32_MAX);
}

bool BinaryTree::isEmpty() const
{
    return root == nullptr;
}

BinaryTree::~BinaryTree()
{
    BinaryTree::Node::deleteNode(root);
    delete root;
}
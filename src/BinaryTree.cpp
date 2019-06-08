#include "../headers/BinaryTree.h"

BinaryTree::Node::Node(int value, BinaryTree::Node* rightLeaf, BinaryTree::Node* leftLeaf)
{
    this -> value = value;
    this -> rightLeaf = rightLeaf;
    this -> leftLeaf = leftLeaf;
}

void BinaryTree::Node::print(BinaryTree::Node*& node, const long n)
{
    if (node == nullptr) return;

    const int SHIFT = 5;

    print(node -> rightLeaf, n + SHIFT);

    for (long i = 0; i < n; i++) {
        std::cout << ' ';
    }

    std::cout << node -> value << std::endl;

    print(node -> leftLeaf, n + SHIFT);
}

void BinaryTree::Node::numberOfEvenNumbers(BinaryTree::Node*& node, int& count)
{
    if (node == nullptr) {
        return;
    }

    if (node -> value % 2 == 0) {
        count++;
    }

    numberOfEvenNumbers(node -> leftLeaf, count);
    numberOfEvenNumbers(node -> rightLeaf, count);
}

bool BinaryTree::Node::isPositive(BinaryTree::Node*& node)
{
    if (node == nullptr) {
        return true;
    }
    else if (node -> value >= 0 && isPositive(node -> leftLeaf) && isPositive(node -> rightLeaf)) {
        return true;
    }

    return false;
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

void BinaryTree::Node::deleteAllLeafs(BinaryTree::Node*& node)
{
    if (node == nullptr) {
        return;
    }
    else if (node -> leftLeaf == nullptr && node -> rightLeaf == nullptr) {
        deleteNode(node);
        return;
    }

    deleteAllLeafs(node -> leftLeaf);
    deleteAllLeafs(node -> rightLeaf);
}

void BinaryTree::Node::average(BinaryTree::Node*& node, int& sum, int& count)
{
    if (node == nullptr) {
        return;
    }

    sum += node -> value;
    count++;

    average(node -> leftLeaf, sum, count);
    average(node -> rightLeaf, sum, count);
}

void BinaryTree::Node::findRoute(BinaryTree::Node*& node, bool& isFind, const int& x, std::vector<int>*& route)
{
    if (isFind) {
        return;
    }
    else if (node == nullptr) {
        return;
    }
    else if (node -> value == x) {
        isFind = true;

        return;
    }

    route -> push_back(0);
    findRoute(node -> leftLeaf, isFind, x, route);

    if (!isFind) {
        route -> pop_back();
        route -> push_back(1);

        findRoute(node -> rightLeaf, isFind, x, route);

        if (!isFind) {
            route -> pop_back();
        }
    }
}

bool BinaryTree::Node::check(BinaryTree::Node*& node, const int& min, const int& max)
{
    if (node == nullptr) {
        return true;
    }
    else if (node -> value <= min || max <= node -> value) {
        return false;
    }

    return check(node -> leftLeaf, min, node -> value) && check(node -> rightLeaf, node -> value, max);
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

void BinaryTree::print()
{
    if (isEmpty()) {
        std::cout << "Binary tree is empty" << std::endl;
    }
    else {
        BinaryTree::Node::print(root, 0);
    }
}

int BinaryTree::numberOfEvenNumbers()
{
    if (isEmpty()) {
        return 0;
    }

    int count = 0;
    BinaryTree::Node::numberOfEvenNumbers(root, count);

    return count;
}

bool BinaryTree::isPositive()
{
    return isEmpty() ? true : BinaryTree::Node::isPositive(root);
}

void BinaryTree::deleteAllLeafs()
{
    BinaryTree::Node::deleteAllLeafs(root);
}

double BinaryTree::average()
{
    if (isEmpty()) {
        return 0;
    }

    int sum = 0;
    int count = 0;

    BinaryTree::Node::average(root, sum, count);

    return (double) sum / count;
}

std::vector<int>* BinaryTree::findRoute(const int x)
{
    if (isEmpty()) {
        return nullptr;
    }

    auto route = new std::vector<int>();
    bool isFind = false;

    BinaryTree::Node::findRoute(root, isFind, x, route);
    route -> shrink_to_fit();

    return route;
}

bool BinaryTree::isBinarySearchTree()
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
}
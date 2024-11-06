void BinarySearchTree::addItem(int value) {
    root = _addItem(root, value);
}

BinarySearchTree::Node* BinarySearchTree::_addItem(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }
    if (value < node->key) {
        node->left = _addItem(node->left, value);
    } else if (value > node->key) {
        node->right = _addItem(node->right, value);
    }
    return node;
}

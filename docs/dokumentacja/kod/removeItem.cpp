void BinarySearchTree::removeItem(int value) {
    root = _removeItem(root, value);
}

BinarySearchTree::Node* BinarySearchTree::_removeItem(Node* node, int value) {
    if (node == nullptr) {
        return nullptr;
    }
    if (value < node->key) {
        node->left = _removeItem(node->left, value);
    } else if (value > node->key) {
        node->right = _removeItem(node->right, value);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = _findMin(node->right);
        node->key = temp->key;
        node->right = _removeItem(node->right, temp->key);
    }
    return node;
}

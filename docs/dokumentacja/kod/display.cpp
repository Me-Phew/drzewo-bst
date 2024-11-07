void BinarySearchTree::display(BinaryTreeTraversalMethod traversalMethod) {
    switch (traversalMethod) {
        case PREORDER:
            _traversePreorder(root);
            break;
        case INORDER:
            _traverseInorder(root);
            break;
        case POSTORDER:
            _traversePostorder(root);
            break;
    }
}

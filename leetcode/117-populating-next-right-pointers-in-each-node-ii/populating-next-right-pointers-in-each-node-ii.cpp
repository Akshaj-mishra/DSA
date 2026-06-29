class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        Node* curr = root;

        while (curr) {
            Node* head = nullptr; // first node of next level
            Node* prev = nullptr; // previous connected node

            while (curr) {

                if (curr->left) {
                    if (!head)
                        head = curr->left;
                    if (prev)
                        prev->next = curr->left;
                    prev = curr->left;
                }

                if (curr->right) {
                    if (!head)
                        head = curr->right;
                    if (prev)
                        prev->next = curr->right;
                    prev = curr->right;
                }

                curr = curr->next;
            }

            curr = head;
        }

        return root;
    }
};
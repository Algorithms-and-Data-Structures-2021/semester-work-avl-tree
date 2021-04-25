#pragma once

// Заголовочный файл с объявлением структуры данных

namespace itis {

    struct Node final {
        int key;
        int height; // высота
        Node *left;
        Node *right;

        Node(int k);
    };

    struct AVLTree final {
         private:
            Node *head_{nullptr};

            Node *search_(int key, Node* node);
            void clear_(Node* node);
            Node* insert_(int key, Node* node);

    public:
            ~AVLTree();

            bool is_empty ();

            int balance_factor(Node* node);
            int height(Node* node);
            void set_height(Node* node);

            void insert(int key);

            Node* rotate_left(Node* node);
            Node* rotate_right(Node* node);
            Node* balance(Node* node);

            void remove(int key);
            Node* remove_(int key, Node* node);

            Node *search(int key);

            void clear();

            Node* find_min(Node* node);

            Node* remove_min(Node* node);

    };

}  // namespace itis
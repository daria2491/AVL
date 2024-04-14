#pragma once
#include <iostream>
#include <stdexcept>
#define COUNT 20
class BTNode{
        public:
        BTNode *left, *right, *parent;
        int key, height;

        BTNode(BTNode* parent, BTNode* left, BTNode* right, int key, int height = 1): parent(parent), left(left), right(right), key(key), height(height) {}
};
class BT{
    public:
    
    BTNode *root;

    BT(){
        root = nullptr;
    }
    ~BT(){
    destroyTree(root);
    }

    void destroyTree(BTNode* node){
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
    int height(BTNode *N){  
        if (N == nullptr)  
            return 0;  
        return N->height;  
    } 
    BTNode *rotateRight(BTNode *y){  
        BTNode *x = y->left;  
        BTNode *T2 = x->right; 
        BTNode *Xparent = y->parent;

        if(T2 != nullptr){
            T2->parent = y;
        }

        y->parent = x;
        x->parent = Xparent;

        x->right = y; 
        y->left = T2;      
        y->height = std::max(height(y->left), height(y->right)) + 1;  
        x->height = std::max(height(x->left), height(x->right)) + 1;  
        return x;  
    } 
    BTNode *rotateLeft(BTNode *x){ 
        BTNode *y = x->right;  
        BTNode *T2 = y->left; 
        BTNode *Yparent = x->parent;

        if(T2 != nullptr){
            T2->parent = x;
        }
        
        x->parent = y;
        y->parent = Yparent;

        y->left = x;  
        x->right = T2;
        x->height = std::max(height(x->left), height(x->right)) + 1;  
        y->height = std::max(height(y->left), height(y->right)) + 1;  
        std::cout << y->key << std::endl;

        return y;  
        }  

    int getBalance(BTNode *N){  
        if (N == nullptr)  
            return 0;  
        return height(N->left) - height(N->right);  
    } 

    void insert(int x){
        insert(root, root, root, x);
    }

    BTNode* insert(BTNode* root1, BTNode* prev, BTNode* node, int x){  
        BTNode* old = root1; //przechowywanie starego korzenia jest potrzebne w sytuacji gdy: wykonujemy podwójną rotację na korzeniu, aby ustalić nowy korzeń po rotacji
        if(root == nullptr){
            BTNode* newNode = new BTNode(nullptr, nullptr, nullptr, x);
            root = newNode;
            return newNode; 
            
        } 
        if(node == nullptr){
            BTNode* newNode = new BTNode(prev, nullptr, nullptr, x);
            return newNode;  
        }
        if(x < node->key){ 
            node->left = insert(old, node, node->left, x); 
        } 
        else{
            node->right = insert(old, node, node->right, x); 
        } 
        node->height = 1 + std::max(height(node->left), height(node->right));  

        int balance = getBalance(node);  

        if (balance > 1 && x < node->left->key)  {
            node = rotateRight(node);  
            return node;
        } 
        if (balance < -1 && (x > node->right->key)) {
            node = rotateLeft(node);
            return node;  
        } 
        if (balance > 1 && x > node->left->key){  
            node->left = rotateLeft(node->left);  

            if(old == node || root == node){
                node = rotateRight(node);
                root = node;
                return node;
            }
            node = rotateRight(node);
            return node;  
        }  
        if (balance < -1 && (x < node->right->key)){  
            node->right = rotateRight(node->right);  
            
            if(old == node || root == node){
                node = rotateLeft(node);
                root = node;
                return node;
            }
            node = rotateLeft(node);
            return node;  
        }  

        root = node;
        return node;   
    } //wstawia element x do drzewa

    BTNode* searchRecursive(int x) {
        return searchRecursive(root, x);
    }

    BTNode* searchRecursive(BTNode *current,  int x) {
        if (current == nullptr || current->key == x) {
            return current;
        }
        if (x < current->key) {
            return searchRecursive(current->left, x);
        }
        return searchRecursive(current->right, x);
    }

    BTNode* searchParent(BTNode *child){
        return searchParent(child, root);
    }
    BTNode* searchParent(BTNode *current,  BTNode* root) {
        
        if (root->right == current || root->left == current) {
            return root;
        }
        BTNode* parent = root;
        if (current->key >= root->key) {
            return searchParent(current, root->right);
        }else{
        return searchParent(current, root->left);
        }
        return parent;
    }

    int size(){
        return size(root);
    }

    int size(BTNode* node){
        if (node == nullptr) {
            return 0;
        }
        return 1 + size(node->left) + size(node->right);
    }

    BTNode* minimumNode(BTNode* node){
        BTNode *current = node;
        while(current->left != nullptr){
            current = current->left;
        }
        return current;
    }

    int maximum(){
        BTNode *current = root;
        while(current->right != nullptr){
            current = current->right;
        }
        int x = current->key;
        return x;
    }

    int minimum(){
        BTNode *current = root;
        while(current->left != nullptr){
            current = current->left;
        }
        int x = current->key;
        return x;
    }

    int depth() {
        return depth(root);
    }

    int depth(BTNode* current){
        if (current == nullptr) {
            return 0;
        }
        int leftDepth = depth(current->left);
        int rightDepth = depth(current->right);

        return 1 + std::max(leftDepth, rightDepth);
    }// - zwraca wysokość drzewa
    
    void inorder() {
        inorder(root);
    }
    void inorder(BTNode *current){
        if(current != nullptr){
            inorder(current->left);
            std::cout << current->key << std::endl;
            inorder(current->right);
        }
    } 

    void preorder() {
        preorder(root);
    }

    void preorder(BTNode* current) {
        if (current != nullptr){
            std::cout << current->key << std::endl;
            preorder(current->left);
            preorder(current->right);
            }
    }

    void postorder() {
        postorder(root);
    }

    void postorder(BTNode* current) {
        if (current != nullptr){
            postorder(current->left);
            postorder(current->right);
            std::cout << current->key << std::endl;
            }
    }

    void print2DUtil(){
        std::cout << "tree printing: " << std::endl;
        print2DUtil(root, 0);
    }
    void print2DUtil(BTNode* root, int space){
        
    if (root == nullptr){
        return;
    }
    space += COUNT;

    print2DUtil(root->right, space);
    std::cout << std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    std::cout << root->key << std::endl;
 
    print2DUtil(root->left, space);
    }

    void erase(int x){
        erase(root, x);
    }

    BTNode *erase(BTNode *node, int x){
        if (root->key == x){
            throw std::out_of_range("no provision for root removal");
        }
        if (x < node->key){
            node->left = erase(node->left, x);
        }
        else if (x > node->key){
            node->right = erase(node->right, x);
        }
        else{
            if(node->key == x){
                if((node->left == nullptr) || (node->right == nullptr)){ 
                    BTNode *temp = node->left ? node->left : node->right; 
                    if(temp == nullptr) {
                        temp = node;
                        node = nullptr;
                    }else{
                        *node = *temp;
                    }
                    delete temp;
                }else{
                    BTNode *temp = minimumNode(node->right); 
                    node->key = temp->key;
                    node->right = erase(node->right,temp->key);
                }
            }else{
                throw std::out_of_range("brak klucza");
            }
        }
        if (node == nullptr){
            return node;
        }
        node->height = 1 + std::max(height(node->left), height(node->right));
        int balanceFactor = getBalance(node);
        if (balanceFactor > 1) {
            if (getBalance(node->left) >= 0){
                if(node == root){
                    node = rotateRight(node);
                    root = node;
                    return node;
                }
                return rotateRight(node);
            } else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
            }
        }
        if (balanceFactor < -1) {
            if (getBalance(node->right) <= 0) {
                if(node == root){
                    node = rotateLeft(node);
                    root = node;
                    return node;
                }
                node = rotateLeft(node);
                return node;
            } else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
            }
        }
        return node;
    }

    void rebalance(BTNode* oldroot, BTNode* node){ //po wykonaniu łączenia drzew
        BTNode* old = oldroot;

        if(node == nullptr){
            return;
        }

        rebalance(oldroot, node->right);
        rebalance(oldroot, node->left);
        int balanceFactor = getBalance(node);

        if (balanceFactor > 1) {
            if (getBalance(node->left) >= 0){
                if(node == root){
                    node = rotateRight(node);
                    root = node;
                    return rebalance(oldroot, node);
                }
                if(root->left == node){
                    node = rotateRight(node);
                    root->right = node;
                }else{
                    BTNode* prev = node->parent;
                    node = rotateRight(node);  
                    prev->right = node;  
                }
                return rebalance(oldroot, node);
            } else {
                node->left = rotateLeft(node->left);
                if(old == node || root == node){
                    node = rotateRight(node);
                    root = node;
                    return;
                }
                node = rotateRight(node);
            return rebalance(oldroot, node);
            }
        }
        if (balanceFactor < -1) {
            if (getBalance(node->right) <= 0) {
                if(node == root){ 
                    node = rotateLeft(node);
                    root = node;
                    return rebalance(oldroot, node);
                }
                if(root->right == node){
                    node = rotateLeft(node);
                    root->right = node;
                }else{
                    BTNode* prev = node->parent;
                    node = rotateLeft(node);  
                    prev->left = node;            
                }
                return rebalance(oldroot, node);
            } else {
                node->right = rotateRight(node->right);
                if(old == node || root == node){
                    node = rotateLeft(node);
                    root = node;
                    return rebalance(oldroot, node);
                }
            node = rotateLeft(node);
            return rebalance(oldroot, node);
            }
        }
        return;
    }

    int updateHeight(BTNode* node){ //po wykonaniu łączenia drzew należy zaktualizować wszystkie wysokości
        if(node == nullptr){
            return 0;
        }
        node->height = 1 + std::max(depth(node->left), depth(node->right));
        updateHeight(node->right);
        updateHeight(node->left);
    }
};

void join(BT &S1, BT &S2){   //zwraca S2 jako nowe drzewo
    if(S1.maximum() < S2.minimum()){ 
        int h1 = S1.height(S1.root);
        int h2 = S2.height(S2.root);
        int min = S2.minimum();
        S2.erase(min);
        //S2.print2DUtil();
        int h = S2.height(S2.root);
        BTNode* v = S1.root;
        BTNode* u = v;
        int h_ = h1;

        while (h_ > h+1){
            if( S1.getBalance(v) == -1){
                h_ -= 2;
            }else{
                h_ -= 1;
            }
            u = v;
            v = v->right;
        }
        BTNode* newRoot = new BTNode(nullptr, v, S2.root, min);

        if(S1.root->key == v->key){
            S2.root = newRoot;
        }else{
            S2.root = S1.root;
            u->right = newRoot;
            newRoot -> parent = u;
            S2.updateHeight(S2.root); //aktualizuje wysokosc wszystkich węzłów 
        }
        S2.rebalance(S2.root, S2.root);     
 
    }else{
        throw std::out_of_range("trees with the given parameters cannot be joined");
    }
    //dzieli drzewo na dwa drzewa: pierwszy złożony z elementów mniejszych bądź równych   //x i drugi złożonych z elementów większych od x
}
void split(int x, BT &S1, BT &emptyTree){

    if(S1.searchRecursive(x) == nullptr)
        throw std::out_of_range("no key");

    BTNode* object = S1.searchRecursive(x); 

    if(object->left == nullptr && object->right == nullptr){
        S1.erase(x);
        emptyTree.root = object;
        return;
    }
    if(object == S1.root){
        object->right->parent = nullptr;
        S1.root = object->right;
        object->right = nullptr;
        emptyTree.root = object;
        S1.updateHeight(S1.root);
        S1.rebalance(S1.root, S1.root); 
        emptyTree.updateHeight(emptyTree.root);
        emptyTree.rebalance(emptyTree.root, emptyTree.root);
        return;
    }
    BTNode* parent1 = object->parent;
    if(parent1 == S1.root){
        if(object <= parent1){ 
            emptyTree.root = parent1;
            S1.root = parent1->right;
            parent1->right = nullptr;
        }
        else{ //OK
            S1.root = object->right;
            object->right = nullptr;
            emptyTree.root = parent1;   
        }
        S1.updateHeight(S1.root);
        S1.rebalance(S1.root, S1.root); 
        emptyTree.updateHeight(emptyTree.root);
        emptyTree.rebalance(emptyTree.root, emptyTree.root);
        return;
    }

    if(parent1 != S1.root && object != S1.root){
      
        BTNode* parent1parent = parent1->parent;

        if(object <= parent1 && parent1 <= parent1parent){
            parent1->left = object->right;
            object->right = nullptr;
            object->parent = nullptr;  
            emptyTree.root = object;
            S1.updateHeight(S1.root);
            S1.rebalance(S1.root, S1.root); 
            emptyTree.updateHeight(emptyTree.root);
            emptyTree.rebalance(emptyTree.root, emptyTree.root);
            return;
        }
        if(object <= parent1 && parent1 > parent1parent){ //ok
            parent1parent->right = object;
            parent1->left = object->right;
            object->right = nullptr;
            S1.root = parent1parent;
            emptyTree.root = parent1;
            S1.updateHeight(S1.root);
            S1.rebalance(S1.root, S1.root); 
            emptyTree.updateHeight(emptyTree.root);
            emptyTree.rebalance(emptyTree.root, emptyTree.root);
            return;
        }
        if(object > parent1 && parent1 > parent1parent){ //OK
            emptyTree.root = object->right;
            object->right->parent = nullptr;
            object->right = nullptr;
            S1.updateHeight(S1.root);
            S1.rebalance(S1.root, S1.root); 
            emptyTree.updateHeight(emptyTree.root);
            emptyTree.rebalance(emptyTree.root, emptyTree.root);
            return;
        }
        if(object > parent1 && parent1 <= parent1parent){
            parent1parent->left = object->right;
            object->right->parent = parent1parent;
            object->right = nullptr;
            S1.root = parent1parent;
            emptyTree.root = parent1;
            S1.updateHeight(S1.root);
            S1.rebalance(S1.root, S1.root); 
            emptyTree.updateHeight(emptyTree.root);
            emptyTree.rebalance(emptyTree.root, emptyTree.root);
            return;   
            }
    }
} 
    
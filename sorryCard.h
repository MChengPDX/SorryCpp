/*
 * Michael Cheng
 * CS 202 Program 3
 * Winter 2016
 *
 * node.h
 *
 */



class Bnode
{
    private:
        int height, data;
        Bnode * left;
        Bnode * right;
        Bnode * prev;
        
    public:
        Bnode(int n);
        ~Bnode();
        int get_data();
        int get_height();
        
        int display_data();

        int set_data(int value);
        int set_height(int value);

        Bnode *& get_left();
        Bnode *& get_right();
        Bnode *& get_prev();

};


class Maze
{
    private:
        Bnode * root;
    public:
        Maze();
        ~Maze();
        void remove_all();
        void remove_all(Bnode * root);
        void display_all();
        void display_all(Bnode * root);
        void insert(int data);
        int height(Bnode * root);
        int max (int a, int b);
        Bnode * insert(int data, Bnode * root);
        // Rotate tree node with left child 
        Bnode * RLC(Bnode * root);
        // Rotate with right child
        Bnode * RRC(Bnode * root);
        // Double rotate the binary tree node
        // first left child with its right child
        // then the node to rotate with  the new left child
        Bnode * DWLC(Bnode * root);
        //Doing the opposite of DWLC
        Bnode * DWRC(Bnode * root);
        int countBnodes();
        int countBnodes(Bnode * root);

        void test();
        void display_left(Bnode * root);
        void display_right(Bnode * root);


        void checkOrders();
        void inorder(Bnode * root);
        void preorder(Bnode * root);
        void postorder(Bnode * root);
      
        Bnode * go_back(Bnode * root);
        Bnode * advance_l(Bnode * root);
        Bnode * advance_r(Bnode * root);
        void move();
        Bnode * advance(int value, Bnode * current);

        //operator overloading to move
        //Bnode & Maze operator >> (Bnode & to_move); //moving right
        //Bnode & Maze operator << (Bnode & to_move); //move left


        //setting previous pointers
        void set_previous(Bnode * ptr, Bnode * ptr2);
        void set_previous();

};

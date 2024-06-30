#include <QApplication>
#include "TreeViewWidget.hpp"
#include <iostream>
#include "Tree.hpp"
#include "Node.hpp"
#include "Complex.hpp"

using namespace std;


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Complex c(1,6);
    Complex c1(1,5);
    Complex c2(1,4);
    Complex c3(1,3);
    Complex c4(1,2);
    Complex c5(1,1);
    Complex c6(0,1);


    Node<Complex> root_node = Node<Complex>(c);
    Tree<Complex> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<Complex> n1 = Node<Complex>(c1);
    Node<Complex> n2 = Node<Complex>(c2);
    Node<Complex> n3 = Node<Complex>(c3);
    Node<Complex> n4 = Node<Complex>(c4);
    Node<Complex> n5 = Node<Complex>(c5);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    cout << root_node.getKey() << endl;
    cout << root_node.getChildren()[0]->getKey() << "     " << root_node.getChildren()[1]->getKey() << endl;
    cout << n1.getChildren()[0]->getKey() << "     " << n1.getChildren()[1]->getKey()  << "     " << n2.getChildren()[0]->getKey()<< endl;


    cout << "in order: ";
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << *node << ", ";

    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << endl;
    cout << "pre order: ";
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << *node << ", ";

    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;
    cout << "post order: ";
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << *node << ", ";
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << endl;

    cout << "BFS: ";
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << (*node)->getKey() << ", ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    cout << "DFS: ";
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        cout << *node << ", ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;

    // Create the TreeViewWidget and display the int tree
    TreeViewWidget complexViewWidget;
    complexViewWidget.displayTree(tree);
    complexViewWidget.show();



    tree.myHeap();

    cout << tree.getRoot()->getKey() << endl;
    cout << tree.getRoot()->getChildren()[0]->getKey() << "     " << tree.getRoot()->getChildren()[1]->getKey() << endl;
    cout << tree.getRoot()->getChildren()[0]->getChildren()[0]->getKey() << "     " << tree.getRoot()->getChildren()[0]->getChildren()[1]->getKey()  << "     " << tree.getRoot()->getChildren()[1]->getChildren()[0]->getKey()<< endl;

    TreeViewWidget complexViewWidget2;
    complexViewWidget2.displayTree(tree);
    complexViewWidget2.show();



    Node<double> root_node1 = Node<double>(1.1);
    Node<double> n11 = Node<double>(1.2);
    Node<double> n21 = Node<double>(1.3);
    Node<double> n31 = Node<double>(1.4);
    Node<double> n41 = Node<double>(1.5);
    Node<double> n51 = Node<double>(1.6);


    Tree<double,3> three_ary_tree; // 3-ary tree.
    three_ary_tree.add_root(root_node1);
    three_ary_tree.add_sub_node(root_node1, n11);
    three_ary_tree.add_sub_node(root_node1, n21);
    three_ary_tree.add_sub_node(root_node1, n31);
    three_ary_tree.add_sub_node(n11, n41);
    three_ary_tree.add_sub_node(n21, n51);

    // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */

    TreeViewWidget doubleViewWidget;
    doubleViewWidget.displayTree(three_ary_tree);
    doubleViewWidget.show();


    //string

    Node<string> root_node12 = Node<string>("hello");
    Node<string> n12 = Node<string>("my");
    Node<string> n22 = Node<string>("name");
    Node<string> n32 = Node<string>("is");
    Node<string> n42 = Node<string>("Tzvi");
    Node<string> n52 = Node<string>("Rechel");


    Tree<string,3> string_tree; // 3-ary tree.
    string_tree.add_root(root_node12);
    string_tree.add_sub_node(root_node12, n12);
    string_tree.add_sub_node(root_node12, n22);
    string_tree.add_sub_node(root_node12, n32);
    string_tree.add_sub_node(n12, n42);
    string_tree.add_sub_node(n22, n52);


    TreeViewWidget stringViewWidget;
    stringViewWidget.displayTree(string_tree);
    stringViewWidget.show();


    Node<int> root_node111(1);
    Node<int> n111(2);
    Node<int> n222(3);
    Node<int> n333(4);
    Node<int> n444(5);
    Node<int> n555(6);

    Tree<int, 3> unbalanced_tree;
    unbalanced_tree.add_root(root_node111);
    unbalanced_tree.add_sub_node(root_node111, n111);
    unbalanced_tree.add_sub_node(n111, n222);
    unbalanced_tree.add_sub_node(n222, n333);
    unbalanced_tree.add_sub_node(n333, n444);
    unbalanced_tree.add_sub_node(n444, n555);

    TreeViewWidget intViewWidget;
    intViewWidget.displayTree(unbalanced_tree);
    intViewWidget.show();

    return app.exec();
}

// tzvirechel@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Node.hpp"
#include "../Tree.hpp"
#include "../Complex.hpp"
#include <string>

// Test cases for int
TEST_CASE("Tree of int") {
    Tree<int> intTree;
    Node<int> intRoot(10);
    Node<int> intChild1(20);
    Node<int> intChild2(30);
    Node<int> intChild3(40);
    Node<int> intChild4(50);

    intTree.add_root(intRoot);
    intTree.add_sub_node(intRoot, intChild1);
    intTree.add_sub_node(intRoot, intChild2);
    intTree.add_sub_node(intChild1, intChild3);
    intTree.add_sub_node(intChild1, intChild4);

    CHECK(intRoot.getKey() == 10);
    CHECK(intRoot.getChildren().size() == 2);
    CHECK(intRoot.getChildren()[0]->getKey() == 20);
    CHECK(intRoot.getChildren()[1]->getKey() == 30);
    CHECK(intChild1.getChildren()[0]->getKey() == 40);
    CHECK(intChild1.getChildren()[1]->getKey() == 50);

    // In-order traversal
    auto it = intTree.begin_in_order();
    CHECK(*it == 40);
    ++it;
    CHECK(*it == 20);
    ++it;
    CHECK(*it == 50);
    ++it;
    CHECK(*it == 10);
    ++it;
    CHECK(*it == 30);

    // Pre-order traversal
    auto it1 = intTree.begin_pre_order();
    CHECK(*it1 == 10);
    ++it1;
    CHECK(*it1 == 20);
    ++it1;
    CHECK(*it1 == 40);
    ++it1;
    CHECK(*it1 == 50);
    ++it1;
    CHECK(*it1 == 30);

    // Post-order traversal
    auto it2 = intTree.begin_post_order();
    CHECK(*it2 == 40);
    ++it2;
    CHECK(*it2 == 50);
    ++it2;
    CHECK(*it2 == 20);
    ++it2;
    CHECK(*it2 == 30);
    ++it2;
    CHECK(*it2 == 10);

    // BFS traversal
    auto it3 = intTree.begin_bfs_scan();
    CHECK((*it3)->getKey() == 10);
    ++it3;
    CHECK((*it3)->getKey() == 20);
    ++it3;
    CHECK((*it3)->getKey() == 30);
    ++it3;
    CHECK((*it3)->getKey() == 40);
    ++it3;
    CHECK((*it3)->getKey() == 50);

    // DFS traversal
    auto it4 = intTree.begin_dfs_scan();
    CHECK(*it4 == 10);
    ++it4;
    CHECK(*it4 == 20);
    ++it4;
    CHECK(*it4 == 40);
    ++it4;
    CHECK(*it4 == 50);
    ++it4;
    CHECK(*it4 == 30);
}

// Test cases for std::string
TEST_CASE("Tree of std::string") {
    Tree<std::string> stringTree;
    Node<std::string> stringRoot("root");
    Node<std::string> stringChild1("child1");
    Node<std::string> stringChild2("child2");
    Node<std::string> stringChild3("child3");
    Node<std::string> stringChild4("child4");

    stringTree.add_root(stringRoot);
    stringTree.add_sub_node(stringRoot, stringChild1);
    stringTree.add_sub_node(stringRoot, stringChild2);
    stringTree.add_sub_node(stringChild1, stringChild3);
    stringTree.add_sub_node(stringChild1, stringChild4);

    CHECK(stringRoot.getKey() == "root");
    CHECK(stringRoot.getChildren().size() == 2);
    CHECK(stringRoot.getChildren()[0]->getKey() == "child1");
    CHECK(stringRoot.getChildren()[1]->getKey() == "child2");
    CHECK(stringChild1.getChildren()[0]->getKey() == "child3");
    CHECK(stringChild1.getChildren()[1]->getKey() == "child4");

    // In-order traversal
    auto it = stringTree.begin_in_order();
    CHECK(*it == "child3");
    ++it;
    CHECK(*it == "child1");
    ++it;
    CHECK(*it == "child4");
    ++it;
    CHECK(*it == "root");
    ++it;
    CHECK(*it == "child2");

    // Pre-order traversal
   auto it1 = stringTree.begin_pre_order();
    CHECK(*it1 == "root");
    ++it1;
    CHECK(*it1 == "child1");
    ++it1;
    CHECK(*it1 == "child3");
    ++it1;
    CHECK(*it1 == "child4");
    ++it1;
    CHECK(*it1 == "child2");

    // Post-order traversal
   auto it2 = stringTree.begin_post_order();
    CHECK(*it2 == "child3");
    ++it2;
    CHECK(*it2 == "child4");
    ++it2;
    CHECK(*it2 == "child1");
    ++it2;
    CHECK(*it2 == "child2");
    ++it2;
    CHECK(*it2 == "root");

    // BFS traversal
    auto it3 = stringTree.begin_bfs_scan();
    CHECK((*it3)->getKey() == "root");
    ++it3;
    CHECK((*it3)->getKey() == "child1");
    ++it3;
    CHECK((*it3)->getKey() == "child2");
    ++it3;
    CHECK((*it3)->getKey() == "child3");
    ++it3;
    CHECK((*it3)->getKey() == "child4");

    // DFS traversal
    auto it4 = stringTree.begin_dfs_scan();
    CHECK(*it4 == "root");
    ++it4;
    CHECK(*it4 == "child1");
    ++it4;
    CHECK(*it4 == "child3");
    ++it4;
    CHECK(*it4 == "child4");
    ++it4;
    CHECK(*it4 == "child2");
}

// Test cases for Complex
TEST_CASE("Tree of Complex") {
    Complex c(1, 6);
    Complex c1(1, 5);
    Complex c2(1, 4);
    Complex c3(1, 3);
    Complex c4(1, 2);
    Complex c5(1, 1);

    Node<Complex> root_node(c);
    Tree<Complex> complexTree;
    complexTree.add_root(root_node);
    Node<Complex> n1(c1);
    Node<Complex> n2(c2);
    Node<Complex> n3(c3);
    Node<Complex> n4(c4);
    Node<Complex> n5(c5);

    complexTree.add_sub_node(root_node, n1);
    complexTree.add_sub_node(root_node, n2);
    complexTree.add_sub_node(n1, n3);
    complexTree.add_sub_node(n1, n4);
    complexTree.add_sub_node(n2, n5);

    CHECK(root_node.getKey() == c);
    CHECK(root_node.getChildren()[0]->getKey() == c1);
    CHECK(root_node.getChildren()[1]->getKey() == c2);
    CHECK(n1.getChildren()[0]->getKey() == c3);
    CHECK(n1.getChildren()[1]->getKey() == c4);
    CHECK(n2.getChildren()[0]->getKey() == c5);

    // In-order traversal
    auto it = complexTree.begin_in_order();
    CHECK(*it == c3);
    ++it;
    CHECK(*it == c1);
    ++it;
    CHECK(*it == c4);
    ++it;
    CHECK(*it == c);
    ++it;
    CHECK(*it == c5);
    ++it;
    CHECK(*it == c2);

    // Pre-order traversal
    auto it1 = complexTree.begin_pre_order();
    CHECK(*it1 == c);
    ++it1;
    CHECK(*it1 == c1);
    ++it1;
    CHECK(*it1 == c3);
    ++it1;
    CHECK(*it1 == c4);
    ++it1;
    CHECK(*it1 == c2);
    ++it1;
    CHECK(*it1 == c5);

    // Post-order traversal
    auto it2 = complexTree.begin_post_order();
    CHECK(*it2 == c3);
    ++it2;
    CHECK(*it2 == c4);
    ++it2;
    CHECK(*it2 == c1);
    ++it2;
    CHECK(*it2 == c5);
    ++it2;
    CHECK(*it2 == c2);
    ++it2;
    CHECK(*it2 == c);

    // BFS traversal
    auto it3 = complexTree.begin_bfs_scan();
    CHECK((*it3)->getKey() == c);
    ++it3;
    CHECK((*it3)->getKey() == c1);
    ++it3;
    CHECK((*it3)->getKey() == c2);
    ++it3;
    CHECK((*it3)->getKey() == c3);
    ++it3;
    CHECK((*it3)->getKey() == c4);
    ++it3;
    CHECK((*it3)->getKey() == c5);

    // DFS traversal
    auto it4 = complexTree.begin_dfs_scan();
    CHECK(*it4 == c);
    ++it4;
    CHECK(*it4 == c1);
    ++it4;
    CHECK(*it4 == c3);
    ++it4;
    CHECK(*it4 == c4);
    ++it4;
    CHECK(*it4 == c2);
    ++it4;
    CHECK(*it4 == c5);
}

// Test cases for k-ary tree with k > 2 (continued)
TEST_CASE("3-ary Tree of double") {
    Node<double> root_node(1.1);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    Tree<double, 3> three_ary_tree;
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);

    // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */

    CHECK(root_node.getKey() == 1.1);
    CHECK(root_node.getChildren()[0]->getKey() == 1.2);
    CHECK(root_node.getChildren()[1]->getKey() == 1.3);
    CHECK(root_node.getChildren()[2]->getKey() == 1.4);
    CHECK(n1.getChildren()[0]->getKey() == 1.5);
    CHECK(n2.getChildren()[0]->getKey() == 1.6);

    // BFS traversal
    auto it = three_ary_tree.begin_bfs_scan();
    CHECK((*it)->getKey() == 1.1);
    ++it;
    CHECK((*it)->getKey() == 1.2);
    ++it;
    CHECK((*it)->getKey() == 1.3);
    ++it;
    CHECK((*it)->getKey() == 1.4);
    ++it;
    CHECK((*it)->getKey() == 1.5);
    ++it;
    CHECK((*it)->getKey() == 1.6);

    // DFS traversal
    auto it1 = three_ary_tree.begin_dfs_scan();
    CHECK(*it1 == 1.1);
    ++it1;
    CHECK(*it1 == 1.2);
    ++it1;
    CHECK(*it1 == 1.5);
    ++it1;
    CHECK(*it1 == 1.3);
    ++it1;
    CHECK(*it1 == 1.6);
    ++it1;
    CHECK(*it1 == 1.4);
}


// Test cases for 4-ary tree of double
TEST_CASE("4-ary Tree of double") {
    Node<double> root_node(1.1);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);
    Node<double> n6(1.7);
    Node<double> n7(1.8);
    Node<double> n8(1.9);
    Node<double> n9(2.0);
    Node<double> n10(2.1);

    Tree<double, 4> four_ary_tree;
    four_ary_tree.add_root(root_node);
    four_ary_tree.add_sub_node(root_node, n1);
    four_ary_tree.add_sub_node(root_node, n2);
    four_ary_tree.add_sub_node(root_node, n3);
    four_ary_tree.add_sub_node(root_node, n4);
    four_ary_tree.add_sub_node(n1, n5);
    four_ary_tree.add_sub_node(n1, n6);
    four_ary_tree.add_sub_node(n2, n7);
    four_ary_tree.add_sub_node(n3, n8);
    four_ary_tree.add_sub_node(n4, n9);
    four_ary_tree.add_sub_node(n4, n10);

    // The tree should look like:
    /**
     *       root = 1.1
     *   /    |    |    \
     *  1.2  1.3  1.4  1.5
     *  / \   |    |   / \
     * 1.6 1.7 1.8 1.9 2.0 2.1
     */

    CHECK(root_node.getKey() == 1.1);
    CHECK(root_node.getChildren()[0]->getKey() == 1.2);
    CHECK(root_node.getChildren()[1]->getKey() == 1.3);
    CHECK(root_node.getChildren()[2]->getKey() == 1.4);
    CHECK(root_node.getChildren()[3]->getKey() == 1.5);
    CHECK(n1.getChildren()[0]->getKey() == 1.6);
    CHECK(n1.getChildren()[1]->getKey() == 1.7);
    CHECK(n2.getChildren()[0]->getKey() == 1.8);
    CHECK(n3.getChildren()[0]->getKey() == 1.9);
    CHECK(n4.getChildren()[0]->getKey() == 2.0);
    CHECK(n4.getChildren()[1]->getKey() == 2.1);

    // BFS traversal
    auto it = four_ary_tree.begin_bfs_scan();
    CHECK((*it)->getKey() == 1.1);
    ++it;
    CHECK((*it)->getKey() == 1.2);
    ++it;
    CHECK((*it)->getKey() == 1.3);
    ++it;
    CHECK((*it)->getKey() == 1.4);
    ++it;
    CHECK((*it)->getKey() == 1.5);
    ++it;
    CHECK((*it)->getKey() == 1.6);
    ++it;
    CHECK((*it)->getKey() == 1.7);
    ++it;
    CHECK((*it)->getKey() == 1.8);
    ++it;
    CHECK((*it)->getKey() == 1.9);
    ++it;
    CHECK((*it)->getKey() == 2.0);
    ++it;
    CHECK((*it)->getKey() == 2.1);

    // DFS traversal
    auto it1 = four_ary_tree.begin_dfs_scan();
    CHECK(*it1 == 1.1);
    ++it1;
    CHECK(*it1 == 1.2);
    ++it1;
    CHECK(*it1 == 1.6);
    ++it1;
    CHECK(*it1 == 1.7);
    ++it1;
    CHECK(*it1 == 1.3);
    ++it1;
    CHECK(*it1 == 1.8);
    ++it1;
    CHECK(*it1 == 1.4);
    ++it1;
    CHECK(*it1 == 1.9);
    ++it1;
    CHECK(*it1 == 1.5);
    ++it1;
    CHECK(*it1 == 2.0);
    ++it1;
    CHECK(*it1 == 2.1);
}

// Edge cases

TEST_CASE("Empty Tree") {
    Tree<int> empty_tree;
    CHECK(empty_tree.begin_in_order() == empty_tree.end_in_order());
    CHECK(empty_tree.begin_pre_order() == empty_tree.end_pre_order());
    CHECK(empty_tree.begin_post_order() == empty_tree.end_post_order());
    CHECK(empty_tree.begin_bfs_scan() == empty_tree.end_bfs_scan());
    CHECK(empty_tree.begin_dfs_scan() == empty_tree.end_dfs_scan());
}

TEST_CASE("Tree with Only Root Node") {
    Node<int> root_node(1);
    Tree<int> single_node_tree;
    single_node_tree.add_root(root_node);

    auto it = single_node_tree.begin_in_order();
    CHECK(*it == 1);
    ++it;
    CHECK(it == single_node_tree.end_in_order());

    auto it1 = single_node_tree.begin_pre_order();
    CHECK(*it1 == 1);
    ++it1;
    CHECK(it1 == single_node_tree.end_pre_order());

    auto it2 = single_node_tree.begin_post_order();
    CHECK(*it2 == 1);
    ++it2;
    CHECK(it2 == single_node_tree.end_post_order());

    auto it_bfs = single_node_tree.begin_bfs_scan();
    CHECK((*it_bfs)->getKey() == 1);
    ++it_bfs;
    CHECK(it_bfs == single_node_tree.end_bfs_scan());

    auto it_dfs = single_node_tree.begin_dfs_scan();
    CHECK(*it_dfs == 1);
    ++it_dfs;
    CHECK(it_dfs == single_node_tree.end_dfs_scan());
}

TEST_CASE("Tree with One Level of Children") {
    Node<int> root_node(1);
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);

    Tree<int, 4> one_level_tree;
    one_level_tree.add_root(root_node);
    one_level_tree.add_sub_node(root_node, n1);
    one_level_tree.add_sub_node(root_node, n2);
    one_level_tree.add_sub_node(root_node, n3);
    one_level_tree.add_sub_node(root_node, n4);

    // BFS traversal
    auto it = one_level_tree.begin_bfs_scan();
    CHECK((*it)->getKey() == 1);
    ++it;
    CHECK((*it)->getKey() == 2);
    ++it;
    CHECK((*it)->getKey() == 3);
    ++it;
    CHECK((*it)->getKey() == 4);
    ++it;
    CHECK((*it)->getKey() == 5);

    // DFS traversal
    auto it1 = one_level_tree.begin_dfs_scan();
    CHECK(*it1 == 1);
    ++it1;
    CHECK(*it1 == 2);
    ++it1;
    CHECK(*it1 == 3);
    ++it1;
    CHECK(*it1 == 4);
    ++it1;
    CHECK(*it1 == 5);
}

TEST_CASE("Unbalanced Tree") {
    Node<int> root_node(1);
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);

    Tree<int, 3> unbalanced_tree;
    unbalanced_tree.add_root(root_node);
    unbalanced_tree.add_sub_node(root_node, n1);
    unbalanced_tree.add_sub_node(n1, n2);
    unbalanced_tree.add_sub_node(n2, n3);
    unbalanced_tree.add_sub_node(n3, n4);
    unbalanced_tree.add_sub_node(n4, n5);

    // BFS traversal
    auto it = unbalanced_tree.begin_bfs_scan();
    CHECK((*it)->getKey() == 1);
    ++it;
    CHECK((*it)->getKey() == 2);
    ++it;
    CHECK((*it)->getKey() == 3);
    ++it;
    CHECK((*it)->getKey() == 4);
    ++it;
    CHECK((*it)->getKey() == 5);
    ++it;
    CHECK((*it)->getKey() == 6);

    // DFS traversal
    auto it1 = unbalanced_tree.begin_dfs_scan();
    CHECK(*it1 == 1);
    ++it1;
    CHECK(*it1 == 2);
    ++it1;
    CHECK(*it1 == 3);
    ++it1;
    CHECK(*it1 == 4);
    ++it1;
    CHECK(*it1 == 5);
    ++it1;
    CHECK(*it1 == 6);
}
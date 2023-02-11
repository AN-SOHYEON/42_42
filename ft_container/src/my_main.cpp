
#include <iostream>
#include <map>

#include "../includes/Node.hpp"
#include "../includes/avlTree.hpp"
#include "../includes/bidirectional_iterator.hpp"
#include "../includes/map.hpp"
#include "../includes/utility.hpp"
#include "../includes/vector.hpp"

// ft::Node<int> make_node(int v)
// {
// 	ft::Node<int> n;

// 	n.content = v;
// 	n.left = NULL;
// 	n.right = NULL;
// 	n.parent = NULL;

// 	return n;
// }

// ft::Node<int> make_node(int v, ft::Node<int> *left, ft::Node<int> *right)
// {
// 	ft::Node<int> n;

// 	n.content = v;
// 	n.left = left;
// 	n.right = right;
// 	n.parent = NULL;
// 	left->parent = &n;
// 	right->parent = &n;

// 	return n;
// }


int main() {
    // ft::vector<int> v;

    std::cout << "============= tree test ================\n";
    // ft::avlTree<int, int, std::less<ft::pair<int, int>>, std::allocator<ft::pair<int, int>>> avl(
    //     ft::make_pair(0, 1), std::less<ft::pair<int, int>>, std::allocator<ft::pair<int, int>>);
    // avl.insertNode(ft::make_pair(0, 1));
    // // avl.disPlayInorder();
    // avl.insertNode(2);
    // // avl.disPlayInorder();
    // avl.insertNode(3);
    // avl.disPlayInorder();
    // std::cout << "========= display debug=========\n";
    // avl.disPlayInorder_for_debug();
    // // avl.findTree(3);
    // // avl.findTree(5);
    // std::cout << "\n---delete node test---\n";
    // // avl.deleteNode(4);
    // // avl.deleteNode(2);
    // // std::cout << "fuck\n";
    // avl.deleteNode(1);
    // // avl.deleteNode(3);

    // std::cout << "\n---delete node test---\n";
    // avl.disPlayInorder();

    // // 	std::cout << "============= tree test ================\n";
    // // 	ft::avlTree<int, int, std::less<int>, std::allocator<int> > avl2;
    // // 	avl2.insertNode(1);
    // // 	avl2.insertNode(2);
    // // 	avl2.insertNode(3);
    // // 	avl2.insertNode(4);
    // // 	avl2.insertNode(5);
    // // 	avl2.insertNode(6);
    // // 	avl2.insertNode(7);
    // // 	avl2.insertNode(8);
    // // 	avl2.insertNode(9);
    // // 	avl2.insertNode(10);
    // // 	avl2.insertNode(11);
    // // 	avl2.insertNode(12);
    // // 	avl2.disPlayInorder();
    // // 	std::cout << "begin_node : " << avl2.begin_node()->content << "\n";
    // // 	std::cout << "  end_node : " << avl2.end_node()->content << "\n";

    // // 	// ft::bidirectional_iterator<int> iter();

    // // 	// while (1)
    // // 	// {
    // // 	// }

    // // 	std::cout << "============= tree test && iterator ================\n";
    // // 	ft::Node<int> node1 = make_node(1);
    // // 	ft::Node<int> node3 = make_node(3);
    // // 	ft::Node<int> node2 = make_node(2, &node1, &node3);

    // // 	ft::Node<int> node5 = make_node(5);
    // // 	ft::Node<int> node7 = make_node(7);
    // // 	ft::Node<int> node6 = make_node(6, &node5, &node7);

    // // 	ft::Node<int> node4 = make_node(4, &node2, &node6);

    // // 	ft::Node<int> node9 = make_node(9);
    // // 	ft::Node<int> node11 = make_node(11);
    // // 	ft::Node<int> node10 = make_node(10, &node9, &node11);

    // // 	ft::Node<int> node8 = make_node(8, &node4, &node10);

    // // 	std::cout << *(ft::bidirectional_iterator<int>(&node3)) << "\n";
    // // 	std::cout << *(--(ft::bidirectional_iterator<int>(&node2))) << "\n";
    // // 	std::cout << *(--(ft::bidirectional_iterator<int>(&node3))) << "\n";
    // // 	std::cout << *(--(ft::bidirectional_iterator<int>(&node4))) << "\n";
    // // 	std::cout << *(--(ft::bidirectional_iterator<int>(&node5))) << "\n";
    // // 	std::cout << *(--(ft::bidirectional_iterator<int>(&node6))) << "\n";
    // // 	std::cout << *(--(ft::bidirectional_iterator<int>(&node7))) << "\n";
    // // 	std::cout << *(--(ft::bidirectional_iterator<int>(&node8))) << "\n";
    // // 	std::cout << *(--(ft::bidirectional_iterator<int>(&node9))) << "\n";
    // // 	std::cout << *(--(ft::bidirectional_iterator<int>(&node10))) << "\n";
    // // 	try
    // // 	{
    // // 		std::cout << *(--(ft::bidirectional_iterator<int>(&node11))) << "\n";
    // // 	}
    // // 	catch (const std::exception &e)
    // // 	{
    // // 		std::cerr << e.what() << '\n';
    // // 	}

    // // 	try
    // // 	{
    // // 	}
    // // 	catch (const std::exception &e)
    // // 	{
    // // 		std::cerr << e.what() << '\n';
    // // 	}

    // ft::map<int, int> m;

    // ft::pair<int, int> p;
    // p = ft::make_pair(1, 2);
    // std::cout << "make pair : " << p.first << " " << p.second << "\n";

    // m.insert(p);

    // std::map<int, int> m;

    // std::cout << "m.begin() : " << m.begin()->first << m.begin()->second << "\n";
    // std::cout << "m.end() : " << m.end()->first << m.end()->second << "\n";

    // std::cout << "----------my map-------\n";
    // ft::map<int, int> mym;
    // std::cout << "mym.begin() : " << mym.begin()->first << " " << mym.begin()->second << "\n";
    // std::cout << "mym.end() : " << mym.end()->first << " " << mym.end()->second << "\n";






}
#include <iostream>
#include <map>
#include "bst.h"
#include "avlbst.h"

using namespace std;


int main(int argc, char *argv[])
{
    // Binary Search Tree tests
    // BinarySearchTree<char,int> bst;
    // bt.insert(std::make_pair('e',2));
		// bt.remove('e');
    // bt.insert(std::make_pair('c',1));
	// 	 	bst.insert(std::make_pair(3, 1.0));
	// bst.insert(std::make_pair(2, 1.0));
	// bst.insert(std::make_pair(1, 1.0));
	// bst.remove(3);
	// bst.insert(std::make_pair(2, 1.0));
	// bst.insert(std::make_pair(1, 1.0));
	// bst.insert(std::make_pair(3, 1.0));
	// bst.print();
	// bst.remove(2);
	// bst.print();
	// bst.insert(std::make_pair(2, 1.0));
	// bst.insert(std::make_pair(5, 1.0));
	// bst.insert(std::make_pair(3, 1.0));
	// bst.insert(std::make_pair(6, 1.0));
	// bst.print();
// AVLTree<std::string, std::string> testTree;

// 	testTree.insert(std::make_pair("Hello World", "!!!"));


	// bst.remove(5);
	// bst.print();

    // bt.insert(std::make_pair('b',2));
		// 	bt.insert(std::make_pair('a',3));
		// 	    bt.insert(std::make_pair('e',4));
		// 						bt.insert(std::make_pair('d',5));
		// 									    bt.insert(std::make_pair('f',6));




    // bt.print();
		
		// cout << "is bala?" << bt.isBalanced() <<endl;


		// bt.remove('e');
		//     bt.print();
		// cout << "is bala?" << bt.isBalanced() <<endl;

    
    // cout << "Binary Search Tree contents:" << endl;
    // for(BinarySearchTree<char,int>::iterator it = bt.begin(); it != bt.end(); ++it) {
    //     cout << it->first << " " << it->second << endl;
    // }
    // if(bt.find('b') != bt.end()) {
    //     cout << "Found b" << endl;
    // }
    // else {
    //     cout << "Did not find b" << endl;
    // }
    // cout << "Erasing b" << endl;
    // bt.remove('b');

		// 	bt.print();
		// 	cout << "before clear" << endl;

		// 	bt.clear();

		// 				bt.print();




    //AVL Tree Tests
    // AVLTree<char,int> at;
    // at.insert(std::make_pair('a',1));
    // at.insert(std::make_pair('b',2));
    // at.print();

   

			// AVLTree<uint16_t, uint16_t> testTree;

	// testTree.insert(std::make_pair(0, 9));
	// testTree.insert(std::make_pair(2, 8));
	// testTree.insert(std::make_pair(1, 159));

	// AVLTree<int, double> bst;
	// bst.insert(std::make_pair(2, 1.0));
	// bst.insert(std::make_pair(3, 1.0));
	// bst.insert(std::make_pair(1, 1.0));
	// bst.insert(std::make_pair(4, 1.0));
	// 	bst.print();

	// bst.remove(1);
	// bst.print();




		AVLTree<int, std::string> b, c, d;
	std::pair<int, std::string> item5(5, "five");
	std::pair<int, std::string> item3(3, "three");
	std::pair<int, std::string> item7(7, "seven");
	std::pair<int, std::string> item4(4, "four");
	std::pair<int, std::string> item6(6, "six");
	std::pair<int, std::string> item9(9, "nine");
	std::pair<int, std::string> item10(10, "ten");
	std::pair<int, std::string> item2(2, "two");
	std::pair<int, std::string> item8(8, "eight");
	std::pair<int, std::string> item13(13, "thirteen");
	std::pair<int, std::string> item11(11, "eleven");
	std::pair<int, std::string> item12(12, "twelve");
	std::pair<int, std::string> item15(15, "fifteen");
	std::pair<int, std::string> item14(14, "fourteen");
	std::pair<int, std::string> item16(16, "sixteen");
	std::pair<int, std::string> item17(17, "seventeen");


	// b.insert(item5);
	// b.print();

	// b.remove(7);
	// 	b.print();


	// b.remove(5);
	// 	b.print();


	// b.insert(item5);
	// b.insert(item3);
	// 	b.print();


	// b.remove(5);
	// 	b.print();


	// b.remove(3);
	// 	b.print();



	// b.insert(item5);
	// b.insert(item3);
	// b.insert(item7);
	// 	b.print();


	// b.remove(5);
	// 	b.print();


	// b.remove(7);
	// 	b.print();


	// b.remove(3);
	// 	b.print();


	// b.insert(item5);
	// b.insert(item3);
	// b.insert(item7);
	// b.insert(item4);
	// 	b.print();


	// b.remove(5);
	// 	b.print();


	// b.clear();
	// 	b.print();


	// b.insert(item5);
	// b.insert(item3);
	// b.insert(item7);
	// b.insert(item4);
	// b.insert(item6);
	// 	b.print();


	// b.remove(6);
	// b.print();

	// b.remove(4);
	// b.print();

	// b.clear();
	// b.print();

	// b.insert(item5);
	// b.insert(item3);
	// b.insert(item7);
	// b.insert(item4);
	// b.insert(item6);
	// b.insert(item9);
	// b.print();

	// b.remove(5);
	// b.print();

	// b.remove(7);
	// b.print();

	// b.remove(6);
	// b.print();

	// b.clear();
	// b.print();

	b.insert(item5);
	b.insert(item3);
	b.insert(item7);
	b.insert(item4);
	b.insert(item6);
	b.insert(item9);
	b.insert(item10);
		b.print();


	b.remove(5);
	b.print();


	// b.remove(9);
	// b.print();

	// b.remove(3);

	// b.remove(7);
	// b.print();

	// b.remove(4);
	// b.print();

	// b.remove(10);
	// b.print();

	// b.remove(10);
	// b.print();

	// b.remove(6);
	// b.print();

	// b.insert(item5);
	// b.insert(item3);
	// b.insert(item7);
	// b.insert(item4);
	// b.insert(item6);
	// b.insert(item9);
	// b.insert(item10);
	// b.insert(item2);
	// b.insert(item8);
	// b.print();


	// b.insert(item13);

	// b.print();

	// b.insert(item12);
	// b.print();


	// b.insert(item11);
	// b.print();


	// b.remove(13);
	// b.print();


	// b.remove(12);
	// b.print();


	// b.remove(10);
	// b.remove(13);
	// b.remove(7);
	// b.remove(8);
	// b.remove(7);
	// b.print();



	// d.insert(item10);
	// d.insert(item3);
	// d.insert(item2);
	// d.insert(item15);
	// d.insert(item12);
	// d.insert(item11);
	// d.insert(item14);
	// d.insert(item13);
	// d.insert(item16);
	// d.insert(item17);
	// d.print();



	// d.remove(15);
	// d.print();



	// d.remove(10);
	// d.print();


	// c.insert(item5);
	// c.insert(item3);
	// c.insert(item7);
	// c.insert(item4);
	// c.insert(item6);
	// c.insert(item9);
	// c.insert(item10);
	// c.insert(item2);
	// c.insert(item8);
	// c.insert(item15);
	// c.insert(item11);
	// c.insert(item14);
	// c.insert(item13);
	// c.insert(item12);
	// b.print();


	// c.remove(15);
	// c.remove(14);


	// 		c.print();



    // cout << "\nAVLTree contents:" << endl;
    // for(AVLTree<char,int>::iterator it = at.begin(); it != at.end(); ++it) {
    //     cout << it->first << " " << it->second << endl;
    // }
    // if(at.find('b') != at.end()) {
    //     cout << "Found b" << endl;
    // }
    // else {
    //     cout << "Did not find b" << endl;
    // }
    // cout << "Erasing b" << endl;
    // at.remove('b');

    return 0;
}

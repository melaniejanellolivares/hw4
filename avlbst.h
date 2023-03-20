#ifndef AVLBST_H
#define AVLBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include "bst.h"

struct KeyError { };

/**
* A special kind of node for an AVL tree, which adds the balance as a data member, plus
* other additional helper functions. You do NOT need to implement any functionality or
* add additional data members or helper functions.
*/
template <typename Key, typename Value>
class AVLNode : public Node<Key, Value>
{
public:
    // Constructor/destructor.
    AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent);
    virtual ~AVLNode();

    // Getter/setter for the node's height.
    int8_t getBalance () const;
    void setBalance (int8_t balance);
    void updateBalance(int8_t diff);

    // Getters for parent, left, and right. These need to be redefined since they
    // return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
    // for more information.
    virtual AVLNode<Key, Value>* getParent() const override;
    virtual AVLNode<Key, Value>* getLeft() const override;
    virtual AVLNode<Key, Value>* getRight() const override;

protected:
    int8_t balance_;    // effectively a signed char
};

/*
  -------------------------------------------------
  Begin implementations for the AVLNode class.
  -------------------------------------------------
*/

/**
* An explicit constructor to initialize the elements by calling the base class constructor
*/
template<class Key, class Value>
AVLNode<Key, Value>::AVLNode(const Key& key, const Value& value, AVLNode<Key, Value> *parent) :
    Node<Key, Value>(key, value, parent), balance_(0)
{

}

/**
* A destructor which does nothing.
*/
template<class Key, class Value>
AVLNode<Key, Value>::~AVLNode()
{

}

/**
* A getter for the balance of a AVLNode.
*/
template<class Key, class Value>
int8_t AVLNode<Key, Value>::getBalance() const
{
    return balance_;
}

/**
* A setter for the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::setBalance(int8_t balance)
{
    balance_ = balance;
}

/**
* Adds diff to the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::updateBalance(int8_t diff)
{
    balance_ += diff;
}

/**
* An overridden function for getting the parent since a static_cast is necessary to make sure
* that our node is a AVLNode.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getParent() const
{
    return static_cast<AVLNode<Key, Value>*>(this->parent_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getLeft() const
{
    return static_cast<AVLNode<Key, Value>*>(this->left_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getRight() const
{
    return static_cast<AVLNode<Key, Value>*>(this->right_);
}


/*
  -----------------------------------------------
  End implementations for the AVLNode class.
  -----------------------------------------------
*/


template <class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value>
{
public:
    virtual void insert (const std::pair<const Key, Value> &new_item); // TODO
    virtual void remove(const Key& key);  // TODO
protected:
    virtual void nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2);

    // Add helper functions here

    void rotateLeft(AVLNode<Key,Value>* node);
    void rotateRight(AVLNode<Key,Value>* node);
		int getHeightA(AVLNode<Key,Value>* root);
		void insertFix(AVLNode<Key,Value>* parent, AVLNode<Key,Value>* node);
		void removeFix(AVLNode<Key,Value>* parent, int diff);




};

/*
 * Recall: If key is already in the tree, you should 
 * overwrite the current value with the updated value.
 */
template<class Key, class Value>
void AVLTree<Key, Value>::insert(const std::pair<const Key, Value> &new_item)
{
    // TODO
		

		if(BinarySearchTree<Key, Value>::empty()){
			BinarySearchTree<Key, Value>::root_ =  new AVLNode<Key, Value>(new_item.first, new_item.second, NULL);
			static_cast<AVLNode<Key, Value>*>(BinarySearchTree<Key, Value>::root_)->setBalance(0);
			return;
    }
		if(BinarySearchTree<Key, Value>::internalFind(new_item.first) != NULL){ //found
			BinarySearchTree<Key, Value>::internalFind(new_item.first)->setValue(new_item.second);
			return;
		}

    Node<Key, Value>* temp = BinarySearchTree<Key, Value>::root_;

    while(temp->getLeft() != NULL || temp->getRight() != NULL){

        if(new_item.first < temp->getKey() ){

            if(temp->getLeft() == NULL){
                break;
            }
            temp= temp->getLeft();
        }
        else{

            if(temp->getRight() == NULL){
                break;
            }
            temp= temp->getRight();
        }

    }

    AVLNode<Key, Value>* addingNode = new AVLNode<Key, Value>(new_item.first, new_item.second, static_cast<AVLNode<Key, Value>*>(temp));
    addingNode->setLeft(NULL);
    addingNode->setRight(NULL);

    if(new_item.first < temp->getKey()){
														
			temp->setLeft(addingNode);
    }
    else{
														

			temp->setRight(addingNode);

    }





		Node<Key, Value>* newNode = BinarySearchTree<Key, Value>::internalFind(new_item.first);

		//need to get parent of the new node and update its balance

		static_cast<AVLNode<Key, Value>*>(newNode)->setBalance(0);
		if(newNode == BinarySearchTree<Key, Value>::root_){
			return; 
		}
		Node<Key, Value>* newNodeParent = newNode->getParent();
		if(static_cast<AVLNode<Key, Value>*>(newNodeParent)->getBalance() == -1){
			static_cast<AVLNode<Key, Value>*>(newNodeParent)->setBalance(0);
			// insertFix(static_cast<AVLNode<Key, Value>*>(newNodeParent), static_cast<AVLNode<Key, Value>*>(newNode));
			return;
		}
		else if(static_cast<AVLNode<Key, Value>*>(newNodeParent)->getBalance() == 1){
			static_cast<AVLNode<Key, Value>*>(newNodeParent)->setBalance(0);
				// insertFix(static_cast<AVLNode<Key, Value>*>(newNodeParent), static_cast<AVLNode<Key, Value>*>(newNode));

			return;
		}
		// else if(static_cast<AVLNode<Key, Value>*>(newNodeParent)->getBalance() == 0){
		// 	if(static_cast<AVLNode<Key, Value>*>(newNodeParent)->getRight() == newNode){ // new node right child
		// 		static_cast<AVLNode<Key, Value>*>(newNodeParent)->updateBalance(1);
		// 	}
		// 	else{
		// 		static_cast<AVLNode<Key, Value>*>(newNodeParent)->updateBalance(-1);
		// 	}
		// 	insertFix(static_cast<AVLNode<Key, Value>*>(newNodeParent), static_cast<AVLNode<Key, Value>*>(newNode));
		// }
		else{
			if(newNodeParent->getRight() == newNode){
				static_cast<AVLNode<Key, Value>*>(newNodeParent)->setBalance(1);
			}
			else{
				static_cast<AVLNode<Key, Value>*>(newNodeParent)->setBalance(-1);

			}
			insertFix(static_cast<AVLNode<Key, Value>*>(newNodeParent), static_cast<AVLNode<Key, Value>*>(newNode));
		}

}

template<class Key, class Value>
void AVLTree<Key, Value>::insertFix(AVLNode<Key,Value>* parent, AVLNode<Key,Value>* node){
	if(parent == NULL || parent->getParent() == NULL){
		return; 
	}
	AVLNode<Key,Value>* gp = parent->getParent();

	if(gp->getLeft() == parent){ //p is left child of gp
		gp->updateBalance(-1);
		if(gp->getBalance() == 0){
			return;
		}
		else if(gp->getBalance() == -1){
			insertFix(gp, parent);

		}
		else if(gp->getBalance() == -2){
			if(parent->getLeft() == node){ //zig-zig 
				rotateRight(gp);
				parent->setBalance(0);
				gp->setBalance(0);


			}
			else{//zig-zag
				rotateLeft(parent);
			 	rotateRight(gp);
				if(node->getBalance() == -1){
					parent->setBalance(0);
					gp->setBalance(1);
					node->setBalance(0);
				}
				else if(node->getBalance() == 0){
					parent->setBalance(0);
					gp->setBalance(0);
					node->setBalance(0);
				}
				else if(node->getBalance() == 1){
					parent->setBalance(-1);
					gp->setBalance(0);
					node->setBalance(0);
				}
			}
		}
	}
	else{
		gp->updateBalance(1);
		if(gp->getBalance() == 0){
			return;
		}
		else if(gp->getBalance() == 1){
			insertFix(gp, parent);

		}
		else if(gp->getBalance() == 2){
			if(parent->getRight() == node){ //zig-zig 
				rotateLeft(gp);
				parent->setBalance(0);
				gp->setBalance(0);


			}
			else{//zig-zag
				rotateRight(parent);
			 	rotateLeft(gp);
				if(node->getBalance() == 1){
					parent->setBalance(0);
					gp->setBalance(-1);
					node->setBalance(0);
				}
				else if(node->getBalance() == 0){
					parent->setBalance(0);
					gp->setBalance(0);
					node->setBalance(0);
				}
				else if(node->getBalance() == -1){
					parent->setBalance(1);
					gp->setBalance(0);
					node->setBalance(0);
				}
			}
		}

	}
	


}


/*
 * Recall: The writeup specifies that if a node has 2 children you
 * should swap with the predecessor and then remove.
 */
template<class Key, class Value>
void AVLTree<Key, Value>:: remove(const Key& key)
{
    // TODO
		

		if(BinarySearchTree<Key, Value>::root_ == NULL){
			return;
		}
		if(BinarySearchTree<Key, Value>::internalFind(key) == NULL){
			return;
		}
    AVLNode<Key, Value>* temp = static_cast<AVLNode<Key, Value>*>(BinarySearchTree<Key, Value>::internalFind(key));
		int diff = 0;

		// if(temp->getLeft() != NULL && temp->getRight() != NULL){ //2 children
		// 	Node<Key, Value>* temppred = BinarySearchTree<Key, Value>::predecessor(temp); 
		
			
		// 	nodeSwap(static_cast<AVLNode<Key, Value>*>(temp), static_cast<AVLNode<Key, Value>*>(temppred));
			
		// 	if(temp->getLeft() == NULL && temp->getRight() == NULL){
		// 		if(temp == BinarySearchTree<Key, Value>::root_){
						
		// 			delete temp;
		// 			BinarySearchTree<Key, Value>::root_ = NULL;
		// 		}
		// 		else if(temp->getParent()->getLeft() == temp){ //left child
		// 				temp->getParent()->setLeft(NULL);
		// 			delete temp;
		// 			diff = 1;
		// 		}
		// 		else{ //right child
		// 			temp->getParent()->setRight(NULL);
		// 			delete temp;
		// 			diff = -1;

		// 		}
    // 	}
		// 	else if( (temp->getLeft() == NULL && temp->getRight() != NULL ) || (temp->getLeft() != NULL && temp->getRight() == NULL )){ //one child
					
		// 		if(temp->getLeft() != NULL){
		// 				Node<Key, Value>* templeft = temp->getLeft();
		// 				if(temp == BinarySearchTree<Key, Value>::root_){
							
		// 					delete temp;
		// 					BinarySearchTree<Key, Value>::root_ = templeft;
		// 				}
		// 				else if(temp->getParent()->getLeft() == temp){ //left child
		// 				temp->getParent()->setLeft(templeft);
		// 				templeft->setParent(temp->getParent()); 
		// 				delete temp;
		// 				diff = 1;
		// 			}
		// 			else{
		// 				temp->getParent()->setRight(templeft);
		// 				templeft->setParent(temp->getParent()); 
		// 				delete temp;
		// 				diff = -1;

		// 			}
						
		// 		}
		// 		else{
		// 				Node<Key, Value>* tempright = temp->getRight();
		// 				if(temp == BinarySearchTree<Key, Value>::root_){
		// 					delete temp;
		// 					BinarySearchTree<Key, Value>::root_ = tempright;
							
		// 				}
		// 				else if(temp->getParent()->getLeft() == temp){ //left child
		// 					temp->getParent()->setLeft(tempright);
		// 					tempright->setParent(temp->getParent()); 
		// 					delete temp;
		// 					diff = 1;
		// 				}
		// 				else{
		// 					temp->getParent()->setRight(tempright);
		// 					tempright->setParent(temp->getParent()); 
		// 					delete temp;
		// 					diff = -1;

		// 				}
		// 			}
    // 		}
		// }
	  // BinarySearchTree<Key, Value>::print();
		if(temp->getLeft() != NULL && temp->getRight() != NULL){ //2 children
			AVLNode<Key, Value>* temppred = static_cast<AVLNode<Key, Value>*>(BinarySearchTree<Key, Value>::predecessor(temp)); 
			nodeSwap(temp, temppred);
		}
				
		if(temp->getLeft() == NULL && temp->getRight() == NULL){ //0 child
			if(temp == BinarySearchTree<Key, Value>::root_){

				delete temp;
				BinarySearchTree<Key, Value>::root_ = NULL;
				return;
			
				
					
				
			}
			else if(temp->getParent()->getLeft() == temp){ //left child
				temp->getParent()->setLeft(NULL);
				diff = 1;
			}
			else{ //right child
				temp->getParent()->setRight(NULL);
				diff = -1;

			}
			

		}
		else if( temp->getLeft() == NULL || temp->getRight() == NULL ){ //one child
				
			if(temp->getLeft() != NULL){
				AVLNode<Key, Value>* templeft = static_cast<AVLNode<Key, Value>*>(temp->getLeft());
				if(temp == BinarySearchTree<Key, Value>::root_){
					
					BinarySearchTree<Key, Value>::root_ = templeft;
					BinarySearchTree<Key, Value>::root_->setParent(NULL);
					// diff = 1;
				}
				else if(temp->getParent()->getLeft() == temp){ //left child
					templeft->setParent(temp->getParent()); 

					temp->getParent()->setLeft(templeft);
					diff = 1;

				}
				else{
					templeft->setParent(temp->getParent()); 

					temp->getParent()->setRight(templeft);
					diff = -1;

				}
					
			}
			else{
				AVLNode<Key, Value>* tempright = static_cast<AVLNode<Key, Value>*>(temp->getRight());
				if(temp == BinarySearchTree<Key, Value>::root_){
					BinarySearchTree<Key, Value>::root_ = tempright;
					BinarySearchTree<Key, Value>::root_->setParent(NULL);
					// diff = -1;


				}
				else if(temp->getParent()->getLeft() == temp){ //left child
					tempright->setParent(temp->getParent()); 

					temp->getParent()->setLeft(tempright);
					diff = 1;
				}
				else{
					tempright->setParent(temp->getParent()); 

					temp->getParent()->setRight(tempright);
					diff = -1;

			}
		}
		}
		
		
		
	
			
			
		

	
	// if(parent != NULL){
	// 	if(parent->getLeft() == temp){
	// 		diff = 1;
	// 		parent->setLeft(NULL);
	// 	}
	// 	else{
	// 		diff = -1;
	// 		parent->setRight(NULL);

	// 	}
	// }

	// }
	// if(BinarySearchTree<Key, Value>::root_ == temp){
	// 	if(temp->getLeft() != NULL){
	// 		BinarySearchTree<Key, Value>::root_ = temp->getLeft();
	// 		BinarySearchTree<Key, Value>::root_->setParent(NULL);
	// 		diff = 1;
	// 			delete temp;
	// 	}
	// 	else if(temp->getRight() != NULL){
	// 		BinarySearchTree<Key, Value>::root_ = temp->getRight();
	// 		BinarySearchTree<Key, Value>::root_->setParent(NULL);
	// 					diff = -1;

	// 					delete temp;


	// 	}
	// 	else{
	// 		BinarySearchTree<Key, Value>::root_ = NULL;
	// 		delete temp;
	// 		return;

	// 	}
	// }
	AVLNode<Key, Value>* parent = static_cast<AVLNode<Key, Value>*>(temp->getParent());

	delete temp;
	removeFix(parent, diff);

}

template<class Key, class Value>
void AVLTree<Key, Value>::removeFix(AVLNode<Key,Value>* parent, int diff){
	if(parent == NULL){
		return;
	}
	AVLNode<Key, Value>* nextparent = parent->getParent();
	int nextdiff = 0;

	if(nextparent != NULL){
		if(nextparent->getLeft() == parent){
			nextdiff = 1;
		}
		else if(nextparent->getRight() == parent){
			nextdiff = -1;

		}
	}

	if(diff == -1){
		if(parent->getBalance() + diff == -2){
			AVLNode<Key, Value>* child = parent->getLeft();
			if(child->getBalance() == -1){//zig-zig
				rotateRight(parent);
				parent->setBalance(0);
				child->setBalance(0);
				removeFix(nextparent, nextdiff);
			}
			else if(child->getBalance() == 0){
				rotateRight(parent);
				parent->setBalance(-1);
				child->setBalance(1);
				return;

			}
			else if(child->getBalance() == 1){
				AVLNode<Key, Value>* gc = child->getRight();
				rotateLeft(child);
				rotateRight(parent);
				if(gc->getBalance() == 1){
					parent->setBalance(0);
					child->setBalance(-1);
					gc->setBalance(0);
				}
				else if(gc->getBalance() == 0){
					parent->setBalance(0);
					child->setBalance(0);
					gc->setBalance(0);
				}
				else if(gc->getBalance() == -1){
					parent->setBalance(1);
					child->setBalance(0);
					gc->setBalance(0);
				}
				removeFix(nextparent, nextdiff);
			}

		}
		else if(parent->getBalance() + diff == -1){
			parent->setBalance(-1);
			return;
		}
		else if(parent->getBalance() + diff == 0){
			parent->setBalance(0);
			removeFix(nextparent, nextdiff);
		}
	}
	else if(diff == 1){
		if(parent->getBalance() + diff == 2){
			AVLNode<Key, Value>* child = parent->getRight();
			if(child->getBalance() == 1){//zig-zig
				rotateLeft(parent);
				parent->setBalance(0);
				child->setBalance(0);
				removeFix(nextparent, nextdiff);
			}
			else if(child->getBalance() == 0){
				rotateLeft(parent);
				parent->setBalance(1);
				child->setBalance(-1);
				return;

			}
			else if(child->getBalance() == -1){
				AVLNode<Key, Value>* gc = child->getLeft();
				rotateRight(child);
				rotateLeft(parent);
				if(gc->getBalance() == -1){
					parent->setBalance(0);
					child->setBalance(1);
					gc->setBalance(0);
				}
				else if(gc->getBalance() == 0){
					parent->setBalance(0);
					child->setBalance(0);
					gc->setBalance(0);
				}
				else if(gc->getBalance() == 1){
					parent->setBalance(-1);
					child->setBalance(0);
					gc->setBalance(0);
				}
				removeFix(nextparent, nextdiff);
				
			}

		}
		else if(parent->getBalance() + diff == 1){
			parent->setBalance(1);
			return;
		}
		else if(parent->getBalance() + diff == 0){
			parent->setBalance(0);
			removeFix(nextparent, nextdiff);
		}
	}
		
	

}


template<class Key, class Value>
void AVLTree<Key, Value>::nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2)
{
    BinarySearchTree<Key, Value>::nodeSwap(n1, n2);
    int8_t tempB = n1->getBalance();
    n1->setBalance(n2->getBalance());
    n2->setBalance(tempB);
}
template<class Key, class Value>

void AVLTree<Key, Value>::rotateRight(AVLNode<Key,Value>* node){
    AVLNode<Key,Value>* n1 = node->getLeft();
		AVLNode<Key,Value>* n2 = n1->getRight();
		AVLNode<Key,Value>* nodeparent = node->getParent();

		if(nodeparent !=NULL){
			if(nodeparent->getLeft() == node){
					nodeparent->setLeft(n1);
				}
				else{
					nodeparent->setRight(n1);
				}
		}
		

		//chnage pointers
		//check if cahnging the root
		if(node == BinarySearchTree<Key, Value>::root_){
			BinarySearchTree<Key, Value>::root_ = node->getLeft();
			
		}
		n1->setRight(node); 
		node->setLeft(n2); 
		if(n2 != NULL){
				n2->setParent(node);

		}
		node->setParent(n1); 
		n1->setParent(nodeparent);

		//update new heights


		// node->setBalance(getHeightA(node->getRight()) - getHeightA(node->getLeft()) );
		// n1->setBalance(getHeightA(n1->getRight()) - getHeightA(n1->getLeft()));
}

template<class Key, class Value>

void AVLTree<Key, Value>::rotateLeft(AVLNode<Key,Value>* node){
    AVLNode<Key,Value>* n1 = node->getRight();
		AVLNode<Key,Value>* n2 = n1->getLeft();
		AVLNode<Key,Value>* nodeparent = node->getParent();

		if(nodeparent !=NULL){

				if(nodeparent->getLeft() == node){
					nodeparent->setLeft(n1);
				}
				else{
					nodeparent->setRight(n1);
				}
			}

		

		if(node == BinarySearchTree<Key, Value>::root_){
			BinarySearchTree<Key, Value>::root_ = node->getRight();
			
			
		}

		n1->setLeft(node);
		node->setRight(n2);
		if(n2 != NULL){
				n2->setParent(node);

		}
		node->setParent(n1);
		n1->setParent(nodeparent);
		

		// node->setBalance(getHeightA(node->getRight()) - getHeightA(node->getLeft()));
		// n1->setBalance(getHeightA(n1->getRight()) - getHeightA(n1->getLeft()));
		
    

}

template<class Key, class Value>
	int AVLTree<Key, Value>::getHeightA(AVLNode<Key,Value>* root){
		if(root == NULL){
		return 0;
	}
		if(getHeightA(root->getRight()) > getHeightA(root->getLeft()) ){
			return 1 + getHeightA(root->getRight());

		}
		else{
			return 1 + getHeightA(root->getLeft());

		}
	}



#endif

#ifndef __SLLIST_H__
#define __SLLIST_H__

namespace ds {

template <typename ItemType> class Node {
public:
  ItemType item;
  Node *next;

  Node(ItemType i, Node *n = nullptr) {
    this->item = i;
    this->next = n;
  }
};

template <typename ItemType>
class TestDriver; // for autograding only; please ignore

/** Singly linked list. */
template <typename ItemType> class SLList {
  friend class TestDriver<ItemType>; // for autograding only; please ignore

private:
  /** Pointer pointing to the sentinel node. */
  Node<ItemType> *sentinel;

  /** Stores the current size of the list. */
  int count;

public:
  /** Construct a new SLList object. */
  SLList() {
    this->sentinel = new Node<ItemType>(ItemType(), nullptr);
    this->count = 0;
  }

  /** Destroy the SLList object. */
  ~SLList() {
    count = 0;
    while (sentinel != nullptr) {
      Node<ItemType> *curr = sentinel;
      sentinel = sentinel->next;
      delete curr;
    }
  }

  /** Add x at the beginning of the list. */
  void addFirst(ItemType x) {
    count += 1;
    sentinel->next = new Node<ItemType>(x, sentinel->next);
  }

  /** Return the first element. */
  ItemType &getFirst() const { return sentinel->next->item; }

  /** Return the number of elements in list. */
  int size() const { return count; }

  /** Append the list with x. */
  void addLast(ItemType x) {
    count += 1;
    Node<ItemType> *p = sentinel;
    while (p->next != nullptr) {
      p = p->next;
    }
    p->next = new Node<ItemType>(x, nullptr);
  }
  

  inline SLList(const SLList<ItemType> &other);
  inline ItemType &get(int i) const;
  inline void insertAt (ItemType x, int pos);
  inline ItemType removeFirst();
  inline ItemType removeLast();
};

/**
 * Copy-construct a new SLList<ItemType>::SLList object
 *
 * @param other some list
 */
template <typename ItemType>
SLList<ItemType>::SLList(const SLList<ItemType> &other) {
  // TODO: Initialize the SLList to be an identical copy of `other`
  
  count = 0;
  sentinel = new Node<ItemType>(ItemType(), nullptr);
  
  Node<ItemType> *curr = other.sentinel->next; //access first node of other list
  Node<ItemType> *prev = sentinel; 

  while (curr != nullptr) 
  {
    Node<ItemType> *newNode = new Node<ItemType>(curr->item, nullptr); //create new node
   
    prev->next = newNode; 
    prev = newNode;
    curr = curr->next;
    count++; 
  }

}

/**
 *  Return the i-th item in list. Index starts from 0.
 *  For simplicity, assume the item always exists.
 *
 * @param i index of item
 * @return ItemType& the i-th item
 */
template <typename ItemType> ItemType &SLList<ItemType>::get(int i) const 
{
  // TODO:
  
  Node<ItemType> *curr = sentinel->next; //access first node
  
  for (int k = 0; k < i; k++) 
  {
    curr = curr->next;
  }
    return curr->item; //return item at i-th index

  ItemType a; //These two lines are here to avoid compilation error
  return a;
}

/**
 *  Add a new Itemtype of valeu x into the list at the i-th item in list. Index starts from 0.
 *  For simplicity, assume the list containts at least i number of items.
 * @param x new item to into the list 
 * @param i index for the new item
 */
template <typename ItemType> void SLList<ItemType>::insertAt(ItemType x, int i) 
{
  // TODO:
  
  Node<ItemType> *prev = sentinel;
  
  for (int j = 0; j < i; j++) 
  {
    prev = prev->next; // node at position j-1
  }
  
  Node<ItemType> *newNode = new Node<ItemType>(x, prev->next); //new node linked to prev node
  prev->next = newNode; 
  
  count++; 
 
}

/**
 * Remove and return the first item of the list.
 * For example, list [1,2,3] becomes [2,3] and 1 is returned.
 *
 * @return ItemType the first item in the original list before removing
 */
template <typename ItemType> ItemType SLList<ItemType>::removeFirst() {
  // TODO:
  
  Node<ItemType> *firstNode = sentinel->next; 
  ItemType item = firstNode->item;
  sentinel->next = firstNode->next; //sentinel node moved over one
  
  delete firstNode; 
  count--; 
  
  return item; 

  ItemType a; //These two lines are here to avoid compilation error
  return a;
}

/**
 * Remove and return the last item of the list.
 * For example, list [1,2,3] becomes [1,2] and 3 is returned.
 *
 * @return ItemType the last item in the original list before removing
 */
template <typename ItemType> ItemType SLList<ItemType>::removeLast() {
  // TODO:

  Node<ItemType> *prev = sentinel;
  while (prev->next->next != nullptr) //loop until there are two nodes left
  {
    prev = prev->next;
  }
   
  Node<ItemType> *lastNode = prev->next;
  ItemType item = lastNode->item; 

  delete lastNode;
  prev->next = nullptr;
  count--;
  
  return item; 
 
  ItemType a; //These two lines are here to avoid compilation error
  return a;
}

} // namespace ds

#endif // __SLLIST_H__

#include "IntArray.h"

namespace ds {

/**
 * Construct a new IntArray object
 *
 * @param len length of the IntArray
 */
IntArray::IntArray(int len) {
  // TODO: initialize data members
  length = len;
  storedArray = new int[length];
}

/**
 * Destroy the IntArray object
 */
IntArray::~IntArray() {
  // TODO: delete the internal array
  delete[] storedArray;
}

/**
 * Reverse the IntArray
 */
void IntArray::reverse() {
  // TODO: reverse `storedArray`
  int begin = 0;
  int end = length - 1;

  for(int i = 0; i < end; i++)
  {
    int temp = storedArray[begin];
    storedArray[begin] = storedArray[end];
    storedArray[end] = temp;

    begin++;
    end--;
  }
}

} // namespace ds

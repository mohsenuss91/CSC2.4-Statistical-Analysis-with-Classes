//statList.h
//
//Created by Hunter Holder

#ifndef H_statList
#define H_statList

#include <iostream>
#include <cassert>

using namespace std;

class statList
{
public:
    bool isEmpty() const;  /* *WRITTEN* */
    //Function to determine whether the list is empty.
    //Postcondition: Returns true if the list is empty,
    //               otherwise it returns false.
    
    bool isFull() const;  /* *WRITTEN* */
    //Function to determine whether the list is full.
    //Postcondition: Returns true if the list is full,
    //               otherwise it returns false.
    
    int getLength() const;  /* *WRITTEN* */
    //Function to return the number of elements in the list.
    //Postcondition: The value of length is returned.
    
    int getMaxSize() const;  /* *WRITTEN* */
    //Function to return the maximum number of elements
    //that can be stored in the list.
    //Postcondition: The value of maxSize is returned.
    
    double getItem(int) const;  /* *WRITTEN* */
    //Function to return the value held in the list at position i.
    //Postcondition: The value held in the list at i is returned.
    
    double getMedian() const;
    //Function to return the median of the list.
    //Precondition:  The list must be sorted and the size known.
    //Postcondition:  The median of the list is returned.
    //Odd and even length lists are accounted for.
    
    double getMean() const;
    //Function to return the mean of the list.
    //Precondition:  none
    //Postcondition:  The mean of the list is returned.
    
    double getStdDev() const;
    //Function to return the standard deviation of the list.
    //Precondition:  The mean of the list must be known.
    //The list mean will be retrieved by getMean.
    //Postcondition:  The mean of the list is returned.
    
    void insertAt(double, int);
    //Function to insert item in the list at the location
    //specified by position.
    //Postcondition: list[position] = item; length++;
    //               If position is out of range, the program
    //               is aborted.
    
    void findIndex(double);
    //Function to find the index at which to insert the item read
    //in by insertInOrder, passing it and the index to insertAt.
    //Postcondition: position found in list for item insertion.
    
    void insertInOrder(ifstream& inFl);
    //Function to read all values from a given file and pass each
    //findIndex.
    //Postcondition: All items from file read in and inserted
    //in order.
    
    void printList(ostream&) const;
    //Print the list in a tabular format, then print its statistics.
    
    statList();  /* *WRITTEN* */
    
    statList(int listSize);  /* *WRITTEN* */
    //Constructor
    //Creates an array of double of the size specified by the
    //parameter listSize; the default array size is 50.
    //Postcondition: list contains the base address of the
    //               array; length = 0; maxsize = listSize;
    //               the array is initialized.
    
    ~statList();  /* *WRITTEN* */
    //Destructor
    //Deletes all the elements of the list.
    //Postcondition: The array list is deleted.
    
private:
    int maxSize;   //variable to store the maximum size
    //of the list
    int length;    //variable to store the number of elements
    //in the list
    double *list;  //pointer to the array that holds the
    //list elements
};
#endif

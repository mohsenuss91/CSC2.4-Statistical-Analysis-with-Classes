
//statListImp.cpp
//
//Created by Hunter Holder


#ifndef M_statList
#define M_statList

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include "statList.h"

bool statList::isEmpty() const
{
    return (length == 0);
    
}

bool statList::isFull() const
{
    return (length == maxSize);
}

int statList::getLength() const
{
    return length;
}

int statList::getMaxSize() const
{
    return maxSize;
}

double statList::getItem(int i) const
{
    assert(i < maxSize);
    assert(i >= 0);
    assert (length > 0);
    return list[i];
}

double statList::getMedian() const
{
    assert (length > 0);
    
    double median = 0;
    
    //odd number of array elements
    if (length % 2 != 0){
        median = list[(length/2)];
    }
    
    
    //even number of array elements
    else if (length % 2 == 0){
        int i1, i2;
        
        i1 = (length/2) - 1;
        i2 = (length/2);
        
        median = (list[i1] + list[i2])/2;
    }
    
    return median;
}

double statList::getMean() const
{
    assert (length > 0);
    
    double sum = 0;
    double mean = 0;
    
    for(int i = 0; i<length; i++)
        sum += list[i];
    
    mean = sum/length;
    
    return mean;
}

double statList::getStdDev() const
{
    
    assert (length > 0);
    double mean = getMean();
    double diff = 0;
    
    for(int i = 0; i < length; i++){
        diff += (((list[i] - mean) * (list[i] - mean)));
    }
    
    double deviation = sqrt(diff / (length-1));
    
    
    return deviation;
}

void statList::printList(ostream& outPtr) const
{
    int i;
    
        outPtr << setprecision(3) << right << fixed << showpoint;
    for(i=0; i < length; i++){
        outPtr << setw(8) << getItem(i);
        if ((i+1)%10 == 0 && i != 1) outPtr << endl;
        else outPtr << " |";
    }
    outPtr << right << endl;
    outPtr << setw(23) << "Length = " << length << endl;
    outPtr << setw(23) << "Mean = " << getMean() << endl;
    outPtr << setw(23) << "Median = " << getMedian() << endl;
    outPtr << setw(23) << "Standard Deviation = " << getStdDev() << endl;
}//end of printList

//Constructor; the default array size is 50
statList::statList(int listSize)
{
    listSize = 50;
    list = new double [listSize];
    length = 0;
    maxSize = listSize;
    for (int i=0; i<listSize; i++) list[i] = 0;
}

statList::~statList()  //destructor
{
    delete  [] list;
}

void statList::insertAt(double item, int position)
{
    assert(length <= maxSize);
    assert(position >= 0);
    assert(position <= maxSize);
    
    int i;
    
    //Move all elements in the list from the insertion point to the
    //right end one index to the right, then insert the item at the
    //insertion point, position.
    
    for (i=length; i>position; i--)
        list[i] = list[i-1];
    list[position] = item;
    length++;

    
}//end insertAt

void statList::findIndex(double item)
{
    int limit = 0;
    
    while (item > list[limit] && limit < length)
        limit++;
    
    insertAt(item, limit);

}

void statList::insertInOrder(ifstream& inFl)
{
    double nxtVal = 0;
    //while there are values to be read from the stream passed, read
    //each in and call findIndex with the current value.
    
    
    while (inFl >> nxtVal)
        (findIndex(nxtVal));

}

#endif


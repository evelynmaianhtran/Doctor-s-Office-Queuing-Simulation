/*
* lqueue.hpp
* Written by : Mai Anh Tran (c3427150)
* Modified : 05/02/2024
*
* This class represents the implementation for a templated Queue using a linked list as the underlying collection.
* This file should be used in conjunction with Assignment 2 for SENG1120/SENG6120.
*/
//Constructor
//Create a new LQueue with all the variables initialised
template <typename T>
LQueue<T>::LQueue()
{   
    list = new std::list<T>(); //Create a new list
    count = 0;
}

//Destructor
template <typename T>
LQueue<T>::~LQueue()
{

}

// Insert the supplied data to the rear of the queue
template <typename T>
void LQueue<T>::enqueue(const T& data)
{   
    list->push_back(data);   //Insert the data to the back of the queue       
    count++;                 //Increase the count
}

// Removes and returns the front element from the queue.
template <typename T>
T LQueue<T>::dequeue()
{
    // Throws an exception if the queue is empty
    if(empty()) {
        throw empty_collection_exception();
    }

    T removed_data = list->front(); //Get the data item from the front of the list
    list->pop_front();              //Remove the front element from the queue
    count--;                        //Decrease the count
    return removed_data;            //Return removed data
}

// Returns a reference to the front element on the queue.
template <typename T>
T& LQueue<T>::front()
{   
    // Throws an exception if the queue is empty
    if(empty()) {
        throw empty_collection_exception();
    }

    return list->front();
}

// Returns the number of items in the queue.
template <typename T>
int LQueue<T>::size() const
{
    return count;
}

// Check if the queue is empty
template <typename T>
bool LQueue<T>::empty() const
{
    if(count == 0)      return true; 
    else                return false;
    
}
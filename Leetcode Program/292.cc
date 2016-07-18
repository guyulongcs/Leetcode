#include <iostream>
#include <list>
using namespace std;

void printList(list<int> l) {
    std::cout << "list: ";
    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
        std::cout << *it << ' ';
    
    std::cout << '\n';
}
int main ()
{
    // constructing lists
    // constructors used in the same order as described above:
    std::list<int> first;                                // empty list of ints
    std::list<int> second (4,100);                       // four ints with value 100
    std::list<int> third (second.begin(),second.end());  // iterating through second
    std::list<int> fourth (third);                       // a copy of third
    
    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    std::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
    
    
    //methods
    list<int> l(myints);
    printList(l);
    
    return 0;
}
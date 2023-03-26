#include <iostream>
#include "Container.h"
using namespace std;

int main()
{
    try
    {
    Array array(10);
    for (int i = 0; i < 10; ++i)
        array[i] = i + 1;
    
        array.resize(8);
        array.insertAfter(20, 5);
        array.remove(3);
        array.insertAtEnd(30);
        array.insertAtBeginning(40);
        
        for (int i = 0; i < array.getLength(); ++i)
            std::cout << array[i] << ' ';
        std::cout << endl;
        array.search(20);
    }
    catch (const char* exception)
    {
       cout << " exception cought: " << exception << endl;
    }
    catch (bad_alloc& array)
    {
        cout << "bad_alloc caught!" << endl;
        cout << array.what() << endl;
    }
    

    return 0;
}
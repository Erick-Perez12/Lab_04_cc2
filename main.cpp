#include <iostream>
#include "node.h"
//#include "node.cpp"
#include "list.h"
//#include "list.cpp"
#include <string>
using namespace std;
 
int main()
{
    LinkedList<int> list_1;
    list_1.insert(2);
    list_1.insert(4);
    list_1.insert(8);
    list_1.insert(24);
    list_1.print();
    list_1.remove(3);
    list_1.print();
    cout<<endl;
   
    //cout<<list_1;
    
    
    //Node n1= Node(14);
    //Node n2= Node(31);
    //cout<<n1<<endl;
    //cout<<n2;
    
    return 0;
}
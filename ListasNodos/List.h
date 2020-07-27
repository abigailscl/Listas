#if !defined(__List_h)
#define __List_h
#include "Node.h"
#include <iostream>
using namespace std;
template <class T>
class List{
	public:
		List();
		~List(){}
		virtual bool isEmpty() = 0;
	/*	virtual T adition()= 0;
    	virtual T adition(int, int)= 0;
		virtual T subtraction(int, int)= 0;
		virtual T multiplication(int, int)= 0;
		virtual T division(int, int)= 0;*/
};
/**@brief  Constructor
@param  void
@returns void
*/
template <class T>
List<T>::List(){

}
/**@brief  Verifica si la lista esta vacia
@param  void
@returns void
*/
template <class T>
bool List<T>::isEmpty(){
	
}
#endif

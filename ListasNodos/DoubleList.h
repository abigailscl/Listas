#if !defined(__DoubleList_h)
#define __DoubleList_h
#include "Node.h"
#include "List.h"
#include <iostream>
#define inicialize 0
#define inicialize1 1
using namespace std;
template<class T>
class DoubleList : List<T>{
	public:
		//Constructor
		DoubleList();
		~DoubleList(){		};
		virtual bool isEmpty();
		int sizeList();
		//Metodos para agregar
    	void addFront(T);
    	void addBack(T);
 		void addMiddle(T, int);
		//Metodos para eliminar 	
    	void deleteFront();
    	void deleteBack();
   		void deleteData(T);
    	void deletePosition(int);
    	//Imprimir
    	void printFromHead();
    	void printFromTail();
    	//Operations
	/*	virtual T adition();
    	virtual T adition(int, int);
		virtual T subtraction(int, int);
		virtual T multiplication(int, int);
		virtual T division(int, int);*/
	private:
		Node<T>* head;
		Node<T>* tail;		
};
/**@brief  Constructor
@param  void
@returns void
*/
template <class T>
DoubleList<T>::DoubleList(){
	this->head= new Node<T>;
	this->tail = new Node<T>;
	head->setNext(this->tail);
	tail->setPrevious(this->head);
	head->setPrevious(NULL);
	tail->setNext(NULL);
}
/**@brief  agregar al inicio
@param  T d
@returns void
*/
template <class T>
 void DoubleList<T>::addFront(T d){
 	Node<T>* aux = new Node<T>();
 	aux->setData(d);
 	aux->setPrevious(this->head);
 	aux->setNext(this->head->getNext());
 	
 	this->head->getNext()->setPrevious(aux);
	this->head->setNext(aux);	
 }
 /**@brief  agregar en posicion
 @param  T d
@param  int position
@returns void
*/
 template <class T>
 void DoubleList<T>::addMiddle(T d, int position){
 	int index = inicialize1;
 	if(this->isEmpty() || position == 0){
 		this->addFront(d);
	 }else if(position >= this->sizeList()){
	 	cout<<"Posicion fuera del rango de la lista"<<endl;
	 }else{
		Node<T>* aux = this->head->getNext();
		while(aux!=this->tail)
 		{
 			if(index == position){
 				Node<T>* aux2 = new Node<T>(); 
				aux2->setData(d);
				aux2->setNext(aux->getNext());
				aux2->setPrevious(aux);	
				aux->getNext()->setPrevious(aux2);
				aux->setNext(aux2);
 				break;
		 	}
		 	index ++;
 			aux = aux->getNext();
		}	 	
	 }
 }
 /**@brief  agregar al final
@param  T d
@returns void
*/
template <class T>
 void DoubleList<T>::addBack(T d){
 	Node<T>* aux = new Node<T>(); 
	aux->setData(d);
	aux->setPrevious(this->tail->getPrevious());
	aux->setNext(this->tail);
	
	this->tail->getPrevious()->setNext(aux);
	this->tail->setPrevious(aux);
 }
/**@brief  Imprimir desde la cola
@param  void
@returns void
*/
template <class T>
 void DoubleList<T>::printFromTail(){
 	Node<T>* aux = this->tail->getPrevious();
 		cout<<" NULL ";
 	while(aux!=this->head)
 	{
 		cout<<"  " <<aux->getData();
 		aux = aux->getPrevious();
	 }
	cout<<" NULL "<<endl;
 }
 /**@brief  imprimir desde la cabeza
@param  void
@returns void
*/
template <class T>
 void DoubleList<T>::printFromHead(){
 	Node<T>* aux = this->head->getNext();
 		cout<<" NULL ";
 	while(aux!=this->tail)
 	{
 		cout<< aux->getData()<< "  ";
 		aux = aux->getNext();
	 }
	 
	cout<<" NULL "<<endl;
 }
/**@brief  eliminar dato de la cabeza
@param  void
@returns void
*/
template <class T>
 void DoubleList<T>::deleteFront(){
 	Node<T>* aux = this->head->getNext()->getNext();
 	delete  this->head->getNext();
 	this->head->setNext(aux);
 	aux->setPrevious(this->head);
 }
/**@brief  eliminar dato
@param  T d
@returns void
*/
template <class T>
 void DoubleList<T>::deleteData(T d){
  	if(!this->isEmpty()){
  		Node<T>* aux = this->head->getNext();
	 	while(aux!=this->tail)
 		{
			if(aux->getData() == d){
				aux->getNext()->setPrevious(aux->getPrevious());
				aux->getPrevious()->setNext(aux->getNext());
				delete aux;
 				break;	
			}
 			aux = aux->getNext();
	 	}
	}else{
		cout<<"Lista vacia"<<endl;
	}	
 }
 /**@brief  eliminar por posicion 
@param  int position
@returns void
*/
template <class T>
 void DoubleList<T>:: deletePosition(int position){
 	int index = inicialize;
 	if(this->isEmpty()){
 		cout<<"Lista Vacia"<<endl;
	 }else if(position > this->sizeList()){
	 	cout<<"Posicion fuera del rango de la lista"<<endl;
	 }else{
  		Node<T>* aux = this->head->getNext();
	 	while(aux!=this->tail)
 		{
			if(index == position){
				Node<T>* aux2 = new Node<T>(); 
				aux->getNext()->setPrevious(aux->getPrevious());
				aux->getPrevious()->setNext(aux->getNext());
				delete aux;
 				break;	
			}
		 	index ++;
 			aux = aux->getNext();
	 	}
	 }	
 }
 /**@brief  eliminar dato desde la cola
@param  void
@returns void
*/	
template <class T>
 void DoubleList<T>::deleteBack(){
 	Node<T>* aux = this->tail->getPrevious()->getPrevious();
 	delete this->tail->getPrevious();
 	this->tail->setPrevious(aux);
 	aux->setNext(this->tail);
 	
 } 
 /**@brief  verifica si la lista esta vacia 
@param  void
@returns void
*/
template<class T>
bool DoubleList<T>::isEmpty() {
	if( (head->getNext() == this->tail && tail->getPrevious() == this->head )){
		return  true;
	}else{
		return false;
	}
}
/**@brief  Numero de datos de la lista
@param  void
@returns int
*/
template <class T>
 int DoubleList<T>::sizeList(){
 	int contador = inicialize;
 	Node<T>* aux = this->head->getNext();
 	while(aux!=this->tail)
 	{
 		aux = aux->getNext();
 		contador++;
	 }
	return contador;
 }
#endif

#if !defined(__DoubleCircularList_h)
#define __DoubleCircularList_h
#include "Node.h"
#include "List.h"
#include <iostream>
#define inicialize 0
#define inicialize1 1
using namespace std;
template<class T>
class DoubleCircularList : List<T>{
	public:
		//Constructor
		DoubleCircularList();
		~DoubleCircularList(){		};
		virtual bool isEmpty();
		int sizeList();
		//Metodos para agregar
    	void addFront(T);
    	void addEmpty(T);
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
DoubleCircularList<T>::DoubleCircularList(){
	this->head= new Node<T>;
	this->tail = new Node<T>;
	this->head = NULL;
	this->tail = NULL;
}
/**@brief  agregar el primer elemnto en una lista vacia
@param  T d
@returns void
*/
template <class T>
 void DoubleCircularList<T>::addEmpty(T d){
 	Node<T>* aux = new Node<T>();
	aux->setData(d);
	this->head = aux;
	this->tail = aux;
	aux->setPrevious(this->tail);
 	aux->setNext(this->tail);
 }
 /**@brief  agregar al inicio
@param  T d
@returns void
*/
template <class T>
 void DoubleCircularList<T>::addFront(T d){
 	if (this->isEmpty()){ 
	 	this->addEmpty(d);		
	 }else{
 		if(this->head == this->tail){
 			Node<T>* aux = new Node<T>();
 			aux->setData(d);
 			aux->setPrevious(this->tail);
 			aux->setNext(this->tail);
 			this->tail->setNext(aux);
 			this->tail->setPrevious(aux);
			this->head = aux;
		}else{
 			Node<T>* aux = new Node<T>();
 			aux->setData(d);
 			aux->setPrevious(this->tail);
 			aux->setNext(this->head);
 			this->head->setPrevious(aux);
			this->head = aux;
			this->tail->setNext(this->head);	
		}
 
	 }
 }
 /**@brief  agregar en una posicion
@param  T d
@param int position
@returns void
*/
 template <class T>
 void DoubleCircularList<T>::addMiddle(T d, int position){
 	int index = inicialize;
 	if(this->isEmpty() || position == 0){
 		this->addFront(d);
	 }else if(position > this->sizeList()){
	 	cout<<"Posicion fuera del rango de la lista"<<endl;
	 }else if(position == this->sizeList()){
		Node<T>* aux = new Node<T>();
 		aux->setData(d);
 		aux->setPrevious(this->tail->getPrevious());
 		aux->setNext(this->tail);
 		this->tail->getPrevious()->setNext(aux);
 		this->tail->setPrevious(aux);
	 }else{
		Node<T>* aux = this->head;
		while(aux!=this->tail)
 		{
 			if(index == position){
			 	Node<T>* aux2 = new Node<T>();
 				aux2->setData(d);
 				aux2->setPrevious(aux->getPrevious());
 				aux2->setNext(aux);
 				aux->getPrevious()->setNext(aux2);
 				aux->setPrevious(aux2);
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
 void DoubleCircularList<T>::addBack(T d){
 	if (this->isEmpty()){ 
	 	this->addEmpty(d);		
	 }else{
 		if(this->head == this->tail){
 			Node<T>* aux = new Node<T>();
 			aux->setData(d);
 			aux->setPrevious(this->tail);
 			aux->setNext(this->tail);
 			this->tail->setNext(aux);
 			this->tail->setPrevious(aux);
 			this->head = this->tail;
			this->tail = aux;
		}else{
 			Node<T>* aux = new Node<T>();
 			aux->setData(d);
 			aux->setPrevious(this->tail);
 			aux->setNext(this->head);
 			this->tail->setNext(aux);
			this->tail = aux;
			this->head->setPrevious(this->tail);	
		}
 
	 }
 }
/**@brief  imprimir desde la cabeza
@param  void
@returns void
*/
template <class T>
 void DoubleCircularList<T>::printFromTail(){
 	Node<T>* aux = this->tail;
 	while(aux!=this->head)
 	{	
 		cout<< aux->getData()<< "  ";
 		aux = aux->getPrevious();
	 } 
	cout<<this->head->getData()<<endl;
 }
 /**@brief  imprimir desde la cabeza
@param  void
@returns void
*/
template <class T>
 void DoubleCircularList<T>::printFromHead(){
 	Node<T>* aux = this->head;
 	while(aux!=this->tail)
 	{	
 		cout<< aux->getData()<< "  ";
 		aux = aux->getNext();
	 } 
	 cout<<this->tail->getData()<<endl;
 }
/**@brief  eliminar al inicio
@param  void
@returns void
*/
template <class T>
 void DoubleCircularList<T>::deleteFront(){
	Node<T>* aux = this->head;
	this->head->getNext()->setPrevious(this->tail);
	this->head = this->head->getNext();
	this->tail->setNext(this->head);
	delete aux;
 }
/**@brief  eliminar dato
@param  T d
@returns void
*/
template <class T>
 void DoubleCircularList<T>::deleteData(T d){
 	int index = inicialize;
 	if(this->isEmpty()){
 		cout<<"Lista vacia"<<endl;
	 }else{
		Node<T>* aux = this->head;
		while(index<=this->sizeList()){
			if(aux->getData()== d && index == 0){
				this->deleteFront();
			}else if (aux->getData()== d && index == this->sizeList()){
				this->deleteBack();
			}else if(d == aux->getData()){
			 	Node<T>* aux2 = aux;
				aux->getPrevious()->setNext(aux->getNext());
				aux->getNext()->setPrevious(aux->getPrevious());
				delete aux2;				
			}
			index ++;
 			aux = aux->getNext();
		}	
	 }	
 }
 /**@brief  eliminar posicion
@param  int position
@returns void
*/
template <class T>
 void DoubleCircularList<T>:: deletePosition(int position){
 	int index = inicialize;
 	if(this->isEmpty()){
 		cout<<"Lista vacia"<<endl;
	 }else{
	  	if(position == 0){
 			this->deleteFront();
	 	}else if(position > this->sizeList()){
	 		cout<<"Posicion fuera del rango de la lista "<<endl;
		 }else if(position == this->sizeList()){
			this->deleteBack();
		 }else{
			Node<T>* aux = this->head;
			while(aux!=this->tail)
 			{
 				if(index == position){
			 	Node<T>* aux2 = aux;
				aux->getPrevious()->setNext(aux->getNext());
				aux->getNext()->setPrevious(aux->getPrevious());
				delete aux2;
		 		}
			 	index ++;
 				aux = aux->getNext();
			}	 	
		 }	
	 }
	
 }
 /**@brief  eliminar al final
@param  T d
@returns void
*/	
template <class T>
 void DoubleCircularList<T>::deleteBack(){
	Node<T>* aux = this->tail;
	this->tail->getPrevious()->setNext(this->head);
	this->tail = this->tail->getPrevious();
	this->head->setPrevious(this->tail);
	delete aux;
	 	
 } 
 /**@brief  Verifica si la lista esta vacia
@param  void
@returns void
*/
template<class T>
bool DoubleCircularList<T>::isEmpty() {
	if( this->head == NULL && this->tail == NULL){
		return  true;
	}else{
		return false;
	}
}
/**@brief  Numero de elemntos de la lista
@param  void
@returns int
*/
template <class T>
 int DoubleCircularList<T>::sizeList(){
 	int contador = inicialize;
 	Node<T>* aux = this->head->getNext();
 	while(aux!=this->tail)
 	{
 		aux = aux->getNext();
 		contador++;
	 }
	return contador+1;
 }
#endif

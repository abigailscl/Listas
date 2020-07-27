#if !defined(__Menu_h)
#define __Menu_h
#include "List.h"
#include "SimpleList.h"
#include "SimpleCircularList.h"
#include "DoubleCircularList.h"
#include "DoubleList.h"
#include "InputData.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
using namespace std;


class Menu {
public:
	Menu();
	void funMenuPrincipal();
	void funMenuDoble();
	void funMenuSimple();
	void funMenuDobleC();
	void funMenuSimpleC();
private:
	int options;
	string *menuPrincipal = new string [5];
	string *menuSimples = new string[8];
	string *menuDobles = new string[10];
	
};
/**@brief  Constructor
@param  void
@returns void
*/
Menu::Menu()
{
	options=10;
	*(menuPrincipal + 0) = "Listas Simples         ";
	*(menuPrincipal + 1) = "Listas Doblemente Enlazadas        ";
	*(menuPrincipal + 2) = "Listas Simples Circulares        ";
	*(menuPrincipal + 3) = "Listas Doblemente Enlazadas Circulares    ";
	*(menuPrincipal + 4) = "Salir    ";
	
	*(menuSimples + 0) = "Agregar al inicio         ";
	*(menuSimples + 1) = "Agregar al final        ";
	*(menuSimples + 2) = "Eliminar al inicio        ";
	*(menuSimples + 3) = "Eliminar al final    ";
	*(menuSimples + 4) = "Eliminar por dato    ";
	*(menuSimples + 5) = "Eliminar por posicion    ";
	*(menuSimples + 6) = "Imprimir lista     ";
	*(menuSimples + 7) = "Menu principal   ";

	*(menuDobles + 0) = "Agregar al inicio         ";
	*(menuDobles + 1) = "Agregar al final        ";
	*(menuDobles + 2) = "Agregar por posicion        ";
	*(menuDobles + 3) = "Eliminar al inicio        ";
	*(menuDobles + 4) = "Eliminar al final    ";
	*(menuDobles + 5) = "Eliminar por dato    ";
	*(menuDobles + 6) = "Eliminar por posicion    ";
	*(menuDobles + 7) = "Imprimir lista desde el incio    ";
	*(menuDobles + 8) = "Imprimir lista desde el final    ";
	*(menuDobles + 9) = "Menu principal   ";

}
/**@brief  Menu principal
@param  void
@returns void
*/
void Menu::funMenuPrincipal() {
int cursor = 0;
	char tecla;
	int cont = 1;
	system("cls");
	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
		cout << "                SELECCIONE UNA OPCION         " << endl;
		for (int i = 0; i < 5; i++) {
			if (cursor == i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << *(menuPrincipal + i) << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << *(menuPrincipal + i) << endl;
			}
		}//complejidad de algoritmos ejemplo
		for (;;) {
			tecla = _getch();
			if (tecla == 80) {
				cursor++;
				if (cursor == 7) {
					cursor = 0;
				}
				break;
			}
			if (tecla == 72) {
				cursor--;
				if (cursor == -1) {
					cursor = 3 + 1;
				}
				break;
			}
			if (tecla == 13) {
				switch (cursor) {
				case 0: //Listas siemples
					system("cls");
					funMenuSimple();
					break;
				case 1: //Listas dobles
					system("cls");
					funMenuDoble();
					break;
				case 2: //Listas simples circulares
					system("cls");
					funMenuSimpleC();
					break;
				case 3: //Listas dobles circulares
					system("cls");
					funMenuDobleC();
					break;
				case 4:
					exit(1);
					break;
				}
			}
		}
	}

}
/**@brief  Menu lista simple circular
@param  void
@returns void
*/
void Menu::funMenuSimpleC(){
int cursor = 0;
	char tecla;
	int cont = 1;
	char continueProcess ;
	system("cls");
	SimpleCircularList<int> scl;
	InputData<int> enter;
	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
		cout << "                LISTAS SIMPLE CIRCULARES          " << endl;
		for (int i = 0; i < 8; i++) {
			if (cursor == i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << *(menuSimples + i) << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << *(menuSimples + i) << endl;
			}
		}
		for (;;) {
			tecla = _getch();
			if (tecla == 80) {
				cursor++;
				if (cursor == 8) {
					cursor = 0;
				}
				break;
			}
			if (tecla == 72) {
				cursor--;
				if (cursor == -1) {
					cursor = 3 + 1;
				}
				break;
			}
			if (tecla == 13) {
				switch (cursor) {
				case 0: //Ingresar al incio
				cout<< "\n\n";
					do{
						scl.addBegin(atoi(enter.integer("Ingrese un numero: ").c_str()));
						cout<< "Desea volver a ingresar (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 1: //ingresar al final
					cout<< "\n\n";
					do{
						continueProcess = ' ';
						scl.addEnd(atoi(enter.integer("Ingrese un numero: ").c_str()));
						cout<< "Desea volver a ingresar (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 2: //eliminar un dato del incio
					cout<< "\n\n";
					do{
						continueProcess = ' ';
						scl.deleteBegin();
						cout<< "Desea eliminar otro dato (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 3: //eliminar un dato del final
					cout<< "\n\n";
					do{
						continueProcess = ' ';
						scl.deleteEnd();
						cout<< "Desea eliminar otro dato (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 4: //Eliminar por dato
					cout<< "\n\n";
					do{
						continueProcess = ' ';
						scl.deleteData(atoi(enter.integer("Ingrese un numero: ").c_str()));
						cout<< "Desea eliminar otro dato (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 5: //Eliminar por posicion
					cout<< "\n\n";
					do{
						continueProcess = ' ';
						scl.deletePosition(atoi(enter.positiveInteger("Ingrese un numero: ").c_str()));
						cout<< "Desea eliminar otro dato (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 6: //Imprimir
					cout<< "\n\n";
					scl.printList();
					break;
				case 7: //Regresar al menu
					funMenuPrincipal();
					break;
				}
			}
		}
	}
	free(menuSimples);
}
/**@brief  Menu listas simple
@param  void
@returns void
*/
void Menu::funMenuSimple(){
int cursor = 0;
	char tecla;
	int cont = 1;
	char continueProcess ;
	system("cls");
	SimpleList<int> sl;
	InputData<int> enter;
	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
		cout << "                LISTAS SIMPLE          " << endl;
		for (int i = 0; i < 8; i++) {
			if (cursor == i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << *(menuSimples + i) << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << *(menuSimples + i) << endl;
			}
		}
		for (;;) {
			tecla = _getch();
			if (tecla == 80) {
				cursor++;
				if (cursor == 8) {
					cursor = 0;
				}
				break;
			}
			if (tecla == 72) {
				cursor--;
				if (cursor == -1) {
					cursor = 3 + 1;
				}
				break;
			}
			if (tecla == 13) {
				switch (cursor) {
				case 0: //Ingresar al incio
				cout<< "\n\n";
					do{
						sl.addBegin(atoi(enter.integer("Ingrese un numero: ").c_str()));
						cout<< "Desea volver a ingresar (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 1: //ingresar al final
					cout<< "\n\n";
					do{
						continueProcess = ' ';
						sl.addEnd(atoi(enter.integer("Ingrese un numero: ").c_str()));
						cout<< "Desea volver a ingresar (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 2: //eliminar un dato del incio
					cout<< "\n\n";
					do{
						continueProcess = ' ';
						sl.deleteBegin();
						cout<< "Desea eliminar otro dato (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 3: //eliminar un dato del final
					cout<< "\n\n";
					do{
						continueProcess = ' ';
						sl.deleteEnd();
						cout<< "Desea eliminar otro dato (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 4: //Eliminar por dato
					cout<< "\n\n";
					do{
						continueProcess = ' ';
						sl.deleteData(atoi(enter.integer("Ingrese un numero: ").c_str()));
						cout<< "Desea eliminar otro dato (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 5: //Eliminar por posicion
					cout<< "\n\n";
					do{
						continueProcess = ' ';
						sl.deletePosition(atoi(enter.positiveInteger("Ingrese un numero: ").c_str()));
						cout<< "Desea eliminar otro dato (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 6: //Imprimir
					cout<< "\n\n";
					sl.printList();
					break;
				case 7: //Regresar al menu
					funMenuPrincipal();
					break;
				}
			}
		}
	}
	free(menuSimples);
}
/**@brief  Menu listas dobles circulares
@param  void
@returns void
*/
void Menu::funMenuDobleC(){
int cursor = 0;
	char tecla;
	char continueProcess;
	int cont = 1;
	system("cls");
	DoubleCircularList<int> dcl;
	InputData<int> enter;
	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
		cout << "              LISTAS DOBLEMENTE ENLAZADAS CIRCULARES         " << endl;
		for (int i = 0; i < 10; i++) {
			if (cursor == i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << *(menuDobles + i) << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << *(menuDobles + i) << endl;
			}
		}
		for (;;) {
			tecla = _getch();
			if (tecla == 80) {
				cursor++;
				if (cursor == 10) {
					cursor = 0;
				}
				break;
			}
			if (tecla == 72) {
				cursor--;
				if (cursor == -1) {
					cursor = 3 + 1;
				}
				break;
			}
			if (tecla == 13) {
				switch (cursor) {
				case 0: //Ingrese al incio
					cout<< "\n\n";
					do{
						dcl.addFront(atoi(enter.integer("Ingrese un numero: ").c_str()));
						cout<< "Desea volver a ingresar (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 1: //Ingrese al final
					cout<< "\n\n";
					do{
						dcl.addBack(atoi(enter.integer("Ingrese un numero: ").c_str()));
						cout<< "Desea volver a ingresar (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 2: //ingrese por posicion
					cout<< "\n\n";
					int dato, pos;
					do{
						dato = atoi(enter.integer("Ingrese un numero: ").c_str());
						pos = atoi(enter.positiveInteger("Ingrese una posicion: ").c_str());
						dcl.addMiddle(dato, pos);
						cout<< "Desea volver a ingresar (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
				case 3: //eliminar dato inicial
					cout<< "\n\n";
					do{
						dcl.deleteFront();
						cout<< "Desea eliminar otro dato (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 4: //eliminar dato final
					cout<< "\n\n";
					do{
						dcl.deleteBack();
						cout<< "Desea eliminar otro dato (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 5: //eliminar por dato
					cout<< "\n\n";
					do{
						dcl.deleteData(atoi(enter.integer("Ingrese un numero: ").c_str()));
						cout<< "Desea eliminar otro dato (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 6: //eliminar por posicion
					cout<< "\n\n";
					do{
						dcl.deletePosition(atoi(enter.positiveInteger("Ingrese una posicion: ").c_str()));
						cout<< "Desea eliminar otro dato (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 7: //imprimir por cabeza
					cout<< "\n\n";
					dcl.printFromHead();
					break;
				case 8: //imprimir por cola
					cout<< "\n\n";
					dcl.printFromTail();
					break;
				case 9: //menu principal
					funMenuPrincipal();
					break;
				}
			}
		}
	}
	free(menuDobles);
}
/**@brief  Menu lista doble
@param  void
@returns void
*/
void Menu::funMenuDoble(){
int cursor = 0;
	char tecla;
	char continueProcess;
	int cont = 1;
	system("cls");
	DoubleList<int> dl;
	InputData<int> enter;
	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
		cout << "               LISTAS DOBLEMENTE ENLAZADAS          " << endl;
		for (int i = 0; i < 10; i++) {
			if (cursor == i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << *(menuDobles + i) << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << *(menuDobles + i) << endl;
			}
		}
		for (;;) {
			tecla = _getch();
			if (tecla == 80) {
				cursor++;
				if (cursor == 10) {
					cursor = 0;
				}
				break;
			}
			if (tecla == 72) {
				cursor--;
				if (cursor == -1) {
					cursor = 3 + 1;
				}
				break;
			}
			if (tecla == 13) {
				switch (cursor) {
				case 0: //Ingrese al incio
					cout<< "\n\n";
					do{
						dl.addFront(atoi(enter.integer("Ingrese un numero: ").c_str()));
						cout<< "Desea volver a ingresar (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 1: //Ingrese al final
					cout<< "\n\n";
					do{
						dl.addBack(atoi(enter.integer("Ingrese un numero: ").c_str()));
						cout<< "Desea volver a ingresar (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 2: //ingrese por posicion
					cout<< "\n\n";
					int dato, pos;
					do{
						dato = atoi(enter.integer("Ingrese un numero: ").c_str());
						pos = atoi(enter.positiveInteger("Ingrese una posicion: ").c_str());
						dl.addMiddle(dato, pos);
						cout<< "Desea volver a ingresar (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
				case 3: //eliminar dato inicial
					cout<< "\n\n";
					do{
						dl.deleteFront();
						cout<< "Desea eliminar otro dato (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 4: //eliminar dato final
					cout<< "\n\n";
					do{
						dl.deleteBack();
						cout<< "Desea eliminar otro dato (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 5: //eliminar por dato
					cout<< "\n\n";
					do{
						dl.deleteData(atoi(enter.integer("Ingrese un numero: ").c_str()));
						cout<< "Desea eliminar otro dato (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 6: //eliminar por posicion
					cout<< "\n\n";
					do{
						dl.deletePosition(atoi(enter.positiveInteger("Ingrese un numero: ").c_str()));
						cout<< "Desea eliminar otro dato (S/N): "; cin>> continueProcess;
					}while(continueProcess == 'S' || continueProcess == 's' );
					break;
				case 7: //imprimir por cabeza
					cout<< "\n\n";
					dl.printFromHead();
					break;
				case 8: //imprimir por cola
					cout<< "\n\n";
					dl.printFromTail();
					break;
				case 9: //menu principal
					funMenuPrincipal();
					break;
				}
			}
		}
	}
	free(menuDobles);
}
#endif

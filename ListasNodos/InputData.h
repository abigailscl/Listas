/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396                                                       *
******************************************************************/
/***********************************************************************
 * Module:  IngresoDatos.h
 * Author:  Abigail Cabascango
 * Modified: domingo, 28 de mayo de 2020 17:51:04
 * Purpose: Ingresar datos por consola
 ***********************************************************************/
#if !defined(__Input_Data_h)
#define __Input_Data_h

#include<iostream>
#include"Check.h"

using namespace std;

template <class T> class InputData{
public:
	InputData();    
	string matrizFloatDouble(int, int);		
    string floatDouble();
private:
    Check check;   
    string value;
};
template <>        class InputData<int> {
public:
    string integer(string);
    string positiveInteger(string, int min, int max);
    string positiveInteger(string);
    string integerArray(int);    
    string matrizInteger(int, int);
private:
    Check check;
    string value;
};
template <>        class InputData<double> {
public:
    string realArray(int const);
private:
    Check check;
    string value;
};
template <>         class InputData<string> {
public:
    string CI(string);
private:
    Check check;
    string value;
};
///Construtor
template <class T> InputData<T>::InputData(){}

template <class T> string InputData<T>::matrizFloatDouble(int i, int j) {
    cout << "\nIngrese valor[" << i << "][" << j << "]: ";
    cin >> value;
    while (check.floatDouble(value)) {
        cout << "\nIngreso erroneo, vuelva a ingresar: ";
        cin >> value;
    }
    return value;
}

template <class T> string InputData<T>::floatDouble(){ 	
 	cout << "\nIngrese valor real:  ";
 	cin  >> value;
 	while (check.floatDouble(value)) {
 		cout << "\nIngreso erroneo, vuelva a ingresar: ";
 		cin  >> value;
    }
	return value;
}

string InputData<int>::integer(string message) {
    cout << message;
    cin >> value;
    while (check.integer(value)) {
        cout << "\nIngreso erroneo, vuelva a ingresar: ";
        cin >> value;
    }
    return value;
}

string InputData<int>::positiveInteger(string message, int min, int max){
 	cout << message;
 	cin  >> value;
 	while (check.positiveInteger(value, min, max)) {
 		cout << "\nIngreso erroneo, vuelva a ingresar: ";
 		cin >> value;
	}
	return value;
}

string InputData<int>::positiveInteger(string message){
 	cout << message;
 	cin  >> value;
 	while (check.positiveInteger(value)) {
 		cout << "\nIngreso erroneo, vuelva a ingresar: ";
 		cin >> value;
	}
	return value;
}

string InputData<int>::integerArray(int i) {
    cout << "\nIngrese valor[" << i << "]: ";
    cin >> value;
    while (check.integer(value)) {
        cout << "\nIngreso erroneo, vuelva a ingresar: ";
        cin >> value;
    }
    return value;
}

string InputData<int>::matrizInteger(int const i, int const j) {
 	cout << "\nIngrese valor[" << i << "][" << j << "]: ";
 	cin  >> value;
 	while (check.integer(value)) {
 		cout << "\nIngreso erroneo, vuelva a ingresar: ";
 		cin  >> value;
	}
	return value;
}

string InputData<double>::realArray(int i) {
    cout << "\nIngrese valor real[" << i << "]: ";
    cin >> value;
    while (check.floatDouble(value)) {
        cout << "\nIngreso erroneo, vuelva a ingresar: ";
        cin >> value;
    }
    return value;
}

string InputData<string>::CI(string message) {
    cout << message;    
    cin >> value;    
    while (check.identificationCard(value)) {
        cout << "\nCedula incorrecta, ingrese nuevamente: ";
        cin >> value;
    }
    return value;
}
#endif


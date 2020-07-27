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
 * Purpose: Validar datos ingresados por consola
 ***********************************************************************/

#if !defined(__Check_h)
#define __Check_h

#include<iostream>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
using namespace std;

class Check {
public:
	Check();
	bool integer(string cadena);
	bool floatDouble(string cadena);
	bool positiveInteger(string cadena, int min, int max);
	bool positiveInteger(string cadena);
	bool identificationCard(string);
	bool checkAccount(string, int);

private:
	char lastDigit(string);
	int calculateTen(int);
	int charToInt(char);
	char intToChar(int);
};

////////////////////////////////////////////////////////////////////////
// Name:       Validaciones::Validaciones()
// Purpose:    Constructor of  class Validaciones
// Parameters: 
////////////////////////////////////////////////////////////////////////
Check::Check() {}

////////////////////////////////////////////////////////////////////////
// Name:      Validaciones::validar(string cadena, int tipo) 
// Purpose:    Implementation of  Validaciones::validar(string cadena, int tipo) 
// Parameters: string cadena, int tipo
// Return:     bool
////////////////////////////////////////////////////////////////////////
bool Check::integer(string value)
{
	int cont = 0;
	try {
		for (size_t i = 0; i < value.length(); i++) {
			if (isalpha(value[i]))
				throw 1;
			if (!isdigit(value[i]) && value[i] != '-')
				throw 1;
			if (value[i] == '-')
				cont++;
			if (cont > 1)
				throw 1;

		}
	}
	catch (int e) {
		return true;
	}
	return false;
}
bool Check::floatDouble(string value)
{
	int cont = 0;

	try {
		for (size_t i = 0; i < value.length(); i++) {
			if (isalpha(value[i]))
				throw 1;
			if (!isdigit(value[i]) && value[i] == '.')
				cont++;
			if (!isdigit(value[i]) && value[i] == '-')
				cont++;
			if (cont > 2)
				throw 1;
		}
	}
	catch (int e) {
		return true;
	}
	return false;

}
bool Check::positiveInteger(string cadena, int min, int max)
{
	try {
		for (size_t i = 0; i < cadena.length(); i++) {
			if (isalpha(cadena[i]))
				throw 1;			
			if (!isdigit(cadena[i]) )
				throw 1;					
		}
		//if(atoi(cadena.c_str())< min || atoi(cadena.c_str())> max){
		//	throw 1;
		//}		
	}
	catch (int e) {
		return true;
	}	
	return false;	
}
bool Check::positiveInteger(string cadena)
{
	try {
		for (size_t i = 0; i < cadena.length(); i++) {
			if (isalpha(cadena[i]))
				throw 1;			
			if (!isdigit(cadena[i]) )
				throw 1;					
		}
		//if(atoi(cadena.c_str())< min || atoi(cadena.c_str())> max){
		//	throw 1;
		//}		
	}
	catch (int e) {
		return true;
	}	
	return false;	
}
bool Check::identificationCard(string identificationCard) {

	try {

		for (size_t i = 0; i < identificationCard.length(); i++)
		{
			if (isalpha(identificationCard[i]))
				throw 1;
			if (!isdigit(identificationCard[i]))
				throw 1;
			if (identificationCard[i] == '.')
				throw 1;
			if (identificationCard[i] == '-')
				throw 1;
			if (identificationCard[0] < 3 && identificationCard[1] < 5)
				throw 1;
			if (identificationCard[2] < 7)
				throw 1;
			if (identificationCard[9] != lastDigit(identificationCard))
				throw 1;
		}

	}
	catch (int e) {
		return true;
	}
	return false;
}

char Check::lastDigit(string identificationCard) {
	int aux, impar, result = 0;
	for (size_t i = 0; i < 5; i++) {
		aux = (2 * charToInt(identificationCard.at(2 * i)));
		if (i < 4)
			impar = charToInt(identificationCard.at((2 * i + 1)));

		if (aux >= 10)
			aux -= 9;

		result += (aux + impar);
		impar = 0;
	}
	result = calculateTen(result) - result;
	return intToChar(result);
}

int Check::calculateTen(int ten) {
	return (ten - (ten % 10)) + 10;
}

int Check::charToInt(char val) {
	if (val == 48)
		return 0;
	if (val == 49)
		return 1;
	if (val == 50)
		return 2;
	if (val == 51)
		return 3;
	if (val == 52)
		return 4;
	if (val == 53)
		return 5;
	if (val == 54)
		return 6;
	if (val == 55)
		return 7;
	if (val == 56)
		return 8;
	if (val == 57)
		return 9;

}

char Check::intToChar(int val) {
	if (val == 0)
		return '0';
	if (val == 1)
		return '1';
	if (val == 2)
		return '2';
	if (val == 3)
		return '3';
	if (val == 4)
		return '4';
	if (val == 5)
		return '5';
	if (val == 6)
		return '6';
	if (val == 7)
		return '7';
	if (val == 8)
		return '8';
	if (val == 9)
		return '9';
}
bool Check::checkAccount(string accountT, int type)
{
	string ciAccnt;
	for (int i = 2; i < 12; i++)
	{
		 ciAccnt[i] = accountT[i];
	}
	if (type == 11)
	{
		try {

			for (int i = 0; i < 12; i++)
			{
				if (isalpha(accountT[i]))
					throw 1;
				if (!isdigit(accountT[i]))
					throw 1;
				if (accountT[i] == '.')
					throw 1;
				if (accountT[i] == '-')
					throw 1;
				if (accountT[0] != '1' && accountT[1] != '1')
					throw 1;
				if (ciAccnt[0] < 3 && ciAccnt[1] < 5)
					throw 1;
				if (ciAccnt[2] < 7)
					throw 1;
				if (ciAccnt[9] != lastDigit(ciAccnt))
					throw 1;
				if (ciAccnt[9] != lastDigit(ciAccnt))
					throw 1;			
			}

		}
		catch (int e) {
			return true;
		}
	}
	if (type == 22)
	{
		try {

			for (int i = 0; i <12; i++)
			{
				if (isalpha(accountT[i]))
					throw 1;
				if (!isdigit(accountT[i]))
					throw 1;
				if (accountT[i] == '.')
					throw 1;
				if (accountT[i] == '-')
					throw 1;
				if (accountT[0] != '2' && accountT[1] != '2')
					throw 1;
				if (ciAccnt[0] < 3 && ciAccnt[1] < 5)
					throw 1;
				if (ciAccnt[2] < 7)
					throw 1;
				if (ciAccnt[9] != lastDigit(ciAccnt))
					throw 1;
				if (ciAccnt[9] != lastDigit(ciAccnt))
					throw 1;
			}

		}
		catch (int e) {
			return true;
		}
	}
}

#endif

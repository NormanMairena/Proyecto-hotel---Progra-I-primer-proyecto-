#pragma once
#include <iostream>
#include "Hotel.h"
#include "Habitacion.h"
#include <time.h>
#include<sstream>
using namespace std;
class Control {
private:
	Hotel* H;
public:
	 Control(Hotel* H);
	 int validarEntero();
	 void menu();
	 void subMenuPrimeraOpcion();
	 void subMenuCuartaOpcion();
	 void subMenuQuintaOpcion();
	 void realizarReservacion(int);
	 void opcion1_1();
	 void validarChar(char);
	 void validarTodoIncluido(bool);
	 void validarEstandar(char);
	
		


	
	

};


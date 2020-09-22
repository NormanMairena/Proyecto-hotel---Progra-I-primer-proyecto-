#include "Control.h"
Control::Control(Hotel *H){
	this->H = H;
	H->agregarHabitacion();
	H->inicializarIdentificacion();
} 
int Control::validarEntero() {
	int	Respuesta;
	bool validar = true;
	while (validar) {
		if (cin >> Respuesta) {
			return Respuesta;
		}
		else {
			cout << "Respuesta invalida, digite un numero entero(Ej.1, 2 ,3 ...)" << endl;
			cin >> Respuesta;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}
void Control::validarChar(char opcionchar) {
	if (opcionchar!= 'E'&&opcionchar != 'C'&& opcionchar != 'D'){
		cout << "Opcion incorrecta digite una opcion valida('E'.Efectivo,'C'.Credito,'D'.Debito)" << endl;
	}
	else 
		cin >> opcionchar;
}
void Control::validarTodoIncluido(bool opcionbool=0) {
	if (opcionbool != 0 && opcionbool != 1) {
		cout << "Respuesta invalida digite un valor de verdad (1.todoIncluido,2.sinTodoIncluido)" << endl;
	}
	else {
		cin >> opcionbool;
	}
}
void Control::validarEstandar(char estandar) {
	if (estandar != 'P' && estandar != 'S' && estandar != 'T') {
		cout << "Opcion incorrecta digite una opcion valida('P'(Primera Clase),'S'(SegundaClase)'T'(Tercera Clase))" << endl;
	}
	else {
		cin >> estandar;
	}
}
void Control::realizarReservacion(int id3) {

	string nombreCliente, identificacion_Cliente, numeroTelefono, numeroCuenta;
	char metodo_Pago;
	int numreservacion = rand() % 10000, numerodeniños, numerodeadultos, entrada, salida, dias;
	bool todoIncluido = 0;
	int eleccion = 1;
	cout << "----Datos de la habitacion----" << endl;
	cout << H->opcion2_0(id3);
	
		cout << "----Informacion de la reservacion----" << endl;
			cout << "Numero de reservacion: " << numreservacion << endl;
			cout << "Cuantos niños se hospedaran en el hotel" << endl;
			numerodeniños = validarEntero();
			cout << "Cuantos adultos se hospedaran en el hotel" << endl;
			numerodeadultos = validarEntero();
			cout << "Hora de entrada al hotel" << endl;
			entrada = validarEntero();
			cout << "Hora de salida del hotel" << endl;
			salida = validarEntero();
			cout << "Dias que se hospedaran" << endl;
			dias = validarEntero();
			cout << "Informacion del cliente" << endl << endl << endl;
			cout << "Digite el nombre del cliente" << endl;
			cin >> nombreCliente;
			cout << "Digite el numero de identificacion" << endl;
			cin >> identificacion_Cliente;
			cout << "Digite el numero de cuenta" << endl;
			cin >> numeroCuenta;
			cout << "Digite el numero de telefono del Cliente" << endl;
			cin >> identificacion_Cliente;
			cout << "Digite el metodo de pago, Efectivo('E'.Efectivo,'C'.Credito,'D'.Debito)" << endl;
			cin >> metodo_Pago;
			validarChar(metodo_Pago);
			cout << "Todo incluido o estandar 1 = todo incluido, 0 = no todo incluido" << endl;
			validarTodoIncluido(todoIncluido);
			Cliente* C = new Cliente(identificacion_Cliente, metodo_Pago, numeroTelefono, numeroCuenta, nombreCliente);
			Reservacion* R = new Reservacion(numreservacion, numerodeadultos, numerodeniños, entrada, salida, dias, todoIncluido);
			H->opcion3_0(id3)->ingresarcliente(C, R);
			H->opcion3_0(id3)->setestado('O');
	
} 
 void Control::opcion1_1(){
	cout<<H->tostring();
 }
 void Control::subMenuPrimeraOpcion() {
	 int opcionInterna2=1;
	  int i=0, j = 0;
	 int opcionInterna;
	  char opcion;
	 while (opcionInterna2 == 1) {
		 cout << "Seleccione una de las siguientes opciones de busqueda" << endl;
		 cout << "1 - Listado de todas las habitaciones del hotel" << endl;
		 cout << "2 - Busqueda por tipo(primera clase, segunda clase, tercera clase" << endl;
		 cout << "3 - Busqueda por cantidad de camas" << endl;
		 opcionInterna = validarEntero();
		 cout << "Presione <ENTER> para continuar" << endl;
		 cin.get();
		 cin.get();
		 system("cls");
		 switch (opcionInterna) {
		 case 1:
			 cout << "1-Listado de todas las habitaciones del hotel" << endl;
			 cout<<H->opcion1_1();
			 break;
		 case 2:
			 
			 cout << "2-Busqueda por Tipo" << endl;
			 cout << "P-> para primera clase" << endl;
			 cout << "S-> para segunda clase" << endl;
			 cout << "T-> tercera clase" << endl;
			 cin >> opcion;
			 validarEstandar(opcion);
			 cout << H->opcion1_2(opcion);
			 break;

		 case 3:
			 cout << "3-Busqueda de habitaciones por cantidad de camanas" << endl;
			 cout << "cual es el numero de camas que desea?" << endl;
			 int num;
			 cin >> num;
			 cout<<H->opcion1_3(num);
			 break;

		 }
		cout << "Desea realizar otra accion" << endl;
		opcionInterna2 = validarEntero();
		cout << "Presione <ENTER> para continuar" << endl;
		cin.get();
		cin.get();
		system("cls");
		menu();
	 }
 }
 void Control::subMenuCuartaOpcion() {
	 int opcion;
	 string idCliente;
	 int reservacionEliminar;
	 cout << "Desea liberar la habitacion por # de cedula del cliente(1) o por # de habitacion(2)" << endl;
	 opcion = validarEntero();
	 if (opcion == 1) {
		cout << "Procedemos a realizar búsqueda por cedula del cliente" << endl;
		cout << "Digite el ID del cliente :" << endl;
		cin >> idCliente;
		cout << "El cliente posee las siguientes reservaciones :" << endl;
		H->opcion5_complemento1(idCliente);
		
		cout << "Digite el numero de la reservacion que desee liberar :" << endl;
		cin >> reservacionEliminar;
		H->opcion4_1(reservacionEliminar);
		cout << "Listo!! La habitacion ha sigo liberada" << endl;
	 }
	 else if(opcion==2){
		 int id4;
		cout << "Procedemos a realizar busqueda por numero de habitacion" << endl;
		cout << "Digite el ID de la habitacion:" << endl;
		cin>>id4;
		H->opcion4_2(id4);
		cout << "Listo!! La habitacion ha sido liberada" << endl;

	}
}
 void Control::subMenuQuintaOpcion() {
	string idCliente2;
	int id5;
	
	cout << "Reservaciones por cliente" << endl;
	cout << "------------------------------------" << endl;
	
		cout << "Digite el id del cliente: " << endl;
		cin >> idCliente2;
		cout << "El cliente posee las siguientes reservaciones" << endl;
		cout << H->opcion5_complemento1(idCliente2);
		cout << "Digita el ID de la reservacion deseada" << endl;
		cin >> id5;
		cout << H->opcion5_complemento2(id5);
		cout << "Presione <ENTER> para continuar" << endl;
		cin.get();
		cin.get();
		system("cls");
}
 void Control::menu() {
	 string a;
	 int b;
	 int eleccionUsuario;
	 int respuestaInicio = 1;
	 while (respuestaInicio == 1) {
			 cout << "1.Habitaciones  libres, ocupadas y en mantenimiento" << endl;
			 cout << "2.Detalle por habitacion" << endl;
			 cout << "3.Realizar Reservacion " << endl;
			 cout << "4.Liberar Habitacion" << endl;
			 cout << "5.Reservaciones  por cliente" << endl;
			 cout << "6.Cantidad de adultos  y  ni"<<(char)164<<"os  con reservacion " << endl;
			 cout << "7.Poner habitacion  en mantenimiento  " << endl;
			 cout << "8.Cuanto dinero recaudo hoy el hotel" << endl;
			 cout << "9.Salir" << endl;
			 cout << "Cual opcion desea visualizar" << endl;
			 eleccionUsuario = validarEntero();
			 cout << "Presione <ENTER> para continuar" << endl;
			 cin.get();
			 cin.get();
			 system("cls");
			switch(eleccionUsuario) {
			 case 1:
				 subMenuPrimeraOpcion();
				 break;
			 case 2:
				 int id2;
				 cout << "Detalle de habitacion" << endl;
				 cout << "Ingrese la identificacion de su habitacion" << endl;
				 cin >> id2;
				 cout<<H->opcion2_0(id2)<<endl;
				 break;
			 case 3:
				srand(time(NULL));
				int id3;
				cout << "Realizar reservacion del usuario" << endl;
				cout << "Lista de habitaciones" << endl;
				cout<<H->opcion1_1();
				cout << "Digite el id de la habitacion en la que desea hacer la reservacion: ";
				cin>>id3;
				realizarReservacion(id3);
				
				break;
			 case 4:
				cout << "Liberar habitacion del usuario" << endl;
				cout << "Desea  realizar busqueda  por cedula  (1 ) o   por habitacion (2) ?" << endl;
				subMenuCuartaOpcion();
				break;
			 case 5:
				 subMenuQuintaOpcion();
				 break;
			 case 6:
				cout << "6.Cantidad de adultos  y  niños con reservacion " << endl<<endl; 
				cout<<H->opcion6();

				cout << "Presione <ENTER> para continuar" << endl;
				cin.get();
				cin.get();
				system("cls");
				break;
			 case 7:
				cout << "7-Poner habitación  en mantenimiento  " << endl;
				int id;
				int eleccion;
				cout<<"Digite el id de la habitacion que desea poner en mantenimiento"<<endl;
				id=validarEntero();
				cout << "Desea poner la habitacion en mantenimiento 1.Si,2.No" << endl;
				eleccion=validarEntero();
				cout<<H->opcion7_0(id);
				cout << "Presione <ENTER> para continuar" << endl;
				cin.get();
				cin.get();
				system("cls");
				break;
			 case 8:
				cout << "8-Cuánto dinero recaudó hoy el hotel" << endl; 
				cout << H->opcion8();
				break;
			 case 9:
				cout << "Presione <ENTER> para continuar" << endl;
				cin.get();
				cin.get();
				system("cls");
				exit(0); 
				break;
			 }
			 cout << "Desea realizar otra accion(1.Si,2.No)" << endl;
			 respuestaInicio = validarEntero();
			 cout << "Presione <ENTER> para continuar" << endl;
			 cin.get();
			 cin.get();
			 system("cls");
		 }
	 }
 
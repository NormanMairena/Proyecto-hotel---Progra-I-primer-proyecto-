#include "Hotel.h"
const int F = 5, C = 8;

Hotel::Hotel(){
	
	Cuartos = new Habitacion **[F];
	for (int i = 0; i < F; i++) {
		Cuartos[i] = new Habitacion * [C];
	}
	for (int i = 0; i < F; i++) {
		for (int j = 0; j < C; j++) {
			Cuartos[i][j] = NULL;
		}
	}
}
string Hotel::tostring(){
	stringstream s;
	for (int f = 0; f < F; f++) {
		for (int c = 0; c < C; c++) {
			s << "[" << Cuartos[f][c] << "]";
			s << Cuartos[f][c]->tostring();
		}
		s << '\n';
	}
	return s.str();
}
void Hotel::inicializarIdentificacion() {
	
	int n = 1;
	for (int f = 0; f < F; f++) {
		for (int c = 0; c < C; c++) {
			Cuartos[f][c]->setidentificacionHabitacion(n++);
			
		}
		
	}
	
}
string Hotel::inicializarEstado() {
	stringstream s;
	for (int f = 0; f < F; f++) {
		for (int c = 0; c < C; c++) {
			s << "[" << Cuartos[f][c]->getestado() << "]" << endl;
		}
		s << '\n';
	}
	return s.str();
}
Habitacion* Hotel::gethabitacion(int i, int j)
{
	return Cuartos[i][j];
}
string Hotel::opcion1_1()
{
	stringstream s;

	for (int i = 0; i <F; i++)
	{
		for (int j = 0; j < C; j++)
		{

			s << Cuartos[i][j]->getidentificacionHabitacion()
				<<"("<< Cuartos[i][j]->getestado() <<")"<<"   ";

		}
		s << endl;
	}


	return s.str();
}
string Hotel::opcion1_2(char id)
{
	stringstream s;
	for (int i = 0; i < F; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (id == Cuartos[i][j]->getestandarHabitacion()) {
				s << Cuartos[i][j]->getidentificacionHabitacion()
					<<"("<< Cuartos[i][j]->getestado()<<")"<<endl;
			}
		}
	}



	return s.str();
}
string Hotel::opcion1_3(int camas)
{
	stringstream s;
	for (int i = 0; i < F; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (camas == Cuartos[i][j]->getNumeroCamas()) {
				s << Cuartos[i][j]->getidentificacionHabitacion()
					<< "(" << Cuartos[i][j]->getestado() << ")" << endl;
			}
		}
	}
	return s.str();
}
Hotel::~Hotel() { 

	for (int i = 0; i < F; i++)
	{
		for (int j = 0; j < C; j++)
		{
			delete[] Cuartos[i][j];

		}
	}

	delete[] Cuartos;
}
void Hotel:: agregarHabitacion() {
		srand(time(NULL));
		for (int i = 0; i < F; i++) {
			for (int j = 0; j < C; j++) {
			
				Cuartos[i][j] = new Habitacion();
				Cuartos[i][j]->RandomBed();
				Cuartos[i][j]->RandomStandar();
			}
		}
	}
string Hotel::opcion2_0(int id) {
	stringstream s;
	
	for (int i = 0; i < F; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (id == Cuartos[i][j]->getidentificacionHabitacion()) {
				s<<Cuartos[i][j]->tostring();
			}
		}
	}
	return s.str();
}
Habitacion* Hotel::opcion3_0(int id)
{
	for ( int i = 0; i < F; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (id==Cuartos[i][j]->getidentificacionHabitacion()&& Cuartos[i][j]->getestado()=='L')
			{
				return Cuartos[i][j];
				break;
			}

		}
	}
	
}
string Hotel::opcion7_0(int id) {
	stringstream s;
	for (int i = 0; i < F; i++){
		for (int j = 0; j < C; j++){
			if(Cuartos[i][j]->getestado()=='L'){
				if (id == Cuartos[i][j]->getidentificacionHabitacion()) {
					s << "El estado actual de la habitacion es:" <<"("<< Cuartos[i][j]->getestado()<<")"<<endl;
					Cuartos[i][j]->setestado('M');
					s << "La habitacion se ha puesto en mantenimiento" << endl;
				}
			}
			else{
					s << "Habitacion ocupada en este momento" << endl;
			}
		}
	}
	return s.str();
}

string Hotel::opcion4_2(int id)
{
	stringstream s;

	for (int i = 0; i < F; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (id == Cuartos[i][j]->getidentificacionHabitacion()&&Cuartos[i][j]->getestado()!='L') {
				Cuartos[i][j]->anularCR();
				Cuartos[i][j]->setestado('L');

			}
		}
	}
	return s.str();
}

string Hotel::opcion5_complemento1(string id_cliente)
{

	stringstream s;
	
		for (int i = 0; i < F; i++)
		{
			for (int f = 0; f < C; f++)
			{
				if (Cuartos[i][f]->getcliente()->getidentificacion_Cliente() == id_cliente) {
					s << Cuartos[i][f]->getreservacion()->getnumreserv()<< endl;
				}
				else
				{
					s << "No se encontraron conicidencias" << endl;
					break;
				}
				
			}
		}
	return s.str();
}

string Hotel::opcion5_complemento2(int id_reserv){
	stringstream s;
	for (int i = 0; i < F; i++){
		for (int j = 0; j < C; j++){
			if (id_reserv = Cuartos[i][j]->getreservacion()->getnumreserv()) {
				s << "Detalle de reservacion" << endl;
				s << Cuartos[i][j]->tostring()
					<< Cuartos[i][j]->getreservacion()->tiquete();
			}
		}
	}
	return s.str();
}

string Hotel::opcion6()
{
	int ninnos=0, adultos=0;
	stringstream s;

	for (int i = 0; i < F; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (Cuartos[i][j]->getreservacion())
			{
				ninnos+=Cuartos[i][j]->getreservacion()->getnumNinnos();
				adultos+=Cuartos[i][j]->getreservacion()->getnumAdultos();

			}
			

		}
	}

	s << "los ninnos y adultos de todo el Hotel son:" << endl;
	s << "Cantidad de ninnos: " << ninnos << endl;
	s << "Cantidad de adultos: " << adultos << endl;

	return s.str();
}

string Hotel::opcion8()
{
	float Ti = 0, NTi = 0;
	stringstream s;
	for (int i = 0; i < F; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (Cuartos[i][j]->getreservacion()&& Cuartos[i][j]->getreservacion()->gettodoIncluido()==true)
			{
				if (Cuartos[i][j]->getestandarHabitacion()=='P')
				{
					Ti = Cuartos[i][j]->getreservacion()->calcularPreciosContodo()*1.30;
				}								
				if (Cuartos[i][j]->getestandarHabitacion()=='S')
				{
					Ti = Cuartos[i][j]->getreservacion()->calcularPreciosContodo()*1.20;
				}			
				if (Cuartos[i][j]->getestandarHabitacion() == 'T')
				{
					Ti = Cuartos[i][j]->getreservacion()->calcularPreciosContodo();

				}
			}
			else
			{
				if (Cuartos[i][j]->getreservacion()&& Cuartos[i][j]->getreservacion()->gettodoIncluido() == false)
				{
					if (Cuartos[i][j]->getestandarHabitacion()=='P')
				{
					Ti = Cuartos[i][j]->getreservacion()->calcularPreciosSintodo()*1.30;
				}								
				if (Cuartos[i][j]->getestandarHabitacion()=='S')
				{
					Ti = Cuartos[i][j]->getreservacion()->calcularPreciosSintodo()*1.20;
				}			
				if (Cuartos[i][j]->getestandarHabitacion() == 'T')
				{
					Ti = Cuartos[i][j]->getreservacion()->calcularPreciosSintodo();

				}
				}
			}
		}
	}

	s << "recaudacion del dia de hoy del hotel: " << endl;
	s << "Recaudacion con todo incluido:  $" << Ti << endl;
	s << "Recaudacion sin incluido:  $" << NTi << endl;
	return s.str();
}

string Hotel::stringdereservaciones(string x)
{
	stringstream s;
	for (int i = 0; i < F; i++){
		for(int j = 0; j < C; j++){
			if (x == Cuartos[i][j]->getcliente()->getidentificacion_Cliente()) {
				s << Cuartos[i][j]->getnumreservacion();
			}

		}
	}
	return s.str();
}

string Hotel::opcion4_1(int id)
{
	stringstream s;

	for (int i = 0; i < F; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (id == Cuartos[i][j]->getreservacion()->getnumreserv() && Cuartos[i][j]->getestado() != 'L') {
				Cuartos[i][j]->anularCR();
				Cuartos[i][j]->setestado('L');

			}
		}
	}


	return s.str();
}



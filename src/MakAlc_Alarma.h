#pragma once
#include <Arduino.h>

enum resolucion {
	SEGUNDOS,
	MILISEGUNDOS,
	MICROSEGUNDOS
};

enum estado : byte {
	Sin_definir,
	Preparado,
	Iniciado,
	Pausado,
	Finalizado
};

class MakAlc_Alarma
{
private:
	int _repeticiones = 1;
	int _cuentaRepeticiones = 1;
	resolucion _resolucion = MILISEGUNDOS;
	byte _estado = estado::Sin_definir;
	unsigned long _tiempo = 0;
	unsigned long _inicio = 0;
	bool _llamarFuncion = false;

	void actualizaEstado();
	void asignaInicio();
	void (*_funcion)();
	
public:
	~MakAlc_Alarma();
	
	MakAlc_Alarma();
	MakAlc_Alarma(unsigned long tiempo);
	MakAlc_Alarma(unsigned long tiempo, int repeticiones);
	MakAlc_Alarma(unsigned long tiempo, int repeticiones, resolucion intervalo);
	MakAlc_Alarma(unsigned long tiempo, void (*funcion)());
	MakAlc_Alarma(unsigned long tiempo, void (*funcion)(), int repeticiones);
	MakAlc_Alarma(unsigned long tiempo, void (*funcion)(), int repeticiones, resolucion intervalo);

	void Start();
	void Start(unsigned long tiempo);
	void Start(unsigned long tiempo, int repeticiones);
	void Start(unsigned long tiempo, int repeticiones, resolucion intervalo);
	void Start(unsigned long tiempo, void (*funcion)());
	void Start(unsigned long tiempo, void (*funcion)(), int repeticiones);
	void Start(unsigned long tiempo, void (*funcion)(), int repeticiones, resolucion intervalo);

	void Define(unsigned long tiempo);
	void Define(unsigned long tiempo, int repeticiones);
	void Define(unsigned long tiempo, int repeticiones, resolucion intervalo);
	void Define(unsigned long tiempo, void (*funcion)());
	void Define(unsigned long tiempo, void (*funcion)(), int repeticiones);
	void Define(unsigned long tiempo, void (*funcion)(), int repeticiones, resolucion intervalo);

	void ProximoEvento();	// Pendiente definir.
	void Finaliza();
	void Borra();
	void Pausa();
	bool Comprueba();
	int QuedanRepeticiones();
};


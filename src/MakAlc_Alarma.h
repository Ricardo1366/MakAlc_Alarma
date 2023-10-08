#pragma once
#include <Arduino.h>

enum resolucion
{
	SEGUNDOS,
	MILISEGUNDOS,
	MICROSEGUNDOS
};

enum estado : byte
{
	Sin_definir,
	Preparado,
	Iniciado,
	Pausado,
	Finalizado
};

// Crea "Alarmas" que se repiten cada "X" tiempo. Controla cuantas veces debe ejecutarse antes de desactivarse.
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

	// Controla si se ha llegado a la última repetición.
	void actualizaEstado();

	// Asigna el "tiempo" a partir del cual contamos.
	void asignaInicio();
	// Función a ejecutar.
	void (*_funcion)();

public:
	~MakAlc_Alarma();

	// Inicializa sin parámetros.
	// Es necesario configurarla antes de utilizarla.
	MakAlc_Alarma();

	// Inicializa la alarma para que devuelva 'True' una vez que pase el plazo establecido.
	// Parámetros:
	// tiempo -> Tiempo asignado a la alarma (obligatorio)
	// repeticiones -> Número de veces que se ejecuta antes de desactivarse (opcional)
	//    Por defecto 1. Cero o -1 indica que siempre está activa.
	// intervalo -> Unidad de medida del parámetro tiempo (opcional)
	//    Se pueden utilizar segundos, milisegundos (por defecto) o microsegundos.
	MakAlc_Alarma(unsigned long tiempo, int repeticiones = 1, resolucion intervalo = MILISEGUNDOS);

	// Inicializa la alarma para que ejecute una función una vez que pase el plazo establecido.
	// Parámetros:
	// tiempo -> Tiempo asignado a la alarma (obligatorio)
	// funcion -> Función a jecutar (obligatorio)
	//    La función tiene que ser de tipo "void" sin parámetros.
	// repeticiones -> Número de veces que se ejecuta antes de desactivarse (opcional)
	//    Por defecto 1. Cero o -1 indica que siempre está activa.
	// intervalo -> Unidad de medida del parámetro tiempo (opcional)
	//    Se pueden utilizar segundos, milisegundos (por defecto) o microsegundos.
	MakAlc_Alarma(unsigned long tiempo, void (*funcion)(), int repeticiones = 1, resolucion intervalo = MILISEGUNDOS);

	// Inicia una "Alarma".
	// El primer evento sucede al pasar el tiempo establecido.
	void Start();

	// Inicia la "Alarma" y lanza el primer evento.
	// Establece los intervalos al tiempo indicado manteniendo el resto
	// de parámetros tal como se definieron en "define"
	void Start(unsigned long tiempo);

	// Inicia la "Alarma" y lanza el primer evento.
	// Establece el tiempo y repeticiones indicadas manteniendo el resto
	// de parámetros tal como se definieron en "define"
	void Start(unsigned long tiempo, int repeticiones);

	// Inicia la "Alarma" y lanza el primer evento.
	void Start(unsigned long tiempo, int repeticiones = 1, resolucion intervalo = MILISEGUNDOS);

	// Inicia la "Alarma" y lanza el primer evento.
	void Start(unsigned long tiempo, void (*funcion)(), int repeticiones = 1, resolucion intervalo = MILISEGUNDOS);

	// Configura la alarma para que devuelva 'True' una vez que pase el plazo establecido.
	// Parámetros:
	// tiempo -> Tiempo asignado a la alarma (obligatorio)
	// repeticiones -> Número de veces que se ejecuta antes de desactivarse (opcional)
	//    Por defecto 1. Cero o -1 indica que siempre está activa.
	// intervalo -> Unidad de medida del parámetro tiempo (opcional)
	//    Se pueden utilizar segundos, milisegundos (por defecto) o microsegundos.
	void Define(unsigned long tiempo, int repeticiones = 1, resolucion intervalo = MILISEGUNDOS);

	// Configura la alarma para que ejecute una función una vez que pase el plazo establecido.
	// Parámetros:
	// tiempo -> Tiempo asignado a la alarma (obligatorio)
	// funcion -> Función a jecutar (obligatorio)
	//    La función tiene que ser de tipo "void" sin parámetros.
	// repeticiones -> Número de veces que se ejecuta antes de desactivarse (opcional)
	//    Por defecto 1. Cero o -1 indica que siempre está activa.
	// intervalo -> Unidad de medida del parámetro tiempo (opcional)
	//    Se pueden utilizar segundos, milisegundos (por defecto) o microsegundos.
	void Define(unsigned long tiempo, void (*funcion)(), int repeticiones = 1, resolucion intervalo = MILISEGUNDOS);

	// Devuelve cuanto tiempo queda para ejecutar el próximo evento.
	unsigned long ProximoEvento(); // Pendiente definir.

	// Marca una "Alarma" como finalizda.
	// Con Start() vuelve a ejecutarse de nuevo.
	void Finaliza();

	// Elimina la configuración de una alarma.
	// Es necesario volver a definirla para utilizarla de nuevo.
	// No puede borrarse la definición de una alarma activa. Primero hay que pararla o finalizarla.
	void Borra();

	// Si la "Alarma" está iniciada la pausa.
	// Con Start se vuelve a activar y continua.
	void Pausa();

	// Comprueba si se ha cumplido el plazo definido. Si es así devuelve true.
	// Si se ha informado nº de repeticiones la alarma se ejecutará tantas veces
	// como se haya indicado. Luego se desactiva.
	// Si se ha informado una función además de devolver true, ejecuta la función.
	bool Comprueba();

	// Devuelve el número de repeticiones pendientes de ejecutar;
	int QuedanRepeticiones();
};

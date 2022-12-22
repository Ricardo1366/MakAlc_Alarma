Libreria MarkAlc_Alarma
=======================
Arduino
-------
Para instalar esta librería en Arduino solo hay que descargar el fichero "ZIP" pulsando [AQUÍ](https://github.com/AsociacionMakerAlicante/MakAlc_Alarma/archive/refs/heads/master.zip). Una vez descargado se instala desde la opción de menú "Programa | Incluir librería | Añadir biblioteca ZIP"
![Instalar librería ZIP](https://github.com/AsociacionMakerAlicante/MakAlc_Alarma/raw/master/test/Instalar_Libreria_Zip.JPG)

PlaformIO
---------
Para trabajar con esta ibreria en PlatormIO solo tienes que incluir en el fichero platformio.ini el siguiente texto:
```text
lib_deps =
           https://github.com/AsociacionMakerAlicante/MakAlc_Alarma
```
Documentación
=============
MakAlc_alarma implementa la clase "MakAlc_Alarma" cuya funcionalidad principal es controlar si ha pasado el tiempo indicado. Devuelve "True" cuando se ha llegado o superado el tiempo indicado y puede opcionalmente llamar a la función que le hayamos indicado en su inicialización.

La declaración es la siguiente:
```cpp
Marklc_Alarma Nombre_Variable;
```
Los parámetros que admite son los siguientes:

___tiempo___ (unsigned long): Tiempo a cronometrar. El parámetro "resolución" indica si se ,mide en microsegundos, milisegundos (por defecto) o en segundos.

___repeticiones___ (int): Indica cuantas veces se debe repetir el proceso. Si se indica un número inferior a 1 se repite de forma indefinida.

___funcion___: Nombre de la función a ejecutar cuando se cumpla el tiempo establecido. Es un parámetro opcional, no es necesario informarlo.

___resolucion___: Unidad en la que se mide el primer parámetro (tiempo). Admite tres posibles valores, MICROSEGUNDOS, MILISEGUNDOS y SEGUNDOS.

FUNCIONES
---------
__define__: Informa los parámetros con los que se va a ejecutar. Si no se han informado parámetros al declarar la variable se informan con esta función.

__Borra__: Elimina la definición de la alarma. Es necesario volver a definir los parámetros antes de volver a ponerla en marcha.

__Comprueba__: Función encargada de comprobar si se ha cumplido el tiempo estipulado. Devuelve true cuando se ha alcanzado. Cuando alcanza el número de repeticiones informadas desactiva la alarma. Si se ha informado una función además de devolver true la ejecuta.

__Finaliza__: Da por finalizada una alarma sin esperar a que se cumpla el tiempo ni las repeticiones.

__Pausa__: Pone la alarma en modo "espera". Para volver a iniciarla hay que utilizar `Start()` sin parámetros. Si la alarma tiene informadas repeticiones empieza a contar desde la repetición en la que se indicó `Pausa()`

__ProximoEvento__: Devuelve el tiempo que falta para que la alarma se active. El valor devuelto está en la misma unidad que el parámetro "resolución" (MICROSEGUNDOS, MILISEGUNDOS, SEGUNDOS)

__QuedanRepeticiones__: Devuelve el número de veces que se ejecutará la alarma antes de darse por finalizada.

__Start__: Pone es marcha la cuenta atrás. Si se le pasa algún parámetro sobrescribe el valor informado con `define()`.

Si encuntras algún fallo en la ejecución de la libreria, por favor informa [AQUÍ](mailto:ricardomakeralicante@gmail.com)

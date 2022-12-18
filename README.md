Libreria MarkAlc_Alarma
=======================
Arduino
-------
Para instalar esta librería en Arduino solo hay que descargar el fichero "ZIP" pulsando [AQUÍ](https://github.com/AsociacionMakerAlicante/MakAlc_Alarma/archive/refs/heads/master.zip). Una vez descargado se instala desde la opción de menú "Programa | Incluir librería | Añadir biblioteca ZIP"
![Instalar librería ZIP](https://github.com/AsociacionMakerAlicante/MakAlc_Alarma/raw/master/test/Instalar_Libreria_Zip.JPG)

PlaformIO
---------
Para trabajar con esta ibreria en PlatormIO solo tienes que incluir en el fichero platformio.ini el siguiente teto:

lib_deps =
>https://github.com/AsociacionMakerAlicante/MakAlc_Alarma

Documentación
=============
MakAlc_alarma implementa la clase "MakAlc_Alarma" cuya funcionalidad principal es controlar si ha pasado el tiempo indicado. Devuelve "True" cuando se ha llegado o superado el tiempo indicado y puede opcionalmente llamar a la función que le hayamos indicado en su inicialización.

La declaración es la siguiente:

`Marklc_Alarma Nombre_Variable;`

Los parámetros que admite son los siguientes:

___tiempo___ (unsigned long): Tiempo a cronometrar. El parámetro "resolución" indica si se ,mide en microsegundos, milisegundos (por defecto) o en segundos.

___repeticiones___ (int): Indica cuantas veces se debe repetir el proceso. Si se indica un número inferior a 1 se repite de forma indefinida.

___fucion___: Nombre de la función a ejecutar cuando se cumpla el tiempo establecido. Es un parámetro opcional, no es necesario informarlo.

___resolucion___: Unidad en la que se mide el primer parámetro (tiempo). Admite tres posibles valores, MICROSEGUNDOS, MILISEGUNDOS y SEGUNDOS.

*(En construcción)*

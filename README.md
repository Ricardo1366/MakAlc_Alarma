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

`Marklc_Alarma Alarma;`

*(En construcción)*

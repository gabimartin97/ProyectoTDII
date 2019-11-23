# ProyectoTDII

PR0YECT0

Este proyecto consiste en integrar dichos ejercicios de la siguiente manera: \
a. Realice un programa a fin de que el usuario pueda seleccionar desde un menú, una de ocho secuencias de luces posibles. Cuatro de ellas serán comunes para todos los proyectos y son: "El auto fantástico", "El choque", "La apilada" y "La carrera". Las otras cuatros serán propias de cada grupo y se deberán implementar dos de ellas con algoritmo y las dos restantes por medio de la técnica de tablas de datos.\
a. Implemente el control de acceso a este menú mediante password.\
a. Cada vez que el usuario seleccione una secuencia el programa deberá cambiar la pantalla para indicar cual secuencia está ejecutándose y como hacer para salir de la misma. Al optar por abandonar la actual, el programa deberá regresar al menú principal inmediatamente sin completar la secuencia que se está desarrollando y apagando todas las luces.\\
a. Permita la posibilidad de controlar la velocidad de cada secuencia. Presionando la flecha hacia arriba se incrementará la velocidad y presionando la flecha hacia abajo se reducirá. Introduzca el sensado de las teclas oprimidas en el lugar apropiado de su programa a fin de percibir la reacción del sistema en forma inmediata, independiente de la velocidad actual. La velocidad ajustada en cada secuencia deberá conservarse entre llamadas a diferentes secuencias.\
a. El valor inicial correspondiente a la velocidad de las secuencias deberá ingresarse mediante la lectura del estado de los potenciómetros que están conectados a las entradas analógicas del conversor A/D.\
a. Generar una opción en el programa que permita establecer dos modos de trabajo: local y remoto. En modo local las secuencias de luces se ejecutarán en los leds que se encuentran en el hardware adicionado a la placa Raspberry donde se ejecuta el programa. En modo remoto las secuencias se ejecutarán sobre el hardware adicional colocado en otra Raspberry y conectada a la que ejecuta el programa mediante un cable serie RS-232. Se podrá usar el mismo programa para implementar esta opción en las dos Raspberry o realizar uno principal y otro secundario.\
a. Como opción genere una sección destinada a establecer las velocidades iniciales de las secuencias realizando el ajuste de los potenciómetros.\

\ **ESTADO DEL PROYECTO (20/11/19):TODO JOYA FALTA PULIR Y 1 SECUENCIA


o	8 FUNCIONES DE LAS SECUENCIAS DE LUCES\
Auto fantástico - La carrera - El choque - La apilada -¿?-¿?-¿?-¿?\
o	MENU COMPLETO CON CONTRASEÑA\

o	VARIABLES DE VELOCIDAD PARA CADA SECUENCIA\
El valor inicial del ADC +- Offset\
¿Cómo leer instantáneamente el teclado sin que lo afecte el delay?\

o	MODO DE TRABAJO REMOTO\
Comunicar 2 raspberry con RS232. Hacer programa secundario que solo lea serie y ejecute secuencia de luces\

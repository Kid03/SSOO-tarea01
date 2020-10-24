# SSOO-tarea01
Tarea para ramo de SIstemas Operativos, UV

##Pertenece a
  Hector Delgado
  hector.delgado@alumnos.uv.cl
  

## Funcionamiento del programa
El programa consta de 2 funciones principales, main y sig_handler, en main se prepara para recibir las señales con signal dando que señales va a tomar y que función las manejara, luego se queda en un ciclo infinito con un sleep, para permitir que reciba la señal.
En sig_handler, reconoce 2 señales, SIGUSR1 y SIGINT, para la primera señal, esta tomando la hora y la imprime en el formato pedido, mientras que con SIGINT, hay una variable global, para ayudar a mantener registro de la cantidad de veces que se presiono “^C”, cuando cumple la segunda vez, se llama a la función exit para cerrar las instancias.

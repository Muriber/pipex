# pipex
Este proyecto trata de simular el funcionamiento del comando *pipe* "**|**". Para ello se parte de una estructura de llamada como la siguiente:

~~~
./pipex archivo1 comando1 comando2 archivo2
~~~

Este proyecto pretende aplicar el uso de *procesos* junto con la instrucción *pipe* en **C**, con el objeto de replicar el funcionamiento de la instrucción **pipe**. Para ello se utilizan funciones como:
~~~
dup()
execve()
fork()
pipe()
wait()
waitpid()
~~~


/*-----------------------------------------------------------------
**
**  Fichero:
**    init.asm  10/6/2014
**
**    Fundamentos de Computadores
**    Dpto. de Arquitectura de Computadores y Autom�tica
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Arranca un programa en C
**
**  Notas de dise�o:
**
**---------------------------------------------------------------*/

    .extern main
    .extern _stack
	.global start

start:
    ldr sp,=_stack
    mov fp,#0
    
    bl main

End:
    B End

	.end


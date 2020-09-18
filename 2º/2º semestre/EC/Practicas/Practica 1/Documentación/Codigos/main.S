.extern main
.global start

.equ USRSTACK, 0xc7ff000

.text
start:
	ldr sp, =USRSTACK
    mov fp, #0
    bl main

End:
    B End
.end

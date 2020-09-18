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

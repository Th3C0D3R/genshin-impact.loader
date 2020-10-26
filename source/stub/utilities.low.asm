PUBLIC get_module   

_DATA SEGMENT
 
_DATA ENDS
 
 
_TEXT SEGMENT

get_module PROC
    xor rax, rax
    mov rax, gs:[60h]
    mov rax, [rax + 18h]
    mov rax, [rax + 10h]
    mov rax, [rax]
    ret
get_module ENDP

_TEXT ENDS
 
END
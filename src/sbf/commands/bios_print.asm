bits 16
org 0x7C00

_start:
    mov si, word [esp + 4]
    call print_string
	call exit

uefi_print:
    lodsb
    or al, al
    jz done
    out dx, al
    inc rdi
    cmp rdi, rsi
    jl print_string
    out dx, al
    jmp print_string


bios_print:
    lodsb
    or al, al
    jz done
    int 0x10
    jmp print_string
done:
    ret

bios_exit:
	int 0x18

uefi_exit:
	mov al, 0x4c    ; CPU halt
    out dx, al
    cli
    hlt
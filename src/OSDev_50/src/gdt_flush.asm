; src/gdt_flush.asm
; Loads GDT and reloads segment registers

BITS 32
global gdt_flush

gdt_flush:
    mov eax, [esp+4]      ; pointer to gdt_ptr struct
    lgdt [eax]

    ; Reload segment registers with DATA selector = 0x10
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    ; Far jump to reload CS with CODE selector = 0x08
    jmp 0x08:.flush_cs
.flush_cs:
    ret

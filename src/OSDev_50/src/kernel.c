#include <libc/stdint.h>
#include "gdt.h"
#include "terminal.h"

void main(uint32_t mb_magic, uint32_t mb_info_addr)
{
    (void)mb_magic;
    (void)mb_info_addr;

    gdt_init();

    terminal_initialize();
    terminal_write("Hello World\n");

    for (;;) {
        __asm__ volatile ("hlt");
    }
}

#include <libc/stdint.h>
#include "gdt.h"
#include "terminal.h"

void main(uint32_t multiboot_magic, uint32_t multiboot_info_addr)
{
    (void)multiboot_magic;
    (void)multiboot_info_addr;

    gdt_init();

    terminal_initialize();
    terminal_write("Hello World\n");

    for (;;) {
        __asm__ volatile ("hlt");
    }
}

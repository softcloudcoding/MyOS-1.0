// pc_speaker.c
#include <stdint.h>

void play_sound(uint32_t frequency) {
    uint32_t divisor = 1193180 / frequency;

    outb(0x43, 0xB6); // Command byte
    outb(0x42, (uint8_t)(divisor & 0xFF));      // Low byte
    outb(0x42, (uint8_t)((divisor >> 8) & 0xFF)); // High byte

    uint8_t tmp = inb(0x61);
    if (tmp != (tmp | 3)) {
        outb(0x61, tmp | 3);  // Enable speaker
    }
}

void stop_sound() {
    uint8_t tmp = inb(0x61) & 0xFC;
    outb(0x61, tmp);
}

void beep_sequence() {
    play_sound(440); // A
    delay(250);
    stop_sound();

    play_sound(494); // B
    delay(250);
    stop_sound();

    play_sound(523); // C
    delay(500);
    stop_sound();
}

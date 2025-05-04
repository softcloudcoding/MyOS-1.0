void write_dummy_file() {
    char* disk = (char*)0x100000;  // Fake disk area in RAM or mapped image
    const char* msg = "Installed!";
    for (int i = 0; msg[i] != '\0'; i++) {
        disk[i] = msg[i];
    }
}

void kernel_main() {
    char* video = (char*) 0xb8000;
    const char* msg = "Welcome to MyOS Setup. Press any key to install...";
    for (int i = 0; msg[i] != '\0'; i++) {
        video[i * 2] = msg[i];
        video[i * 2 + 1] = 0x07;
    }

    // Wait for keypress (via BIOS)
    while ((inb(0x64) & 1) == 0);
    inb(0x60); // Read key

    write_dummy_file();

    const char* done = "Installation Complete! Reboot now.";
    for (int i = 0; done[i] != '\0'; i++) {
        video[(i + 40) * 2] = done[i];
        video[(i + 40) * 2 + 1] = 0x0A;
    }

    while (1);
}

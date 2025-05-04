// kernel.c
void main() {
    char* video = (char*) 0xb8000;
    *video = 'X';  // Display an X on screen
}

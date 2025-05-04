void kernel_main() {
    display_welcome_message();
    beep_sequence();        // Play intro tune
    wait_for_key();
    run_installer();
    show_complete_message();
    play_sound(880);        // End tone
}

#include "interruptFunctions.h"

void command_butt_edge (unsigned char address) {
    unsigned edge       = !!(address & 0x10);
    address             &= 0x0f;

    setButtonEdgeINT    (address, edge);
}

void command_butt_mode (unsigned char address) {
    unsigned mode       = !!(address & 0x10);
    address             &= 0x0f;

    setButtonModeINT    (address, mode);
}

void command_reset     (void) {
    resetButtons();
    resetREs();
}

void setButtonEdgeINT (unsigned char address, Edge_t edge) {
    Button_t* button;

    switch (address) {
        case 1: // All sequencer buttons
            button = &UIinfo.Butt_1 + BUTT_SEQ_1;
            button->edge = edge;

            button = &UIinfo.Butt_1 + BUTT_SEQ_2;
            button->edge = edge;

            button = &UIinfo.Butt_1 + BUTT_SEQ_3;
            button->edge = edge;

            button = &UIinfo.Butt_1 + BUTT_SEQ_4;
            button->edge = edge;

            button = &UIinfo.Butt_1 + BUTT_SEQ_5;
            button->edge = edge;

            button = &UIinfo.Butt_1 + BUTT_SEQ_6;
            button->edge = edge;

            button = &UIinfo.Butt_1 + BUTT_SEQ_7;
            button->edge = edge;

            button = &UIinfo.Butt_1 + BUTT_SEQ_8;
            button->edge = edge;

            button = &UIinfo.Butt_1 + BUTT_SEQ_9;
            button->edge = edge;

            button = &UIinfo.Butt_1 + BUTT_SEQ_10;
            button->edge = edge;

            button = &UIinfo.Butt_1 + BUTT_SEQ_11;
            button->edge = edge;

            button = &UIinfo.Butt_1 + BUTT_SEQ_12;
            button->edge = edge;

            button = &UIinfo.Butt_1 + BUTT_SEQ_13;
            button->edge = edge;

            button = &UIinfo.Butt_1 + BUTT_SEQ_14;
            button->edge = edge;

            button = &UIinfo.Butt_1 + BUTT_SEQ_15;
            button->edge = edge;

            button = &UIinfo.Butt_1 + BUTT_SEQ_16;
            button->edge = edge;
            break;

        case 2: // All drum buttons
            button = &UIinfo.Butt_1 + BUTT_DRUM_1;
            button->edge = edge;

            button = &UIinfo.Butt_1 + BUTT_DRUM_2;
            button->edge = edge;

            button = &UIinfo.Butt_1 + BUTT_DRUM_3;
            button->edge = edge;

            button = &UIinfo.Butt_1 + BUTT_DRUM_4;
            button->edge = edge;

            button = &UIinfo.Butt_1 + BUTT_DRUM_5;
            button->edge = edge;

            button = &UIinfo.Butt_1 + BUTT_DRUM_6;
            button->edge = edge;
            break;

        case 3: // Play button
            button = &UIinfo.Butt_1 + BUTT_PLAY;
            button->edge = edge;
            break;

        case 4: // Clear button
            button = &UIinfo.Butt_1 + BUTT_CLEAR;
            button->edge = edge;
            break;

        case 5: // FX button
            button = &UIinfo.Butt_1 + BUTT_FX;
            button->edge = edge;
            break;

        case 6: // Pattern Length
            button = &UIinfo.Butt_1 + BUTT_PATT_LEN;
            button->edge = edge;
            break;

        case 7: // Pattern Select
            button = &UIinfo.Butt_1 + BUTT_PATT_SEL;
            button->edge = edge;
            break;

        case 8: // Shift
            button = &UIinfo.Butt_1 + BUTT_SHIFT;
            button->edge = edge;
            break;

        case 9: // Menu 1
            button = &UIinfo.Butt_1 + BUTT_MENU_1;
            button->edge = edge;
            break;

        case 10: // Menu 2
            button = &UIinfo.Butt_1 + BUTT_MENU_2;
            button->edge = edge;
            break;

        case 11: // Extra 1
            button = &UIinfo.Butt_1 + BUTT_EXTRA_1;
            button->edge = edge;
            break;

        case 12: // Extra 2
            button = &UIinfo.Butt_1 + BUTT_EXTRA_2;
            button->edge = edge;
            break;
    }
}

void setButtonModeINT (unsigned char address, ButtonMode_t mode) {
    Button_t* button;

    switch (address) {
        case 1: // All sequencer buttons
            button = &UIinfo.Butt_1 + BUTT_SEQ_1;
            button->mode = mode;

            button = &UIinfo.Butt_1 + BUTT_SEQ_2;
            button->mode = mode;

            button = &UIinfo.Butt_1 + BUTT_SEQ_3;
            button->mode = mode;

            button = &UIinfo.Butt_1 + BUTT_SEQ_4;
            button->mode = mode;

            button = &UIinfo.Butt_1 + BUTT_SEQ_5;
            button->mode = mode;

            button = &UIinfo.Butt_1 + BUTT_SEQ_6;
            button->mode = mode;

            button = &UIinfo.Butt_1 + BUTT_SEQ_7;
            button->mode = mode;

            button = &UIinfo.Butt_1 + BUTT_SEQ_8;
            button->mode = mode;

            button = &UIinfo.Butt_1 + BUTT_SEQ_9;
            button->mode = mode;

            button = &UIinfo.Butt_1 + BUTT_SEQ_10;
            button->mode = mode;

            button = &UIinfo.Butt_1 + BUTT_SEQ_11;
            button->mode = mode;

            button = &UIinfo.Butt_1 + BUTT_SEQ_12;
            button->mode = mode;

            button = &UIinfo.Butt_1 + BUTT_SEQ_13;
            button->mode = mode;

            button = &UIinfo.Butt_1 + BUTT_SEQ_14;
            button->mode = mode;

            button = &UIinfo.Butt_1 + BUTT_SEQ_15;
            button->mode = mode;

            button = &UIinfo.Butt_1 + BUTT_SEQ_16;
            button->mode = mode;
            break;

        case 2: // All drum buttons
            button = &UIinfo.Butt_1 + BUTT_DRUM_1;
            button->mode = mode;

            button = &UIinfo.Butt_1 + BUTT_DRUM_2;
            button->mode = mode;

            button = &UIinfo.Butt_1 + BUTT_DRUM_3;
            button->mode = mode;

            button = &UIinfo.Butt_1 + BUTT_DRUM_4;
            button->mode = mode;

            button = &UIinfo.Butt_1 + BUTT_DRUM_5;
            button->mode = mode;

            button = &UIinfo.Butt_1 + BUTT_DRUM_6;
            button->mode = mode;
            break;

        case 3: // Play button
            button = &UIinfo.Butt_1 + BUTT_PLAY;
            button->mode = mode;
            break;

        case 4: // Clear button
            button = &UIinfo.Butt_1 + BUTT_CLEAR;
            button->mode = mode;
            break;

        case 5: // FX button
            button = &UIinfo.Butt_1 + BUTT_FX;
            button->mode = mode;
            break;

        case 6: // Pattern Length
            button = &UIinfo.Butt_1 + BUTT_PATT_LEN;
            button->mode = mode;
            break;

        case 7: // Pattern Select
            button = &UIinfo.Butt_1 + BUTT_PATT_SEL;
            button->mode = mode;
            break;

        case 8: // Shift
            button = &UIinfo.Butt_1 + BUTT_SHIFT;
            button->mode = mode;
            break;

        case 9: // Menu 1
            button = &UIinfo.Butt_1 + BUTT_MENU_1;
            button->mode = mode;
            break;

        case 10: // Menu 2
            button = &UIinfo.Butt_1 + BUTT_MENU_2;
            button->mode = mode;
            break;

        case 11: // Extra 1
            button = &UIinfo.Butt_1 + BUTT_EXTRA_1;
            button->mode = mode;
            break;

        case 12: // Extra 2
            button = &UIinfo.Butt_1 + BUTT_EXTRA_2;
            button->mode = mode;
            break;
    }
}
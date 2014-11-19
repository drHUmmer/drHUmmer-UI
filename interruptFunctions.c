#include "interruptFunctions.h"

void command_butt_get  (unsigned char address) {
    if (address == 0x00) { // Send all registers
        clearInterruptData();
        InterruptData.data1     = getButtonRegValue(1, 1);
        InterruptData.data2     = getButtonRegValue(2, 1);
        InterruptData.data3     = getButtonRegValue(3, 1);
        InterruptData.data4     = getButtonRegValue(4, 1);
    }
    else { // Specific register
        clearInterruptData();
        InterruptData.data1     = getButtonRegValue(address, 1);
    }
}

void command_re_get    (unsigned char address) {
    if (address == 0x00) { // Send all registers
        clearInterruptData();
        InterruptData.data1     = getREvalue(1, 1);
        InterruptData.data2     = getREvalue(2, 1);
        InterruptData.data3     = getREvalue(3, 1);
        InterruptData.data4     = getREvalue(4, 1);
        InterruptData.data5     = getREvalue(5, 1);
        InterruptData.data6     = getREvalue(6, 1);
        InterruptData.data7     = getREvalue(7, 1);
        InterruptData.data8     = getREvalue(8, 1);
        InterruptData.data9     = getREvalue(9, 1);
        InterruptData.data10    = getREvalue(10, 1);
        InterruptData.data11    = getREvalue(11, 1);
    }
    else { // Specific register
        clearInterruptData();
        InterruptData.data1     = getREvalue(address, 1);
    }
}

void command_butt_edge (unsigned char address) {
    unsigned edge       = !!(address & 0x10);
    address             &= (address - 1);

    setButtonEdgeINT    (address, edge);
}

void command_butt_mode (unsigned char address) {
    unsigned mode       = !!(address & 0x10);
    address             &= (address - 1);

    setButtonModeINT    (address, mode);
}

void command_reset     (void) {
    resetButtons();
    resetREs();
}

void command_re_update (void) {
    unsigned char work, counter;
    
    UARTsend(0xA5);
    clearInterruptData();

    work = 0x00;
    work |= (!!(getREvalue(1, 0)) << 0);
    work |= (!!(getREvalue(2, 0)) << 1);
    work |= (!!(getREvalue(3, 0)) << 2);
    work |= (!!(getREvalue(4, 0)) << 3);
    work |= (!!(getREvalue(5, 0)) << 4);
    work |= (!!(getREvalue(6, 0)) << 5);
    work |= (!!(getREvalue(7, 0)) << 6);
    work |= (!!(getREvalue(8, 0)) << 7);

    InterruptData.data1 = work;

    work = 0x00;
    work |= (!!(getREvalue(9, 0)) << 0);
    work |= (!!(getREvalue(10, 0)) << 1);
    work |= (!!(getREvalue(11, 0)) << 2);

    InterruptData.data2 = work;

    char* intData       = &InterruptData.data3;

    // Send the registers with a value (not zero)
    for (counter = 1; counter <= NR_OF_ROTARYENC; counter ++) {
        char REvalue = getREvalue(counter, 1);
        if (REvalue) {
            *intData = REvalue;
            intData ++;
        }
    }
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


void clearInterruptData(void) {
    InterruptData.data1     = DUMMY_DATA;
    InterruptData.data2     = DUMMY_DATA;
    InterruptData.data3     = DUMMY_DATA;
    InterruptData.data4     = DUMMY_DATA;
    InterruptData.data5     = DUMMY_DATA;
    InterruptData.data6     = DUMMY_DATA;
    InterruptData.data7     = DUMMY_DATA;
    InterruptData.data8     = DUMMY_DATA;
    InterruptData.data9     = DUMMY_DATA;
    InterruptData.data10    = DUMMY_DATA;
    InterruptData.data11    = DUMMY_DATA;
    InterruptData.data12    = DUMMY_DATA;
    InterruptData.data13    = DUMMY_DATA;
}

void shiftInterruptData(void) {
    InterruptData.data1     = InterruptData.data2;
    InterruptData.data2     = InterruptData.data3;
    InterruptData.data3     = InterruptData.data4;
    InterruptData.data4     = InterruptData.data5;
    InterruptData.data5     = InterruptData.data6;
    InterruptData.data6     = InterruptData.data7;
    InterruptData.data7     = InterruptData.data8;
    InterruptData.data8     = InterruptData.data9;
    InterruptData.data9     = InterruptData.data10;
    InterruptData.data10    = InterruptData.data11;
    InterruptData.data11    = InterruptData.data12;
    InterruptData.data12    = InterruptData.data13;
    InterruptData.data13    = DUMMY_DATA;
}


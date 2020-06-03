#include <stdio.h>
#include <string.h>
#include <wiringPi.h>

#define FBDEVFILE "/dev/fb2"

#define BTN7	24	// #97
#define BTN8	23	// #108
#define BTN9	27	// #98
#define BTN4	22	// #100
#define BTN5	21	// #101
#define BTN6	26	// #99	
#define BTN1	7	// #83
#define BTN2	6	// #103
#define BTN3	11	// #118


#define BTNDEL	1
#define BTNLft	4
#define BTNRgt	5


void initialize_textlcd() {
    pinMode(BTN7, INPUT);
    pinMode(BTN8, INPUT);
    pinMode(BTN9, INPUT);
    pinMode(BTN4, INPUT);
    pinMode(BTN5, INPUT);
    pinMode(BTN6, INPUT);
    pinMode(BTN1, INPUT);
    pinMode(BTN2, INPUT);
    pinMode(BTN3, INPUT);
    pinMode(BTNDEL, INPUT);
    pinMode(BTNLft, INPUT);
    pinMode(BTNRgt, INPUT);
 
    pullUpDnControl(BTN7, PUD_DOWN);
    pullUpDnControl(BTN8, PUD_DOWN);
    pullUpDnControl(BTN9, PUD_DOWN);
    pullUpDnControl(BTN4, PUD_DOWN);
    pullUpDnControl(BTN5, PUD_DOWN);
    pullUpDnControl(BTN6, PUD_DOWN);
    pullUpDnControl(BTN1, PUD_DOWN);
    pullUpDnControl(BTN2, PUD_DOWN);
    pullUpDnControl(BTN3, PUD_DOWN);
    pullUpDnControl(BTNDEL, PUD_UP);
    pullUpDnControl(BTNLft, PUD_UP);
    pullUpDnControl(BTNRgt, PUD_UP);

    delay(2);
}
int main()
{
    wiringPiSetup();

    initialize_textlcd();
    int state = 0;

    for (;;) {
        if (digitalRead(BTN1) ||
            digitalRead(BTN2) ||
            digitalRead(BTN3) ||
            digitalRead(BTN4) ||
            digitalRead(BTN5) ||
            digitalRead(BTN6) ||
            digitalRead(BTN7) ||
            digitalRead(BTN8) ||
            digitalRead(BTN9) ||
            !digitalRead(BTNDEL) ||
            !digitalRead(BTNLft) ||
            !digitalRead(BTNRgt)) {
            if (state == 0) {
                printf("i'm clicked!\n");
                delay(10);
                state = 1;
            }
        }
        else if (digitalRead(BTN1) == 0 &&
            digitalRead(BTN2) == 0 &&
            digitalRead(BTN3) == 0 &&
            digitalRead(BTN4) == 0 &&
            digitalRead(BTN5) == 0 &&
            digitalRead(BTN6) == 0 &&
            digitalRead(BTN7) == 0 &&
            digitalRead(BTN8) == 0 &&
            digitalRead(BTN9) == 0 &&
            !digitalRead(BTNDEL) == 0 &&
            !digitalRead(BTNLft) == 0 &&
            !digitalRead(BTNRgt) == 0) {
            if (state == 1) {
                printf("reset state\n");
                delay(10);
                state = 0;
            }
        }
    }

	return 0;
}


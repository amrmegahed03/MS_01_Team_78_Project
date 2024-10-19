#include <stdio.h>
#include "pico/stdlib.h"

// Define pins for LEDs
#define RED_LED_PIN     0  // Red LED connected to GP0
#define GREEN_LED_PIN   1  // Green LED connected to GP1
#define BLUE_LED_PIN    2  // Blue LED connected to GP2 (Negative logic)

void initLEDs(void) {
    // Initialize the GPIO pins for Red, Green, and Blue LEDs
    gpio_init(RED_LED_PIN);
    gpio_init(GREEN_LED_PIN);
    gpio_init(BLUE_LED_PIN);

    // Set the direction of the pins to output
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);
    gpio_set_dir(BLUE_LED_PIN, GPIO_OUT);

    // Turn off all LEDs initially
    gpio_put(RED_LED_PIN, 0);  // Red LED off
    gpio_put(GREEN_LED_PIN, 0);  // Green LED off
    gpio_put(BLUE_LED_PIN, 1);   // Blue LED off (negative logic)
}

// Turn ON the Red LED (Positive Logic)
void turnOnRedLED(void) {
    gpio_put(RED_LED_PIN, 1);  // Set GP0 HIGH to turn on Red LED
}

// Turn OFF the Red LED (Positive Logic)
void turnOffRedLED(void) {
    gpio_put(RED_LED_PIN, 0);  // Set GP0 LOW to turn off Red LED
}

// Turn ON the Green LED (Positive Logic)
void turnOnGreenLED(void) {
    gpio_put(GREEN_LED_PIN, 1);  // Set GP1 HIGH to turn on Green LED
}

// Turn OFF the Green LED (Positive Logic)
void turnOffGreenLED(void) {
    gpio_put(GREEN_LED_PIN, 0);  // Set GP1 LOW to turn off Green LED
}

// Turn ON the Blue LED (Negative Logic)
void turnOnBlueLED(void) {
    gpio_put(BLUE_LED_PIN, 0);  // Set GP2 LOW to turn on Blue LED (Negative logic)
}

// Turn OFF the Blue LED (Negative Logic)
void turnOffBlueLED(void) {
    gpio_put(BLUE_LED_PIN, 1);   // Set GP2 HIGH to turn off Blue LED (Negative logic)
}

// Turn ON all LEDs
void turnOnAllLEDs(void) {
    turnOnRedLED();
    turnOnGreenLED();
    turnOnBlueLED();
}

// Turn OFF all LEDs
void turnOffAllLEDs(void) {
    turnOffRedLED();
    turnOffGreenLED();
    turnOffBlueLED();
}

int main() {
    // Initialize the stdio library and the LEDs
    stdio_init_all();
    initLEDs();

    // Initial delay with all LEDs off for 5 seconds
    sleep_ms(5000);

    // Continuous cycle loop
    while (1) {
        // Step 1: Turn on Red LED for 1 second, then off
        turnOnRedLED();
        sleep_ms(1000);
        turnOffRedLED();

        // Step 2: Turn on Green LED for 1 second, then off
        turnOnGreenLED();
        sleep_ms(1000);
        turnOffGreenLED();

        // Step 3: Turn on Blue LED for 1 second, then off
        turnOnBlueLED();
        sleep_ms(1000);
        turnOffBlueLED();

        // Step 4: Turn on all LEDs for 2 seconds, then off
        turnOnAllLEDs();
        sleep_ms(2000);
        turnOffAllLEDs();
    }

    return 0;
}

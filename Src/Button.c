#include "Button.h"
#include "menu.h"
#include "stm32l1xx_hal.h"


void delay_ms(uint16_t czas) {
    uint32_t i;
    for (i = 0; i < (czas * 1000); ++i) {
        asm("NOP");
    }
}

void delay_us(uint8_t czas) {
    uint32_t i;
    for (i = 0; i < (czas); ++i) {
        asm("NOP");
    }
}

void key_next_press(void) {
    static uint8_t key_next_lock = 0;

    if (!key_next_lock && (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10) == GPIO_PIN_SET)) {
        key_next_lock = 1;
        delay_ms(50); // Opcjonalne opóźnienie anty-drgańcowe
        menu_next();
    } else if (key_next_lock && HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10) == GPIO_PIN_RESET) {
        key_next_lock = 0; // Reset the lock
        delay_ms(50); // Opcjonalne opóźnienie anty-drgańcowe
    }
}
void key_prev_press(void) {
    static uint8_t key_prev_lock = 0;

    if (!key_prev_lock && (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8) == GPIO_PIN_SET)) {
        key_prev_lock = 1;
        delay_ms(50); // Opcjonalne opóźnienie anty-drgańcowe
        menu_prev();
    } else if (key_prev_lock && HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8) == GPIO_PIN_RESET) {
        key_prev_lock = 0; // Reset the lock
        delay_ms(50); // Opcjonalne opóźnienie anty-drgańcowe
    }
}

void key_enter_press(void) {
    static uint8_t key_enter_lock = 0;

    if (!key_enter_lock && (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5) == GPIO_PIN_SET)) {
        key_enter_lock = 1;
        delay_ms(50); // Opcjonalne opóźnienie anty-drgańcowe
        menu_enter();
    } else if (key_enter_lock && HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5) == GPIO_PIN_RESET) {
        key_enter_lock = 0; // Reset the lock
        delay_ms(50); // Opcjonalne opóźnienie anty-drgańcowe
    }
}

void key_back_press(void) {
    static uint8_t key_back_lock = 0;

    if (!key_back_lock && (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) == GPIO_PIN_SET)) {
        key_back_lock = 1;
        delay_ms(50); // Opcjonalne opóźnienie anty-drgańcowe
        menu_back();
    } else if (key_back_lock && HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) == GPIO_PIN_RESET) {
        key_back_lock = 0; // Reset the lock
        delay_ms(50); // Opcjonalne opóźnienie anty-drgańcowe
    }
}

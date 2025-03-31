#include "global_vars.h"

TFT_eSPI tft = TFT_eSPI();

// Queue for sending commands from controller to main game loop
QueueHandle_t controller_queue;

// Queue for sending which sound should be played
QueueHandle_t sound_queue;

// Semaphore for coordinates on display
SemaphoreHandle_t disp_sem;


#ifndef GLOBAL_VARS
#define GLOBAL_VARS

#include <stdio.h>
#include <inttypes.h>
#include <vector>

#include "sdkconfig.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"
#include "driver/gpio.h"
#include "driver/ledc.h"

#include "macros.h"
#include "TFT_eSPI.h"

#include "gameObjects/DrawableObject.h"
#include "gameObjects/Textbox.h"


extern TFT_eSPI tft;

// Queue for sending commands from controller to main game loop
extern QueueHandle_t controller_queue;

// Queue for sending which sound should be played
extern QueueHandle_t sound_queue;

// Semaphore for coordinates on display
extern SemaphoreHandle_t disp_sem;


// game objects


#endif


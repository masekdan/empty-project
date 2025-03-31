#include "game_loop.h"

static void game_over()
{
    tft.fillRect(0, 0, DISP_WIDTH, DISP_HEIGHT, TFT_BLACK);
    Textbox *gm = new Textbox(TFT_RED, 5, tft);
    gm->draw(70, 100, "GAME OVER!");
    delete gm;
    Textbox *msg = new Textbox(TFT_RED, 1, tft);
    msg->draw(70, 170, "If you want to play again, please restart the game console.");
    delete msg;
}

static void end_game()
{
    tft.fillRect(0, 0, DISP_WIDTH, DISP_HEIGHT, TFT_BLACK);
    Textbox *gm = new Textbox(TFT_YELLOW, 5, tft);
    gm->draw(70, 100, "YOU WON!");
    delete gm;
    Textbox *msg = new Textbox(TFT_YELLOW, 1, tft);
    msg->draw(70, 170, "If you want to play again, please restart the game console.");
    delete msg;
}

static void play_sound(int sound)
{
    xQueueSend(sound_queue, &sound, portMAX_DELAY);
}

// Main game loop
void task_game_loop(void *t_args)
{
    int btnMsg;

    while (1)
    {

        xSemaphoreTake(disp_sem, portMAX_DELAY);
        if (xQueueReceive(controller_queue, &btnMsg, pdMS_TO_TICKS(10)))
        {

            switch (btnMsg)
            {
            case A:
                break;

            case B:
                break;

            case UP:
                break;

            case DOWN:
                break;

            case LEFT:
                break;

            case RIGHT:
                break;

            default:
                break;
            }
        }


        xSemaphoreGive(disp_sem);
        vTaskDelay(10);
    }

    vTaskDelete(NULL);
}

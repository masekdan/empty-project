#include "game_utils.h"

std::vector<int> go_ost = {TONE_H,TONE_DELAY,TONE_F,TONE_DELAY,TONE_G,TONE_DELAY,TONE_E};
std::vector<int> w_ost = {2,3,10,4,6,10,4,6};

/// @brief Sends message to speaker task
/// @param sound predefined sound
void play_sound(int sound)
{
    xQueueSend(sound_queue,&sound,portMAX_DELAY);
}

/// @brief Game over screen if player loses
void game_over()
{
    tft.fillRect(0,0,DISP_WIDTH,DISP_HEIGHT,TFT_BLACK);
    Textbox* gm = new Textbox(TFT_RED,5,tft);
    gm->draw(70,100,"GAME OVER!");
    delete gm;

    Textbox* msg = new Textbox(TFT_RED,1,tft);
    msg->draw(70,170,"If you want to play again, please restart the game console.");
    delete msg;

    for (int x : go_ost)
    {
        play_sound(x);
    }
}

/// @brief Game over screen if player wins
void end_game()
{
    tft.fillRect(0,0,DISP_WIDTH,DISP_HEIGHT,TFT_BLACK);
    Textbox* gm = new Textbox(TFT_YELLOW,5,tft);
    gm->draw(70,100,"YOU WON!");
    delete gm;
    Textbox* msg = new Textbox(TFT_YELLOW,1,tft);
    msg->draw(70,170,"If you want to play again, please restart the game console.");
    delete msg;

    for (int x : w_ost)
    {
        play_sound(x);
    }
}


/// @brief Detects collision between drawable objects
/// @param do1 First object
/// @param do2 Second object
/// @return Returns 0 if there is a collision otherwise 1
int detect_collision(DrawableObject *&do1, DrawableObject *&do2)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = do1->getX();
    rightA = do1->getX() + do1->getWidth();
    topA = do1->getY();
    bottomA = do1->getY() + do1->getHeight();

    leftB = do2->getX();
    rightB = do2->getX() + do2->getWidth();
    topB = do2->getY();
    bottomB = do2->getY() + do2->getHeight();

    if (bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB)
    {
        return 1;
    }
    return 0;
}

/// @brief Function that pauses the game
void pause_game()
{
    int msg = -1;
    play_sound(TONE_D);
    play_sound(TONE_C);
    play_sound(TONE_D);
    play_sound(TONE_C);
    while (msg!=PRESS_B)
    {
        xQueueReceive(controller_queue, &msg, pdMS_TO_TICKS(10));
    }
    play_sound(TONE_D);
    play_sound(TONE_C);
    play_sound(TONE_D);
    play_sound(TONE_C); 
    return;
}
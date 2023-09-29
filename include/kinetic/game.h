#ifndef KINETIC_GAME_H
#define KINETIC_GAME_H

void game_setup();
void game_cleanup();

void game_loop();

typedef enum key {
    KEY_ESCAPE,
    KEY_A,
    KEY_D,
    KEY_S,
    KEY_W,
    KEY_SPACE,
} key;

void game_input_callback(key key);

void exit_game();

#endif//KINETIC_GAME_H

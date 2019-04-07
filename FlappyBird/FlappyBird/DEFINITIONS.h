#pragma once
// Okno
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024
// Menu Glowne
#define MAIN_MENU_BG_FILEPATH "Resources/res/sky.png"
#define TITLE_FILEPATH "Resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "Resources/res/play.png"
// Okno Gry
#define GAME_BG_FILEPATH "Resources/res/sky.png"
// Okno Koniec Gry
#define GAME_OVER_BG_FILEPATH "Resources/res/sky.png"
#define GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define GAME_OVER_FRAME_FILEPATH "Resources/res/Game-Over-Body.png"
// Rury
#define PIPE_UP_FILEPATH "Resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "Resources/res/PipeDown.png"
#define SCORING_PIPE_FILEPATH "Resources/res/InvisibleScoringPipe.png" // System punktow

#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_INTERVAL 1.5f
// Ziemia
#define GROUND_FILEPATH "Resources/res/Land.png"
// Ptak
#define BIRD_ANIMATION_DURATION 0.4f
#define BIRD_FRAME_1_FILEPATH "Resources/res/bird-01.png"
#define BIRD_FRAME_2_FILEPATH "Resources/res/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "Resources/res/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "Resources/res/bird-04.png"

// Stany ptaka
#define BIRD_STATE_STILL 1 // W miejscu
#define BIRD_STATE_FALLING 2 // Spadanie
#define BIRD_STATE_FLYING 3 // Wznoszenie, po wcisnieciu LPM

#define GRAVITY 350.0f
#define FLYING_SPEED 350.0f
#define FLYING_DURATION 0.25f // Okresla, jak dlugo trwa lot (wznoszenie w gore po wcisnieciu LPM)

#define ROTATION_SPEED 100.0f

// Czcionka
#define FONT_FILEPATH "Resources/fonts/FlappyFont.ttf"

// Typ wyliczeniowy - stany gry
enum GameStates {
	Playing,
	GameOver
};

#define TIME_BEFORE_GAME_OVER 1.0f
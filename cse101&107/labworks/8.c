#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // for sleep()

#define MAX_ENEMIES 20
#define MAX_BULLETS 30
#define MAX_SHOTS_ALLOWED 75
#define PLAYER_WIDTH 5
#define PLAYER_HEIGHT 3

typedef struct {
    int x; 
    int y; 
    int active; 
} enemy;

typedef struct { 
    int x; 
    int y; 
    int active; 
} bullet;

typedef struct { 
    int x; 
    int y; 
    int lives; 
} player;

typedef struct { 
    int max_y; 
    int max_x; 
} screen;

typedef struct { 
    int score; 
    int frame; // loop count
    int total_shots_fired; 
    int game_over_flag; 
    int won_flag; 
    int enemy_direction; 
    float bullet_speed;
} gamestate;

void initialize_game(screen scr, enemy enemies[]);
void handle_input(player *plyr, screen scr, gamestate *game, bullet bullets[]);
void update_elements(screen scr, enemy enemies[], gamestate *game, player *plyr);
void update_bullets(screen scr, bullet bullets[], enemy enemies[], gamestate *game);
void update_enemy_bullets(screen scr, bullet enemy_bullets[], player *plyr, gamestate *game);
void draw_elements(screen scr, player *plyr, enemy enemies[], bullet bullets[], bullet enemy_bullets[], gamestate *game);

int main()
{
    initscr();
    cbreak(); // no enter to read input
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);

    screen scr;
    getmaxyx(stdscr, scr.max_y, scr.max_x);

    clear();
    mvprintw(scr.max_y / 2 - 2, scr.max_x / 2 - 8, "SPACE INVADERS");
    mvprintw(scr.max_y / 2, scr.max_x / 2 - 20, "CONTROLS: A=Left | D=Right | SPACE=Shoot | Q=Quit");
    mvprintw(scr.max_y / 2 + 3, scr.max_x / 2 - 8, "Press SPACE to Start");
    refresh();

    while (getch() != ' ');
    napms(500);

    player plyr = {scr.max_x / 2, scr.max_y - PLAYER_HEIGHT, 3};
    gamestate game = {0, 0, 0, 0, 0, 1, 1};

    enemy enemies[MAX_ENEMIES];
    bullet bullets[MAX_BULLETS];
    bullet enemy_bullets[MAX_ENEMIES];

    initialize_game(scr, enemies);
    for (int i = 0; i < MAX_BULLETS; i++) 
        bullets[i].active = 0;
    for (int i = 0; i < MAX_ENEMIES; i++) 
        enemy_bullets[i].active = 0;

    int enemy_move_frame_rate = 3;
    while (!game.game_over_flag)
    {
        handle_input(&plyr, scr, &game, bullets);
        update_bullets(scr, bullets, enemies, &game);
        update_enemy_bullets(scr, enemy_bullets, &plyr, &game);
        if (game.frame % enemy_move_frame_rate == 0)
            update_elements(scr, enemies, &game, &plyr);
        if (game.frame % 30 == 0)
        {
            for (int i = 0; i < MAX_ENEMIES; i++)
            {
                if (enemies[i].active && !enemy_bullets[i].active)
                {
                    if (rand() % 8 == 0)
                    {
                        enemy_bullets[i].x = enemies[i].x;
                        enemy_bullets[i].y = enemies[i].y + 1;
                        enemy_bullets[i].active = 1;
                    }
                }
            }
        }
        if (plyr.lives <= 0)
            game.game_over_flag = 1;
        int all_dead = 1;
        for (int i = 0; i < MAX_ENEMIES; i++)
        {
            if (enemies[i].active)
            {
                all_dead = 0;
                break;
            }
        }
        if (all_dead && game.score > 0)
        {
            game.game_over_flag = 1;
            game.won_flag = 1;
        }
        draw_elements(scr, &plyr, enemies, bullets, enemy_bullets, &game);
        if (game.total_shots_fired >= MAX_SHOTS_ALLOWED && !game.won_flag)
            game.game_over_flag = 1;
        game.frame++;
        napms(80);
    }
    clear();
    if (game.won_flag)
    {
        mvprintw(scr.max_y / 2 - 1, scr.max_x / 2 - 8, "*** YOU WON! ***");
        mvprintw(scr.max_y / 2, scr.max_x / 2 - 10, "FINAL SCORE: %d", game.score);
    } 
    else if (game.total_shots_fired >= MAX_SHOTS_ALLOWED)
    {
        mvprintw(scr.max_y / 2 - 1, scr.max_x / 2 - 15, "GAME OVER! BULLET LIMIT REACHED!");
        mvprintw(scr.max_y / 2, scr.max_x / 2 - 10, "FINAL SCORE: %d", game.score);
    } 
    else
    {
        mvprintw(scr.max_y / 2 - 1, scr.max_x / 2 - 10, "GAME OVER! NO CHANCE LEFT!");
        mvprintw(scr.max_y / 2, scr.max_x / 2 - 5, "FINAL SCORE: %d", game.score);
    }
    refresh();
    sleep(3);
    endwin();
    return 0;
}

void initialize_game(screen scr, enemy enemies[])
{
    srand(time(NULL));
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        enemies[i].x = 5 + (i % 5) * 5;
        enemies[i].y = 3 + (i / 5) * 3;
        enemies[i].active = 1;
    }
}

void handle_input(player *plyr, screen scr, gamestate *game, bullet bullets[])
{
    int ch;
    while ((ch = getch()) != ERR)
    {
        if (ch == 'a' && plyr->x > 2) 
            plyr->x--;
        else if (ch == 'd' && plyr->x < scr.max_x - (PLAYER_WIDTH - 1))
            plyr->x++;
        else if (ch == ' ' && game->total_shots_fired < MAX_SHOTS_ALLOWED)
        {
            for (int i = 0; i < MAX_BULLETS; i++)
            {
                if (!bullets[i].active)
                {
                    bullets[i].x = plyr->x;
                    bullets[i].y = plyr->y - PLAYER_HEIGHT;
                    bullets[i].active = 1;
                    game->total_shots_fired++;
                    break;
                }
            }
        }
        else if (ch == 'm' && game->total_shots_fired + 4 <= MAX_SHOTS_ALLOWED)
        {
            game->bullet_speed = game->bullet_speed + 0.4;
            int bullets_fired = 0;
            for (int i = 0; i < MAX_BULLETS && bullets_fired < 4; i++)
            {
                if (!bullets[i].active)
                {
                    bullets[i].x = plyr->x + bullets_fired;
                    bullets[i].y = plyr->y - PLAYER_HEIGHT;
                    bullets[i].active = 1;
                    game->total_shots_fired++;
                    bullets_fired++;
                }
            }
        }
        else if (ch == 'q')
            game->game_over_flag = 1;
    }
}

void update_bullets(screen scr, bullet bullets[], enemy enemies[], gamestate *game)
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        if (bullets[i].active)
        {
            bullets[i].y -= game->bullet_speed;
            for (int j = 0; j < MAX_ENEMIES; j++)
            {
                if (enemies[j].active && bullets[i].y == enemies[j].y && bullets[i].x == enemies[j].x)
                {
                    bullets[i].active = 0;
                    enemies[j].active = 0;
                    game->score += 10;
                    break;
                }
            }
            if (bullets[i].y <= 1)
                bullets[i].active = 0;
        }
    }
}

void update_enemy_bullets(screen scr, bullet enemy_bullets[], player *plyr, gamestate *game)
{
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (enemy_bullets[i].active)
        {
            enemy_bullets[i].y++;
            if (enemy_bullets[i].x >= plyr->x - 2 && enemy_bullets[i].x <= plyr->x + 2 && enemy_bullets[i].y >= plyr->y - (PLAYER_HEIGHT - 1) && enemy_bullets[i].y <= plyr->y)
            {
                enemy_bullets[i].active = 0;
                plyr->lives--;
            }
            if (enemy_bullets[i].y >= scr.max_y - 1)
                enemy_bullets[i].active = 0;
        }
    }
}

void update_elements(screen scr, enemy enemies[], gamestate *game, player *plyr)
{
    int hit_edge = 0;
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (enemies[i].active)
        {
            enemies[i].x += game->enemy_direction;
            if (enemies[i].x <= 2 || enemies[i].x >= scr.max_x - 3)
                hit_edge = 1;
        }
    }
    if (hit_edge)
        game->enemy_direction *= -1;
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (enemies[i].active && enemies[i].x >= plyr->x - 2 && enemies[i].x <= plyr->x + 2 && enemies[i].y >= plyr->y - (PLAYER_HEIGHT - 1) && enemies[i].y <= plyr->y)
        {
            plyr->lives--;
            enemies[i].active = 0;
        }
    }
}

void draw_elements(screen scr, player *plyr, enemy enemies[], bullet bullets[], bullet enemy_bullets[], gamestate *game)
{
    clear();
    for (int x = 0; x < scr.max_x; x++)
    {
        mvaddch(0, x, '-');
        mvaddch(scr.max_y - 1, x, '-');
    }
    for (int y = 0; y < scr.max_y; y++)
    {
        mvaddch(y, 0, '|');
        mvaddch(y, scr.max_x - 1, '|');
    }
    mvprintw(plyr->y - 2, plyr->x - 2, "/\\_/\\");
    mvprintw(plyr->y - 1, plyr->x - 2, "(o o)");
    mvprintw(plyr->y, plyr->x - 2, "> ^ <");
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (enemies[i].active)
            mvaddch(enemies[i].y, enemies[i].x, 'M');
    }
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        if (bullets[i].active && bullets[i].y >= 1 && bullets[i].y < scr.max_y - 1)
            mvaddch(bullets[i].y, bullets[i].x, '|');
    }
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (enemy_bullets[i].active && enemy_bullets[i].y >= 1 && enemy_bullets[i].y < scr.max_y - 1)
            mvaddch(enemy_bullets[i].y, enemy_bullets[i].x, '*');
    }
    int enemy_count = 0;
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (enemies[i].active)
            enemy_count++;
    }
    mvprintw(1, 2, "SCORE: %d | CHANCE: %d | SHOTS: %d/%d | ENEMY: %d", 
             game->score, plyr->lives, game->total_shots_fired, MAX_SHOTS_ALLOWED, enemy_count);
    refresh();
}
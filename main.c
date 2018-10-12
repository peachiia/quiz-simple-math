// Simple Math Game for MWIT's Student Project
// Dev: Pongsakorn Wechakarn
// Env: TDM-GCC 4.92. (MinGW64)

#include <stdio.h>
#include <stdbool.h>

void clear_screen();
char wait_key();
void print_header();
int  print_menu();
void print_game_not_founded();

void print_game_header(int game_id);
void print_game_hp_bar();
bool render_game_content();
bool render_game_content();



bool is_game_founded(int index);

#define GAME_AVAILABLED_MAX 2

void main()
{
    int game_id = 0;
    print_header();
    game_id = print_menu();
    if (is_game_founded(game_id)) {
        while (1) {

        }
    }
    else {
        print_game_not_founded();
        wait_key();
    }
}

void clear_screen()
{
    system("cls");
}

char wait_key()
{
    return getch();
}

void print_header()
{
    printf("    Simple Game\n");
    printf("-------------------\n\n");
}

int print_menu()
{
    printf("Game List\n");
    printf("   1: Fibo Guess\n");
    printf("   2: Easy Math\n");
    printf("\n");
    printf("Select: ");
    int index = wait_key() - '0';
    printf("%d\n", index);
    return index;
}

void print_game_not_founded()
{
     printf("\nERROR: Selected game is NOT available.\nPlease any key to EXIT.\n");
}

bool is_game_founded(int index)
{
    return (index >0 && index <= GAME_AVAILABLED_MAX);
}
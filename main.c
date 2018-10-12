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
bool is_game_founded(int index);

void print_dashline();
void print_game_header(int game_id);
void print_game_retry_bar();
void print_game_fault_bar();
bool is_retry_flaged();

void render_game_content();
void render_game_fibo();
void render_game_easymath();

#define GAME_ID_MAX 2
enum GAME_ID{
    gid_fibo = 1,
    gid_easymath = 2
};

#define FAULT_MAX 5
int retry_counter = 0;
int fault_counter = 0;

void main()
{
    int game_id = 0;
    print_header();
    game_id = print_menu();
    if (is_game_founded(game_id)) {
        int fault_counter = 0;
        while (1) {
            clear_screen();
           print_game_header(game_id); 
           print_game_retry_bar();
           print_game_fault_bar();
           print_dashline();
           render_game_content(game_id);
        }
    }
    else {
        print_game_not_founded();
        wait_key();
    }
}

void print_game_header(int game_id)
{
    print_dashline();
    switch (game_id) {
        case gid_fibo: {
            printf("    FIBONACCI CALCULATION\n"); 
            break;           
        } 
        case gid_easymath: {
            printf("    EASY MATH\n");
            break;         
        } 
        default: printf("    Unknown Game!\n");
    }
    print_dashline();
}

void print_dashline()
{
    printf("-----------------------------\n");
}

void render_game_fibo()
{
    printf("FIBO. %d", fault_counter++);
    wait_key();
    if (is_retry_flaged()) {

    }
}

void render_game_easymath()
{
    printf("MATH. %d", fault_counter++);
    wait_key();
    if (is_retry_flaged()) {

    }
}

bool is_retry_flaged()
{
    if (fault_counter >= FAULT_MAX) {
        fault_counter = 0;
        retry_counter++;
        return true;
    }
    return false;
}

void print_game_retry_bar()
{
    printf(" Retry: %d\n", retry_counter);
}

void print_game_fault_bar()
{
    int i;
    printf(" Fault: ");
    for (i = 1; i <= FAULT_MAX; i++) {
        if (i <= fault_counter) {
            printf("X ");
        }
        else {
            printf("_ ");
        }
    }
    printf("\n");
}

void render_game_content(int game_id)
{
    switch (game_id) {
        case gid_fibo: {
            render_game_fibo();       
            break;   
        } 
        case gid_easymath: {
            render_game_easymath();    
            break;    
        } 
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
    return (index >0 && index <= GAME_ID_MAX);
}
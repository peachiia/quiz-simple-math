// Simple Math Game for MWIT Student's Project
// Dev: Peachiia
// Env: TDM-GCC 4.92. (MinGW64)

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

void init_game_content(int game_id);
void render_game_content();

void init_game_fibo();
void render_game_fibo();
void update_fibAnswer();
bool check_fibAnswer();
void update_next_fib();
bool print_fibText(char fibText[], int fibLen);

void init_game_easymath();
void render_game_easymath();

#define GAME_ID_MAX 2
enum GAME_ID{
    gid_fibo = 1,
    gid_easymath = 2
};

#define GAME_FIBO_LENGTH_MAX 100
char fibA[GAME_FIBO_LENGTH_MAX];
char fibB[GAME_FIBO_LENGTH_MAX];
char fibAnswer[GAME_FIBO_LENGTH_MAX];
char fibInput[GAME_FIBO_LENGTH_MAX];
int fibA_len, fibB_len, fibAnswer_len;
int fibOrder = 0;

#define FAULT_MAX 5
int retry_counter = 0;
int fault_counter = 0;

/*
void main()
{
    init_game_fibo();
    while(1) {
        render_game_fibo();
    }
}
*/

void main()
{
    int game_id = 0;
    print_header();
    game_id = print_menu();
    if (is_game_founded(game_id)) {
        fault_counter = 0;
        init_game_content(game_id);
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

void init_game_fibo()
{
    fibOrder = 3;
    fibA[0] = '1';
    fibB[0] = '1';
    fibA_len = 1;
    fibB_len = 1;
    
    update_fibAnswer();
}

void update_fibAnswer()
{
    int i = 0, buffer = 0;
    fibAnswer_len = 0;
    for (i = 0; i < fibB_len; i++) {
        if (i < fibA_len) {
            buffer += (fibA[i]-'0') + (fibB[i]-'0');
        }
        else {
            buffer += (fibB[i]-'0');
        }
        fibAnswer[i] = (buffer % 10) + '0';
        buffer /= 10;
        fibAnswer_len++;
    }
    if (buffer > 0) {
        fibAnswer[fibAnswer_len] = buffer + '0';
        fibAnswer_len++;
    }
}

bool check_fibAnswer()
{
    int i;
    if (strlen(fibInput) == fibAnswer_len) {
        for (i = 0; i < fibAnswer_len; i++) {
            if (fibAnswer[i] != fibInput[(fibAnswer_len-1)-i]) {
                break;
            }
        }
        if ( i == fibAnswer_len) {
            return true;
        }
    }
    return false;
}

void update_next_fib()
{
    memcpy(fibA, fibB, sizeof(char) * fibB_len);
    fibA_len = fibB_len;
    memcpy(fibB, fibAnswer, sizeof(char) * fibAnswer_len);
    fibB_len = fibAnswer_len;
    update_fibAnswer();
    fibOrder++;
}

bool print_fibText(char fibText[], int fibLen) 
{
    int i;
    for (i = fibLen-1; i >= 0; i--) {
        printf("%c", fibText[i]);
    }
}

void render_game_fibo()
{
    printf("%5d: ", fibOrder-2);
    print_fibText(fibA, fibA_len);

    printf("\n%5d: ", fibOrder-1);
    print_fibText(fibB, fibB_len);
    
    //printf("\n Actual Answer: ");
    //print_fibText(fibAnswer, fibAnswer_len);

    printf("\n Answer: ");
    scanf("%s", &fibInput);
    if (check_fibAnswer()) {
        update_next_fib();
    }
    else {
        printf("\a");
        fault_counter++;
    }
    if (is_retry_flaged()) {
        init_game_fibo();
    }
}

void init_game_easymath()
{

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

void init_game_content(int game_id)
{
    switch (game_id) {
        case gid_fibo: {
            init_game_fibo();       
            break;   
        } 
        case gid_easymath: {
            init_game_easymath();    
            break;    
        } 
    }
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
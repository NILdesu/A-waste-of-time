#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_INPUT_LEN 10

int main() {
    time_t t;
    int num_picks = 0, break_chance = 0, money = 500, money_gained;
    int exit_received = 0;
    char user_input[MAX_INPUT_LEN];

    /* Initialize random number generator */
    srand((unsigned) time(&t));

    /* Loop until the exit command is received */
    while(!exit_received) {
        /* Take user input */
        printf("> ");
        scanf("%s", user_input);

        /**
          * mine command
          * Requires the user to have at least one pickaxe in their inventory
          * Gives a random amount of money from 30 to 150
          * A pickaxe has an increased chance to break with each use, from 0 to a max of 50 percent
          * Should a pickaxe break, the break chance will reset back to 0
        */
        if(!strcmp(user_input, "mine")) {
            if(num_picks == 0) {
                printf("You have no pickaxes, buy one first\n");
            }

            else {
                if(rand() % 100 < break_chance) {
                    printf("Your pick broke\n");
                    num_picks--;
                    break_chance = 0;
                }
                else {
                    money_gained = 30 + (rand() % 120);
                    money += money_gained;
                    printf("You mined minerals worth %d moneys\n", money_gained);
                    break_chance = break_chance == 50 ? 50 : break_chance + 10;
                }
            }
        }

        /**
          * buy command
          * Requires the user to have at least 75 money
          * Adds a pickaxe to the inventory
        */
        else if(!strcmp(user_input, "buy")) {
            if(money < 75) {
                printf("You can't afford a pickaxe\n");
            }
            else {
                money -= 75;
                printf("You bought a pickaxe for 75 moneys.  You now have %d pickaxe(s) and %d moneys\n", ++num_picks, money);
            }
        }

        /**
          * balance command
          * Displays amount of money user currently has
        */
        else if(!strcmp(user_input, "balance")) {
            printf("You have %d moneys\n", money);
        }

        /**
          * inventory command
          * Displays amount of pickaxes user currently has
        */
        else if(!strcmp(user_input, "inventory")) {
            printf("You have %d pickaxe(s)\n", num_picks);
        }

        /**
          * exit command
          * Exits program
        */
        else if(!strcmp(user_input, "exit")) {
            exit_received = 1;
        }

        else {
            printf("Unrecognized command\n");
        }
    }
    return 0;
}// end main

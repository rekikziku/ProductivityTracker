#include <stdio.h>

int main (int argc, const char **argv){
        int goal;
        int c;
        int total_productive;
        int p, n;

        //reading files
        FILE *fp_productive = fopen("productive.txt", "r");
        FILE *fp_non_productive = fopen("non_productive.txt", "r");
        FILE *fp_neutral = fopen("neutral.txt", "r");

        //usage and input values from .txt files.
        if (argc != 4){
                printf("Usage: %s <total productive> <total non productive> <total neutral>\n", argv[0]);
                return 1;
        }else if (argc == 4){
                printf("Your productivity goal is: ");
                while((c = fgetc(fp_productive)) != EOF){
                       putchar (c);
                }
                printf("Your non productivity goal is: ");
                while((c = fgetc(fp_non_productive)) != EOF){
                       putchar (c);
                }
                printf("Your neutral goal is: ");
                while((c = fgetc(fp_neutral)) != EOF){
                       putchar (c);
                }
        }
        //calculating your productivity level.
        while (fscanf(fp_productive, "%i", &p) == 1) {
                while (fscanf(fp_non_productive, "%i", &n) == 1){
                        printf("%i - %i\n", p , n);
                }
        }

        //if files do not exist, return this:
        if (fp_productive == NULL) {
                printf("Could not open productive.txt\n");
                return 1;
        }
        if (fp_non_productive == NULL) {
                printf("Could not open non_productive.txt\n");
                return 2;
        }
        if (fp_neutral == NULL) {
                printf("Could not open neutral.txt\n");
                return 2;
        }

        //calculate total and goal
        total_productive = argv[1] - argv[2];
        goal = fscanf(fp_productive, "%i", &p) - fscanf(fp_non_productive, "%i", &n);

        //check and return if you have reached your goal.
        if (goal < total_productive){
                printf("You've exceeded your goal for this week.\n");
        }else if (goal == total_productive){
                printf("You have met your goal for the week.\n");
        }else if (goal > total_productive){
                printf("You were not as productive as you anticipated to be.\n");
        }
        fclose(fp_non_productive);
        fclose(fp_productive);
        fclose(fp_neutral);
}

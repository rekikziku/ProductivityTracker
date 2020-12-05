#include "struct.h"

struct productivity calculate_productivity(const int array[], size_t size){
        struct productivity product;

        while (fscanf(fp_productive, "%i", &p) == 1) {
                while (fscanf(fp_non_productive, "%i", &n) == 1){
                        printf("%i - %i\n", p , n);
                }
        }
        fclose(fp_non_productive);
        fclose(fp_productive);
        fclose(fp_neutral);
        return 0;

}

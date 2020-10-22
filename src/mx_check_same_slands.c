#include "pathfinder.h"

bool mx_check_same_islands(char *str, int j) {
    char *sub = NULL;
    int sub_amt = 0;

    sub = mx_strndup(str, j);
    sub_amt = mx_count_substr(str, sub);
    mx_strdel(&sub);

    if (sub_amt != 1) {
        return FALSE;
    }
    
    return TRUE;
}

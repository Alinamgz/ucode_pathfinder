#pragma once

// ======= defines =======
#define BUF_SIZE 32
#define DELIM '\n'
// --- error msgs ---
#define USAGE_ERR "usage: ./pathfinder [filename]\n"
#define FILE_ERR "error: file "
#define LINE_ERR "error: line "
#define EMPTY " is empty\n"
#define INVALID " is not valid\n"
#define NONEXISTENT " does not exist\n"
#define ISLANDS_AMT_ERR "error: invalid number of islands\n"
#define BRIDGES_AMT_ERR "error: duplicate bridges\n"
#define BRIDGES_LNG_ERR "error: sum of bridges lengths is too big\n"

// --- result output ---
#define BOUNDARY "========================================\n"
#define PATH "Path: "
#define ROUTE "Route: "
#define DISTANCE "Distance: "
#define ARROW " -> "
#define PLUSS " + "
#define EQUALS " = "
#define NEWLINE "\n"

// ======= includes =======
#include <libmx.h>

// ======= structs =======
typedef struct s_validation {
    int i;
    int j;
    int lines;
    int amt;
    long dist_tot;
    char *file_str;
    char **file_strarr;
    char **islands;
    char **buf_isl;
    char **buf_dist;
}              t_validation;

// ======= funcs =======

int mx_check_line_part(t_validation *v, char delim, bool (*f)(int));

void mx_validation(int arc, char *file_path, t_validation *v);
void mx_validate_file(int arc, char *file_path);
void mx_validate_lines(t_validation *v);
void mx_validate_isl_amt(t_validation *v);
void mx_line_error(int line_num, char ***arr);
void mx_err_exit(char **file, char ***file_arr);

char ***mx_split_arr(char **file_arr);

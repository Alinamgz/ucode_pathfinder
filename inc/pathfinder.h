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

// ======= funcs =======
void mx_file_validation(char *file_name);
void mx_lines_val(char **arr);

void mx_err_exit(char **file, char ***file_arr);

char ***mx_split_arr(char **file_arr);

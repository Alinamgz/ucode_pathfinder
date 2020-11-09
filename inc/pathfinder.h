#pragma once

// ======= defines =======
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
    unsigned total_dist;
    char *file_str;
    char **file_strarr;
    char **unique_islands;
    char **islands;
    char **distances;
    char **buf_a;
    char **buf_b;
}              t_validation;

typedef struct s_matrix {
    unsigned **adj_m;
    int amt;
    int from;
    int to;
}               t_matrix;

// ======= funcs =======

void mx_init_validation(t_validation *v);
void mx_validation(int arc, char *file_path, t_validation *v);
void mx_validate_file(int arc, char *file_path);
void mx_validate_lines(t_validation *v);
void mx_validate_islands(t_validation *v);
void mx_validate_bridges(t_validation *v);

void mx_adjacency_matrix(t_validation *v, t_matrix *m);
void mx_fw_algorithm(t_matrix *m);

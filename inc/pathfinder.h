#pragma once

// ======= defines =======
// --- error msgs ---
#define USAGE_ERR "usage: ./pathfinder [filename]\n"
#define FILE_ERR "error: file "
#define NONEXISTENT " does not exist\n"
#define EMPTY " is empty\n"
#define FIRST_LINE_ERR "error: line 1 is not valid\n"
#define LINE_ERR "error: line "
#define INVALID " is not valid\n"
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
bool mx_validation(char **arr);

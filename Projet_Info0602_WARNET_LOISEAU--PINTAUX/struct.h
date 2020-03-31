#ifndef STRUCT_H
#define STRUCT_H

#include <stdlib.h>
#include <stdio.h>
#include <json-c/json.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/*
#define HAUT     0
#define DROITE   1
#define BAS      2
#define GAUCHE   3*/
#define VIDE     0
#define CAISSE   1
#define OBSTACLE 2
#define BILLE    3
#define TROU     4

typedef struct {
    int x;
    int y;
    int type;
} case_t;

#endif
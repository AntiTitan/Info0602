#ifndef PROCEDURES_H
#define PROCEDURES_H

#include "struct.h"

int  avance(robot_t robot, case_t** grille);
int  recule(robot_t robot, case_t** grille);
void droite(robot_t robot);
void gauche(robot_t robot);
int  pose(robot_t robot, case_t** grille);
int  prend(robot_t robot, case_t** grille);
int  contenu(int x, robot_t robot, case_t** grille);

#endif
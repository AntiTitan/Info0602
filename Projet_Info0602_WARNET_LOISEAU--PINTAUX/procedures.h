#ifndef PROCEDURES_H
#define PROCEDURES_H

#include "struct.h"

void avance(robot_t robot, case_t** grille);
void recule(robot_t robot, case_t** grille);
void droite(robot_t robot);
void gauche(robot_t robot);
void pose(robot_t robot, case_t** grille);
void prend(robot_t robot, case_t** grille);
int contenu(int x, robot_t robot, case_t** grille);

#endif
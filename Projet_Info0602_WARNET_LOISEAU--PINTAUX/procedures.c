#include "struct.h"

void avance(robot_t robot, case_t** grille) {
    int x, y;
    /*cas differents selon la direction du robot*/
    if (robot.dir == HAUT) {
        x = robot.x - 1;
        y = robot.y;
        if (grille[x][y].type == VIDE) {
            robot.x = x;
        }
    }
    else if (robot.dir == DROITE) {
        x = robot.x;
        y = robot.y + 1;
        if (grille[x][y].type == VIDE) {
            robot.y = y;
        }
    }
    else if (robot.dir == BAS) {
        x = robot.x + 1;
        y = robot.y;
        if (grille[x][y].type == VIDE) {
            robot.x = x;
        }
    }
    else if (robot.dir == GAUCHE) {
        x = robot.x;
        y = robot.y - 1;
        if (grille[x][y].type == VIDE) {
            robot.y = y;
        }
    }
}

void recule(robot_t robot, case_t** grille) {
    int x, y;
    /*cas differents selon la direction du robot*/
    if (robot.dir == HAUT) {
        x = robot.x + 1;
        y = robot.y;
        if (grille[x][y].type == VIDE) {
            robot.x = x;
        }
    }
    else if (robot.dir == DROITE) {
        x = robot.x;
        y = robot.y - 1;
        if (grille[x][y].type == VIDE) {
            robot.y = y;
        }
    }
    else if (robot.dir == BAS) {
        x = robot.x - 1;
        y = robot.y;
        if (grille[x][y].type == VIDE) {
            robot.x = x;
        }
    }
    else if (robot.dir == GAUCHE) {
        x = robot.x;
        y = robot.y + 1;
        if (grille[x][y].type == VIDE) {
            robot.y = y;
        }
    }
}

void droite(robot_t robot) {
    /*cas differents selon la direction du robot*/
    if (robot.dir == HAUT) {
        robot.dir = DROITE;
    }
    else if (robot.dir == DROITE) {
        robot.dir = BAS;
    }
    else if (robot.dir == BAS) {
        robot.dir = GAUCHE;
    }
    else if (robot.dir == GAUCHE) {
        robot.dir = HAUT;
    }
}

void gauche(robot_t robot) {
    /*cas differents selon la direction du robot*/
    if (robot.dir == HAUT) {
        robot.dir = GAUCHE;
    }
    else if (robot.dir == DROITE) {
        robot.dir = HAUT;
    }
    else if (robot.dir == BAS) {
        robot.dir = DROITE;
    }
    else if (robot.dir == GAUCHE) {
        robot.dir = BAS;
    }
}

void pose(robot_t robot, case_t** grille) {
    /*cas differents selon la direction du robot*/

}

void prend(robot_t robot, case_t** grille) {
    /*cas differents selon la direction du robot*/

}

/* si on nomme la fonction case erreur a cause de 'switch case'*/
int contenu(int dir, robot_t robot, case_t** grille) {
    int type, x, y;
    x = robot.x;
    y = robot.y;

    if (dir == HAUT) {
        x--;
        type = grille[x][y].type;
    }
    else if (dir == DROITE) {
        y++;
        type = grille[x][y].type;
    }
    else if (dir == BAS) {
        x++;
        type = grille[x][y].type;
    }
    else if (dir == GAUCHE) {
        y--;
        type = grille[x][y].type;
    }
    return type;
}
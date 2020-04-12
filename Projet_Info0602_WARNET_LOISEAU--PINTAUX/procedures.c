#include "struct.h"

int avance(robot_t robot, case_t** grille) {
    int x, y;
    /*cas differents selon la direction du robot*/
    if (robot.dir == GAUCHE) {
        x = robot.x - 1;
        y = robot.y;
        if (grille[x][y].type == VIDE) {
            robot.x = x;
        }
        else if (grille[x][y].type == CAISSE) {
            if (grille[x-1][y].type == VIDE){
                grille[x-1][y].type = CAISSE;
                robot.x = x;
            }
        }
        else if (grille[x][y].type == BILLE) {
            if (grille[x-1][y].type == VIDE){
                grille[x-1][y].type = BILLE;
                robot.x = x;
            }
        }
        else return FAUX;
    }
    else if (robot.dir == BAS) {
        x = robot.x;
        y = robot.y + 1;
        if (grille[x][y].type == VIDE) {
            robot.y = y;
        }
        else if (grille[x][y].type == CAISSE) {
            if (grille[x][y+1].type == VIDE){
                grille[x][y+1].type = CAISSE;
                robot.y = y;
            }
        }
        else if (grille[x][y].type == BILLE) {
            if (grille[x][y+1].type == VIDE){
                grille[x][y+1].type = BILLE;
                robot.y = y;
            }
        }
        else return FAUX;
    }
    else if (robot.dir == DROITE) {
        x = robot.x + 1;
        y = robot.y;
        if (grille[x][y].type == VIDE) {
            robot.x = x;
        }
        else if (grille[x][y].type == CAISSE) {
            if (grille[x+1][y].type == VIDE){
                grille[x+1][y].type = CAISSE;
                robot.x = x;
            }
        }
        else if (grille[x][y].type == BILLE) {
            if (grille[x+1][y].type == VIDE){
                grille[x+1][y].type = BILLE;
                robot.x = x;
            }
        }
        else return FAUX;
    }
    else if (robot.dir == HAUT) {
        x = robot.x;
        y = robot.y - 1;
        if (grille[x][y].type == VIDE) {
            robot.y = y;
        }
        else if (grille[x][y].type == CAISSE) {
            if (grille[x][y-1].type == VIDE){
                grille[x][y-1].type = CAISSE;
                robot.y = y;
            }
        }
        else if (grille[x][y].type == BILLE) {
            if (grille[x][y-1].type == VIDE){
                grille[x][y-1].type = BILLE;
                robot.y = y;
            }
        }
        else return FAUX;
    }
    return VRAI;
}

int recule(robot_t robot, case_t** grille) {
    int x, y;
    /*cas differents selon la direction du robot*/
    if (robot.dir == GAUCHE) {
        x = robot.x + 1;
        y = robot.y;
        if (grille[x][y].type == VIDE) {
            robot.x = x;
        }
        else if (grille[x][y].type == CAISSE) {
            if (grille[x+1][y].type == VIDE){
                grille[x+1][y].type = CAISSE;
                robot.x = x;
            }
        }
        else if (grille[x][y].type == BILLE) {
            if (grille[x+1][y].type == VIDE){
                grille[x+1][y].type = BILLE;
                robot.x = x;
            }
        }
        else return FAUX;
    }
    else if (robot.dir == BAS) {
        x = robot.x;
        y = robot.y - 1;
        if (grille[x][y].type == VIDE) {
            robot.y = y;
        }
        else if (grille[x][y].type == CAISSE) {
            if (grille[x][y-1].type == VIDE){
                grille[x][y-1].type = CAISSE;
                robot.y = y;
            }
        }
        else if (grille[x][y].type == BILLE) {
            if (grille[x][y-1].type == VIDE){
                grille[x][y-1].type = BILLE;
                robot.y = y;
            }
        }
        else return FAUX;
    }
    else if (robot.dir == DROITE) {
        x = robot.x - 1;
        y = robot.y;
        if (grille[x][y].type == VIDE) {
            robot.x = x;
        }
        else if (grille[x][y].type == CAISSE) {
            if (grille[x-1][y].type == VIDE){
                grille[x-1][y].type = CAISSE;
                robot.x = x;
            }
        }
        else if (grille[x][y].type == BILLE) {
            if (grille[x-1][y].type == VIDE){
                grille[x-1][y].type = BILLE;
                robot.x = x;
            }
        }
        else return FAUX;
    }
    else if (robot.dir == HAUT) {
        x = robot.x;
        y = robot.y + 1;
        if (grille[x][y].type == VIDE) {
            robot.y = y;
        }
        else if (grille[x][y].type == CAISSE) {
            if (grille[x][y+1].type == VIDE){
                grille[x][y+1].type = CAISSE;
                robot.y = y;
            }
        }
        else if (grille[x][y].type == BILLE) {
            if (grille[x][y+1].type == VIDE){
                grille[x][y+1].type = BILLE;
                robot.y = y;
            }
        }
        else return FAUX;
    }
    return VRAI;
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

int pose(robot_t robot, case_t** grille) {
    int x, y;
    /*cas differents selon la direction du robot*/
    if (robot.dir == GAUCHE) {
        x = robot.x - 1;
        y = robot.y;
    }
    else if (robot.dir == BAS) {
        x = robot.x;
        y = robot.y + 1;
    }
    else if (robot.dir == DROITE) {
        x = robot.x + 1;
        y = robot.y;
    }
    else if (robot.dir == HAUT) {
        x = robot.x;
        y = robot.y - 1;
    }

    if (grille[x][y].type == VIDE && robot.porte == CAISSE) {
        grille[x][y].type = CAISSE;
        robot.porte = VIDE;
        return VRAI;
    }
    else if(grille[x][y].type == VIDE && robot.porte == BILLE) {
        grille[x][y].type = BILLE;
        robot.porte = VIDE;
        return VRAI;
    }
    else if(grille[x][y].type == TROU && robot.porte == BILLE) {
        grille[x][y].type = VIDE;
        robot.porte = VIDE;
        return BOUCHE;
    }
    else {
        return FAUX;
    }
}

int prend(robot_t robot, case_t** grille) {
    int x, y;
    /*cas differents selon la direction du robot*/
    if (robot.dir == GAUCHE) {
        x = robot.x - 1;
        y = robot.y;
    }
    else if (robot.dir == BAS) {
        x = robot.x;
        y = robot.y + 1;
    }
    else if (robot.dir == DROITE) {
        x = robot.x + 1;
        y = robot.y;
    }
    else if (robot.dir == HAUT) {
        x = robot.x;
        y = robot.y - 1;
    }

    if (grille[x][y].type == CAISSE && robot.porte == VIDE) {
        grille[x][y].type = VIDE;
        robot.porte = CAISSE;
        return VRAI;
    }
    else if(grille[x][y].type == BILLE && robot.porte == VIDE) {
        grille[x][y].type = VIDE;
        robot.porte = BILLE;
        return VRAI;
    }
    else {
        return FAUX;
    }
}

/* si on nomme la fonction case erreur a cause de 'switch case'*/
int contenu(int dir, robot_t robot, case_t** grille) {
    int type, x, y;
    x = robot.x;
    y = robot.y;

    if (robot.dir == HAUT) {
        if (dir == GAUCHE) {
            x--;
        }
        else if (dir == BAS) {
            y++;
        }
        else if (dir == DROITE) {
            x++;
        }
        else if (dir == HAUT) {
            y--;
        }
    }
    else if (robot.dir == DROITE) {
        if (dir == GAUCHE) {
            y--;
        }
        else if (dir == BAS) {
            x--;
        }
        else if (dir == DROITE) {
            y++;
        }
        else if (dir == HAUT) {
            x++;
        }
    }
    else if (robot.dir == BAS) {
        if (dir == GAUCHE) {
            x++;
        }
        else if (dir == BAS) {
            y--;
        }
        else if (dir == DROITE) {
            x--;
        }
        else if (dir == HAUT) {
            y++;
        }
    }
    else if (robot.dir == GAUCHE) {
        if (dir == GAUCHE) {
            y++;
        }
        else if (dir == BAS) {
            x++;
        }
        else if (dir == DROITE) {
            y--;
        }
        else if (dir == HAUT) {
            x--;
        }
    }
    type = grille[x][y].type;

    return type;
}
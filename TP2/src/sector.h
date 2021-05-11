/*
 * sector.h
 *
 *  Creado en: MAYO 10, 2021
 *      Autor: Andrea Briceño
 */

#ifndef SECTOR_H_
#define SECTOR_H_

#include <string.h>
#include <ctype.h>

typedef struct {
    int sector;
    int isEmpty;
    char nombre[30];
} EsctructuraSector;

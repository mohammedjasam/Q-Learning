#pragma once
#ifndef WORLD_H
#define WORLD_H

#include<iostream>

using namespace std;

// Global variables
static bool IS_THERE_DONUT_ON_MAP = false;

struct location
{
	int x, y;
};

// function definitions
void World();

#endif // !WORLD_H

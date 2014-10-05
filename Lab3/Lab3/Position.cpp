#include "Position.h"

Position& operator+(int diff, Position& pos)
{
    return pos.operator+(diff);
}
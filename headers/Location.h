/***********************************************************************
 * Module:  Location.h
 * Author:  franc
 * Modified: poniedzia�ek, 26 stycznia 2026 19:50:19
 * Purpose: Declaration of the class Location
 ***********************************************************************/

#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>
#include <vector>
#include <list>
class Item;
class PlaceOFImportance;
class NPC;

class Location
{
protected:
   std::string description;
   std::list<PlaceOFImportance *> interestingPlaces;
public:
   int tellAboutInterestingLocations(void);
};
#endif
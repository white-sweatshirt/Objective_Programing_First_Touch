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
class SubLocation;
class NPC;

class Location
{
protected:
   std::string description;
   std::list<SubLocation *> interestingPlaces;

public:
   int tellAboutInterestingLocations(void);
   void addNewSublocation(SubLocation *sublocation);
   Location(std::string desc);
   Location() = default;
   ~Location();
};
#endif
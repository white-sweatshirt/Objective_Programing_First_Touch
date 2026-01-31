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
#include "deque"
class Location
{
protected:
   std::string description;
   std::deque<SubLocation *> sublocations;

public:
   int tellAboutInterestingLocations(void);
   void addNewSublocation(SubLocation *sublocation);
   SubLocation * giveSublocationWithNumber(int numberOfSublocation);
   int giveNumberOfSublocations(void);
   void showAllSublocations(void);
   Location(std::string desc);
   void show();
   Location() = default;
   ~Location();
};
#endif
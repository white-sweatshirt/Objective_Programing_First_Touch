/***********************************************************************
 * Module:  Location.h
 * Author:  franc
 * Modified: poniedzia�ek, 26 stycznia 2026 19:50:19
 * Purpose: Declaration of the class Location
 ***********************************************************************/

#ifndef LOCATION_H
#define LOCATION_H
#include<iostream>
#include <vector>
class Items;
class PlaceOFImportance;
class NPC;

class Location
{
   protected:
   std::string description;
public:
   virtual void tellAboutInterestingLocations(void);

   Items** items;
   std::vector<PlaceOFImportance*> interestingPlaces;
};

class DarkFortress : public Location
{

   int creaturesLayOuts;
   int enemisLocation;
};
class Swamp : public Location
{

};
class Town : public Location
{

   std::vector<NPC*> vectorOfNPCs;
   void tellAboutInterestingLocations(void) override;

};

#endif
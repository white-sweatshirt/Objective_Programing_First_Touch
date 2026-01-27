/***********************************************************************
 * Module:  Location.h
 * Author:  franc
 * Modified: poniedzia�ek, 26 stycznia 2026 19:50:19
 * Purpose: Declaration of the class Location
 ***********************************************************************/

#ifndef LOCATION_H
#define LOCATION_H

class Items;
class PlaceOFImportance;

class Location
{
public:
   void tellAboutInterestingLocations(void);

   Items** items;
   PlaceOFImportance** placeOFImportance;

protected:
private:

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

};
#endif
/***********************************************************************
 * Module:  Location.h
 * Author:  franc
 * Modified: poniedzia³ek, 26 stycznia 2026 19:50:19
 * Purpose: Declaration of the class Location
 ***********************************************************************/

#if !defined(__UMLClassDiagram_1_Location_h)
#define __UMLClassDiagram_1_Location_h

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

#endif
/***********************************************************************
 * Module:  Location.cpp
 * Author:  franc
 * Modified: poniedzia�ek, 26 stycznia 2026 19:50:19
 * Purpose: Implementation of the class Location
 ***********************************************************************/
#include "Location.h"
#include "ImportantPlace.h"
#include "TemplateLib.h"

void Location::tellAboutInterestingLocations(void)
{
   // Use the template to show all interesting places
   std::cout<<"Opis lokacji: "<<this->description<<std::endl;
   std::cout<<"opis sublokacji: "<<std::endl;
   templateLib::showContentsOfContainer(this->interestingPlaces);
}

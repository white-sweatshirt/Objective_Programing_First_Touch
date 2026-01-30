/***********************************************************************
 * Module:  Location.cpp
 * Author:  franc
 * Modified: poniedzia�ek, 26 stycznia 2026 19:50:19
 * Purpose: Implementation of the class Location
 ***********************************************************************/
#include "Location.h"
#include "SubLocation.h"
#include "TemplateLib.h"

int Location::tellAboutInterestingLocations(void)
{
      // Use the template to show all interesting places
      std::cout << "Opis lokacji: " << this->description << std::endl;
      std::cout << "opis sublokacji: " << std::endl;
      int nPlaces = templateLib::showContentsOfContainerWithCounter(this->interestingPlaces);
      return nPlaces;
}
void Location::addNewSublocation(SubLocation *sublocation)
{
      this->interestingPlaces.push_back(sublocation);
}
Location::~Location()
{
      templateLib::killVectorOfPointers(this->interestingPlaces);
}
Location::Location(std::string desc):
description(desc)
{

}
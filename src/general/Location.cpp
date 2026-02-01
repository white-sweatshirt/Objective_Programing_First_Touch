/***********************************************************************
 * Module:  Location.cpp
 * Author:  franc
 * Modified: poniedzia�ek, 26 stycznia 2026 19:50:19
 * Purpose: Implementation of the class Location
 ***********************************************************************/
#include "Location.h"
#include "SubLocation.h"
#include "TemplateLib.h"
void Location::show()
{
      std::cout << "opis lokacji: " << this->description << std::endl;
      std::cout << "ilosc sublokacji: " << this->giveNumberOfSublocations()<<std::endl;
}

void Location::addNewSublocation(SubLocation *sublocation)
{
      this->sublocations.push_back(sublocation);
}
Location::~Location()
{
      templateLib::killVectorOfPointers(this->sublocations);
}
SubLocation *Location::giveSublocationWithNumber(int choice)
{
      return this->sublocations[choice];
}
void Location::showAllSublocations(void)
{
      std::cout << "***************************" << std::endl;
      std::cout << "wsystkie sublokacje w lokcaji " << this->description << ": " << std::endl;
      templateLib::showContentsOfContainerWithCounter(this->sublocations);
}
int Location::giveNumberOfSublocations(void)
{
      return this->sublocations.size();
}
Location::Location(std::string desc) : description(desc)
{
}
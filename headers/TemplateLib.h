#ifndef TEMPLATE_LIB_H
#define TEMPLATE_LIB_H

// due to bug in some compilers(my compiler g++.exe (Rev8, Built by MSYS2 project) 15.2.0)
// there is a need to include full definition
// of template functions
// in this header file , other solutions would be to put them in a separate file *.cpp
// and include it here
// namspace for grouping functions and preventing potenial overUse of name as well as for example
#include <iostream>
namespace templateLib
{

   template <class vectorOfPointers>
   void killVectorOfPointers(vectorOfPointers &killedVector)
   {
      for (auto w : killedVector)
         delete w;
      killedVector.clear();
   }

   // it doesnt delte pointer it just removed it from vector
   template <class vectorOfPointersToClass, class pointerTypeToRemove>
   void removeElemetOfVector(vectorOfPointersToClass &a, pointerTypeToRemove b)
   {
      for (auto it : a)
         if (it == b)
         {
            std::swap(it, a.back()); // bezposrednie odwolanie do przestrzeni std
            a.pop_back();
            return;
         }
   }
   // standard way of showing contents of pointer to class
   template <typename vectorOfPointersToClassesWithShow>
   void showContentsOfContainer(vectorOfPointersToClassesWithShow a)
   {
      for (auto w : a)
         w->show();
   }
   template <typename vectorOfPointersToClassesWithShow>
   int showContentsOfContainerWithCounter(vectorOfPointersToClassesWithShow a)
   {
      int i = 0;
      for (auto w : a)
      {
         std::cout << i << ". " << std::endl;
         w->show();
      }
      return i;
   }

   //void ignoreToNextEnter()
   //{
     
   //}

   template <class T>
   int getStandardChoiceResult(T *objectOnWithIoperate, void (T::*showMenu)(void), int lowerLimit, int upperLimit)
   {
      char choice;
      int i = 0;
       int c = -1;
      int constexpr numberToNotSeeMenu = 10;
      (objectOnWithIoperate->*showMenu)();
      do
      {
         if (i == numberToNotSeeMenu)
         {
            (objectOnWithIoperate->*showMenu)();
            i = 0;
         }
         else
            i++;
         choice = getchar();
         
      while ((c = getchar()) != EOF && c != '\n')
         ;
      } while (choice < lowerLimit || choice > upperLimit);
      return choice;
   }
   template <class T>
   int getStandardChoiceResult(T *objectOnWithIoperate, void (T::*showMenu)(int max), int lowerLimit, int upperLimit)
   {
      char choice;
      int i = 0,c=-1;
      int constexpr numberToNotSeeMenu = 10;
      (objectOnWithIoperate->*showMenu)(upperLimit);
      do
      {
         if (i == numberToNotSeeMenu)
         {
            (objectOnWithIoperate->*showMenu)(upperLimit);
            i = 0;
         }
         else
            i++;
         choice = getchar();
         while ((c = getchar()) != EOF && c != '\n')
         ;
      } while (choice < lowerLimit || choice > upperLimit);
      return choice;
   }
}
#endif
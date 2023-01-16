#include <stdio.h> 
 struct Birthday 
 { 
 int year; 
 int month; 
 int day; 
 }; //注意这里要加分号 
   int main() 
 { 
 struct Birthday b; 
 b.year = 2008; 
 b.month = 11; 
 b.day = 11; 
 printf("%d-%d-%d\n", b.year, b.month, b.day); 
 return 0; 
 } 

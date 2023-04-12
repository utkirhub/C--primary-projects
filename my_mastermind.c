#include <string.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <unistd.h>
 #include <stdbool.h>
 #include <stdint.h>
 #include <time.h>
 #include "mastermind.h"

 int part_1(char* val_1){
     int val = 0;
     while (val_1[val] != '\0'){
         val++;
     }
     return val;
 }
 int part_2(char* edu, char educ){ 
     int val_2 = 0;
     for(int nmb = 0; nmb < part_1(edu); nmb++){ 
         if(edu[nmb] == educ){ 
             val_2++;
         } 
     } 
     if(val_2!=0){
         return val_2; 
     }else {
         return 0;
     }
 } 
 bool control_number(char*set){ 
     if(part_1(set) == 4){
         for(int nmb = 0; set[nmb] != '\0';nmb++){ 
             if(set[nmb] < '0' || set[nmb] > '9'){ return false; 
             } 
         } 
     
         for(int fine = 0; fine < 3;fine++){ 
             for(int nmb = fine + 1;nmb < 4; nmb++){ 
                 if(set[fine] == set[nmb]){ 
                     return false; 
                 } 
             } 
         } 
         return true; 
     return false;
 

     }
     return 0;
 }
 bool compare_number(char *goal,char* win){ 
     if(goal[1] != win[1]){ 
         return true; 
     } 
     return false; 
 }
 

 

 

 int miss_piece(char* prm5, char* prm6){
   if (part_1(prm5) == part_1(prm6)){
     int pending = 0;
     for(int vrbl = 0; vrbl < part_1(prm5);vrbl++){
       for(int veriable2 = 0; veriable2 < part_1(prm6);veriable2++){
         if(prm5[vrbl] ==  prm6[veriable2] && vrbl!=veriable2){
           pending++;
         }
       }
     }
     return pending;
   }
   return 0;
 }
 

 int well_piece(char* prmtr1, char* prmtr2){
   if (part_1(prmtr1) == part_1(prmtr2)){
     int pending2 = 0;
     int nmb = 0;
     while(nmb < part_1(prmtr1)){
       if(prmtr1[nmb] == prmtr2[nmb]){
         pending2++;
       }
       nmb++;
     }
     return pending2;
   }
   return 0;
 }
 

 char* randing(){ 
     srand(time(NULL)); 
     char* go = malloc(4); 
     char num; 
     int nmb = 0; 
     while(nmb<4){ 
         num = rand()%8 + '0'; 
         if(part_2(go,num) == 0){ 
             go[nmb] = num; 
             nmb++; 
         } 
     } 
     return go; 
 } 

 int main(int argv,char* argc[]){ 
     char* goal = malloc(4); 
     goal = 0; 
     int run = 10; 
     printf("Will you find the secret code?\nPlease enter a valid guess\n"); 
     int nmb = 1;
     for(;nmb < argv;){ 
         if(compare_number(argc[nmb], "-t") == 0){ nmb++; run = atoi(argc[nmb]); } 
         else if(compare_number(argc[nmb], "-c") == 0){ nmb++; goal = argc[nmb]; }
         else{nmb++;} 
         nmb++;
     } 
     if(goal == 0) goal = randing();
     int place = 1000; 
 

     for(int dr = 0; dr < run;dr++){ 
         if(place != dr ) printf("---\nRound %d\n", dr); 
         write(1,">",1); 
         char* win = malloc(10); 
         win = read_number(win); 
         place = dr; 
         if(control_number(win) == 0){ 
             printf("Wrong input!\n"); 
             dr--;  
         } 
         else if(control_number(win) == 1) 
         { 
  
             if(well_piece(goal, win) == 4) 
             { 
                 printf("Congratz! You did it!\n"); 
                 break;
             }else{ 
                 printf("\nWell placed pieces: %d\nMisplaced pieces: %d\n", well_piece(goal, win), miss_piece(goal, win)); 
             } 
         } 
     } 
      
 }
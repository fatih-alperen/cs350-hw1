///////////////////////////////////////////
//								         //
//  Copyright 2020 Alperen Fatih Zengin  //
//									     //
///////////////////////////////////////////
/*

This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

#include <stdio.h>

int main(void){

	int numOfPpl;
	int points [7];
	for(int i=0;i<7;i++) points[i] = 0;

	char foods[7][20] = {"Kebab", "Burger" , "Pasta" , "Lahmacun" , "Salad", "Sushi", "Pizza"};

	int disabled[7];
	for(int i=0;i<7;i++) disabled[i]=0;


	printf("Enter the number of people:");
	scanf("%d",&numOfPpl);

//
//		first round
//

	for(int i=0; i<numOfPpl;i++){
		printf("User number %d, please enter five choices from the list in order of your preference.\n",i+1);
		for(int j=0;j<7;j++){
			printf("%d-%s\n",j+1,foods[j]);
		}
		//enable all choices for new user
		for(int i=0;i<7;i++) disabled[i]=0;

		for(int j=0;j<5;j++){
			int choice;
                	scanf("%d",&choice);
			if(choice <=7 && choice > 0 && !disabled[choice-1]){
				points[choice-1] += (5-j);
				disabled[choice-1] = 1;
			}else{
				j--;
				printf("Please enter a valid choice! (You cannot enter same number twice)\n");
			}
		}
	}
//
//		creating short list
//

	int winnerCount =0;
	printf("\n\n");
	for(int j=0;j<7;j++) disabled[j]=1;
	for(int j=0;j<7;j++){
		if(points[j] > (numOfPpl*3)){
	                printf("%d-%s\n",j+1,foods[j]);

					//enable only the winners of the first round
                    disabled[j]=0;
					
					winnerCount++;
                }
	}

	if(winnerCount==0){
		printf("\n\nYou are eating at home/dorm today!\n");
		return 0;
	}

//
//		second round
//

	else if(winnerCount>1)
	for(int i=0; i<numOfPpl;i++){

		printf("User number %d, please vote for your favourite from the list above:\n", i+1);
		
		int choice;
		scanf("%d",&choice);
		
		if(choice <=7 && choice > 0 && !disabled[choice-1])
			points[choice-1] += 5;
		else{
			i--;
			printf("Your choice is not on the list!\n");
		}
	}

	int winner = 0;
	for(int i=0;i<7;i++){
		if(points[i] > points[winner]) winner = i;
		printf("\n%s:%d\n",foods[i],points[i]);
	}
//
//		This part makes the winner all caps so it looks better.
//
	int index=0;
	while(foods[winner][index] != '\0'){
		if(foods[winner][index] >= 'a' && foods[winner][index] <= 'z')
			foods[winner][index] += ('A'-'a');
		index++;
	}


	printf("\n\nWE ARE ORDERING %s TONIGHT\n", foods[winner]);
	return 0;
}

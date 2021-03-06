/*
 ============================================================================
 Name        : veichle.c
 Author      : Nader Atef
 Description : vehicle control system
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void print_sensors_set_menu(void);
void quit_system(void);
void print_main(void);
void system_response(char);
void set_traffic();
void set_roomtemp();
void display_vehicle_state();
#define ON 1
#define OFF 0
struct car_state{
	int Engine_state;
	int AC_state;
	int vehicle_speed;
	int room_temp;
	int Engine_temp;
	int Engine_controller;
	int AC_temp;
	int controller_temp;


}car1;
int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	car1.Engine_state=OFF;
	/*the code depends on an infinte loop (super loop) technique where we 1st call the first menu, then call the 2nd menu unless we turn off the motor
	 * we switch back to the main menu */
	while(1){
		print_main(); // call main menu
		while(car1.Engine_state==ON){ // if the engine is on print the second menu, if not repeat again.
			print_sensors_set_menu();

		}
	}
	return 0;
}

void display_vehicle_state(void){
	// function to display the vehicle state
	printf("AC condition is : %d\n",car1.AC_state);
	printf("Engine state is: %d\n",car1.Engine_state);
	printf("vehicle speed is: %d\n",car1.vehicle_speed);
	printf("Room temperature is: %d\n",car1.room_temp);
	printf("Engine temperature controller state is: %d\n",car1.Engine_controller);
	printf("Engine temperature is: %d\n",car1.Engine_temp);
}
/*print the second menu which determines what to do in the car*/
void print_sensors_set_menu(void){
	car1.Engine_state=ON;

	printf("Now displaying Sensors set menu: \n\n");
	printf("a.\t Turn off the engine\n");
	printf("b.\t Set the traffic light color\n");
	printf("c.\t Set the room temperature\n");
	printf("d.\t Set engine temperature");
	printf("\n\n");
	char choice;
	scanf(" %c",&choice);
	system_response(choice);
	display_vehicle_state();

}
/* function to control the speed of the car based on readings from console depending on the traffic lights*/
void set_traffic(){
	char traffic;
	printf("please enter traffic light color\n");
	scanf(" %c",&traffic);
	if(traffic=='G'){
		car1.vehicle_speed=100;
		printf("i am here \n\n");
	}
	else if(traffic=='O'){
		car1.vehicle_speed=30;

	}
	else if(traffic=='R'){
		car1.vehicle_speed=0;

	}

}
/*function to control the AC unit of the car*/
void set_roomtemp(){
	int temp;
	printf("please enter the temperature of the room \n");
	scanf("%d",&temp);
	if(temp<10){
		car1.AC_state=ON;
		car1.AC_temp=20;
		car1.room_temp=temp;

	}
	else if(temp>30){
		car1.AC_state=ON;
		car1.AC_temp=20;
		car1.room_temp=temp;


	}
	else{
		car1.AC_state=OFF;


	}


}
/*function to control the engine controller and set's its temperature*/
void set_engine(){
	int temp;
	printf("please enter the engine temperature\n");
	scanf("%d",&temp);
	if(temp<100){
		car1.Engine_controller=ON;
		car1.controller_temp=125;
		car1.Engine_temp=temp;

	}
	else if(temp>150){
		car1.Engine_controller=ON;
		car1.controller_temp=125;
		car1.Engine_temp=temp;

	}
	else{
		car1.Engine_controller=OFF;

	}



}

/* system_response is the main function in the control system which accepts the choice from the second menu and chooses what to
do with the sensors */

void system_response(char choice){
	// I only take the input after the system starts to respond depending on the selected option from the second menu
	if(choice=='a'){
		car1.Engine_state=OFF;
		return;
	}
	else if (choice=='b'){
		set_traffic();

	}
	else if(choice=='c'){

		set_roomtemp();

	}
	else if(choice=='d'){

		set_engine();

	}
	if(car1.vehicle_speed==30){
		car1.room_temp =car1.room_temp*(5.0/4)+1;
		car1.Engine_temp=car1.Engine_temp*(5.0/4)+1;
		if(car1.AC_state==OFF){
			car1.AC_state=ON;
		}
		if(car1.Engine_controller==OFF){
			car1.Engine_controller=ON;

		}
	}

}
/*function to quit the system using exit(1) */
void quit_system(void){
	printf("System closed Good bye\n");
	exit(0);

}
/*print_main is a function to print the main menu of the control system it acts like a startup for the system */
void print_main(void){
	char choice;
	// do while to keep repeating until taking the successful input (as was explained in the lecture :) )
	do{
		printf("a.\t Turn on the veichle engine\n");
		printf("b.\t Turn off the veichle engine\n");
		printf("c.\t Quit the system");
		printf("\n\n");
		scanf(" %c",&choice);
	}while(choice=='b');
	if(choice=='a'){
		print_sensors_set_menu();
	}
	else if(choice=='c'){
		quit_system();

	}


}


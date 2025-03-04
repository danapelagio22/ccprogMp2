#include<stdio.h>
#include<string.h>

typedef struct
 {
    char TPNETD[6];
    int time;
    char DEST[20];  
} IndivTrip;

typedef struct {
    int priority;
    char name[50];
    char id[20];
    char dropOff[50];
} Passenger;

int main() 
{
    int hrs, mins;

 
  	  IndivTrip trips[] = { {"AE101", 600, "Manila-Laguna"}, {"AE102", 730, "Manila-Laguna"}, {"AE103", 930, "Manila-Laguna"}, {"AE104", 1100, "Manila-Laguna"}, {"AE105", 100, "Manila-Laguna"}, {"AE106", 230, "Manila-Laguna"},
{"AE107", 330}, {"AE108", 500, "Manila-Laguna"}, {"AE109", 615, "Manila-Laguna"}, {"AE150", 530, "Laguna-Manila"}, {"AE151", 545, "Laguna-Manila"}, {"AE152", 700, "Laguna-Manila"}, {"AE153", 730, "Laguna-Manila"}, 
{"AE154", 900}, {"AE155", 1100, "Laguna-Manila"}, {"AE156", 100, "Laguna-Manila"}, {"AE157", 230, "Laguna-Manila"}, {"AE158", 330, "Laguna-Manila"}, {"AE159", 500, "Laguna-Manila"}, {"AE160", 615, "Laguna-Manila"}

};

    
    char inputTripCode[6];
    printf("Enter Trip Code: ");
    scanf("%s", inputTripCode);

    int found = 0;
    for (int i = 0; i < 21; i++)
	 {  
        if (strcmp(trips[i].TPNETD, inputTripCode) == 0) 
		{
            
            hrs = trips[i].time/100;
            
			mins = trips[i].time%100;
            
			
			printf("Trip Code: %s, Time: %02d:%02d, Destination: %s\n", trips[i].TPNETD, hrs, mins, trips[i].DEST);
            
			found = 1;
            
			break;
        }
    }

    if (!found) 
	{
        printf("Trip code not found.\n");
        return 1;
    }
    
// ?? **Added: Embarkation Card Feature**
    Passenger p;

    // Function to fill out the embarkation card
    printf("\n?? Fill Out Embarkation Card\n");

    // Get priority number (must be between 1-6)
    do {
        printf("Enter Priority Number (1-6, 1 is highest): ");
        scanf("%d", &p.priority);
        if (p.priority < 1 || p.priority > 6) {
            printf("? Invalid priority. Enter a value between 1-6.\n");
        }
    } while (p.priority < 1 || p.priority > 6);

    // Get passenger name
    printf("Enter Name: ");
    scanf(" %[^\n]", p.name);

    // Get ID number
    printf("Enter ID Number: ");
    scanf("%s", p.id);

    // Get drop-off point
    printf("Enter Drop-Off Point: ");
    scanf(" %[^\n]", p.dropOff);

    printf("\n? Embarkation Card Completed!\n");

    // ?? **Added: Display Embarkation Details**
    printf("\n?? Embarkation Card Summary:\n");
    printf("Trip: %s | Time: %02d:%02d | Route: %s\n",
           trips[tripIndex].TPNETD, trips[tripIndex].time / 100, trips[tripIndex].time % 100, trips[tripIndex].DEST);
    printf("Priority: %d\n", p.priority);
    printf("Name: %s\n", p.name);
    printf("ID Number: %s\n", p.id);
    printf("Drop-Off Point: %s\n", p.dropOff);

    return 0;
}
  

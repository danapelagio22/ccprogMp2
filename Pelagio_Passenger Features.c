#include<stdio.h>
#include<string.h>

typedef struct
{
    char TPNETD[6];
    int time;
    char DEST[20];  
} IndivTrip;

// Struct for storing passenger details
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

	char mamplasanDropOff[][50] = {"Mamplasan Toll Exit", "Phase 5, San Jose Village", "MRR East Canopy"};
    char etonDropOff[][50] = {"Laguna Blvd. Guard House", "MRR East Canopy"};
    char estradaDropOff[][50] = {"Petron Gas Station", "Gate 4", "North Gate", "South Gate"};
    char buendiaDropOff[][50] = {"CSB", "Gate 4", "North Gate", "South Gate"};

    char inputTripCode[6];
    printf("Enter Trip Code: ");
    scanf("%s", inputTripCode);

    int found = 0;
    int tripIndex;
    
    for (tripIndex = 0; tripIndex < 20; tripIndex++) 
    {  
        if (strcmp(trips[tripIndex].TPNETD, inputTripCode) == 0) 
        {
            hrs = trips[tripIndex].time / 100;
            mins = trips[tripIndex].time % 100;

            printf("Trip Code: %s, Time: %02d:%02d, Destination: %s\n", 
                   trips[tripIndex].TPNETD, hrs, mins, trips[tripIndex].DEST);

            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("Trip code not found.\n");
        return 1;
    }

    //  Embarkation Card Feature
    Passenger p;

    printf("\nFill Out Embarkation Card\n");

    do {
        printf("Enter Priority Number ");
        scanf("%d", &p.priority);
        if (p.priority < 1 || p.priority > 6) {
            printf("Invalid priority. Enter a value between 1-6.\n");
        }
    } while (p.priority < 1 || p.priority > 6);

    printf("Enter Name: ");
    scanf(" %[^\n]", p.name);

    printf("Enter ID Number: ");
    scanf("%s", p.id);
    
    int validDropOff = 0;
    do {
        printf("Enter Drop-Off Point: ");
        scanf(" %[^\n]", p.dropOff);

        int i;
        if (strcmp(trips[tripIndex].DEST, "Manila-Laguna") == 0) {
            //Validate drop-off points for Manila to Laguna trips
            if (strstr(inputTripCode, "AE10") || strstr(inputTripCode, "AE109")) {
                for (i = 0; i < 3; i++) {
                    if (strcmp(p.dropOff, mamplasanDropOff[i]) == 0) {
                        validDropOff = 1;
                        break;
                    }
                }
            } else {
                for (i = 0; i < 2; i++) {
                    if (strcmp(p.dropOff, etonDropOff[i]) == 0) {
                        validDropOff = 1;
                        break;
                    }
                }
            }
        } else {
            //  Validate drop-off points for Laguna to Manila trips
            if (strstr(inputTripCode, "AE15") || strstr(inputTripCode, "AE159")) {
                for (i = 0; i < 4; i++) {
                    if (strcmp(p.dropOff, estradaDropOff[i]) == 0) {
                        validDropOff = 1;
                        break;
                    }
                }
            } else {
                for (i = 0; i < 4; i++) {
                    if (strcmp(p.dropOff, buendiaDropOff[i]) == 0) {
                        validDropOff = 1;
                        break;
                    }
                }
            }
        }

        if (!validDropOff) {
            printf("Invalid drop-off point for this trip. Try again.\n");
        }
    } while (!validDropOff); 

    printf("\nEmbarkation Card Completed!\n");

    printf("\nEmbarkation Card Summary:\n");
    printf("Trip: %s | Time: %02d:%02d | Route: %s\n",
    
           trips[tripIndex].TPNETD, trips[tripIndex].time / 100, trips[tripIndex].time % 100, trips[tripIndex].DEST);
           
    printf("Priority: %d\n", p.priority);
    printf("Name: %s\n", p.name);
    printf("ID Number: %s\n", p.id);
    printf("Drop-Off Point: %s\n", p.dropOff);

    return 0;
}

   


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct coordinate {
    char location[100];
    char city[100];
    int price;
    int room;
    int bathroom;
    int carpark;
    char type[100];
    char furnish[100];
};

void choice_1(FILE* fptr ,int choice){
	
	struct coordinate hotel[100];
	
	int rows;
	
	if (choice==1){
    	printf("Number of rows: ");
    	scanf("%d", &rows);
		
		if (rows<0){
			printf ("NOT FOUND! : Number of rows must be integer\n");
			return;
		}
		
		char n;
		while (n!='\n'){
			n=fgetc(fptr);
		}
		
		for (int i=0; i<rows; i++){
			fscanf (fptr, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n", hotel[i].location, 
			hotel[i].city, &hotel[i].price, 
			&hotel[i].room, &hotel[i].bathroom, &hotel[i].carpark, 
			hotel[i].type, hotel[i].furnish);
		}
		
		printf("| %-20s | %-12s | %-10s | %-5s | %-8s | %-10s | %-11s | %-12s |\n",
        "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
		
		for (int i=0; i<rows; i++){
			printf ("| %-20s | %-12s | %-10d | %-5d | %-8d | %-10d | %-12s| %-12s |\n", hotel[i].location, 
			hotel[i].city, hotel[i].price, 
			hotel[i].room, hotel[i].bathroom, hotel[i].carpark, 
			hotel[i].type, hotel[i].furnish);
		}
	
	
	}
		
}

void choice_2(FILE* fptr, int choice) {
    char column_choice[100];
    char keyword[100];
    int headerPrinted = 1;
	static int headertable=1;
	
    if (choice == 2) {
        printf("Choose Column: ");
        scanf("%s", column_choice);

        printf("What hotel do you want to find? ");
        scanf("%s", keyword);

        int found = 0;

        rewind(fptr);

        char header[256];
        fgets(header, sizeof(header), fptr);
			
		if (headertable){
			printf("| %-20s | %-12s | %-10s | %-5s | %-8s | %-10s | %-12s | %-12s |\n",
	    	"Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
			headertable=0;
		}
    	

        struct coordinate hotel;

        while (fscanf(fptr, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n",
                      hotel.location, hotel.city, &hotel.price, &hotel.room, &hotel.bathroom,
                      &hotel.carpark, hotel.type, hotel.furnish) == 8) {
            
			          	
            if (headerPrinted){
            	headerPrinted=0;
            	continue;
			}

            if ((strcmp(column_choice, "Location") == 0 && strcmp(hotel.location, keyword) == 0) ||
                (strcmp(column_choice, "City") == 0 && strcmp(hotel.city, keyword) == 0) ||
                (strcmp(column_choice, "Price") == 0 && hotel.price == atoi(keyword)) ||
                (strcmp(column_choice, "Rooms") == 0 && hotel.room == atoi(keyword)) ||
                (strcmp(column_choice, "Bathroom") == 0 && hotel.bathroom == atoi(keyword)) ||
                (strcmp(column_choice, "Carpark") == 0 && hotel.carpark == atoi(keyword)) ||
                (strcmp(column_choice, "Type") == 0 && strcmp(hotel.type, keyword) == 0) ||
                (strcmp(column_choice, "Furnish") == 0 && strcmp(hotel.furnish, keyword) == 0)) {
				
				
                printf("| %-20s | %-12s | %-10d | %-5d | %-8d | %-10d | %-12s | %-12s |\n",
                       hotel.location, hotel.city, hotel.price, hotel.room, hotel.bathroom,
                       hotel.carpark, hotel.type, hotel.furnish);

                found = 1;
            }
        }

        if (!found && headertable==0) {
            printf("NOT FOUND! : No matching data found.\n");
            return;
        }
    }
}



void insertionsort(struct coordinate hotel[4000], int n, const char *column_choice, const char *option_sort){
	int j;
	struct coordinate key;
	
	for (int i=1; i<n; i++){
		key=hotel[i];
		j=i-1;

		while (j>=0){
			int compare_result=0;
			if (strcmp(column_choice, "Location")==0){
				compare_result = strcmp(hotel[j].location, key.location);
			}
			else if (strcmp(column_choice, "City")==0){
				compare_result = strcmp(hotel[j].city, key.city);
			}
			else if (strcmp(column_choice, "Price")==0){
				compare_result = hotel[j].price - key.price;
			}
			else if (strcmp(column_choice, "Rooms")==0){
				compare_result = hotel[j].room - key.room;
			}
			else if (strcmp(column_choice, "Bathroom")==0){
				compare_result = hotel[j].bathroom - key.bathroom;
			}
			else if (strcmp(column_choice, "Carpark")==0){
				compare_result = hotel[j].carpark - key.carpark;
			}
			else if (strcmp(column_choice, "Type")==0){
				compare_result = strcmp(hotel[j].type, key.type);
			}
			else if (strcmp(column_choice, "Furnish")==0){
				compare_result = strcmp(hotel[j].furnish, key.furnish);
			}
			
			if (strcmp(option_sort, "asc") ){
				if (compare_result>0){
					hotel[j+1]=hotel[j];
					j=j-1;
				}	
			}
			
			if (strcmp(option_sort, "dsc")){
				if (compare_result<0){
					hotel[j+1]=hotel[j];
					j=j-1;
				}	
			}
			
			else {
				break;
			}
		}
		hotel[j+1]=key;
	}
	
}

void choice_3 (FILE* fptr, int choice){
	char column_choice[100];
	char option_sort[100];
	struct coordinate hotel[4000];
	int i=-1;
	
	if (choice==3){
		printf ("Choose column: ");
		scanf ("%s", column_choice);
        getchar();
		
		printf ("Sort ascending or descending? ");
		scanf ("%s", option_sort);
        getchar();
		while (!feof(fptr)) {
            struct coordinate throw;
            if (i == -1) {
                i++;
                fscanf(fptr, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n",
                    throw.location, throw.city, &throw.price, &throw.room, &throw.bathroom,
                    &throw.carpark, throw.type, throw.furnish);
                    continue;
            }
            fscanf(fptr, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n",
                    hotel[i].location, hotel[i].city, &hotel[i].price, &hotel[i].room, &hotel[i].bathroom,
                    &hotel[i].carpark, hotel[i].type, hotel[i].furnish);
                    i++;
		}
		//insertionsort(hotel, i, column_choice, option_sort);
		for (int j=0; j<10; j++){
			printf ("| %-20s | %-12s | %-10d | %-5d | %-8d | %-10d | %-12s| %-12s |\n", hotel[j].location, 
				hotel[j].city, hotel[j].price, 
				hotel[j].room, hotel[j].bathroom, hotel[j].carpark, 
				hotel[j].type, hotel[j].furnish);
                	
                    	
        }
	}
	
}


//void exportfile ()

int main() {
    int choice;

    FILE* fptr;
    fptr = fopen("file.csv", "r");

    if (fptr == NULL) {
        printf("404_NOT_FOUND!");
        exit(1);
    }

    printf("What do you want to do?\n");
    printf("1. Display Data\n");
    printf("2. Search Data\n");
    printf("3. Sort Data\n");
    printf("4. Export Data\n");
    printf("5. Exit\n");
    printf("Your choice: ");

    scanf("%d", &choice);

    struct coordinate hotel[100];
	choice_1(fptr, choice);
	choice_2(fptr, choice);
	choice_3(fptr, choice);
    

    fclose(fptr);

    return 0;
}


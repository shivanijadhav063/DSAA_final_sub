// Program to demonstrate Hashing with Linear Probing for Collision Resolution
#include <conio.h >
#include <stdlib.h >

#define LIMIT 5

//Constants
enum record_status {EMPTY, DELETED, OCCUPIED};


struct Employee
{
    int employee_id, employee_age;
    char employee_name[30];
};

// Structure for hash_table array
struct Record
{
    struct Employee info;
    enum record_status status; // status indicates if the record is {EMPTY, DELETED, OCCUPIED}
};

int hash_function(int key)
{
    // Here Modulo N is implemented
    // hash function should be changed as needed
    return (key % LIMIT);
}

int search_records(int key, struct Record hash_table[])
{
    int count, temp, position;

    temp = hash_function(key);
    position = temp;

    for (count = 1; count <= LIMIT; count++)
	{
        if (hash_table[position].status == EMPTY)
		{
            return -1;
        }
        if (hash_table[position].info.employee_id == key)
		{
            return position;
        }
        position = (temp + count) % LIMIT;
    }
    return -1;
}

void insert_records(struct Employee emprec, struct Record hash_table[])
{
    int count, position, temp;
    int key = emprec.employee_id;
    int flag = 1;

    temp = hash_function(key);
    position = temp;

    for (count = 1; count <= LIMIT; count++)
	{
        if (hash_table[position].status == EMPTY || hash_table[position].status == DELETED)
		{
            hash_table[position].info = emprec;
            hash_table[position].status = OCCUPIED;
            printf("\nRecord Inserted into Hash Table !");
            return;
        }
        if(flag)
        {
            printf("\nCollision Occurred !");
            flag = 0;
        }
        if (hash_table[position].info.employee_id == key)
		{
            printf("\nDuplicate Record cannot be Inserted !");
            return;
        }
        position = (temp + count) % LIMIT;
    }
    printf("\nHash Table Limit Exceeded !");
}

void display_records(struct Record hash_table[])
{
    int count;
    printf("\nHash Table\n");
    for (count = 0; count < LIMIT; count++)
	{
        printf("\n[%d] :\t", count);
        if (hash_table[count].status == OCCUPIED)
		{
            printf("Occupied by {ID: %d Name: %s Age: %d}", hash_table[count].info.employee_id, hash_table[count].info.employee_name, hash_table[count].info.employee_age);
        }
		else if (hash_table[count].status == DELETED)
		{
            printf("Record is Deleted");
        }
		else
		{
            printf("Empty");
        }
    }
}

void delete_records(int key, struct Record hash_table[])
{
    int position = search_records(key, hash_table);
    if (position == -1)
	{
        printf("\nKey Not Found");
    }
	else
	{
        hash_table[position].status = DELETED;
        printf("\nRecord Successfully Deleted !");
    }
}

int main()
{
    int count, key, choice;
    struct Record hash_table[LIMIT];
    struct Employee emprec;

    for (count = 0; count < LIMIT; count++)
	{
        hash_table[count].status = EMPTY;
    }

    do
	{
	    printf("\n\n***** Menu *****");
        printf("\n1. Insert a Record");
        printf("\n2. Delete a Record");
        printf("\n3. Search a Record");
        printf("\n4. Display All Records");
        printf("\n5. Exit");

        printf("\nEnter Your choice :\t");
        scanf("%d", &choice);

        switch (choice)
		{
			case 1:
				printf("\nEnter Employee ID :\t");
				scanf("%d", &emprec.employee_id);
				printf("Enter Employee Name :\t");
				scanf("%s", emprec.employee_name);
				printf("Enter Employee Age :\t");
				scanf("%d", &emprec.employee_age);
				insert_records(emprec, hash_table);
				break;

			case 2:
				printf("\nEnter the Key to Delete :\t");
				scanf("%d", &key);
				delete_records(key, hash_table);
				break;

			case 3:
				printf("\nEnter the Key to Search :\t");
				scanf("%d", &key);
				count = search_records(key, hash_table);
				if (count == -1)
				{
					printf("\nRecord Not Found\n");
				}
				else
				{
					printf("\nRecord Found at Index Position :\t%d\n", count);
					printf("Record : {ID: %d Name: %s Age: %d}", hash_table[count].info.employee_id, hash_table[count].info.employee_name, hash_table[count].info.employee_age);
				}
				break;

			case 4:
				display_records(hash_table);
				break;

			case 5:
				break;

            default :
                printf("\nInvalid Input !");
        }
    }while(choice != 5);
    return 0;
}

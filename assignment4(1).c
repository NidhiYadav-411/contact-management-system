#include <stdio.h>
#include <string.h>
#include <ctype.h>


struct Contact {
    char name[100];
    char email[100];
    char phone[20];
};


int compareNames(char name1[], char name2[]) {
    return strcmp(name1, name2);
}


void copyContactDetails(char src[], char dest[]) {
    strcpy(dest, src);
}


int nameLength(char name[]) {
    return strlen(name);
}

void concatenateContactInfo(char name[], char email[], char phone[], char result[]) {
    strcpy(result, name);
    strcat(result, " | ");
    strcat(result, email);
    strcat(result, " | ");
    strcat(result, phone);
}


int isValidName(char name[]) {
    int len = strlen(name);
    
   
    if (len < 1 || len > 15) {
        return 0; 
    }

    
    for (int i = 0; i < len; i++) {
        if (!isalpha(name[i])) {
            return 0; 
        }
    }
    return 1; 
}


int compareContacts(struct Contact contact1, struct Contact contact2) {
    return strcmp(contact1.name, contact2.name);
}

int main() {
    struct Contact contact1, contact2;
    char copiedName[100], contactDetails[300];

    
    while (1) {
        printf("Enter the first contact name (1 to 15 alphabets): ");
        fgets(contact1.name, sizeof(contact1.name), stdin);
        contact1.name[strcspn(contact1.name, "\n")] = '\0'; 

        if (isValidName(contact1.name)) {
            break;
        } else {
            printf("Invalid name! The name must contain between 1 and 15 alphabets.\n");
        }
    }

    
    while (1) {
        printf("Enter the second contact name (1 to 15 alphabets): ");
        fgets(contact2.name, sizeof(contact2.name), stdin);
        contact2.name[strcspn(contact2.name, "\n")] = '\0'; 

        if (isValidName(contact2.name)) {
            break; 
        } else {
            printf("Invalid name! The name must contain between 1 and 15 alphabets.\n");
        }
    }
     if (compareContacts(contact1, contact2) == 0) {
        printf("\nThe contact names are the same/already exists please change the contact name\n");
       return 0;
    } else {
        printf("\nThe contact names are different.\n");
    }

    
    printf("Enter the first contact's email: ");
    fgets(contact1.email, sizeof(contact1.email), stdin);
    contact1.email[strcspn(contact1.email, "\n")] = '\0'; 
 
    printf("Enter the second contact's email: ");
    fgets(contact2.email, sizeof(contact2.email), stdin);
    contact2.email[strcspn(contact2.email, "\n")] = '\0'; 


    printf("Enter the first contact's phone number: ");
    fgets(contact1.phone, sizeof(contact1.phone), stdin);
    contact1.phone[strcspn(contact1.phone, "\n")] = '\0'; 

   

    printf("Enter the second contact's phone number: ");
    fgets(contact2.phone, sizeof(contact2.phone), stdin);
    contact2.phone[strcspn(contact2.phone, "\n")] = '\0'; 

 
   

    copyContactDetails(contact1.name, copiedName);
    printf("\nCopied contact name: %s\n", copiedName);

    printf("\nLength of the first contact's name: %d\n", nameLength(contact1.name));
    printf("Length of the second contact's name: %d\n", nameLength(contact2.name));

  
    concatenateContactInfo(contact1.name, contact1.email, contact1.phone, contactDetails);
    printf("\nFull contact details for contact 1: %s\n", contactDetails);

    concatenateContactInfo(contact2.name, contact2.email, contact2.phone, contactDetails);
    printf("\nFull contact details for contact 2: %s\n", contactDetails);

    return 0;
}
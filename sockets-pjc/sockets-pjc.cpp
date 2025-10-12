// sockets-pjc.cpp : Defines the entry point for the application.
// 

#include "sockets-pjc.h"

// main function to handle all section by choice

void painel() {
    printf("\n\t********************************Menu********************************:\n");
    printf("1. Section0\n");
    printf("2. Section1\n");
    printf("3. Section2\n");
    printf("4. Section3\n");
    printf("5. Section4\n");
    printf("6. Quit\n");
    printf("\n");
}

int main()
{
    s::so s;
    int choice;
    
    if (painel) {
        painel();
    }

    printf("Make your section choice\n");
    printf("Choice: ");

	std::cin >> choice;

    switch (choice)
    {

    case 0:
        s.run(); break;
    
    case 1:
        break;
    
    default:
        break;
    
    }

	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>


void print_info_zone(void* adr){
	/**Pour lire la zone en paquet de 8 octets
	 * et récupérer des tailles de zones
	 */
	size_t* info_adr = (size_t*) adr;
	/*Affichage de l'adresse hexadécimale de la zone*/
	printf("Zone a l’adresse : %p\n" , adr);
	/*Affichage d'une taille juste avant la zone*/
	printf("%lu \n", info_adr[-1]);
	/*Affichage d'une taille deux cases avant la zone*/
	printf("%lu \n", info_adr[-2 ]);
}

int main(int argc, char *argv[]){
	char *t = "yolo";
	print_info_zone(t);
	return EXIT_SUCCESS;
}

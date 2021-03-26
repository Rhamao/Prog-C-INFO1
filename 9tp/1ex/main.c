#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <limits.h>
#include <errno.h>
#include "int_array.h"

int main(int argc, char *argv[]){
    int *t =  NULL;
    int size;
	int base;
	char *endptr, *str;
	long val;

	str = argv[1];
	base = 10;

	errno = 0;    /* Pour distinguer la réussite/échec après l'appel */
	val = strtol(str, &endptr, base);

	/* Vérification de certaines erreurs possibles */

	if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN))
			|| (errno != 0 && val == 0)) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}

	if (endptr == str) {
		fprintf(stderr, "Pas de chiffre trouvé\n");
		exit(EXIT_FAILURE);
	}else{
		size = (int) val;
		t = create_int_array(size);
		fill_array(t, size);
		print_int_array(t, size);

		free_int_array(t);
	}

	return EXIT_SUCCESS;
}

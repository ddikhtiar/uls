#include "uls.h"

char **mx_flags_arr(char **arr) {
	char **flgs = NULL;
	int num_flgs = mx_number_of_flags(arr);

	if (num_flgs != 0) {
		flgs = (char **) malloc(sizeof(char *) * (num_flgs + 1));
		for (int i = 0; i < num_flgs; i++)
			flgs[i] = mx_strdup(arr[i + 1]);
		flgs[num_flgs] = NULL;
	}
	return flgs;
}

#include "main.h"

/**
 * freedouble - frees double pointers or 2D arrays
 * @db: double pointer to be freed
*/
void freedouble(char **db)
{
	int i = 0;

	if (!db)
		return;
	while (db[i])
	{
		free(db[i]);
		i++;
	}
}

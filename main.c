/*
 * Copyright (c) 2020, Olivier Valentin
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <stdio.h>
#include <stdlib.h>

#include "interpreter.h"

long fsize ( FILE *fp );

int main ( int argc, char * const argv[] ) {
	if ( argc == 2 )
	{
		FILE * fp = fopen ( argv [ 1 ], "r" );
		if ( fp != NULL )
		{
			long size = fsize ( fp );
			if ( size > 0 )
			{
				char * sourcecode = malloc ( size );
				int bytesread = fread( sourcecode, 1, size, fp );
				if ( bytesread > 0 )
				{
					execute_at ( sourcecode );
				}
				free ( sourcecode );
			}
		}
	}
	else
	{
		execute();
	}
}

long fsize ( FILE *fp ) 
{
    fseek ( fp, 0, SEEK_END );
    long bytes = ftell ( fp );
    rewind ( fp );
    return bytes;
}
/*
 * This file has been modified as part of the FreeMiNT project. See
 * the file Changes.MH for details and dates.
 */

/*
 * Copyright 1991,1992 Eric R. Smith.
 * Copyright 1992,1993,1994 Atari Corporation.
 * All rights reserved.
 */

# ifndef _mint_file_h
# define _mint_file_h

struct file
{
	short	links;		/* number of copies of this descriptor */
	ushort	flags;		/* file open mode and other file flags */
	long	pos;		/* position in file */
	long	devinfo;	/* device driver specific info */
	fcookie	fc;		/* file system cookie for this file */
	DEVDRV	*dev;		/* device driver that knows how to deal with this */
	FILEPTR	*next;		/* link to next fileptr for this file */
};


/* macros to be applied to FILEPTRS to determine their type */
# define is_terminal(f) ((f)->flags & O_TTY)


# endif /* _mint_file_h */

/*******************************************************************************
*
* Copyright (c) 2019
* Bug Eater Development Team.
* All rights reserved.
*
* Developed by Cristian Campuzano (cristian_canek@hotmail.com).
*
*******************************************************************************/

/*******************************************************************************
                                 INCLUDE HEADERS
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/*******************************************************************************
                     DEFINES, CONSTANTS AND GLOBAL VARIABLES
*******************************************************************************/

/* -------------------------------- DEFINES --------------------------------- */

/* The maximum length allowed for the name of the configuration file. */
#define MAX_CONFIG_FILE_NAME_LENGTH ( 128 )

/* The maximum length allowed for the name of the program. */
#define MAX_PROGRAM_NAME_LENGTH     ( 128 )


/* ------------------------------- CONSTANTS -------------------------------- */

/* Configuration file to be used in case the user does not specify none. */
static const char *DEFAULT_CONFIG_FILE = "default_config_file.json";

/* Valid optional flags gotten as parameters. */
static const char *OPTIONAL_FLAGS = "f:";


/* ---------------------------- GLOBAL VARIABLES ---------------------------- */


/*******************************************************************************
                              FUNCTION DECLARATIONS
*******************************************************************************/

/* Prints the usage help into the stderr output.
 *
 * Parameters:
 *   const char *argv0 : Input : The command used to call this program.
 */

static void printUsage (const char *argv0);


/*******************************************************************************
                                  MAIN PROGRAM
*******************************************************************************/

/* The main function. Here is where the magic starts. */
int main (int argc, char **argv) {

  /* The config (options) file to be used for debugging the program. */
  char config_file[MAX_CONFIG_FILE_NAME_LENGTH] = { 0 };

  /* The program to be debugged. */
  char program[MAX_PROGRAM_NAME_LENGTH] = { 0 };

  /* The character returned by the getopt function. */
  int option;

  /* Indicates if there is a syntax error calling the program. */
  int errflg = 0;

  /* Parse the argv input parameter to get the optional flags. */
  while ((option = getopt(argc, argv, OPTIONAL_FLAGS)) != -1) {
    switch (option) {
      /* Input configuration file. */
      case 'f':
        strcpy(config_file, optarg);
      break;

      /* -f without operand. */
      case ':':
        fprintf (stderr, "Option -%c requires an operand\n", optopt);
        errflg++;
      break;

      /* Invalid option. */
      case '?':
        fprintf (stderr, "Unrecognized option: '-%c'\n", optopt);
        errflg++;
    }
  }

  /* Less arguments than required. */
  if (argc - optind < 1) {
    fprintf (stderr, "%s: too few arguments\n", argv[0]);
    errflg++;
  }
  else {
    /* Save the name of the program to be debugged. */
    sprintf (program, "./%s", argv[optind++]);
  }

  /* Print the usage message in case of wrong call to the program. */
  if (errflg) {
    printUsage (argv[0]);
  }

  /* Use the default configuration file if none was given. */
  if (0 == strlen(config_file)) {
    strcpy(config_file, DEFAULT_CONFIG_FILE);
  }

  /* Execute the program received by parameters. */
  system(program);

  return 0;
}


/*******************************************************************************
                              FUNCTION DEFINITIONS
*******************************************************************************/

/* Prints the usage help into the stderr output.
 *
 * Parameters:
 *   const char *argv0 : Input : The name of the main program.
 */

static void printUsage (const char *argv0) {
  fprintf (stderr, "Usage: %s [-f config_file] program\n", argv0);
  exit (EXIT_FAILURE);
}

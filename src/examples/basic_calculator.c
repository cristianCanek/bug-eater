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
#include <unistd.h>


/*******************************************************************************
                     DEFINES, CONSTANTS AND GLOBAL VARIABLES
*******************************************************************************/

/* -------------------------------- DEFINES --------------------------------- */


/* ------------------------------- CONSTANTS -------------------------------- */

/* Valid optional flags gotten as parameters. */
static const char *OPTIONAL_FLAGS = "a:b:";


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

int main (int argc, char **argv) {

  /* The character returned by the getopt function. */
  int option;

  /* Indicates if there is a syntax error calling the program. */
  int errflg = 0;

  /* First operand. */
  float a = 0.0;

  /* Second operand. */
  float b = 0.0;

  /* Operator. */
  char op = 0;

  /* Parse the argv input parameter to get the optional flags. */
  while ((option = getopt(argc, argv, OPTIONAL_FLAGS)) != -1) {
    switch (option) {
      /* Operand a. */
      case 'a':
        a = atof(optarg);
      break;

      /* Operand b. */
      case 'b':
        b = atof(optarg);
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
    /* Save the operation required. */
    op = argv[optind++][0];
    //printf("Operation: %s\n", argv[optind++]);
  }

  /* Print the usage message in case of wrong call to the program. */
  if (errflg) {
    printUsage (argv[0]);
  }

  /* Perform the requested operation. */
  switch(op) {
    case '+':
      printf ("%f + %f = %f\n", a, b, a + b);
    break;

    case '-':
      printf ("%f - %f = %f\n", a, b, a - b);
    break;

    case 'x':
      printf ("%f x %f = %f\n", a, b, a * b);
    break;

    case '/':
      if (0.0 != b) {
        printf ("%f / %f = %f\n", a, b, a / b);
      }
      else {
        fprintf (stderr, "Division by 0 has an undefined result.\n");
        exit (EXIT_FAILURE);
      }

    break;
  }

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
  fprintf (stderr, "Usage: %s [-a -b] operator\n", argv0);
  fprintf (stderr, "\ta, b : first and second float operands (in that order)\n");
  fprintf (stderr, "\toperator : operation to be performed (+, -, x, /)\n");
  exit (EXIT_FAILURE);
}

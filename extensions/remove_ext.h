/**if not already defined
*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
*/
#include <libgen.h>

/**
 * @author paxdiablo@stackoverflow.com
 * @source http://stackoverflow.com/questions/2736753/how-to-remove-extension-from-file-name
 */
// remove_ext: removes the "extension" from a file spec.
//   mystr is the string to process.
//   dot is the extension separator.
//   sep is the path separator (0 means to ignore).
// Returns an allocated string identical to the original but
//   with the extension removed. It must be freed when you're
//   finished with it.
// If you pass in NULL or the new string can't be allocated,
//   it returns NULL.

char *remove_ext (char* mystr, char dot, char sep) {
    char *retstr, *lastdot, *lastsep;
    
    // Error checks and allocate string.

    if (mystr == NULL)
        return NULL;
    if ((retstr = malloc (strlen (mystr) + 1)) == NULL)
        return NULL;

    // Make a copy and find the relevant characters.

    strcpy (retstr, mystr);
    lastdot = strrchr (retstr, dot);
    lastsep = (sep == 0) ? NULL : strrchr (retstr, sep);

    // If it has an extension separator.

    if (lastdot != NULL) {
        // and it's before the extenstion separator.

        if (lastsep != NULL) {
            if (lastsep < lastdot) {
                // then remove it.

                *lastdot = '\0';
            }
        } else {
            // Has extension separator with no path separator.

            *lastdot = '\0';
        }
    }

    // Return the modified string.

    return retstr;
}

/********************
 * usage
 * *******************
    char *s;
    printf ("[%s]\n", (s = remove_ext ("hello", '.', '/'))); free (s);
    printf ("[%s]\n", (s = remove_ext ("hello.", '.', '/'))); free (s);
    printf ("[%s]\n", (s = remove_ext ("hello.txt", '.', '/'))); free (s);
    printf ("[%s]\n", (s = remove_ext ("hello.txt.txt", '.', '/'))); free (s);
    printf ("[%s]\n", (s = remove_ext ("/no.dot/in_path", '.', '/'))); free (s);
    printf ("[%s]\n", (s = remove_ext ("/has.dot/in.path", '.', '/'))); free (s);
    printf ("[%s]\n", (s = remove_ext ("/no.dot/in_path", '.', 0))); free (s);
 */

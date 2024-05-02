
/*
 ▄████████                 ▄█        ▄█  ▀█████████▄     ▄████████    ▄████████    ▄████████ ▄██   ▄   
███    ███                ███       ███    ███    ███   ███    ███   ███    ███   ███    ███ ███   ██▄ 
███    █▀                 ███       ███▌   ███    ███   ███    ███   ███    ███   ███    ███ ███▄▄▄███ 
███                       ███       ███▌  ▄███▄▄▄██▀   ▄███▄▄▄▄██▀   ███    ███  ▄███▄▄▄▄██▀ ▀▀▀▀▀▀███ 
███                       ███       ███▌ ▀▀███▀▀▀██▄  ▀▀███▀▀▀▀▀   ▀███████████ ▀▀███▀▀▀▀▀   ▄██   ███ 
███    █▄                 ███       ███    ███    ██▄ ▀███████████   ███    ███ ▀███████████ ███   ███ 
███    ███                ███▌    ▄ ███    ███    ███   ███    ███   ███    ███   ███    ███ ███   ███ 
████████▀                 █████▄▄██ █▀   ▄█████████▀    ███    ███   ███    █▀    ███    ███  ▀█████▀  
                          ▀                             ███    ███                ███    ███           
*/

/**
 * @author - default_ (Arthur Clemente Machado)
 * @version - 0.1
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*

   ▄████████    ▄█    █▄       ▄████████    ▄▄▄▄███▄▄▄▄   ▀█████████▄   ▄█          ▄████████    ▄████████ 
  ███    ███   ███    ███     ███    ███  ▄██▀▀▀███▀▀▀██▄   ███    ███ ███         ███    ███   ███    ███ 
  ███    █▀    ███    ███     ███    ███  ███   ███   ███   ███    ███ ███         ███    █▀    ███    █▀  
  ███         ▄███▄▄▄▄███▄▄   ███    ███  ███   ███   ███  ▄███▄▄▄██▀  ███        ▄███▄▄▄       ███        
▀███████████ ▀▀███▀▀▀▀███▀  ▀███████████  ███   ███   ███ ▀▀███▀▀▀██▄  ███       ▀▀███▀▀▀     ▀███████████ 
         ███   ███    ███     ███    ███  ███   ███   ███   ███    ██▄ ███         ███    █▄           ███ 
   ▄█    ███   ███    ███     ███    ███  ███   ███   ███   ███    ███ ███▌    ▄   ███    ███    ▄█    ███ 
 ▄████████▀    ███    █▀      ███    █▀    ▀█   ███   █▀  ▄█████████▀  █████▄▄██   ██████████  ▄████████▀  
                                                                       ▀                                   
*/

/*
 * Function: shambles
 * -------------------
 * Replaces all occurrences of oldString in str with newString in all the existance.
 *
 * oldString: The string to be replaced.
 * newString: The string to replace oldString with.
 * str: The string to search and perform replacements on.
 *
 * Returns:
 *   A pointer to a dynamically allocated string containing the modified string.
 *   It's the caller's responsibility to free the memory allocated for the returned string.
 */
char *shambles(const char *oldString, const char *newString, const char *str)
{
    // variables
    size_t oldLen = strlen(oldString);
    size_t newLen = strlen(newString);
    size_t strLen = strlen(str);
    size_t count = 0;

    const char *tmp = str;
    while ((tmp = strstr(tmp, oldString)))
    { // count all occurrences of oldString in str
        count++;
        tmp += oldLen;
    }

    size_t resultLen = strLen + count * (newLen - oldLen) + 1; // calculate result length
    char *result = (char *)malloc(resultLen);

    char *out = result;
    const char *in = str;
    while (*in)
    {
        // replace oldString with newString in str
        if (strncmp(in, oldString, oldLen) == 0)
        {
            strcpy(out, newString);
            in += oldLen;
            out += newLen;
        }
        else
        {
            *out++ = *in++; // copy str to the result pointer
        }
    }
    *out = '\0';

    return result;
} // end shambles()

/*

████████▄   ▄█     ▄████████    ▄▄▄▄███▄▄▄▄      ▄████████ ███▄▄▄▄       ███      ▄█          ▄████████ 
███   ▀███ ███    ███    ███  ▄██▀▀▀███▀▀▀██▄   ███    ███ ███▀▀▀██▄ ▀█████████▄ ███         ███    ███ 
███    ███ ███▌   ███    █▀   ███   ███   ███   ███    ███ ███   ███    ▀███▀▀██ ███         ███    █▀  
███    ███ ███▌   ███         ███   ███   ███   ███    ███ ███   ███     ███   ▀ ███        ▄███▄▄▄     
███    ███ ███▌ ▀███████████  ███   ███   ███ ▀███████████ ███   ███     ███     ███       ▀▀███▀▀▀     
███    ███ ███           ███  ███   ███   ███   ███    ███ ███   ███     ███     ███         ███    █▄  
███   ▄███ ███     ▄█    ███  ███   ███   ███   ███    ███ ███   ███     ███     ███▌    ▄   ███    ███ 
████████▀  █▀    ▄████████▀    ▀█   ███   █▀    ███    █▀   ▀█   █▀     ▄████▀   █████▄▄██   ██████████ 
                                                                                 ▀                      
*/

/*
   Function: numOfChar
   Description: Counts the number of occurrences of a character in a string.
   Parameters:
       regex - The character to count occurrences of.
       str - The string to search within.
   Returns:
       The count of occurrences of the character plus one.
*/
size_t numOfChar(char regex, char* str)
{
    size_t x = 0, y = 0;
    size_t size = strlen(str); // Calculate the length of the string
    for (x = 0; x < size; x++) // Loop through each character in the string
    {
        if (str[x] == regex) // Check if the current character matches the given character
        {
            y++; // Increment the count of occurrences
        }
    }
    return y + 1; // Return the count of occurrences plus one
}

/*
   Function: dismantle
   Description: Splits a string by a given character delimiter into an array of strings.
   Parameters:
       regex - The character to split the string by.
       str - The string to be split.
   Returns:
       An array of strings containing the split substrings.
*/
char* *dismantle(char regex, char* str)
{
    size_t size = numOfChar(regex, str); // Get the size of the output array
    char**output = (char**)malloc(size * sizeof(char*)); // Allocate memory for the output array
    for (size_t i = 0; i < size; i++)
    {
        output[i] = (char*)malloc(200 * sizeof(char));
    }

    int x = 0, y = 0, z = 0;

    while (str[x] != '\0') // Loop until the end of the string
    {
        if (str[x] == regex) // Check if the current character matches the delimiter
        {
            output[y][z] = '\0'; // Terminate the current substring

            y++; // Move to the next substring
            z = 0; // Reset the index for the next substring
            if ((str[x + 1] == regex) || (str[x + 1] == '\0') || (str[x + 1] == '\n')) // Check if the next character is also a delimiter or the end of the string
            {
                x++; // Skip the next character
                y++; // Move to the next substring
            }
        }
        else
        {
            if (str[x] != '\n') // Check if the current character is not a newline character
            {
                output[y][z] = str[x]; // Copy the character to the current substring
                z++; // Move to the next position in the current substring
            }
        }
        x++; // Move to the next character in the string
    }

    return output; // Return the array of split substrings
} // end dismantle()

/*
    ███        ▄█    █▄       ▄████████         ▄█    █▄       ▄████████ ███▄▄▄▄   ████████▄  
▀█████████▄   ███    ███     ███    ███        ███    ███     ███    ███ ███▀▀▀██▄ ███   ▀███ 
   ▀███▀▀██   ███    ███     ███    █▀         ███    ███     ███    ███ ███   ███ ███    ███ 
    ███   ▀  ▄███▄▄▄▄███▄▄  ▄███▄▄▄           ▄███▄▄▄▄███▄▄   ███    ███ ███   ███ ███    ███ 
    ███     ▀▀███▀▀▀▀███▀  ▀▀███▀▀▀          ▀▀███▀▀▀▀███▀  ▀███████████ ███   ███ ███    ███ 
    ███       ███    ███     ███    █▄         ███    ███     ███    ███ ███   ███ ███    ███ 
    ███       ███    ███     ███    ███        ███    ███     ███    ███ ███   ███ ███   ▄███ 
   ▄████▀     ███    █▀      ██████████        ███    █▀      ███    █▀   ▀█   █▀  ████████▀                                                                             
*/

/* Function to trim leading and trailing whitespaces from a string */
char *theHand(char *str)
{
    char *end;

    // Skip leading whitespaces
    while (isspace((unsigned char)*str))
        str++;

    // If the entire string is whitespaces, return the string itself
    if (*str == 0)
        return str;

    // Find the end of the string
    end = str + strlen(str) - 1;
    // Trim trailing whitespaces
    while (end > str && isspace((unsigned char)*end))
        end--;

    // Null-terminate the string after the last non-whitespace character
    end[1] = '\0';

    // Return the trimmed string
    return str;
} // end theHand ( )
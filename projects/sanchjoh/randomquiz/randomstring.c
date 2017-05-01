/*

Johnny Sanchez
CS 362
04/30/2017


  The approach that I took to making this unit test was to come up with different cases using a switch statement.  This appoach is randomized in the sense that the random number generator will only iterate through all of the options for the characters.

  The test also has an additional level of randomness due to the randomization  of the string that is passed on by the inputString function.  I could have added more switch statements to it, but I believe that the problem itself demonstrates random testing.  Had I made more cases for the string that is passed by the function, then the program would have iterated more times before reaching the error code.

  It is important to note that for this test, we wanted the program to exit abnormally, so one of the input strings had to be the same one that would eventually trigger the error.  The string that would produce the error was "reset", and thus it was hard-coded into the testing program.

  I would imagine that we would probably use a more randomized solution to test a program, with the purpose of testing for input that is not supposed to occur.

  The way the solution works is that the program will randomly spit out a character that is picked from the list of characters that will trigger an effect, as seen by the control structions within the test me function.  Next, the program will also generate a random string picked from a list, and then compare that string to the series of characters that will cause the error code to manifest itself.

*/

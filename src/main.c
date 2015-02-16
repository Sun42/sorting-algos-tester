#include <stdlib.h>
#include <stdio.h>
#include "words.h"

void	bubbleSort(t_words *s_words)
{
  int j;
  int i;
  char *tmp;

  for (j = s_words->cpt - 1; j >= 0; j--)
    {
      fprintf(stdout, "j %i \n", j);
      for (i = 0; i < j ;i++)
	{
	  if (strcmp(s_words->words[i], s_words->words[j]) > 0)
	    {
	      // fprintf(stdout, "SWAP %s with %s \n", s_words->words[i], s_words->words[j]);;
	      tmp = s_words->words[i];
	      s_words->words[i] = s_words->words[j];
	      s_words->words[j] = tmp;
	    }
	}
    }
}


int	main(int argc, char **argv)
{
  if (argc != 2)
    {
      fprintf(stderr, "usage ./sort filetosort \n");
      exit(1);
    }
  t_words *s_words;

  s_words = fileToWords(argv[1]);
  displayWords(s_words);
  fprintf(stdout, "sorting... \n");
  bubbleSort(s_words);

  displayWords(s_words);
  freeWords(s_words);
  exit(EXIT_SUCCESS);
}

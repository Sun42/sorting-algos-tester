#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "words.h"

// error return -1
int	countLines(const char *path)
{
  FILE *fp;
  int	c;
  int	ct_lines;
  ct_lines = 0;
  fp = fopen(path, "rb");
  if (fp == NULL)
    return -1;
  do {
    c = fgetc(fp);
    if (c == '\n')
      ct_lines++;
  } while (c != EOF);
  fclose(fp);
  return ct_lines;
}

void	displayWords(const t_words *s_words)
{
  int	i;

  if (s_words != NULL && s_words->words != NULL)
    {
      fprintf(stdout, "Number of words : %i \n", s_words->cpt);
      fprintf(stdout, "Word length is : %i \n", s_words->len);
      for (i = 0; i < s_words->cpt; ++i)
	{
	  fprintf(stdout, "%s\n", s_words->words[i]);
	}
    }
}

char	**getWords(const char *path, int nb_lines)
{
  char		**words;
  FILE		*file;
  char		*line = NULL;
  size_t	len = 0;
  ssize_t	read;
  int		i;
  int len_to_copy;

  words = malloc(nb_lines * sizeof(char *));
  if (words == NULL)
    {
      fprintf(stderr, "error malloc \n");
      return NULL;
    }
  i = 0;
  file = fopen(path, "r");
  if (file == NULL)
    {
      fprintf(stderr, "error opening file %s \n", path);
      return NULL;
    }
  while ((read = getline(&line, &len, file)) != -1)
    {
      if (line[read - 1] == '\n')
	len_to_copy = read - 1;
      else
	len_to_copy = read;
      words[i] = strndup(line, read - 1);
      i++;
    }
  free(line);
  fclose(file);
  return words;
}

void	freeWords(t_words *s_words)
{
  int i;
  if (s_words == NULL)
    return ;
  for (i = 1; i < s_words->cpt; ++i)
    {
      free(s_words->words[i]);
    }
  free (s_words);
}

t_words *fileToWords(const char *path)
{
  t_words	*s_words;


  s_words = malloc(sizeof(t_words));
  if (s_words == NULL)
    {
      fprintf(stderr, "malloc error");
      return NULL;
    }

  s_words->cpt = countLines(path);
  s_words->words = getWords(path, s_words->cpt);
  if (s_words->words == NULL)
    return NULL;
  s_words->len = strlen(s_words->words[0]);
  return s_words;
}

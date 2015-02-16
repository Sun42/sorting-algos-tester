#ifndef _H_WORDS_H_
 #define _H_WORDS_H_

typedef struct s_words
{
  int cpt; // number of words
  int len; // words length
  char **words;
} t_words;


int	countLines(const char *path);
char	**getWords(const char *path, int nb_lines);
void	displayWords(const t_words *s_words);
t_words	*fileToWords(const char *path);
void	wordsToFile(const char *path, t_words *s_words);
void	freeWords(t_words *s_words);
#endif // _H_WORDS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 128
#define WLEN 16
#define MAXPASSPORTS 500

struct proto_passport
{
	char section[8][WLEN];
	int filled_sections;
}
passport[MAXPASSPORTS];

int pass_no;

char eye_color[7][WLEN] = { "amb", "blu", "brn", "gry", "grn", "hzl", "oth" };

int is_digit(char *word)
{
	int len = strlen(word);
	for (int i = 0; i < len; i++)
		if (word[i]<'0' || word[i] > '9')
			return 0;
	return 1;
}

int is_hex(char *word)
{
	int len = strlen(word);
	if (len != 7) return 0;
	if (word[0] == '#')
	{
		for (int i = 1; i < 7; i++)
			if ((word[i]<'0' || word[i] > '9') && (word[i]<'a' || word[i] > 'f'))
				return 0;
		return 1;
	}
	return 0;
}

int check_validity(int section_no, int pass_no)
{
	int value;
	char word[WLEN];
	strcpy(word, passport[pass_no].section[section_no]);
	int len = strlen(word);

	switch (section_no)
	{
		case 0:
			if (len != 4) return 0;
			if (!is_digit(word)) return 0;
			value = atoi(word);
			if (value < 1920 || value > 2002)
				return 0;
			return 1;

		case 1:
			if (len != 4) return 0;
			if (!is_digit(word)) return 0;
			value = atoi(word);
			if (value < 2010 || value > 2020)
				return 0;
			return 1;

		case 2:
			if (len != 4) return 0;
			if (!is_digit(word)) return 0;
			value = atoi(word);
			if (value < 2020 || value > 2030)
				return 0;
			return 1;

		case 3:
			if (word[len - 1] == 'n' && word[len - 2] == 'i')
			{
				value = atoi(word);
				if (value < 59 || value > 76) return 0;
				else return 1;
			}
			if (word[len - 1] == 'm' && word[len - 2] == 'c')
			{
				value = atoi(word);
				if (value < 150 || value > 193) return 0;
				else return 1;
			}
			return 0;

		case 4:
			if (is_hex(word)) return 1;
			else return 0;

		case 5:
			for (int i = 0; i < 7; i++)
				if (strcmp(word, eye_color[i]) == 0)
					return 1;
			return 0;

		case 6:
			if (len != 9) return 0;
			if (is_digit(word)) return 1;
			return 0;

		case 7:
			return 1;
	}

	return 0;
}

int name_to_number(char *name)
{
	switch (name[0])
	{
		case 'b':
			return 0;
		case 'i':
			return 1;
		case 'p':
			return 6;
		case 'c':
			return 7;
		case 'h':
			switch (name[1])
			{
				case 'g':
					return 3;
				case 'c':
					return 4;
			}
		case 'e':
			switch (name[1])
			{
				case 'y':
					return 2;
				case 'c':
					return 5;
			}
	}
	return 0;
}

char *number_to_name(int n)
{
	switch (n)
	{
		case 0:
			return "byr";
		case 1:
			return "iyr";
		case 2:
			return "eyr";
		case 3:
			return "hgt";
		case 4:
			return "hcl";
		case 5:
			return "ecl";
		case 6:
			return "pid";
		case 7:
			return "cid";
	}
	return NULL;
}

void insert_item_in_passport(char *line, int pass_no)
{
	int name;
	char *token;

	token = strtok(line, ":");

	while (token != NULL)
	{
		name = name_to_number(token);

		token = strtok(NULL, " ");
		strcpy(passport[pass_no].section[name], token);

		if (name != 7)
			passport[pass_no].filled_sections++;

		token = strtok(NULL, ":");
	}

	return;
}

int main()
{
	char line[LEN];

	while (fgets(line, LEN, stdin) != NULL)
	{
		int len = strlen(line);
		if (line[len - 1] == '\n' || line[len - 1] == EOF)
			line[len - 1] = 0;

		if (len < 2)
			pass_no++;
		else
			insert_item_in_passport(line, pass_no);
	}

	int valid = 0;
	int flag;
	for (int i = 0; i < pass_no; i++)
	{
		if (passport[i].filled_sections == 7)
		{
			flag = 1;
			for (int j = 0; j < 8; j++)
				if (!check_validity(j, i))
				{
					flag = 0;
					break;
				}
			if (flag) valid++;
		}
	}

	printf("%d\n", valid);

	return 0;
}

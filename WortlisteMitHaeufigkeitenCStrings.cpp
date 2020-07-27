#include <iostream>

using namespace std;

struct w_haeufigkeit
{
	char* wort;
	unsigned int haeufigkeit;
};

unsigned int my_strlen(const char * ptr)
{
	int i = 0;
	for (; ; i++)
	{
		if (ptr[i] == '\0')
		{
			break;
		}
	}
	return i;
}

int my_strcmp(const char * ptr1, const char * ptr2)
{
	unsigned int ptr1_len = my_strlen(ptr1);
	unsigned int ptr2_len = my_strlen(ptr2);
	unsigned int i = 0;
	if (ptr1_len == ptr2_len)
	{
		for (; i < ptr1_len; i++)
		{
			if (ptr1[i] != ptr2[i])
			{
				break;
			}
		}
	}
	if (i == ptr1_len && i == ptr2_len)
	{
		return 0;
	}
	else if (ptr1_len < ptr2_len)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

char* naechstes_wort(const char* const zeile, unsigned int& pos)
{
	char* naechstes_wort_array;
	for (; pos < my_strlen(zeile); pos++)
	{
		if (zeile[pos] != ' '  && zeile[pos] != '.'&& zeile[pos] != ',' && zeile[pos] != '!'&& zeile[pos] != '?')
		{
			break;
		}
	}
	unsigned int i = pos;
	for (; pos < my_strlen(zeile); pos++)
	{
		if (zeile[pos] == ' ' || zeile[pos] == '.' || zeile[pos] == ',' || zeile[pos] == '!' || zeile[pos] == '?' || zeile[pos] == '\0')
		{
			break;
		}
	}
	int wortlaenge = pos - i + 1;
	naechstes_wort_array = new char[wortlaenge] { 0 };
	int j = 0;
	for (; i < pos; i++, j++)
	{
		if (zeile[i] != ' '  && zeile[i] != '.'&& zeile[i] != ',' && zeile[i] != '!'&& zeile[i] != '?')
		{
			naechstes_wort_array[j] = zeile[i];
		}
		else
		{
			break;
		}
	}
	return naechstes_wort_array;
}

void zaehle_wort(char* wort, struct w_haeufigkeit w_haeufigkeiten[], unsigned int& w_count)
{
			unsigned int z = 0;
			for (; z < w_count; z++)
			{
				if (my_strcmp(wort, w_haeufigkeiten[z].wort) == 0)
				{
					w_haeufigkeiten[z].haeufigkeit++;
					break;
				}
			}

			if (z == w_count)
			{
				w_haeufigkeiten[z].haeufigkeit = 1;
				w_haeufigkeiten[z].wort = wort;
				w_count++;
			}
}

int main()
{
	const unsigned int eingabezeilen_max = 5;
	const unsigned int wort_max = 1000;
	const unsigned int max_line_length = 80;
	char eingabe[eingabezeilen_max][max_line_length] = { 0 };
	w_haeufigkeit haeufigkeiten[wort_max] = { 0 };
	char* wort_aktuell;
	unsigned int pos = 0;
	unsigned int w_count = 0;
	for (int i = 0; i < eingabezeilen_max; i++)
	{
		cout << "Eingabezeile = ? ";
		cin.getline(eingabe[i], max_line_length);
		if (eingabe[i][0] == '\0')
		{
			break;
		}
	}

	for (int i = 0; i < eingabezeilen_max; i++)
	{
		if (eingabe[i][0] == '\0')
		{
			break;
		}
		pos = 0;

		while (true)
		{
			wort_aktuell = naechstes_wort(eingabe[i], pos);
			if (wort_aktuell[0] == '\0')
			{
				break;
			}
			zaehle_wort(wort_aktuell, haeufigkeiten, w_count);
			//cout << wort_aktuell << " Pos = " << pos << " Wortlänge = " << my_strlen(wort_aktuell) << endl;
			unsigned int j = 0;
		}
		//cout << endl;
	}

	for (unsigned int k = 0; k < w_count; k++)
		cout << haeufigkeiten[k].wort << ": "
		<< haeufigkeiten[k].haeufigkeit << endl;
	system("PAUSE");
	return 0;
}
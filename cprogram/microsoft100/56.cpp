#include <cstdio>
#include <cstring>


int lcs(char*, char*);
int max_item(int ,int);
void print_lcs(char** t_simbol, char*, int, int);
int main(int argc, char** argv)
{
	char a[] = "476255";
	char b[] = "245576";	
	int lc = lcs(a,b);
	printf("\n%s\n",a);
	printf("%s\n",b);
	printf("%d \n", lc);

	return 0;
}


int lcs(char* stra, char* strb)
{
	int	lena = strlen(stra);
	int	lenb = strlen(strb);
	
	int table[lena+1][lenb+1];
	
	memset(table, 0, (lena+1)*(lenb+1)*sizeof(int));

	char** t_simbol = new char*[lena+1];
	for(int k=0; k<lena+1; k++)
		t_simbol[k]  = new char[lenb+1];
	
	


	int i,j, left_i, left_j ,up_i, up_j ,left_up_i, left_up_j;

	t_simbol[0][0] = ' ';
	for(i=1; i<=lena; ++i)
		t_simbol[i][0] = stra[i-1];
	for(j=1; j<=lenb; ++j)
		t_simbol[0][j] = strb[j-1];

	for(i=1; i<=lena; i++)
	{
		for(j=1; j<=lenb; j++)
		{
			left_i = i;
			left_j = j-1;
			up_i = i-1;
			up_j = j;
			left_up_i = i-1;
			left_up_j = j-1;
			

			if(*(stra+i-1) == *(strb+j-1))
			{
				table[i][j] = table[left_up_i][left_up_j] + 1;
				t_simbol[i][j] = 'c';
			}

			else
			{
				if(table[left_i][left_j] > table[up_i][up_j])
				{
					table[i][j] = table[left_i][left_j];
					t_simbol[i][j] = 'l';
				}
				else
				{

					table[i][j] = table[up_i][up_j];
					t_simbol[i][j] = 'u';
				}
			}
			

		}
	}




	for(i=0; i<=lena; i++)
	{
		for(j=0; j<=lenb; j++)
		{
				printf("%d ", table[i][j]);
				if(j == lenb)
					printf("\n");
		}
	}
	
	printf("\n");

	for(i=0; i<=lena; i++)
	{
		for(j=0; j<=lenb; j++)
		{
				printf("%c ", t_simbol[i][j]);
				if(j == lenb)
					printf("\n");
		}
	}
	print_lcs(t_simbol, stra, lena, lenb);

	for(int m=0; m<lena+1; m++)
		delete[] t_simbol[m];
	delete t_simbol;
	return table[lena][lenb];
}

void print_lcs(char** t_simbol, char* a, int i, int j)
{
	// termination condition
	//
	if(i==0 || j ==0)
	{
		printf("\n");
		return;
	}

	// recursive function call
	if(t_simbol[i][j] == 'c')
	{
		print_lcs(t_simbol, a, i-1, j-1);
		printf("%c", a[i-1]);
	}
	else if(t_simbol[i][j] == 'l')
	{
		print_lcs(t_simbol, a, i, j-1);
	}
	else
	{
		print_lcs(t_simbol, a, i-1, j);
	}
}




int max_item(int a, int b)
{
	return a<b?b:a;
}


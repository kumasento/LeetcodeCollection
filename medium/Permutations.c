
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Return an array of int arrays with *m as the array size */
/* The sizes of int arrays are returned in *lens */
void permute_dfs(int *numbers, int n, int *used, int *index, int pos,
                    int ***ret, int *row)
{
    int i;
    if (pos == n)
    {
        int *ans = (int *) malloc(sizeof(int) * n);
        for (i = 0; i < n; i++)
            ans[i] = numbers[index[i]];
        (*row) ++;
        int **tmp = (int **) malloc(sizeof(int*) * (*row));
        tmp[(*row)-1] = ans;
        if (*row != 1)
        {
            for (i = 0; i < *row-1; i++)
                tmp[i] = (*ret)[i];
            free(*ret);
        }
        *ret = tmp;

        return ;
    }
    for (i = 0; i < n; i++)
    {
        if (used[i]) continue;
        used[i] = 1;
        index[pos] = i;
        permute_dfs(numbers, n, used, index, pos+1, ret, row);
        used[i] = 0;
    }
}
int **permute(int *numbers, int n, int *row)
{
    int **ret = NULL;
    int *used = (int *) malloc(sizeof(int) * n);
    int *index = (int *) malloc(sizeof(int) * n);
    *row = 0;
    memset(used, 0, sizeof(int) * n);
    permute_dfs(numbers, n, used, index, 0, &ret, row);
    free(used);
    free(index);

    return ret;
}

int main()
{
    int n1, i;
    int *a1;
    FILE *fp = fopen("Permutations.out", "w");
    while (scanf("%d", &n1) != EOF)
    {
        a1 = (int *) malloc(sizeof(int) * n1);
        for (i = 0; i < n1; i++)
            scanf("%d", &a1[i]);
        int row = 0;
        int **ret = permute(a1, n1, &row);

        fprintf(fp, "[");
        int i, j;
        for (i = 0; i < row; i++)
        {
            fprintf(fp, "[");
            for (j = 0; j < n1; j++)
            {
               fprintf(fp, "%d", ret[i][j]);
               if (j != n1-1)
                   fprintf(fp, ",");
            }
            fprintf(fp, "]");
            if (i != row-1)
                fprintf(fp, ",");
        }
        fprintf(fp, "]\n");

    }

    return 0;
}

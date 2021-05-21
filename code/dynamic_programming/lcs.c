int LCSrec(i, j)
{
    if (i == 0 && j == 0)
        return 0;
    else if (x[i] == y[j])
    {
        return LCSrec(i - 1, j - 1) + 1
    }
    else
        return max(LCSrec(i - 1, j), LCSrec(i, j - 1))
}

int LCSmemo(i, j)
{
    if (i == 0 && j == 0)
        return 0;
    else if (c[i][j] < n + m)
        return c[i][j];
    else if (x[i] == y[j])
    {
        c[i][j] = LCSmemo(i - 1, j - 1) + 1;
        return c[i][j];
    }
    else
    {
        c[i][j] = max(LCSmemo(i - 1, j), LCSmemo(i, j - 1));
        return c[i][j]
    }

    int printLCS(x, y, i, j)
    {
        if (i == 0 && j == 0)
            return;
        if (c[i, j] > c[i - 1, j] && c[i, j] > c[i, j - 1])
        {
            printLCS(x, y, i - 1, j - 1);
            printf("%c", x[i])
        }
        else if (c[i, j] == c[i - 1, j])
        {
            printLCS(x, y, i - 1, j)
        }
        else
            printLCS(x, y, i, j - 1)
    }
}

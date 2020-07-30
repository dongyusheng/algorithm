bool Find(int* matrix, int rows, int columns, int number)
{
    if ((matrix != nullptr) && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns - 1;
        while (row < rows&&column >= 0)
        {
            if (matrix[row*columns + column] == number)
                return true;
            else if (matrix[row*columns + column]>number)
                --column;
            else
                ++row;
        }
        return false;
    }
    return false;
}

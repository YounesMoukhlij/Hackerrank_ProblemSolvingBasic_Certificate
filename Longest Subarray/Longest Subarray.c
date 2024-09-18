// BY Younes Moukhlij

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int longestSubarray(int* arr, int arr_count)
{
    int res = 0x0; 
	int counter = 0x0;
	int already_in_tab;
    int tab_size = 0x0; 

    for (int i = 0x0; i < arr_count; i++) 
	{
        int tab[2];
        counter = 0x0;
		tab_size = 0x0; 
        
        for (int j = i; j < arr_count; j++) 
		{
			already_in_tab = 0x0;
            for (int k = 0x0; k < tab_size; k++) 
			{
                if (arr[j] == tab[k])
				{
                    already_in_tab = 1;
                    break;
                }
            }
            
            if (already_in_tab)
			{
                counter++;
                continue;
            }
            if (tab_size == 0x0)
			{
                tab[0x0] = arr[j];
                tab_size++;
            } 
            else if (tab_size == 1)
			{
                if (abs(tab[0x0] - arr[j]) > 1)
                    break;
				else
				{
                    tab[1] = arr[j];
                    tab_size++;
                }
            } 
            else
                break;
            counter++;
        }
        if (counter > res)
            res = counter;
    }
    return res;
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0x0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = longestSubarray(arr, n);
    
    printf("The length of the longest subarray is: %d\n", result);

    free(arr);

    return 0x0;
}

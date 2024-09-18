// By Younes Moukhlij

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxCost(int cost_count, int* cost,  int labels_count, char** labels, int dailyCount)
{
	(void) labels_count;
    int res = 0;
    int cur_cnt = 0;     
    int cur_cost = 0;  
    
    for (int i = 0; i < cost_count; i++)
	{
        cur_cost += cost[i];
        if (strcmp(labels[i], "illegal") == 0)
            continue; 
        cur_cnt++; 
        if (cur_cnt == dailyCount)
		{
            if (cur_cost > res)
                res = cur_cost;  
            cur_cnt = 0;   
            cur_cost = 0; 
        }
    }
    return res;
}

int main() {
    int cost_count;
    printf("Enter the number of cost items: ");
    scanf("%d", &cost_count);

    int* cost = (int*)malloc(cost_count * sizeof(int));  
    printf("Enter the cost items:\n");
    for (int i = 0; i < cost_count; i++)
	{
        scanf("%d", &cost[i]);  
    }

    int labels_count;
    printf("Enter the number of labels: ");
    scanf("%d", &labels_count);

    char** labels = (char**)malloc(labels_count * sizeof(char*));  
    printf("Enter the labels:\n");
    for (int i = 0; i < labels_count; i++) {
        labels[i] = (char*)malloc(10 * sizeof(char));  
        scanf("%s", labels[i]);  
    }

    int dailyCount;
    printf("Enter the daily count: ");
    scanf("%d", &dailyCount);

    
    int result = maxCost(cost_count, cost, labels_count, labels, dailyCount);
    
    
    printf("The maximum cost is: %d\n", result);

    
    for (int i = 0; i < labels_count; i++) {
        free(labels[i]);  
    }
    free(labels);  
    free(cost);    

    return 0;
}

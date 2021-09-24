#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

typedef struct{
    int hap;
    int weight;
}food;

int main(void){
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++){
        int num, happiness;
        scanf("%d %d", &num, &happiness);

        food arr[num];
        for (int i = 0; i < num; i++){
            scanf("%d %d", &arr[i].hap, &arr[i].weight);
        }

        int ans = 0;

        int total;

        for (int i = 0; i < num; i++){
            for (int j = i;)
        }

        
    //     for(int i = 0; i < num - 1; i++){
    //         for(int j = 0; j < num - i - 1; j++){
    //             if (arr[j].weight > arr[j+1].weight){
    //                 swap(&arr[j].hap, &arr[j+1].hap);
    //                 swap(&arr[j].weight, &arr[j+1].weight);
    //             }
    //             else if (arr[j].weight == arr[j+1].weight){
    //                 if(arr[j].hap < arr[j+1].hap){
    //                     swap(&arr[j].hap, &arr[j+1].hap);
    //                     swap(&arr[j].weight, &arr[j+1].weight);
    //                 }
    //             }
    //         }
    //     }

    //     int hap_count = 0;
    //     int weight_count = 0;
    //     for (int i = 0 ; i < num; i++){
    //         hap_count += arr[i].hap;
    //         weight_count += arr[i].weight;
    //         if (hap_count >= happiness){
    //             break;
    //         }
    //     }

    //     if (hap_count < happiness){
    //         printf("Case #%d: Impossible\n", tc+1);
    //     }
    //     else{
    //         printf("Case #%d: %d\n", tc+1, weight_count);
    //     }
    // }

    
}
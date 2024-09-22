#include <bits/stdc++.h>
using namespace std;

int sqrt(int num){

    long long int ans = 0;
    // If number is 0 or 1 return number
    if(num == 0 || num == 1){
        return num;
    }

    long long int result = 1, square_cntr = 1;
    // Run loop till result is not equal to square
    while(result <= num){

        square_cntr++;
        
        // Calculate square of numbers one by one
        result = square_cntr * square_cntr;
    }

    ans = square_cntr-1;
    return ans;

}

int sqrt_search_space_pattern(int num){
    int start = 0;
    int end = num;
    int mid = start + ((end-start)/2);
    int ans = -1;
    while(start <= end){
        // Termination condition
        if(mid * mid == num){
            return mid;
        }
        // If product is less than number
        // Move to the right
        if(mid * mid < num){
            ans = mid;
            start = mid + 1;
        }
        // If product is greater than number
        // Move to the left
        else{
            end = mid - 1;
        }
        // Update the mid
        mid = start + ((end-start)/2);
    }

    return ans;
}

double sqrt_search_space_pattern_precision(int num){
    int start = 0;
    int end = num;
    int mid = start + ((end-start)/2);
    int ans = -1;
    while(start <= end){
        // Termination condition
        if(mid * mid == num){
            return mid;
        }
        // If product is less than number
        // Move to the right
        if(mid * mid < num){
            ans = mid;
            start = mid + 1;
        }
        // If product is greater than number
        // Move to the left
        else{
            end = mid - 1;
        }
        // Update the mid
        mid = start + ((end-start)/2);
    }

    double sqrt_ans = ans;
    
    // Answer variable
    double ans_dec;

    // Compare difference with the square
    double num_dec = 0;

    // Factor in decimal
    double factor = 1;

    // Loop till decimal places
    for(int j=1; j<3; j++){
        factor = factor * 10;
        // from 1 to 9
        for(int i=1; i<10; i++){
            double precision = i/factor;
            double new_num = sqrt_ans + precision;
            if((new_num * new_num) < num){
                ans_dec = new_num;
            }
            else{
                break;
            }
        }
        sqrt_ans = ans_dec;
    }
    return ans_dec;
}

int main(){
    int num = 100;

    int ans = sqrt(100);
    cout << ans << endl;
    
    double ans_search_space_pattern = sqrt_search_space_pattern_precision(8);
    cout << ans_search_space_pattern;

    return 0;
}


